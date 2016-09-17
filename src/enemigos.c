#include "header.h"
void IniciarEnemigo1(Enemigo *enemigo)
{
//	enemigo->nombre={'D','r','a','g','o','n'};
        enemigo->imagen = al_load_bitmap("./assets/dsm12set.png");
        al_convert_mask_to_alpha(enemigo->imagen, al_map_rgb(120, 195, 128));
	enemigo->vida.x=5;
	enemigo->vida.y=5;
	enemigo->velocidad=2;
	enemigo->danio=2;
	enemigo->pocicion.x=320;
	enemigo->pocicion.y=0;
	enemigo->FrameActual.x=0;
	enemigo->FrameActual.y=0;
	enemigo->DistanciaFrames.x=32;
	enemigo->DistanciaFrames.y=32;
	enemigo->CantidadFrames.x=3;
	enemigo->CantidadFrames.y=4;
	enemigo->contador=0;
	enemigo->bandera=0;
	enemigo->spritey=0;
//le doy valor al enemigo 	
}
void IniciarEnemigo2(Enemigo *enemigo)
{
//	enemigo->nombre={'D','r','a','g','o','n'};
        enemigo->imagen = al_load_bitmap("./assets/dsm12set.png");
        al_convert_mask_to_alpha(enemigo->imagen, al_map_rgb(120, 195, 128));
	enemigo->vida.x=5;
	enemigo->vida.y=5;
	enemigo->velocidad=7;
	enemigo->danio=2;
	enemigo->pocicion.x=320;
	enemigo->pocicion.y=0;
	enemigo->FrameActual.x=0;
	enemigo->FrameActual.y=4;
	enemigo->DistanciaFrames.x=32;
	enemigo->DistanciaFrames.y=32;
	enemigo->CantidadFrames.x=3;
	enemigo->CantidadFrames.y=4;
	enemigo->contador=0;
	enemigo->bandera=0;
	enemigo->spritey=4;
//le doy valor al enemigo 	
}
void BarraDeVida(Enemigo *enemigo)
{
	float porcentaje=(32.0)/(enemigo->vida.y);
	if(porcentaje*enemigo->vida.x>0)
	{
       		al_draw_filled_rectangle(enemigo->pocicion.x,enemigo->pocicion.y-5,enemigo->pocicion.x+32,enemigo->pocicion.y,al_map_rgb(0, 255, 0));
		al_draw_filled_rectangle(enemigo->pocicion.x+(porcentaje*enemigo->vida.x),enemigo->pocicion.y-5,enemigo->pocicion.x+32,enemigo->pocicion.y,al_map_rgb(255, 0, 0));
	}
	else
	{
		enemigo->bandera=12;
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
		nuevoEnemigo->anterior=aux->anterior;
	}
	return nuevoEnemigo;//retorno el puntero al principio
	/*
        Enemigo *nuevo;
        nuevo=(Enemigo *) malloc(sizeof(Enemigo));//pido memoria para el struct enemigo
        if (anterior)//si es el
        {
                nuevo->siguiente=anterior;
        }
        else
        {
                nuevo->siguiente=NULL;
        }
        return nuevo;*/
}
/*void OrdenarEnemigos(Enemigo *enemigo)
{
	Enemigo *aux1,*aux2,*aux3;
	aux3=enemigo;
	//for(aux2=enemigo;aux2!=NULL;aux2=aux2->siguiente)
	for(aux1=enemigo;aux1!=NULL;aux1=aux1->siguiente)
	{		
		for(aux2=enemigo;aux2!=NULL;aux2=aux2->siguiente)
		{
			if(aux2->bandera > aux2->siguiente->bandera)
			{
				aux3=aux2->siguiente;
				
				aux2->siguiente=aux2;
				aux2=aux3;
			}
		}
		if(aux1->siguiente==NULL)
			free(aux1);
		
	}	
}*/
void MoverEnemigoAbajo(int final,Enemigo *enemigo,int bandera)
{
//	int bandera;
//	bandera=enemigo->bandera;
	if (enemigo->bandera==bandera)//compara el flag para elegir que orden hace
	{
		enemigo->FrameActual.y=0;//mueve el sprite en el eje y
		if(++enemigo->contador >= 3)
		{
			if(++enemigo->FrameActual.x >= enemigo->CantidadFrames.x)
				enemigo->FrameActual.x = 0;//mueve entre los frames del enemigo
		
			enemigo->contador= 0;//vuelvo a iniciar el sprite
		}
		
		enemigo->pocicion.y+=enemigo->velocidad;//cambia el valor de la pocicion del enemigo
		if(enemigo->pocicion.y >= CUADRADOY*final)
		{
			enemigo->bandera=bandera+1;//pone un flag cuando llega al final de la linea
		}
		if(bandera==11)
	        {
                	al_destroy_bitmap(enemigo->imagen);
	                free(enemigo);
       	 	}

	}
}
void MoverEnemigoIzquierda(int final,Enemigo *enemigo,int bandera)
//void MoverEnemigoIzquierda(int final,Enemigo *enemigo)
{
//	int bandera;
//	bandera=enemigo->bandera;
	if (enemigo->bandera==bandera)//compara el flag para elegir que orden hace
	{
		enemigo->FrameActual.y=1;//mueve el sprite en el eje y
		if(++enemigo->contador >= 3)
		{
			if(++enemigo->FrameActual.x >= enemigo->CantidadFrames.x)
				enemigo->FrameActual.x = 0;//mueve entre los frames del enemigo

			enemigo->contador= 0;//vuelvo a iniciar el sprite
		}
		enemigo->pocicion.x-=enemigo->velocidad;//cambia el valor de la pocicion del enemigo
		if(enemigo->pocicion.x <= CUADRADOX*final)
			enemigo->bandera=bandera+1;//pone un flag cuando llega al final de la linea

	}
}
void MoverEnemigoDerecha(int final,Enemigo *enemigo,int bandera)
{
//	int bandera=enemigo->bandera;
	if (enemigo->bandera==bandera)//compara el flag para elegir que orden hace
	{
		enemigo->FrameActual.y=2;//mueve el sprite en el eje y
		if(++enemigo->contador >= 3)
		{
			if(++enemigo->FrameActual.x >= enemigo->CantidadFrames.x)
				enemigo->FrameActual.x = 0;//mueve entre los frames del enemigo

			enemigo->contador= 0;//vuelvo a iniciar el sprite
		}
		
		enemigo->pocicion.x+=enemigo->velocidad;//cambia el valor de la pocicion del enemigo
		if(enemigo->pocicion.x >= CUADRADOX*final)
			enemigo->bandera=bandera+1;//pone un flag cuando llega al final de la linea
	}
}
void MoverEnemigoArriba(int final,Enemigo *enemigo,int bandera)
{
//	int bandera;
//	bandera=enemigo->bandera;
	if (enemigo->bandera==bandera)//compara el flag para elegir que orden hace
	{
		enemigo->FrameActual.y=3;//mueve el sprite en el eje y
		if(++enemigo->contador >= 3)
		{
			if(++enemigo->FrameActual.x >= enemigo->CantidadFrames.x)
				enemigo->FrameActual.x = 0;//mueve entre los frames del enemigo
	
			enemigo->contador= 0;//vuelvo a iniciar el sprite
		}
		
		enemigo->pocicion.y-=enemigo->velocidad;//cambia el valor de la pocicion del enemigo
		if(enemigo->pocicion.y <= CUADRADOY*final)
			enemigo->bandera=bandera+1;//pone un flag cuando llega al final de la linea
	}
}
void MoverEnemigo(Enemigo *enemigo, Jugador *jugador)
{
	//mueve la pocicion del enemigo
	MoverEnemigoAbajo(1, enemigo,0);
	MoverEnemigoIzquierda(1,enemigo,1);
//	MoverEnemigoIzquierda(1,enemigo);
	MoverEnemigoAbajo(10,enemigo,2);
	MoverEnemigoDerecha(7,enemigo,3);
	MoverEnemigoArriba(5,enemigo,4);
	MoverEnemigoIzquierda(5,enemigo,5);
//	MoverEnemigoIzquierda(5,enemigo);
	MoverEnemigoAbajo(8,enemigo,6);
//	MoverEnemigoIzquierda(3,enemigo);
	MoverEnemigoIzquierda(3,enemigo,7);
	MoverEnemigoArriba(3,enemigo,8);
	MoverEnemigoDerecha(10,enemigo,9);
	MoverEnemigoAbajo(12,enemigo,10);

	if(enemigo->bandera==11)
	{
	//	jugador->vida=enemigo->danio;
	//	LiberarMemoriaEnemigo();
		enemigo->bandera=15;
	}
	else if(enemigo->bandera==12)
	{
		//LiberarMemoriaEnemigo();
	}
	else
	{
		//dibuja al enemigo
		BarraDeVida(enemigo);
		al_draw_bitmap_region(enemigo->imagen,enemigo->FrameActual.x*enemigo->DistanciaFrames.x,(enemigo->spritey+enemigo->FrameActual.y)*enemigo->DistanciaFrames.y, enemigo->DistanciaFrames.x, enemigo->DistanciaFrames.y, enemigo->pocicion.x, enemigo->pocicion.y, 0);
	}
}
Enemigo *EmpezarOleada(Enemigo *enemigo, int oleada,int malo)
{	
	if(oleada==1)//hace esto para la oleada
	{
		if(malo%2)//si es impar 
		{
			enemigo=NuevoEnemigo(enemigo);//pide memoria para el enemigio en la lista
			IniciarEnemigo1(enemigo);//inicia el enemigo con sus valores
		}
		else
		{
			enemigo=NuevoEnemigo(enemigo);//pide memoria para el enemigio en la lista
			IniciarEnemigo2(enemigo);//inicia el enemigo con sus valores
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
			MoverEnemigo(aux,&jugador);
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

