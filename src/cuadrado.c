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
        if(cuadrado->x > LARGO-CUADRADOX)
                cuadrado->x = LARGO-CUADRADOX;
}
