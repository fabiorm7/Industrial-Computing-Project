//Disparo horizontal con personaje en movimiento y vertical si está parado

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
}