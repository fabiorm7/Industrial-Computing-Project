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
	friend class Interaccion;
private:
	SpriteSequence sprite;
};