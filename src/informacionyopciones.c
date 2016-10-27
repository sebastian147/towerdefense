#include"header.h"
void OpcionesTorre(ALLEGRO_FONT *fuente)
{
	al_draw_rectangle(12*CUADRADOX,2*CUADRADOY, 15*CUADRADOX, 3*CUADRADOY, al_map_rgb(255, 255, 255),0);
	al_draw_rectangle(12*CUADRADOX,2*CUADRADOY, 14*CUADRADOX, 3*CUADRADOY, al_map_rgb(255, 255, 255),0);
	al_draw_rectangle(12*CUADRADOX,2*CUADRADOY, 13*CUADRADOX, 3*CUADRADOY, al_map_rgb(255, 255, 255),0);
	al_draw_rectangle(12*CUADRADOX,3*CUADRADOY, 15*CUADRADOX, 4*CUADRADOY, al_map_rgb(255, 255, 255),0);
	al_draw_rectangle(12*CUADRADOX,3*CUADRADOY, 14*CUADRADOX, 4*CUADRADOY, al_map_rgb(255, 255, 255),0);
	al_draw_rectangle(12*CUADRADOX,3*CUADRADOY, 13*CUADRADOX, 4*CUADRADOY, al_map_rgb(255, 255, 255),0);
	al_draw_textf(fuente,al_map_rgb(100,100,255),12*CUADRADOX+18,2*CUADRADOY+15,0,"A");
	al_draw_textf(fuente,al_map_rgb(100,100,255),13*CUADRADOX+18,2*CUADRADOY+15,0,"B");
	al_draw_textf(fuente,al_map_rgb(100,100,255),14*CUADRADOX+18,2*CUADRADOY+15,0,"C");
	al_draw_textf(fuente,al_map_rgb(100,100,255),12*CUADRADOX+18,3*CUADRADOY+15,0,"D");
	al_draw_textf(fuente,al_map_rgb(100,100,255),13*CUADRADOX+18,3*CUADRADOY+15,0,"E");
	al_draw_textf(fuente,al_map_rgb(100,100,255),14*CUADRADOX+18,3*CUADRADOY+15,0,"F");
}
void Informacion(ALLEGRO_FONT *fuente,Jugador *jugador)
{
	al_draw_textf(fuente,al_map_rgb(0,0,255),LARGO-150,ALTO-60,0,"vida:%d",jugador->vida);
	al_draw_textf(fuente,al_map_rgb(0,0,255),LARGO-150,ALTO-80,0,"oleada:%d",jugador->oleada);
	al_draw_textf(fuente,al_map_rgb(0,0,255),LARGO-150,ALTO-100,0,"plata:%d",jugador->plata);
	al_draw_textf(fuente,al_map_rgb(0,0,255),LARGO-150,ALTO-120,0,"score:%d",jugador->score);
	//imprimo los datos del jugador
	al_draw_rectangle(12*CUADRADOX,CUADRADOY, 15*CUADRADOX, 2*CUADRADOY, al_map_rgb(255, 255, 255),0);
	al_draw_rectangle(12*CUADRADOX,CUADRADOY, 14*CUADRADOX, 2*CUADRADOY, al_map_rgb(255, 255, 255),0);
	al_draw_rectangle(12*CUADRADOX,CUADRADOY, 13*CUADRADOX, 2*CUADRADOY, al_map_rgb(255, 255, 255),0);
	al_draw_textf(fuente,al_map_rgb(100,100,255),12*CUADRADOX+18,CUADRADOY+15,0,"1");
	al_draw_textf(fuente,al_map_rgb(100,100,255),13*CUADRADOX+18,CUADRADOY+15,0,"2");
	al_draw_textf(fuente,al_map_rgb(100,100,255),14*CUADRADOX+18,CUADRADOY+15,0,"3");
	//imprimir opcions de las torres
	al_draw_rectangle(12*CUADRADOX,0, 14*CUADRADOX-25, CUADRADOY, al_map_rgb(255, 255, 255),0);
	al_draw_rectangle(14*CUADRADOX-25,0, 15*CUADRADOX, CUADRADOY, al_map_rgb(255, 255, 255),0);
	al_draw_textf(fuente,al_map_rgb(100,100,255),14*CUADRADOX-20,15,0,"PAUSA");
	al_draw_textf(fuente,al_map_rgb(100,100,255),12*CUADRADOX+10,15,0,"EXIT");
}
void IniciarReloj(Reloj *reloj)
{
	reloj->segundos=0;
	reloj->milisegundos=10;//inicio la estructura del reloj
	reloj->DentroDeFuncion=0;
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
