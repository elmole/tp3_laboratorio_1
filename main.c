#include "func.h"

int main()
    {
        FILE *parch;
        EMovie movie;
        char seguir='s';
        int opcion=0;

        system("color 6F");

        parch = fopen("datos.dat","rb+");
        if(parch==NULL)
        {
            parch = fopen("datos.dat", "wb+");

            if(parch==NULL)
            {
                printf("\nNo se pudo crear el registro");
                exit(1);
            }
        }

        while(seguir=='s')
        {
            opcion = menu();

            system("cls");

            switch(opcion)
            {
                case 1:
                    agregarPelicula(movie, parch);
                    system("cls");
                    break;
                case 2:
                    borrarPelicula(movie, parch);
                    system("cls");
                    break;
                case 3:
                    modificarPelicula(movie, parch);
                    system("cls");
                    break;
                case 4:
                    generarPagina();
                    break;
                case 5:
                    seguir = 'n';
                    break;
                default:
                    printf("\nINGRESE UNA OPCION CORRECTA");
            }
        }

        return 0;
    }
