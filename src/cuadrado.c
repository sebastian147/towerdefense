#include "header.h"
float CuadradoLargo=(LARGO-160)/12;
float CuadradoAlto=ALTO/12;
void IniciarCuadrado(Cuadrado *cuadrado)
{
        cuadrado->x = 0;
        cuadrado->y = 0;
        cuadrado->ID = JUGADOR;
}
void DibujarCuadrado(Cuadrado *cuadrado)
{
        al_draw_rectangle(cuadrado->x, cuadrado->y , cuadrado->x+CuadradoLargo, cuadrado->y+CuadradoAlto, al_map_rgb(0, 0, 0),0);
}
void MoverCuadradoArriba(Cuadrado *cuadrado)
{
        cuadrado->y -= CuadradoAlto;
        if(cuadrado->y < 0)
                cuadrado->y = 0;
}
void MoverCuadradoAbajo(Cuadrado *cuadrado)
{
        cuadrado->y += CuadradoAlto;
        if(cuadrado->y > ALTO-CuadradoAlto)
                cuadrado->y = ALTO-CuadradoAlto;
}
void MoverCuadradoIzquierda(Cuadrado *cuadrado)
{
        cuadrado->x -= CuadradoLargo;
        if(cuadrado->x < 0)
                cuadrado->x = 0;
}
void MoverCuadradoDerecha(Cuadrado *cuadrado)
{
        cuadrado->x += CuadradoLargo;
        if(cuadrado->x > LARGO-CuadradoLargo)
                cuadrado->x = LARGO-CuadradoLargo;
}


