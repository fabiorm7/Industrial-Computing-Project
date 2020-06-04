//Enemigos, son esferas que rebotan

#pragma once

#include "Vector2D.h"
#include "ColorRGB.h"
#include "ObjetoMovil.h"

class Enemigo :public ObjetoMovil
{
protected:
	ColorRGB color;
public:
	Enemigo(float rad, float x = 0.0f, float y = 0.0f, float vx = 0.0f, float vy = 0.0f);
	virtual ~Enemigo();
	void dibuja();
	void setColor(unsigned char r, unsigned char v, unsigned char a);
	friend class Interaccion;
};