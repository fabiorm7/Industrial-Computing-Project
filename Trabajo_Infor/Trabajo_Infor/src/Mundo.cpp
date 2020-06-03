//Gestión principal del juego

#include "Mundo.h"
#include "ETSIDI.h"
#include "glut.h"
#include <math.h>

void Mundo::RotarOjo()//No sé si nos sirve para algo, no la he tocado desde la práctica 2, creo que es prescindible
{
	float dist=sqrt(x_ojo*x_ojo+z_ojo*z_ojo);
	float ang=atan2(z_ojo,x_ojo);
	ang+=0.05f;
	x_ojo=dist*cos(ang);
	z_ojo=dist*sin(ang);
}
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
	/*bonus.dibuja();
	esferas.dibuja();*/
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
	for (int i = 0; i < plataformas.getNumero(); i++) {//Para mantenerse sobre las plataformas
		Interaccion::rebote(hombre, *plataformas[i]);
	}
	finNiv = Interaccion::finNivel(hombre, *plataformas[6]);//Fin cuando atraviesa la puerta. 
	//El índice de la plataforma debe ser alto porque no sabemos cuántas habrá y si nos pasamos automáticamente 
	//nos coge la última (que debería ser la puerta)

	for (int i = 0; i < plataformas.getNumero(); i++) {//Indica que el personaje está en un lugar alto para la muerte por caída
		if (hombre.getPos().y >= 8.0f) {
			lugarAlto = true;
		}
		//Si desde la altura ha bajado antes a una plataforma más baja se resetea la variable pra no morir
		if (Interaccion::rebote(hombre, *plataformas[i]) && hombre.getPos().y < 8.0f) {
			lugarAlto = false;
		}
	}
	if (lugarAlto && hombre.getPos().y == 0.0f) {//Si estaba en lugar alto y llega al suelo sin pasar por una plataforma muere
		caidaAlta = true;
	}
	disparos.mueve(0.025f);
	disparos.colision(caja);
	/*bonus.mueve(0.025f);
	esferas.mueve(0.025f);
	esferas.rebote(caja);
	esferas.rebote(plataforma);
	esferas.rebote();
	disparos.colision(plataforma);
	for (int i = 0; i < esferas.getNumero(); i++)
	{
		for (int j = 0; j < disparos.getNumero(); j++) {
			if (Interaccion::colision(*disparos[j], *esferas[i]))
			{
				Esfera* e = esferas[i]->dividir();
				if (e == 0) //no division
					esferas.eliminar(esferas[i]);
				else
					esferas.agregar(e);
				disparos.eliminar(disparos[j]);
				ETSIDI::play("sonidos/impacto.wav");
				break;
			}
		}
	}
	Esfera *aux = esferas.colision(hombre);
	if (aux != 0)
		impacto = true;*/
}

void Mundo::Inicializa()
{
	finNiv = false;
	caidaAlta = false;
	lugarAlto = false;
	//impacto = false;
	nivel = 0;
	/*x_ojo = 0;
	y_ojo = 7.5;
	z_ojo = 30;
	y_obs = y_ojo;
	x_obs = z_obs = 0.0f;*/
	//bonus.setPos(5.0f, 5.0f);
	hombre.setVel(0.0f, 0.0f);
	cargarNivel();
}

Mundo::~Mundo()
{
	plataformas.destruirContenido();
	//esferas.destruirContenido();
	disparos.destruirContenido();
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
	case 'z':
		{
		/*DisparoEspecial* z = new DisparoEspecial();
		Vector2D pos = hombre.getPos();
		z->setPos(pos);
		disparos.agregar(z);
		hombre.setVel(0, 0);
		ETSIDI::play("sonidos/disparo.wav");*/
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

/*bool Mundo::getImpacto() {
	return impacto;
}

int Mundo::getNumEsferas()
{
	return esferas.getNumero();
}*/

bool Mundo::cargarNivel()
{
	nivel++;
	x_ojo = 0;
	y_ojo = 7.5;
	z_ojo = 30;
	y_obs = y_ojo;
	x_obs = z_obs = 0.0f;
	hombre.setPos(0, 0);
	plataformas.destruirContenido();
	//esferas.destruirContenido();
	disparos.destruirContenido();
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
		/*plataforma.setPos(-3.0f, 6.0f, 3.0f, 6.0f);
		plataforma.setColor(255, 0, 0);
		EsferaPulsante* e3 = new EsferaPulsante;
		e3->setPos(0, 12);
		e3->setVel(5, 3);
		esferas.agregar(e3);*/
	}
	if (nivel == 3)
	{
		/*plataforma.setPos(-10.0f, 12.0f, 4.0f, 10.0f);
		plataforma.setColor(255, 0, 255);
		for (int i = 0; i < 5; i++)
		{
			Esfera* aux = new Esfera(1.5, -5 + i, 12, i, 5);
			aux->setColor(i * 40, 0, 255 - i * 40);
			esferas.agregar(aux);
		}*/
	}
	if (nivel <= 1)
		return true;
	return false;
}