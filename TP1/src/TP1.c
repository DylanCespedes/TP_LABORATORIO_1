/*
 ============================================================================
Dylan Rafael Cespedes 1F
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

int main(void) {

	setbuf(stdout,NULL);

	MenuOpciones("\nBienvenidos al sistema de ingreso\n\n",
				 "\n1)Ingresar kilometros del vuelo: ",
				 "\n2)Ingresar el precio del vuelo de Aerolineas Argentinas y LATAM: ",
				 "\n3)Calcular todo los costos",
				 "\n4)Informar resultados",
				 "\n5)Carga forzada de datos",
				 "\n6)Salir");

}
