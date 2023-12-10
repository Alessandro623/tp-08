#include <stdio.h>
#include <stdlib.h>
#define MAX 100
struct
{
    int dia;
    int mes;
    int anio;
}typedef fS;

struct
{
    int dia;
    int mes;
    int anio;
}typedef fR;

struct
{
    char apellido[MAX];
    char nombre[MAX];
    int dni[10];
}typedef datosPersonales;

struct
{
    char destino;
    datosPersonales persona1;
    fS fechaSalida;
    fR fechaRegreso;
    float precio;
    int habReservadas;
    int *numeroHabReservadas;
} typedef viaje;


fS IngresarFechaSalida();
fR IngresarFechaRegreso();
viaje cargarViaje();
void mostrarViajes(viaje unViaje);

int main(){
    int viajes;
    printf("cuantos viajes desea reservar?= ");
    scanf("%d", &viajes);
    fflush(stdin);
    while (viajes <= 0)
    {
        printf("Porfavor ingrese un valor valido de viajes=");
        scanf("%d", &viajes);
        fflush(stdin);
    }

    for (int i = 0; i < viajes; i++)
    {
        viaje unViaje = cargarViaje();
        mostrarViajes(unViaje);
    }
    
}


void mostrarViajes(viaje unViaje)
{
    printf("\nInformación del Viaje:\n");
    printf("Destino del viaje: %c\n", unViaje.destino);
    printf("Apellido del guia: %s\n", unViaje.persona1.apellido);
    printf("Nombre del guia: %s\n", unViaje.persona1.nombre);
    printf("DNI del guia: %d\n", unViaje.persona1.dni);
    printf("Fecha de Salida: %d/%d/%d\n", unViaje.fechaSalida.dia, unViaje.fechaSalida.mes, unViaje.fechaSalida.anio);
    printf("Fecha de Regreso: %d/%d/%d\n", unViaje.fechaRegreso.dia, unViaje.fechaRegreso.mes, unViaje.fechaRegreso.anio);
    printf("Precio del viaje: %.2f\n", unViaje.precio);
    printf("Habitaciones reservadas: %d\n", unViaje.habReservadas);
    printf("Numero de habitaciones reservadas: ");
    for (int i = 0; i < unViaje.habReservadas; i++)
    {
        printf("%d ", unViaje.numeroHabReservadas[i]);
    }
    printf("\n");
}

viaje cargarViaje(){
    viaje nuevoViaje;

    printf("Ingresa el destino del viaje:");
    scanf("%s", &nuevoViaje.destino);
    fflush(stdin);
    printf("Ingrese los datos del guia:\n");
    printf("Apellido: ");
    gets(nuevoViaje.persona1.apellido);
    fflush(stdin);
    printf("Nombre: ");
    gets(nuevoViaje.persona1.nombre);
    fflush(stdin);
    printf("DNI: ");
    scanf("%d", &nuevoViaje.persona1.dni);

    printf("Ingrese la fecha de salida:\n");
    nuevoViaje.fechaSalida = IngresarFechaSalida();
    nuevoViaje.fechaRegreso = IngresarFechaRegreso();

    fflush(stdin);
    printf("Ingrese el precio del viaje: ");
    scanf("%f", &nuevoViaje.precio);

    printf("Ingrese la cantidad de habitaciones reservadas: ");
    scanf("%d", &nuevoViaje.habReservadas);
    fflush(stdin);
    nuevoViaje.numeroHabReservadas = malloc(nuevoViaje.habReservadas * sizeof(int));
    fflush(stdin);

    for (int i = 0; i < nuevoViaje.habReservadas; i++)
    {
        printf("ingrese los numeros de las habitaciones reservadas: ");
        scanf("%d", &nuevoViaje.numeroHabReservadas[i]);
    }

    return nuevoViaje;
}

fR IngresarFechaRegreso(){
    fR fechaRegreso;
    printf("Ingrese dia, mes y anio en el que Regresara: ");
    scanf("%d", &fechaRegreso.dia);
    scanf("%d", &fechaRegreso.mes);
    scanf("%d", &fechaRegreso.anio);
    if (fechaRegreso.anio >= 2023 && fechaRegreso.anio <= 2025)
    {
        switch (fechaRegreso.mes)
        {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                if (fechaRegreso.dia > 1 && fechaRegreso.dia <= 31)
                {
                    printf("fecha ingresada con exito\n");
                    
                } else {
                    printf("fecha no valida\n");
                }
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                if (fechaRegreso.dia > 1 && fechaRegreso.dia <= 30)
                {
                    printf("fecha ingresada con exito\n");
                } else {
                    printf("fecha no valida\n");
                }
                break;
            case 2:
                if (fechaRegreso.dia > 1 && fechaRegreso.dia <= 28)
                {
                    printf("fecha ingresada con exito\n");
                } else {
                    printf("fecha no valida\n");
                }
                break;
        }
    } else {
        printf("Anio no valido\n");
    }
    return fechaRegreso;
}

fS IngresarFechaSalida(){
    fS fechaSalida;
    printf("Ingrese dia, mes y anio en el que saldra: ");
    scanf("%d", &fechaSalida.dia);
    scanf("%d", &fechaSalida.mes);
    scanf("%d", &fechaSalida.anio);
    if (fechaSalida.anio >= 2023 && fechaSalida.anio <= 2025)
    {
        switch (fechaSalida.mes)
        {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                if (fechaSalida.dia > 1 && fechaSalida.dia <= 31)
                {
                    printf("fecha ingresada con exito\n");
                    
                } else {
                    printf("fecha no valida\n");
                }
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                if (fechaSalida.dia > 1 && fechaSalida.dia <= 30)
                {
                    printf("fecha ingresada con exito\n");
                } else {
                    printf("fecha no valida\n");
                }
                break;
            case 2:
                if (fechaSalida.dia > 1 && fechaSalida.dia <= 28)
                {
                    printf("fecha ingresada con exito\n");
                } else {
                    printf("fecha no valida\n");
                }
                break;
        }
    } else {
        printf("Anio no valido\n");
    }
    return fechaSalida;
}