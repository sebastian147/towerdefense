/**
 * \file aux.c
 * \brief Funciones auxiliares al programa.
 * \author Leandro Kollenberger <lkollenberger@frba.utn.edu.ar>
 * \date 26.08.2016
*/

#include "header.h"

/**
 * \fn int buscanombre(char *name, char *path)
 * \brief Busca el nombre del archivo dentro de una ruta completa
 * \author Leandro Kollenberger <lkollenberger@frba.utn.edu.ar>
 * \date 27.08.2016
 * \return Retorna siempre cero.
 * \bug No verifica si los parametros son validos
*/

int buscanombre(char *name, char *path) {
  char *last_slash;
  size_t len;
  int i;
  
  len = strlen(path);
  last_slash = path;
  
  for(i = 0; i < len; i++) {
    if(path[i] == '\\' || path[i] == '/') { // encontre una barra
      last_slash = path + i;
    }
  }
  
  strcpy(name, last_slash + 1);
  return 0;
}
