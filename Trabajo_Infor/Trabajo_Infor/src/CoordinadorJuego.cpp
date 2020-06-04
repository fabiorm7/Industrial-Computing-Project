//Máquina de estados, en "JUEGO" llama a mundo que es el que realmente gestiona todo

#include "CoordinadorJuego.h"
#include "ETSIDI.h"
#include "glut.h"
#include <string>

CoordinadorJuego::CoordinadorJuego()
{
	estado = INICIO;
}

CoordinadorJuego::~CoordinadorJuego()
{
}

void CoordinadorJuego::teclaEspecial(unsigned char key)
{
	if (estado == JUEGO)
		mundo.teclaEspecial(key);
}

void CoordinadorJuego::tecla(unsigned char key)
{
	if (estado == INICIO) {
		if (key == 'e') {
			mundo.Inicializa();
			estado = JUEGO;
		}
		else if (key == 's') {
			exit(0);
		}
	}
	else if (estado == JUEGO) {
		mundo.Tecla(key);
		if (key == 'p') {
			estado = PAUSA;
		}
	}
	else if (estado == GAMEOVER)
	{
		if (key == 'c')
			estado = INICIO;
	}
	else if (estado == FIN)
	{
		if (key == 'c')
			estado = INICIO;
	}
	else if (estado == PAUSA) {
		if (key == 'c') {
			estado = JUEGO;
		}
	}
}

void CoordinadorJuego::mueve()
{
	if (estado == JUEGO)
	{
		mundo.Mueve();
		if (mundo.finNivel())
		{
			if (!mundo.cargarNivel())
				estado = FIN;
		}
		if (mundo.getCaida() || mundo.getImpacto())
		{
			estado = GAMEOVER;
		}
	}
}

void CoordinadorJuego::dibuja()
{
	if (estado == INICIO) {
		gluLookAt(0, 7.5, 30,  // posicion del ojo
			0.0, 7.5, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y) 
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("Bienvenido al [Insertar nombre de juego]", -5, 8);
		ETSIDI::printxy("CONTROLES:", -5, 5);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
		ETSIDI::printxy("PULSE LA TECLA -E- PARA EMPEZAR", -5, 7);
		ETSIDI::printxy("PULSE LA TECLA -S- PARA SALIR", -5, 6);
		ETSIDI::printxy("USE LAS FLECHAS PARA MOVERSE", -5, 4);
		ETSIDI::printxy("PULSE ESPACIO PARA DISPARO", -5, 3);
		ETSIDI::printxy("PULSE P PARA PAUSA", -5, 1);
		//Controles del pang como ejemplo, se pueden cambiar
		ETSIDI::printxy("[Insertar nombre de participantes o grupo]", 2, -1);
	}
	else if (estado == JUEGO) {
		mundo.Dibuja();
		/*ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 10);
		char marcador[] = { char(mundo.marc()) };
		ETSIDI::printxy(marcador, -1, 16);*/
	}
	else if (estado == GAMEOVER)
	{
		//Aleja la vista para tener un visionado general del nivel
		gluLookAt(0.0, 3.5, 30.0,  // posicion del ojo
			0.0, 3.5, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y) 
		mundo.Dibuja();
		ETSIDI::setTextColor(1, 0, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("GAMEOVER: Has perdido", -5, 10);
		ETSIDI::printxy("Pulsa -C- para continuar", -5, 4);
	}
	else if (estado == FIN)
	{
		mundo.Dibuja();
		ETSIDI::setTextColor(0, 0, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("ENHORABUENA, ¡Has triunfado!", -5, 10);
		ETSIDI::printxy("Pulsa -C- para continuar", -5, 6);
	}
	else if (estado == PAUSA) {
		//Aleja la vista para tener un visionado general del nivel
		gluLookAt(0.0, 3.5, 30.0,  // posicion del ojo
			0.0, 3.5, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y) 
		mundo.Dibuja();
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("PAUSA", -2, 12);
		ETSIDI::printxy("Pulsa -C- para continuar", -5, 10);
	}
}
