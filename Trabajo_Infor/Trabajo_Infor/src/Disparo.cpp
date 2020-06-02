//Práctica 6 Ismael Gómez Pacheco 53985 grupo EE309 martes 9:30-11:30

#include "Disparo.h"
#include "glut.h"

Disparo::Disparo(float vhombre)
{
	radio = 0.25f;
	if (vhombre < 0) {
		velocidad.x = -10.0f;
	}
	else if (vhombre > 0) {
		velocidad.x = 10.0f;
	}
	else {
		velocidad.y = 10.0f;
	}
}

Disparo::~Disparo()
{
}

void Disparo::dibuja()
{
	glColor3f(0.0f, 1.0f, 1.0f);
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glutSolidSphere(radio, 20, 20);
	glPopMatrix();

	glDisable(GL_LIGHTING);
	glBegin(GL_LINES);
	glVertex3f(origen.x, origen.y, 0);
	glVertex3f(posicion.x, posicion.y, 0);
	glEnd();
	glEnable(GL_LIGHTING);
}

void Disparo::setPos(Vector2D pos)
{
	ObjetoMovil::setPos(pos);
	origen = pos;
}

void Disparo::setPos(float x, float y)
{
	posicion.x = x;
	posicion.y = y + 0.7f;
	origen = posicion;
}