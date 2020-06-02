//Práctica 6 Ismael Gómez Pacheco 53985 grupo EE309 martes 9:30-11:30

#include "DisparoEspecial.h"
#include "glut.h"

/*DisparoEspecial::DisparoEspecial(float vhom)
{
	radio = 0.4f;
	if (vhom < 0) {
		velocidad.x = -15.0f;
	}
	else if (vhom > 0) {
		velocidad.x = 15.0f;
	}
	else {
		velocidad.y = 15.0f;
	}
}*/

DisparoEspecial::~DisparoEspecial()
{
}

void DisparoEspecial::dibuja()
{
	glColor3f(1.0f, 1.0f, 0.0f);

	glDisable(GL_LIGHTING);
	glLineWidth(2.0f);

	glBegin(GL_LINES);
	glVertex3f(origen.x - 0.1, origen.y, 0);
	glVertex3f(posicion.x - 0.1, posicion.y, 0);
	glVertex3f(origen.x + 0.1, origen.y, 0);
	glVertex3f(posicion.x + 0.1, posicion.y, 0);
	glEnd();
	glEnable(GL_LIGHTING);
	glLineWidth(1.0f);

	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);

	glutSolidSphere(radio, 20, 20);
	glPopMatrix();
}