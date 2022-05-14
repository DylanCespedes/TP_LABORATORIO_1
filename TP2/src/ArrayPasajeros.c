#include "ArrayPasajeros.h"
#include "Generic_Functions.h"

void initPassengers(ePassenger listaPasajeros[], int tam)
{
	int i;

	for(i=0; i<tam; i++)
	{
		listaPasajeros[i].isEmpty = TRUE;
	}
}

void HarcodearPassenger(ePassenger listaPasajeros[], int *idIncrementaPasajeros, int tam, int *pFlag)
{
	char Nombre[][TAMA] = {"Jose", "Pablo", "Mauricio", "Lalo"};
	char Apellido[][TAMA] = {"Ramirez", "Castillos", "Santos", "Landa"};
	float precio[] = {250,300,400,350};
	char codVuelo[][TAMA] = {"PJT1","PJT2","P34J","P2N3"};
	int tipoPasajero[] = {100,101,100,101};
	int status[] = {1,1,0,2};

	for(int i=0; i<tam; i++)
	{
	    if(listaPasajeros[i].isEmpty == TRUE && idIncrementaPasajeros != NULL)
	    {
	    	listaPasajeros[i].id = eGen_ObtenerID(*idIncrementaPasajeros);
		    strcpy(listaPasajeros[i].name, Nombre[i]);
		    strcpy(listaPasajeros[i].lastName, Apellido[i]);
		    listaPasajeros[i].price = precio[i];
		    strcpy(listaPasajeros[i].flyCode, codVuelo[i]);
		    listaPasajeros[i].typePassenger = tipoPasajero[i];
		    listaPasajeros[i].statusFlight = status[i];
		    listaPasajeros[i].isEmpty = FALSE;
	    	*idIncrementaPasajeros = listaPasajeros[i].id;
	    }
	}

	*pFlag = 1;
}

int FindFreeIndex(ePassenger listaPasajeros[], int tam)
{
	int i;
	int index = -1;

	for(i=0; i<tam; i++)
	{
		if(listaPasajeros[i].isEmpty == TRUE)
		{
			index = i;
			break;
		}
	}
	return index;
}

int FindPassengerById(ePassenger listaPasajeros[], int tam, int datoId)
{
	int i;
	int index = -1;

	for(i=0; i<tam; i++)
	{
		if(listaPasajeros[i].id == datoId)
		{
			index = i;
			break;
		}
	}
	return index;
}

void addOnePassenger(ePassenger listaPasajeros[], int tam, int IdIncrementalPassenger, eTipoPasajero listaTipo[], int tamTipo)
{
	int i;
	i = FindFreeIndex(listaPasajeros, tam);

	if(i != -1)
	{
		listaPasajeros[i] = AddPassenger(IdIncrementalPassenger, listaTipo, tamTipo);
		if(listaPasajeros[i].isEmpty == FALSE)
		{
			printf("\nDatos cargados con exito!!\n\n");
			system("pause");
			system("cls");
		}
	}
	else
	{
		 printf("\nNo hay espacio para la carga de datos\n\n");
		 system("pause");
		 system("cls");
	}
}

void InicializarTipoPasajero(eTipoPasajero listaTipo[], int tam)
{
	int i;

	for(i=0; i<tam; i++)
	{
		listaTipo[i].isEmpty = TRUE;
	}
}

void HarcodearTipoPasajero(eTipoPasajero listaTipo[], int tam, int *pFlag)
{
	char descripcion[][50] = {"Argentino", "Extranjero"};
	char IdTipo[] = {100, 101};

	for(int i=0; i<tam; i++)
	{
	    if(listaTipo[i].isEmpty == TRUE)
	    {
	    	listaTipo[i].idTipo = IdTipo[i];
		    strcpy(listaTipo[i].descripcion, descripcion[i]);
		    listaTipo[i].isEmpty = FALSE;

	    }
	}

	*pFlag = 1;
}

void PrintTipoPasajero(eTipoPasajero listaTipo[], int tam)
{
	for(int i=0; i<tam; i++)
		{
			if(listaTipo[i].isEmpty == FALSE)
				{
					PrintOneTipoPasajero(listaTipo[i]);
				}
		}
}

void PrintOneTipoPasajero(eTipoPasajero listaTipo)
{
	if(listaTipo.isEmpty == FALSE)
	{
		printf("\n*%4d %9s\n", listaTipo.idTipo,
						   listaTipo.descripcion);
	}
}

int buscarTipoPassenger(eTipoPasajero listaTipo[], int tam, int id, int* pIndex)
{
    int todoOk = 0;
    if( listaTipo != NULL && pIndex != NULL && tam > 0 )
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if( !listaTipo[i].isEmpty  && listaTipo[i].idTipo == id)
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}


ePassenger AddPassenger(int IdIncrementalPassenger, eTipoPasajero listaTipos[], int tamTipo)
{
	ePassenger AddedPassenger;
	int auxTipo;
	int auxIndex;

	Get_OnlyAlphabetStringWithSpaces("\nIngrese el nombre del pasajero: ", "Ingrese el nombre nuevamente(solo caracteres alfabeticos): ", AddedPassenger.name, TAMA);
	Get_OnlyAlphabetStringWithSpaces("\nIngrese el apellido del pasajero: ", "Ingrese el apellido nuevamente(solo caracteres alfabeticos): ", AddedPassenger.lastName, TAMA);
	AddedPassenger.price = GetFloat("\nIngrese el precio del vuelo: ", "Ingrese el precio del vuelo nuevamente (solo caracteres numericos positivos): ");
	GetStrings("\nIngrese el codigo de vuelo: ", AddedPassenger.flyCode, TAMA);

	PrintTipoPasajero(listaTipos, tamTipo);
	auxTipo = GetInt("\nIngrese el codigo del tipo de pasajero: ", "Ingrese el codigo de nuevamente (solo caracteres numericos enteros): ");
	while(!buscarTipoPassenger (listaTipos, tamTipo, auxTipo, &auxIndex))
	{
		printf("/nERROR!!! No se encontro el ID ingresado.");
		PrintTipoPasajero(listaTipos, tamTipo);
		auxTipo = GetInt("\nIngrese el codigo del tipo de pasajero: ", "Ingrese el codigo de nuevamente (solo caracteres numericos enteros): ");

	}
	AddedPassenger.typePassenger = auxTipo;
	AddedPassenger.statusFlight = GetIntRange("\nIngrese el estado de vuelo(0 = Cancelado // 1 = Activo // 2 = Demorado): ", "Ingrese el estado del vuelo nuevamente (0 = Cancelado // 1 = Activo // 2 = Demorado): ", -1, 2);
	AddedPassenger.id = IdIncrementalPassenger;
	AddedPassenger.isEmpty = FALSE;

	return AddedPassenger;

}

void PrintPasajero(ePassenger listaPasajeros[], int tam, eTipoPasajero listaTipos[], int tamTipo)
{
	for(int i=0; i<tam; i++)
		{
			for(int j=0; j<tamTipo; j++)
			{
				if(listaPasajeros[i].isEmpty == FALSE && listaPasajeros[i].typePassenger == listaTipos[j].idTipo)
					{
						PrintOnePasajeroTipo(listaPasajeros[i], listaTipos[j]);
					}
			}
		}
}

void PrintOnePasajeroTipo(ePassenger unPasajero, eTipoPasajero unTipo)
{
	char auxStatus[TAMA];

	if(unPasajero.statusFlight == 0)
		strcpy(auxStatus, "Cancelado");

	else if(unPasajero.statusFlight == 1)
		strcpy(auxStatus, "Activo");
	else
		strcpy(auxStatus, "Demorado");

	if(unPasajero.isEmpty == FALSE)
	{
		printf("\n*%2d %12s %12s %12.2f %12s %17s %12s\n\n", unPasajero.id,
															 unPasajero.name,
															 unPasajero.lastName,
															 unPasajero.price,
															 unPasajero.flyCode,
															 unTipo.descripcion,
															 auxStatus);
	}
}

void PrintOnePasajero(ePassenger unPasajero)
{
	char auxStatus[TAMA];

		if(unPasajero.statusFlight == 0)
			strcpy(auxStatus, "Cancelado");

		else if(unPasajero.statusFlight == 1)
			strcpy(auxStatus, "Activo");
		else
			strcpy(auxStatus, "Demorado");

	printf("\n*%2d %12s %12s %12.2f %13s %13d %12s\n\n", unPasajero.id,
														 unPasajero.name,
														 unPasajero.lastName,
														 unPasajero.price,
														 unPasajero.flyCode,
														 unPasajero.typePassenger,
														 auxStatus);
}

int buscarPassenger(ePassenger listaPasajeros[], int tam, int id, int* pIndex)
{
    int todoOk = 0;
    if( listaPasajeros != NULL && pIndex != NULL && tam > 0 )
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if( !listaPasajeros[i].isEmpty  && listaPasajeros[i].id == id)
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}


void ModifyPasajero(ePassenger listaPasajeros[], int tam, eTipoPasajero listaTipo[], int tamTipo)
{
	int indexPasajero;
	int auxTipoId;
	int indexTipo;
	int idIngresada;
	char auxNombre[TAMA];
	char auxApellido[TAMA];
	char auxCod[TAMA];
	float auxPrecio;
	int opcion;
	char seguir;

		system("cls");
		printf("\n\n### Pasajeros encontrados ###\n");
		printf("\n%5s %9s %13s %11s %17s %9s %16s","Codigo", "Nombre", "Apellido", "Precio", "Codigo vuelo", "Tipo", "Estado\n");
		PrintPasajero(listaPasajeros, tam, listaTipo, tamTipo);
		idIngresada = GetInt("\nIngrese el codigo del tipo de pasajero: ", "Ingrese el codigo de nuevamente (solo caracteres numericos enteros): ");
		while(!buscarPassenger(listaPasajeros, tam, idIngresada, &indexPasajero))
			{
				printf("/nERROR!!! No se encontro el ID ingresado.");
				PrintPasajero(listaPasajeros, tam, listaTipo, tamTipo);
				idIngresada = GetInt("\nIngrese el codigo del tipo de pasajero: ", "Ingrese el codigo de nuevamente (solo caracteres numericos enteros): ");
			}

		if(indexPasajero != -1)
		{
		  system("cls");
		  printf("\n%5s %9s %13s %11s %17s %9s %13s","Codigo", "Nombre", "Apellido", "Precio", "Codigo vuelo", "Tipo", "Estado\n");
		  PrintOnePasajero(listaPasajeros[indexPasajero]);
		  opcion = GetIntRange("\nSe ha encontrado la Id ingresada !!\n\nQue desea modificar? \n\n1-Nombre\n\n2-Apellido\n\n3-Precio\n\n4-Tipo Pasajero\n\n5-Codigo\n\n6-Salir\n\nIngrese una opcion: ", "Usted ha ingresado una opcion incorrecta, reingrese: ", 1, 6);

			switch(opcion)
			{
				case 1:

					Get_OnlyAlphabetStringWithSpaces("Ingrese el nuevo nombre: ", "Error, reingrese el nuevo nombre: ", auxNombre, TAMA);
					seguir = getChar("\nEsta seguro de querer continuar? Ingrese 's' para continuar o 'n' para cancelar: ", "Error, reingrese 's' para continuar o 'n' para cancelar la modificacion: ");

					if(seguir == 's')
						{
							strcpy(listaPasajeros[indexPasajero].name, auxNombre);
							printf("\nNombre modificado con exito!!\n");
							system("pause");
							system("cls");
						}
						else
							{
								printf("\nSe ha cancelado la modificacion del Nombre\n");
								system("pause");
								system("cls");
							}
					break;

				case 2:

					Get_OnlyAlphabetStringWithSpaces("Ingrese el nuevo apellido: ", "Error, reingrese el nuevo apellido: ", auxApellido, TAMA);
					seguir = getChar("\nEsta seguro de querer continuar? Ingrese 's' para continuar o 'n' para cancelar: ", "Error, reingrese 's' para continuar o 'n' para cancelar la modificacion: ");

					if(seguir == 's')
					{
						strcpy(listaPasajeros[indexPasajero].lastName, auxApellido);
						printf("\nApellido modificado con exito!!\n");
						system("pause");
						system("cls");
					}
					else
					{
						printf("\nSe ha cancelado la modificacion del Apellido\n");
						system("pause");
						system("cls");
					}

					break;

				case 3:

					auxPrecio = GetFloat("Ingrese el nuevo precio: ", "Ingrese el precio nuevamente (solo caracteres numericos positivos): ");
					seguir = getChar("\nEsta seguro de querer continuar? Ingrese 's' para continuar o 'n' para cancelar: ", "Ingrese 's' para continuar o 'n' para cancelar la modificacion: ");

					   if(seguir == 's')
						{
							listaPasajeros[indexPasajero].price = auxPrecio;
							printf("\nSe ha modificado el precio con exito!!\n");
							system("pause");
							system("cls");
						}
						else
						{
							printf("\nSe ha cancelado la modificacion del precio\n");
							system("pause");
							system("cls");
						}
					break;

				case 4:
						printf("Listado de tipos de pasajeros\n");
						PrintTipoPasajero(listaTipo, tamTipo);
						auxTipoId = GetInt("\nIngrese el codigo del tipo de pasajero: ", "Ingrese el codigo de nuevamente (solo caracteres numericos enteros): ");
						while(!buscarTipoPassenger(listaTipo, tamTipo, auxTipoId, &indexTipo))
						{
							printf("/nERROR!!! No se encontro el ID ingresado.");
							PrintTipoPasajero(listaTipo, tamTipo);
							auxTipoId = GetInt("\nIngrese el codigo del tipo de pasajero: ", "Ingrese el codigo de nuevamente (solo caracteres numericos enteros): ");

						}
						seguir = getChar("\nEsta seguro de querer continuar? Ingrese 's' para continuar o 'n' para cancelar: ", "Ingrese 's' para continuar o 'n' para cancelar la modificacion: ");

						 if(seguir == 's')
						{
							listaPasajeros[indexPasajero].typePassenger = auxTipoId;
							printf("\nSe ha modificado el tipo de pasajero con exito!!\n");
							system("pause");
							system("cls");
						}
						else
						{
							printf("\nSe ha cancelado la modificacion del tipo de pasajero\n");
							system("pause");
							system("cls");
						}

					break;

				case 5:
					GetStrings("\nIngrese el codigo de vuelo: ", auxCod, TAMA);
					seguir = getChar("\nEsta seguro de querer continuar? Ingrese 's' para continuar o 'n' para cancelar: ", "Ingrese 's' para continuar o 'n' para cancelar la modificacion: ");

					if(seguir == 's')
					{
						strcpy(listaPasajeros[indexPasajero].flyCode, auxCod);
						printf("\nSe ha modificado el codigo de vuelo con exito!!\n");
						system("pause");
						system("cls");
					 }
					 else
					{
						 printf("\nSe ha cancelado la modificacion del codigo de vuelo\n");
						 system("pause");
						 system("cls");
					}

					break;

				case 6:
					 printf("\nSe ha cancelado la modificacion de pasajeros\n");
					 system("pause");
					 system("cls");
					break;
			}
		}
		else
		{
			printf("\nNo se ha encontrado la id ingresada\n");
			system("pause");
			system("cls");
		}
}

void DeletePasseger(ePassenger listaPasajeros[], int tam, eTipoPasajero listaTipo[], int tamTipo)
{
	int idEliminar;
	int indexPasajero;
	char seguir;

	system("cls");
	printf("\n\n### Pasajeros encontrados ###\n");
	printf("\n%5s %9s %13s %11s %17s %9s %16s","Codigo", "Nombre", "Apellido", "Precio", "Codigo vuelo", "Tipo", "Estado\n");
	PrintPasajero(listaPasajeros, tam, listaTipo, tamTipo);
	idEliminar = GetInt("\nIngrese el codigo del tipo de pasajero: ", "Ingrese el codigo de nuevamente (solo caracteres numericos enteros): ");

	while(!buscarPassenger(listaPasajeros, tam, idEliminar, &indexPasajero))
	{
		printf("/nERROR!!! No se encontro el ID ingresado.");
		PrintPasajero(listaPasajeros, tam, listaTipo, tamTipo);
		idEliminar = GetInt("\nIngrese el codigo del tipo de pasajero: ", "Ingrese el codigo de nuevamente (solo caracteres numericos enteros): ");
	}

	if(idEliminar != -1)
		{
			system("cls");

			printf("\n\nListado de pasajeros encontrados\n");
			printf("\n%5s %9s %13s %11s %17s %9s %13s","Codigo", "Nombre", "Apellido", "Precio", "Codigo vuelo", "Tipo", "Estado\n");
			PrintOnePasajero(listaPasajeros[indexPasajero]);
			seguir = getChar("\nSe ha encontrado la id ingresada, esta seguro de querer continuar con la baja? Ingrese s(si) o n(no): ", "\nReingrese s(si) o n(no): ");

			if(seguir == 's')
				{
					RemovePasseger(listaPasajeros, tam, indexPasajero, "\nSe ha eliminado el pasajero con exito!!!\n");
					system("pause");
				}
				else
				{
					printf("\nUsted ha cancelado la baja del pasajero\n");
					system("pause");
					system("cls");
				}
			}
}

void RemovePasseger(ePassenger listaPasajeros[], int tam, int indice, char mensaje[])
{
	for(int i=0; i<tam; i++)
	{
		if(i == indice)
		{
			printf("%s", mensaje);
			listaPasajeros[i].isEmpty = TRUE;
			break;
		}
	}
}


int MenuPasseger(ePassenger listaPasajeros[], int tam, eTipoPasajero listaTipo[], int tamTipo)
{
	float suma;
	float promedio;
	int ContadorPasajerosMaxPrecio;

	int continuar;
	int respuesta;
	do
		{
			system("cls");
			printf("#### Menu Mostrar ###");
			printf("\n\n1-Listado de los pasajeros ordenados alfabeticamente por Apellido y Tipo de pasajero.\n");
			printf("2-Total y promedio de los precios de los pasajes, y cuantos pasajeros superan el precio promedio.\n");
			printf("3-Listado de los pasajeros por Codigo de vuelo y estados de vuelos ACTIVO.\n");
			printf("4-Salir.\n");

			continuar = GetIntRange("\nIngrese una opcion: ", "Usted ha ingresado una opcion invalida: \n", 1, 4);

				switch(continuar)
					{
						case 1:
							system("cls");
							printf("1-Listado ascedente (Z-A) de pasajeros.\n");
							printf("2-Listado descendente (A-Z) de pasajeros.\n");
							printf("3-Salir.\n");

							respuesta = GetIntRange("\nIngrese una opcion: ", "Usted ha ingresado una opcion invalida: \n", 1, 3);
							switch (respuesta)
							{
								case 1:
									system("cls");
									printf("Listado ascedente de pasajeros\n");
									printf("\n%5s %9s %13s %11s %17s %9s %16s","Codigo", "Nombre", "Apellido", "Precio", "Codigo vuelo", "Tipo", "Estado\n");
									sortPassengersByCode(listaPasajeros, tam, respuesta, listaTipo, tamTipo);
									system("pause");
									system("cls");

									break;

								case 2:
									system("cls");
									printf("Listado descendente de pasajeros\n");
									printf("\n%5s %9s %13s %11s %17s %9s %16s","Codigo", "Nombre", "Apellido", "Precio", "Codigo vuelo", "Tipo", "Estado\n");
									sortPassengersByCode(listaPasajeros, tam, respuesta, listaTipo, tamTipo);
									system("pause");
									system("cls");

									break;

								default:

									printf("\nUsted ha cancelado el ordenamiento.\n");
									system("pause");
									system("cls");
							}
									break;

						case 2:
							system("cls");
							printf("Listado de pasajeros encontrados\n");
							printf("\n%5s %9s %13s %11s %17s %9s %16s","Codigo", "Nombre", "Apellido", "Precio", "Codigo vuelo", "Tipo", "Estado\n");
							PrintPasajero(listaPasajeros, tam, listaTipo, tamTipo);
							suma = SumPrices(listaPasajeros, tam);
							promedio = AveragePrice(listaPasajeros, tam);
							ContadorPasajerosMaxPrecio = ShowAveragePassenger(listaPasajeros, tam);
							printf("\n\nEl total de precio entre los pasajeros es: %.2f$\n", suma);
							printf("\nEl promedio de todos los precios de los pasajeros es: %.2f$\n", promedio);
							printf("\nLa cantidad de pasajeros que superan el precio promedio son: %d\n\n", ContadorPasajerosMaxPrecio);
							system("pause");
							system("cls");
							break;

						case 3:
							system("cls");
							printf("Listado de los pasajeros por Codigo de vuelo y estados de vuelos (ACTIVO)\n");
							printf("\n%5s %9s %13s %11s %17s %9s %16s","Codigo", "Nombre", "Apellido", "Precio", "Codigo vuelo", "Tipo", "Estado\n");
							sortPassengersByStatus(listaPasajeros, tam, listaTipo, tamTipo);
							system("pause");
							system("cls");


							break;
					}

						}while(continuar !=4);

		if(continuar == 3 || continuar > 3)
		{
			continuar = -1;
		}
		return continuar;
}


float SumPrices(ePassenger listaPasajeros[], int tam)
{
    int i;
    float AcumularSalarios = 0;

    for(i=0; i<tam; i++)
    {
        if(listaPasajeros[i].isEmpty == FALSE)
        {
        	AcumularSalarios += listaPasajeros[i].price;
        }
    }
    return AcumularSalarios;
}

float AveragePrice(ePassenger listaPasajeros[], int tam)
{
    int i;
    float PromedioPrecios = 0;

    for(i=0; i<tam; i++)
    {
        if(listaPasajeros[i].isEmpty == FALSE)
        {
        	PromedioPrecios = SumPrices(listaPasajeros, tam) / CountPassenger(listaPasajeros, tam);
        }
    }
    return PromedioPrecios;
}


int CountPassenger(ePassenger listaPasajeros[], int tam)
{
    int i;
    int ContadorPasajeros = 0;

    for(i=0; i<tam; i++)
    {
        if(listaPasajeros[i].isEmpty == FALSE)
        {
        	ContadorPasajeros++;
        }
    }
    return ContadorPasajeros;
}


int ShowAveragePassenger(ePassenger listaPasajeros[], int tam)
{
    int i;
    float Promedio;
    int pasajerosMayorSueldo = 0;
    Promedio = AveragePrice(listaPasajeros, tam);

    for(i=0; i<tam; i++)
    {
        if(listaPasajeros[i].isEmpty == FALSE && listaPasajeros[i].price > Promedio)
        {
        	pasajerosMayorSueldo++;
        }
    }
    return pasajerosMayorSueldo;
}

void sortPassengersByCode(ePassenger listaPasajeros[], int tam, int respuesta, eTipoPasajero listaTipo[], int tamTipo)
{
	ePassenger aux;
	int i;
	int j;

	for(i=0; i<tam-1; i++)
	{
		for(j=i+1; j<tam; j++)
		{
			if(respuesta == 1)
			{
				if(strcmp(listaPasajeros[i].lastName, listaPasajeros[j].lastName)<0)
				{
					aux = listaPasajeros[i];
					listaPasajeros[i] = listaPasajeros[j];
					listaPasajeros[j] = aux;

				}
				else
				{
					if((strcmp(listaPasajeros[i].lastName, listaPasajeros[j].lastName)<0) && (listaPasajeros[i].typePassenger > listaPasajeros[j].typePassenger))
						{
							{
								aux = listaPasajeros[i];
								listaPasajeros[i] = listaPasajeros[j];
								listaPasajeros[j] = aux;
							}
						}
				}
			}
			else
			{
				if(strcmp(listaPasajeros[i].lastName, listaPasajeros[j].lastName)>0)
						{
							aux = listaPasajeros[i];
							listaPasajeros[i] = listaPasajeros[j];
							listaPasajeros[j] = aux;

						}
						else
						{
							if((strcmp(listaPasajeros[i].lastName, listaPasajeros[j].lastName)>0) && (listaPasajeros[i].typePassenger > listaPasajeros[j].typePassenger))
								{
									{
										aux = listaPasajeros[i];
										listaPasajeros[i] = listaPasajeros[j];
										listaPasajeros[j] = aux;
									}
								}
						}
				}
			}
		}
	PrintPasajero(listaPasajeros, tam, listaTipo, tamTipo);
}

void sortPassengersByStatus(ePassenger listaPasajeros[], int tam, eTipoPasajero listaTipo[], int tamEstado)
{
	ePassenger aux;
	int i;
	int j;

	for(i=0; i<tam-1; i++)
		{
			for(j=i+1; j<tam; j++)
			{
				if(strcmp(listaPasajeros[i].flyCode, listaPasajeros[j].flyCode)>0)
				{
					aux = listaPasajeros[i];
					listaPasajeros[i] = listaPasajeros[j];
					listaPasajeros[j] = aux;
				}
			}
		}
	PrintPasajerosEstadoActivo(listaPasajeros, tam, listaTipo, tamEstado);
}

void PrintPasajerosEstadoActivo(ePassenger listaPasajeros[], int tam, eTipoPasajero listaTipos[], int tamTipo)
{
	for(int i=0; i<tam; i++)
		{
			for(int j=0; j<tamTipo; j++)
			{
				if(listaPasajeros[i].isEmpty == FALSE && listaPasajeros[i].typePassenger == listaTipos[j].idTipo)
					{
						if(listaPasajeros[i].statusFlight == 1)
						{
							PrintOnePasajeroTipo(listaPasajeros[i], listaTipos[j]);
						}
					}
			}
		}
}
