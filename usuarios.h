#ifndef USUARIOS_H_INCLUDED
#define USUARIOS_H_INCLUDED
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <conio.h>
#include "domicilio.h"

typedef struct{
    int idusuario;
    char email[100];
    char password[20];
    char username[20];
    int esAdmin;  /// 1 = si  0 = no
    char genero;
    char fechanacimiento[20];  /// o se puede hacer con dia, mes, anio.
    int librosfavoritos[50]; /// se van a guardar los id de los libros favs.
    char dni[10];
    stDomicilio domicilio;
    int eliminado; /// 0 si est� activo - 1 si est� eliminado
}stUsuario;


//RECIBIR EMAIL Y CONTRASEÑA LOGUEO
//1.
int logueoUsuario(stUsuario arreglo[], int validos);//LISTO
//1bis
int buscoPosEnArregloPorEmail(stUsuario arreglo[],int validos, char email[]);//LISTO

//VERIFICAR E INDICAR SI EL MAIL EXISTE.
//2.
int verificarEmailExistente(char email[], stUsuario arreglo[], int validos);//LISTO

//VERIFICAR SI E INDICAR SI LA CONTRASEÑA ES CORRECTA.
//3.
int verificarContraseniaCorrespondeAlEmail(char contrasenia[], char email[], stUsuario arreglo[], int validos);//LISTO


//REGISTRO
//4.
stUsuario registroUnUsuario(char nombreArchivo[]); //LISTO


//5.
void mostrarUnUsuario(stUsuario usuario); //LISTO

//VERIFICAR EMAIL Y CONTRASEÑA CARACTERISTICAS
//6.
int emailCorrecto(char email[]);//LISTO

//7.
int indiceDeCaracterEnCadena(char cadena[], char caracter[]);//LISTO

//8.
int contraseniaCorrecta(char contrasenia[]);//LISTO


//CARGA AL ARREGLO
//9.
int cargarUsuariosAlArreglo(stUsuario A[], int v, int dim,char nombreArchivo[]);//LISTO

//10.
void mostrarUsuariosDelArreglo(stUsuario arreglo[], int v);//LISTO


//PASO DE ARREGLO AL ARCHIVO Y VICEVERSA

//11.
void arregloUsuarioAlArchivo (stUsuario arreglo[], int v, char nombreArchivo[]);//LISTO
//11.bis
void arregloUsuarioAlArchivoSinLosEliminados(stUsuario arreglo[], int validos, char nombreArchivo[]);

//12.
int archivoToArregloUsuarios(char nombrearchivo[], stUsuario a[], int v, int dim);//LISTO

//13.
int cuentaRegistrosArchivoFtell(char nombreArchivo[]);//LISTO

//MODIFICAR INFO, DESLOGUEO USUARIO
//14.
void modificarUsuario(stUsuario arreglo[], int validos);//LISTO

//15.
int buscaAlumnoPosicionPorNombreEnArreglo(stUsuario arreglo[], int validos, char nombre[]);//LISTO

//16.
void deslogueoUsuario(stUsuario arreglo[], int validos);


//USUARIO ADMINISTRADOR
//17.
void darDeBajaUsuario(stUsuario arreglo[], int validos);//LISTO



#endif // USUARIOS_H_INCLUDED
