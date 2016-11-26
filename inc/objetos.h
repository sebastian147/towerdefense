#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

//enum IDS{JUGADOR};
struct XY
{
	int x;
	int y;
};
typedef struct XY xy;



struct CUADRADO
{
        int ID;
        int x;
        int y;
};
typedef struct CUADRADO Cuadrado;


struct ENEMIGO
{
	int ID;
	ALLEGRO_BITMAP *imagen;
	xy vida;
	int velocidad;
	int danio;
	xy pocicion;
	xy FrameActual;
	xy DistanciaFrames;
	xy CantidadFrames;
	int contador;
	int bandera;
	int puntaje;
	int dinero;
	struct ENEMIGO *siguiente;
	struct ENEMIGO *anterior;
	int spritey;
//eliminar las que siguen
};
typedef struct ENEMIGO Enemigo;

struct OLEADA
{
	struct ENEMIGO *Enemigo;
	struct ENEMIGO *Minota;
};
typedef struct OLEADA Oleada;


struct RELOJ
{
	int minutos;
	int segundos;
	int milisegundos;
	int DentroDeFuncion;
};
typedef struct RELOJ Reloj;



struct INICIAR
{
	ALLEGRO_DISPLAY *display;
	ALLEGRO_EVENT_QUEUE *event_queue;
	ALLEGRO_TIMER *timer;
	ALLEGRO_BITMAP *mapa;
	ALLEGRO_BITMAP *fondo;
	ALLEGRO_FONT *fuente;

};
typedef struct INICIAR Iniciar;



struct JUGADOR
{
	char iniciales[3];
	int vida;
	int score;
	int plata;
	int oleada;
	int relojito;
	int malo;
};
typedef struct JUGADOR Jugador;


struct BALA
{
	xy pocicion;
	int velocidad;
	xy pocicionenemigo;
	struct BALA *siguiente;
	ALLEGRO_BITMAP *imagen;

};
typedef struct BALA Bala;


struct TORRE
{
	int rango;
	int danio;
	xy FrameActual;
	xy DistanciaFrames;
	xy pocicion;
	int cadencia;
	int tiempo;
	int velocidad;
	xy pocicionenemigo;
	int tiros;
	struct TORRE *siguiente;
	struct TORRE *anterior;
	struct BALA disparo[5];
	ALLEGRO_BITMAP *imagen;
	int bandera;
	int PrecioMejora;
};
typedef struct TORRE Torre;

struct PUNTAJE
{
	char nombre[5];
	int score;
};
typedef struct PUNTAJE Puntaje;

struct LINEA
{
		xy pocicioninicial;
		xy pocicionfinal;
		int bandera;
};
typedef struct LINEA Linea;
