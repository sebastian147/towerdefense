#include "header.h"
void IniciarJugador(Jugador *jugador)
{

	jugador->vida=50;
	jugador->score=0;
	jugador->plata=300;
	//arreglar
	jugador->oleada=1;
	jugador->relojito=0;
	jugador->malo=0;
}
