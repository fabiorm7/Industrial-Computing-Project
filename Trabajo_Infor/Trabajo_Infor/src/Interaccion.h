//Pr�ctica 6 Ismael G�mez Pacheco 53985 grupo EE309 martes 9:30-11:30

#pragma once

#include "Hombre.h"
#include "Caja.h"
#include "Esfera.h"
#include "Disparo.h"

class Interaccion {
public:
	static void rebote(Hombre& h, Caja c);
	static bool rebote(Hombre& h, Pared p);
	Interaccion();
	virtual ~Interaccion();
	static bool rebote(Esfera &e, Pared p);
	static void rebote(Esfera &e, Caja c);
	static bool rebote(Esfera& e1, Esfera& e2);
	static bool colision(Esfera e, Hombre h);
	static bool colision(Disparo d, Pared p);
	static bool colision(Disparo d, Caja c);
	static bool colision(Disparo d, Esfera e);
	static bool enPlataforma(Hombre h, Pared p);
};
