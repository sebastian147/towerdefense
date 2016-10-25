#include "header.h"
void ImprimirMapa(Iniciar *iniciar)
{
  int j,i;
  for(i=0;i<12;i++)
  {
    for(j=0;j<12;j++)
    {
        if((j==6&&i<2)||(i==1&&j>1&&j<6)||(j==1&&i<11&&i>0)||(i==10&&j>1&&j<8)||(j==7&&i<10&&i>5)||(i==5&&j>4&&j<8)||(j==5&&i<9&&i>5)||(i==8&&j<5&&j>2)||(j==3&&i<8&&i>2)||(i==3&&j>3&&j<11)||(j==10&&i>3&&i<12))
        {
          al_draw_bitmap_region(iniciar->mapa,4*CUADRADOX,CUADRADOY,CUADRADOX,CUADRADOY,j*CUADRADOX,i*CUADRADOY,0);
        }
        /*else if((i==9&&j>10&&j<6)||(j==9&&i>2&&j<5))
        {
          al_draw_bitmap_region(iniciar->mapa,4*CUADRADOX,CUADRADOY,CUADRADOX,CUADRADOY,j*CUADRADOX,i*CUADRADOY,0);
        }*/
        else
        {
          al_draw_bitmap_region(iniciar->mapa,2*CUADRADOX,0,CUADRADOX,CUADRADOY,j*CUADRADOX,i*CUADRADOY,0);
        }
    }
  }
}
