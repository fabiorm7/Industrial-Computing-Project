//Gestión principal del juego, se explica mejor en el cpp

#include "Caja.h"
#include "Hombre.h"
#include "Interaccion.h"
#include "ListaPlataformas.h"
#include "ListaDisparos.h"
#include "ListaEnemigos.h"
#include "ListaBonus.h"

class Mundo
{
public:
	virtual ~Mundo();
	void Tecla(unsigned char key);
	void Inicializa();
	void Mueve();
	void Dibuja();
	void teclaEspecial(unsigned char key);
	bool getCaida();
	bool finNivel();
	bool getImpacto();
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
	ListaEnemigos enemigos;
	ListaBonus bonus;
	ListaPlataformas plataformas;
	Caja caja;
};
