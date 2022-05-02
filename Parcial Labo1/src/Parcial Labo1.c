/*
 ============================================================================

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "ArrayAlbum.h"

int main(void) {

	setbuf(stdout,NULL);

	int IdIncrementalAlbum = 100;
	int idIncrementalArtista = 3000;
	int idIncrementalGenero = 2000;
	int idIncrementalTipo = 1;
	int seguir;
	int continuar;
	int ControlFlag = 0;

	eArtista listaArtista[TAMA];
	eGenero listaGenero[TAMA];
	eTipoArtista listaTipo[2];
	eAlbum listaAlbum[TAMA];

	HardcodearTipoArtista(listaTipo, idIncrementalTipo, 2);
	HardcodearGenero(listaGenero, idIncrementalGenero, TAMA);
	HardcodearArtista(listaArtista, idIncrementalArtista, TAMA);
	InicializarAlbumes(listaAlbum, TAMA);

	do
		{
			printf("#### Menu de Albumes ###");
			printf("\n\n1-Ingresar album.\n");
			printf("2-Modificar Album.\n");
			printf("3-Baja Album.\n");
			printf("4-Listado de Albumes ingresados.\n");
			printf("5-Salir.\n");
			seguir = GetIntRange("\nIngrese una opcion: ", "Usted ha ingresado una opcion invalida: \n", 1, 5);

			switch(seguir)
			{
				case 1:

					IdIncrementalAlbum++;
					AddOneAlbum(listaAlbum, T, IdIncrementalAlbum);
					ControlFlag = 1;

					break;

				case 2:

					if(ControlFlag != 0)
					{
						printf("\n\nListado de albumes encontrados\n");
						printf("\n%5s %10s %12s %9s", "Codigo", "Titulo", "Fecha", "Importe\n");
						ModifyAlbum(listaAlbum, IdIncrementalAlbum, idIncrementalGenero, idIncrementalTipo, idIncrementalArtista, T);
						system("cls");
					}

					else
						{
							printf("\nTiene que haber almenos un album cargado para poder acceder a esta opcion.\n\n");
							system("cls");
						}

					break;

				case 3:

					if(ControlFlag != 0)
					{
						printf("\n\nListado de albumes encontrados\n");
						printf("\n%5s %10s %12s %9s", "Codigo", "Titulo", "Fecha", "Importe\n");
						DeleteAlbum(listaAlbum, idIncrementalArtista, T);
						idIncrementalArtista--;
						system("cls");
					}
					else
					{
						printf("\nTiene que haber almenos un album cargado para poder acceder a esta opcion.\n\n");
						system("cls");
					}

					break;

				//case 4:

				if((ControlFlag != 0))
					{
						continuar = MenuEmployee(ListaEmpleados, E);

						if(continuar == -1)
						{
							printf("Sera redireccionado al menu principal\n\n");
							system("cls");
						}
					}
					else
					{
						printf("\nTiene que haber almenos un empleado cargado para poder acceder a esta opcion.\n\n");
						system("cls");
					}

					break;

			}

		}while(seguir != 5);

	}



