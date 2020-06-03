//Caja que forma el marco de visión del nivel

#pragma once

#include "Pared.h"

class Caja {
public:
	Caja();
	virtual ~Caja();
	void dibuja();
	friend class Interaccion;
private:
	Pared suelo;
	Pared techo;
	Pared pared_izq;
	Pared pared_dcha;
};
