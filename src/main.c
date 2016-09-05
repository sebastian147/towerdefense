/**
 * \file main.c
 * \brief Programa sencillo para abrir una imagen y presentarla en una ventana
 * \details Utilizamos la biblioteca Opencv para abrir la imagen aprovechando 
 * sus funciones independientes del tipo de archivo, y tambien para crear una
 * ventana sencilla (sin menu), para presentarla en la GUI del sistema operativo
 * que se tenga (Linux, Windows, o MAC OS).
 * Este programa compila en Linux, mediante el comando siguiente:
 * gcc -o img img.c `pkg-config --cflags --libs opencv` -g -ggdb -Wall 
 * \author Alejandro Furfaro <afurfaro@electron.frba.utn.edu.ar>. Modificado por lkollenberger.
 * 
 * Muy similar a http://opencv.wikispaces.com/3%29+First+Sample+Program
 * 
 * \date 12.05.2011
*/ 

#include "header.h"

/**
 * \fn int main(int argc, char *argv[])
 * \brief Muestra imagenes por linea de comandos, o las que haya en una carpeta
 * predefinida.
 * \author Alejandro Furfaro. <afurfaro@electron.frba.utn.edu.ar>
 * \date 27.08.2016
 * \return Retorna cero en caso de exito, -1 en caso de error.
*/

int main(int argc, char *argv[]) {
  int i;
  char *arg;
  char *file;
  char path[256];
  DIR *dp;
  struct dirent *ep;
  int rv;
  
  if(argc < 2) { // modo automatico
  	dp = opendir("./assets");
  	if(!dp) {
  	  perror("No pude abrir el directorio de assets :(");
  	  return -1;
  	}
  	i = 0;
  	while((ep = readdir(dp)) != NULL) {
  	  file = ep->d_name;
  	  if(strncmp(file, ".", 1) && strncmp(file, "..", 2)) { //archivo valido
  	    strcpy(path, "./assets/");
  	    strcat(path, file);
  	    rv = show_image(path, i);
  	    if(rv == -1) {
  	      fprintf(stderr, "Error mostrando imagen %s: %s\n", path, 
  	        strerror(errno));
  	    }
  	    i++;
  	  }
  	}
  	closedir(dp); 
  } else { // imagenes especificamente seleccionadas por el usuario
    for(i = 0, arg = argv[1]; arg != NULL; i++, arg++) {
      rv = show_image(arg, i);
      if(rv == -1) {
  	    fprintf(stderr, "Error mostrando imagen %s: %s\n", arg, 
  	      strerror(errno));
  	  }
    }
  }
  printf("Mostradas exitosamente %d imagenes!\n", i);
  
  //Terminamos el programa
  return 0;
}
