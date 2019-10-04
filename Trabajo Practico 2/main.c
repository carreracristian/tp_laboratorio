#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArraysEmployee.h"

#define T 1000

int main()
{
    int opcion;
    int empleadoIngresado = 0;
    eEmpleado empleados[T];
    inicializarvecEmpleados(empleados,T);

    hardcodearEmpleados(empleados,T);

    do
    {
        opcion = menu("1. ALTA.\n2. BAJA.\n3. MODIFICACION.\n4. INFORMES.\n5. SALIR\n\nOpcion: ");

        switch(opcion)
        {
            case 1:
                darDeAltaEmpleado(empleados, T);
                empleadoIngresado = 1;
                break;
            case 2:
                if(empleadoIngresado == 1)
                {
                    darDeBajaEmpleado(empleados, T);
                }
                else
                {
                    printf("\nPrimero debe ingresar un empleado.\n\n");
                }
                break;
            case 3:
                if(empleadoIngresado == 1)
                {
                    modificarEmpleado(empleados, T);
                }
                else
                {
                    printf("\nPrimero debe ingresar un empleado.\n\n");
                }
                break;
            case 4:
                if(empleadoIngresado == 1)
                {
                    informarEmpleados(empleados, T);
                }
                else
                {
                    printf("\nPrimero debe ingresar un empleado.\n\n");
                }
                break;
            case 5:
                printf("\nSalida exitosa.\n\n");
                break;
            default:
                printf("\nOpcion invalida.\n\n");
                break;
        }

        system("pause");
        system("cls");

    } while(opcion!=5);

    return 0;
}
