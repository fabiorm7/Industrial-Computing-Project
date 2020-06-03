//Aún no se usa

#pragma once

#include "Esfera.h"

class EsferaPulsante :public Esfera 
{
private:
	float pulso; //la velocidad de pulso
	float radio_max;
	float radio_min;
public:
	EsferaPulsante();
	virtual ~EsferaPulsante();
	void mueve(float t);
	EsferaPulsante* dividir();
};