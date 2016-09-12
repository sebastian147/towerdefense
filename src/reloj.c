#include"header.h"
void IniciarReloj(Reloj *reloj)
{
	reloj->segundos=0;
	reloj->milisegundos=10;
}
void Reloj0(ALLEGRO_FONT *fuente)
{
	int minutos=0;
	int segundos=0;
	al_draw_textf(fuente,al_map_rgb(255,255,255),LARGO-80,ALTO-40,0,"%d:%d",minutos,segundos);
}
bool EmpezarReloj(ALLEGRO_FONT *fuente,Reloj *reloj)
{
	

			if(reloj->segundos==0)
			{	
				reloj->minutos=1;
				
			}
			else if(reloj->segundos<0)
			{
				reloj->minutos=0;
				reloj->segundos=59;
			}
			
			al_draw_textf(fuente,al_map_rgb(255,255,255),LARGO-80,ALTO-40,0,"%d:%d",reloj->minutos,reloj->segundos);
			if(reloj->milisegundos==0)
			{
				reloj->segundos--;
				reloj->milisegundos=1;
				if((reloj->segundos==0) && (reloj->minutos==0))
				{
					return true;
				}
			}
			else
			{
				reloj->milisegundos--;
			}

		return false;
}
