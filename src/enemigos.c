#include "header.h"
void IniciarEnemigo1(Enemigo **enemigo)
{
//	enemigo->nombre={'D','r','a','g','o','n'};
        (*enemigo)->imagen = al_load_bitmap("./assets/dsm12set.png");
        al_convert_mask_to_alpha((*enemigo)->imagen, al_map_rgb(120, 195, 128));
	(*enemigo)->vida.x=5;
	(*enemigo)->vida.y=5;
	(*enemigo)->velocidad=2;
	(*enemigo)->danio=2;
	(*enemigo)->pocicion.x=320;
	(*enemigo)->pocicion.y=0;
	(*enemigo)->FrameActual.x=0;
	(*enemigo)->FrameActual.y=0;
	(*enemigo)->DistanciaFrames.x=32;
	(*enemigo)->DistanciaFrames.y=32;
	(*enemigo)->CantidadFrames.x=3;
	(*enemigo)->CantidadFrames.y=4;
	(*enemigo)->contador=0;
	(*enemigo)->bandera=0;
	(*enemigo)->spritey=0;
//le doy valor al enemigo
}
void IniciarEnemigo2(Enemigo **enemigo)
{
//	enemigo->nombre={'D','r','a','g','o','n'};
  (*enemigo)->imagen = al_load_bitmap("./assets/dsm12set.png");
  al_convert_mask_to_alpha((*enemigo)->imagen, al_map_rgb(120, 195, 128));
	(*enemigo)->vida.x=5;
	(*enemigo)->vida.y=5;
	(*enemigo)->velocidad=7;
	(*enemigo)->danio=2;
	(*enemigo)->pocicion.x=320;
	(*enemigo)->pocicion.y=0;
	(*enemigo)->FrameActual.x=0;
	(*enemigo)->FrameActual.y=4;
	(*enemigo)->DistanciaFrames.x=32;
	(*enemigo)->DistanciaFrames.y=32;
	(*enemigo)->CantidadFrames.x=3;
	(*enemigo)->CantidadFrames.y=4;
	(*enemigo)->contador=0;
	(*enemigo)->bandera=0;
	(*enemigo)->spritey=4;
//le doy valor al enemigo
}
void LiberarMemoriaEnemigo(Enemigo **enemigo)
{
  Enemigo *aux,*aux2;
  aux=*enemigo;
  aux2=*enemigo;
  if(aux->anterior==NULL && aux->siguiente!=NULL)
  {

    printf("ok1\n");
    aux2=aux2->siguiente;
    aux2->anterior=aux->anterior;
    *enemigo=aux2;
  }//si es el primero
  else if(aux->siguiente!=NULL && aux->anterior!=NULL)
  {
    printf("ok2\n");
    aux2->anterior->siguiente=aux2->siguiente;
    aux2->siguiente->anterior=aux2->anterior;
    aux2=aux2->anterior;
    *enemigo=aux2;
  }//si es alguno del medio
  else if(aux->anterior!=NULL&&aux->siguiente==NULL)
  {
    printf("ok3\n");
    aux2=aux2->anterior;
    aux2->siguiente=NULL;
    *enemigo=aux2;
  }//si es el ultimo
  else if(aux->anterior==NULL&&aux->siguiente==NULL)
  {
    *enemigo=NULL;
    printf("ok44444\n");
  }
  al_destroy_bitmap(aux->imagen);//libero la imagen
  free(aux);//libero el auxiliar
}/*
void LiberarMemoriaEnemigo(Enemigo **enemigo)
{
	Enemigo *aux;
	if((*enemigo)->anterior==NULL&&(*enemigo)->siguiente!=NULL)
	{
		aux=(*enemigo)->siguiente;
		aux->anterior=NULL;
		free(*enemigo);
	}
	else if((*enemigo)->anterior!=NULL&&(*enemigo)->siguiente==NULL)
	{
		aux=(*enemigo)->anterior;
		aux->siguiente=NULL;
		free(*enemigo);
	}
	else if((*enemigo)->siguiente==NULL &&(*enemigo)->anterior==NULL)
	{
		free(*enemigo);
	}
	else if((*enemigo)->siguiente!=NULL && (*enemigo)->anterior!=NULL)
	{
		aux=(*enemigo);
		(*enemigo)->anterior->siguiente=(*enemigo)->siguiente;
		(*enemigo)->siguiente->anterior=(*enemigo)->anterior;
		free(aux);
	}
}*/
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
			printf("%d\n",(*enemigo)->bandera);
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
			printf("%d\n",(*enemigo)->bandera);
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

	if((*enemigo)->bandera==11)
	{
		jugador->vida-=(*enemigo)->danio;
		LiberarMemoriaEnemigo(enemigo);
	}
	else if((*enemigo)->bandera==12)
	{
		LiberarMemoriaEnemigo(enemigo);
	}
	else
	{
		//dibuja al enemigo
		BarraDeVida(enemigo);
		al_draw_bitmap_region((*enemigo)->imagen,(*enemigo)->FrameActual.x*(*enemigo)->DistanciaFrames.x,((*enemigo)->spritey+(*enemigo)->FrameActual.y)*(*enemigo)->DistanciaFrames.y, (*enemigo)->DistanciaFrames.x, (*enemigo)->DistanciaFrames.y, (*enemigo)->pocicion.x, (*enemigo)->pocicion.y, 0);
	}
}
Enemigo *EmpezarOleada(Enemigo *enemigo, int oleada,int malo)
{
	if(oleada==1)//hace esto para la oleada
	{
		if(malo%2)//si es impar
		{
			enemigo=NuevoEnemigo(enemigo);//pide memoria para el enemigio en la lista
			IniciarEnemigo1(&enemigo);//inicia el enemigo con sus valores
		}
		else
		{
			enemigo=NuevoEnemigo(enemigo);//pide memoria para el enemigio en la lista
			IniciarEnemigo2(&enemigo);//inicia el enemigo con sus valores
		}
	}
	return enemigo;
}
Enemigo *SpawnearEnemigos(Enemigo *enemigo,Jugador *jugador)
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
		for(aux=enemigo;aux!=NULL;aux=aux->siguiente)
		{
			MoverEnemigo(&aux,jugador);
		}
		jugador->relojito++;//reloj cuando pasa 10 veces, spawnea al enemigo(pasa 1 segundo)
	}
	if(jugador->relojito==10 && enemigo!=NULL)
	{
		jugador->relojito=0;//lo pone en 0 para pasar a la proxima lista
	}
	if(enemigo!=NULL && jugador->malo==15)
	{
		jugador->oleada++;
		jugador->malo++;
		jugador->relojito=10;
	}
	return enemigo;
}
