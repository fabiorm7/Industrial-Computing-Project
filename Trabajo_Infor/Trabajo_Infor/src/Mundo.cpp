//Práctica 6 Ismael Gómez Pacheco 53985 grupo EE309 martes 9:30-11:30

#include "Mundo.h"
#include "ETSIDI.h"
#include "glut.h"
#include <math.h>

void Mundo::RotarOjo()
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
	plataforma_1.dibuja();
	plataforma_2.dibuja();
	plataforma_3.dibuja();
	plataforma_4.dibuja();
	hombre.dibuja();
	/*disparos.dibuja();
	bonus.dibuja();
	esferas.dibuja();*/
}

void Mundo::Mueve()
{
	hombre.mueve(0.025f);
	Interaccion::rebote(hombre, caja);
	Interaccion::rebote(hombre, plataforma_1);
	Interaccion::rebote(hombre, plataforma_2);
	Interaccion::rebote(hombre, plataforma_3);
	Interaccion::rebote(hombre, plataforma_4);
	/*bonus.mueve(0.025f);
	disparos.mueve(0.025f);
	esferas.mueve(0.025f);
	esferas.rebote(caja);
	esferas.rebote(plataforma);
	esferas.rebote();
	disparos.colision(caja);
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
	//impacto = false;
	nivel = 0;
	x_ojo = 0;
	y_ojo = 7.5;
	z_ojo = 30;
	y_obs = y_ojo;
	x_obs = z_obs = 0.0f;
	//bonus.setPos(5.0f, 5.0f);
	cargarNivel();
}

Mundo::~Mundo()
{
	/*esferas.destruirContenido();
	disparos.destruirContenido();*/
}

void Mundo::Tecla(unsigned char key)
{
	switch (key)
	{
	case ' ':
		{
		/*Disparo* d = new Disparo();
		Vector2D pos = hombre.getPos();
		d->setPos(pos);
		disparos.agregar(d);
		hombre.setVel(0, 0);
		ETSIDI::play("sonidos/disparo.wav");*/
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
		x_obs -= 0.05f;
		x_ojo -= 0.05f;
		hombre.setVel(-5.0f, 0.0f);
		break;
	case GLUT_KEY_RIGHT:
		x_obs += 0.05f;
		x_ojo += 0.05f;
		hombre.setVel(5.0f, 0.0f);
		break;
	case GLUT_KEY_UP:
		if (hombre.getVel().y < -10.0f) {
			hombre.setVel(0.0f, 10.0f);
		}
		break;
	}
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
	//hombre.setPos(0, 0);
	//esferas.destruirContenido();
	//disparos.destruirContenido();
	if (nivel == 1)
	{
		plataforma_1.setColor(255, 0, 0);
		plataforma_1.setPos(-5.0f, 3.0f, 2.0f, 3.0f);
		plataforma_2.setColor(255, 0, 0);
		plataforma_2.setPos(4.0f, 6.0f, 6.0f, 6.0f);
		plataforma_3.setColor(255, 0, 0);
		plataforma_3.setPos(8.0f, 8.0f, 10.0f, 8.0f);
		plataforma_4.setColor(255, 0, 0);
		plataforma_4.setPos(13.0f, 8.0f, 18.0f, 8.0f);
		/*Esfera *e1 = new Esfera(1.5f, 2, 4, 5, 15);
		e1->setColor(0, 0, 255);
		esferas.agregar(e1); //esfera*/
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
	if (nivel <= 3)
		return true;
	return false;
}