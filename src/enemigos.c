#include "header.h"
void IniciarEnemigo1(Enemigo *enemigo)
{
//	enemigo->nombre={'D','r','a','g','o','n'};
	enemigo->vida=5;
	enemigo->velocidad=10;
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
}

void MoverEnemigo(Enemigo *enemigo)
{

	if (enemigo->bandera==0)
	{
		enemigo->FrameActual.y=0;
		if(++enemigo->contador >= 3)
		{
			if(++enemigo->FrameActual.x >= enemigo->CantidadFrames.x)
				enemigo->FrameActual.x = 0;
		
			enemigo->contador= 0;
		}
		
		enemigo->pocicion.y+=enemigo->velocidad;
		if(enemigo->pocicion.y >= CUADRADOY)
			enemigo->bandera=1;
	}
	else if (enemigo->bandera==1)
	{
		enemigo->FrameActual.y=1;
		if(++enemigo->contador >= 3)
		{
			if(++enemigo->FrameActual.x >= enemigo->CantidadFrames.x)
				enemigo->FrameActual.x = 0;

			enemigo->contador= 0;
		}
		
		enemigo->pocicion.x-=enemigo->velocidad;
		if(enemigo->pocicion.x <= CUADRADOX)
			enemigo->bandera=2;
	}
	else if (enemigo->bandera==2)
	{
		enemigo->FrameActual.y=0;
		if(++enemigo->contador >= 3)
		{
			if(++enemigo->FrameActual.x >= enemigo->CantidadFrames.x)
				enemigo->FrameActual.x = 0;
	
			enemigo->contador= 0;
		}
		
		enemigo->pocicion.y+=enemigo->velocidad;
		if(enemigo->pocicion.y >= CUADRADOY*10)
			enemigo->bandera=3;
	}

	else if (enemigo->bandera==3)
	{
		enemigo->FrameActual.y=2;
		if(++enemigo->contador >= 3)
		{
			if(++enemigo->FrameActual.x >= enemigo->CantidadFrames.x)
				enemigo->FrameActual.x = 0;

			enemigo->contador= 0;
		}
		
		enemigo->pocicion.x+=enemigo->velocidad;
		if(enemigo->pocicion.x >= CUADRADOX*7)
			enemigo->bandera=4;
	}
	else if (enemigo->bandera==4)
	{
		enemigo->FrameActual.y=3;
		if(++enemigo->contador >= 3)
		{
			if(++enemigo->FrameActual.x >= enemigo->CantidadFrames.x)
				enemigo->FrameActual.x = 0;
	
			enemigo->contador= 0;
		}
		
		enemigo->pocicion.y-=enemigo->velocidad;
		if(enemigo->pocicion.y <= CUADRADOY*5)
			enemigo->bandera=5;
	}
	else if (enemigo->bandera==5)
	{
		enemigo->FrameActual.y=1;
		if(++enemigo->contador >= 3)
		{
			if(++enemigo->FrameActual.x >= enemigo->CantidadFrames.x)
				enemigo->FrameActual.x = 0;

			enemigo->contador= 0;
		}
		
		enemigo->pocicion.x-=enemigo->velocidad;
		if(enemigo->pocicion.x <= CUADRADOX*5)
			enemigo->bandera=6;
	}
	else if (enemigo->bandera==6)
	{
		enemigo->FrameActual.y=0;
		if(++enemigo->contador >= 3)
		{
			if(++enemigo->FrameActual.x >= enemigo->CantidadFrames.x)
				enemigo->FrameActual.x = 0;
	
			enemigo->contador= 0;
		}
		
		enemigo->pocicion.y+=enemigo->velocidad;
		if(enemigo->pocicion.y >= CUADRADOY*8)
			enemigo->bandera=7;
	}
	else if (enemigo->bandera==7)
	{
		enemigo->FrameActual.y=1;
		if(++enemigo->contador >= 3)
		{
			if(++enemigo->FrameActual.x >= enemigo->CantidadFrames.x)
				enemigo->FrameActual.x = 0;

			enemigo->contador= 0;
		}
		
		enemigo->pocicion.x-=enemigo->velocidad;
		if(enemigo->pocicion.x <= CUADRADOX*3)
			enemigo->bandera=8;
	}
	else if (enemigo->bandera==8)
	{
		enemigo->FrameActual.y=3;
		if(++enemigo->contador >= 3)
		{
			if(++enemigo->FrameActual.x >= enemigo->CantidadFrames.x)
				enemigo->FrameActual.x = 0;
	
			enemigo->contador= 0;
		}
		
		enemigo->pocicion.y-=enemigo->velocidad;
		if(enemigo->pocicion.y <= CUADRADOY*3)
			enemigo->bandera=9;
	}
	else if (enemigo->bandera==9)
	{
		enemigo->FrameActual.y=2;
		if(++enemigo->contador >= 3)
		{
			if(++enemigo->FrameActual.x >= enemigo->CantidadFrames.x)
				enemigo->FrameActual.x = 0;

			enemigo->contador= 0;
		}
		
		enemigo->pocicion.x+=enemigo->velocidad;
		if(enemigo->pocicion.x >= CUADRADOX*10)
			enemigo->bandera=10;
	}
	else if (enemigo->bandera==10)
	{
		enemigo->FrameActual.y=0;
		if(++enemigo->contador >= 3)
		{
			if(++enemigo->FrameActual.x >= enemigo->CantidadFrames.x)
				enemigo->FrameActual.x = 0;
	
			enemigo->contador= 0;
		}
		
		enemigo->pocicion.y+=enemigo->velocidad;
		if(enemigo->pocicion.y >= CUADRADOY*12)
			enemigo->bandera=11;
	}
	al_draw_bitmap_region(enemigo->imagen,enemigo->FrameActual.x*enemigo->DistanciaFrames.x,enemigo->FrameActual.y*enemigo->DistanciaFrames.y, enemigo->DistanciaFrames.x, enemigo->DistanciaFrames.y, enemigo->pocicion.x, enemigo->pocicion.y, 0);

}



/*
	if(ev.type == ALLEGRO_EVENT_TIMER)
	{
		if(++ContadorDeFrames >= velocidad)
			{
				FrameActualx++;
				if(FrameActualx*FrameActualy >= MaximoFrame)
				{
					FrameActualx = 0;
					FrameActualy = 0;
				}
				else if(FrameActualx==2)
				{
					FrameActualy+=32;
				}
				ContadorDeFrames = 0;
			}

			enemigo1y += 5;

			if(enemigo1y >= ALTO)
				enemigo1y = 0;
		}
		
		
				*/
