#pragma once

#include "Mundo.h"

class CoordinadorJuego {
public:
	CoordinadorJuego();
	~CoordinadorJuego();
	void teclaEspecial(unsigned char key);
	void tecla(unsigned char key);
	void mueve();
	void dibuja();
private:
	Mundo mundo;
	enum Estado{INICIO, JUEGO, GAMEOVER, FIN, PAUSA};
	Estado estado;
};