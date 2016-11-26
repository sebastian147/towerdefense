#include "header.h"
void  DibujarInstrucciones(Iniciar *iniciar)
{
  al_clear_to_color(al_map_rgb(0,0,0));



  al_draw_bitmap(iniciar->fondo,0,0,0);


  al_flip_display();
}
bool TeclasOprimidasInstrucciones(bool *teclas,bool salir, ALLEGRO_EVENT *ev)
{

  if(ev->type == ALLEGRO_EVENT_DISPLAY_CLOSE)
  {
    salir = true;
  }//cierra el display
 if(ev->type == ALLEGRO_EVENT_KEY_UP)
  {
    switch(ev->keyboard.keycode)
    {
      case ALLEGRO_KEY_ESCAPE:
        teclas[ENTER]=true;//es enter pero para no crear orea variable
        break;
      case ALLEGRO_KEY_LEFT:
        teclas[IZQUIERDA] = true;
        break;
      case ALLEGRO_KEY_RIGHT:
        teclas[DERECHA] = true;
        break;
    }
  }
  return salir;
}
void MoverImagenDerecha(ALLEGRO_BITMAP **imagenes)
{

}
void MoverImagenIzquierda(ALLEGRO_BITMAP **imagenes)
{

}
int Instrucciones(Iniciar *iniciar)
{


  /*********************************************variables*************************************/

  bool salir=false;
  bool teclas[4] = {false, false, false, false};//le dice como estan las teclas
  int opcion=1;
  ALLEGRO_BITMAP *imagenes[4];


  /********************************comienza el menu**********************************/


  while (!salir)
  {

    ALLEGRO_EVENT ev;
    al_wait_for_event(iniciar->event_queue, &ev);

    DibujarInstrucciones(iniciar);


//lo que hace por cada tecla que oprimo
    if(teclas[IZQUIERDA])
    {
      MoverImagenIzquierda(imagenes);
    }
    if(teclas[DERECHA])
    {
      MoverImagenDerecha(imagenes);
    }
    if(teclas[ENTER])
    {
      return 1;
    }
    memset(teclas,false,3);

    salir=TeclasOprimidasInstrucciones(teclas, salir, &ev);

  }
  return OK;
}
