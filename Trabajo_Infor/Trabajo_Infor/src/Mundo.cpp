//Gestión principal del juego

#include "Mundo.h"
#include "ETSIDI.h"
#include "glut.h"
#include <math.h>

void Mundo::Dibuja()
{
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
			x_obs, y_obs, z_obs,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	//aqui es donde hay que poner el codigo de dibujo
	caja.dibuja();
	plataformas.dibuja();
	hombre.dibuja();
	disparos.dibuja();
	enemigos.dibuja();
	bonus.dibuja();
}

void Mundo::Mueve()
{
	hombre.mueve(0.025f);
	x_obs = x_ojo = hombre.getPos().x;//La vista acompaña al personaje
	if (x_obs < 0) {
		x_ojo = x_obs = 0.0f;
	}
	if (x_obs > 10) {
		x_ojo = x_obs = 10.0f;
	}
	Interaccion::rebote(hombre, caja);
	disparos.colision(caja);
	bonus.rebote(caja);
	enemigos.rebote(caja);
	enemigos.rebote();
	for (int i = 0; i < plataformas.getNumero(); i++) {//Para mantenerse sobre las plataformas
		Interaccion::rebote(hombre, *plataformas[i]);
		enemigos.rebote(*plataformas[i]);
		bonus.rebote(*plataformas[i]);
	}
	finNiv = Interaccion::finNivel(hombre, *plataformas[6]);//Fin cuando atraviesa la puerta. 
	//El índice de la plataforma debe ser alto porque no sabemos cuántas habrá y si nos pasamos automáticamente 
	//nos coge la última (que debería ser la puerta)

	for (int i = 0; i < plataformas.getNumero(); i++) {//Indica que el personaje está en un lugar alto para la muerte por caída
		if (hombre.getPos().y >= 8.0f) {
			lugarAlto = true;
		}
		//Si desde la altura ha bajado antes a una plataforma más baja se resetea la variable para no morir
		if (Interaccion::rebote(hombre, *plataformas[i]) && hombre.getPos().y < 8.0f) {
			lugarAlto = false;
		}
	}
	if (lugarAlto && hombre.getPos().y == 0.0f) {//Si estaba en lugar alto y llega al suelo sin pasar por una plataforma muere
		caidaAlta = true;
	}
	disparos.mueve(0.025f);
	enemigos.mueve(0.025f);
	bonus.mueve(0.025f);
	for (int i = 0; i < enemigos.getNumero(); i++)
	{
		for (int j = 0; j < disparos.getNumero(); j++) {
			if (Interaccion::colision(*disparos[j], *enemigos[i]))
			{
				Bonus *b = new Bonus();
				b->setPos(enemigos[i]->getPos());
				bonus.agregar(b);
				enemigos.eliminar(enemigos[i]);
				disparos.eliminar(disparos[j]);
				ETSIDI::play("sonidos/impacto.wav");
				break;
			}
		}
	}
	Enemigo *aux = enemigos.colision(hombre);
	if (aux != 0)
		impacto = true;
	Bonus *baux = bonus.colision(hombre);
	if (baux != 0) {
		bonus.eliminar(baux);
		disparos.aumentarMax();
	}
	if (nivel == 3) {
		enemigos.crear(4.0f);
	}
}

void Mundo::Inicializa()
{
	disparos.setMax(1);//Máximo 1 disparo al empezar
	nivel = 0;
	cargarNivel();
}

Mundo::~Mundo()
{
	plataformas.destruirContenido();
	enemigos.destruirContenido();
	disparos.destruirContenido();
	bonus.destruirContenido();
}

void Mundo::Tecla(unsigned char key)
{
	switch (key)
	{
	case ' ':
		{
		Disparo* d = new Disparo(hombre.getVel().x);
		Vector2D pos = hombre.getPos();
		pos.y += 0.7f;//Si no dispara desde el suelo
		d->setPos(pos);
		disparos.agregar(d);
		ETSIDI::play("sonidos/disparo.wav");
		break;
		}
	}
}

void Mundo::teclaEspecial(unsigned char key)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		hombre.setVel_x(-5.0f);
		break;
	case GLUT_KEY_RIGHT:
		hombre.setVel_x(5.0f);
		break;
	case GLUT_KEY_UP://Si el hombre está en el suelo o sobre una plataforma podrá saltar, si no, no
		if (hombre.getPos().y == 0) {
			hombre.setVel_y(8.0f);
			break;
		}
		for (int i = 0; i < plataformas.getNumero(); i++) {
			if (Interaccion::rebote(hombre, *plataformas[i])) {
				hombre.setVel_y(8.0f);
				break;
			}
		}
		break;
	case GLUT_KEY_DOWN:
		hombre.setVel(0.0f, -7.0f);//Detiene al personaje porque no se frena solo en el eje x. Si está en el aire aumenta la velocidad de caída
		break;
	}
}

bool Mundo::getCaida() {
	return caidaAlta;
}

bool Mundo::finNivel()
{
	return finNiv;
}

bool Mundo::getImpacto() {
	return impacto;
}

bool Mundo::cargarNivel()
{
	nivel++;
	x_ojo = 0;
	y_ojo = 7.5;
	z_ojo = 30;
	y_obs = y_ojo;
	x_obs = z_obs = 0.0f;
	hombre.setPos(0, 0);
	hombre.setVel(0.0f, 0.0f);
	plataformas.destruirContenido();
	enemigos.destruirContenido();
	disparos.destruirContenido();
	bonus.destruirContenido();
	impacto = false;
	finNiv = false;
	caidaAlta = false;
	lugarAlto = false;
	if (nivel == 1)//El nivel 1 solo tiene 4 plataformas y la puerta final, es como un tutorial para el jugador
	{
		Pared *p1 = new Pared();
		p1->setColor(255, 0, 0);
		p1->setPos(-5.0f, 3.0f, 2.0f, 3.0f);
		plataformas.agregar(p1);
		Pared *p2 = new Pared();
		p2->setColor(255, 0, 0);
		p2->setPos(4.0f, 6.0f, 6.0f, 6.0f);
		plataformas.agregar(p2);
		Pared *p3 = new Pared();
		p3->setColor(255, 0, 0);
		p3->setPos(8.0f, 8.0f, 10.0f, 8.0f);
		plataformas.agregar(p3);
		Pared *p4 = new Pared();
		p4->setColor(255, 0, 0);
		p4->setPos(13.0f, 8.0f, 18.0f, 8.0f);
		plataformas.agregar(p4);
		Pared *puerta = new Pared();
		puerta->setColor(0, 0, 250);
		puerta->setPos(17.0f, 8.0f, 17.0f, 14.0f);
		plataformas.agregar(puerta);
	}
	if (nivel == 2)
	{
		Pared *p1 = new Pared();
		p1->setColor(255, 0, 0);
		p1->setPos(13.0f, 3.0f, 18.0f, 3.0f);
		plataformas.agregar(p1);
		Pared *p2 = new Pared();
		p2->setColor(255, 0, 0);
		p2->setPos(8.0f, 6.0f, 10.0f, 6.0f);
		plataformas.agregar(p2);
		Pared *p3 = new Pared();
		p3->setColor(255, 0, 0);
		p3->setPos(2.0f, 6.0f, 6.0f, 6.0f);
		plataformas.agregar(p3);
		Pared *p4 = new Pared();
		p4->setColor(255, 0, 0);
		p4->setPos(-7.0f, 6.0f, -2.0f, 6.0f);
		plataformas.agregar(p4);
		Pared *puerta = new Pared();
		puerta->setColor(0, 0, 250);
		puerta->setPos(-5.0f, 6.0f, -5.0f, 12.0f);
		plataformas.agregar(puerta);
		Enemigo *e1 = new Enemigo(1.5f, 5.0f, 1.5f, -5.0f, 0.0f);
		enemigos.agregar(e1);
		Enemigo *e2 = new Enemigo(1.5f, 10.0f, 7.0f, -3.0f, 0.0f);
		enemigos.agregar(e2);
	}
	if (nivel == 3)
	{
		Pared *p1 = new Pared();
		p1->setColor(255, 0, 0);
		p1->setPos(-5.0f, 3.0f, 2.0f, 3.0f);
		plataformas.agregar(p1);
		Pared *p2 = new Pared();
		p2->setColor(255, 0, 0);
		p2->setPos(4.0f, 6.0f, 6.0f, 6.0f);
		plataformas.agregar(p2);
		Pared *p3 = new Pared();
		p3->setColor(255, 0, 0);
		p3->setPos(8.0f, 8.0f, 10.0f, 8.0f);
		plataformas.agregar(p3);
		Pared *p4 = new Pared();
		p4->setColor(255, 0, 0);
		p4->setPos(13.0f, 8.0f, 18.0f, 8.0f);
		plataformas.agregar(p4);
		Pared *puerta = new Pared();
		puerta->setColor(0, 0, 250);
		puerta->setPos(17.0f, 8.0f, 17.0f, 14.0f);
		plataformas.agregar(puerta);
	}
	if (nivel <= 3)
		return true;
	return false;
}