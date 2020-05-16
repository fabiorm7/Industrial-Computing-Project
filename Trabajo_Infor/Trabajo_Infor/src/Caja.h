//Práctica 6 Ismael Gómez Pacheco 53985 grupo EE309 martes 9:30-11:30

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
