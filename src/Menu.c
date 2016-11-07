#include "header.h"
void  DibujarMenu(Iniciar *iniciar)
{
  al_convert_mask_to_alpha(iniciar->fondo, al_map_rgb(255, 255, 255));

  al_draw_bitmap(iniciar->fondo,130,300,0);
  al_draw_filled_rectangle(LARGO/2-CUADRADOX*2,ALTO/2-CUADRADOY*2, LARGO/2+CUADRADOX*2, ALTO/2, al_map_rgb(255, 255, 255));
  al_draw_textf(iniciar->fuente,al_map_rgb(0,0,0),LARGO/2-CUADRADOX*2+CUADRADOX/4,ALTO/2-CUADRADOY*2+CUADRADOY/2,0,"Enter para jugar");
}
