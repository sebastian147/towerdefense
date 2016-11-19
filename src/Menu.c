#include "header.h"
void  DibujarMenu(Iniciar *iniciar)
{
  al_clear_to_color(al_map_rgb(0,0,0));

  
  al_convert_mask_to_alpha(iniciar->fondo, al_map_rgb(255, 255, 255));

  al_draw_bitmap(iniciar->fondo,130,300,0);
  al_draw_filled_rectangle(LARGO/2-CUADRADOX*2,ALTO/2-CUADRADOY*2, LARGO/2+CUADRADOX*2, ALTO/2, al_map_rgb(255, 255, 255));
  al_draw_textf(iniciar->fuente,al_map_rgb(0,0,0),LARGO/2-CUADRADOX*2+CUADRADOX/4,ALTO/2-CUADRADOY*2+CUADRADOY/2,0,"Enter para jugar");
  al_flip_display();
}
bool TeclasOprimidasMenu(bool *teclas,bool salir, ALLEGRO_EVENT *ev)
{

  if(ev->type == ALLEGRO_EVENT_DISPLAY_CLOSE)
  {
    salir = true;
  }//cierra el display
  else if(ev->type == ALLEGRO_EVENT_KEY_DOWN)
  {
    switch(ev->keyboard.keycode)
    {
      case ALLEGRO_KEY_ESCAPE:
        salir = true;
        break;
      case ALLEGRO_KEY_ENTER:
        teclas[ENTER]=true;
        break;
      case ALLEGRO_KEY_UP:
        teclas[ARRIBA] = true;
        break;
      case ALLEGRO_KEY_DOWN:
        teclas[ABAJO] = true;
        break;
    }
  }
  else if(ev->type == ALLEGRO_EVENT_KEY_UP)
  {
    switch(ev->keyboard.keycode)
    {
      /*case ALLEGRO_KEY_ESCAPE:
        salir = true;
        break;*/
      case ALLEGRO_KEY_ENTER:
        teclas[ENTER]=false;//es enter pero para no crear orea variable
        break;
      case ALLEGRO_KEY_UP:
        teclas[ARRIBA] = false;
        break;
      case ALLEGRO_KEY_DOWN:
        teclas[ABAJO] = false;
        break;
    }
  }
  return salir;
}
int Menu(Iniciar *iniciar)
{


  /*********************************************variables*************************************/


  bool salir=false;
  bool teclas[4] = {false, false, false, false};//le dice como estan las teclas

  /********************************comienza el menu**********************************/


  while (!salir)
  {

    ALLEGRO_EVENT ev;
    al_wait_for_event(iniciar->event_queue, &ev);

    DibujarMenu(iniciar);

//lo que hace por cada tecla que oprimo
    if(teclas[ARRIBA])
    {

    }
    if(teclas[ABAJO])
    {

    }
    if(teclas[ENTER])
    {
      return 2;
    }

    salir=TeclasOprimidasMenu(teclas, salir, &ev);

  }
  return 0;
}
