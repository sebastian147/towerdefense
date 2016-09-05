/**
 * \file header.h
 * \brief Archivo cabecera del programa.
 * \author Leandro Kollenberger <lkollenberger@frba.utn.edu.ar>
 * \date 26.08.2016
*/

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <opencv/cv.h>
#include <highgui.h>

int buscanombre(char *name, char *path);
int show_image(char *path, int num);
