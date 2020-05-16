//Práctica 6 Ismael Gómez Pacheco 53985 grupo EE309 martes 9:30-11:30

#pragma once

#include "Vector2D.h"
#include "ObjetoMovil.h"

class Bonus :public ObjetoMovil 
{
public:
	Bonus();
	virtual ~Bonus();
	void dibuja();
};