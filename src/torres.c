#include "header.h"
void IniciarTorre(Torre **seleccionada,Cuadrado *cuadrado)
{
  (*seleccionada)->imagen = al_load_bitmap("./assets/PromoImages.jpg");
  (*seleccionada)->rango=3;
  (*seleccionada)->danio=5;
  (*seleccionada)->pocicion.x=cuadrado->x;
  (*seleccionada)->pocicion.y=cuadrado->y;
  (*seleccionada)->cadencia=1;
  al_draw_bitmap_region((*seleccionada)->imagen,100,70,140,32,(*seleccionada)->pocicion.x,(*seleccionada)->pocicion.y,0);
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
  if(nuevaTorre==NULL)//pregunto si sale error
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
void ActualizarTorre(Torre **primera)
{
  Torre *aux=*primera;
  while(aux!=NULL)
  {
    al_draw_bitmap_region(aux->imagen,0,0,0,0,aux->pocicion.x,aux->pocicion.y,0);
    aux=aux->siguiente;
  }
}
