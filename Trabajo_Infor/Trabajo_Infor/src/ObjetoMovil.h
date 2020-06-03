//Clase base de todo lo móvil: Personaje, disparos, esferas, bonus...

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
	Vector2D getPos();
	float getRadio();
	Vector2D getVel();
	void setRadio(float r);
	void setVel_y(float vy) { velocidad.y = vy; }
	void setVel_x(float vx) { velocidad.x = vx; }
	friend class Interaccion;
};