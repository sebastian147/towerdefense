#include "header.h"
bool TeclasOprimidasJugar(bool *teclas, bool salir, ALLEGRO_EVENT *ev)
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
      case ALLEGRO_KEY_UP:
        teclas[ARRIBA] = true;
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
      case ALLEGRO_KEY_1:
        if(teclas[UNO]==true)
        {
          teclas[UNO] = false;
        }//si la tecla esta apretada de antes cierra la pestania
        else if(teclas[UNO] == false)
        {
          teclas[UNO] = true;
        }
        break;
      case ALLEGRO_KEY_2:
        teclas[DOS] = true;
        break;
      case ALLEGRO_KEY_3:
        teclas[TRES] = true;
        break;
      case ALLEGRO_KEY_A:
        if(teclas[UNO])
          teclas[A] = true;
          break;
      case ALLEGRO_KEY_B:
        if(teclas[UNO])
          teclas[B] = true;
          break;
      case ALLEGRO_KEY_C:
        if(teclas[UNO])
          teclas[C] = true;
          break;
    }
  }//cambia los botones mientras los aprieto
  else if(ev->type == ALLEGRO_EVENT_KEY_UP)
  {
    switch(ev->keyboard.keycode)
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
      case ALLEGRO_KEY_2:
        teclas[DOS] = false;
        break;
      case ALLEGRO_KEY_3:
        teclas[TRES] = false;
        break;
    }
  }//cambia los botones cuando los suelto
  return salir;

}
bool ActualizarDibujosJuegar(Iniciar *iniciar,Cuadrado *cuadrado,Jugador *jugador,bool redraw)
{
  if(redraw && al_is_event_queue_empty(iniciar->event_queue))
  {
    redraw = false;


    // al_draw_bitmap(iniciar.mapa,0,0,0);

    DibujarCuadrado(cuadrado);
    Informacion(iniciar->fuente,jugador);//dibuja la informacion del jugador

    al_flip_display();
    al_clear_to_color(al_map_rgb(0,0,0));

    ImprimirMapa(iniciar);


  }//si no recibe ningun evento hace esto
  return redraw;
}
int Jugar(Iniciar *iniciar)
{

  /*********************************************variables*************************************/

  //declaro las estructuras
  Cuadrado cuadrado;//el cuadrado que se mueve por la pantalla
  Enemigo *enemigo=NULL,*aux=NULL;//declaro los punteros de enemigos para trabajarlos en forma de lista
  Reloj reloj;//El reloj de abajo a la derecha
  Jugador jugador;
  Torre *torre=NULL;
  //Pongo punteros a null a los structs de allegro que inicio despues
  //declaro bools
  bool salir = false;//para salir del while
  bool redraw = true;//hace que entre al if de volver a dibujar
  bool teclas[11] ;//le dice como estan las teclas
  bool RelojSalida=false;//reloj
  int oleada=0;//para saber donde esta

  /*********************inicio los structs******************************************/

  IniciarReloj(&reloj);
  IniciarCuadrado(&cuadrado);
  IniciarJugador(&jugador);
  memset(teclas,false,11);

  /********************************comienza el juego**********************************/


  while(!salir)
  {
    ALLEGRO_EVENT ev;
    al_wait_for_event(iniciar->event_queue, &ev);
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

      if(teclas[UNO])
      {
        OpcionesTorre(iniciar->fuente);
        if(teclas[A])
        {
          if((cuadrado.x/CUADRADOX==6&&cuadrado.y/CUADRADOY<2)||(cuadrado.y/CUADRADOY==1&&cuadrado.x/CUADRADOX>1&&cuadrado.x/CUADRADOX<6)||(cuadrado.x/CUADRADOX==1&&cuadrado.y/CUADRADOY<11&&cuadrado.y/CUADRADOY>0)||(cuadrado.y/CUADRADOY==10&&cuadrado.x/CUADRADOX>1&&cuadrado.x/CUADRADOX<8)||(cuadrado.x/CUADRADOX==7&&cuadrado.y/CUADRADOY<10&&cuadrado.y/CUADRADOY>5)||(cuadrado.y/CUADRADOY==5&&cuadrado.x/CUADRADOX>4&&cuadrado.x/CUADRADOX<8)||(cuadrado.x/CUADRADOX==5&&cuadrado.y/CUADRADOY<9&&cuadrado.y/CUADRADOY>5)||(cuadrado.y/CUADRADOY==8&&cuadrado.x/CUADRADOX<5&&cuadrado.x/CUADRADOX>2)||(cuadrado.x/CUADRADOX==3&&cuadrado.y/CUADRADOY<8&&cuadrado.y/CUADRADOY>2)||(cuadrado.y/CUADRADOY==3&&cuadrado.x/CUADRADOX>3&&cuadrado.x/CUADRADOX<11)||(cuadrado.x/CUADRADOX==10&&cuadrado.y/CUADRADOY>3&&cuadrado.y/CUADRADOY<12))
          {//si es el camino imprime un errror
            //tengo que imprimir un error
          }
          else if(HayTorre(&cuadrado,torre)==0)// si ya hay una torre ahi
          {
            //tengo que imprimir un error
          }
          else if(jugador.plata<200)
          {
            //error de no hay plata suficiente
          }
          else
          {
            CrearTorre(&torre);
            IniciarTorre(&torre,&cuadrado,1);
            jugador.plata-=200;
          }//pone la torre
          teclas[A] =   false;
        }
        if(teclas[B])
        {
          if((cuadrado.x/CUADRADOX==6&&cuadrado.y/CUADRADOY<2)||(cuadrado.y/CUADRADOY==1&&cuadrado.x/CUADRADOX>1&&cuadrado.x/CUADRADOX<6)||(cuadrado.x/CUADRADOX==1&&cuadrado.y/CUADRADOY<11&&cuadrado.y/CUADRADOY>0)||(cuadrado.y/CUADRADOY==10&&cuadrado.x/CUADRADOX>1&&cuadrado.x/CUADRADOX<8)||(cuadrado.x/CUADRADOX==7&&cuadrado.y/CUADRADOY<10&&cuadrado.y/CUADRADOY>5)||(cuadrado.y/CUADRADOY==5&&cuadrado.x/CUADRADOX>4&&cuadrado.x/CUADRADOX<8)||(cuadrado.x/CUADRADOX==5&&cuadrado.y/CUADRADOY<9&&cuadrado.y/CUADRADOY>5)||(cuadrado.y/CUADRADOY==8&&cuadrado.x/CUADRADOX<5&&cuadrado.x/CUADRADOX>2)||(cuadrado.x/CUADRADOX==3&&cuadrado.y/CUADRADOY<8&&cuadrado.y/CUADRADOY>2)||(cuadrado.y/CUADRADOY==3&&cuadrado.x/CUADRADOX>3&&cuadrado.x/CUADRADOX<11)||(cuadrado.x/CUADRADOX==10&&cuadrado.y/CUADRADOY>3&&cuadrado.y/CUADRADOY<12))
          {//si es el camino imprime un errror
            //tengo que imprimir un error
          }
          else if(HayTorre(&cuadrado,torre)==0)// si ya hay una torre ahi
          {
            //tengo que imprimir un error
          }
          else if(jugador.plata<300)
          {
            //error de no hay plata suficiente
          }
          else
          {
            CrearTorre(&torre);
            IniciarTorre(&torre,&cuadrado,4);
            jugador.plata-=300;

          }//pone la torre
          teclas[B] =   false;
        }
        if(teclas[C])
        {
          if((cuadrado.x/CUADRADOX==6&&cuadrado.y/CUADRADOY<2)||(cuadrado.y/CUADRADOY==1&&cuadrado.x/CUADRADOX>1&&cuadrado.x/CUADRADOX<6)||(cuadrado.x/CUADRADOX==1&&cuadrado.y/CUADRADOY<11&&cuadrado.y/CUADRADOY>0)||(cuadrado.y/CUADRADOY==10&&cuadrado.x/CUADRADOX>1&&cuadrado.x/CUADRADOX<8)||(cuadrado.x/CUADRADOX==7&&cuadrado.y/CUADRADOY<10&&cuadrado.y/CUADRADOY>5)||(cuadrado.y/CUADRADOY==5&&cuadrado.x/CUADRADOX>4&&cuadrado.x/CUADRADOX<8)||(cuadrado.x/CUADRADOX==5&&cuadrado.y/CUADRADOY<9&&cuadrado.y/CUADRADOY>5)||(cuadrado.y/CUADRADOY==8&&cuadrado.x/CUADRADOX<5&&cuadrado.x/CUADRADOX>2)||(cuadrado.x/CUADRADOX==3&&cuadrado.y/CUADRADOY<8&&cuadrado.y/CUADRADOY>2)||(cuadrado.y/CUADRADOY==3&&cuadrado.x/CUADRADOX>3&&cuadrado.x/CUADRADOX<11)||(cuadrado.x/CUADRADOX==10&&cuadrado.y/CUADRADOY>3&&cuadrado.y/CUADRADOY<12))
          {//si es el camino imprime un errror
            //tengo que imprimir un error
          }
          else if(HayTorre(&cuadrado,torre)==0)// si ya hay una torre ahi
          {
            //tengo que imprimir un error
          }
          else if(jugador.plata<300)
          {
            //error de no hay plata suficiente
          }
          else
          {
            CrearTorre(&torre);
            IniciarTorre(&torre,&cuadrado,7);
            jugador.plata-=300;

          }//pone la torre
          teclas[C] =   false;
        }
      }
      // printf("%d\n",teclas[UNO]);
      if(teclas[DOS])
      {
        DestruirTorre(&torre,&cuadrado);
      }
      if(teclas[TRES])
      {
        MejorarTorre(&torre,&cuadrado,&jugador);
      }

      // reloj
      if(!RelojSalida && enemigo==NULL)
      {
        RelojSalida=EmpezarReloj(iniciar->fuente,&reloj);//reloj de 1 minuto a 0
      }
      else if(RelojSalida)
      {
        //Crea al enemigo
        enemigo=SpawnearEnemigos(enemigo,&jugador,&RelojSalida);
        //pone el reloj en 0
        Reloj0(iniciar->fuente);
    }
    ActualizarTorre(&torre,&cuadrado,&enemigo,&reloj);
  }//de acuero a la tecla que oprimi se mueve
  if(jugador.vida<0)
  {
    salir=true;
  }
  salir =TeclasOprimidasJugar(teclas, salir, &ev);
  redraw=ActualizarDibujosJuegar(iniciar,&cuadrado,&jugador,redraw);

}
  //IniciarLiberarMemoria(&torre,&enemigo);
  return jugador.score;
}
