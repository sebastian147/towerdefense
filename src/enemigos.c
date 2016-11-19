#include "header.h"
void IniciarEnemigo(Enemigo **enemigo,int a)
{
//	enemigo->nombre={'D','r','a','g','o','n'};
	FILE *f;
	char buff[100];
	char *token;
	char aux[20];
	int i=0;
	f=fopen("./datos/enemigos","r");
	if(f==NULL)
	{
		fprintf(stdin,"Error al abrir el archivo\n");
	}
	while(i!=a)
	{
		fscanf(f,"%s",buff);
		i++;
	}
	token = strtok(buff, ";"); // token = "producto";
	(*enemigo)->imagen = al_load_bitmap(token);
	al_convert_mask_to_alpha((*enemigo)->imagen, al_map_rgb(120, 195, 128));
	token = strtok(NULL, ";");
	strcpy(aux,token);
	(*enemigo)->vida.x=atoi(aux);
	token = strtok(NULL, ";");
	strcpy(aux,token);
	(*enemigo)->vida.y=atoi(aux);
	token = strtok(NULL, ";");
	strcpy(aux,token);
	(*enemigo)->velocidad=atoi(aux);
	token = strtok(NULL, ";");
	strcpy(aux,token);
	(*enemigo)->danio=atoi(aux);
	token = strtok(NULL, ";");
	strcpy(aux,token);
	(*enemigo)->pocicion.x=atoi(aux);
	token = strtok(NULL, ";");
	strcpy(aux,token);
	(*enemigo)->pocicion.y=atoi(aux);
	token = strtok(NULL, ";");
	strcpy(aux,token);
	(*enemigo)->FrameActual.x=atoi(aux);
	token = strtok(NULL, ";");
	strcpy(aux,token);
	(*enemigo)->FrameActual.y=atoi(aux);
	token = strtok(NULL, ";");
	strcpy(aux,token);
	(*enemigo)->DistanciaFrames.x=atoi(aux);
	token = strtok(NULL, ";");
	strcpy(aux,token);
	(*enemigo)->DistanciaFrames.y=atoi(aux);
	token = strtok(NULL, ";");
	strcpy(aux,token);
	(*enemigo)->CantidadFrames.x=atoi(aux);
	token = strtok(NULL, ";");
	strcpy(aux,token);
	(*enemigo)->CantidadFrames.y=atoi(aux);
	token = strtok(NULL, ";");
	strcpy(aux,token);
	(*enemigo)->bandera=atoi(aux);
	token = strtok(NULL, ";");
	strcpy(aux,token);
	(*enemigo)->contador=atoi(aux);
	token = strtok(NULL, ";");
	strcpy(aux,token);
	(*enemigo)->spritey=atoi(aux);
	token = strtok(NULL, ";");
	strcpy(aux,token);
	(*enemigo)->dinero=atoi(aux);
	token = strtok(NULL, "\0");
	strcpy(aux,token);
	(*enemigo)->puntaje=atoi(aux);

//le doy valor al enemigo
}
void LiberarMemoriaEnemigo(Enemigo **enemigo,Enemigo **primero)
{
  Enemigo *aux,*aux2;
  aux=*enemigo;
  aux2=*enemigo;
  if(aux->anterior==NULL && aux->siguiente!=NULL)
  {

    aux2=(*enemigo)->siguiente;
    aux2->anterior=NULL;
    *primero=aux2;
    *enemigo=aux2;
  }//si es el primero
  else if(aux->siguiente!=NULL && aux->anterior!=NULL)
  {
    aux2->anterior->siguiente=aux2->siguiente;
    aux2->siguiente->anterior=aux2->anterior;
    aux2=aux2->anterior;
    *enemigo=aux2;
  }//si es alguno del medio
  else if(aux->anterior!=NULL&&aux->siguiente==NULL)
  {
    aux2=aux2->anterior;
    aux2->siguiente=NULL;
    *enemigo=aux2;
  }//si es el ultimo
  else if(aux->anterior==NULL&&aux->siguiente==NULL)
  {
    *enemigo=NULL;
    *primero=NULL;
  }
  al_destroy_bitmap(aux->imagen);//libero la imagen
  free(aux);//libero el auxiliar
}
void BarraDeVida(Enemigo **enemigo)
{
	float porcentaje=(32.0)/((*enemigo)->vida.y);//saco el porcentaje de la barra de vida
	if(porcentaje*(*enemigo)->vida.x>0)
	{
    al_draw_filled_rectangle((*enemigo)->pocicion.x,(*enemigo)->pocicion.y-5,(*enemigo)->pocicion.x+32,(*enemigo)->pocicion.y,al_map_rgb(0, 255, 0));//dibujo la barra verde
		al_draw_filled_rectangle((*enemigo)->pocicion.x+(porcentaje*(*enemigo)->vida.x),(*enemigo)->pocicion.y-5,(*enemigo)->pocicion.x+32,(*enemigo)->pocicion.y,al_map_rgb(255, 0, 0));//dibujo la barra roja
	}
	else
	{
		(*enemigo)->bandera=12;//si la vida es 0 que salga con un flag para liberarla despues
	}
}
Enemigo * NuevoEnemigo(Enemigo *enemigo)
{

	Enemigo *aux=NULL,*nuevoEnemigo=NULL;//Declaro variables
	nuevoEnemigo=(Enemigo *)malloc(sizeof(Enemigo));//pido memoria
	if(nuevoEnemigo==NULL)//pregunto si sale error
	{
		printf("Error al crear enemigo");
		return -1;
	}
	aux=enemigo;//hago la variable auxiliar igual al enemigo
	if(aux==NULL)//si auxiliar no existe creo la lista
	{
		nuevoEnemigo->siguiente=NULL;
		nuevoEnemigo->anterior=NULL;
	}
	else//agrego el nuevo nodo de la lista al principio|
	{
		nuevoEnemigo->siguiente=aux;
		aux->anterior=nuevoEnemigo;
		nuevoEnemigo->anterior=NULL;
	}
	return nuevoEnemigo;//retorno el puntero al principio
}
void MoverEnemigoAbajo(int final,Enemigo **enemigo,int bandera)
{
	if ((*enemigo)->bandera==bandera)//compara el flag para elegir que orden hace
	{
		(*enemigo)->FrameActual.y=0;//mueve el sprite en el eje y
		if(++(*enemigo)->contador >= 3)
		{
			if(++(*enemigo)->FrameActual.x >= (*enemigo)->CantidadFrames.x)
				(*enemigo)->FrameActual.x = 0;//mueve entre los frames del enemigo
			(*enemigo)->contador= 0;//vuelvo a iniciar el sprite
		}
		(*enemigo)->pocicion.y+=(*enemigo)->velocidad;//cambia el valor de la pocicion del enemigo
		if((*enemigo)->pocicion.y >= CUADRADOY*final)
		{
			(*enemigo)->bandera=bandera+1;//pone un flag cuando llega al final de la linea
		}
		if(bandera==11)
	        {
                	al_destroy_bitmap((*enemigo)->imagen);
       	 	}

	}
}
void MoverEnemigoIzquierda(int final,Enemigo **enemigo,int bandera)
{
	if ((*enemigo)->bandera==bandera)//compara el flag para elegir que orden hace
	{
		(*enemigo)->FrameActual.y=1;//mueve el sprite en el eje y
		if(++(*enemigo)->contador >= 3)
		{
			if(++(*enemigo)->FrameActual.x >= (*enemigo)->CantidadFrames.x)
				(*enemigo)->FrameActual.x = 0;//mueve entre los frames del enemigo

			(*enemigo)->contador= 0;//vuelvo a iniciar el sprite
		}
		(*enemigo)->pocicion.x-=(*enemigo)->velocidad;//cambia el valor de la pocicion del enemigo
		if((*enemigo)->pocicion.x <= CUADRADOX*final)
			(*enemigo)->bandera=bandera+1;
	}
}
void MoverEnemigoDerecha(int final,Enemigo **enemigo,int bandera)
{
	if ((*enemigo)->bandera==bandera)//compara el flag para elegir que orden hace
	{
		(*enemigo)->FrameActual.y=2;//mueve el sprite en el eje y
		if(++(*enemigo)->contador >= 3)
		{
			if(++(*enemigo)->FrameActual.x >= (*enemigo)->CantidadFrames.x)
				(*enemigo)->FrameActual.x = 0;//mueve entre los frames del enemigo

			(*enemigo)->contador= 0;//vuelvo a iniciar el sprite
		}
		(*enemigo)->pocicion.x+=(*enemigo)->velocidad;//cambia el valor de la pocicion del enemigo
		if((*enemigo)->pocicion.x >= CUADRADOX*final)
			(*enemigo)->bandera=bandera+1;//pone un flag cuando llega al final de la linea
	}
}
void MoverEnemigoArriba(int final,Enemigo **enemigo,int bandera)
{
	if ((*enemigo)->bandera==bandera)//compara el flag para elegir que orden hace
	{
		(*enemigo)->FrameActual.y=3;//mueve el sprite en el eje y
		if(++(*enemigo)->contador >= 3)
		{
			if(++(*enemigo)->FrameActual.x >= (*enemigo)->CantidadFrames.x)
				(*enemigo)->FrameActual.x = 0;//mueve entre los frames del enemigo
			(*enemigo)->contador= 0;//vuelvo a iniciar el sprite
		}
		(*enemigo)->pocicion.y-=(*enemigo)->velocidad;//cambia el valor de la pocicion del enemigo
		if((*enemigo)->pocicion.y <= CUADRADOY*final)
			(*enemigo)->bandera=bandera+1;//pone un flag cuando llega al final de la linea
	}
}
void MoverEnemigo(Enemigo **enemigo, Jugador *jugador)
{

	MoverEnemigoAbajo(1,enemigo,0);
	MoverEnemigoIzquierda(1,enemigo,1);
	MoverEnemigoAbajo(10,enemigo,2);
	MoverEnemigoDerecha(7,enemigo,3);
	MoverEnemigoArriba(5,enemigo,4);
	MoverEnemigoIzquierda(5,enemigo,5);
	MoverEnemigoAbajo(8,enemigo,6);
	MoverEnemigoIzquierda(3,enemigo,7);
	MoverEnemigoArriba(3,enemigo,8);
	MoverEnemigoDerecha(10,enemigo,9);
	MoverEnemigoAbajo(12,enemigo,10);


	//dibuja al enemigo
	BarraDeVida(enemigo);
	al_draw_bitmap_region((*enemigo)->imagen,(*enemigo)->FrameActual.x*(*enemigo)->DistanciaFrames.x,((*enemigo)->spritey+(*enemigo)->FrameActual.y)*(*enemigo)->DistanciaFrames.y, (*enemigo)->DistanciaFrames.x, (*enemigo)->DistanciaFrames.y, (*enemigo)->pocicion.x, (*enemigo)->pocicion.y, 0);


}
Enemigo *EmpezarOleada(Enemigo *enemigo, int oleada,int malo)
{
	if(oleada==1)//hace esto para la oleada
	{
		if(malo%2)//si es impar
		{
			enemigo=NuevoEnemigo(enemigo);//pide memoria para el enemigio en la lista
			IniciarEnemigo(&enemigo,1);//inicia el enemigo con sus valores
		}
		else
		{
			enemigo=NuevoEnemigo(enemigo);//pide memoria para el enemigio en la lista
			IniciarEnemigo(&enemigo,2);//inicia el enemigo con sus valores
		}
	}
	else if(oleada==2)//hace esto para la oleada
	{
			enemigo=NuevoEnemigo(enemigo);//pide memoria para el enemigio en la lista
			IniciarEnemigo(&enemigo,1);//inicia el enemigo con sus valores
	}
	else if(oleada==3)//hace esto para la oleada
	{
			enemigo=NuevoEnemigo(enemigo);//pide memoria para el enemigio en la lista
			IniciarEnemigo(&enemigo,2);//inicia el enemigo con sus valores
	}
	else
	{
			enemigo=NuevoEnemigo(enemigo);//pide memoria para el enemigio en la lista
			IniciarEnemigo(&enemigo,2);//inicia el enemigo con sus valores
	}
	return enemigo;
}
Enemigo *SpawnearEnemigos(Enemigo *enemigo,Jugador *jugador,bool *RelojSalida)
{
	Enemigo *aux;
	if(jugador->relojito==0&&jugador->malo!=15)
	{
		enemigo=EmpezarOleada(enemigo,jugador->oleada,jugador->malo);//empieza la oleada
		jugador->malo++;//aumenta la cantidad de enemigos que se spawnean
	}
	if(enemigo!=NULL)
	{
		//mueve a los enemigos recorriendo la lista
    		aux=enemigo;
		while(aux!=NULL)
		{
			MoverEnemigo(&aux,jugador);

			if(aux->bandera==11)
			{
				jugador->vida-=aux->danio;
				LiberarMemoriaEnemigo(&aux,&enemigo);
			}//si llega al final resta vida
			else if(aux->bandera==12)
			{
				jugador->plata+=aux->dinero;
				jugador->score+=aux->puntaje;
				LiberarMemoriaEnemigo(&aux,&enemigo);
			}//muere en el camino
			if(aux!=NULL)
			{
				aux=aux->siguiente;
			}//me crashaba asi que le puse esta condicion para que solo lo haga


		}
		jugador->relojito++;//reloj cuando pasa 10 veces, spawnea al enemigo(pasa 1 segundo)
	}
	if(jugador->relojito==10 && enemigo!=NULL)
	{
		jugador->relojito=0;//lo pone en 0 para pasar a la proxima lista
	}
/*	if(enemigo!=NULL && jugador->malo==15)
	{
		jugador->oleada++;
		jugador->malo++;
		jugador->relojito=10;
	}*///no se si es util me olvide que hace
	  if(enemigo==NULL&&jugador->malo==15)
	  {
	    jugador->oleada++;
	    jugador->malo=0;
			jugador->relojito=0;
	    *RelojSalida=false;
	  }//vuelve a los valores iniciales y avanza de oleada
	return enemigo;
}
void BuscarUltimoEnLaLista(Enemigo *primero)
{
  while(primero!=NULL)
  {
	//printf("%dbandera\n\n",primero->bandera);
      primero=primero->siguiente;
  }
printf("\n\n\n");
}
//lo uso para debuguear imprime las banderas de los enemigos
void PredecirMovimiento(Enemigo **aux, Torre *torre)
{
	Enemigo *enemigo=*aux;
	int i=0;
	/*for(i=1;fabs(sqrt(pow(enemigo->pocicion.x+enemigo->DistanciaFrames.x-(torre->pocicion.x+25),2)+pow(enemigo->pocicion.y+enemigo->DistanciaFrames.y-(torre->pocicion.y+25),2))) < torre->rango*CUADRADOX || fabs(sqrt(pow(enemigo->pocicion.x-(torre->pocicion.x+25),2)+pow(enemigo->pocicion.y-(torre->pocicion.y+25),2))) < (torre->rango*CUADRADOX) || fabs(sqrt(pow(enemigo->pocicion.x+enemigo->DistanciaFrames.x-(torre->pocicion.x+25),2)+pow(enemigo->pocicion.y-(torre->pocicion.y+25),2))) < torre->rango*CUADRADOX || fabs(sqrt(pow(enemigo->pocicion.x-(torre->pocicion.x+25),2)+pow(enemigo->pocicion.y+enemigo->DistanciaFrames.y-(torre->pocicion.y+25),2))) < (torre->rango*CUADRADOX) /(i*torre->velocidad*torre->cadencia*10)>2;i++)
	{	*/for(i=1;fabs(sqrt(pow(enemigo->pocicion.x+enemigo->DistanciaFrames.x/2-(torre->pocicion.x+25),2)+pow(enemigo->pocicion.y+enemigo->DistanciaFrames.y/2-(torre->pocicion.y+25),2)))/(i*torre->velocidad*torre->cadencia*10)>1;i++)
	{
		MoverEnemigoAbajo(1,&enemigo,0);
		MoverEnemigoIzquierda(1,&enemigo,1);
		MoverEnemigoAbajo(10,&enemigo,2);
		MoverEnemigoDerecha(7,&enemigo,3);
		MoverEnemigoArriba(5,&enemigo,4);
		MoverEnemigoIzquierda(5,&enemigo,5);
		MoverEnemigoAbajo(8,&enemigo,6);
		MoverEnemigoIzquierda(3,&enemigo,7);
		MoverEnemigoArriba(3,&enemigo,8);
		MoverEnemigoDerecha(10,&enemigo,9);
		MoverEnemigoAbajo(12,&enemigo,10);
	}
			//enemigo->pocicion.x-=4;
			//enemigo->pocicion.y-=4;

	/*while(fabs(sqrt(pow(enemigo->pocicion.x+enemigo->DistanciaFrames.x-(torre->pocicion.x+25),2)+pow(enemigo->pocicion.y+enemigo->DistanciaFrames.y-(torre->pocicion.y+25),2))) < torre->rango*CUADRADOX || fabs(sqrt(pow(enemigo->pocicion.x-(torre->pocicion.x+25),2)+pow(enemigo->pocicion.y-(torre->pocicion.y+25),2))) < (torre->rango*CUADRADOX) || fabs(sqrt(pow(enemigo->pocicion.x+enemigo->DistanciaFrames.x-(torre->pocicion.x+25),2)+pow(enemigo->pocicion.y-(torre->pocicion.y+25),2))) < torre->rango*CUADRADOX || fabs(sqrt(pow(enemigo->pocicion.x-(torre->pocicion.x+25),2)+pow(enemigo->pocicion.y+enemigo->DistanciaFrames.y-(torre->pocicion.y+25),2))) > (torre->rango*CUADRADOX))
	{*/

		/*else
		{
			(enemigo)=enemigo->anterior;
			x=enemigo->pocicion.x;
			y=enemigo->pocicion.y;
			z=enemigo->bandera;


			MoverEnemigoAbajo(1,&enemigo,0);
			MoverEnemigoIzquierda(1,&enemigo,1);
			MoverEnemigoAbajo(10,&enemigo,2);
			MoverEnemigoDerecha(7,&enemigo,3);
			MoverEnemigoArriba(5,&enemigo,4);
			MoverEnemigoIzquierda(5,&enemigo,5);
			MoverEnemigoAbajo(8,&enemigo,6);
			MoverEnemigoIzquierda(3,&enemigo,7);
			MoverEnemigoArriba(3,&enemigo,8);
			MoverEnemigoDerecha(10,&enemigo,9);
			MoverEnemigoAbajo(12,&enemigo,10);
		}
	}*/
}
