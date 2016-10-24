/**
 * \file header.h
 * \brief Archivo cabecera del programa.
 * \author Leandro Kollenberger <lkollenberger@frba.utn.edu.ar>
 * \date 26.08.2016
*/

#include <stdio.h>
#include <string.h>
#include "objetos.h"

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#define LARGO 800
#define ALTO 480
#define FPS 10

#define CUADRADOY 42
#define CUADRADOX 53.33333

enum MYKEYS 
{
	KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT
};
enum TECLAS{ARRIBA, ABAJO, IZQUIERDA, DERECHA, SPACE};

//iniciar
void InicializarIniciar(Iniciar *iniciar);
int IniciarYErrores(Iniciar *iniciar);
void IniciarLiberarMemoria(Iniciar *iniciar);


//reloj
bool EmpezarReloj(ALLEGRO_FONT *fuente,Reloj *reloj);
void Reloj0(ALLEGRO_FONT *fuente);
void IniciarReloj(Reloj *reloj);
void Informacion(ALLEGRO_FONT *fuente,Jugador *jugador);



//cuadrado
void IniciarCuadrado(Cuadrado *cuadrado);
void DibujarCuadrado(Cuadrado *cuadrado);
void MoverCuadradoArriba(Cuadrado *cuadrado);
void MoverCuadradoAbajo(Cuadrado *cuadrado);
void MoverCuadradoIzquierda(Cuadrado *cuadrado);
void MoverCuadradoDerecha(Cuadrado *cuadrado);



//jugador
void IniciarJugador(Jugador *jugador);



//enemigos
void MoverEnemigo(Enemigo **enemigo, Jugador *jugador);
void IniciarEnemigo1(Enemigo **enemigo);
void MoverEnemigoAbajo(int final,Enemigo **enemigo,int bandera);
void MoverEnemigoIzquierda(int final,Enemigo **enemigo,int bandera);
void MoverEnemigoDerecha(int final,Enemigo **enemigo,int bandera);
void MoverEnemigoArriba(int final,Enemigo **enemigo,int bandera);
void IniciarEnemigo2(Enemigo **enemigo);
Enemigo * NuevoEnemigo(Enemigo *anterior);
void BarraDeVida(Enemigo **enemigo);
Enemigo *EmpezarOleada(Enemigo *enemigo, int oleada,int malo);
Enemigo *SpawnearEnemigos(Enemigo *enemigo,Jugador *jugador);
//void OrdenarEnemigos(Enemigo *enemigo);
void LiberarMemoriaEnemigo(Enemigo **enemigo);
