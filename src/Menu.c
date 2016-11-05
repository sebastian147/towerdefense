#include "header.h"
void  DibujarMenu(ALLEGRO_FONT *fuente)
{

  al_draw_rectangle(LARGO/2-CUADRADOX*2,ALTO/2-CUADRADOY*2, LARGO/2+CUADRADOX*2, ALTO/2+CUADRADOY*2, al_map_rgb(255, 255, 255),0);
  al_draw_textf(fuente,al_map_rgb(100,100,255),12*CUADRADOX+18,CUADRADOY+15,0,"1");
}
