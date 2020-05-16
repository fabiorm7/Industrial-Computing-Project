//Práctica 6 Ismael Gómez Pacheco 53985 grupo EE309 martes 9:30-11:30

#pragma once

#include "Vector2D.h"
#include "ColorRGB.h"
#include "ObjetoMovil.h"

class Esfera :public ObjetoMovil
{
protected:
	ColorRGB color;
public:
	Esfera();
	Esfera(float rad, float x = 0.0f, float y = 0.0f, float vx = 0.0f, float vy = 0.0f);
	virtual ~Esfera();
	void dibuja();
	void setColor(unsigned char r, unsigned char v, unsigned char a);
	friend class Interaccion;
	virtual Esfera* dividir();
};