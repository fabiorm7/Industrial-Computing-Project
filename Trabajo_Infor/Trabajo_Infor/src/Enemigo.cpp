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