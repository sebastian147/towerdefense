#include "header.h"
void  DibujarMenu(Iniciar *iniciar,Linea *linea)
{
  al_clear_to_color(al_map_rgb(0,0,0));


  al_draw_bitmap(iniciar->fondo,0,0,0);
  DibujarLinea(linea);

  al_flip_display();
}
bool TeclasOprimidasMenu(bool *teclas,bool salir, ALLEGRO_EVENT *ev)
{

  if(ev->type == ALLEGRO_EVENT_DISPLAY_CLOSE)
  {
    salir = true;
  }//cierra el display
 if(ev->type == ALLEGRO_EVENT_KEY_UP)
  {
    switch(ev->keyboard.keycode)
    {
      case ALLEGRO_KEY_ENTER:
        teclas[ENTER]=true;//es enter pero para no crear orea variable
        break;
      case ALLEGRO_KEY_UP:
        teclas[ARRIBA] = true;
        break;
      case ALLEGRO_KEY_DOWN:
        teclas[ABAJO] = true;
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
  int opcion=1;

  Linea linea;


  IniciarLinea(&linea);

  /********************************comienza el menu**********************************/


  while (!salir)
  {

    ALLEGRO_EVENT ev;
    al_wait_for_event(iniciar->event_queue, &ev);

    DibujarMenu(iniciar,&linea);


//lo que hace por cada tecla que oprimo
    if(teclas[ARRIBA])
    {
      MoverLineaArriba(&linea);
    }
    if(teclas[ABAJO])
    {
      MoverLineaAbajo(&linea);
    }
    if(teclas[ENTER])
    {
      if(linea.bandera==0)
      {
        return 2;
      }
      else if(linea.bandera==1)
      {
        return 3;
      }
      if(linea.bandera==2)
      {
        return 4;
      }
      else if(linea.bandera==3)
      {
        return 0;
      }

    }
    memset(teclas,false,3);

    salir=TeclasOprimidasMenu(teclas, salir, &ev);

  }
  return OK;
}
