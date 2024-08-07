#include "libros.h"

#define ESC 27
#define DIM_ARREGLO 100

//FUNCIONES

// 1.
stLibro cargarUnLibro(char nombreArchivo []){
    stLibro libro;
    int opcionCategoria=0;

    int idLibro = cuentaRegistrosArchivoFtell(nombreArchivo) + 1;

    libro.idLibro = idLibro;

    printf("\n Ingrese los datos del libro que desea cargar:\n");

    printf("\n Titulo: ");
    fflush(stdin);
    gets(libro.titulo);

    printf("\n Editorial: ");
    fflush(stdin);
    gets(libro.editorial);

    printf("\n Autor: ");
    fflush(stdin);
    gets(libro.autor);

    printf("\n Categoria: ");
    mostrarOpcionesCategoria();
    fflush(stdin);
    gets(libro.categoria);

    libro.valoracion = 0;

    return libro;
}

// 2.
int cargaArregloLibros(stLibro a[], int dim, int validos, char nombreArchivo [])
{
    char opcion=0;
    int i=validos;

    while(i<dim && opcion != ESC){
        system("cls");
        a[i]=cargarUnLibro(nombreArchivo);
        i++;

        printf("\n ESC para salir o cualquier tecla para continuar.");
        fflush(stdin);
        opcion=getch();

    }

    return i;
}

//3.
void mostrarOpcionesCategoria() {
    printf("\n Seleccione una categoria:");
    printf("\n 1) Ciencia ficcion");
    printf("\n 2) Fantasia");
    printf("\n 3) Terror");
    printf("\n 4) Drama");
    printf("\n 5) Poesia");
    printf("\n");
}

//4.
//SELECCIONAR CATEGORIA
void seleccionarCategoria(char *categoria) {
    char opcion;
    int flag = 0; //Bandera para ver los libros de esa categoria

    mostrarOpcionesCategoria();

    do {
        printf(" Ingrese una opcion: ");
        scanf("%c", &opcion);
        fflush(stdin);

        switch(opcion) {
            case '1':
                strcpy(categoria, "Ciencia ficcion");
                flag = 1;
                break;
            case '2':
                strcpy(categoria, "Fantasia");
                flag = 1;
                break;
            case '3':
                strcpy(categoria, "Terror");
                flag = 1;
                break;
            case '4':
                strcpy(categoria, "Drama");
                flag = 1;
                break;
            case '5':
                strcpy(categoria, "Poesia");
                flag = 1;
                break;
            case ESC:
                printf("\n ESC para salir");
                opcion = ESC;
                break;
            default:
                printf("\n Opcion no valida. Por favor intentelo nuevamente.\n");
        }

    } while (flag==0 && opcion != ESC);

    if (opcion == ESC && flag==0) {
        categoria[0] = '\0';
    }
}

// 5.
void muestraUnLibro(stLibro libro)
{
    printf("\n ID: %d", libro.idLibro);
    printf("\n Titulo: %s", libro.titulo);
    printf("\n Autor: %s", libro.autor);
    printf("\n Editorial: %s", libro.editorial);
    printf("\n Categoria: %s", libro.categoria);
    printf("\n ========================================================\n");
}

// 6.
//MUESTRA LIBROS POR CATEGORIA
void mostrarLibrosPorCategoria(stLibro libros[], int validos, char *categoria){
    int flag = 0;
    int i = 0;

    while (flag == 0 && i < validos) {
        if (strcmp(libros[i].categoria, categoria) == 0) {
            muestraUnLibro(libros[i]);
            flag = 1;
        }
        i++;
    }
    if (flag == 0) {
        printf("\n No se encontro ningun libro con esa categoria \"%s\".\n", categoria);
    }
}

//7.
//MOSTRAR LIBROS POR CATEGORIA
//HACER SYSTEM("CLS") en el menu que llama a la funcion y probar si limpia corractamente
//void mostrarLibrosPorAutor(stLibro libros[], int validos, char *autor) {
//    int flag = 0; /*Bandera para verificar si se encontro algun libro, fue la solucion que encontre porque
//    sino no el ultimo printf me lo mostraba en bucle cuando no habia libros de ese autor. lo mismo con la de categoria" */
//    printf("\n Libros del autor %s:\n", autor);
//    for (int i = 0; i < validos; i++) {
//        if (strcmp(libros[i].autor, autor) == 0) {
//            muestraUnLibro(libros[i]);
//            flag = 1;
//        }
//    }
//    if (flag == 0) {
//        printf("\n No se encontraron libros de este autor.\n");
//    }
//}

void mostrarLibrosPorAutor(stLibro libros[], int validos, char *autor) {
    int flag = 0;
    int i = 0;

    while (flag == 0 && i < validos) {
        if (strcmp(libros[i].autor, autor) == 0) {
            muestraUnLibro(libros[i]);
            flag = 1;
        }
        i++;
    }
    if (flag == 0) {
        printf("\n No se encontro ningun libro con ese autor \"%s\".\n", autor);
    }
}

//8.
void buscaLibroPorTitulo(stLibro libros[], int validos, char *titulo) {
    int flag = 0;
    int i = 0;

    while (flag == 0 && i < validos) {
        if (strcmp(libros[i].titulo, titulo) == 0) {
            muestraUnLibro(libros[i]);
            flag = 1;
        }
        i++;
    }
    if (flag == 0) {
        printf("\n No se encontro ningun libro con el titulo \"%s\".\n", titulo);
    }
}

// 9.
int archivoToArregloLIB(char nombreArchivo[], stLibro a[], int dim, int validos){
    FILE *archi=fopen(nombreArchivo, "rb");
    if(archi){
        while(validos < dim && fread(&a[validos], sizeof(stLibro), 1, archi)>0){
            validos ++;
        }
        fclose(archi);
    }
    return validos;
}

// 10.
void arregloToArchivoLIB(char nombreArchivo[], stLibro libros[], int validos)
{
    FILE *archi=fopen(nombreArchivo, "ab");
    stLibro libro;
    int i=0;

    if(archi){
        while(i<validos){
            fwrite(&libro, sizeof(stLibro), 1, archi);
            i++;
        }
        fclose(archi);
    }
}

void darDeBajaLibro(stLibro libros[], int validos, int id) {
    int flag = 0;

    for (int i = 0; i < validos; i++) {
        if (libros[i].idLibro == id) {
            libros[i].eliminado = 1;
            flag = 1;
        }
    }
    if (flag == 1) {
        printf("\n El libro con ID %d fue dado de baja con exito.\n", id);
    } else {
        printf("\n No se encontro un libro con el ID %d.\n", id);
    }
}
