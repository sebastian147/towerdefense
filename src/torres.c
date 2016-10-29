#include "header.h"
void IniciarTorre(Torre **seleccionada,Cuadrado *cuadrado)
{
    (*seleccionada)->imagen = al_load_bitmap("./assets/BigPreviewThree.jpg");
    al_convert_mask_to_alpha((*seleccionada)->imagen, al_map_rgb(255, 255, 255));
    (*seleccionada)->rango=3;
    (*seleccionada)->danio=2;
    (*seleccionada)->pocicion.x=cuadrado->x;
    (*seleccionada)->pocicion.y=cuadrado->y;
    (*seleccionada)->cadencia=2;
    (*seleccionada)->tiempo=0;
    memset((*seleccionada)->disparo,0,5);
    (*seleccionada)->velocidad=10;
    (*seleccionada)->tiros=0;

}
int HayTorre(Cuadrado *cuadrado,Torre *torre)
{
	while(torre!=NULL)
	{
		if(cuadrado->x == torre->pocicion.x && cuadrado->y == torre->pocicion.y)
			return OK;//si el cuadrado esta sobre la pocicion de una torre retorna ok
		torre=torre->siguiente;
	}
	return ERROR;
}
void MejorarTorre(Torre **seleccionada)
{

}
void NuevoProyectil(Torre **primera)
{
	if((*primera)->tiros<4)
	{
	int i,j,l;
	(*primera)->disparo[(*primera)->tiros].pocicion.x=(*primera)->pocicion.x;
	(*primera)->disparo[(*primera)->tiros].pocicion.y=(*primera)->pocicion.y;
	(*primera)->disparo[(*primera)->tiros].velocidad=(*primera)->velocidad;
	(*primera)->disparo[(*primera)->tiros].imagen = al_load_bitmap("./assets/BigPreviewFourds2.jpg");
	for(i=250,j=250,l=250;l!=255;l++,j++,i++)
	{
		al_convert_mask_to_alpha((*primera)->disparo[(*primera)->tiros].imagen, al_map_rgb(j, i, l));
	}	
	(*primera)->tiros++;
	}
/*	int i,j,l;
	Bala *nueva=NULL;
	nueva=(Bala*)malloc(sizeof(Bala));
	if(nueva==NULL)
	{
		printf("ERROR\n");//si no hay memoria imprimo error
	}
	if((*primera)->disparo==NULL)
	{

		(*primera)->disparo=nueva;

		(*primera)->disparo->siguiente=NULL;

	}//si es el primero lo agrego
	else
	{
		nueva->siguiente=(*primera)->disparo;
		(*primera)->disparo=nueva;
	}//si ya hay lo pongo como el primero
	nueva->pocicion.x=(*primera)->pocicion.x;
	nueva->pocicion.y=(*primera)->pocicion.y;
	nueva->velocidad=(*primera)->velocidad;
	nueva->imagen = al_load_bitmap("./assets/BigPreviewFourds2.jpg");
	for(i=250,j=250,l=250;l!=255;l++,j++,i++)
	{
		al_convert_mask_to_alpha(nueva->imagen, al_map_rgb(j, i, l));
	}	
	(*primera)->tiros++;
*/
}
void DestruirTorre(Torre **seleccionada)
{

}
int CantidadDeBalas(Torre *seleccionada)
{
	return OK;
}
void ActualizarProyectil(Torre **primera,Enemigo **ultimo)
{
	int i=0;
	if((*primera)->tiros!=0)
	{
		for(i=0;i<(*primera)->tiros;i++)
		{
			if((*primera)->disparo[i].pocicion.x < (*ultimo)->pocicion.x)
			{
				(*primera)->disparo[i].pocicion.x+=(*primera)->disparo[i].velocidad;
			}
			else if((*primera)->disparo[i].pocicion.x > (*ultimo)->pocicion.x)
			{
				(*primera)->disparo[i].pocicion.x-=(*primera)->disparo[i].velocidad;

			}
			if((*primera)->disparo[i].pocicion.y < (*ultimo)->pocicion.y)
			{
				(*primera)->disparo[i].pocicion.y+=(*primera)->disparo[i].velocidad;
			}
			else if((*primera)->disparo[i].pocicion.y > (*ultimo)->pocicion.y)
			{
				(*primera)->disparo[i].pocicion.y-=(*primera)->disparo[i].velocidad;

			}
		//printf("LLEGUE\n");

			al_draw_bitmap_region((*primera)->disparo[i].imagen,15,60,18,9,(*primera)->disparo[i].pocicion.x,(*primera)->disparo[i].pocicion.y,0);

			if((((*primera)->disparo[i].pocicion.y > (*ultimo)->pocicion.y) && ((*primera)->disparo[i].pocicion.y < ((*ultimo)->pocicion.y + (*ultimo)->DistanciaFrames.y))) && (((*primera)->disparo[i].pocicion.x > (*ultimo)->pocicion.x) && ((*primera)->disparo[i].pocicion.x < ((*ultimo)->pocicion.x + (*ultimo)->DistanciaFrames.x))))
			{
					//al_destroy_bitmap((*primera)->disparo[i].imagen);
					(*ultimo)->vida.x-=(*primera)->danio;
					(*primera)->tiros--;
					
			}
		}
	}
/*
	if(aux!=NULL)
	{
		while(aux!=NULL)
		{

		
			if(aux->pocicion.x == aux->pocicionenemigo.x)
			{
			}
			else if(aux->pocicion.x < aux->pocicionenemigo.x)
			{
				aux->pocicion.x+=aux->velocidad;
			}
			else if(aux->pocicion.x > aux->pocicionenemigo.x)
			{
				aux->pocicion.x-=aux->velocidad;

			}
			if(aux->pocicion.y == aux->pocicionenemigo.y)
			{
			}
			else if(aux->pocicion.y < aux->pocicionenemigo.y)
			{
				aux->pocicion.y+=aux->velocidad;
			}
			else if(aux->pocicion.y > aux->pocicionenemigo.y)
			{
				aux->pocicion.y-=aux->velocidad;

			}
			if(aux->pocicion.x < (*ultimo)->pocicion.x)
			{
				aux->pocicion.x+=aux->velocidad;
			}
			else if(aux->pocicion.x > (*ultimo)->pocicion.x)
			{
				aux->pocicion.x-=aux->velocidad;

			}
			if(aux->pocicion.y < (*ultimo)->pocicion.y)
			{
				aux->pocicion.y+=aux->velocidad;
			}
			else if(aux->pocicion.y > (*ultimo)->pocicion.y)
			{
				aux->pocicion.y-=aux->velocidad;

			}
			    al_draw_bitmap_region(aux->imagen,15,60,18,9,aux->pocicion.x,aux->pocicion.y,0);

			if(((aux->pocicion.y > (*ultimo)->pocicion.y) && (aux->pocicion.y < ((*ultimo)->pocicion.y + (*ultimo)->DistanciaFrames.y))) && ((aux->pocicion.x > (*ultimo)->pocicion.x) && (aux->pocicion.x < ((*ultimo)->pocicion.x + (*ultimo)->DistanciaFrames.x))))
			//if(comets[i].x - comets[i].boundx < ship->x + ship->boundx &&
			//	comets[i].x + comets[i].boundx > ship->x - ship->boundx &&
			//	comets[i].y - comets[i].boundy < ship->y + ship->boundy &&
			//	comets[i].y + comets[i].boundy > ship->y - ship->boundy)
			{
				(*ultimo)->vida.x-=(*seleccionada)->danio;
				if(aux->siguiente==NULL)
				{
					al_destroy_bitmap(aux->imagen);
					free(aux);
					printf("oK2\n");
					aux2->siguiente=NULL;
					aux=aux2;
					//printf("oK31231\n");
					al_destroy_bitmap(aux->imagen);
					(*seleccionada)->disparo=NULL;
					free(aux);
					aux=NULL;
					//printf("oK2\n");
				}
				else if(aux == aux2 && aux != NULL)
				{
					//printf("oK31231\n");
					al_destroy_bitmap(aux->imagen);
					(*seleccionada)->disparo=NULL;
					free(aux);
					aux=NULL;
					//printf("oK312312\n");
				}//revisar
			}
			aux2=aux;	
			if(aux!=NULL)
			{
				aux=aux->siguiente;//voy al siguiente tiro
			}
		}
	}
*/
}
void DispararAlUltimo(Torre **seleccionada,Enemigo **ultimo,Reloj *reloj)
{
	Torre *aux=*seleccionada;
	if(reloj->DentroDeFuncion==10*aux->cadencia && (*ultimo)->vida.x > aux->danio*aux->tiros)
	{
		NuevoProyectil(seleccionada);//crea un nuevo proyectil
		reloj->DentroDeFuncion=0;//pone en 0 el reloj
	}
	ActualizarProyectil(seleccionada,ultimo);//actualiza el proyectil anterior

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
  int j=ERROR;
  Enemigo *ultimo=*primero, *aux=*primero;
  		
  
  while(aux!=NULL)
  {	//elchoclo es para calcular la distancia
      if(fabs(sqrt(pow(aux->pocicion.x+aux->DistanciaFrames.x-(torre->pocicion.x+25),2)+pow(aux->pocicion.y+aux->DistanciaFrames.y-(torre->pocicion.y+25),2))) < torre->rango*CUADRADOX || fabs(sqrt(pow(aux->pocicion.x-(torre->pocicion.x+25),2)+pow(aux->pocicion.y-(torre->pocicion.y+25),2))) < (torre->rango*CUADRADOX) || fabs(sqrt(pow(aux->pocicion.x+aux->DistanciaFrames.x-(torre->pocicion.x+25),2)+pow(aux->pocicion.y-(torre->pocicion.y+25),2))) < torre->rango*CUADRADOX || fabs(sqrt(pow(aux->pocicion.x-(torre->pocicion.x+25),2)+pow(aux->pocicion.y+aux->DistanciaFrames.y-(torre->pocicion.y+25),2))) < (torre->rango*CUADRADOX))
      {
        if(aux->bandera==0 || aux->bandera==2 || aux->bandera==6 || aux->bandera==10)
        {
          if(aux->pocicion.y > ultimo->pocicion.y)
          {
            ultimo=aux;
          }
        }
        else if(aux->bandera==1 || aux->bandera==5 || aux->bandera==7)
        {
          if(aux->pocicion.x < ultimo->pocicion.x)
          {
            ultimo=aux;
          }
        }

        else if(aux->bandera==3 || aux->bandera==9)
        {
          if(aux->pocicion.x > ultimo->pocicion.x)
          {
            ultimo=aux;
          }
        }
        else if(aux->bandera==4 || aux->bandera==8)
        {
          if(aux->pocicion.y < ultimo->pocicion.y)
          {
            ultimo=aux;
          }
        }//busco segun el camino el ultimo

     j=OK;
     }
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
	//dibujo la torre
    if(cuadrado->x==aux->pocicion.x&&cuadrado->y==aux->pocicion.y)
	 al_draw_circle(cuadrado->x+25,cuadrado->y+25,aux->rango*CUADRADOX, al_map_rgb(255, 255, 255),0);
    		//dibujo el circulo cuando el cuadrado esta sobre la torre
    if(*primero!=NULL)
    {
      if(/*aux->tiempo==aux->cadencia && agregarle cadencia*/ OK==BuscarUltimoEnRadio(&atacar,aux))
      {
		
		DispararAlUltimo(&aux,&atacar,reloj);
 		//dispara
	               //atacar->vida.x-=aux->danio;
		    reloj->DentroDeFuncion++;//avanzo el tiempo
      }
      atacar=*primero;
    }
    aux=aux->siguiente;
  }
}
