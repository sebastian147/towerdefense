#include"header.h"
void Informacion(ALLEGRO_FONT *fuente,Jugador *jugador)
{
	al_draw_textf(fuente,al_map_rgb(0,0,255),LARGO-150,ALTO-60,0,"vida:%d",jugador->vida);
	al_draw_textf(fuente,al_map_rgb(0,0,255),LARGO-150,ALTO-80,0,"oleada:%d",jugador->oleada);
	al_draw_textf(fuente,al_map_rgb(0,0,255),LARGO-150,ALTO-100,0,"plata:%d",jugador->plata);
	al_draw_textf(fuente,al_map_rgb(0,0,255),LARGO-150,ALTO-120,0,"score:%d",jugador->score);
	//imprimo los datos del jugador
	al_draw_rectangle(12*CUADRADOX,0, 15*CUADRADOX, CUADRADOY, al_map_rgb(255, 255, 255),0);
	al_draw_rectangle(12*CUADRADOX,0, 14*CUADRADOX, CUADRADOY, al_map_rgb(255, 255, 255),0);
	al_draw_rectangle(12*CUADRADOX,0, 13*CUADRADOX, CUADRADOY, al_map_rgb(255, 255, 255),0);
	al_draw_textf(fuente,al_map_rgb(100,100,255),12*CUADRADOX+18,15,0,"1");
	al_draw_textf(fuente,al_map_rgb(100,100,255),13*CUADRADOX+18,15,0,"2");
	al_draw_textf(fuente,al_map_rgb(100,100,255),14*CUADRADOX+18,15,0,"3");
	//imprimir opcions de las torres
}
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
