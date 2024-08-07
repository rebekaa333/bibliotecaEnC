#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include "usuarios.h"
#include "comentario.h"
#include "libros.h"

#define AR_ARCHIVOS "archivoUsuario.dat"
#define AR_ARCHIVOSCOM "comentarios.dat"
#define AR_ARCHIVOSLIB "libros.dat"

#define DIM_ARREGLO 100
#define DIM_ARREGLOCOM 50
#define DIM_ARREGLOLIB 100

#define ESC 27

//1.
void recuadro(char c, int cantidad);
//2.
void titulo(char titulo[]);

//3.
void opcionesMenuGeneral();
//4.
void menuGeneral(int tipoUsuario);

//5.
void opcionesSubMenuLibros(int tipoUsuario);
//6.
void subMenuLibros(int tipoUsuario);
//7.
void opcSubMenu2AgregarQuitarLibrosFavoritos();
//8.
void agregarQuitarLibrosFavoritos();
//9.
void opcSubMenu2VerLibros();
//10.
void verLibrosPorCategoriaAutor(stLibro arreglo [], int validos);

//11.
void opcionesSubMenuComentarios(int tipoUsuario);
//12.
void subMenuComentarios(int tipoUsuario);
//13.
void opcSubMenu2ModificarEliminarComentario();
//14.
void modificarEliminarComentario(stComentario arreglo[], int validos);

//15.
void opcionesSubMenuUsuario(int tipoUsuario);
//16.
void subMenuUsuario(int tipoUsuario);

//17.
void opcionesInicioYRegistro();
//18.
void inicioYRegistro();
//19.
int tipoDeUsuario(int posUsuario, stUsuario arreglo[]);
//20.
void saltoLinea(int cant);


int main()
{
    inicioYRegistro();
    return 0;
}

// RECUADRO MENU
//1.
void recuadro(char c, int cantidad)
{
    color(3);
    for(int i=0; i<cantidad; i++)
    {
        printf("%c", c);
    }
}

// TITULO PRINCIPAL
//2.
void titulo(char titulo[])
{
    color(9);
    printf("%s", titulo);
}

///=============================================================================================================================
///=============================================================================================================================

// OPCIONES MENU USUARIO
//3.
void opcionesMenuGeneral()
{
    printf("\n");
    recuadro('*', 60);
    titulo("\n B I E N V E N I D O S\n");
    recuadro('*', 60);

    printf("\n\n Seleccione una opcion: \n");
    printf("\n 1) Libros");
    printf("\n 2) Comentarios");
    printf("\n 3) Usuario");
    color(5);
    printf("\n Esc para salir\n\n");

    recuadro('*', 60);
}

//MENU USUARIO
//4.
void menuGeneral(int tipoUsuario)
{
    char opcion;

    do
    {
        opcionesMenuGeneral();
        opcion = getch();
        system("cls");

        switch(opcion)
        {
        case '1':
            subMenuLibros(tipoUsuario);
            break;
        case '2':
            subMenuComentarios(tipoUsuario);
            break;
        case '3':
            subMenuUsuario(tipoUsuario);
            break;

        case 27:
            color(13);
            printf("\n Salir del Menu Principal\n\n");
            break;
        default:
            color(12);
            printf("\n\n<<<<< Opcion invalida. Por favor, vuelva a intentarlo >>>>>\n\n");
            Sleep(1500);
            system("cls");

        }
        printf("\n Presiona una tecla para continuar.");
        getch();
        system("cls");
    }
    while(opcion != ESC);
}

///=============================================================================================================================
///=============================================================================================================================

// OPCIONES SUBMENU LIBROS
//5.
void opcionesSubMenuLibros(int tipoUsuario)
{
    printf("\n");
    recuadro('*', 60);
    titulo("\n L I B R O S\n");
    recuadro('*', 60);

    printf("\n\n Seleccione una opcion: \n");
    printf("\n 1) Agregar libro");              ///listo
    printf("\n 2) Ver listado de libros");      ///por categoria o autor
    printf("\n 3) Buscar libro por titulo");    ///listo
    printf("\n 4) Agregar/Quitar un libro como favorito");
    printf("\n 5) Ver puntaje");

    if(tipoUsuario == 1)
    {
        printf("\n 6) Dar de baja libro");
        printf("\n 7) Eliminar definitivamente un libro");
    }

    color(5);
    printf("\n ESC para volver.\n\n");

    recuadro('*', 60);
}

// SUBMENU LIBROS
//6.
void subMenuLibros(int tipoUsuario)
{
    char opcion;
    char categoria[50];
    char autor[50];
    do
    {
        opcionesSubMenuLibros(tipoUsuario);
        opcion = getch();
        system("cls");

        stLibro arreglo[DIM_ARREGLOLIB];
        int validos = archivoToArregloLIB(AR_ARCHIVOSLIB, arreglo, DIM_ARREGLOLIB, validos);

        char titulo[100];

        switch(opcion)
        {
        case '1':

            validos = cargaArregloLibros(arreglo, DIM_ARREGLOLIB, validos, AR_ARCHIVOSLIB);
            arregloToArchivoLIB(AR_ARCHIVOSLIB, arreglo, validos);

            break;
        case '2':

            //CATEGORIA

            printf("\n Ingrese la categoria a mostrar: ");
            fflush(stdin);
            seleccionarCategoria(categoria);

            if (categoria[0] != '\0')
            {
                mostrarLibrosPorCategoria(arreglo, validos, categoria);
            }
            else
            {
                printf("No se selecciono ninguna categoría válida.\n");
            }

            //AUTOR

            printf("\n Ingrese el autor a mostrar: ");
            fflush(stdin);
            gets(autor);

            if (autor[0] != '\0')
            {
                mostrarLibrosPorAutor(arreglo, validos, autor);
            }
            else
            {
                printf("No se selecciono ningun autor válido.\n");
            }

//            verLibrosPorCategoriaAutor(arreglo,validos);
            break;


        case '3':

            printf("\n Ingrese el titulo del libro que quiere buscar: ");
            fflush(stdin);
            gets(titulo);

            if (titulo[0] != '\0')
            {
                buscaLibroPorTitulo(arreglo, validos, titulo);
            }
            else
            {
                printf("\n No se selecciono ningun titulo valido.\n");
            }
            break;

        case '4':
            agregarQuitarLibrosFavoritos();
            //LLAMAR A LAS DOS FUNCIONES.
            break;
        case '5':
            printf("\n Ver puntaje de libro");
            //LLAMAR A LA FUNCION.
            break;

        case '6':
            if(tipoUsuario == 1)
            {
                int id;
                printf("\n Ingrese el ID del libro que quiere dar de baja: ");
                scanf("%d", &id);

                darDeBajaLibro(arreglo, validos, id);
            }
            else
            {
                color(12);
                printf("\n\n<<<<< Opcion invalida. Por favor, vuelva a intentarlo >>>>>\n\n");
                Sleep(1500);
                system("cls");
            }
            break;
        case '7':
            if(tipoUsuario == 1)
            {
                printf("\n Eliminar definitivamente un libro");
                //LLAMAR A LA FUNCION QUE ELIMINA DEFINITIVAMENTE UN LIBRO.
            }
            else
            {
                color(12);
                printf("\n\n<<<<< Opcion invalida. Por favor, vuelva a intentarlo >>>>>\n\n");
                Sleep(1500);
                system("cls");
            }
            break;
        case 27:
            color(13);
            printf("\n <<< Volver a MENU PRINCIPAL >>>\n\n");
            break;
        default:
            color(12);
            printf("\n\n<<<<< Opcion invalida. Por favor, vuelva a intentarlo >>>>>\n\n");
            Sleep(1500);
            system("cls");
        }
        printf("\n Presiona una tecla para continuar.");
        getch();
        system("cls");
    }
    while(opcion != ESC);
}

//SUBMENU AGREGAR O QUITAR LIBROS COMO FAVORITOS
//7.
void opcSubMenu2AgregarQuitarLibrosFavoritos()
{
    printf("\n");
    recuadro('*', 60);
    titulo("\n\t\tL I B R O S\n");
    recuadro('*', 60);

    printf("\n\n Seleccione una opcion: \n");
    printf("\n 1) Agregar libro como favorito");
    printf("\n 2) Quitar libro como favorito");
    color(5);
    printf("\n ESC para volver.\n\n");

    recuadro('*', 60);
}

//8.
void agregarQuitarLibrosFavoritos()
{
    char opcion;

    do
    {
        opcSubMenu2AgregarQuitarLibrosFavoritos();
        opcion = getch();
        system("cls");

        switch(opcion)
        {
        case '1':
            printf("\n Agregar libro como favorito");
            //LLAMAR A LA FUNCION QUE AGREGUE UN LIBRO COMO FAVORITO.
            break;
        case '2':
            printf("\n Quitar libro como favorito");
            //LLAMAR A LA FUNCION QUE QUITE UN LIBRO COMO FAVORITO.
            break;
        case 27:
            color(13);
            printf("\n <<< Volver a MENU LIBROS >>>\n\n");
            break;
        default:
            color(12);
            printf("\n\n<<<<< Opcion invalida. Por favor, vuelva a intentarlo >>>>>\n\n");
            Sleep(1500);
            system("cls");
        }
        printf("\n Presiona una tecla para continuar.");
        getch();
        system("cls");

    }
    while(opcion != ESC);
}

///=============================================================================================================================
///=============================================================================================================================

//SUBMENU VER LIBROS POR CATEGORIA/AUTOR
//9.
void opcSubMenu2VerLibros()
{
    printf("\n");
    recuadro('*', 60);
    titulo("\n N U E S T R O S  L I B R O S\n");
    recuadro('*', 60);

    printf("\n\n Seleccione una opcion: \n");
    printf("\n 1) Por categoria");
    printf("\n 2) Por autor");
    color(5);
    printf("\n ESC para volver.\n\n");

    recuadro('*', 60);
}

//10.
void verLibrosPorCategoriaAutor(stLibro arreglo [], int validos)
{
    char opcion;
    char categoria[50];
    char autor[50];

    do
    {
        opcSubMenu2VerLibros();
        opcion = getch();
        system("cls");

        switch(opcion)
        {
        case '1':
            printf("\n POR CATEGORIA");
            printf("\n Ingrese la categoria a mostrar: ");
            fflush(stdin);

            seleccionarCategoria(categoria);

            if (categoria[0] != '\0')
            {
                mostrarLibrosPorCategoria(arreglo, validos, categoria);
            }
            else
            {
                printf("No se selecciono ninguna categoría válida.\n");
            }

            break;

        case '2':
            printf("\n Ingrese el autor a mostrar: ");
            fflush(stdin);
            gets(autor);

            if (autor[0] != '\0')
            {
                mostrarLibrosPorAutor(arreglo, validos, autor);
            }
            else
            {
                printf("No se selecciono ningun autor válido.\n");
            }
            break;

        case 27:
            color(13);
            printf("\n <<< Volver a MENU LIBROS >>>\n\n");
            break;
        default:
            color(12);
            printf("\n\n<<<<< Opcion invalida. Por favor, vuelva a intentarlo >>>>>\n\n");
            Sleep(1500);
            system("cls");
        }
        printf("\n Preciona una tecla para continuar.");
        getch();
        system("cls");

    }
    while(opcion != ESC);
}

///=============================================================================================================================
///=============================================================================================================================

// OPCIONES SUBMENU COMENTARIOS
//11.
void opcionesSubMenuComentarios(int tipoUsuario)
{
    printf("\n");
    recuadro('*', 60);
    titulo("\n C O M E N T A R I O S\n");
    recuadro('*', 60);

    printf("\n\n Seleccione una opcion: \n");
    printf("\n 1) Agregar un comentario a un libro");
    printf("\n 2) Ver comentarios");
    printf("\n 3) Modificar o eliminar un comentario");

    if(tipoUsuario == 1)
    {
        printf("\n 4) Eliminar a demanda comentarios/valoraciones de cualquier usuario");
    }
    color(5);
    printf("\n ESC para volver.\n\n");

    recuadro('*', 60);
}

// SUBMENU COMENTARIOS
//12.
void subMenuComentarios(int tipoUsuario)
{
    char opcion;
    stComentario arreglo[DIM_ARREGLOCOM];

    int validos = pasarArchivoAlArregloCOM(AR_ARCHIVOSCOM, arreglo, validos, DIM_ARREGLOCOM);

    do
    {
        opcionesSubMenuComentarios(tipoUsuario);
        opcion = getch();
        system("cls");

        switch(opcion)
        {
        case '1':
            printf("\n AGREGAR COMENTARIO");

            validos = cargarComentariosAlArregloCOM(arreglo, validos, DIM_ARREGLOCOM, AR_ARCHIVOSCOM);

            break;

        case '2':
            printf("\n MOSTRAR LOS COMENTARIOS");
            mostrarComentariosDelArreglo(arreglo, validos);
            break;
        case '3':

            modificarEliminarComentario(arreglo, validos);
            pasarArregloAlArchivoCOM(AR_ARCHIVOSCOM, arreglo, validos);

            break;
        case '4':
            if(tipoUsuario == 1)
            {
                printf("\n Eliminar a demanda comentarios/valoraciones de cualquier usuario");
                //LLAMAR A LA FUNCION QUE ELIMINAR COMENTARIOS DE CUALQUIER USUARIO.
            }
            else
            {
                color(12);
                printf("\n\n<<<<< Opcion invalida. Por favor, vuelva a intentarlo >>>>>\n\n");
                Sleep(1500);
                system("cls");
            }
            break;
        case 27:
            color(13);
            printf("\n <<< Volver a MENU PRINCIPAL >>>\n\n");
            break;
        default:
            color(12);
            printf("\n\n<<<<< Opcion invalida. Por favor, vuelva a intentarlo >>>>>\n\n");
            Sleep(1500);
            system("cls");
        }
        printf("\n Presiona una tecla para continuar.");
        getch();
        system("cls");
    }
    while(opcion != ESC);
}

//SUBMENU MODIFICAR O ELIMINAR UN COMENTARIO
//13.
void opcSubMenu2ModificarEliminarComentario()
{
    printf("\n");
    recuadro('*', 60);
    titulo("\n\t\tC O M E N T A R I O S\n");
    recuadro('*', 60);

    printf("\n\n Seleccione una opcion: \n");
    printf("\n 1) Modificar comentario");
    printf("\n 2) Eliminar comentario");
    color(5);
    printf("\n ESC para volver.\n\n");

    recuadro('*', 60);
}

//14.
void modificarEliminarComentario(stComentario arreglo[], int validos)
{
    char opcion;

    do
    {
        opcSubMenu2ModificarEliminarComentario();
        opcion = getch();
        system("cls");

        switch(opcion)
        {
        case '1':
            printf("\n Modificar comentario");
            modificarComentario(arreglo, validos);
            pasarArregloAlArchivoCOM(AR_ARCHIVOSCOM, arreglo, validos);
            break;
        case '2':
            printf("\n Eliminar comentario");
            eliminarComentario(arreglo, validos);
            arregloComentarioAlArchivoSinEliminados(arreglo, validos,AR_ARCHIVOSCOM);
            break;
        case 27:
            color(13);
            printf("\n <<< Volver a MENU COMENTARIOS >>>\n\n");
            break;
        default:
            color(12);
            printf("\n\n<<<<< Opcion invalida. Por favor, vuelva a intentarlo >>>>>\n\n");
            Sleep(1500);
            system("cls");
        }
        printf("\n Presiona una tecla para continuar.");
        getch();
        system("cls");
    }
    while(opcion != ESC);
}

///=============================================================================================================================
///=============================================================================================================================

// OPCIONES SUBMENU USUARIOS
//15.
void opcionesSubMenuUsuario(int tipoUsuario)
{


    printf("\n");
    recuadro('*', 60);
    titulo("\n\t\tU S U A R I O\n");
    recuadro('*', 60);

    printf("\n\n Seleccione una opcion: \n");
    printf(" 1) Modificar informacion\n");
    printf(" 2) Cerrar sesion\n");


    if(tipoUsuario == 1)
    {

        printf(" 3) Ver todos los usuarios registrados en el sistema\n");
        printf(" 4) Dar de baja usuario");
    }
    color(5);
    printf("\n ESC para volver.\n\n");

    recuadro('*', 60);
}

// SUBMENU USUARIOS
//16.
void subMenuUsuario(int tipoUsuario)
{
    char opcion;

    stUsuario arreglo[DIM_ARREGLO];
    int validos = 0;
    validos = archivoToArregloUsuarios(AR_ARCHIVOS, arreglo, validos, DIM_ARREGLO);

    do
    {
        opcionesSubMenuUsuario(tipoUsuario);
        opcion = getch();
        system("cls");

        switch(opcion)
        {
        case '1':
            printf("\n MODIFICAR INFORMACION\n");
            modificarUsuario(arreglo, validos);
            arregloUsuarioAlArchivo(arreglo, validos, AR_ARCHIVOS);

            break;
        case '2':
            printf("\n CERRAR SESION\n");
            deslogueoUsuario(arreglo, validos);

            break;
        case '3':
            if(tipoUsuario == 1)
            {
                printf("\n Ver todos los usuarios registrados en el sistema\n");
                mostrarUsuariosDelArreglo(arreglo, validos);

            }
            else
            {
                color(12);
                printf("\n\n<<<<< Opcion invalida. Por favor, vuelva a intentarlo >>>>>\n\n");
                Sleep(1500);
                system("cls");
            }
            break;
        case '4':
            if(tipoUsuario == 1)
            {
                printf("\n Dar de baja usuarios");

                darDeBajaUsuario(arreglo,validos);

                arregloUsuarioAlArchivoSinLosEliminados(arreglo, validos, AR_ARCHIVOS);


            }
            else
            {
                color(12);
                printf("\n\n<<<<< Opcion invalida. Por favor, vuelva a intentarlo >>>>>\n\n");
                Sleep(1500);
                system("cls");
            }
        case 27:
            color(13);
            printf("\n <<< Volver a MENU PRINCIPAL >>>\n\n");
            break;
        default:
            color(12);
            printf("\n\n<<<<< Opcion invalida. Por favor, vuelva a intentarlo >>>>>\n\n");
            Sleep(1500);
            system("cls");
        }
        printf("\n Presiona una tecla para continuar.");
        getch();
        system("cls");
    }
    while(opcion != ESC);
}

///=============================================================================================================================
///=============================================================================================================================

//ENTRADA AL PROGRAMA
//17.
void opcionesInicioYRegistro()
{
    recuadro('*', 75);
    titulo("\n\t\t<<<<<< B I B L I O T E C A  V I R T U A L >>>>>>\n");
    recuadro('*', 75);

    printf("\n\n Seleccione una opcion: \n");
    printf("\n 1) Iniciar sesion");
    printf("\n 2) Registrarse");
    color(5);
    printf("\n ESC para salir del sistema\n\n");

    recuadro('*', 75);

}

//18.
void inicioYRegistro()
{

    char opcion;
    stUsuario arreglo[DIM_ARREGLO];

    int validos = archivoToArregloUsuarios(AR_ARCHIVOS, arreglo, validos, DIM_ARREGLO);

    int posUsuario = 0;
    int tipoUsuario = 0;
    stUsuario usuario;

    do
    {
        opcionesInicioYRegistro();
        opcion = getch();
        system("cls");

        switch(opcion)
        {
        case '1':
            printf("\n");
            recuadro('*', 32);
            titulo("\n I N I C I O  D E  S E S I O N \n");
            recuadro('*', 32);

            posUsuario = logueoUsuario(arreglo, validos);
            tipoUsuario = tipoDeUsuario(posUsuario, arreglo);
            system("cls");

            if(tipoUsuario >= 0)
            {
                menuGeneral(tipoUsuario);
            }
            break;
        case '2':
            printf("\n");
            recuadro('*', 26);
            titulo("\n R E G I S T R A R S E \n");
            recuadro('*', 26);

            printf("\n Registro usuario \n");

            validos = cargarUsuariosAlArreglo(arreglo, validos, DIM_ARREGLO, AR_ARCHIVOS);

            break;
        case 27:
            color(13);
            printf("\n\n<<< Gracias por su visita, vuelva pronto >>>\n\n");
            break;
        default:
            color(12);
            printf("\n\n<<<<< Opcion invalida. Por favor, vuelva a intentarlo >>>>>\n\n");
            Sleep(1500);
            system("cls");
        }
        printf("\n Presiona una tecla para continuar.");
        getch();
        system("cls");
    }
    while(opcion != ESC);
}

///=============================================================================================================================
///=============================================================================================================================

//ADMINISTRADOR
//19.
int tipoDeUsuario(int posUsuario, stUsuario arreglo[])
{
    stUsuario usuario;

    usuario = arreglo[posUsuario];

    int tipoUsuario = -1;

    if( usuario.esAdmin == 1)
    {
        tipoUsuario = 1;
    }
    else
    {
        tipoUsuario = 0;
    }

    return tipoUsuario;

}

void saltoLinea(int cant)
{
    for (int i = 0; i<cant; i++)
    {
        printf("\n");
    }
}
