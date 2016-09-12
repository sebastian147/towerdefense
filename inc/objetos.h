#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>

enum IDS{JUGADOR};
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
	char nombre[20];
	ALLEGRO_BITMAP *imagen;
	int vida;
	int velocidad;
	int danio;
	xy pocicion;
	xy FrameActual;
	xy DistanciaFrames;
	xy CantidadFrames;
	int contador;
	int bandera;
};
typedef struct ENEMIGO Enemigo;
