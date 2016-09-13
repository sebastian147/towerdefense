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
		enemigo->bandera=11;
	}
}
Enemigo * NuevoEnemigo(Enemigo *anterior)
{
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
        return nuevo;
}

void MoverEnemigoAbajo(int final,Enemigo *enemigo,int bandera)
{
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
			enemigo->bandera=bandera+1;//pone un flag cuando llega al final de la linea
		if(bandera==11)
	        {
                	al_destroy_bitmap(enemigo->imagen);
	                free(enemigo);
       	 	}

	}
}
void MoverEnemigoIzquierda(int final,Enemigo *enemigo,int bandera)
{
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
void MoverEnemigo(Enemigo *enemigo)
{
	//mueve la pocicion del enemigo
	MoverEnemigoAbajo(1, enemigo,0);
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

	if(enemigo->bandera==11)
	{
	//	LiberarMemoriaEnemigo();
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
	if(oleada==1)
	{
		if(malo%2)
		{
			enemigo=NuevoEnemigo(enemigo);
			IniciarEnemigo1(enemigo);
		}
		else
		{
			enemigo=NuevoEnemigo(enemigo);
			IniciarEnemigo2(enemigo);
		}
	}
	return enemigo;
}
Enemigo *SpawnearEnemigos(Enemigo *enemigo,Jugador *jugador)
{

	Enemigo *aux;
	if(jugador->relojito==0&&jugador->malo!=15)
	{
			
		enemigo=EmpezarOleada(enemigo,jugador->oleada,jugador->malo);
		jugador->malo++;			
	}
	if(enemigo!=NULL)
	{
	//mueve el enemigo
		for(aux=enemigo;aux!=NULL;aux=aux->siguiente)
		{
			MoverEnemigo(aux);
		}	
	}
	jugador->relojito++;
	if(jugador->relojito==10)
	{
		jugador->relojito=0;
	}
	return enemigo;
}

