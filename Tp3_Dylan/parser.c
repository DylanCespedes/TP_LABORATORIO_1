#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "Generic_Functions.h"
#include "Controller.h"
#define L 25
#define T 100

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{

	Passenger* newPassenger;
			char IdAux[L];
			char auxNombre[T];
			char auxApellido[T];
			char auxCod[L];
			char auxTipo[T];
			char auxPrecio[T];
			int TextLeidos;
			int respuesta = 0;

			if(pFile != NULL && pArrayListPassenger != NULL)
			{
				fscanf(pFile, "%[^,], %[^,], %[^,], %[^,], %[^,], %[^\n]\n", IdAux, auxNombre, auxApellido, auxPrecio, auxTipo, auxCod);
				while(!feof(pFile))
				{
					TextLeidos = fscanf(pFile, "%[^,], %[^,], %[^,], %[^,], %[^,], %[^\n]\n", IdAux, auxNombre, auxApellido, auxPrecio, auxTipo, auxCod);
					if(TextLeidos == 6)
					{
						newPassenger = passenger_newParametros(IdAux, auxNombre, auxApellido, atof(auxPrecio), atoi(auxTipo), auxCod);
						ll_add(pArrayListPassenger, newPassenger);
						respuesta = 1;
					}
						if(feof(pFile))
						{
							break;
						}
				}
				fclose(pFile);
				controller_ListPassenger(pArrayListPassenger);
				respuesta = 1;
			}
		    return respuesta;


}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	Passenger* newPassenger;
			int respuesta = 0;
			int flag;

			if(pFile!= NULL && pArrayListPassenger != NULL)
			{
				while(!feof(pFile))
				{
					newPassenger = Passenger_New();
					flag = fread(newPassenger, sizeof(Passenger), 1, pFile);

					if(flag == 1)
					{
						ll_add(pArrayListPassenger, newPassenger);
					}
				}
				respuesta = 1;
				fclose(pFile);
			}
		    return respuesta;


}
