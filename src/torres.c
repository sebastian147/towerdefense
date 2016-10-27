#include "header.h"
void IniciarTorre(Torre **seleccionada,Cuadrado *cuadrado)
{
    (*seleccionada)->imagen = al_load_bitmap("./assets/BigPreviewThree.jpg");
    al_convert_mask_to_alpha((*seleccionada)->imagen, al_map_rgb(255, 255, 255));
    (*seleccionada)->rango=3;
    (*seleccionada)->danio=5;
    (*seleccionada)->pocicion.x=cuadrado->x;
    (*seleccionada)->pocicion.y=cuadrado->y;
    (*seleccionada)->cadencia=1;
    (*seleccionada)->tiempo=0;
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
void DispararAlUltimo(Torre *seleccionada,Enemigo **ultimo)
{
  Torre *aux=seleccionada;

}
void CrearTorre(Torre **primera)
{
  Torre *aux=NULL,*nuevaTorre=NULL;//Declaro variables
  nuevaTorre=(Torre*)malloc(sizeof(Torre));//pido memoria
  if(nuevaTorre==NULL)//pregunto si sale error
  {
    printf("Error al crear torre");
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
int BuscarUltimoEnRadio(Enemigo **primero,Torre *torre)
{
  int /*i=0,l,*/j=ERROR;
  Enemigo *ultimo=*primero, *aux=*primero;
  while(aux!=NULL)
  {
    /*for(i=0,l=3;i<=PI && l < 2*PI ;i++,l++)
    {
      if((aux->pocicion.x < torre->rango*cos(i)+torre->pocicion.x)&&(aux->pocicion.y < torre->rango*sin(i)+torre->pocicion.y)||(aux->pocicion.x < torre->rango*cos(l)+torre->pocicion.x)&&(aux->pocicion.y < torre->rango*sin(l)+torre->pocicion.y))
      */
      if(fabs(sqrt(pow(aux->pocicion.x+aux->DistanciaFrames.x-(torre->pocicion.x+25),2)+pow(aux->pocicion.y+aux->DistanciaFrames.y-(torre->pocicion.y+25),2)))<(torre->rango*CUADRADOX))
      {
        if(aux->bandera==0 || aux->bandera==2 || aux->bandera==6 || aux->bandera==10)
        {
          if(aux->pocicion.y > ultimo->pocicion.y)
          {
            ultimo=aux;
            j=OK;
          }
        }
        else if(aux->bandera==1 || aux->bandera==5 || aux->bandera==7)
        {
          if(aux->pocicion.x < ultimo->pocicion.x)
          {
            ultimo=aux;
            j=OK;
          }
        }

        else if(aux->bandera==3 || aux->bandera==9)
        {
          if(aux->pocicion.x > ultimo->pocicion.x)
          {
            ultimo=aux;
            j=OK;

          }
        }
        else if(aux->bandera==4 || aux->bandera==8)
        {
          if(aux->pocicion.y < ultimo->pocicion.y)
          {
            ultimo=aux;
            j=OK;
          }
        }//busco segun el camino el ultimo
      }
    //}
    aux=aux->siguiente;
  }
  *primero=ultimo;
  return j;
}
void ActualizarTorre(Torre **primera,Cuadrado *cuadrado,Enemigo **primero,Reloj *reloj)
{
  Torre *aux=*primera;
  Enemigo *atacar=*primero;
  int i;
  while(aux!=NULL)
  {
    al_draw_bitmap_region(aux->imagen,150,50,50,50,aux->pocicion.x,aux->pocicion.y,0);
      al_draw_circle(cuadrado->x+25,cuadrado->y+25,aux->rango*CUADRADOX, al_map_rgb(255, 255, 255),0);
    if(*primero!=NULL)
    {
      if(/*aux->tiempo==aux->cadencia && agregarle cadencia*/ 0==BuscarUltimoEnRadio(&atacar,aux))
      {
                atacar->vida.x=2;
      }
      atacar=*primero;
    }
    reloj->DentroDeFuncion++;
    aux=aux->siguiente;
  }
}
