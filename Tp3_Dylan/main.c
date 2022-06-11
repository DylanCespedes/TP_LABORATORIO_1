/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "Generic_Functions.h"


int main()
{
	setbuf(stdout,NULL);

	int seguir;

	int flag = 0;

	LinkedList* listaPasajeros = ll_newLinkedList();

	do{
		printf("//// Sistema de administracion de pasajeros. ////\n");
		printf("1) Cargar datos desde el archivo data.csv(Modo texto).\n");
		printf("2) Cargar datos desde el archivo data.csv(Modo binario).\n");
		printf("3) Alta de pasajero.\n");
		printf("4) Modificar datos del pasajero.\n");
		printf("5) Baja de pasajero.\n");
		printf("6) Listado de los pasajeros.\n");
		printf("7) Ordenar lista de pasajeros.\n");
		printf("8) Guardar datos desde el archivo data.csv(Modo texto).\n");
		printf("9) Guardar datos desde el archivo data.csv(Modo binario).\n");
		printf("10) Salir.\n");
		fflush(stdin);

		seguir = Get_IntRange("\nIngrese una opcion: ", "\nUsted ingresastes la opcion incorrecta. Vuelve a intentarlo: ", 1, 10);

		switch(seguir){

			case 1:

				 flag = controller_loadFromText("data.csv", listaPasajeros);
				  if(flag == 1)
				  {
				    printf("*************************************\n");
				    printf("\nArchivo cargado con exito!!!\n");
				    system("pause");
				    system("cls");
				  }
				   else
				    {
					   printf("\nArchivo no encontrado\n");
					   system("pause");
					   system("cls");
				    }
			break;

			case 2:

			flag = controller_loadFromBinary("data.dat", listaPasajeros);

			if(flag == 1)
			{
				printf("\nArchivo cargado con exito!!!\n");
				system("pause");
				system("cls");
			}
			else
			{
				 printf("\nArchivo no encontrado\n");
				 system("pause");
				 system("cls");
			}

				break;

			case 3:
					controller_addPassenger(listaPasajeros);
					system("pause");
					system("cls");
				break;

			case 4:
					controller_editPassenger(listaPasajeros);
					system("pause");
				    system("cls");
				break;

			case 5:
					controller_removePassenger(listaPasajeros);
					system("pause");
					system("cls");
				break;

			case 6:
					controller_ListPassenger(listaPasajeros);
					system("pause");
					system("cls");
				break;

			case 7:
					controller_sortPassenger(listaPasajeros);
					system("pause");
					system("cls");
				break;

			case 8:
					controller_saveAsText("data.csv", listaPasajeros);

					if(flag == 1)
				    {
						printf("\nArchivo guardado con exito!!!\n");
						system("pause");
						system("cls");
					}
					else
					{
					    printf("\nNo se pudo guardar\n");
					    system("pause");
					    system("cls");
					}
				break;

			case 9:
				flag = controller_saveAsBinary("data.csv", listaPasajeros);
				if(flag == 1)
				{
					printf("\nArchivo guardado con exito!!!\n");
					system("pause");
					system("cls");
				}
				else
				{
					printf("\nNo se pudo guardar\n");
					system("pause");
				    system("cls");
				}
				break;

			case 10:
				system("cls");

				break;

		}

	}while(seguir != 10);

    return 0;
}

