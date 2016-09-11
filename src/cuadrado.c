#include "header.h"
void IniciarCuadrado(Cuadrado *cuadrado)
{
        cuadrado->x = 0;
        cuadrado->y = 0;
        cuadrado->ID = JUGADOR;
}
void DibujarCuadrado(Cuadrado *cuadrado)
{
        al_draw_rectangle(cuadrado->x, cuadrado->y , cuadrado->x+56, cuadrado->y+42, al_map_rgb(0, 0, 0),0);
}
void MoverCuadradoArriba(Cuadrado *cuadrado)
{
        cuadrado->y -= 42;
        if(cuadrado->y < 0)
                cuadrado->y = 0;
}
void MoverCuadradoAbajo(Cuadrado *cuadrado)
{
        cuadrado->y += 42;
        if(cuadrado->y > ALTO)
                cuadrado->y = ALTO;
}
void MoverCuadradoIzquierda(Cuadrado *cuadrado)
{
        cuadrado->x -= 56;
        if(cuadrado->x < 0)
                cuadrado->x = 0;
}
void MoverCuadradoDerecha(Cuadrado *cuadrado)
{
        cuadrado->x += 56;
        if(cuadrado->x > LARGO)
                cuadrado->x = LARGO;
}


