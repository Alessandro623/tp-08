#include <stdio.h>
#include <stdlib.h>

struct Movimiento {
    float fecha;
    int hora;
    float monto;
};

struct FechaNacimiento {
    int dia;
    int mes;
    int anio;
};

struct DatosCuenta {
    int CBU;
    float Saldo;
    struct Movimiento historial[10];  // Tamaño por defecto
};

struct Cliente {
    char Apellido[50];
    char Nombre[50];
    char Dni[10];
    int contrasenia;
    struct FechaNacimiento Fecha;
    struct DatosCuenta Datos;
};

struct Cliente clientes[2];  // Dos clientes fijos

void cargarClientes();
void mostrarClientes();

int main() {
    printf("Ingrese la información de los clientes\n");
    for (int i = 0; i < 2; i++) {
        cargarClientes();
    }

    // Menú interactivo para seleccionar un cliente
    while (1) {
        printf("\nPre-menú interactivo:\n");
        mostrarClientes();

        printf("Ingrese el número del cliente que desea seleccionar (0 para finalizar): ");
        int seleccion;
        scanf("%d", &seleccion);

        if (seleccion == 0) {
            break;
        } else if (seleccion == 1 || seleccion == 2) {
            // Operaciones con el cliente seleccionado
            printf("Ha seleccionado al Cliente %d\n", seleccion);
            // Puedes agregar más lógica aquí según lo que desees hacer con el cliente seleccionado
        } else {
            printf("Opción no válida. Por favor, ingrese 1 o 2.\n");
        }
    }

    return 0;
}

void cargarClientes() {
    struct Cliente *cliente = &clientes[i];

    printf("-------------------\n");
    printf("Apellido: ");
    scanf("%s", cliente->Apellido);
    printf("Nombre: ");
    scanf("%s", cliente->Nombre);
    printf("DNI: ");
    scanf("%s", cliente->Dni);
    printf("Fecha de Nacimiento:\n");
    scanf("%d", &cliente->Fecha.dia);
    scanf("%d", &cliente->Fecha.mes);
    scanf("%d", &cliente->Fecha.anio);
    printf("Ingrese una contrasenia:");
    scanf("%d", &cliente->contrasenia);
    fflush(stdin);
    printf("Ingrese un CBU:");
    scanf("%d", &cliente->Datos.CBU);
    fflush(stdin);
    printf("Ingrese su Saldo:");
    scanf("%f", &cliente->Datos.Saldo);
    fflush(stdin);
    printf("Ingrese la cantidad de movimientos: ");
    int numMovimientos;
    scanf("%d", &numMovimientos);

    for (int i = 0; i < numMovimientos; i++) {
        printf("Ingrese el movimiento %d: fecha, hora, monto\n", i + 1);
        scanf("%f", &cliente->Datos.historial[i].fecha);
        scanf("%d", &cliente->Datos.historial[i].hora);
        scanf("%f", &cliente->Datos.historial[i].monto);
    }
}

void mostrarClientes() {
    for (int i = 0; i < 2; i++) {
        printf("Cliente %d: [%s, %s, %s]\n", i + 1, clientes[i].Apellido, clientes[i].Nombre, clientes[i].Dni);
    }
}
