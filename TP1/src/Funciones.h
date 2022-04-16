#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


/**
 * @fn void MenuOpciones(char[], char[], char[], char[], char[], char[])
 * @brief --> Recibe varias cadenas de caracteres "mensajes" introducidos en el main para poder mostrar el menu de opciones.
 *
 * @param mensaje1 --> Primer mensaje a mostrar.
 * @param mensaje2 --> Segundo mensaje a mostrar.
 * @param mensaje3 --> Tercer mensaje a mostrar.
 * @param mensaje4 --> Cuarto mensaje a mostrar.
 * @param mensaje5 --> Quinto mensaje a mostrar.
 * @param mensaje6 --> Sexto mensaje a mostrar.
 * @param mensaje7 --> Septimo mensaje a mostrar.
 */
void MenuOpciones(char mensaje1[], char mensaje2[], char mensaje3[], char mensaje4[], char mensaje5[], char mensaje6[], char mensaje7[]);

/**
 * @fn int ValidarInt(char cadenaValidar[])
 * @brief --> Valida que la cadena de caracteres sea numerica entera.
 * @param cadenaValidar --> Cadena de caracteres a validar.
 * @return --> Devuelve 1 si la cadena es solo numerica y entera, de lo contrario retorna 0.
 */
int ValidarInt(char cadenaValidar[]);

/**
 * @fn int ValidarInt(char validFloat[])
 * @brief --> Valida que la cadena de caracteres sea numerica flotante.
 * @param validFloat --> Cadena de caracteres a validar.
 * @return --> Devuelve 1 si la cadena es solo numerica flotante, de lo contrario retorna 0.
 */
int ValidarFloat(char validFloat[]);

/**
 * @fn ParseInt(char stringData[])
 * @brief --> Parsea una cadena a entero.
 * @param stringData --> Cadena a parsear a entero.
 * @return --> Retorna la cadena parseada a entero.
 */
int ParseInt(char stringData[]);

/**
 * @fn ValidarRangoInt(char stringData[], int rango)
 * @brief --> Valida que el la cadena entera y se encuentre entre un rango especifico (llama a la funcion ParseFloat)
 * @param stringData --> Cadena de caracteres a parsear a entero.
 * @param rango --> Rango a validar.
 * @return --> Retorna si la cadena recibida cumple la condicion de estar dentro del rango establecido.
 */
int ValidarRangoInt(char stringData[], int rango);

/**
 * @fn int MenuSecundario(char mensaje1[], char mensaje2[], char mensaje3[], float* pY, float* pZ, int* pBanderaAerolineas, int* pBanderaLatam)
 * @brief --> Permite mostrar un menu secundario para la obtencion de precios de ambas aerolineas, recibe mensajes, punteros para el guardado de datos y banderas.
 * @param mensaje1 --> Primer mensaje a mostrar.
 * @param mensaje2 --> Segundo mensaje a mostrar.
 * @param mensaje3 --> Tercer mensaje a mostrar.
 * @param pY --> Primer puntero que guarda la direccion de memoria de la variable en que almacena el valor ingresado del precio de Aerolineas Argentinas.
 * @param pZ --> Segundo puntero que guarda la direccion de memoria de la variable en que almacena el valor ingresado del precio de LATAM.
 * @param pBanderaAerolineas --> Puntero que guarda el estado, si es que se encuentra cargado el primer dato.
 * @param pBanderaLatam --> Puntero que guarda el estado, si es que se encuentra cargado el segundo dato.
 */
void MenuSecundario(char mensaje1[], char mensaje2[], char mensaje3[], float* pY, float* pZ, int* pBanderaAerolineas, int* pBanderaLatam);

/**
 * @fn int ValidarIngreso(char stringImput[], int cantidadOpciones)
 * @brief --> Valida que la opcion se encuentre en un rango especifico.
 * @param stringImput --> Cadena que almacena el valor ingresado.
 * @param cantidadOpciones --> Rango de opciones a utilzar.
 * @return --> Retorna 1 si cumple la condicion del rango, de lo contrario retorna 0.
 */
int ValidarIngreso(char stringImput[], int cantidadOpciones);

/**
 * @fn float ParseFloat(char stringData[])
 * @brief --> Parsea una cadena a flotante.
 * @param stringData --> Cadena a parsear.
 * @return --> Retorna la cadena ya parseada.
 */
float ParseFloat(char stringData[]);

/**
 * @fn GetNum(char mensajeIngreso[], char mensajeError[])
 * @brief --> Permite la obtencion y validacion de un numero flotante al usuario.
 * @param mensajeIngreso --> El mensaje a mostrar al usuario.
 * @param mensajeError --> Un mensaje de error en caso de que no se cumpla con lo pedido.
 * @return --> Retorna el numero flotante ingresado por el usuario.
 */
float GetNum(char mensajeIngreso[], char mensajeError[]);

/**
 * @fn void MostrarDatos(float* dato2, float* dato3)
 * @brief --> Permite mostrar los datos ingresados por el usuario en el menu de opciones.
 * @param dato2 --> Puntero a la variable que almacena el dato de Aerolineas.
 * @param dato3 --> Puntero a la variable que almacena el dato de LATAM.
 */
void MostrarDatos(float* dato2, float* dato3);

/**
 * @fn float CalcularDescuento(float dato)
 * @brief --> Permite calcular el descuento especificado por la consigna.
 * @param dato --> Dato al cual calcularle el descuento.
 * @return --> Retorna el valor actual del dato menos el descuento calculado.
 */
float CalcularDescuento(float dato);

/**
 * @fn float CalcularInteres(float dato)
 * @brief --> Permite calcular los interes especificados en la consigna.
 * @param dato --> Dato al cual calcularle el interes.
 * @return -->  Retorna el valor actual del dato mas el impuesto calculado.
 */
float CalcularInteres(float dato);

/**
 * @fn PrecioEnBitcoins(float dato)
 * @brief --> Permite calcular el valor ingresado en su equivalente en Bitcoins.
 * @param dato --> Dato al cual calcularle el valor en Bitcoins.
 * @return --> El valor en Bitcoins del dato ingresado;
 */
float PrecioEnBitcoins(float dato);

/**
 * @fn float PrecioPorKm(float dato, float km)
 * @brief --> Permite calcular el precio unitario por Km.
 * @param dato --> Dato al cual calcularle el precio unitario.
 * @param km --> Cantidad de Km ingresados.
 * @return --> El precio actual unitario por Km ingresado.
 */
float PrecioPorKm(float dato, float km);

/**
 * @fn float DiferenciaPrecio(float dato, float dato2)
 * @brief --> Calcula la diferencia de precios que existe entre ambas Aerolineas (LATAM - Aerolineas).
 * @param dato --> Precio actual de Aerolineas Argentinas.
 * @param dato2 --> Precio actual de LATAM.
 * @return --> La diferencia entre precios de amnbos
 */
float DiferenciaPrecio(float dato, float dato2);

