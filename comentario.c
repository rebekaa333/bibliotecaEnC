#include "comentario.h"
#include <conio.h>
#include "string.h"

stComentario cargaComentario(char nombreArchivo[])
{
    stComentario comentario;

    int idComentario = cuentaRegistrosArchivoFtell(nombreArchivo) + 1;

    comentario.idComentario = idComentario;

    char aux[500];

    printf("ingrese un titulo para su comentario\n");
    fflush(stdin);
    gets(aux);
    strcpy(comentario.tituloComentario, aux);

    printf("ingrese la descripcion de su comentario\n");
    fflush(stdin);
    gets(aux);
    strcpy(comentario.descripcion, aux);

    printf("ingrese un puntaje (0 a 5) estrellas\n");
    fflush(stdin);
    scanf("%d", &comentario.puntaje);

    printf("\n Ingrese el dia/mes/anio de publicacion:\n");
    fflush(stdin);
    scanf("%s", aux);
    strcpy(comentario.fechaComentario, aux);


    return comentario;
}

void mostrarUnComentario(stComentario comentario)
{
    printf("\n-------------------------------------\n");
    printf("Id cometario: ......%d\n", comentario.idComentario);
    printf("Título: .....%s\n",comentario.tituloComentario );
    printf("Descripcion:....%s\n", comentario.descripcion);
    printf("Puntaje:.....%d\n", comentario.puntaje);
    printf("Fecha:.....%s\n", comentario.fechaComentario);
    printf("\n-------------------------------------\n");


}



int cargarComentariosAlArregloCOM (stComentario A[], int v, int dim, char nombreArchivo[] )
{
    char opcion;
    int i=v;
    stComentario c;

    while(v<dim && opcion!=27)
    {
        printf("\nCARGAR COMENTARIOS AL ARREGLO\n");
        c = cargaComentario(nombreArchivo);
        A[i]=c;
        i++;
        v++;

        printf("Desea seguir cargando? presione ESC para salir\n");
        opcion = getch();
        system ("cls");
        pasarArregloAlArchivoCOM(nombreArchivo, A, v);

    }

    return v;
}

void mostrarComentariosDelArreglo(stComentario A[], int v)
{
    stComentario c;
    int i;
    for (i=0; i<v; i++)
    {
        c = A[i];
        mostrarUnComentario(c);
    }
}

//void mostrarComentariosUsuario(stComentario Ac[], int vComentarios, stUsuario usuario, stLibro Alibro[], int vLibros) //prototipar
//{
//    stLibro aux;
//
//    for (int i = 0; i < vComentarios; i++) {
//        if (Ac[i].eliminado != -1 && Ac[i].idusuario == usuario.idusuario && usuario.eliminado != -1) {
//            aux = buscaLibroPorTitulo(Alibro, vLibros, Alibro[i].titulo);
//
//            mostrarUnComentario(Ac[i], usuario, aux);
//        }
//    }
//}


int randomRango(int min, int max)
{
    return min + rand() % (max - min + 1);
}

void generarFechaAleatoria(char fecha[])
{
    int dia = randomRango(1, 31);
    int mes = randomRango(1, 12);
    int anio = randomRango(1900, 2024);
    sprintf(fecha, "%02d/%02d/%04d", dia, mes, anio);
}

void generarTituloComentarioAleatorio(char titulo[])
{
    const char* titulos[] =
    {
        "Excelente libro", "No me gustó", "Recomendado", "Mala experiencia",
        "Muy interesante", "Decepcionante", "Una joya", "No vale la pena"
    };
    strcpy(titulo, titulos[randomRango(0, 7)]);
}

void generarDescripcionAleatoria(char descripcion[])
{
    const char* descripciones[] =
    {
        "Me encanto la trama y los personajes.",
        "No pude terminarlo, muy aburrido.",
        "Un libro que todos deberían leer.",
        "No cumplió con mis expectativas.",
        "La narrativa es impresionante.",
        "Simplemente decepcionante.",
        "Lo disfruté de principio a fin.",
        "No lo recomiendo."
        "El final fue inesperado y emocionante.",
        "Una lectura muy enriquecedora.",
        "El autor tiene un estilo único y cautivador.",
        "Demasiado predecible, esperaba más.",
        "La ambientacinn es espectacular.",
        "Cada pagina me hizo reflexionar.",
        "Un viaje literario inolvidable.",
        "Sencillamente magistral.",
        "Una pérdida de tiempo, no lo recomiendo."

    };
    strcpy(descripcion, descripciones[randomRango(0, 17)]);
}

stComentario cargarComentarioAleatorio(int idComentario)
{
    stComentario comentario;

    comentario.idComentario = idComentario;
    comentario.idLibro = randomRango(1, 1000);
    comentario.idUsuario = randomRango(1, 10000);
    generarTituloComentarioAleatorio(comentario.tituloComentario);
    generarDescripcionAleatoria(comentario.descripcion);
    comentario.puntaje = randomRango(0, 5);
    generarFechaAleatoria(comentario.fechaComentario);



    return comentario;
}


void pasarArregloAlArchivoCOM(char nombreArchivo[], stComentario A[], int v)
{

    FILE * archi = fopen(nombreArchivo,"wb");

    if(archi)
    {
        fwrite(A,sizeof(stComentario),v,archi);
        fclose(archi);
    }
}

int cantElementosArchivo(char nombreArchivo[], int tamanio)
{

    FILE * archi = fopen(nombreArchivo,"rb");
    int cant = 0;

    if(archi)
    {
        fseek(archi, 0, SEEK_END);
        cant = ftell(archi)/tamanio;
        fclose(archi);
    }

    return cant;

}
int pasarArchivoAlArregloCOM(char nombrearchivo[], stComentario A[], int v, int dim)
{

    int cant = cantElementosArchivo(nombrearchivo,sizeof(stComentario));
    int total = v + cant;

    FILE * archi = fopen(nombrearchivo,"rb");

    if( archi && total <= dim)
    {
        while(fread(&A[v],sizeof(stComentario),1,archi) > 0)
        {
            v++;
        }
        fclose(archi);
    }

    return v;

}

int buscaLibroPorIdEnArreglo(stComentario A[], int v, int idLibro)
{
    int i = 0;
    int pos = 0;

    stComentario comentario;

    while(i < v && pos == 0)
    {
        comentario = A[i];

        if(comentario.idLibro == idLibro)
        {
            pos = i;
        }
        i++;
    }
    return pos;
}




void modificarComentario(stComentario A[], int v)

{

    int id ;
    int opcion;
    int pos = -1;

    stComentario comentario;

    printf("Escriba el id del libro para buscar el comentario que desea modificar:");
    scanf("%d", &id);


    pos = buscaLibroPorIdEnArreglo(A, v, id);

    if(pos > -1)
    {
        do
        {

            printf("Cual campo desea modificar?\n");
            printf("1. TITULO\n");
            printf("2. DESCRIPCION\n");
            printf("3. PUNTAJE\n");
            printf("4. FECHA\n");
            printf("5. CANCELAR\n");

            scanf("%d",&opcion);

            switch(opcion)
            {

            case 1:
                printf("Ingrese el nuevo titulo\n");
                fflush(stdin);
                gets(A[pos].tituloComentario);
                printf("Se modifico correctamente \n");
                break;

            case 2:
                printf("Ingrese la nueva descripción de su comentario\n");
                fflush(stdin);
                gets(A[pos].descripcion);
                printf("Se modifico correctamente \n");
                break;

            case 3:
                printf("Ingrese el nuevo puntaje \n");
                fflush(stdin);
                scanf(&A[pos].puntaje);
                printf("Se modifico correctamente \n");
                break;

            case 4:
                printf("Ingrese la nueva fecha \n");
                gets(A[pos].fechaComentario);
                printf("Se modifico correctamente\n");
                break;


            case 5:
                printf("operacion cancelada \n");
                break;


            }

        }
        while(opcion != 5);

    }
    else
    {

        printf("\n No existe ese id de libro");
    }


}
void arregloComentarioAlArchivoSinEliminados(stComentario arreglo[], int v, char nombreArchivo[])
{
    FILE *archi = fopen(nombreArchivo, "wb");
    if (archi)
    {
        for (int i = 0; i < v; i++)
        {
            if (arreglo[i].eliminado != -1)
            {
                fwrite(&arreglo[i], sizeof(stComentario), 1, archi);
            }
        }
        fclose(archi);
    }
    else
    {
        printf("Error al abrir el archivo para escribir.\n");
    }
}
void eliminarComentario(stComentario arreglo[], int validos)
{

    int idComentario; // Ajusta el tamaño del nombre según tu estructura
    int pos = -1;

    printf("\nIngrese el ID de comentario que desea eliminar: ");
    fflush(stdin);
    scanf("%d", &idComentario);

    pos = buscaComentarioPosicionPorIdArreglo(arreglo, validos, idComentario);

    if (pos >= 0)
    {
        arreglo[pos].eliminado = -1; // Marca el usuario como eliminado
        printf("Comentario %d marcado como eliminado.\n", idComentario);
    }
    else
    {
        printf("Comentario %d no encontrado.\n", idComentario);
    }
}
int buscaComentarioPosicionPorIdArreglo(stComentario arreglo[], int validos, int id)
{
    int i = 0;
    int pos = -1;


    while(i < validos && pos == -1)
    {

        if(arreglo[i].idComentario == id)
        {
            pos = i;
        }
        i++;
    }
    return pos;
}
