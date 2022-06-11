/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */

#include "Passenger.h"
#include "LinkedList.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


Passenger* Passenger_New()
{
	Passenger* pPassengerList;

	pPassengerList = (Passenger*)malloc(sizeof(Passenger));

	return pPassengerList;
}

Passenger* passenger_newParametros(char* idStr, char* nombreStr, char* apellidoStr, float precio, int tipo, char* codVueloStr)
{
	Passenger* pPassenger;

	pPassenger = Passenger_New();

	if(pPassenger != NULL)
	{
		Passenger_setId(pPassenger, atoi(idStr));
		Passenger_setNombre(pPassenger, nombreStr);
		Passenger_setApellido(pPassenger, apellidoStr);
		Passenger_setPrecio(pPassenger, precio);
		Passenger_setTipoPasajero(pPassenger, tipo);
		Passenger_setCodigoVuelo(pPassenger, codVueloStr);
	}

	return pPassenger;
}

void Passenger_delete()
{




}

/*////////////////////////////////////////////////////////*/

int Passenger_setId(Passenger* thisPassenger,int id)
{
	int responseSetId = 0;

		if(thisPassenger != NULL && id > 0)
		{
			thisPassenger->id = id;
			responseSetId = 1;
		}

		return responseSetId;
}

int Passenger_getId(Passenger* thisPassenger,int* id)
{
	int responseGetId = 0;

		if(thisPassenger != NULL && id != NULL)
		{
			*id = thisPassenger->id;
			responseGetId = 1;
		}

		return responseGetId;
}

/*////////////////////////////////////////////////////////*/

void Passenger_printOne(Passenger* unPasajero)
{



}

/*////////////////////////////////////////////////////////*/

int Passenger_setNombre(Passenger* thisPassenger,char* nombre)
{
	int responseSetNombre = 0;

		if(thisPassenger != NULL && nombre != NULL)
		{
			strcpy(thisPassenger->nombre, nombre);
			responseSetNombre = 1;
		}

		return responseSetNombre;
}

int Passenger_getNombre(Passenger* thisPassenger,char* nombre)
{
	int responseGetNombre = 0;

		if(thisPassenger != NULL && nombre != NULL)
		{
			strcpy(nombre, thisPassenger->nombre);
			responseGetNombre = 1;
		}

		return responseGetNombre;
}

int Passenger_setApellido(Passenger* thisPassenger,char* apellido)
{
	int responseSetApellido = 0;

			if(thisPassenger != NULL && apellido != NULL)
			{
				strcpy(thisPassenger->apellido, apellido);
				responseSetApellido = 1;
			}

			return responseSetApellido;
}

int Passenger_getApellido(Passenger* thisPassenger,char* apellido)
{
	int responseGetApellido = 0;

			if(thisPassenger != NULL && apellido != NULL)
			{
				strcpy(apellido, thisPassenger->apellido);
				responseGetApellido = 1;
			}

			return responseGetApellido;
}

/*////////////////////////////////////////////////////////*/

int Passenger_setCodigoVuelo(Passenger* thisPassenger,char* codigoVuelo)
{
	int responseSetCodVuelo = 0;

				if(thisPassenger != NULL && codigoVuelo != NULL)
				{
					strcpy(thisPassenger->codigoVuelo, codigoVuelo);
					responseSetCodVuelo = 1;
				}

				return responseSetCodVuelo;
}

int Passenger_getCodigoVuelo(Passenger* thisPassenger,char* codigoVuelo)
{
	int responseGetCodVuelo = 0;

				if(thisPassenger != NULL && codigoVuelo != NULL)
				{
					strcpy(codigoVuelo, thisPassenger->codigoVuelo);
					responseGetCodVuelo = 1;
				}

				return responseGetCodVuelo;
}

/*////////////////////////////////////////////////////////*/

int Passenger_setTipoPasajero(Passenger* thisPassenger,int tipoPasajero)
{
	int responseSetTipoPasajero = 0;

				if(thisPassenger != NULL && tipoPasajero > 0)
				{
					thisPassenger->tipoPasajero = tipoPasajero;
					responseSetTipoPasajero = 1;
				}

			return responseSetTipoPasajero;
}

int Passenger_getTipoPasajero(Passenger* thisPassenger,int* tipoPasajero)
{
	int responseGetTipoPasajero = 0;

					if(thisPassenger != NULL && tipoPasajero != NULL)
					{
						*tipoPasajero = thisPassenger->tipoPasajero;
						responseGetTipoPasajero = 1;
					}

					return responseGetTipoPasajero;
}

/*////////////////////////////////////////////////////////*/

int Passenger_setPrecio(Passenger* thisPassenger,float precio)
{
	int responseSetPrecio = 0;

			if(thisPassenger != NULL && precio > 0)
			{
				thisPassenger->precio = precio;
				responseSetPrecio = 1;
			}

		return responseSetPrecio;
}

int Passenger_getPrecio(Passenger* thisPassenger, float* precio)
{
	int responseGetPrecio = 0;

						if(thisPassenger != NULL && precio != NULL)
						{
							*precio = thisPassenger->precio;
							responseGetPrecio = 1;
						}

						return responseGetPrecio;
}

int Passenger_SearchIdPassenger(LinkedList* pArrayListPassenger, int auxId)
{
    Passenger* auxPasajero;

    int index=-1;
    int idPasajero;
    int length;
    int i;

    length=ll_len(pArrayListPassenger);

    for(i=0; i<length; i++)
    {
    	auxPasajero = (Passenger*)ll_get(pArrayListPassenger, i);
    	idPasajero = auxPasajero->id;
        Passenger_getId(auxPasajero, &idPasajero);

       if(auxId==idPasajero)
       {
            index=i;
            break;
       }
    }

    return index;
}


int Passenger_CompareNames(void* passenger1, void* passenger2)
{
    Passenger* pasajero1;
    Passenger* pasajero2;
    char auxNombre1[30];
    char auxNombre2[30];
    int compare;

    pasajero1 = (Passenger*)passenger1;
    pasajero2 = (Passenger*)passenger2;

    Passenger_getNombre(pasajero1, auxNombre1);
    Passenger_getNombre(pasajero2, auxNombre2);
    compare = strcmp(auxNombre1, auxNombre2);

    return compare;
}

int Passenger_CompareId(void* passenger1, void* passenger2)
{
	Passenger* pasajero1;
    Passenger* pasajero2;
    int auxId1;
    int auxId2;
    int compare=0;

    pasajero1 = (Passenger*)passenger1;
    pasajero2 = (Passenger*)passenger2;

    Passenger_getId(pasajero1, &auxId1);
    Passenger_getId(pasajero2, &auxId2);

    if(auxId1>auxId2)
    {
        compare=1;

    }
    else
    {
        if(auxId1<auxId2)
        {
            compare=-1;
        }
    }
    return compare;
}


int Passenger_CompareLastName(void* passenger1, void* passenger2)
{
    Passenger* pasajero1;
    Passenger* pasajero2;
    char auxApellido1[30];
    char auxApellido2[30];
    int compare;

    pasajero1 = (Passenger*)passenger1;
    pasajero2 = (Passenger*)passenger2;

    Passenger_getApellido(pasajero1, auxApellido1);
    Passenger_getApellido(pasajero2, auxApellido2);
    compare = strcmp(auxApellido1, auxApellido2);

    return compare;
}

int Passenger_ComparePrices(void* passenger1, void* passenger2)
{
	Passenger* pasajero1;
	Passenger* pasajero2;
    int auxPrecio1;
    int auxPrecio2;
    int compare=0;

    pasajero1 = (Passenger*)passenger1;
    pasajero2 = (Passenger*)passenger2;

    Passenger_getPrecio(pasajero1, &auxPrecio1);
    Passenger_getPrecio(pasajero2, &auxPrecio2);


    if(auxPrecio1>auxPrecio2)
    {
        compare=1;

    }
    else
    {
        if(auxPrecio1<auxPrecio2)
        {
            compare=-1;
        }
    }
    return compare;
}

int Passenger_CompareType(void* passenger1, void* passenger2)
{
	Passenger* pasajero1;
	Passenger* pasajero2;
    int auxTipo1;
    int auxTipo2;
    int compare=0;

    pasajero1 = (Passenger*)passenger1;
    pasajero2 = (Passenger*)passenger2;

    Passenger_getTipoPasajero(pasajero1, &auxTipo1);
    Passenger_getTipoPasajero(pasajero2, &auxTipo2);


    if(auxTipo1>auxTipo2)
    {
        compare=1;

    }
    else
    {
        if(auxTipo1<auxTipo2)
        {
            compare=-1;
        }
    }
    return compare;
}

int Passenger_CompareCod(void* passenger1, void* passenger2)
{
    Passenger* pasajero1;
    Passenger* pasajero2;
    char auxCod1[30];
    char auxCod2[30];
    int compare;

    pasajero1 = (Passenger*)passenger1;
    pasajero2 = (Passenger*)passenger2;

    Passenger_getApellido(pasajero1, auxCod1);
    Passenger_getApellido(pasajero2, auxCod2);
    compare = strcmp(auxCod1, auxCod2);

    return compare;
}
