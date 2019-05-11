#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define T 100
#include "trabajopractico.h"

int main()
{

    int opcion;
    int empleado;
    int opc;

    empleado=0;

    eEmployee unEmpleado;
    eEmployee listadoEmpleados[T];
    construirArray(listadoEmpleados, T);

    do
    {
        printf("1.ALTA\n2.BAJA\n3.MODIFICAR\n4.Informar\n5.Salir\nElija opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
               ingresarEmpleado(listadoEmpleados, T);
               empleado=1;
            break;
            case 2:
                if(empleado == 1)
                {
                    borrarEmpleado(listadoEmpleados,T);
                }
                else
                {
                    printf("\nDEBE DAR DE ALTA A AL MENOS UN EMPLEADO EN EL SISTEMA.\n\n");
                }
                break;
            case 3:
                if(empleado == 1)
                {
                    editarEmpleado(listadoEmpleados, T);
                }
                else
                {
                    printf("\nDEBE DAR DE ALTA A AL MENOS UN EMPLEADO EN EL SISTEMA.\n\n");
                }
                break;

            case 4:
                if(empleado == 1)
                {
                    printf("1.Mostrar empleados ordenados por apellido y sector\n2.Mostrar informacion de los sueldos\n5.Salir\nElija opcion: ");
                    scanf("%d", &opc);
                    switch(opc)
                    {
                    case 1:
                        ordenarEmpleados(listadoEmpleados,T);
                        mostrarArray(listadoEmpleados,T);
                        break;

                    case 2:
                        mostrarSalario(listadoEmpleados,T);
                        break;
                    }
                }
                else
                {
                    printf("\nPrimero debe ingresar un empleado.\n\n");
                }

                break;
        }
    }while(opcion!=5);

    return 0;
}
