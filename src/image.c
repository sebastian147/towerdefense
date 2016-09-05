/**
 * \file image.c
 * \brief Funciones de manejo de imagenes.
 * \author Alejandro Furfaro <afurfaro@electron.frba.utn.edu.ar>. Modificado por lkollenberger.
 * \date 26.08.2016
*/

#include "header.h"

/**
 * \fn int show_image(char *path, int num)
 * \brief Abre una imagen en una ventana y espera al usuario
 * \author Alejandro Furfaro. <afurfaro@electron.frba.utn.edu.ar>
 * \date 27.08.2016
 * \return Retorna cero en caso de exito, -1 en caso de error.
*/

int show_image(char *path, int num) {
  char win_name[256];
  char filename[64];

  //Instancia una estructura IplImage, definida en openCV para 
  //cargar la información de la imagen origen
  IplImage *image = cvLoadImage(path, CV_LOAD_IMAGE_ANYDEPTH);
  
  if(!image) { // error
  	return -1;
  }
  
  //Creamos una ventana autoajustable al 
  //tamaño de la imagen que le vamos a colocar dentro
  buscanombre(filename, path);
  sprintf(win_name, "Imagen %d: %s", num, filename);
  cvNamedWindow(win_name, CV_WINDOW_AUTOSIZE);
  
  //Movemos la ventana al pixel 100 de la fila 100
  cvMoveWindow(win_name, 100, 100);
  
  //Mostramos la imagen leida en la ventana creada
  cvShowImage(win_name, image);
  
  //Esperamos que el usuario presione cualquier tecla...
  cvWaitKey(1000);
  
  //Liberamos los recursos utilizados
  cvReleaseImage(&image);
  cvDestroyWindow(win_name);
  
  return 0;
}
