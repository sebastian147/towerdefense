
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

	Iniciar iniciar;
	InicializarIniciar(&iniciar);


	bool salir=false;


	int opcion =1;



	char IP[]="127.0.0.1";

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


/********************************comienza el juego**********************************/

	while(!salir)
	{



		switch(opcion)
		{
			case 0:
						salir=true;
						break;
			case 1:
						opcion=menu(&iniciar);
						break;
			case 2:
						opcion=jugar(&iniciar);
						//funcion para ingresar iniciales
						MandarPuntaje(opcion,PUERTO,"seb",IP,iniciar.fuente);
						opcion=1;
						break;
			}



	}
/*************************************Libera la memoria************************************/


	IniciarLiberarMemoriaCierre(&iniciar);


	return 0;
}
