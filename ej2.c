#include <stdio.h>
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
}typedef viaje;


fS IngresarFechaSalida();

int main(){
    IngresarFechaSalida();
    return 0;
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
                    printf("fecha ingresada con exito");
                    
                } else {
                    printf("fecha no valida");
                }
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                if (fechaSalida.dia > 1 && fechaSalida.dia <= 30)
                {
                    printf("fecha ingresada con exito");
                } else {
                    printf("fecha no valida");
                }
                break;
            case 2:
                if (fechaSalida.dia > 1 && fechaSalida.dia <= 28)
                {
                    printf("fecha ingresada con exito");
                } else {
                    printf("fecha no valida");
                }
                break;
        }
    } else {
        printf("Anio no valido");
    }
    return fechaSalida;
}