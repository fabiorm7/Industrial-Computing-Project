//Se obtiene al destruir enemigos, aumenta el n�mero m�ximo de disparos

#pragma once

#include "Vector2D.h"
#include "ObjetoMovil.h"

class Bonus :public ObjetoMovil 
{
public:
	Bonus();
	virtual ~Bonus();
	void dibuja();
	friend class Interaccion;
};