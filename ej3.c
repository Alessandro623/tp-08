#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
struct
{
    float fecha;
    int hora;
    float monto;
}typedef Movimiento;

struct
{
    int dia;
    int mes;
    int anio;    
}typedef fecNac;

struct 
{   
    int CBU;
    float Saldo;
    Movimiento *historial;
}typedef datosCuenta;

struct 
{
    char Apellido[MAX];
    char Nombre[MAX];
    char Dni[11];
    int contrasenia;
    fecNac Fecha;
    datosCuenta Datos;
    Movimiento movimiento1;
}typedef Cliente;

Cliente cargarClientes();
void mostrarClientes(Cliente clientes[], int numClientes);

int main(){
    int opcion;
    Cliente clientes[2];

    printf("Ingrese la informacion de 2 clientes\n");
    for (int i = 0; i < 2; i++) {
        clientes[i] = cargarClientes();
    }

    printf("\nClientes disponibles:\n");
    for (int i = 0; i < 2; i++) {
        printf("Cliente %d: [%s, %s, %s]\n", i + 1, clientes[i].Apellido, clientes[i].Nombre, clientes[i].Dni);
    }
    printf("Ingrese el numero de cliente (1-2) o 0 para finalizar: ");
    scanf("%d", &opcion);
    fflush(stdin);
    if (opcion == 1) {
        mostrarClientes(clientes, opcion - 1);
        int subOpcion;
        printf("1:CAMBIAR CONTRASENIA\n2:DEPOSITAR\n3:RETIRO\n4:CONSULTAR SALDO\n5:MOSTRAR DATOS\n:");
        scanf("%d", &subOpcion);
        switch (subOpcion)
        {
        case 1: printf("Ingrese su nueva contrasenia: ");
                scanf("%d", &clientes->contrasenia);
                printf("contrasenia cambiada con exito: %d", clientes->contrasenia);
            break;
        case 2: printf("Ingrese el monto a depositar");
                int montoDeposito;
                scanf("%f", &montoDeposito);
                clientes->Datos.Saldo += montoDeposito;
            break;
        case 3: printf("Ingrese el monto a RETIRAR: ");
                int montoRetiro;
                scanf("%f", &montoRetiro);
                clientes->Datos.Saldo -= montoRetiro;
            break;
        case 4: printf("Su saldo es %.2f", clientes->Datos.Saldo);
        case 5: printf("Nombre de cliente: %s, %s", clientes->Apellido, clientes->Nombre);
                printf("Su CVU es: %d", clientes->Datos.CBU);
            break;
        default:
            break;
        }
    } else if (opcion == 2) {
        mostrarClientes(clientes, opcion - 1);
        int subOpcion;
        printf("1:CAMBIAR CONTRASENIA\n2:DEPOSITAR\n3:RETIRO\n4:CONSULTAR SALDO\n5:MOSTRAR DATOS\n");
        scanf("%d", &subOpcion);
        switch (subOpcion)
        {
        case 1: printf("Ingrese su nueva contrasenia: ");
                scanf("%d", &clientes->contrasenia);
                printf("contrasenia cambiada con exito: %d", clientes->contrasenia);
            break;
        case 2: printf("Ingrese el monto a depositar");
                int montoDeposito;
                scanf("%f", &montoDeposito);
                clientes->Datos.Saldo += montoDeposito;
            break;
        case 3: printf("Ingrese el monto a RETIRAR: ");
                int montoRetiro;
                scanf("%f", &montoRetiro);
                clientes->Datos.Saldo -= montoRetiro;
            break;
        case 4: printf("Su saldo es %.2f", clientes->Datos.Saldo);
        case 5: printf("Nombre de cliente: %s, %s", clientes->Apellido, clientes->Nombre);
                printf("Su CVU es: %d", clientes->Datos.CBU);
            break;
        default:
            break;
        }
    } else if ((opcion == 0))
    {
        printf("saliendo del programa");
        getchar();
    }
    
    // Liberar la memoria reservada para el historial de movimientos
    for (int i = 0; i < 2; i++) {
        free(clientes[i].Datos.historial);
    }
    return 0;
}
Cliente cargarClientes(){
    Cliente cliente;
        printf("-------------------\n");
        printf("Apellido: ");
        scanf("%s", &cliente.Apellido);
        printf("Nombre: ");
        scanf("%s", &cliente.Nombre);
        printf("DNI: ");
        scanf("%s", &cliente.Dni);
        printf("Fecha de Nacimiento:\n");
        scanf("%d", &cliente.Fecha.dia);
        scanf("%d", &cliente.Fecha.mes);
        scanf("%d", &cliente.Fecha.anio);
        printf("Ingrese una contrasenia:");
        scanf("%d", &cliente.contrasenia);
        fflush(stdin);
        printf("Ingrese un CBU:");
        scanf("%d", &cliente.Datos.CBU);
        fflush(stdin);
        printf("Ingrese su Saldo:");
        scanf("%f", &cliente.Datos.Saldo);
        fflush(stdin);
        printf("Ingrese solo un movimiento: fecha, hora, monto\n");
        scanf("%f", &cliente.movimiento1.fecha);
        scanf("%d", &cliente.movimiento1.hora);
        scanf("%f", &cliente.movimiento1.monto);

        // Reserva dinámica para el historial de movimientos (ejemplo con tamaño por defecto)
        cliente.Datos.historial = malloc(10 * sizeof(Movimiento));

    return cliente;
}

void mostrarClientes(Cliente clientes[], int numCliente) {
    printf("\nMostrando información del Cliente %d:\n", numCliente + 1);
    printf("Apellido: %s\n", clientes[numCliente].Apellido);
    printf("Nombre: %s\n", clientes[numCliente].Nombre);
    printf("DNI: %s\n", clientes[numCliente].Dni);
    printf("Fecha de Nacimiento: %d/%d/%d\n", clientes[numCliente].Fecha.dia,
           clientes[numCliente].Fecha.mes, clientes[numCliente].Fecha.anio);
    printf("Contraseña: %d\n", clientes[numCliente].contrasenia);
    printf("CBU: %d\n", clientes[numCliente].Datos.CBU);
    printf("Saldo: %.2f\n", clientes[numCliente].Datos.Saldo);
}