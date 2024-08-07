#ifndef LIBROS_H_INCLUDED
#define LIBROS_H_INCLUDED
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <conio.h>

//ESTRUCTURA
typedef struct{
    int idLibro; /// único, autoincremental
    char titulo[100];
    char editorial[50];
    char autor[50];
    char categoria[50];
    float valoracion;
    int eliminado; /// 0 si está activo - 1 si está eliminado
}stLibro;

//PROTOTIPADOS
//1.
stLibro cargarUnLibro(char nombreArchivo[]);
//2.
int cargaArregloLibros(stLibro a[], int dim, int validos, char nombreArchivo []);
//3.
void mostrarOpcionesCategoria();
//4.
//SELECCIONAR CATEGORIA
void seleccionarCategoria(char *categoria);
// 5.
void muestraUnLibro(stLibro libro);
// 6.
//MUESTRA LIBROS POR CATEGORIA
void mostrarLibrosPorCategoria(stLibro libros[], int validos, char *categoria);
//7.
void mostrarLibrosPorAutor(stLibro libros[], int validos, char *autor);
//8.
void buscaLibroPorTitulo(stLibro libros[], int validos, char *titulo);
//9.
int archivoToArregloLIB(char nombreArchivo[], stLibro a[], int dim, int validos);
//10.
void arregloToArchivoLIB(char nombreArchivo[], stLibro libros[], int validos);


void darDeBajaLibro(stLibro libros[], int validos, int id);



#endif // LIBROS_H_INCLUDED
