//Caja que forma el marco de visión del nivel

#include "Caja.h"
#include "ETSIDI.h"

Caja::Caja()
{
	suelo.setColor(0, 100, 0);
	suelo.setPos(-10.0f, 0, 20.0f, 0);
	techo.setColor(0, 100, 0);
	techo.setPos(-10.0f, 15.0f, 20.0f, 15.0f);
	pared_dcha.setColor(0, 150, 0);
	pared_dcha.setPos(-10.0f, 0, -10.0f, 15.0f);
	pared_izq.setColor(0, 150, 0);
	pared_izq.setPos(20.0f, 0, 20.0f, 15.0f);
}

Caja::~Caja()
{
}

void Caja::dibuja()
{
	suelo.dibuja();
	techo.dibuja();
	pared_dcha.dibuja();
	pared_izq.dibuja();

	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/fondo.png").id); //fondo del juego
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);

	glTexCoord2d(0, 1);		glVertex3f(-10, 0, -0.1);
	glTexCoord2d(1, 1);		glVertex3f(20, 0, -0.1);
	glTexCoord2d(1, 0);		glVertex3f(20, 15, -0.1);
	glTexCoord2d(0, 0);		glVertex3f(-10, 15, -0.1);
	glEnd();

	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}
