#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "Generic_Functions.h"
#include "parser.h"
#include "Controller.h"
#define L 25
#define T 100


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pArchivo;
		int response = 0;

		pArchivo = (FILE*)malloc(sizeof(FILE));

		if(path != NULL && pArrayListPassenger != NULL)
		{
			pArchivo = fopen(path, "r");

			if(pArchivo != NULL)
			{
				response = parser_PassengerFromText(pArchivo, pArrayListPassenger);
			}
		}
	    return response;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int response = 0;

		FILE* pArchivo;

		pArchivo = (FILE*)malloc(sizeof(FILE));

		if(path != NULL && pArrayListPassenger != NULL)
		{
			pArchivo = fopen(path, "rb");

			if(pArchivo != NULL)
			{
				response = parser_PassengerFromBinary(pArchivo, pArrayListPassenger);
			}
			else
			 {
				pArchivo = fopen(path, "wb");
			 }
		}
	    return response;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
		Passenger* newPassenger;
		char idIngresado[L];
		char nombreIngresado[T];
		char apellidoIngresado[L];
		float precioIngresado;
		char codigoIngresado[L];
		int tipoIngresado;

		int response = 0;
		int newId;
		int lengt;

		lengt = ll_len(pArrayListPassenger);

		if(pArrayListPassenger != NULL)
		{
			newPassenger = Passenger_New();

			if(newPassenger != NULL)
			{
				Get_OnlyAlphabetString("\nIngrese el nombre del pasajero: ", "\nNombre invalido, reingrese: ", nombreIngresado, T);
				Get_OnlyAlphabetString("\nIngrese el apellido del pasajero: ", "\nApellido invalido, reingrese: ", apellidoIngresado, T);
				Get_String("Ingrese el codigo de vuelo", "\nCodigo Invalido, reingrese ", codigoIngresado, L);
				precioIngresado = Get_Float("\nIngrese el precio: ", "\nReingrese el precio: ");
				tipoIngresado = Get_Int("\nIngrese el tipo: ", "\nReingrese el tipo: ");
				newId = lengt + 1;
				itoa(newId, idIngresado, L);

				newPassenger = passenger_newParametros(idIngresado, nombreIngresado, apellidoIngresado, precioIngresado, tipoIngresado, codigoIngresado);
				ll_add(pArrayListPassenger, newPassenger);

				printf("\nDatos del pasajero cargados con exito!!!\n\n");
				response = 1;
			}
		}
	    return response;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
		Passenger* aPassenger;
		char auxNombre[20];
		char auxApellido[20];
		char auxCod[20];
		int auxTipo;
		float auxPrecio;
		int opcion;
		int auxId;
		int index;

		    if(pArrayListPassenger != NULL)
		    {
		    	controller_ListPassenger(pArrayListPassenger);
		        auxId = Get_Int("\nIngrese el id del pasajero a modificar: ", "\nReingrese el id a modificar: ");

		        index = Passenger_SearchIdPassenger(pArrayListPassenger, auxId);

		      if(index != -1)
		      {
		    	aPassenger = (Passenger*)ll_get(pArrayListPassenger, index);
		        printf("\nQue desea modificar?\n");
		        opcion = Get_IntRange("1.Nombre\n2.Apellido\n3.Precio\n4.Tipo\n5.Codigo Vuelo\n", "Reingrese una opcion", 1, 5);

		        switch(opcion)
		        {
		            case 1:
		                    Get_OnlyAlphabetString("\nIngrese el nuevo nombre: ", "\nReingrese el nombre: ", auxNombre, 20);
		                    Passenger_setNombre(aPassenger, auxNombre);
		                    printf("\nNombre modificado con exito!!!\n");
		                    break;

		            case 2:
		            		Get_OnlyAlphabetString("\nIngrese el nuevo apellido: ", "\nReingrese el apellido: ", auxApellido, 20);
		            		Passenger_setApellido(aPassenger, auxApellido);
		                    printf("\nApellido modificado con exito!!!\n");
		                    break;

		            case 3:
		                    auxPrecio = Get_Float("\nIngrese el precio", "\nReingrese el precio: ");
		                    Passenger_setPrecio(aPassenger, auxPrecio);
		                    printf("\nPrecio modificado con exito!!!\n");
		                    break;

		            case 4:
		            		auxTipo = Get_Int("\nIngrese el tipo", "\nReingrese el tipo: ");
		            	    Passenger_setTipoPasajero(aPassenger, auxTipo);
		            	    printf("\nTipo modificado con exito!!!\n");
		            	    break;

		            case 5:
		            		Get_String("\nIngrese el codigo de vuelo", "\nReingrese el codigo", auxCod, 20);
		            		Passenger_setCodigoVuelo(aPassenger, auxCod);
		            		printf("\nCodigo de vuelo modificado con exito!!!\n");
		            		break;
		        }
		      }
		    }
		return index;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int auxId;
	    Passenger* auxPassenger;
	    int opcion;
	    int index;

	    if(pArrayListPassenger != NULL)
	    {
	        controller_ListPassenger(pArrayListPassenger);

	        auxId = Get_Int("\nIngrese el id del pasajero a modificar: ", "\nReingrese el id a modificar: ");

	        printf("\nEsta seguro de querer eliminar este pasajero %d ?\n",auxId);

	        opcion = Get_IntRange("1.Si\n2.No\n", "Reingrese una opcion", 1, 2);

	        if(opcion == 1)
	        {
	            index = Passenger_SearchIdPassenger(pArrayListPassenger, auxId);

	            if(index !=- 1)
	            {
	            	auxPassenger = ll_pop(pArrayListPassenger, index);
	                printf("\nPasajero eliminado correctamente...\n");
	                printf("%5d %10s %10s %6s %6.2f %5d\n",auxPassenger->id, auxPassenger->nombre, auxPassenger->apellido, auxPassenger->codigoVuelo, auxPassenger->precio, auxPassenger->tipoPasajero);
	            }

	        }
	        else
	        {
	          printf("A cancelado la eliminacion\n");
	        }
	    }

	    return 1;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
		Passenger* aPassenger;

		int i;
		int lenght;
		int respuesta = 0;
		int auxId;
		char auxApellido[T];
		int auxTipo;
		char auxNombre[T];
		char auxCodVuelo[T];
		float auxPrecio;


		printf("\n%3s%15s%15s%15s%18s%10s", "ID", "Nombre", "Apellido", "Precio","Codigo de Vuelo", "Tipo\n\n");
		printf("***********************************\n");
		if(pArrayListPassenger != NULL)
		{
			lenght = ll_len(pArrayListPassenger);

			for(i = 0; i<lenght; i++)
			{
				aPassenger=(Passenger*)ll_get(pArrayListPassenger, i);
				Passenger_getId(aPassenger, &auxId);
				Passenger_getNombre(aPassenger, auxNombre);
				Passenger_getApellido(aPassenger, auxApellido);
				Passenger_getPrecio(aPassenger, &auxPrecio);
				Passenger_getCodigoVuelo(aPassenger, auxCodVuelo);
				Passenger_getTipoPasajero(aPassenger, &auxTipo);
				printf("%5d %10s %10s %6.2f %6s %5d\n",auxId, auxNombre, auxApellido, auxPrecio, auxCodVuelo, auxTipo);
			}

			respuesta = 1;
		}

	  return respuesta;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int opcion;

		    if(pArrayListPassenger != NULL)
		    {
		        printf("\nBajo que criterio le gustaria ordenar la lista?\n");
		        opcion = Get_IntRange("\n1.Por Id ascendente\n"
		        		"2.Por Id descendente\n"
		        		"3.Por Nombre A->Z\n"
		        		"4.Por Nombre Z->A\n"
		        		"5.Por Apellido A->Z\n"
		        		"6.Por Apellido Z->A\n"
		        		"7.Por Precio ascendente\n"
		        		"8.Por Precio descendente\n"
		        		"9.Por Tipo ascendente\n"
		        		"10.Por Tipo descendente\n"
		        		"11.Por Codigo ascendente\n"
		        		"12.Por Codigo descendente\n"
		        		"Ingrese una opcion: ", "Reingrese una opcion", 1, 12);

		        switch(opcion)
		        {
		            case 1:
		                    ll_sort(pArrayListPassenger, Passenger_CompareId, 1);
		                    controller_ListPassenger(pArrayListPassenger);
		                    printf("\nPasajeros ordenados por Id ascendente con exito\n");
		                    break;
		            case 2:
		                    ll_sort(pArrayListPassenger, Passenger_CompareId, 0);
		                    controller_ListPassenger(pArrayListPassenger);
		                    printf("\nPasajeros ordenados por Id descendente con exito\n");
		                    break;
		            case 3:
		                    ll_sort(pArrayListPassenger, Passenger_CompareNames, 1);
		                    controller_ListPassenger(pArrayListPassenger);
		                    printf("\nPasajeros ordenados por Nombre A->Z con exito\n");
		                    break;
		            case 4:
		                    ll_sort(pArrayListPassenger, Passenger_CompareNames, 0);
		                    controller_ListPassenger(pArrayListPassenger);
		                    printf("\nPasajeros ordenados Por Nombre Z->A con exito\n");
		                    break;
		            case 5:
		                    ll_sort(pArrayListPassenger, Passenger_CompareLastName, 1);
		                    controller_ListPassenger(pArrayListPassenger);
		                    printf("\nPasajeros ordenados Por Apellido A->Z  con exito\n");
		                    break;
		            case 6:
		                    ll_sort(pArrayListPassenger, Passenger_CompareLastName, 0);
		                    controller_ListPassenger(pArrayListPassenger);
		                    printf("\nPasajeros ordenados Por Apellido Z->A con exito\n");
		                    break;
		            case 7:
		            		ll_sort(pArrayListPassenger, Passenger_ComparePrices, 1);
		            		controller_ListPassenger(pArrayListPassenger);
		                    printf("\nPasajeros ordenados por Precio (ascendente) con exito\n");
		                    break;
		            case 8:
		            		ll_sort(pArrayListPassenger, Passenger_ComparePrices, 0);
		            		controller_ListPassenger(pArrayListPassenger);
		            		printf("\nPasajeros ordenados por Precio (descendente) con exito\n");
		                    break;
		            case 9:
		            		ll_sort(pArrayListPassenger, Passenger_CompareType, 1);
		            		controller_ListPassenger(pArrayListPassenger);
		            		printf("\nPasajeros ordenados por Tipo (ascendente) con exito\n");
		            		break;
		            case 10:
		            		ll_sort(pArrayListPassenger, Passenger_CompareType, 1);
		            		controller_ListPassenger(pArrayListPassenger);
		            		printf("\nPasajeros ordenados por Tipo (descendente) con exito\n");
		            		break;
		            case 11:
		            		ll_sort(pArrayListPassenger, Passenger_CompareCod, 1);
		            		controller_ListPassenger(pArrayListPassenger);
		            		printf("\nPasajeros ordenados por Codigo (ascendente) con exito\n");
		            		break;
		            case 12:
		            		ll_sort(pArrayListPassenger, Passenger_CompareCod, 1);
		            		controller_ListPassenger(pArrayListPassenger);
		            		printf("\nPasajeros ordenados por Codigo (descendente) con exito\n");
		            		break;
		        }
		    }
	    return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pFile;
	Passenger* pasajero;

	int length;
	int respuesta = 0;
	int i;
	char auxNombre[20];
	char auxApellido[20];
	char auxCod[20];
	int auxTipo;
	int auxId;
	float auxPrecio;

	    if(path != NULL && pArrayListPassenger != NULL)
	    {
	        pFile = fopen(path, "w");
	        if(pFile != NULL)
	        {
	            length = ll_len(pArrayListPassenger);
	            fprintf(pFile, "id,nombre,apellido,precio,tipo,codVuelo\n");

	            for(i=0; i<length ;i++)
	            {
	                pasajero = (Passenger*)ll_get(pArrayListPassenger,i);
	                Passenger_getId(pasajero, &auxId);
	                Passenger_getNombre(pasajero, auxNombre);
	                Passenger_getApellido(pasajero, auxApellido);
	                Passenger_getPrecio(pasajero, &auxPrecio);
	                Passenger_getTipoPasajero(pasajero, &auxTipo);
	                Passenger_getCodigoVuelo(pasajero, auxCod);
	                fprintf(pFile,"%d,%s,%s,%.2f,%d,%s\n", auxId, auxNombre, auxApellido, auxPrecio, auxTipo, auxCod);
	            }
	            fclose(pFile);
	        }
	        respuesta = 1;
	    }
	    return respuesta;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
		FILE* pFile;
		Passenger* pasajero;

		int respuesta = 0;
		int i;
		int length;

		    if(path!=NULL && pArrayListPassenger!=NULL)
		    {
		        pFile=fopen(path,"wb");

		        if(pFile!=NULL)
		        {
		            length=ll_len(pArrayListPassenger);

		            for(i=0;i<length;i++)
		            {
		                pasajero = (Passenger*)ll_get(pArrayListPassenger,i);
		                fwrite(pasajero,sizeof(Passenger),1,pFile);
		            }

		            fclose(pFile);
		        }
		        respuesta = 1;
		    }
		    return respuesta;
}

