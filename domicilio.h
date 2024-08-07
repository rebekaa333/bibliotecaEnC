#ifndef DIRECCION_H_INCLUDED
#define DIRECCION_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>


typedef struct{

    char pais[100];
    char ciudad[100];
    char localidad[50];
    int codigoPostal;
    char calle[50];
    int altura;

}stDomicilio;

stDomicilio cargarDomicilio();
void mostrarUnDomicilio(stDomicilio domicilio);


#endif // DIRECCION_H_INCLUDED
