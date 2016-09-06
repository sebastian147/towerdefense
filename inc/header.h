/**
 * \file header.h
 * \brief Archivo cabecera del programa.
 * \author Leandro Kollenberger <lkollenberger@frba.utn.edu.ar>
 * \date 26.08.2016
*/

#include <stdio.h>
#include <string.h>
//#include <sys/types.h>
//#include <dirent.h>
//#include <errno.h>
//#include <opencv/cv.h>
//#include <highgui.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>

#define WIDTH 640
#define HEIGHT 480
#define FPS 60

enum MYKEYS 
{
	KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT
};

int buscanombre(char *name, char *path);
int show_image(char *path, int num);
