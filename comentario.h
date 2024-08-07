#ifndef COMENTARIO_H_INCLUDED
#define COMENTARIO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>



typedef struct
{
    int idComentario;  /// único, autoincremental
    int idLibro;
    int idUsuario;
    char tituloComentario[100];
    char descripcion[500];
    int puntaje; /// de 0 a 5 "estrellas"
    char fechaComentario[20]; /// o se puede hacer con dia, mes, anio.
    int eliminado; /// 0 si está activo - 1 si está eliminado
} stComentario;


///CARGA Y MUESTRA UN COMENTARIO ///
stComentario cargaComentario(char nombreArchivo[]); ///listo
void mostrarUnComentario(stComentario comentario);///listo


///CARGA AL ARREGLO Y MUESTRA ///
int cargarComentariosAlArregloCOM (stComentario A[], int v, int dim, char nombreArchivo[]); ///listo
void mostrarComentariosDelArreglo(stComentario A[], int v);///listo
void mostrarOtrosComentarios (stComentario A[], int v, int idUsuario, int idLibro);

///PASO DE ARREGLO AL ARCHIVO Y VISEVERSA///

void pasarArregloAlArchivoCOM (char nombreArchivo[], stComentario A[], int v);///listo
int cantElementosArchivo(char nombreArchivo[], int tamanio);///listo
int pasarArchivoAlArregloCOM(char nombreArchivo[], stComentario A[], int v, int dim);///listo

///CARGA RANDOM DE COMENTARIOS (50 COMENTARIOS)///

int randomRango(int min, int max);
void generarFechaAleatoria(char fecha[]);
void generarTituloComentarioAleatorio(char titulo[]);
void generarDescripcionAleatoria(char descripcion[]);
stComentario cargarComentarioAleatorio(int idComentario);

///MODIFICAR COMENTARIO o PUNTAJE///

int buscaLibroPorIdEnArreglo(stComentario A[], int v, int idLibro);///listo
void modificarComentario(stComentario A[], int v); ///listo



///ELIMINAR COMENTARIO///

void arregloComentarioAlArchivoSinEliminados(stComentario arreglo[], int v, char nombreArchivo[]);
void eliminarComentario(stComentario arreglo[], int validos);
int buscaComentarioPosicionPorIdArreglo(stComentario arreglo[], int validos, int id);


//void mostrarComentariosUsuario(stComentario Ac[], int vComentarios, stUsuario usuario, stLibro Alibro[], int vLibros);



//int cargaComentarios(int A[], int v, int dim);

#endif // COMENTARIO_H_INCLUDED
