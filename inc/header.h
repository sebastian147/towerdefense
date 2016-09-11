/**
 * \file header.h
 * \brief Archivo cabecera del programa.
 * \author Leandro Kollenberger <lkollenberger@frba.utn.edu.ar>
 * \date 26.08.2016
*/

#include <stdio.h>
#include <string.h>
#include "objetos.h"
//#include <sys/types.h>
//#include <dirent.h>
//#include <errno.h>
//#include <opencv/cv.h>
//#include <highgui.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>

#define LARGO 800
#define ALTO 480
#define FPS 60

enum MYKEYS 
{
	KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT
};
enum KEYS{UP, DOWN, LEFT, RIGHT, SPACE};

//cuadrado
void IniciarCuadrado(Cuadrado *cuadrado);
void DibujarCuadrado(Cuadrado *cuadrado);
void MoverCuadradoArriba(Cuadrado *cuadrado);
void MoverCuadradoAbajo(Cuadrado *cuadrado);
void MoverCuadradoIzquierda(Cuadrado *cuadrado);
void MoverCuadradoDerecha(Cuadrado *cuadrado);





