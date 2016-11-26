/**
 * \file header.h
 * \brief Archivo cabecera del programa.
 * \author Leandro Kollenberger <lkollenberger@frba.utn.edu.ar>
 * \date 26.08.2016
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "objetos.h"
//incluyo las librerias de c


#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
//incluyo las librerias de allegro


#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
//incluyo las librerias de sockets


#define LARGO 750
#define ALTO 600
#define FPS 10

#define CUADRADOY 50
#define CUADRADOX 50


#define PI 3.141592
#define ERROR -1
#define OK 0

#define PUERTO 8888


#define ENTER 2

enum MYKEYS
{
	KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT
};
enum TECLAS
{
	ARRIBA, ABAJO, IZQUIERDA, DERECHA, SPACE, UNO,DOS,TRES, A, B, C
};



//jugar
int Jugar(Iniciar *iniciar);
bool TeclasOprimidasJugar(bool *teclas, bool salir, ALLEGRO_EVENT *ev);
bool ActualizarDibujosJuegar(Iniciar *iniciar,Cuadrado *cuadrado,Jugador *jugador,bool redraw);



//menu
int Menu(Iniciar *iniciar);
bool TeclasOprimidasMenu(bool *teclas, bool salir, ALLEGRO_EVENT *ev);
void DibujarMenu(Iniciar *iniciar,Linea *linea);


//puntaje
int MandarPuntaje(int puntaje, int puerto,char *iniciales,char *ip, ALLEGRO_FONT *fuente);
int MostrarPuntaje(int sockfd, ALLEGRO_FONT *fuente);
void OrdenarPuntaje(Puntaje *puntaje);


//instrucciones
bool TeclasOprimidasInstrucciones(bool *teclas, bool salir, ALLEGRO_EVENT *ev);
void MoverImagenIzquierda(ALLEGRO_BITMAP **);
void MoverImagenDerecha(ALLEGRO_BITMAP **);
void  DibujarInstrucciones(Iniciar *iniciar);
int Instrucciones(Iniciar *iniciar);



//iniciar
void InicializarIniciar(Iniciar *iniciar);
int IniciarYErrores(Iniciar *iniciar);
void IniciarLiberarMemoria(Torre **torre,Enemigo **enemigo);
void IniciarLiberarMemoriaCierre(Iniciar *iniciar);


//reloj
bool EmpezarReloj(ALLEGRO_FONT *fuente,Reloj *reloj);
void Reloj0(ALLEGRO_FONT *fuente);
void IniciarReloj(Reloj *reloj);
void Informacion(ALLEGRO_FONT *fuente,Jugador *jugador);
void OpcionesTorre(ALLEGRO_FONT *fuente);


//cuadrado y linea
void IniciarCuadrado(Cuadrado *cuadrado);
void DibujarCuadrado(Cuadrado *cuadrado);
void MoverCuadradoArriba(Cuadrado *cuadrado);
void MoverCuadradoAbajo(Cuadrado *cuadrado);
void MoverCuadradoIzquierda(Cuadrado *cuadrado);
void MoverCuadradoDerecha(Cuadrado *cuadrado);
void IniciarLinea(Linea *linea);
void DibujarLinea(Linea *linea);
void MoverLineaArriba(Linea *linea);
void MoverLineaAbajo(Linea *linea);



//jugador
void IniciarJugador(Jugador *jugador);


//enemigos
void MoverEnemigo(Enemigo **enemigo, Jugador *jugador);
int IniciarEnemigo(Enemigo **enemigo,int a);
void MoverEnemigoAbajo(int final,Enemigo **enemigo,int bandera);
void MoverEnemigoIzquierda(int final,Enemigo **enemigo,int bandera);
void MoverEnemigoDerecha(int final,Enemigo **enemigo,int bandera);
void MoverEnemigoArriba(int final,Enemigo **enemigo,int bandera);
Enemigo * NuevoEnemigo(Enemigo *anterior);
void BarraDeVida(Enemigo **enemigo);
Enemigo *EmpezarOleada(Enemigo *enemigo, int oleada,int malo);
Enemigo *SpawnearEnemigos(Enemigo *enemigo,Jugador *jugador,bool *RelojSalida);
//void OrdenarEnemigos(Enemigo *enemigo);
void LiberarMemoriaEnemigo(Enemigo **enemigo,Enemigo **primero);
void BuscarUltimoEnLaLista(Enemigo *primero);
void PredecirMovimiento(Enemigo **enemigo, Torre *torre);


//torres
void MejorarTorre(Torre **seleccionada,Cuadrado *cuadrado,Jugador *jugador);
void NuevoProyectil(Torre **primera);
int DestruirTorre(Torre **seleccionada,Cuadrado *cuadrado);
void LiberarMemoriaTorres(Torre **seleccionada, Torre **primera);
void CrearTorre(Torre **primera);
int BuscarUltimoEnRadio(Enemigo **primero,Torre **torre);
void IniciarTorre(Torre **seleccionada,Cuadrado *cuadrado,int a);
void ActualizarTorre(Torre **primera,Cuadrado *cuadrado,Enemigo **primero, Reloj *reloj);
void DispararAlUltimo(Torre **seleccionada,Enemigo **ultimo,Reloj *reloj);
int HayTorre(Cuadrado *cuadrado,Torre *torre);
int CantidadDeBalas(Torre *seleccionada);
void ActualizarProyectil(Torre **seleccionada, Enemigo **ultimo);


//mapa
void ImprimirMapa(Iniciar *iniciar);
