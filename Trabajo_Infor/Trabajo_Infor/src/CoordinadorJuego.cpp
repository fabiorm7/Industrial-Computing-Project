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
			estado = INTRO;
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
		else if (key == 'm') {
			estado = INICIO;
		}
	}
	else if (estado == INTRO) {
		if (key == 'e') {
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
		ETSIDI::printxy("Bienvenido al Covid Explorer", -5, 8);
		ETSIDI::printxy("CONTROLES:", -5, 5);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
		ETSIDI::printxy("PULSE LA TECLA -E- PARA EMPEZAR", -5, 7);
		ETSIDI::printxy("PULSE LA TECLA -S- PARA SALIR", -5, 6);
		ETSIDI::printxy("USE LAS FLECHAS PARA MOVERSE", -5, 4);
		ETSIDI::printxy("PULSE ESPACIO PARA DISPARO", -5, 3);
		ETSIDI::printxy("OJO AL CAER DESDE ALTO", -5, 2);
		ETSIDI::printxy("PULSE P PARA PAUSA", -5, 0);
		ETSIDI::printxy("ETSIDI Computing Team", 2, -2);
	}
	else if (estado == JUEGO) {
		mundo.Dibuja();
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
		ETSIDI::printxy("Pulsa -M- para volver al menu", -5, 8);
	}
	else if (estado == INTRO) {
		gluLookAt(0, 7.5, 30,  // posicion del ojo
			0.0, 7.5, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y) 
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 10);
		ETSIDI::printxy("En pleno 2020, la humanidad se encuentra al borde del colapso. ", -9, 15);
		ETSIDI::printxy("Catastrofes naturales, guerras comerciales y politicos tiranos asolan las naciones", -9, 14);
		ETSIDI::printxy("de la Tierra. Pero la humanidad tenia aun que enfrentarse a su mayor desafio…", -9, 13);
		ETSIDI::printxy("Negras nubes se ciernen sobre la siempre alegre y soleada ETSIDI.", -9, 11);
		ETSIDI::printxy("Algo más temible que los examenes finales habia llegado para quedarse, ", -9, 10);
		ETSIDI::printxy("su nombre COVID. Donde antes habia contentos y ansiosos estudiantes ahora", -9, 9);
		ETSIDI::printxy("solo hay pasillos vacios, las aulas, otrora bulliciosas en donde no hace mucho", -9, 8);
		ETSIDI::printxy("se podía oír las risas nerviosas de los alumnos y algun que otro lamento yacen ", -9, 7);
		ETSIDI::printxy("ahora desiertas, el silencio ha ocupado sus sitios y el desamparo sus corazones.", -9, 6);
		ETSIDI::printxy("Tras esta serie de inoportunos acontecimientos y algún que otro examen online,", -9, 4);
		ETSIDI::printxy("nuestro heroe “Timmy” decide que ya ha tenido bastante y planta cara a este  ", -9, 3);
		ETSIDI::printxy("viruloso rival. Armado con una pistola con gel desinfectante, coraje y ", -9, 2);
		ETSIDI::printxy("mucho animo, Timmy decide adentrarse una vez mas en la ETSIDI…", -9, 1);
		ETSIDI::printxy("Pulsa -E- para empezar", -5,-1);
	}
}
