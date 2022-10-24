/*
 ============================================================================
 Name        : Ignacio Pablo Gatti
 File        : 112534
 Date        : 24/10/22
 University  : UTN-FRA
 Exercise    : 0_0
			   PARCIAL N°1 PROGRAMACION
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM_VAC 10

typedef struct{
    int id;
    char nombre[20];
    char tipo;
    float efectividad;
}eVacuna;

float aplicarAumento(float precio);
int reemplazarCaracteres(char vec[], int size, char caracter1, char caracter2);
int ordenarTipoEfectividad(eVacuna lista[], int size);

int main(void){

	setbuf(stdout,NULL);

	eVacuna vacunas[TAM_VAC] = {
	        {1, "Pfizer", 'a', 97},
	        {2, "Sputnik", 'c', 93},
	        {3, "AstraZeneca", 'c', 80},
	        {4, "Moderna", 'a', 85},
	        {5, "Pfizer", 'a', 90},
	        {6, "Sputnik", 'c', 97},
	        {7, "AstraZeneca", 'c', 80},
	        {8, "Moderna", 'a', 61},
	        {8, "Sinopharm", 'c', 87},
	        {8, "Sinopharm", 'a', 65}
	};

	//EJERCICIO N°1
	printf("EJERCICIO N°1: \n");
	float resultado = 0;
	resultado = aplicarAumento(150.5);
	printf("PRECIO AUMENTANDO: %2.f\n\n", resultado);

	//EJERCICIO N°2
	printf("EJERCICIO N°2: \n");
	char cadena[11] = "Hipopotamo";
	int cantidad;
	cantidad = reemplazarCaracteres(cadena, 11, 'o', 'a');
	printf("Cadena: %s\n", cadena);
	printf("Cantidad: %d\n\n", cantidad);

	//EJERCICIO N°3
	printf("EJERCICIO N°3: \n");
	ordenarTipoEfectividad(vacunas, TAM_VAC);
    for(int i = 0; i < TAM_VAC; i++)
    {
        printf("ID: %d   NOMBRE: %s\t    TIPO: %c       EFECTIVIDAD: %.2f\n",vacunas[i].id, vacunas[i].nombre, vacunas[i].tipo, vacunas[i].efectividad);
    }


	return EXIT_SUCCESS;
}

//1. Crear una función llamada aplicarAumento que reciba como parámetro el precio
//de un producto y devuelva el valor del producto con un aumento
//del 5%. Realizar la llamada desde el main.

float aplicarAumento(float precio){
	float resultado;
	float aumento = 5;

	aumento = (aumento * precio) / 100;
	resultado = aumento + precio;

	return resultado;
}

//2. Crear una función que se llame reemplazarCaracteres que reciba
//una cadena de caracteres como primer parámetro, un carácter como segundo y otro
//carácter  como tercero,  la misma deberá reemplazar cada ocurrencia del segundo parámetro
//por el tercero y devolver la cantidad de veces que se reemplazo ese carácter  en la cadena

int reemplazarCaracteres(char vec[], int size, char caracter1, char caracter2){

    int cantSwap = 0;
    if(vec != NULL && size > 0){
        for(int i=0; i < size; i++){
            if(vec[i] == caracter1){
                vec[i] = caracter2;
                cantSwap ++;
            }
        }
    }
    else{
        printf("ERROR");
    }
    return cantSwap;
}

// 3.Dada la siguiente estructura generar una función que permita ordenar un array
// de dicha estructura por tipo. Ante igualdad de tipo deberá ordenarse por efectividad
// creciente. Hardcodear datos y mostrarlos desde el main.
int ordenarTipoEfectividad(eVacuna lista[], int size){
	int todoOk = 0;
	eVacuna auxVacuna;
	if(lista != NULL && size > 0){
		for(int i = 0; i < size-1; i++){
			for(int j = i+1; j < size; j++){
				if(  (lista[i].tipo == lista[j].tipo  && lista[i].efectividad > lista[j].efectividad)
				||   (lista[i].tipo < lista[j].tipo) ){
					auxVacuna = lista[i];
					lista[i] = lista[j];
					lista[j] = auxVacuna;
				}
			}
		}
		todoOk = 1;
	}
	return todoOk;
}
