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

#define CUADRADOY 40
#define CUADRADOX 54

enum MYKEYS 
{
	KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT
};
enum KEYS{UP, DOWN, LEFT, RIGHT, SPACE};

//iniciar
void InicializarIniciar(Iniciar *iniciar);
int IniciarYErrores(Iniciar *iniciar);

//reloj
bool EmpezarReloj(ALLEGRO_FONT *fuente,Reloj *reloj);
void Reloj0(ALLEGRO_FONT *fuente);
void IniciarReloj(Reloj *reloj);


//cuadrado
void IniciarCuadrado(Cuadrado *cuadrado);
void DibujarCuadrado(Cuadrado *cuadrado);
void MoverCuadradoArriba(Cuadrado *cuadrado);
void MoverCuadradoAbajo(Cuadrado *cuadrado);
void MoverCuadradoIzquierda(Cuadrado *cuadrado);
void MoverCuadradoDerecha(Cuadrado *cuadrado);


//enemigos
void MoverEnemigo(Enemigo *enemigo);
void IniciarEnemigo1(Enemigo *enemigo);
void MoverEnemigoAbajo(int final,Enemigo *enemigo,int bandera);
void MoverEnemigoIzquierda(int final,Enemigo *enemigo,int bandera);
void MoverEnemigoDerecha(int final,Enemigo *enemigo,int bandera);
void MoverEnemigoArriba(int final,Enemigo *enemigo,int bandera);
void IniciarEnemigo2(Enemigo *enemigo);
Enemigo * NuevoEnemigo(Enemigo *anterior);
void BarraDeVida(Enemigo *enemigo);
