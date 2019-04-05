#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

float primerNumero(void){
    float numero1;

    printf("Ingrese el primer numero: ");
    scanf("%f",&numero1);
    fflush(stdin);

    return numero1;
}
float segundoNumero (void){
    float numero2;

    printf("Ingrese el segundo numero: ");
    scanf("%f",&numero2);
    fflush(stdin);

    return numero2;
}
float suma(float numUno,float numDos){

    float sumar;

    sumar=numUno+numDos;
    printf("* La suma de %.3f + %.3f es de: %.3f\n\n",numUno,numDos,sumar);

    return sumar;

}
float resta(float numUno,float numDos){

    float restar;

    restar=numUno-numDos;
    printf("* La resta de %.3f - %.3f es de: %.3f\n\n",numUno,numDos,restar);

    return restar;
}
float multiplicacion(float numUno,float numDos){

    float multiplicar;

    multiplicar=numUno*numDos;
    printf("* La multiplicacion de %.3f * %.3f es de: %.3f\n\n",numUno,numDos,multiplicar);

    return multiplicar;
}
float division(float numUno,float numDos){

    float dividir;

    if (numDos!=0){
        dividir=numUno/numDos;
        printf("* La division de %.3f / %.3f es de: %.3f\n\n",numUno,numDos,dividir);
    }
    else{
        printf("* ERROR: no se puede dividir por 0\n\n");
    }
    return dividir;
}
float factorial(float numUno, float numDos){
    float factorialA;
    float factorialB;
    float primerFactorial;
    float segundoFactorial;

    factorialA=1;
    factorialB=1;

    if (numUno>=0){
        for (primerFactorial=numUno; primerFactorial>1; primerFactorial--){
            factorialA=factorialA*primerFactorial;
        }
        printf("* El factorial de A %.3f es: %.3f\n\n",numUno,factorialA);
    }
    else
        printf("* No puede operar un numero negativo\n");

    if (numDos>=0){
        for (segundoFactorial=numDos; segundoFactorial>1; segundoFactorial--){
            factorialB=factorialB*segundoFactorial;
        }

        printf("* El factorial de B %.3f es: %.3f\n",numDos,factorialB);
    }
    else
        printf("* No puede operar un numero negativo\n");

    return factorialA;
}
