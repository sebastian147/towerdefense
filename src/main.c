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
	//declaro variables
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP *image = NULL; 	
	bool salir = false;


	if(!al_init())
	{
		fprintf(stderr, "Fallo al iniciar allegro\n");
		return -1;
	//verifica si se inicio bien allegro
	}

	if(!al_install_keyboard())
	{
		fprintf(stderr, "Fallo al iniciar el teclado\n");
		return -1;
	//verifica si se inicio bien el teclado
	}
 
	timer = al_create_timer(1.0 / FPS);
	//crea el timer
	
	if(!timer)
	{
		fprintf(stderr, "Fallo al crear el timer\n");
		return -1;
	//ve si el timer anda
	}

	if(!al_init_image_addon())
	{
		fprintf(stderr,"Fallo al iniciar imagen addon\n");
		al_destroy_timer(timer);
		return -1;
	}

	display = al_create_display(WIDTH, HEIGHT);
	//Crear el display

	if(!display)	
	{
		fprintf(stderr, "Fallo al crearo el display\n");
		al_destroy_timer(timer);
		return -1;
	//Ver si el display anda
	}


 	image = al_load_bitmap("./assets/Map0.png");

	//cargo la imagen del mapa

	if(!image)
	{
		fprintf(stderr, "Fallo al crear el mapa\n");
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	//verifico si se cargo bien
	}

	event_queue = al_create_event_queue();
	//creo un evento

	if(!event_queue)
	{
		fprintf(stderr, "Fallo al crear el evento queue\n");
		al_destroy_bitmap(image);
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	//verifico si se creo bien
	}
	

	al_register_event_source(event_queue, al_get_display_event_source(display));
 
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
 
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	//registro los eventos	

 	al_draw_bitmap(image,0,0,0);
	al_flip_display();
//	al_rest(2);
 
	al_start_timer(timer);
	while(!salir)
	{

		ALLEGRO_EVENT ev;

		al_wait_for_event(event_queue, &ev);
		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			salir=true;
		//sale del while al apretar la cruz del display
		}
	}
	 
	//Terminamos el programa
	al_destroy_bitmap(image);
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);
	return 0;
}
