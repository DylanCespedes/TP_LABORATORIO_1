#include <stdio.h>
#include <stdlib.h>

#include "ArrayPasajeros.h"
#include "Generic_Functions.h"

int main(void)
{
	setbuf(stdout,NULL);

	int IdIncremental = 0;
	//int idIncrementalTipo = 0;
	int seguir;
	int continuar;
	int ControlFlag = 0;
	int* pFlag = &ControlFlag;

	ePassenger listaPasajeros[P];
	eTipoPasajero listaTipo[2];

	initPassengers(listaPasajeros, P);
	InicializarTipoPasajero(listaTipo, 2);

	HarcodearPassenger(listaPasajeros, &IdIncremental, 4, pFlag);
	HarcodearTipoPasajero(listaTipo, 2, pFlag);

	do
		{
			system("cls");
			printf("#### Menu de Pasajeros ###");
			printf("\n\n1-Ingresar pasajeros.\n");
			printf("2-Modificar pasajeros.\n");
			printf("3-Eliminar pasajeros.\n");
			printf("4-Informar.\n");
			printf("5-Salir.\n");
			fflush(stdin);
			seguir = GetIntRange("\nIngrese una opcion ", "\nUsted ha ingresado una opcion invalida, reingrese ", 1, 5);

			switch(seguir)
			{
				case 1:

					IdIncremental++;
					addOnePassenger(listaPasajeros, P,IdIncremental, listaTipo, 2);
					ControlFlag = 1;

				    	break;

				case 2:

					if(ControlFlag != 0)
					{
						ModifyPasajero(listaPasajeros, P, listaTipo, 2);
						system("cls");
					}
					else
					{
						printf("\nTiene que haber almenos un pasajero registrado para poder acceder a esta opcion.\n\n");
						system("pause");
						system("cls");
					}
				    	break;

				case 3:

					if(ControlFlag != 0)
					{
						system("cls");
						DeletePasseger(listaPasajeros, P, listaTipo, 2);
						system("cls");
					}
					else
					{
						printf("\nTiene que haber almenos un pasajero cargado para poder acceder a esta opcion.\n\n");
						system("pause");
						system("cls");
					}
				    	break;

				case 4:

				if(ControlFlag != 0)
				{
					continuar = MenuPasseger(listaPasajeros, P, listaTipo, 2);

					if(continuar == -1)
					{
						printf("\nSera redireccionado al menu principal\n\n");
						system("pause");
						system("cls");
					}
				}
				else
				{
					printf("\nTiene que haber almenos un pasajero cargado para poder acceder a esta opcion.\n\n");
					system("pause");
					system("cls");
				}
			    	break;

				case 5:
					system("cls");

		            break;
			}
		}while(seguir != 5);
}
