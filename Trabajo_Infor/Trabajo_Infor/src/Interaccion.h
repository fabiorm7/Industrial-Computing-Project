//Interacciones entre objetos, en el cpp se explica mejor

#pragma once

#include "Hombre.h"
#include "Caja.h"
#include "Enemigo.h"
#include "Disparo.h"
#include "Bonus.h"

class Interaccion {
public:
	static void rebote(Hombre &h, Caja c);
	static bool rebote(Hombre &h, Pared p);
	static bool finNivel(Hombre& h, Pared p);
	Interaccion();
	virtual ~Interaccion();
	static bool rebote(Enemigo &e, Pared p);
	static void rebote(Enemigo &e, Caja c);
	static bool rebote(Bonus &b, Pared p);
	static void rebote(Bonus &b, Caja c);
	static bool rebote(Enemigo& e1, Enemigo& e2);
	static bool colision(Enemigo e, Hombre h);
	static bool colision(Bonus b, Hombre h);
	static bool colision(Disparo d, Pared p);
	static bool colision(Disparo d, Caja c);
	static bool colision(Disparo d, Enemigo e);
};
