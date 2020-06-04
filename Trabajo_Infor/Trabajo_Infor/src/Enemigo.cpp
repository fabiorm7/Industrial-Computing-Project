//Enemigos, son esferas que rebotan

#include "Enemigo.h"
#include "glut.h"

Enemigo::Enemigo(float rad, float x, float y, float vx, float vy)
{
	radio = rad;
	posicion.x = x;
	posicion.y = y;
	velocidad.x = vx;
	velocidad.y = vy;
	setColor(255, 255, 100);
	aceleracion.y = -9.8;
}

Enemigo::~Enemigo()
{
}

void Enemigo::dibuja()
{
	color.ponColor();
	glTranslatef(posicion.x, posicion.y, 0);
	glutSolidSphere(radio, 20, 20);
	glTranslatef(-posicion.x, -posicion.y, 0);
}

void Enemigo::setColor(unsigned char r, unsigned char v, unsigned char a)
{
	color.set(r, v, a);
}

/*Esfera* Esfera::dividir()
{
	if (radio < 1.0f)
		return 0; //no dividimos
	radio /= 2.0f;//Dividimos el radio por 2
	//Creamos una esfera nueva, copiando la actual
	Esfera *aux = new Esfera(*this);
	//Les damos nuevas velocidades
	aux->setVel(5, 8);//a la nueva mitad
	setVel(-5, 8);//a la mitad original
	return aux;
}*/