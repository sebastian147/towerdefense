
/**
 * \file main.c
 * \brief Programa sencillo para abrir una imagen y presentarla en una ventana
 * \details Utilizamos la biblioteca Opencv para abrir la imagen aprovechando
 * sus funciones independientes del tipo de archivo, y tambien para crear una
 * ventana sencilla (sin menu), para presentarla en la GUI del sistema operativo
 * que se tenga (Linux, Windows, o MAC OS).
 * Este programa compila en Linux, mediante el comando siguiente:
 * gcc -o img img.c `pkg-config --cflags --libs opencv` -g -ggdb -Wall
 * \author Alejandro Furfaro <afurfaro@electron.frba.utn.edu.ar>. Modificado por lkollenberger.
 *
 * Muy similar a http://opencv.wikispaces.com/3%29+First+Sample+Program
 *
 * \date 12.05.2011
*/

#include "header.h"

/**
 * \fn int main(int argc, char *argv[])
 * \brief Muestra imagenes por linea de comandos, o las que haya en una carpeta
 * predefinida.
 * \author Alejandro Furfaro. <afurfaro@electron.frba.utn.edu.ar>
 * \date 27.08.2016
 * \return Retorna cero en caso de exito, -1 en caso de error.
*/

int main(int argc, char **argv)
{

/*********************************************variables*************************************/
	//declaro las estructuras
	Cuadrado cuadrado;//el cuadrado que se mueve por la pantalla
	Enemigo *enemigo=NULL,*aux;//declaro los punteros de enemigos para trabajarlos en forma de lista
	Reloj reloj;//El reloj de abajo a la derecha
	Iniciar iniciar;
	Jugador jugador;
	//Pongo punteros a null a los structs de allegro que inicio despues
	InicializarIniciar(&iniciar);

	//declaro bools
	bool salir = false;//para salir del while
  bool redraw = true;//hace que entre al if de volver a dibujar
	bool teclas[5] = {false, false, false, false, false};//le dice como estan las teclas
	bool RelojSalida=false;//reloj
	int oleada=0;//para saber donde esta

/**************************************Inicia Allegro y analiza errores*********************************/

	if(IniciarYErrores(&iniciar))
	{
		return -1;
	}


/****************************************Registro los eventos************************************/


	al_register_event_source(iniciar.event_queue, al_get_display_event_source(iniciar.display));

	al_register_event_source(iniciar.event_queue, al_get_timer_event_source(iniciar.timer));

	al_register_event_source(iniciar.event_queue, al_get_keyboard_event_source());

	al_start_timer(iniciar.timer);
/*********************inicio los structs******************************************/

	IniciarReloj(&reloj);
  IniciarCuadrado(&cuadrado);
	IniciarJugador(&jugador);

/********************************comienza el juego**********************************/

	while(!salir)
	{

		ALLEGRO_EVENT ev;
		al_wait_for_event(iniciar.event_queue, &ev);

		if(ev.type == ALLEGRO_EVENT_TIMER)
		{
			redraw = true;

			//mueve el cuadrado
			if(teclas[ARRIBA])
				MoverCuadradoArriba(&cuadrado);
			if(teclas[ABAJO])
				MoverCuadradoAbajo(&cuadrado);
			if(teclas[IZQUIERDA])
				MoverCuadradoIzquierda(&cuadrado);
			if(teclas[DERECHA])
				MoverCuadradoDerecha(&cuadrado);

			//reloj
			if(!RelojSalida && enemigo==NULL)
			{
				RelojSalida=EmpezarReloj(iniciar.fuente,&reloj);//reloj de 1 minuto a 0
			}
			else if(RelojSalida)
			{
				//Crea al enemigo
				enemigo=SpawnearEnemigos(enemigo,&jugador);
				//pone el reloj en 0
				Reloj0(iniciar.fuente);
			}
			Informacion(iniciar.fuente,&jugador);//dibuja la informacion del jugador
		}//de acuero a la tecla que oprimi se mueve
		else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			salir = true;
		}//cierra el display
                else if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
                {
                        switch(ev.keyboard.keycode)
                        {
            	            case ALLEGRO_KEY_ESCAPE:
            	                    salir = true;
            	                    break;
            	            case ALLEGRO_KEY_UP:
															teclas[ARRIBA] = true;
                             	enemigo->vida.x--;
				   												break;
	        	    					case ALLEGRO_KEY_DOWN:
        	                        teclas[ABAJO] = true;
                  	              break;
                  	      case ALLEGRO_KEY_LEFT:
                  	              teclas[IZQUIERDA] = true;
                        	        break;
                  	      case ALLEGRO_KEY_RIGHT:
                        	        teclas[DERECHA] = true;
                               		 break;
                        }
                }//cambia los botones mientras los aprieto
		else if(ev.type == ALLEGRO_EVENT_KEY_UP)
		{
			switch(ev.keyboard.keycode)
			{
				case ALLEGRO_KEY_ESCAPE:
					salir = true;
					break;
				case ALLEGRO_KEY_UP:
					teclas[ARRIBA] = false;
					break;
				case ALLEGRO_KEY_DOWN:
					teclas[ABAJO] = false;
					break;
				case ALLEGRO_KEY_LEFT:
					teclas[IZQUIERDA] = false;
					break;
				case ALLEGRO_KEY_RIGHT:
					teclas[DERECHA] = false;
					break;
			}
		}//cambia los botones cuando los suelto


		if(redraw && al_is_event_queue_empty(iniciar.event_queue))
		{
			redraw = false;

			DibujarCuadrado(&cuadrado);

			al_flip_display();
			//al_draw_bitmap(iniciar.mapa,0,0,0);
			ImprimirMapa(&iniciar);
		}//si no recibe ningun evento hace esto


	}
/*************************************Libera la memoria************************************/
	IniciarLiberarMemoria(&iniciar);


	return 0;
}
