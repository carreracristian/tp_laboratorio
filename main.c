#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

float primerNumero(void);
float segundoNumero(void);
float suma(float numUno, float numDos);
float resta(float numUno, float numDos);
float multiplicacion(float numUno, float numDos);
float division(float numUno, float numDos);
float factorial(float numUno, float numDos);
int main(){
	int numeroUno;
	int numeroDos;
	int opc;
	int continuar='s';

	do{
		printf("\n1. Ingresar primer operador (A=x).\n2. Ingresar segundo operador (B=y).\n3. Calcular todas las operaciones.\n4. Informar resultados.\n5. Salir.\nOpciones: ");
		scanf("%d",&opc);
		fflush(stdin);

		switch(opc){
			case 1:
                system("cls");
                numeroUno=primerNumero();
                system("pause");
                fflush(stdin);
                break;
			case 2:
			    system("cls");
                numeroDos=segundoNumero();
                system("pause");
                fflush(stdin);
                break;
			case 3:
			    system("cls");
			    printf("\nCalculando operaciones, ingresar opcion 4 para ver resultados");
			    printf("\nLa suma de:%3f + %3f",numeroUno,numeroDos);
                printf("\nLa resta de:%3f - %.3f",numeroUno,numeroDos);
                printf("\nLa multiplicacion de:%3f * %.3f",numeroUno,numeroDos);
                printf("\nLa divicion de:%3f / %.3f",numeroUno,numeroDos);
                printf("\nEl factorial de:%3f y %.3f",numeroUno,numeroDos);
                system("pause");
                break;
            case 4:
                printf("\nLos resultados son:\n");

                suma(numeroUno,numeroDos);
                resta(numeroUno,numeroDos);
                multiplicacion(numeroUno,numeroDos);
                division(numeroUno,numeroDos);
                factorial(numeroUno,numeroDos);
                break;
			case 5:
                printf("\nPresione enter para cerrar la consola... \n");
                continuar='n';
                break;
			default:printf("Opcion incorrecta");
		}

	}while(continuar=='s');

	return 0;
}

