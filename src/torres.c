#include "header.h"
void IniciarTorre(Torre **seleccionada)
{
  
}
void MejorarTorre(Torre **seleccionada)
{

}
void Proyectil(Torre *primera)
{

}
void DestruirTorre(Torre **seleccionada)
{

}
void CrearTorre(Torre **primera)
{
  Torre *aux=NULL,*nuevaTorre=NULL;//Declaro variables
  nuevaTorre=(Torre*)malloc(sizeof(Torre));//pido memoria
  if(nuevoTorre==NULL)//pregunto si sale error
  {
    printf("Error al crear enemigo");
    return -1;
  }
  aux=*primera;//hago la variable auxiliar igual al enemigo
  if(aux==NULL)//si auxiliar no existe creo la lista
  {
    nuevaTorre->siguiente=NULL;
    nuevaTorre->anterior=NULL;
  }
  else//agrego el nuevo nodo de la lista al principio|
  {
    nuevaTorre->siguiente=aux;
    aux->anterior=nuevaTorre;
    nuevaTorre->anterior=NULL;
  }
  *primera=nuevaTorre;
}
Enemigo* BuscarUltimoEnRadio(Enemigo *primero)
{

}
