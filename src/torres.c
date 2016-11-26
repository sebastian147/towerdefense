
#include "header.h"
void IniciarTorre(Torre **seleccionada,Cuadrado *cuadrado,int a)
{//se abre el archivo donde estan los datos de la torre, carga en buffer de datos.torres ...
  FILE *f;
	char buff[100];
	char *token;
	char aux[20];
	int i=0;
	f=fopen("./datos/torres","r");
	if(f==NULL)
	{
		fprintf(stdin,"Error al abrir el archivo\n");
	}
	while(i!=a)
	{
		fscanf(f,"%s",buff);
		i++;
	}//con strtok lee del buff hasta ";"  y lo guarda en token
	token = strtok(buff, ";"); // token = "producto";
	(*seleccionada)->imagen = al_load_bitmap(token);
	al_convert_mask_to_alpha((*seleccionada)->imagen, al_map_rgb(0, 0, 0));
	token = strtok(NULL, ";");//copia desde donde se quedo parado el strtok ";"
	strcpy(aux,token);
	(*seleccionada)->rango=atoi(aux);
	token = strtok(NULL, ";");
	strcpy(aux,token);
	(*seleccionada)->danio=atoi(aux);
	token = strtok(NULL, ";");
	strcpy(aux,token);
	(*seleccionada)->cadencia=atoi(aux);
	token = strtok(NULL, ";");
	strcpy(aux,token);
	(*seleccionada)->tiempo=atoi(aux);
	token = strtok(NULL, ";");
	strcpy(aux,token);
	(*seleccionada)->velocidad=atoi(aux);
	token = strtok(NULL, "\n");
	strcpy(aux,token);
	(*seleccionada)->tiros=atoi(aux);
	memset((*seleccionada)->disparo,0,5);//que las 5 posiciones del string tomen como valor "0"
  (*seleccionada)->pocicion.x=cuadrado->x;//posicion torre=posicion del cuadrado
  (*seleccionada)->pocicion.y=cuadrado->y;
//le doy valor al enemigo
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
   (*primera)->disparo[(*primera)->tiros].pocicion.x=(*primera)->pocicion.x;
	 (*primera)->disparo[(*primera)->tiros].pocicion.y=(*primera)->pocicion.y;
	 (*primera)->disparo[(*primera)->tiros].pocicionenemigo.x=(*primera)->pocicionenemigo.x;
	 (*primera)->disparo[(*primera)->tiros].pocicionenemigo.y=(*primera)->pocicionenemigo.y;
	 (*primera)->disparo[(*primera)->tiros].velocidad=(*primera)->velocidad;
	 (*primera)->disparo[(*primera)->tiros].imagen = al_load_bitmap("./assets/BigPreviewFourds2.jpg");
	 al_convert_mask_to_alpha((*primera)->disparo[(*primera)->tiros].imagen, al_map_rgb(0, 0, 0));
	 (*primera)->tiros++;
	}
}
void LiberarMemoriaTorres(Torre **torre,Torre **primera)
{
  Torre *aux,*aux2;
  aux=*torre;
  aux2=*torre;
  if(aux->anterior==NULL && aux->siguiente!=NULL)
  {

    aux2=(*torre)->siguiente;
    aux2->anterior=NULL;
    *primera=aux2;
    *torre=aux2;
  }//si es el primero
  else if(aux->siguiente!=NULL && aux->anterior!=NULL)
  {
    aux2->anterior->siguiente=aux2->siguiente;
    aux2->siguiente->anterior=aux2->anterior;
    aux2=aux2->anterior;
    *torre=aux2;
  }//si es alguno del medio
  else if(aux->anterior!=NULL&&aux->siguiente==NULL)
  {
    aux2=aux2->anterior;
    aux2->siguiente=NULL;
    *torre=aux2;
  }//si es el ultimo
  else if(aux->anterior==NULL&&aux->siguiente==NULL)
  {
    *torre=NULL;
    *primera=NULL;
  }
  al_destroy_bitmap(aux->imagen);//libero la imagen
  free(aux);//libero el auxiliar
}
int DestruirTorre(Torre **seleccionada,Cuadrado *cuadrado)
{
  Torre *aux=*seleccionada;
  while(aux != NULL)
  {
    if((aux->pocicion.x == cuadrado->x && aux->pocicion.y == cuadrado->y))
    {
      LiberarMemoriaTorres(&aux, seleccionada);
      return 0;
    }
    aux=aux->siguiente;
  }
  return -1;
}
void ActualizarProyectil(Torre **primera,Enemigo **ultimo)
{
	int i=0;
	if((*primera)->tiros!=0)
	{
		for(i=0;i<(*primera)->tiros;i++)
		{
			if((*primera)->disparo[i].pocicion.x < (*primera)->pocicionenemigo.x)
			{
				(*primera)->disparo[i].pocicion.x+=(*primera)->disparo[i].velocidad;
			}
			else if((*primera)->disparo[i].pocicion.x > (*primera)->pocicionenemigo.x)
			{
				(*primera)->disparo[i].pocicion.x-=(*primera)->disparo[i].velocidad;

			}
			if((*primera)->disparo[i].pocicion.y < (*primera)->pocicionenemigo.y)
			{
				(*primera)->disparo[i].pocicion.y+=(*primera)->disparo[i].velocidad;
			}
			else if((*primera)->disparo[i].pocicion.y > (*primera)->pocicionenemigo.y)
			{
				(*primera)->disparo[i].pocicion.y-=(*primera)->disparo[i].velocidad;

			}
	//	printf("%d\n",(*primera)->pocicion.x);

			al_draw_bitmap_region((*primera)->disparo[i].imagen,15,60,18,9,(*primera)->disparo[i].pocicion.x,(*primera)->disparo[i].pocicion.y,0);
      if((((*primera)->disparo[i].pocicion.y+11 > (*ultimo)->pocicion.y) && ((*primera)->disparo[i].pocicion.y < ((*ultimo)->pocicion.y + (*ultimo)->DistanciaFrames.y))) && (((*primera)->disparo[i].pocicion.x+20 > (*ultimo)->pocicion.x) && ((*primera)->disparo[i].pocicion.x < ((*ultimo)->pocicion.x + (*ultimo)->DistanciaFrames.x))))
			{
					//al_destroy_bitmap((*primera)->disparo[i].imagen);
					(*ultimo)->vida.x-=(*primera)->danio;
					(*primera)->tiros--;

			}
		}
	}
}
void DispararAlUltimo(Torre **seleccionada,Enemigo **ultimo,Reloj *reloj)
{
	Torre *aux=*seleccionada;
	if(reloj->DentroDeFuncion==10*aux->cadencia /*&& (*ultimo)->vida.x > aux->danio*aux->tiros*/)
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
int BuscarUltimoEnRadio(Enemigo **primero,Torre **seleccionada)
{
  int j=ERROR;
  Torre *torre=*seleccionada;
  Enemigo *ultimo=*primero, *aux=*primero;
  int x,y,z;
  while(aux!=NULL)
  {
	//x=aux->pocicion.x;
	//y=aux->pocicion.y;
	//z=aux->bandera;
	//PredecirMovimiento(&aux,torre);
	//elchoclo es para calcular la distancia
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
        torre->pocicionenemigo.x=ultimo->pocicion.x;
        torre->pocicionenemigo.y=ultimo->pocicion.y;
	//ultimo->pocicion.x=x;
	//ultimo->pocicion.y=y;
	//ultimo->bandera=z;

     j=OK;
     }
	//aux->pocicion.x=x;
	//aux->pocicion.y=y;
	//aux->bandera=z;

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
      if( OK==BuscarUltimoEnRadio(&atacar,&aux))
      {
		      DispararAlUltimo(&aux,&atacar,reloj);
 		       //dispara
		         reloj->DentroDeFuncion++;//avanzo el tiempo
      }
      atacar=*primero;
    }
    aux=aux->siguiente;
  }
}
