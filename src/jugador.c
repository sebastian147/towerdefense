#include "header.h"
void IniciarJugador(Jugador *jugador)
{
	strcpy(jugador->iniciales,"seb");
	jugador->vida=50;
	jugador->score=0;
	jugador->plata=200;
	//arreglar
	jugador->oleada=1;
	jugador->relojito=0;
	jugador->malo=0;
}
void MeterIniciales()
{
	//dibujar
}
