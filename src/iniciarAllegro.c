#include "header.h"
void InicializarIniciar(Iniciar *iniciar)
{
	iniciar->display = NULL;
	iniciar->event_queue = NULL;
	iniciar->timer = NULL;
	iniciar->mapa = NULL;
	iniciar->fuente =NULL;
}
int IniciarYErrores(Iniciar *iniciar)
{
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
 
	iniciar->timer = al_create_timer(1.0 /FPS);
	//crea el timer
	
	if(!iniciar->timer)
	{
		fprintf(stderr, "Fallo al crear el timer\n");
		return -1;
	//ve si el timer anda
	}

	if(!al_init_image_addon())
	{
		fprintf(stderr,"Fallo al iniciar imagen addon\n");
		al_destroy_timer(iniciar->timer);
		return -1;
	}

	iniciar->display = al_create_display(LARGO,ALTO);
	//Crear el display

	if(!iniciar->display)	
	{
		fprintf(stderr, "Fallo al crearo el display\n");
		al_destroy_timer(iniciar->timer);
		return -1;
	//Ver si el display anda
	}


	iniciar->mapa = al_load_bitmap("./assets/Map0.png");

	//cargo la imagen del mapa 

	if(!iniciar->mapa)
	{
		fprintf(stderr, "Fallo al crear el mapa\n");
		al_destroy_display(iniciar->display);
		al_destroy_timer(iniciar->timer);
		return -1;
	//verifico si se cargo bien
	}

//	al_convert_mask_to_alpha(enemigo.imagen, al_map_rgb(120, 195, 128));
        //cargo la imagen del enemigo
//
  /*      if(!enemigo1.imagen)
        {
                fprintf(stderr, "Fallo al crear el mapa\n");
                al_destroy_display(display);
                al_destroy_timer(timer);
		al_destroy_bitmap(enemigo1.imagen);
                return -1;
        //verifico si se cargo bien
        }
	//nuevoenemigo.imagen=enemigo.imagen;
*/
	if(!al_init_primitives_addon())
	{
		fprintf(stderr,"Fallo al crear el evento\n");
		al_destroy_bitmap(iniciar->mapa);
		al_destroy_display(iniciar->display);
		al_destroy_timer(iniciar->timer);
     //           al_destroy_bitmap(enemigo1.imagen);
		return -1;
	//fallo al crear dibujos primarios
	}
	if(!al_install_keyboard())
	{
		fprintf(stderr, "Fallo al crear el teclado\n");
		al_destroy_bitmap(iniciar->mapa);
		al_destroy_display(iniciar->display);
		al_destroy_timer(iniciar->timer);
 //               al_destroy_bitmap(enemigo1.imagen);
		return -1;

	}
        iniciar->event_queue = al_create_event_queue();
        //creo un evento

	if(!iniciar->event_queue)
	{
		fprintf(stderr, "Fallo al crear el evento queue\n");
		al_destroy_bitmap(iniciar->mapa);
		al_destroy_display(iniciar->display);
		al_destroy_timer(iniciar->timer);
  
 //             al_destroy_bitmap(enemigo1.imagen);
		return -1;
	//verifico si se creo bien
	}
	
//	fuente =al_load_ttf_font("./assest/Action\ force\ Normal.ttf",10,0);
	al_init_font_addon();//inicio el addon para leer fuenetes

	if(!al_init_ttf_addon())	
	{
                fprintf(stderr, "Fallo al iniciar el archivo .ttf\n");
                al_destroy_bitmap(iniciar->mapa);
                al_destroy_display(iniciar->display);
                al_destroy_timer(iniciar->timer);
	        al_destroy_event_queue(iniciar->event_queue);

		return -1;
	//verifico si puede abrir el archivo de texto para leer fuentes
	}

        iniciar->fuente =al_load_ttf_font("./assets/fuente1.ttf",20,0);//cargo el archivo con las funtes de texto
	return 0;
}

