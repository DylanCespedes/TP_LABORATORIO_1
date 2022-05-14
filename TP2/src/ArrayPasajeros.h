#ifndef ARRAYPASAJEROS_H_
#define ARRAYPASAJEROS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define P 2000
#define TRUE 1
#define FALSE 0
#define TAMA 51

typedef struct
{
	int id;
	char name[TAMA];
	char lastName[TAMA];
	float price;
	char flyCode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty;
}ePassenger;

typedef struct
{
	int idTipo;
	char descripcion[TAMA];
	int isEmpty;

}eTipoPasajero;

/**
 * initPassengers(ePassenger listaPasajeros[], int tam)
 *
 * @param listaPasajeros = Inicializa la lista de pasajeros.
 * @param tam = Tamanio de la lista de pasajeros.
 * Inicializa una lista de pasajeros.
 */

void initPassengers(ePassenger listaPasajeros[], int tam);

/**
 * InicializarTipoPasajero(eTipoPasajero listaTipo[], int tam)
 *
 * @param listaTipo = Inicializa la lista de tipos.
 * @param tam = Tamanio de la lista de tipos.
 * Inicializa una lista con el tipo del pasajero.
 */

void InicializarTipoPasajero(eTipoPasajero listaTipo[], int tam);

/**
 * HarcodearPassenger(ePassenger listaPasajeros[], int *idIncrementaPasajeros, int tam, int *pFlag)
 *
 * @param listaPasajeros = Harcodea una lista de pasajeros.
 * @param idIncrementaPasajeros = Incrementa la lista de pasajeros.
 * @param tam = Tamanio de la lista.
 * @param pFlag = Bandera de primero de la lista.
 * Harcodea la lista de pasajeros con datos.
 */

void HarcodearPassenger(ePassenger listaPasajeros[], int *idIncrementaPasajeros, int tam, int *pFlag);

/**
 * HarcodearTipoPasajero(eTipoPasajero listaTipo[], int tam, int *pFlag)
 *
 * @param listaTipo = Harcodea la lista de tipos.
 * @param tam = Tamanio de la lista.
 * @param pFlag = Bandera de primero de la lista.
 * Harcodea la lista de tipos de pasajeros con datos.
 */

void HarcodearTipoPasajero(eTipoPasajero listaTipo[], int tam, int *pFlag);

/**
 * PrintTipoPasajero(eTipoPasajero listaTipo[], int tam)
 *
 * @param listaTipo = Muestra la lista de tipos.
 * @param tam = Tamanio de la lista.
 * Harcodea la lista de tipo de pasajeros.
 */

void PrintTipoPasajero(eTipoPasajero listaTipo[], int tam);

/**
 * PrintTipoPasajero(eTipoPasajero listaTipo[], int tam)
 *
 * @param listaTipo = Muestra solo una lista de un tipo.
 * Muestra la lista de un tipo de pasajero.
 */

void PrintOneTipoPasajero(eTipoPasajero listaTipo);

/**
 * PrintPasajero(ePassenger listaPasajeros[], int tam, eTipoPasajero listaTipos[], int tamTipo)
 *
 * @param listaPasajeros = Muestra la lista de los pasajeros.
 * @param tam = Tamanio de la lista
 * @param listaTipos = Muestra la lista de tipos.
 * @param tamTipo = Tamanio de la lista de tipos.
 * Muestra la lista de pasajeros con su tipo.
 */

void PrintPasajero(ePassenger listaPasajeros[], int tam, eTipoPasajero listaTipos[], int tamTipo);

/**
 * PrintOnePasajero(ePassenger unPasajero)
 *
 * @param unPasajero = Pasajero a mostrar.
 * Muestra un pasajero de la lista.
 * Muestra solo un pasajero en la lista.
 */

void PrintOnePasajero(ePassenger unPasajero);

/**
 * PrintOnePasajeroTipo(ePassenger unPasajero, eTipoPasajero unTipo)
 *
 * @param unPasajero = Pasajero de la lista a mostrar.
 * @param unTipo = Tipo de la lista a mostrar.
 * Muestra un pasajero y un tipo de la lista.
 */

void PrintOnePasajeroTipo(ePassenger unPasajero, eTipoPasajero unTipo);
/**
 * buscarPassenger(ePassenger listaPasajeros[], int tam, int id, int* pIndex)
 *
 * @param listaPasajeros = Lista de pasajeros.
 * @param tam = Tamanio de la lista.
 * @param id = ID ingresada por el usuario.
 * @param pIndex = Indice donde se encuentra el pasajero en la lista.
 * @return = Retorna el indice de la lista si lo encuentra de lo contrario retorna -1
 * Busca en la lista el pasajero ingresado por el usuario.
 */
int buscarPassenger(ePassenger listaPasajeros[], int tam, int id, int* pIndex);

/**
 * buscarTipoPassenger(eTipoPasajero listaTipo[], int tam, int id, int* pIndex)
 *
 * @param listaTipo = Lista de tipos
 * @param tam = Tamanio de la lista.
 * @param id = ID ingresada por el usuario.
 * @param pIndex = Indice donde se encuentra el tipo de la lista.
 * @return = Retorna el indice de la lista si lo encuentra de lo contrario retorna -1
 * Busca el tipo de pasajero en la lista ingresado por el usuario.
 */

int buscarTipoPassenger(eTipoPasajero listaTipo[], int tam, int id, int* pIndex);

/**
 * FindFreeIndex(ePassenger listaPasajeros[], int tam)
 *
 * @param listaPasajeros = Lista de pasajeros.
 * @param tam = Tamanio de la lista.
 * @return = Retorna el indice si encuentra un espacio libre para cargar.
 * Busca un lugar libre en la lista.
 */

int FindFreeIndex(ePassenger listaPasajeros[], int tam);

/**
 * FindPassengerById(ePassenger listaPasajeros[], int tam, int datoId)
 *
 * @param listaPasajeros = Lista de pasajeros.
 * @param tam = Tamanio de la lista.
 * @param datoId = Dato a buscar.
 * @return = Retorna el indice si el id coincide retorna a -1
 * Busca el pasajero por el id ingresado.
 */

int FindPassengerById(ePassenger listaPasajeros[], int tam, int datoId);

/**
 * addOnePassenger(ePassenger listaPasajeros[], int tam, int IdIncrementalPassenger, eTipoPasajero listaTipo[], int tamTipo)
 *
 * @param listaPasajeros = Lista de pasajeros.
 * @param tam = Tamanio de la lista.
 * @param IdIncrementalPassenger = ID a asignar.
 * @param listaTipo = Lista de tipos.
 * @param tamTipo = Tamanio de la lista de tipos.
 * Busca un indice libre y lo asigna a una lista de pasajeros vacia.
 */

void addOnePassenger(ePassenger listaPasajeros[], int tam, int IdIncrementalPassenger, eTipoPasajero listaTipo[], int tamTipo);

/**
 * ModifyPasajero(ePassenger listaPasajeros[], int tam, eTipoPasajero listaTipo[], int tamTipo)
 *
 * @param listaPasajeros = Lista de pasajeros.
 * @param tam = Tamanio de la lista.
 * @param listaTipo = Lista de tipos.
 * @param tamTipo = Tamanio de la lista de tipos.
 * Modifica un pasajero ingresando la ID a modificar.
 */

void ModifyPasajero(ePassenger listaPasajeros[], int tam, eTipoPasajero listaTipo[], int tamTipo);

/**
 * AddPassenger(int IdIncrementalPassenger, eTipoPasajero listaTipos[], int tamTipo)
 *
 * @param IdIncrementalPassenger = ID a asignar.
 * @param listaTipos = Lista de tipos.
 * @param tamTipo = Tamanio de la lista de tipos.
 * @return = Retorna un pasajero con todos los datos cargados.
 * Carga los datos de un pasajero.
 */

ePassenger AddPassenger(int IdIncrementalPassenger, eTipoPasajero listaTipos[], int tamTipo);

/**
 * DeletePasseger(ePassenger listaPasajeros[], int tam, eTipoPasajero listaTipo[], int tamTipo)
 *
 * @param listaPasajeros = Lista de pasajeros.
 * @param tam = Tamanio de la lista de pasajeros.
 * @param listaTipo = Lista de tipos.
 * @param tamTipo = Tamanio de tipos.
 * Solicita el id a ingresar por el usuario para eliminar un pasajero de la lista.
 */

void DeletePasseger(ePassenger listaPasajeros[], int tam, eTipoPasajero listaTipo[], int tamTipo);

/**
 * RemovePasseger(ePassenger listaPasajeros[], int tam, int indice, char mensaje[])
 *
 * @param listaPasajeros = Lista de pasajeros.
 * @param tam = Tamanio de la lista.
 * @param indice = Indice del array de pasajeros.
 * @param mensaje = Mensaje a mostrar.
 * Elimina un pasajero de la lista cambiandole el estado.
 */

void RemovePasseger(ePassenger listaPasajeros[], int tam, int indice, char mensaje[]);
/**
 * MenuPassager(ePassenger listaPasajeros[], int tam, eTipoPasajero listaTipo[], int tamTipo)
 *
 * @param listaPasajeros = Lista de pasajeros.
 * @param tam = Tamanio de la lista.
 * @param listaTipo = Lista de tipos.
 * @param tamTipo = Tamanio de la lista de tipos.
 * @return = Retorna -1 si se decide salir del menu secundario.
 * Menu secundario de pasajeros.
 */
int MenuPasseger(ePassenger listaPasajeros[], int tam, eTipoPasajero listaTipo[], int tamTipo);
/**
 * sortPassengersByCode(ePassenger listaPasajeros[], int tam, int respuesta, eTipoPasajero listaTipo[], int tamTipo)
 *
 * @param listaPasajeros = Lista de pasajeros.
 * @param tam = Tamanio de la lista.
 * @param respuesta = Respuesta del usuario para ordenar el array.
 * @param listaTipo = Lista de tipos.
 * @param tamTipo = Tamanio de la lista de tipos.
 * Ordena la lista de pasajeros.
 */
void sortPassengersByCode(ePassenger listaPasajeros[], int tam, int respuesta, eTipoPasajero listaTipo[], int tamTipo);
/**
 * SumPrices(ePassenger listaPasajeros[], int tam)
 *
 * @param listaPasajeros = Lista de pasajeros.
 * @param tam = Tamanio de la lista.
 * @return = Retorna a la suma total de precios.
 * Suma los precios de la lista.
 */
float SumPrices(ePassenger listaPasajeros[], int tam);
/**
 * AveragePrice(ePassenger listaPasajeros[], int tam)
 *
 * @param listaPasajeros = Lista de pasajeros.
 * @param tam = Tamanio de la lista.
 * @return = Retorna el promedio de precios de la lista.
 * Calcula el precio.
 */
float AveragePrice(ePassenger listaPasajeros[], int tam);
/**
 * CountPassenger(ePassenger listaPasajeros[], int tam)
 *
 * @param listaPasajeros = Lista de pasajeros.
 * @param tam = Tamanio de la lista.
 * @return = Retorna la cantidad de pasajeros de la lista.
 * Cuenta y retorna la lista de pasajeros.
 */
int CountPassenger(ePassenger listaPasajeros[], int tam);
/**
 * ShowAveragePassenger(ePassenger listaPasajeros[], int tam)
 *
 * @param listaPasajeros = Lista de pasajeros.
 * @param tam = Tamanio de la lista.
 * @return = Retorna el indice del pasajero con salario superior al promedio.
 * Retorna el indice del pasajero con el mayor salario promedio.
 */
int ShowAveragePassenger(ePassenger listaPasajeros[], int tam);
/**
 * sortPassengersByStatus(ePassenger listaCodigo[], int tam, eTipoPasajero listaEstado[], int tamEstado)
 *
 * @param listaCodigo = Listado de codigos.
 * @param tam = Tamanio de la lista.
 * @param listaEstado = Lista de estados.
 * @param tamEstado = Tamanio de la lista de estados.
 * Ordena la lista de pasajeros por el estado activo.
 */
void sortPassengersByStatus(ePassenger listaCodigo[], int tam, eTipoPasajero listaEstado[], int tamEstado);
/**
 * PrintPasajerosEstadoActivo(ePassenger listaPasajeros[], int tam, eTipoPasajero listaTipos[], int tamTipo)
 *
 * @param listaPasajeros = Lista de pasajeros.
 * @param tam = Tamanio de la lista.
 * @param listaTipos = Lista de tipos.
 * @param tamTipo = Tamanio de tipos.
 * Muestra los pasajeros ordenados por estado activo.
 */
void PrintPasajerosEstadoActivo(ePassenger listaPasajeros[], int tam, eTipoPasajero listaTipos[], int tamTipo);

#endif /* ARRAYPASAJEROS_H_ */
