//Práctica 6 Ismael Gómez Pacheco 53985 grupo EE309 martes 9:30-11:30

#pragma once

#include "Disparo.h"

class DisparoEspecial :public Disparo
{
public:
	DisparoEspecial(float vhom);
	virtual ~DisparoEspecial();
	void dibuja();
};