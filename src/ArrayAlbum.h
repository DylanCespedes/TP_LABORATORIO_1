/*
 * albunes.h
 *
 *  Created on: 1 may. 2022
 *      Author: nicoC
 */

#ifndef ARRAYALBUM_H_
#define ARRAYALBUM_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define T 51
#define TRUE 1
#define FALSE 0
#define TAMA 4


typedef struct
{
	int IdGenero;
	char descripcionGen[T];
	int isEmpty;

}eGenero;

typedef struct
{
	int IdArtista;
	char nombre[T];
	int isEmpty;

}eArtista;

typedef struct
{
	int IdTipo;
	char descripcionTipo[T];
	int isEmpty;

}eTipoArtista;

typedef struct
{
	int IdAlbum;
	char titulo[T];
	char fecha[T];
	float importe;
	int generoId;
	int tipoId;
	int artistaId;
	int IsEmpty;
}eAlbum;

void HardcodearGenero(eGenero listaGeneros[], int idIncrementalGenero, int tam);
void HardcodearArtista(eArtista listaArtista[], int idIncrementalArtista, int tam);
void HardcodearTipoArtista(eTipoArtista listaTipoArtista[], int idIncrementalTipo, int tam);
int FindAlbumById(eAlbum listaAlbum[], int tam, int datoId);
void InicializarAlbumes(eAlbum listaAlbum[], int tam);
void AddOneAlbum(eAlbum listaAlbum[], int tam, int IdIncrementalAlbum);
void PrintAlbum(eAlbum listaAlbum[], int tam);
eAlbum AddAlbum(int IdIncrementalAlbum);
void ModifyAlbum(eAlbum listaAlbum[], int idMinimaAlbum, int idMinimaGenero, int idMinimaTipo, int idMinimaArtista, int tam);
int BuscarIdMaxima(eAlbum listaAlbum[], int tam);
void DeleteAlbum(eAlbum listaAlbum[], int idMinimaAlbum, int tam);
void PrintTipoArtista(eTipoArtista *listaTipoArtista, int tam);

#endif /* ARRAYALBUM_H_ */
