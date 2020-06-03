//Aún no se usa

#include <stdlib.h>
#include "Bonus.h"
#include "glut.h"

Bonus::Bonus()
{
	aceleracion.y = -9.8f;
	radio = 0.5f;
	velocidad.y = 5;
}

Bonus::~Bonus()
{
}

void Bonus::dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glRotatef(30, 1, 1, 1);
	glColor3f(rand() / (float)RAND_MAX, rand() / (float)RAND_MAX,
		rand() / (float)RAND_MAX);//color aleatorio
	glutSolidCube(radio);
	glPopMatrix();
}