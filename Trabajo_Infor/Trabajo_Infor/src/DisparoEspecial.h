//Aún no se usa, el constructor está comentado porque me daba problemas al compilar

#pragma once

#include "Disparo.h"

class DisparoEspecial :public Disparo
{
public:
	DisparoEspecial(float vhom);
	virtual ~DisparoEspecial();
	void dibuja();
};