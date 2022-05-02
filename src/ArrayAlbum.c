#include "ArrayAlbum.h"
#include "Generic_Functions.h"

void HardcodearGenero(eGenero listaGeneros[], int idIncrementalGenero, int tam)
{
	int i;

	char Desc[][L]={"Rock", "Pop", "Euro Dance", "Rock Nacional"};

	for(i=0; i<tam; i++)
	{
		listaGeneros[i].IdGenero = eGen_ObtenerID(idIncrementalGenero);
		strcpy(listaGeneros[i].descripcionGen, Desc[i]);
		listaGeneros[i].isEmpty = FALSE;
		idIncrementalGenero++;
	}
}

void HardcodearArtista(eArtista listaArtista[], int idIncrementalArtista, int tam)
{
	int i;

	char Desc[][L]={"Freddy Mercury", "Michael Jackson", "Gustavo Cerati", "Pablo Fontaner"};

	for(i=0; i<tam; i++)
	{
		listaArtista[i].IdArtista = eGen_ObtenerID(idIncrementalArtista);
		strcpy(listaArtista[i].nombre, Desc[i]);
		listaArtista[i].isEmpty = FALSE;
		idIncrementalArtista++;
	}
}

void HardcodearTipoArtista(eTipoArtista listaTipoArtista[], int idIncrementalTipo, int tam)
{
	int i;

	char Desc[][L]={"Solista", "Banda"};

	for(i=0; i<tam; i++)
	{
		listaTipoArtista[i].IdTipo = eGen_ObtenerID(idIncrementalTipo);
		strcpy(listaTipoArtista[i].descripcionTipo, Desc[i]);
		listaTipoArtista[i].isEmpty = FALSE;
		idIncrementalTipo++;
	}
}

void InicializarAlbumes(eAlbum listaAlbum[], int tam)
{
	int i;

	for(i=0; i<tam; i++)
	{
		listaAlbum[i].IsEmpty = TRUE;
	}
}

int FindFreeIndex(eAlbum listaAlbum[], int tam)
{
	int i;
	int index = -1;

	for(i=0; i<tam; i++)
	{
		if(listaAlbum[i].IsEmpty == TRUE)
		{
			index = i;
			break;
		}
	}
	return index;
}

int FindAlbumById(eAlbum listaAlbum[], int tam, int datoId)
{
	int i;
	int index = -1;

	for(i=0; i<tam; i++)
	{
		if(listaAlbum[i].IdAlbum == datoId)
		{
			index = i;
			break;
		}
	}
	return index;
}

void RemoveAlbum(eAlbum listaAlbum[], int tam, int indice, char mensaje[])
{
	int i;

	for(i=0; i<tam; i++)
	{
		if(i == indice)
			{
				printf("%s", mensaje);
				listaAlbum[i].IsEmpty = TRUE;
				break;
			}
	}

}

void AddOneAlbum(eAlbum listaAlbum[], int tam, int IdIncrementalAlbum)
{
	int i;
	i = FindFreeIndex(listaAlbum, tam);

	if(i != -1)
	{
		listaAlbum[i] = AddAlbum(IdIncrementalAlbum);
		if(listaAlbum[i].IsEmpty == FALSE)
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

void PrintAlbum(eAlbum listaAlbum[], int tam)
{
	int i;
	for(i=0; i<tam; i++)
		{
			if(listaAlbum[i].IsEmpty == FALSE)
				{
					printf("\n*%4d %9s %11s %10f$\n", listaAlbum[i].IdAlbum,
													  listaAlbum[i].titulo,
													  listaAlbum[i].fecha,
													  listaAlbum[i].importe);
				}
		}
}

eAlbum AddAlbum(int IdIncrementalAlbum)
{
	eAlbum addAlbum;

	char dia[T];
	char mes[T];
	char anio[T];
	char fecha[T];

	Get_OnlyAlphabetStringWithSpaces("\nIngrese el titulo del album: ", "Ingrese el titulo nuevamente(solo caracteres alfabeticos): ", addAlbum.titulo, T);
	GetDate("\nIngrese el dia de publicacion del album: ", "Reingrese el dia (solo caracteres numericos): ", dia, 0, 31);
	GetDate("\nIngrese el mes de publicacion del album: ", "Reingrese el mes (solo caracteres numericos): ", mes, 0, 12);
	GetDate("\nIngrese el anio de publicacion del album: ", "Reingrese el anio (solo caracteres numericos): ", anio, 1900, 2022);
	ToDate(dia, mes, anio, fecha);
	strcpy(addAlbum.fecha, fecha);



	addAlbum.importe = GetFloat("\nIngrese el importe del album: ", "Error, Reingrese el importe nuevamente (solo caracteres numericos positivos): ");
	addAlbum.IdAlbum = IdIncrementalAlbum;
	addAlbum.IsEmpty = FALSE;

	return addAlbum;

}


void ModifyAlbum(eAlbum listaAlbum[], int idMinimaAlbum, int idMinimaGenero, int idMinimaTipo, int idMinimaArtista, int tam)
{
	int indexAlbum;
	int idIngresada;
	char auxTitulo[T];
	char auxFecha[T];
	char dia[T];
	char mes[T];
	char anio[T];
	float auxImporte;
	//int auxSector;
	int opcion;
	int maxId;
	char seguir;

		PrintAlbum(listaAlbum, tam);

		idIngresada = GetInt("\n\nIngrese el id a la cual le desea modificar datos: ", "\nReingrese el id: ");
		indexAlbum = FindAlbumById(listaAlbum, tam, idIngresada);

		if(indexAlbum != -1)
		{
		  maxId = BuscarIdMaxima(listaAlbum, tam);
		  opcion = GetIntRange("\n\nSe ha encontrado la Id ingresada !!\nQue desea modificar? \n\n1-Titulo\n\n2-Fecha\n\n3-Importe\n\nIngrese una opcion: ", "Usted ha ingresado una opcion incorrecta, reingrese: ", idMinimaAlbum, maxId);

			switch(opcion)
			{
				case 1:

					Get_OnlyAlphabetStringWithSpaces("Ingrese el nuevo titulo: ", "Error, reingrese el nuevo titulo: ", auxTitulo, T);
					seguir = getChar("\nEsta seguro de querer continuar? Ingrese 's' para continuar o 'n' para cancelar: ", "Ingrese 's' para continuar o 'n' para cancelar la modificacion: ");

					if(seguir == 's')
						{
							strcpy(listaAlbum[indexAlbum].titulo, auxTitulo);
							printf("\nTitulo modificado con exito!!\n");
							system("pause");
							system("cls");
						}
						else
							{
								printf("\nSe ha cancelado la modificacion del titulo\n");
								system("pause");
								system("cls");
							}
					break;

				case 2:

					GetDate("\nIngrese el dia de publicacion del album: ", "Reingrese el dia (solo caracteres numericos): ", dia, 0, 31);
					GetDate("\nIngrese el mes de publicacion del album: ", "Reingrese el mes (solo caracteres numericos): ", mes, 0, 12);
					GetDate("\nIngrese el anio de publicacion del album: ", "Reingrese el anio (solo caracteres numericos): ", anio, 1900, 2022);
					ToDate(dia, mes, anio, auxFecha);
					strcpy(listaAlbum[indexAlbum].fecha, auxFecha);
					seguir = getChar("\nEsta seguro de querer continuar? Ingrese 's' para continuar o 'n' para cancelar: ", "Ingrese 's' para continuar o 'n' para cancelar la modificacion: ");

						if(seguir == 's')
							{
								ToDate(dia, mes, anio, auxFecha);
								strcpy(listaAlbum[indexAlbum].fecha, auxFecha);
								printf("\nSe ha modificado la fecha con exito!!\n");
								system("pause");
								system("cls");
							}
							else
							{
								printf("\nSe ha cancelado la modificacion de la fecha\n");
								system("pause");
								system("cls");
							}
					break;

				case 3:

					auxImporte = GetFloat("Ingrese el importe del empleado: ", "Ingrese el importe nuevamente (solo caracteres numericos positivos): ");
					seguir = getChar("\nEsta seguro de querer continuar? Ingrese 's' para continuar o 'n' para cancelar: ", "Ingrese 's' para continuar o 'n' para cancelar la modificacion: ");

					   if(seguir == 's')
						{
							listaAlbum[indexAlbum].importe = auxImporte;
							printf("\nSe ha modificado el importe con exito!!\n");
							system("pause");
							system("cls");
						}
							else
								{
									printf("\nSe ha cancelado la modificacion del salario\n");
									system("pause");
									system("cls");
								}
					break;
			}
		}
				/*case 4:

					auxSector = GetInt("Ingrese el sector al que corresponda el empleado: ", "Ingrese el sector nuevamente (solo caracteres numericos enteros): ");
					seguir = getChar("\nEsta seguro de querer continuar? Ingrese 's' para continuar o 'n' para cancelar: ", "Ingrese 's' para continuar o 'n' para cancelar la modificacion: ");

					   if(seguir == 's')
						{
							listaEmployee[indexEmployee].Sector = auxSector;
							printf("\nSector modificado con exito!!\n");
						}
							else
								{
									printf("\nSe ha cancelado la modificacion del sector\n");
									system("pause");
									system("cls");
								}
					break;
			}
		}
		else
			{
				printf("\nNo se ha encontrado la id ingresada\n");
				system("pause");
				system("cls");
			}*/
}

void DeleteAlbum(eAlbum listaAlbum[], int idMinimaAlbum, int tam)
{
	int idEliminar;
	int index;
	int idMax;
	char seguir;

	PrintAlbum(listaAlbum, tam);

	idMax = BuscarIdMaxima(listaAlbum, tam);

	idEliminar = GetIntRange("\n\nIngrese la id la cual desea eliminar: ", "\nReingrese id (solo ids pertenecientes a la lista): ", idMinimaAlbum, idMax);
	index = FindAlbumById(listaAlbum, tam, idEliminar);
	//printf("%d", index);

		if(index != -1)
			{
				seguir = getChar("\nSe ha encontrado la id ingresada, esta seguro de querer continuar? Ingrese s(si) o n(no): ", "\nReingrese s(si) o n(no): ");

				if(seguir == 's')
					{
						RemoveAlbum(listaAlbum, tam, index, "\nSe ha eliminado el album con exito!!!\n");
					}
					else
					{
						printf("\nUsted ha cancelado la baja del album\n");
						system("pause");
						system("cls");
					}
			}
			else
			{
				printf("\nNo se ha encontrado la id ingresada\n");
				system("pause");
				system("cls");
			}
}

/*
void OrderEmployees_Salary_Sector(eEmployee listaEmployee[], int tamEmployee, int respuesta)
{
	eEmployee aux;
	int i;
	int j;

	for(i=0; i<tamEmployee-1; i++)
	{
		for(j=i+1; j<tamEmployee; j++)
		{
			if(respuesta == 1)
			{
				if(strcmp(listaEmployee[i].lastName, listaEmployee[j].lastName)<0)
				{
					aux = listaEmployee[i];
					listaEmployee[i] = listaEmployee[j];
					listaEmployee[j] = aux;

				}
				else
				{
					if((strcmp(listaEmployee[i].lastName, listaEmployee[j].lastName)<0) && (listaEmployee[i].Sector > listaEmployee[j].Sector))
						{
							{
								aux = listaEmployee[i];
								listaEmployee[i] = listaEmployee[j];
								listaEmployee[j] = aux;
							}
						}
				}
			}
			else
			{
				if(strcmp(listaEmployee[i].lastName, listaEmployee[j].lastName)>0)
						{
							aux = listaEmployee[i];
							listaEmployee[i] = listaEmployee[j];
							listaEmployee[j] = aux;

						}
						else
						{
							if((strcmp(listaEmployee[i].lastName, listaEmployee[j].lastName)>0) && (listaEmployee[i].Sector > listaEmployee[j].Sector))
								{
									{
										aux = listaEmployee[i];
										listaEmployee[i] = listaEmployee[j];
										listaEmployee[j] = aux;
									}
								}
						}
			}
		}
	}
	PrintEmployees(listaEmployee, tamEmployee);
}

int MenuEmployee(eEmployee listaEmployee[], int tamEmployee)
{
	float suma;
	float promedio;
	int ContadorEmpleadosMaxSalario;

	int continuar;
	int respuesta;
	do
		{
			printf("\n#### Menu Mostrar ###");
			printf("\n\n1-Listado de los empleados ordenados alfabeticamente por Apellido y Sector.\n");
			printf("2-Total y promedio de los salarios (empleados que superan el salario promedio).\n");
			printf("3-Salir.\n");
			continuar = GetIntRange("\nIngrese una opcion: ", "Usted ha ingresado una opcion invalida: \n", 1, 3);

				switch(continuar)
					{
						case 1:
							printf("\n\n1-Listado ascedente (Z-A) de empleados.\n");
							printf("2-Listado descendente (A-Z) de emlpeados.\n");
							printf("3-Salir.\n");

							respuesta = GetIntRange("\nIngrese una opcion: ", "Usted ha ingresado una opcion invalida: \n", 1, 3);
							switch (respuesta)
							{
								case 1:

									printf("\n\nListado ascedente de empleados\n");
									printf("\n%5s %10s %12s %9s %10s", "Id", "Nombre", "Apellido", "Salario", "Sector\n");
									OrderEmployees_Salary_Sector(listaEmployee, tamEmployee, respuesta);
									system("pause");
									system("cls");

									break;

								case 2:

									printf("\n\nListado descendente de emlpeados\n");
									printf("\n%5s %10s %12s %9s %10s", "Id", "Nombre", "Apellido", "Salario", "Sector\n");
									OrderEmployees_Salary_Sector(listaEmployee, tamEmployee, respuesta);
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

							printf("\n\nListado de empleados encontrados\n");
							printf("\n%5s %10s %12s %9s %10s", "Id", "Nombre", "Apellido", "Salario", "Sector\n");
							PrintEmployees(listaEmployee, tamEmployee);
							suma = SumSalaries(listaEmployee, tamEmployee);
							promedio = AverageSalarie(listaEmployee, tamEmployee);
							ContadorEmpleadosMaxSalario = ShowAverageEmployess(listaEmployee, tamEmployee);
							printf("\n\nEl total del salario de los empleados es: %.2f$\n", suma);
							printf("\nEl promedio de todos los salarios de los empleados es: %.2f$\n", promedio);
							printf("\nLa cantidad de empleados que supera el salario promedio es: %d\n", ContadorEmpleadosMaxSalario);
							system("pause");
							system("cls");
						break;
							}

						}while(continuar !=3);

		if(continuar == 3 || continuar > 3)
		{
			continuar = -1;
		}
		return continuar;
}


float SumSalaries(eEmployee listaEmployee[], int tamEmployee)
{
    int i;
    float AcumularSalarios = 0;

    for(i=0; i<tamEmployee; i++)
    {
        if(listaEmployee[i].IsEmpty == FALSE)
        {
        	AcumularSalarios += listaEmployee[i].Salary;
        }
    }
    return AcumularSalarios;
}

float AverageSalarie(eEmployee listaEmployee[], int tamEmployee)
{
    int i;
    float PromedioSalarios = 0;

    for(i=0; i<tamEmployee; i++)
    {
        if(listaEmployee[i].IsEmpty == FALSE)
        {
        	PromedioSalarios = SumSalaries(listaEmployee, tamEmployee) / CountEmployees(listaEmployee, tamEmployee);
        }
    }
    return PromedioSalarios;
}


int CountEmployees(eEmployee listaEmployee[], int tamEmployee)
{
    int i;
    int ContadorEmpleados = 0;

    for(i=0; i<tamEmployee; i++)
    {
        if(listaEmployee[i].IsEmpty == FALSE)
        {
        	ContadorEmpleados++;
        }
    }
    return ContadorEmpleados;
}


int ShowAverageEmployess(eEmployee listaEmployee[], int tamEmployee)
{
    int i;
    float Promedio;
    int EmpleadosConMayorSueldo = 0;
    Promedio = AverageSalarie(listaEmployee, tamEmployee);

    for(i=0; i<tamEmployee; i++)
    {
        if(listaEmployee[i].IsEmpty == FALSE && listaEmployee[i].Salary > Promedio)
        {
        	EmpleadosConMayorSueldo++;
        }
    }
    return EmpleadosConMayorSueldo;
}

void PrintGenero(eGenero *listaGeneros, int tam)
{
	int i;
	for(i=0; i<tam; i++)
	{
		if(listaGeneros[i].isEmpty == FALSE)
		{
			printf("\n*%4d %9s \n", listaGeneros[i].IdGenero,
									listaGeneros[i].descripcionGen);
		}
	}
}

void PrintArtista(eArtista *listaArtistas, int tam)
{
	int i;
	for(i=0; i<tam; i++)
	{
		if(listaArtistas[i].isEmpty == FALSE)
		{
			printf("\n*%4d %9s \n", listaArtistas[i].IdArtista,
									listaArtistas[i].nombre);
		}
	}
}

void PrintTipoArtista(eTipoArtista *listaTipoArtista, int tam)
{
	int i;
	for(i=0; i<tam; i++)
	{
		if(listaTipoArtista[i].isEmpty == FALSE)
		{
			printf("\n*%4d %9s \n", listaTipoArtista[i].IdTipo,
									listaTipoArtista[i].descripcionTipo);
		}
	}
}
*/
int BuscarIdMaxima(eAlbum listaAlbum[], int tam)
{
	int idMaxima;

	if(tam>0)
	{
		for(int i = 0; i<tam; i++)
		{
			if(listaAlbum[i].IsEmpty != TRUE)
			{
				idMaxima = listaAlbum[i].IdAlbum;
			}
		}
	}
	return idMaxima;
}

