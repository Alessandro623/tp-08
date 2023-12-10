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