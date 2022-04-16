#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Funciones.h"

void MenuOpciones(char mensaje1[], char mensaje2[], char mensaje3[], char mensaje4[], char mensaje5[], char mensaje6[], char mensaje7[])
{
	char opcion[20];
	int cantidadOpciones = 7;
	int opcionValidada;
	int banderaAerolineas = 0;
	int banderaLatam, banderaKm, banderaMostrar, banderaCarga = 0;
	float x = 0;
	float y = 0;
	float z = 0;
	float aerolineasDescuento, aerolineasInteres, bitcoinsAerolineas, precioUnitAerolineas, latamDescuento, latamInteres, bitcoinsLatam, precioUnitLatam, diferenciaPrecio;

	do
	{
		system("cls");
		printf("Km ingresados = %.2fKm\n", x);
		MostrarDatos(&y, &z);

		printf("%s", mensaje1);
		printf("%s", mensaje2);
		printf("%s", mensaje3);
		printf("%s", mensaje4);
		printf("%s", mensaje5);
		printf("%s", mensaje6);
		printf("%s", mensaje7);

		printf("\n\nIngrese una opcion: ");
		scanf("%s", opcion);

		ValidarIngreso(opcion, cantidadOpciones);

		opcionValidada = ParseInt(opcion);

		switch(opcionValidada)
		{
			case 1:
				x = GetNum("\nIngrese el kilometraje: ", "\nError!!! ingrese el kilometraje: ");
				if(x == 0)
				{
					printf("\nUsted ha ingresado un numero menor o igual a 0, vuelva a cargar el dato\n");
					system("pause");
				}
				else
				{
					printf("\nSe ha cargado el dato con exito\n");
					banderaKm = 1;
					system("pause");
				}
				break;

			case 2:
				MenuSecundario("\n1)Ingresar precio de vuelo Aerolineas Argentinas",
								"\n2)Ingresar precio de vuelo LATAM",
								"\n3)Salir", &y, &z, &banderaAerolineas, &banderaLatam);
				break;

			case 3:

				if(banderaAerolineas == 1 && banderaLatam == 1 && banderaKm == 1)
				{
					//Precio Aerolineas
					aerolineasDescuento = CalcularDescuento(y);
					aerolineasInteres = CalcularInteres(y);
					bitcoinsAerolineas = PrecioEnBitcoins(y);
					precioUnitAerolineas = PrecioPorKm(y, x);
					//Precio LATAM

					latamDescuento = CalcularDescuento(z);
					latamInteres = CalcularInteres(z);
					bitcoinsLatam = PrecioEnBitcoins(z);
					precioUnitLatam =  PrecioPorKm(y, x);

					diferenciaPrecio = DiferenciaPrecio(y, z);
					banderaMostrar = 1;
					//printf("%.2f", aerolineasDescuento);
					printf("\nSe han calculado todos los costos\n\n");
					system("pause");
				}
				else
				{
					printf("\nDebe ingresar todos los datos para operar!!!!!\n\n");
					system("pause");
					system("cls");
				}
					break;

			case 4:
				if(banderaMostrar)
				{
					printf("\nPrecio Aerolineas: $%.2f", y);
					printf("\na) Precio con tarjeta de debito: $%.2f", aerolineasDescuento);
					printf("\nb) Precio con tarjeta de credio: $%.2f", aerolineasInteres);
					printf("\nc) Precio pagando con bitcoin: %.5f BTC", bitcoinsAerolineas);
					if(x == 0)
					{
						printf("\nc) Error, no es posible dividir por 0");
					}
					else
					{
						printf("\nd) Precio unitario aerolineas: $%.2f", precioUnitAerolineas);

					}
					printf("\n\nPrecio Latam: $%.2f", z);
					printf("\na) Precio con tarjeta de debito: $%.2f", latamDescuento);
					printf("\nb) Precio con tarjeta de credio: $%.2f", latamInteres);
					printf("\nc) Precio pagando con bitcoin: %.5f BTC", bitcoinsLatam);
					if(x == 0)
					{
						printf("\nc) Error, no es posible dividir por 0");
					}
					else
					{
						printf("\nd) Precio unitario aerolineas: $%.2f", precioUnitLatam);

					}
					printf("\n\n* La diferencia de precios es $%.2f\n\n", diferenciaPrecio);

					if(banderaCarga != 0)
					{
						x = 0;
						y = 0;
						z = 0;
						banderaAerolineas = 0;
						banderaLatam = 0;
						banderaKm = 0;
					}
					banderaMostrar = 0;
					system("pause");
					system("cls");
				}
				else
				{
					printf("\nPara mostrar el resultado de las operaciones usted tuvo que haber ingresado a la opcion 3 con anterioridad\n\n");
					system("pause");
					system("cls");
				}
				break;

			case 5:

				x = 7090;
				y = 162975;
				z = 159339;

				//Precio Aerolineas
				aerolineasDescuento = CalcularDescuento(y);
				aerolineasInteres = CalcularInteres(y);
				bitcoinsAerolineas = PrecioEnBitcoins(y);
				precioUnitAerolineas = PrecioPorKm(y, x);
				//Precio LATAM
				latamDescuento = CalcularDescuento(z);
				latamInteres = CalcularInteres(z);
				bitcoinsLatam = PrecioEnBitcoins(z);
				precioUnitLatam =  PrecioPorKm(y, x);
				diferenciaPrecio = DiferenciaPrecio(y, z);

				banderaCarga = 1;
				banderaAerolineas = 1;
				banderaLatam = 1;
				banderaKm = 1;

				printf("\nSe ha completado la carga forzada de datos\n\n");
				system("pause");
				break;

			case 6:
				printf("\nUsted ha salido del sistema de carga de datos\n\n");
				system("pause");
				break;
		}

	}while(opcionValidada != 6);
}

float GetNum(char mensajeIngreso[], char mensajeError[])
{

	char ingreso[20];

	printf("%s", mensajeIngreso);

	fflush(stdin);

	scanf("%s", ingreso);

	while(ValidarFloat(ingreso) != 1)
	{
		printf("%s", mensajeError);
		//fflush(ingreso);
		scanf("%s", ingreso);

	}

	return ParseFloat(ingreso);
}

int ValidarInt(char cadenaValidar[])
{
	int esInt = 1;

	for(int i=0; i < strlen(cadenaValidar); i++)
	{
		if(!isdigit(cadenaValidar[i]))
			{
				esInt = 0;
				break;
			}
	}
	return esInt;
}

int ValidarFloat(char validFloat[])
{
	int i;
	int countsign = 0;
	int response;
	response = 1;

	for(i=0; i<strlen(validFloat); i++)
	{
		if(validFloat[i] == '.' || validFloat[i] == ',')
		{
			countsign++;
		}
		else
		{
			if(isdigit(validFloat[i]) == 0)
			{
				response = 0;
				break;
			}
		}
	}
	if(countsign > 1)
	{
		response = 0;
	}
	return response;
}

int ParseInt(char stringdata[])
{
	int intNumber;

	intNumber = atoi(stringdata);

	return intNumber;
}

float ParseFloat(char stringData[])
{
	float floatNumber;

	floatNumber = atof(stringData);

	return floatNumber;
}

int ValidarRangoInt(char stringData[], int rango)
{
	int cumpleRango = 0;
	int num;

	num = ParseInt(stringData);

	if(num < rango && ValidarInt(stringData) != 0)
	{
		cumpleRango = 1;
	}
	return cumpleRango;
}

int ValidarIngreso(char stringImput[], int cantidadOpciones)
{
	float opcionValidada;

	while(ValidarInt(stringImput) == 0 || ValidarRangoInt(stringImput, cantidadOpciones) == 0)
		{
			printf("\nError, Ingrese una opcion correcta: ");
			scanf("%s", stringImput);
		}

	opcionValidada = ParseInt(stringImput);

	return opcionValidada;
}

void MenuSecundario(char mensaje1[], char mensaje2[], char mensaje3[], float* pY, float* pZ, int* pBanderaAerolineas, int* pBanderaLatam)
{
	char opcion[20];
	int opcionValidada;
	int cantidadOpciones = 4;

	do
	{
		system("cls");
		MostrarDatos(pY, pZ);
		printf("%s", mensaje1);
		printf("%s", mensaje2);
		printf("%s", mensaje3);

		printf("\n\nIngrese una opcion: ");
		scanf("%s", opcion);
		opcionValidada = ValidarIngreso(opcion, cantidadOpciones);

		switch(opcionValidada)
		{
			case 1:
				system("cls");

				*pY = GetNum("Ingrese el precio de aerolineas: ", "ERROR!!! Ingrese el precio de aerolineas: ");
				if(*pY == 0)
				{
					printf("\nUsted ha ingresado un numero igual a 0, vuelva a cargar el dato\n");
					system("pause");
				}
				else
				{
					printf("\nPrecio ingresado con exito!!!\n\n");
					*pBanderaAerolineas = 1;
					system("pause");
				}

				break;

			case 2:
				system("cls");
				*pZ = GetNum("Ingrese el precio de Latam: ", "ERROR!!! Ingrese el precio de Latam: ");
				if(*pZ == 0)
				{
					printf("\nUsted ha ingresado un numero igual a 0, vuelva a cargar el dato.\n");
					system("pause");
				}
				else
				{
					printf("\nPrecio ingresado con exito!!!\n\n");
				    *pBanderaLatam = 1;
					system("pause");
				}
			    *pBanderaLatam = 1;
				break;

			case 3:
				printf("\nUsted ha salido del menu de ingresos.\n\n");
				system("pause");
				break;
		}

	}while(opcionValidada != 3);
}

void MostrarDatos(float* dato2, float* dato3)
{
	printf("Precio Aerolineas = $%.2f\n", *dato2);
	printf("Precio Latam = $%.2f$\n", *dato3);
}

float CalcularDescuento(float dato)
{
	int descuento = 10;
	//(Porcentaje de descuento * Valor total) / 100
	return dato - (dato * descuento) / 100;

}

float CalcularInteres(float dato)
{
	return dato + dato * (0.2);
}

float PrecioEnBitcoins(float dato)
{
	return dato / 4643599.54;
}

float PrecioPorKm(float dato, float km)
{
	return dato / km;
}

float DiferenciaPrecio(float dato, float dato2)
{
	return dato2 - dato;
}
