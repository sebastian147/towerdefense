#include "header.h"
void IniciarEnemigo1(Enemigo *enemigo)
{
//	enemigo->nombre={'D','r','a','g','o','n'};
	enemigo->vida=5;
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
	enemigo->vida=5;
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
	
	//dibuja al enemigo
	al_draw_bitmap_region(enemigo->imagen,enemigo->FrameActual.x*enemigo->DistanciaFrames.x,(enemigo->spritey+enemigo->FrameActual.y)*enemigo->DistanciaFrames.y, enemigo->DistanciaFrames.x, enemigo->DistanciaFrames.y, enemigo->pocicion.x, enemigo->pocicion.y, 0);

}



