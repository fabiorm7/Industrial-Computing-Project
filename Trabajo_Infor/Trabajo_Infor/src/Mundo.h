//Práctica 5 Ismael Gómez Pacheco 53985 grupo EE309 martes 9:30-11:30

#include "Caja.h"
#include "Hombre.h"
#include "Interaccion.h"
#include "ListaPlataformas.h"
/*#include "Esfera.h"
#include "Bonus.h"
#include "Disparo.h"
#include "ListaEsferas.h"
#include "ListaDisparos.h"
#include "EsferaPulsante.h"
#include "DisparoEspecial.h"*/

class Mundo
{
public: 
	virtual ~Mundo();
	void Tecla(unsigned char key);
	void Inicializa();
	void RotarOjo();
	void Mueve();
	void Dibuja();
	void teclaEspecial(unsigned char key);
	bool finNivel;
	//bool finNivel();
	/*bool getImpacto();
	int getNumEsferas();*/
	bool cargarNivel();
private:
	float x_ojo;
	float y_ojo;
	float z_ojo;
	float x_obs;
	float y_obs;
	float z_obs;
	//bool impacto;
	int nivel;
	Hombre hombre;
	/*Bonus bonus;
	ListaEsferas esferas;
	ListaDisparos disparos;
	DisparoEspecial disparo_especial;*/
	ListaPlataformas plataformas;
	Caja caja;
};
