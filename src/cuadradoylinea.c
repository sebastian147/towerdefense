#include "header.h"
void IniciarCuadrado(Cuadrado *cuadrado)
{
        cuadrado->x = 0;
        cuadrado->y = 0;
}
void DibujarCuadrado(Cuadrado *cuadrado)
{
        al_draw_rectangle(cuadrado->x, cuadrado->y , cuadrado->x+CUADRADOX, cuadrado->y+CUADRADOY, al_map_rgb(255,255,255),0);
}
void MoverCuadradoArriba(Cuadrado *cuadrado)
{
        cuadrado->y -= CUADRADOY;
        if(cuadrado->y < 0)
                cuadrado->y = 0;
}
void MoverCuadradoAbajo(Cuadrado *cuadrado)
{
        cuadrado->y += CUADRADOY;
        if(cuadrado->y > ALTO-CUADRADOY)
                cuadrado->y = ALTO-CUADRADOY;
}
void MoverCuadradoIzquierda(Cuadrado *cuadrado)
{
        cuadrado->x -= CUADRADOX;
        if(cuadrado->x < 0)
                cuadrado->x = 0;
}
void MoverCuadradoDerecha(Cuadrado *cuadrado)
{
        cuadrado->x += CUADRADOX;
        if(cuadrado->x > LARGO-4*CUADRADOX)
                cuadrado->x = LARGO-4*CUADRADOX;
}
void IniciarLinea(Linea *linea)
{
  linea->pocicioninicial.x=359;
  linea->pocicioninicial.y=264;
  linea->pocicionfinal.x=431;
  linea->pocicionfinal.y=264;
  linea->bandera=0;

}
void DibujarLinea(Linea *linea)
{
  al_draw_line(linea->pocicioninicial.x, linea->pocicioninicial.y ,   linea->pocicionfinal.x, linea->pocicionfinal.y, al_map_rgb(0,0,0),0);
}
void MoverLineaArriba(Linea *linea)
{
  if(linea->bandera==1)
  {
    linea->pocicioninicial.x=359;
    linea->pocicioninicial.y=264;
    linea->pocicionfinal.x=431;
    linea->pocicionfinal.y=264;
  }
  else if(linea->bandera==2)
  {
    linea->pocicioninicial.x=311;
    linea->pocicioninicial.y=345;
    linea->pocicionfinal.x=509;
    linea->pocicionfinal.y=345;
  }
  else if(linea->bandera==3)
  {
    linea->pocicioninicial.x=356;
    linea->pocicioninicial.y=431;
    linea->pocicionfinal.x=464;
    linea->pocicionfinal.y=431;
  }
  if(linea->bandera > 0)
    linea->bandera--;
}
void MoverLineaAbajo(Linea *linea)
{
  if(linea->bandera==0)
  {
    linea->pocicioninicial.x=311;
    linea->pocicioninicial.y=345;
    linea->pocicionfinal.x=509;
    linea->pocicionfinal.y=345;
  }
  else if(linea->bandera==1)
  {
    linea->pocicioninicial.x=356;
    linea->pocicioninicial.y=431;
    linea->pocicionfinal.x=464;
    linea->pocicionfinal.y=431;
  }
  else if(linea->bandera==2)
  {
    linea->pocicioninicial.x=357;
    linea->pocicioninicial.y=510;
    linea->pocicionfinal.x=429;
    linea->pocicionfinal.y=510;
  }
  if (linea->bandera<3)
    linea->bandera++;
}
