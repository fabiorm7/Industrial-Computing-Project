//Personaje

#include "Hombre.h"
#include "glut.h"

Hombre::Hombre() :sprite("imagenes/pangPlayer.png", 5)
{
	sprite.setCenter(1, 0);
	sprite.setSize(2, 2);
	radio = 1.8f;//el radio es la altura, pero llamándolo asi simplificamos las clases al heredar de ObjetoMovil
	aceleracion.y = -9.8f;
}

Hombre::~Hombre()
{
}

void Hombre::dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0.5);
	glColor3f(1.0f, 1.0f, 1.0f);
	if (velocidad.x > 0.01)sprite.flip(false, false);
	if (velocidad.x < -0.01)sprite.flip(true, false);
	if ((velocidad.x < 0.01) && (velocidad.x > -0.01))
		sprite.setState(0);
	else if (sprite.getState() == 0)
		sprite.setState(1, false);
	sprite.draw();

	glPopMatrix();
}
