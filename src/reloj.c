#include"header.h"
void IniciarReloj(Reloj *reloj)
{
	reloj->segundos=0;
	reloj->milisegundos=10;//inicio la estructura del reloj
}
void Reloj0(ALLEGRO_FONT *fuente)
{
	int minutos=0;
	int segundos=0;
	al_draw_textf(fuente,al_map_rgb(255,255,255),LARGO-80,ALTO-40,0,"%d:%d",minutos,segundos);
	//dibujo el tiempo en 0
}
bool EmpezarReloj(ALLEGRO_FONT *fuente,Reloj *reloj)
{
	

			if(reloj->segundos==0)
			{	
				reloj->minutos=1;//empieza el tiempi
				
			}
			else if(reloj->segundos<0)
			{
				reloj->minutos=0;
				reloj->segundos=59;//cambia de 1 minuto a 59 segundos
			}
			
			al_draw_textf(fuente,al_map_rgb(255,255,255),LARGO-80,ALTO-40,0,"%d:%d",reloj->minutos,reloj->segundos);//dibuja el reloj
			if(reloj->milisegundos==0)
			{
				reloj->segundos--;
				reloj->milisegundos=1;//resta los segundos cuando se acaban los milisegundos
				if((reloj->segundos==0) && (reloj->minutos==0))
				{
					return true;//retorna verdadero cuando se acaba el tiempo
				}
			}
			else
			{
				reloj->milisegundos--;//resta los milisegundos hasta ser 0
			}

		return false;
}
