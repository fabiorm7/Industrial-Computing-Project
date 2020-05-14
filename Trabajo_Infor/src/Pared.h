//Práctica 6 Ismael Gómez Pacheco 53985 grupo EE309 martes 9:30-11:30

#pragma once

#include "Vector2D.h"
#include "ColorRGB.h"

class Pared {
private:
	ColorRGB color;
	Vector2D limite1;
	Vector2D limite2;
public:
	Pared();
	virtual ~Pared();
	void dibuja();
	void setColor(Byte r, Byte v, Byte a);
	void setPos(float x1, float y1, float x2, float y2);
	friend class Interaccion;
	float distancia(Vector2D punto, Vector2D *direccion);
};