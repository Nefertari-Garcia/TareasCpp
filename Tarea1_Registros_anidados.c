#include <stdio.h>
#include <time.h>
#define length 5

typedef struct Fecha
{
    unsigned int mes, dia, anyo;

} Fechas;

struct Agenda
{
    char nombre[30];
    char domicilio[30];
    char telefono[10];
    char correo[20];
    Fechas fecha_de_nacimiento;
} Agendas[length];

int main()
{
    struct Agenda personas[5];
    int opcion;
    printf("MENÚ - AGENDA\n");
    printf("1.  ALTAS\n");
    printf("2.  CONSULTAS GENERALES\n");
    printf("3.  CONSULTA INDIVIDUAL\n");
    printf("4.  SALIR\n");
    printf("ELIGE TU OPCIÓN:\n");

    do
    {

        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            for (int i = 0; i < length; i++)
            {
                fflush(stdin);
                printf("\n--------------ALTA %d--------------\n", i);
                printf("Ingresa tu nombre: \n");
                scanf("%s", &Agendas[i].nombre);
                printf("Ingresa tu domicilio: \n");
                scanf("%s", &Agendas[i].domicilio);
                printf("Ingresa tu telefono: \n");
                scanf("%s", &Agendas[i].telefono);
                printf("Ingresa tu correo: \n");
                scanf("%s", &Agendas[i].correo);
                printf("Ingresa tu fecha de nacimiento dia): \n");
                scanf("%d", &Agendas[i].fecha_de_nacimiento.dia);
                printf("Ingresa tu fecha de nacimiento mes: \n");
                scanf("%d", &Agendas[i].fecha_de_nacimiento.mes);
                printf("Ingresa tu fecha de nacimiento año: \n");
                scanf("%d", &Agendas[i].fecha_de_nacimiento.anyo);
                printf("--------------ALTA EXITOSA--------------");
            }
            break;

        case 2:
            for (int i = 0; i < length; i++)
            {

                printf("\n--------------CONSULTAS GENERALES--------------\n");
                printf("Nombre: %s\n", Agendas[i].nombre);
                printf("Domicilio: %s\n", Agendas[i].domicilio);
                printf("Telefono: %s\n", Agendas[i].telefono);
                printf("Correo: %s\n", Agendas[i].correo);
                printf("Fecha de nacimiento: %02u/%02u/%04u\n",
                       Agendas[i].fecha_de_nacimiento.dia,
                       Agendas[i].fecha_de_nacimiento.mes,
                       Agendas[i].fecha_de_nacimiento.anyo);
                printf("\n--------------CONSULTAS GENERALES EXITOSAS--------------\n");
            }

            break;
        case 3:
            int individual;
            printf("\n--------------CONSULTAS INDIVIDUALES--------------\n");
            printf("A quien te gustaria consultar\n");
            scanf("%d", &individual);
            printf("Nombre: %s\n", Agendas[individual].nombre);
            printf("Domicilio: %s\n", Agendas[individual].domicilio);
            printf("Telefono: %s\n", Agendas[individual].telefono);
            printf("Correo: %s\n", Agendas[individual].correo);
            printf("Fecha de nacimiento: %02u/%02u/%04u\n",
                   Agendas[individual].fecha_de_nacimiento.dia,
                   Agendas[individual].fecha_de_nacimiento.mes,
                   Agendas[individual].fecha_de_nacimiento.anyo);
            printf("\n--------------CONSULTAS INDIVIDUALES EXITOSAS--------------\n");
            break;
        default:
            break;
        }
    } while (opcion != 4);
};
