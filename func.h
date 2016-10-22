#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<ctype.h>

typedef struct
    {
        char titulo[21];
        char genero[21];
        int duracion;
        char descripcion[151];
        float puntaje;
        char linkImagen[301];
        int estado;
    }EMovie;

int menu();
void agregarPelicula(EMovie movie, FILE *parch);
void borrarPelicula(EMovie movie, FILE *parch);
void modificarPelicula(EMovie movie, FILE *parch);
int generarPagina();
void val_tam(char x[], int tam);
void val_rta(char respuesta);

