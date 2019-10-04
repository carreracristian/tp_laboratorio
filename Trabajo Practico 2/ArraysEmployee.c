#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArraysEmployee.h"
#define LIBRE 0
#define OCUPADO 1

eEmpleado ingresarSoloUnEmpleado()
{
    eEmpleado empleadoRetorno;
    printf("\n");
    getSoloLetras("Ingrese el nombre del empleado: ", empleadoRetorno.nombre);
    getSoloLetras("Ingrese el apellido del empleado: ", empleadoRetorno.apellido);
    empleadoRetorno.sector = getSoloEnteros("Ingrese el sector del empleado: ");
    empleadoRetorno.salario = getSoloFlotantes("Ingrese el salario del empleado: ");
    empleadoRetorno.estado = OCUPADO;

    return empleadoRetorno;
}
void mostrarSoloUnEmpleado(eEmpleado unEmpleado)
{
    printf("%10d %15s %15s %15.2f %10d\n", unEmpleado.id, unEmpleado.apellido, unEmpleado.nombre, unEmpleado.salario, unEmpleado.sector);
}
void inicializarvecEmpleados(eEmpleado vec[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        vec[i].estado = LIBRE;
        vec[i].id = 0;
        vec[i].salario = 0;
        vec[i].sector = 0;
        strcpy(vec[i].nombre, "");
        strcpy(vec[i].apellido, "");
    }
}
void mostrarvecEmpleados(eEmpleado vec[], int tam)
{
    int i;

    printf("\n        ID        APELLIDO          NOMBRE         SALARIO     SECTOR\n");

    for(i=0; i<tam; i++)
    {
        if(vec[i].estado == OCUPADO)
        {
            mostrarSoloUnEmpleado(vec[i]);
        }
    }

    printf("\n");
}
int generarId(eEmpleado vec[], int tam)
{
    int i;
    int idParaRetornar;

    idParaRetornar = 0;

    for(i=0; i<tam; i++)
    {
        if(vec[i].estado == OCUPADO)
        {
                if(vec[i].id > idParaRetornar)
                {
                    idParaRetornar = vec[i].id;
                }
        }
    }

    return (idParaRetornar+1);
}

int buscarEmpleadoPorId(eEmpleado vec[], int tam, int id)
{
    int i;
    int retorno;

    retorno = -1;

    for(i=0; i<tam; i++)
    {
        if( (vec[i].estado == OCUPADO) && (vec[i].id == id) )
        {
            retorno = i;
            break;
        }
    }

    return retorno;
}
int buscarLugarLibre(eEmpleado vec[], int tam)
{
    int i;
    int indice;

    indice = -1;

    for(i=0; i<tam; i++)
    {
        if(vec[i].estado == LIBRE)
        {
            indice = i;
            break;
        }
    }

    if(indice == -1)
    {
        printf("\nNo hay espacio.\n\n");
    }

    return indice;
}

int darDeAltaEmpleado(eEmpleado vec[], int tam)
{
    int indice;
    int id;

    indice = buscarLugarLibre(vec, tam);
    id = generarId(vec, tam);

    if(indice >= 0)
    {
        vec[indice] = ingresarSoloUnEmpleado();
        vec[indice].id = id;
        printf("\nPara el empleado: %s.\nSu id es: %d\n\n", vec[indice].nombre, vec[indice].id);
    }

    return indice;
}
int darDeBajaEmpleado(eEmpleado vec[], int tam)
{
    int id;
    int opcion;
    int retorno;
    int indice;

    retorno = 0;

    mostrarvecEmpleados(vec,tam);
    id = getSoloEnteros("\nIngrese el id del empleado a dar de baja: ");
    indice = buscarEmpleadoPorId(vec,tam,id);

    if(indice >= 0)
    {
            retorno = 1;
            opcion = getSoloEnteros("\nDar de baja al empleado? (1 = SI / 0 = NO): ");

            if(opcion == 1)
            {
                vec[indice].estado = LIBRE;
                vec[indice].id = 0;
                printf("\nEmpleado dado de baja exitosamente.\n\n");
            }
            else
            {
                if(opcion == 0)
                {
                    printf("\nBaja de empleado cancelada.\n\n");
                }
                else
                {
                    printf("\nOpcion invalida.\n\n");
                }
            }
    }

    if(retorno == 0)
    {
        printf("\nId inexistente.\n\n");
    }

    return retorno;
}

int modificarEmpleado(eEmpleado vec[], int tam)
{
    int id;
    int opcion;
    int retorno;
    int indice;
    char auxNombre[50];
    char auxApellido[50];
    float auxSalario;
    int auxSector;

    retorno = 0;

    mostrarvecEmpleados(vec,tam);
    id = getSoloEnteros("\nIngrese el id del empleado modificar: ");
    indice = buscarEmpleadoPorId(vec,tam,id);

    if(indice >= 0)
    {
            retorno = 1;
            opcion = getSoloEnteros("\nQue desea modificsr?\n\n1. Nombre.\n2. Apellido.\n3. Salario.\n4. Sector\n\nOpcion: ");

            switch(opcion)
            {
                case 1:
                    getSoloLetras("\nIngrese nuevo nombre: ", auxNombre);
                    strcpy(vec[indice].nombre, auxNombre);
                    printf("\nModificacion exitosa.\n\n");
                    break;

                case 2:
                    getSoloLetras("\nIngrese nuevo apellido: ", auxApellido);
                    strcpy(vec[indice].apellido, auxApellido);
                    printf("\nModificacion exitosa.\n\n");
                    break;

                case 3:
                    auxSalario = getSoloFlotantes("\nIngrese nuevo salario: ");
                    vec[indice].salario = auxSalario;
                    printf("\nModificacion exitosa.\n\n");
                    break;

                case 4:
                    auxSector = getSoloEnteros("\nIngrese nuevo sector: ");
                    vec[indice].sector = auxSector;
                    printf("\nModificacion exitosa.\n\n");
                    break;

                default:
                    printf("\nOpcion invalida\n\n");
                    break;
            }
    }

    if(retorno == 0)
    {
        printf("\nId inexistente.\n\n");
    }

    return retorno;
}

void ordenarvecPorApellidoySector(eEmpleado vec[], int tam)
{
    int i, j;
    eEmpleado auxiliar;

    for(i=0; i<tam; i++)
    {
        for(j=0; j<tam-1; j++)
        {
            if(stricmp(vec[i].apellido, vec[j].apellido) == -1)
            {
                auxiliar = vec[i];
                vec[i] = vec[j];
                vec[j] = auxiliar;
            }
            else
            {
                if(stricmp(vec[i].apellido, vec[j].apellido) == 0)
                {
                    if(vec[i].sector < vec[j].sector)
                    {
                        auxiliar = vec[i];
                        vec[i] = vec[j];
                        vec[j] = auxiliar;
                    }
                }
            }
        }
    }
}

void informarSalarios(eEmpleado vec[], int tam)
{
    int i;
    float acumuladorSalarios = 0;
    float promedioSalarios = 0;
    int contadorSalarios = 0;
    int contadorSalariosMayores = 0;

    for(i=0; i<tam; i++)
    {
        if(vec[i].estado == OCUPADO)
        {
            acumuladorSalarios = acumuladorSalarios + vec[i].salario;
            contadorSalarios++;
        }
    }

    promedioSalarios = (acumuladorSalarios) / (contadorSalarios);

    for(i=0; i<tam; i++)
    {
        if( (vec[i].estado == OCUPADO) && (vec[i].salario > promedioSalarios) )
        {
            contadorSalariosMayores++;
        }
    }

    printf("\nTotal de salarios: %.2f", acumuladorSalarios);
    printf("\nPromedio: %.2f", promedioSalarios);
    printf("\nCantidad de empleados con salario mayor al promedio: %d\n\n", contadorSalariosMayores);
}

void informarEmpleados(eEmpleado vec[], int tam)
{
    int opcion;

    opcion = menu("\n1. Empleados ordenados por apellido y sector:\n2. Total y promedio de salarios:\n\nOpcion: ");

    switch(opcion)
    {
        case 1:
            ordenarvecPorApellidoySector(vec, tam);
            mostrarvecEmpleados(vec, tam);
            break;
        case 2:
            mostrarvecEmpleados(vec, tam);
            informarSalarios(vec, tam);
            break;
        default:
            printf("\nOpcion invalida.\n\n");
            break;
    }

}

void hardcodearEmpleados(eEmpleado vec[], int tam)
{
    int id[5] = {1,2,3,4,5};
    char nombre[5][50] = {"Jose","Valeria","Pablo","Alejandro","Manuela"};
    char apellido[5][50] = {"Arellano","Romero","Gutierrez","Hernandez","Ahumada"};
    float salario[5] = {10000,11000,12000,13000,14000};
    int sector[5] = {12,4,8,2,16};
    int i;

    for(i=0; i<5; i++)
    {
        vec[i].id = id[i];
        strcpy(vec[i].nombre, nombre[i]);
        strcpy(vec[i].apellido, apellido[i]);
        vec[i].salario = salario[i];
        vec[i].sector = sector[i];
        vec[i].estado = OCUPADO;
    }
}

