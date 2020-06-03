//Gesti�n principal del juego, se explica mejor en el cpp

#include "Caja.h"
#include "Hombre.h"
#include "Interaccion.h"
#include "ListaPlataformas.h"
#include "ListaDisparos.h"
#include "ListaEsferas.h"
/*#include "Esfera.h"
#include "Bonus.h"
#include "Disparo.h"
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
	bool getCaida();
	bool finNivel();
	bool getImpacto();
	//int getNumEsferas();
	bool cargarNivel();
private:
	float x_ojo;
	float y_ojo;
	float z_ojo;
	float x_obs;
	float y_obs;
	float z_obs;
	bool finNiv;
	bool lugarAlto;
	bool caidaAlta;
	bool impacto;
	int nivel;
	Hombre hombre;
	ListaDisparos disparos;
	ListaEsferas esferas;
	/*Bonus bonus;
	DisparoEspecial disparo_especial;*/
	ListaPlataformas plataformas;
	Caja caja;
};
