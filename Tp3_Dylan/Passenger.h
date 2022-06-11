/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_
#include "LinkedList.h"
typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[4];
	int isEmpty;

}Passenger;

Passenger* Passenger_New();
Passenger* passenger_newParametros(char* idStr, char* nombreStr, char* apellidoStr, float precio, int tipo, char* codVueloStr);
void Passenger_delete();

int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);

void Passenger_printOne(Passenger* unPasajero);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);

int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);

int Passenger_SearchIdPassenger(LinkedList* pArrayListPassenger, int auxId);

int Passenger_CompareNames(void* passenger1, void* passenger2);
int Passenger_CompareId(void* passenger1, void* passenger2);

int Passenger_CompareLastName(void* passenger1, void* passenger2);
int Passenger_ComparePrices(void* passenger1, void* passenger2);

int Passenger_CompareType(void* passenger1, void* passenger2);
int Passenger_CompareCod(void* passenger1, void* passenger2);


#endif /* PASSENGER_H_ */
