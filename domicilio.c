#include "domicilio.h"

stDomicilio cargarDomicilio(){

    stDomicilio domicilio;

    char aux[50];

    printf("\n-----------Carga datos Domicilio----------------\n");

    printf("Ingrese pais:\n");
    fflush(stdin);
    scanf("%s", &aux);
    strcpy(domicilio.pais, aux);

    printf("Ingrese ciudad:\n");
    fflush(stdin);
    scanf("%s", &aux);
    strcpy(domicilio.ciudad, aux);

    printf("Ingrese Localidad:\n");
    fflush(stdin);
    scanf("%s", &aux);
    strcpy(domicilio.localidad, aux);

    printf("Ingrese Codigo Postal:\n");
    fflush(stdin);
    scanf("%d", &domicilio.codigoPostal);

    printf("Ingrese Calle:\n");
    fflush(stdin);
    scanf("%s", &aux);
    strcpy(domicilio.calle, aux);

    printf("Ingrese Altura:\n");
    fflush(stdin);
    scanf("%d", &domicilio.altura);

    return domicilio;


}

void mostrarUnDomicilio(stDomicilio domicilio){

    printf("\n----------------------DOMICILIO-------------------------------\n");
    printf("PAIS: %s\n", domicilio.pais);
    printf("CIUDAD: %s\n", domicilio.ciudad);
    printf("LOCALIDAD: %s\n", domicilio.localidad);
    printf("CP: %d\n", domicilio.codigoPostal);
    printf("CALLE: %s\n", domicilio.calle);
    printf("ALTURA: %d\n", domicilio.altura);
    printf("\n-----------------------------------------------------\n");
}
