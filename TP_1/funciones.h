#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

/** Suma dos numeros enteros y guarda el resultado de la operacion en resultado
 *
 * Si no hubo errores devuelve 0.
 * En caso de error de overflow devuelve -1.
 */
int sumarEnteros(int primerNumero, int segundoNumero, float* resultado);

/** Resta dos numeros enteros y guarda el resultado de la operacion en resultado
 *
 * Si no hubo errores devuelve 0.
 * En caso de error de overflow devuelve -1.
 */
int restarEnteros(int primerNumero, int segundoNumero, float* resultado);

/** Divide dos numeros enteros y guarda el resultado de la operacion en resultado
 *
 * Si no hubo errores devuelve 0.
 * En caso de dar error al querer dividir por 0, devuelve -1.
 */
int dividirEnteros(int primerNumero, int segundoNumero, float* resultado);

/** Multiplica dos numeros enteros y guarda el resultado de la operacion en resultado
 *
 * Si no hubo errores devuelve 0.
 * En caso de error de overflow devuelve -1.
 */
int multiplicarEnteros(int primerNumero, int segundoNumero, float* resultado);


#endif // FUNCIONES_H_INCLUDED
