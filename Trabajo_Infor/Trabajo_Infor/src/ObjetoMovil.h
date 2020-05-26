//Práctica 6 Ismael Gómez Pacheco 53985 grupo EE309 martes 9:30-11:30

#pragma once

#include "Vector2D.h"

class ObjetoMovil {
protected:
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;
	float radio;
public:
	ObjetoMovil();
	virtual ~ObjetoMovil();
	virtual void mueve(float t);
	void setPos(float x, float y);
	void setPos(Vector2D pos);
	void setVel(float vx, float vy);
	void setMov(float distancia);
	Vector2D getPos();
	float getRadio();
	Vector2D getVel();
	void setRadio(float r);
};