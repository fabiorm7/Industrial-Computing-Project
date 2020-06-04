//Interacciones entre objetos

#include "Interaccion.h"
#include <math.h>


void Interaccion::rebote(Hombre &h, Caja c)//Para que el hombre no salga del recinto
{
	float xmax = c.suelo.limite2.x;
	float xmin = c.suelo.limite1.x;
	float ymax = c.pared_izq.limite2.y;
	float ymin = c.pared_izq.limite1.y;
	if (h.posicion.x > xmax) h.posicion.x = xmax;
	if (h.posicion.x < xmin) h.posicion.x = xmin;
	if (h.posicion.y > ymax) h.posicion.y = ymax;
	if (h.posicion.y < ymin) h.posicion.y = ymin;
}

bool Interaccion::rebote(Hombre &h, Pared p)//Para que el hombre se sostenga sobre las plataformas
{
	Vector2D dir;
	float dif = p.distancia(h.posicion, &dir) - h.radio/4;
	if (h.getVel().y <= 0) {
		if (dif < 0.0f) {
			h.posicion.y = p.limite1.y;
			h.setVel_y(0.0f);
			return true;
		}
	}
	return false;
}

bool Interaccion::finNivel(Hombre & h, Pared p)//Acción en la que el hombre atraviesa la puerta del final del nivel
{
	if (h.getPos().x == p.limite1.x && h.getPos().y >= p.limite1.y && h.getPos().y <= p.limite2.y) {
		return true;
	}
	return false;
}

Interaccion::Interaccion()
{
}

Interaccion::~Interaccion()
{
}

bool Interaccion::rebote(Enemigo &e, Pared p)//Para que el enemigo rebote con las plataformas
{
	Vector2D dir;
	float dif = p.distancia(e.posicion, &dir) - e.radio;
	if (dif <= 0.0f)
	{
		Vector2D v_inicial = e.velocidad;
		e.velocidad = v_inicial - dir * 2.0*(v_inicial*dir);
		e.posicion = e.posicion - dir * dif;
		return true;
	}
	return false;
}

void Interaccion::rebote(Enemigo & e, Caja c)//Para que el enemigo no salga del recinto
{
	rebote(e, c.suelo);
	rebote(e, c.techo);
	rebote(e, c.pared_dcha);
	rebote(e, c.pared_izq);
}

bool Interaccion::rebote(Bonus & b, Pared p)//Para que el bonus se mantenga en las plataformas
{
	Vector2D dir;
	float dif = p.distancia(b.posicion, &dir) - 2*b.radio;
	if (b.getVel().y <= 0) {
		if (dif < 0.0f) {
			b.posicion.y = p.limite1.y + b.radio;
			b.setVel_y(0.0f);
			return true;
		}
	}
	return false;
}

void Interaccion::rebote(Bonus & b, Caja c)//Para que el bonus no salga de la caja
{
	rebote(b, c.suelo);
	rebote(b, c.techo);
	rebote(b, c.pared_dcha);
	rebote(b, c.pared_izq);
}

bool Interaccion::rebote(Enemigo &esfera1, Enemigo &esfera2)//rebote entre enemigos
{
	//Hacemos un vector que una los centros y sacamos su módulo restándole los radios
	Vector2D diferencia = esfera2.posicion - esfera1.posicion;
	float modulo = diferencia.modulo();
	float argd = diferencia.argumento();
	float distancia = modulo - (esfera1.radio + esfera2.radio);

	if (distancia < 0.0f)
	{
		//Declaramos los módulos y argumentos de las velocidades
		float vel1 = esfera1.velocidad.modulo();
		float arg1 = esfera1.velocidad.argumento();
		float vel2 = esfera2.velocidad.modulo();
		float arg2 = esfera2.velocidad.argumento();

		//Separamos ligeramente las esferas antes de darles su nueva velocidad
		Vector2D sep(distancia / 2 * cos(argd), distancia / 2 * sin(argd));
		esfera1.posicion = esfera1.posicion + sep;
		esfera2.posicion = esfera2.posicion - sep;

		//Sacamos el ángulo de las velocidades antes del choque y sus componentes
		argd = argd - 3.14159f / 2;
		float th1 = arg1 - argd;
		float th2 = arg2 - argd;
		float u1x = vel1 * cos(th1);
		float u1y = vel1 * sin(th1);
		float u2x = vel2 * cos(th2);
		float u2y = vel2 * sin(th2);

		//Hallamos las componentes después del choque
		//La componente X se mantiene constante
		float v1x = u1x;
		float v2x = u2x;
		//En el eje Y hay rebote elástico
		float m1 = esfera1.radio;
		float m2 = esfera2.radio;
		float py = m1 * u1y + m2 * u2y; //Cantidad de movimiento inicial en el eje Y
		float ey = m1 * u1y*u1y + m2 * u2y*u2y; //Energia cinética inicial en el eje Y

		//Calculamos los coeficientes y el discriminante de la ecuacion cuadrada
		float a = m2 * m2 + m1 * m2;
		float b = -2 * py*m2;
		float c = py * py - m1 * ey;
		float disc = b * b - 4 * a*c;
		if (disc < 0)disc = 0;

		//Estas serían las nuevas velocidades para el eje Y según la fórmula
		float v2y = (-b + sqrt(disc)) / (2 * a);
		float v1y = (py - m2 * v2y) / m1;

		//Y estos el módulo y argumento de las velocidades en coordenadas absolutas
		float modv1, modv2, fi1, fi2;
		modv1 = sqrt(v1x*v1x + v1y * v1y);
		modv2 = sqrt(v2x*v2x + v2y * v2y);
		fi1 = argd + atan2(v1y, v1x);
		fi2 = argd + atan2(v2y, v2x);

		//Declaramos las velocidades en coordenadas absolutas despues del choque
		esfera1.velocidad.x = modv1 * cos(fi1);
		esfera1.velocidad.y = modv1 * sin(fi1);
		esfera2.velocidad.x = modv2 * cos(fi2);
		esfera2.velocidad.y = modv2 * sin(fi2);
	}
	return false;
}

bool Interaccion::colision(Enemigo e, Hombre h)
{
	Vector2D pos = h.getPos(); //la posicion de la base del hombre
	pos.y += h.getRadio() / 2.0f; //posicion del centro
	float distancia = (e.posicion - pos).modulo();
	if (distancia<e.radio)
		return true;
	return false;
}

bool Interaccion::colision(Bonus b, Hombre h)
{
	Vector2D pos = h.getPos(); //la posicion de la base del hombre
	pos.y += h.getRadio() / 2.0f; //posicion del centro
	float distancia = (b.posicion - pos).modulo();
	if (distancia < b.radio)
		return true;
	return false;
}

bool Interaccion::colision(Disparo d, Pared p)//Se usa para que los disparos se eliminen al chocar con la pared
{
	Vector2D pos = d.getPos();
	float dis = p.distancia(pos, NULL);
	if (dis<d.getRadio()) {
		return true;
	}
	return false;
}

bool Interaccion::colision(Disparo d, Caja c)//Aplicación del anterior a la caja
{
	if (colision(d, c.techo)) return true;
	else if (colision(d, c.pared_dcha)) return true;
	else if (colision(d, c.pared_izq)) return true;
	else if (colision(d, c.suelo)) return true;
	else return false;
}

bool Interaccion::colision(Disparo d, Enemigo e)
{
	Vector2D pos = d.getPos(); //la posicion de la base del hombre
	pos.y += d.getRadio() / 2.0f; //posicion del centro
	float distancia = (e.posicion - pos).modulo();
	if (distancia < e.radio)
		return true;
	return false;
}
