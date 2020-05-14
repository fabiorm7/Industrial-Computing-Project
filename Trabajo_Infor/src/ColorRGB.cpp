//Práctica 6 Ismael Gómez Pacheco 53985 grupo EE309 martes 9:30-11:30

#include "ColorRGB.h"
#include "glut.h"

ColorRGB::ColorRGB(Byte _r, Byte _v, Byte _a)
{
	r = _r;
	g = _v;
	b = _a;
}
void ColorRGB::ponColor()
{
	glColor3ub(r, g, b);
}
ColorRGB::~ColorRGB()
{
}
