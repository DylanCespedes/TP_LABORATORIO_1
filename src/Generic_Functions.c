#include "Generic_Functions.h"

void GetStrings(char message[], char aux[], int tam)
{
	char buffer[L];

	printf("%s", message);
	fflush(stdin);
	scanf("%[^\n]", buffer);

	strcpy(aux, buffer);
}


int GetInt(char mensaje[], char messageError[])
{
	char aux[L];
	int auxInt;

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%[^\n]", aux);

	while(ValidarInt(aux) == 0)
			{
				printf ("%s", messageError);
				fflush(stdin);
				scanf("%[^\n]", aux);
			}

	auxInt = TurnIntoInt(aux);

	return auxInt;
}


int GetIntRange(char *mensaje, char *messageError, int min_range, int max_range)
{
	char aux[L];
	int auxInt;

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%[^\n]", aux);

	while((ValidarInt(aux) == 0))
			{
				printf ("%s", messageError);
				fflush(stdin);
				scanf("%[^\n]", aux);
			}

	auxInt = TurnIntoInt(aux);

		while(auxInt < min_range || auxInt > max_range)
		{
			printf ("%s", messageError);
			scanf("%d", &auxInt);
		}

	return auxInt;
}


float GetFloat(char mensaje[], char messageError[])
{
	char aux[L];
	float auxFloat;

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%[^\n]", aux);

	while(ValidarFloat(aux) == 0)
			{
				printf ("%s", messageError);
				fflush(stdin);
				scanf("%[^\n]", aux);
			}

	auxFloat = TurnIntoFloat(aux);
	return auxFloat;
}


char getChar(char mensaje[], char messageError[])
{
	char aux;

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%c", &aux);

	while((Validarchar(aux) == 0) && (aux != 's' || aux != 'n'))
	{
		printf("%s", messageError);
		fflush(stdin);
		scanf("%c", &aux);
	}

	return aux;
}

void Get_OnlyAlphabetStringWithSpaces(char MSJ[], char ERROR_MSJ[], char aux[], int TAM)
{
	char buffer[L];

	printf("%s", MSJ);
	fflush(stdin);
	gets(buffer);

	while (strlen(buffer) > TAM || strlen(buffer) == 0
			|| Validate_OnlyAlphabetWithSpaces(buffer) == 0) {

		if (strlen(buffer) > TAM || strlen(buffer) == 0) {
			printf("ERROR. Fuera de rango -> CARACTERES [MIN]=1 [MAX]=%d.\n",
					TAM);
		} else {
			printf("ERROR. Solo caracteres alfabeticos validos.\n");
		}

		printf("%s", ERROR_MSJ);
		fflush(stdin);
		gets(buffer);
	}

	strcpy(aux, buffer);
}

int eGen_ObtenerID(int Gen_idIncremental)
{
	return Gen_idIncremental += 1;
}

void GetDate(char mensaje[], char mensajeError[], char *aux, int min, int max)
{
	int intAux;
	intAux = GetIntRange(mensaje, mensajeError, min, max);

	sprintf(aux, "%d", intAux);
}


//---------------------------------------------------------------------------------VALIDACIONES--------------------------------------------------------------------------------------------//

int ValidarInt(char numero[])
{
	int i;
	int result;
	int countsign = 0;

	result = 1;

	for (i=0; i<strlen(numero); i++)
	{
		if(numero[i] == '-')
		{
			countsign++;
		}
		else
		 {
			if(!isdigit(numero[i]))
			{
				result = 0;
			}
		 }
	}
	if(countsign > 1)
	  {
		result = 0;
	  }

	return result;
}

char Validarchar(char caracter)
{
	char aux = 0;

	if(isalpha(caracter) != 0)

	{
		aux = caracter;
	}
	return aux;
}

int ValidarFloat(char validfloat[])
{
	int i;
	int countsign = 0;
	int response;
	response = 1;

	for(i=0; i<strlen(validfloat); i++)
	{
		if(validfloat[i] == '.' || validfloat[i] == ',')
		{
			countsign++;
		}
		else
		{
			if(isdigit(validfloat[i]) == 0)
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

int Validate_OnlyAlphabetWithSpaces(char aux[])
{
	int rtn = 1;

	if (strlen(aux) > 0)
	{
		for (int i = 0; i < strlen(aux); i++)
		{
			if (isalpha(aux[i]) == 0) {
				if (isspace(aux[i]) == 0)
				{
					rtn = 0;
					break;
				}
			}
		}
	}
	else
		{
			rtn = 0;
		}

	return rtn;
}

//---------------------------------------------------------------------------------CONVERSION DATOS--------------------------------------------------------------------------------------------//

float TurnIntoFloat(char stringdata[])
{
	float FloatNumber;

		FloatNumber = atof(stringdata);

		return FloatNumber;
}


int TurnIntoInt(char stringdata[])
{
	int IntNumber;

	IntNumber = atoi(stringdata);

	return IntNumber;
}



void ToDate(char *dia, char *mes, char *anio, char *aux)
{
	strcpy(aux, dia);
	strcpy(aux, "/");
	strcpy(aux, mes);
	strcpy(aux, "/");
	strcpy(aux, anio);
}











