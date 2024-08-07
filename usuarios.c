#include "usuarios.h"
#include "domicilio.h"

int logueoUsuario(stUsuario arreglo[], int validos)
{
    char auxEmail [50];
    int banderaEmail = 0;

    char auxContrasenia [8];
    int banderaContrasenia = 0;

    int posUsuario = -1;

    while(banderaEmail == 0)
    {

        printf("\nIngrese su email: \n");
        fflush(stdin);
        scanf("%s", auxEmail);
        banderaEmail = verificarEmailExistente(auxEmail, arreglo, validos);

        if (banderaEmail == 0 )
        {
            printf("Email es incorrecto o inexistente.\n");
            Sleep(2000);
            system("cls");
        }
    }

    while(banderaContrasenia == 0)
    {

        printf("Ingrese su contrasenia: \n");
        fflush(stdin);
        scanf("%s", auxContrasenia);
        banderaContrasenia = verificarContraseniaCorrespondeAlEmail(auxContrasenia, auxEmail, arreglo, validos);

        if (banderaContrasenia == 0 )
        {
            printf("La contraseña es incorrecta o no corresponde al email.\n");
            Sleep(2000);
            system("cls");
        }
    }

    if (banderaEmail == 1 && banderaContrasenia == 1)
    {
        posUsuario = buscoPosEnArregloPorEmail(arreglo, validos, auxEmail);
    }


    return posUsuario;
}

//1bis
int buscoPosEnArregloPorEmail(stUsuario arreglo[],int validos, char email[])
{
    int i = 0;
    int pos = 0;

    stUsuario usuario;

    while(i < validos && pos == 0)
    {
        usuario = arreglo[i];

        if(strcmp(usuario.email, email) == 0)
        {
            pos = i;
        }
        i++;
    }
    return pos;
}

//2.
int verificarEmailExistente(char email[], stUsuario arreglo[], int validos)
{
    int i = 0;
    stUsuario usuario;
    int bandera = 0;

    while( i<validos )
    {
        usuario = arreglo[i];

        if(strcmp(usuario.email, email) == 0)
        {
            bandera = 1;
        }
        i++;
    }

    return bandera;
}

//3.
int verificarContraseniaCorrespondeAlEmail(char contrasenia[],char email[], stUsuario arreglo[], int validos)
{
    int i = 0;
    stUsuario usuario;
    int bandera = 0;

    while( i<validos )
    {
        usuario = arreglo[i];


        if(strcmp(usuario.email, email ) == 0)//usar funciones de string
        {
            if(strcmp(usuario.password, contrasenia) == 0)
            {
                bandera = 1;
            }
        }
        i++;
    }

    return bandera;
}

//4.
stUsuario registroUnUsuario(char nombreArchivo[])
{
    stUsuario usuario;

    int banderaEmail = 0;
    int banderaContrasenia = 0;

    char aux [50];
    char auxEmail[50];
    char auxContra[8];

    int idUsuario = cuentaRegistrosArchivoFtell(nombreArchivo) + 1;

    usuario.idusuario = idUsuario;

    while(banderaEmail == 0)
    {

        printf("Ingrese email(debe tener @ y .com): \n");
        fflush(stdin);
        scanf("%s", auxEmail);
        strcpy(usuario.email, auxEmail);

        banderaEmail = emailCorrecto(auxEmail);

        if(banderaEmail == 0)
        {
            printf("Email erroneo, ingrese email con @ y .com \n");
            Sleep(2000);
            system("cls");
        }

    }

    while(banderaContrasenia == 0)
    {
        printf("Ingrese su contrasenia (debe tener una MAYUSCULA y una minuscula): \n");
        fflush(stdin);
        scanf("%s", auxContra);
        strcpy(usuario.password,auxContra);

        banderaContrasenia = contraseniaCorrecta(auxContra);

        if(banderaContrasenia == 0)
        {
            printf("La contrasenia es erronea, debe tener una MAYUSCULA y una minuscula.\n");
            Sleep(2000);
            system("cls");
        }
    }
    printf("Ingrese el nombre de usuario:  \n");
    fflush(stdin);
    scanf("%s", aux);
    strcpy(usuario.username,aux);

    printf("Seleccione que tipo de usuario es:\n Usuario Regular(opcion 0). \n Usuario Admin(opcion 1).");
    fflush(stdin);
    scanf("%d",&usuario.esAdmin);

    printf("\n Ingrese el genero ('m' , 'f', 'x' ): \n ");
    fflush(stdin);
    scanf("%c",&usuario.genero);

    printf("\n Ingrese fecha de nacimiento: (dia/mes/año) \n");
    fflush(stdin);
    scanf("%s", aux);
    strcpy(usuario.fechanacimiento, aux);

//    usuario.librosfavoritos = 0;

    printf("\n Ingrese dni:\n");
    fflush(stdin);
    scanf("%s",aux);
    strcpy(usuario.dni,aux);

    usuario.domicilio = cargarDomicilio();

    usuario.eliminado = 0;

    return usuario;
}

//5.
void mostrarUnUsuario(stUsuario usuario)
{


    printf("\nID de usuario:.......%d \n",usuario.idusuario);
    printf("Nombre:...............%s \n",usuario.username);
    printf("Email:................%s \n",usuario.email);
    printf("DNI:..................%s \n",usuario.dni);
    printf("Genero:...............%c \n",usuario.genero);
    printf("Fecha Nacimiento:.....%s \n",usuario.fechanacimiento);
    printf("Estado:...............%d \n",usuario.eliminado);
    printf("Tipo de usuario:......%d \n",usuario.esAdmin);
    saltoLinea(2);
    mostrarUnDomicilio(usuario.domicilio);
}

//6.
int emailCorrecto(char email[])
{

    int banderaEmail = 0;

    int indicePunto = indiceDeCaracterEnCadena(email, '.');
    int indiceArroba = indiceDeCaracterEnCadena(email, '@');

    if (indicePunto == 1 && indiceArroba == 1)
    {
        banderaEmail = 1;
    }

    return banderaEmail;

}

//7.
int indiceDeCaracterEnCadena(char cadena[], char caracter[])
{
    int pos = 0;
    int indice = 0;

    while (cadena[pos] != '\0')
    {
        char actual = cadena[pos];

        if (actual == caracter)
        {
            indice = 1;
        }
        pos++;
    }
    return indice;
}


//8.
int contraseniaCorrecta(char contrasenia [])
{
    int bandera = 0;
    int i = 0;

    while( i < strlen(contrasenia) && bandera == 0)
    {

        if(isupper(contrasenia[i]))
        {
            bandera = 1;
        }
        i++;
    }
    return bandera;
}

//9.
int cargarUsuariosAlArreglo(stUsuario A[], int v, int dim, char nombreArchivo[])
{

    char opcion;
    stUsuario u;

    while(v < dim && opcion != 27)
    {
        u = registroUnUsuario(nombreArchivo);
        A[v] = u;
        v ++;


        printf("Desea seguir cargando usuarios, presione ESC para salir");
        fflush(stdin);
        opcion = getch();
        system("cls");

        arregloUsuarioAlArchivo(A, v, nombreArchivo);
    }


    return v;
}

//10.
void mostrarUsuariosDelArreglo(stUsuario A[], int v)
{


    for (int i = 0; i < v; i++)
    {
        if(A[i].eliminado != -1)
        {
            mostrarUnUsuario(A[i]);
            printf("\n");
        }
    }
}

//11.
void arregloUsuarioAlArchivo(stUsuario arreglo[], int validos, char nombreArchivo[]) {

    FILE *archivo;
    archivo = fopen(nombreArchivo, "wb");
    if (archivo != NULL) {
        fwrite(arreglo, sizeof(stUsuario), validos, archivo);
        fclose(archivo);
    }else {
        printf("Error al abrir el archivo para escribir.\n");
    }
}

//11.bis
void arregloUsuarioAlArchivoSinLosEliminados(stUsuario arreglo[], int validos, char nombreArchivo[])
{
    FILE *archivo = fopen(nombreArchivo, "wb");
    if (archivo != NULL) {
        for (int i = 0; i < validos; i++) {
            if (arreglo[i].eliminado != -1) {
                fwrite(&arreglo[i], sizeof(stUsuario), 1, archivo);
            }
        }
        fclose(archivo);
    } else {
        printf("Error al abrir el archivo para escribir.\n");
    }
}

//12.
int archivoToArregloUsuarios(char nombrearchivo[], stUsuario a[], int v, int dim)
{

    int cant = cuentaRegistrosArchivoFtell(nombrearchivo);
    int total = v + cant;

    FILE * archi = fopen(nombrearchivo,"rb");

    if( archi && total <= dim)
    {
        while(fread(&a[v],sizeof(stUsuario),1,archi) > 0)
        {
            v++;
        }
        fclose(archi);
    }

    return v;

}

//13.
int cuentaRegistrosArchivoFtell(char nombreArchivo[])
{
    int cantidad =0;
    FILE * archi= fopen(nombreArchivo,"rb"); /// no funciona si abro con ab o a+b

    if(archi!=NULL)
    {

        fseek(archi,0, SEEK_END);

        cantidad = ftell(archi)/ sizeof(stUsuario);

        fclose(archi);
    }
    return cantidad;
}

//14.
void modificarUsuario(stUsuario arreglo[], int validos)
{

    char nombre[15];
    int option2;
    int pos = -1;
    char opcionSalir = 0;


    printf("Escriba su nombre para modificar su usuario:");
    scanf("%s", nombre);


    pos = buscaAlumnoPosicionPorNombreEnArreglo(arreglo, validos, nombre);

    if(pos > -1)
    {
        while(option2 != 6 && opcionSalir != 27)
        {

            printf("Cual campo queres modificar?\n");
            printf("1. Email\n");
            printf("2. Contrasenia\n");
            printf("3. Nombre\n");
            printf("4. Genero\n");
            printf("5. Fecha Nacimiento\n");
            printf("6. Cancelar\n");

            scanf("%d",&option2);

            switch(option2)
            {

            case 1:
                printf("Ingrese el nuevo email\n");
                fflush(stdin);
                gets(arreglo[pos].email);
                printf("Se modifico correctamente \n");
                break;

            case 2:
                printf("Ingrese la nueva contrasenia\n");
                fflush(stdin);
                gets(arreglo[pos].password);
                printf("Se modifico correctamente \n");
                break;

            case 3:
                printf("Ingrese el nuevo nombre \n");
                fflush(stdin);
                gets(arreglo[pos].username);
                printf("Se modifico correctamente \n");
                break;

            case 4:
                printf("Ingrese el nuevo genero \n");
                fflush(stdin);
                scanf("%c", arreglo[pos].genero);
                printf("Se modifico correctamente\n");
                break;

            case 5:
                printf("Ingrese la nueva fecha de nacimiento \n");
                fflush(stdin);
                gets(arreglo[pos].fechanacimiento);
                printf("Se modifico correctamente\n");
                break;

            case 6:
                break;
            default:
                printf("No existe esa opción \n");
            }

            printf("Desea seguir modificando datos? presione ESC para salir");
            fflush(stdin);
            opcionSalir = getch();
            system("cls");
        }

    }
    else
    {

        printf("\n No existe usuario con ese nombre");
    }


}


//15.
int buscaAlumnoPosicionPorNombreEnArreglo(stUsuario arreglo[], int validos, char nombre[])
{
    int i = 0;
    int pos = -1;

    stUsuario usuario;

    while(i < validos && pos == -1)
    {
        usuario = arreglo[i];

        if(strcmp(usuario.username, nombre) == 0)
        {
            pos = i;
        }
        i++;
    }
    return pos;
}

//16.
void deslogueoUsuario(stUsuario arreglo[], int validos)
{
    int opcion = 0;
    printf("Presione 1 para Salir.\n");
    fflush(stdin);
    scanf("%d", &opcion);
    system("cls");

    if(opcion == 1)
    {
        inicioYRegistro();
    }

}

//17.
void darDeBajaUsuario(stUsuario arreglo[], int validos) {
    char nombre[50]; // Ajusta el tamaño del nombre según tu estructura
    int pos = -1;

    printf("\nIngrese nombre de usuario que desea eliminar: ");
    fflush(stdin);
    scanf("%s", nombre);

    pos = buscaAlumnoPosicionPorNombreEnArreglo(arreglo, validos, nombre);

    if (pos >= 0) {
        arreglo[pos].eliminado = -1; // Marca el usuario como eliminado
        printf("Usuario %s marcado como eliminado.\n", nombre);
    } else {
        printf("Usuario %s no encontrado.\n", nombre);
    }
}


