//Práctica 6 Ismael Gómez Pacheco 53985 grupo EE309 martes 9:30-11:30

#pragma once

#include "Vector2D.h"
#include "ObjetoMovil.h"

class Disparo :public ObjetoMovil
{
public:
	Disparo();
	virtual ~Disparo();
	virtual void dibuja();
	friend class Interaccion;
	void setPos(Vector2D pos);
	void setPos(float x, float y);
protected:
	Vector2D origen;
};