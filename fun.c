#include "func.h"

int menu()
    {
        int op;

        printf("*****BIENVENIDO AL MENU DE OPCIONES*****\n");
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");
        printf("\nIngrese la opcion: ");
        scanf("%d",&op);

        return op;
    }

void agregarPelicula(EMovie movie, FILE *parch)
    {
        char auxtitulo[100], auxgenero[100], auxdescripcion[300];

        movie.estado = 1;

        printf("\nIngrese el titulo de la pelicula (maximo 20 caracteres): ");
        fflush(stdin);
        gets(auxtitulo);
        val_tam(auxtitulo,21);
        strcpy(movie.titulo,auxtitulo);

        printf("\nIngrese el genero de la pelicula (maximo 20 caracteres): ");
        fflush(stdin);
        gets(auxgenero);
        val_tam(auxgenero,21);
        strcpy(movie.genero,auxgenero);

        printf("\nIngrese la duracion de la pelicula (en cantidad de minutos): ");
        scanf("%d",&movie.duracion);

        printf("\nIngrese la descripcion de la pelicula (hasta 150 caracteres): ");
        fflush(stdin);
        gets(auxdescripcion);
        val_tam(auxdescripcion,151);
        strcpy(movie.descripcion,auxdescripcion);

        printf("\nIngrese el puntaje de la pelicula: ");
        scanf("%f",&movie.puntaje);

        printf("\nIngrese el link de la imagen de la pelicula: ");
        fflush(stdin);
        gets(movie.linkImagen);

        fseek(parch, 0L, SEEK_END);
        fwrite(&movie, sizeof(EMovie), 1, parch);

    }

void borrarPelicula(EMovie movie, FILE *parch)
    {
        char auxtit[21];
        char rta;

        printf("\nIngrese el titulo de la pelicula a borrar: ");
        fflush(stdin);
        gets(auxtit);

        rewind(parch);
        while(!feof(parch))
        {
            fread(&movie, sizeof(EMovie), 1, parch);

            if(strcmpi(auxtit,movie.titulo)==0 && movie.estado!=0)
            {
                printf("\nLos datos encontrados son:");
                printf("\n-TITULO: %s",movie.titulo);
                printf("\n-GENERO: %s",movie.genero);
                printf("\n-DURACION: %d",movie.duracion);
                printf("\n-DESCRIPCION: %s",movie.descripcion);
                printf("\n-PUNTAJE: %.2f",movie.puntaje);
                printf("\n-LINK IMAGEN: %s",movie.linkImagen);

                printf("\nSeguro que desea borrarlos? s/n: ");
                fflush(stdin);
                rta = tolower(getche());
                val_rta(rta);

                system("pause");
                system("cls");

                if(rta=='s')
                {
                    movie.estado = 0;
                    strcpy(movie.titulo,"\0");

                    fseek(parch, (-1)*sizeof(EMovie), SEEK_CUR);
                    fwrite(&movie, sizeof(EMovie), 1, parch);

                    system("cls");

                    printf("\nLos datos han sido borrados.");
                    system("pause");
                    break;
                }
                else
                {
                    printf("\nLos datos no han sido borrados.");
                    system("pause");
                    break;
                }
            }
            else
            {
                printf("\nNo se encontro la pelicula");
                system("pause");
                system("cls");
                break;
            }
        }
    }

void modificarPelicula(EMovie movie, FILE *parch)
    {
        char auxtit[21];
        char rta;

        printf("\nIngrese el titulo de la pelicula a modificar: ");
        fflush(stdin);
        gets(auxtit);

        rewind(parch);
        while(!feof(parch))
        {
            fread(&movie, sizeof(EMovie), 1, parch);

            if(strcmpi(auxtit,movie.titulo)==0)
            {
                printf("\nLos datos encontrados son:");
                printf("\n-TITULO: %s",movie.titulo);
                printf("\n-GENERO: %s",movie.genero);
                printf("\n-DURACION: %d",movie.duracion);
                printf("\n-DESCRIPCION: %s",movie.descripcion);
                printf("\n-PUNTAJE: %.2f",movie.puntaje);
                printf("\n-LINK IMAGEN: %s",movie.linkImagen);

                printf("\nSeguro que desea modificarlos? s/n: ");
                fflush(stdin);
                rta = tolower(getche());
                val_rta(rta);

                system("pause");
                system("cls");

                if(rta=='s')
                {
                    printf("\nIngrese el nuevo titulo de la pelicula: ");
                    fflush(stdin);
                    gets(movie.titulo);

                    printf("\nIngrese el nuevo genero de la pelicula: ");
                    fflush(stdin);
                    gets(movie.genero);

                    printf("\nIngrese la nueva duracion de la pelicula (en cantidad de minutos): ");
                    scanf("%d",&movie.duracion);

                    printf("\nIngrese la nueva descripcion de la pelicula: ");
                    fflush(stdin);
                    gets(movie.descripcion);

                    printf("\nIngrese el nuevo puntaje de la pelicula: ");
                    scanf("%f",&movie.puntaje);

                    printf("\nIngrese el nuevo link de la imagen de la pelicula: ");
                    fflush(stdin);
                    gets(movie.linkImagen);

                    fseek(parch, (-1)*sizeof(EMovie), SEEK_CUR);
                    fwrite(&movie, sizeof(EMovie), 1, parch);

                    system("cls");

                    printf("\nLos datos han sido modificados.");
                    system("pause");
                    break;
                }
                else
                {
                    printf("\nLos datos no han sido modificados.");
                    system("pause");
                    break;
                }
            }
            else
            {
                printf("\nNo se encontro la pelicula");
                system("pause");
                system("cls");
                break;
            }
        }
    }

int generarPagina()
    {
        FILE *parch;

        int i;
        char bloque1[]="Bloque del pie  de html: <!DOCTYPE html><html><head><title>Example</title></head><body>";
        char bloque2[2048];
        char bloque3[]="Bloque del pie  de html: </html></body>";

        parch = fopen("archivo.html", "w");

        fprintf(parch, "%s\n", bloque1);

        for(i=0; i<5; i++)
        {
            fprintf(parch, "%s %d\n", "bloque de cuerpo", i+1);
        }

        fprintf(parch, "%s", bloque3);

        fclose(parch);

        return 0;
    }

void val_tam(char x[], int tam)
    {
        while(strlen(x)>tam-1)
        {
            printf("\nERROR. Reingrese una cadena que no supere los %d caracteres: ",tam-1);
            fflush(stdin);
            gets(x);
        }
    }

void val_rta(char respuesta)
    {
        while(respuesta!='s' && respuesta!='n')
        {
            printf("\nERROR, ingrese una opcion correcta (s/n): ");
            fflush(stdin);
            respuesta = tolower(getche());
        }
    }

