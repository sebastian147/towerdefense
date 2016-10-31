#include "header.h"
void IniciarLiberarMemoria(Iniciar *iniciar,Torre **torre,Enemigo **enemigo)
{
	Enemigo *aux=*enemigo, *aux2;
	//Terminamos el programa
	al_destroy_bitmap(iniciar->mapa);
	al_destroy_timer(iniciar->timer);
	al_destroy_display(iniciar->display);
	al_destroy_event_queue(iniciar->event_queue);
	al_destroy_font(iniciar->fuente);
 //       al_destroy_bitmap(enemigo1.imagen);
	while(aux->siguiente!=NULL)
	{
		aux2=aux->siguiente;
		aux->anterior=NULL;
		al_destroy_bitmap(aux->imagen);
		free (aux);
		aux=aux2;
	}
	al_destroy_bitmap(aux->imagen);
	free (aux);
	*enemigo=NULL;
	Torre *aux1=*torre,*aux3;
	while(aux1->siguiente!=NULL)
	{
		aux3=aux1->siguiente;
		aux1->anterior=NULL;
		al_destroy_bitmap(aux1->imagen);
		free (aux1);
		aux1=aux3;
	}
	al_destroy_bitmap(aux1->imagen);
	free (aux1);
	*torre=NULL;

}
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


	iniciar->mapa = al_load_bitmap("./assets/basic.bmp");

	//cargo la imagen del mapa

	if(!iniciar->mapa)
	{
		fprintf(stderr, "Fallo al crear el mapa\n");
		al_destroy_display(iniciar->display);
		al_destroy_timer(iniciar->timer);
		return -1;
	//verifico si se cargo bien
	}
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
