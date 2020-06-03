//Personaje

#pragma once

#include "Vector2D.h"
#include "ObjetoMovil.h"
#include "ETSIDI.h"

using ETSIDI::SpriteSequence;
class Hombre :public ObjetoMovil 
{
public:
	Hombre();
	virtual ~Hombre();
	void dibuja();
	void setVel_y(float vy) { velocidad.y = vy; }
	void setVel_x(float vx) { velocidad.x = vx; }
	friend class Interaccion;
private:
	SpriteSequence sprite;
};