#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trabajopractico.h"
#define LIBRE 0
#define OCUPADO 1


eEmployee pedirEmpleado()
{
    eEmployee retornarEmpleado;

    getSoloLetras("Ingresar nombre: ", retornarEmpleado.nombre);
    getSoloLetras("Ingresar apellido: ", retornarEmpleado.apellido);
    getSoloLetras("Ingresar sector: ",retornarEmpleado.sector);
    //retornarEmpleado.salario = getSoloFlotantes("Ingresar salario: ");
    printf("Ingresar salario: ");
    scanf("%f",&retornarEmpleado.salario);
    retornarEmpleado.estado = OCUPADO;

    return retornarEmpleado;
}

void mostrarEmpleado(eEmployee unEmpleado)
{
    printf("%12s %16s %11d %15s %12.2f\n\n", unEmpleado.nombre, unEmpleado.apellido, unEmpleado.id, unEmpleado.sector, unEmpleado.salario);
}
void cargarArray(eEmployee listado[], int cant)
{
    int i;
    for(i=0; i<cant; i++)
    {
        listado[i]= pedirEmpleado();
    }
}
void construirArray(eEmployee listado[], int cant)
{
    int i;
    for(i=0; i<cant; i++)
    {
        listado[i].estado= LIBRE;
        listado[i].salario= 0;
        strcpy(listado[i].nombre, "");
        strcpy(listado[i].apellido, "");
        strcpy(listado[i].sector, "");
        listado[i].id = 0;
    }
}
void mostrarArray(eEmployee listado[], int cant)
{
    int i;
    printf("\n        Nombre        Apellido          ID         Sector     Salario\n");

    for(i=0; i<cant; i++)
    {
        if(listado[i].estado==OCUPADO)
        {
            mostrarEmpleado(listado[i]);
        }
    }
}
int crearId(eEmployee listado[], int tam)
{
    int i;
    int retornarId;

    retornarId=0;

    for(i=0;i<tam;i++)
    {
        if(listado[i].estado==OCUPADO)
        {
            if(listado[i].id>retornarId)
            {
                retornarId=listado[i].id;
            }
        }
    }
    return (retornarId+1);
}
int dameLugarLibre(eEmployee listado[], int tam)
{
    int i;
    int index = -1;

    for(i=0; i<tam; i++)
    {
        if(listado[i].estado==LIBRE)
        {
            index = i;
            break;
        }
    }
    return index;
}
int ingresarEmpleado(eEmployee listado[], int cant)
{
    int indice;
    int id;

    indice = dameLugarLibre(listado, cant);
    id = crearId(listado, cant);

    if(indice >= 0)
    {
        listado[indice] = pedirEmpleado();
        listado[indice].id=id;
        printf("\nEl id del empleado %s %s es: %d\n\n", listado[indice].nombre,listado[indice].apellido, listado[indice].id);
    }

    return indice;
}
int borrarEmpleado(eEmployee lista[], int tam)
{


   int i;
   int codigo;
   int loEncontro = 0;

   printf("Ingrese el ID del empleado: ");
   fflush(stdin);
   scanf("%d",&codigo);

   for(i=0; i<tam; i++)
   {
       if(lista[i].id==codigo)
       {
          lista[i].estado = LIBRE;
            loEncontro = 1;
           break;
       }

   }

   if(loEncontro==0)
   {
      printf("ID inexistente!!");
   }

    return 0;
}


int editarEmpleado(eEmployee lista[], int tam)
{
   int i;
   int codigo;
   int loEncontro = 0;
   int opc;

   printf("Ingrese el ID del empleado: ");
   fflush(stdin);
   scanf("%d",&codigo);

   for(i=0; i<tam; i++)
   {
       if(lista[i].id==codigo)
       {
    do
    {
        printf("1.Modificar nombre.\n2.Modificar apellido\n3.Modificar salario\n4.Modificar sector\n5.Salir.\nElija opcion: ");
        scanf("%d", &opc);

        switch(opc)
        {
            case 1:
               printf("Ingrese el nuevo nombre: ");
           scanf("%s",&lista[i].nombre);
            break;
            case 2:
                printf("Ingrese el nuevo apellido: ");
           scanf("%s",&lista[i].apellido);
                break;
            case 3:
                printf("Ingrese el nuevo salario: ");
           scanf("%f", &lista[i].salario);
                break;

            case 4:
                printf("Ingrese el nuevo sector: ");
           scanf("%s", &lista[i].sector);
                break;
        }
    }while(opc!=5);

            loEncontro = 1;
           break;
       }

   }

   if(loEncontro==0)
   {
      printf("ID inexistente!!");
   }

   return 0;
}
void ordenarEmpleados(eEmployee listado[], int tam)
{
    int i,j;
    eEmployee aux;

    for(i=0;i<tam;i++)
    {
        for(j=0;j<tam-1;j++)
        {
            if(strcmp(listado[i].apellido,listado[j].apellido)==-1)
            {
                aux=listado[i];
                listado[i]=listado[j];
                listado[j]=aux;
            }
            else
            {
                if(strcmp(listado[i].apellido,listado[j].apellido)==0)
                {
                    if(strcmp(listado[i].sector,listado[j].sector)==-1)
                    {
                        aux=listado[i];
                        listado[i]=listado[j];
                        listado[j]=aux;
                    }
                }
            }
        }
    }
}
void mostrarSalario(eEmployee listado[], int tam)
{
    int i;
    float sumaSalario=0;
    float promedio=0;
    int contadorDeSalarios=0;
    int salariosMayores=0;

    for(i=0;i<tam;i++)
    {
        if(listado[i].estado==OCUPADO)
        {
            sumaSalario=sumaSalario+listado[i].salario;
            contadorDeSalarios++;
        }
    }
    promedio=(sumaSalario)/(contadorDeSalarios);

    for(i=0;i<tam;i++)
    {
        if(listado[i].estado==OCUPADO && listado[i].salario>promedio)
        {
            salariosMayores++;
        }
    }
    printf("\nLa suma de los salarios es: %.2f",sumaSalario);
    printf("\nEl salario promedio es: %.2f",promedio);
    printf("\nLos empleados con sueldo mayor al promedio son: %d\n\n",salariosMayores);

}
