// Consigna Taller S1
// Integrantes:
//  - Samuel Aldaz
//  - Adrian Carrera

#include <stdio.h>
#include <string.h>

int main()
{
    // Declaracion de variables
    int ID, opcion, cantidad;
    int stock = 0;
    char nombre[50];
    float precio;
    float ganancias = 0;

    // Registro inicial del producto
    printf("===========| REGISTRO DEL PRODUCTO |===========\n");
    printf("Ingrese ID del producto: ");
    scanf("%d", &ID);
    getchar(); // limpiar buffer

    printf("Ingrese nombre del producto: ");
    fgets(nombre, sizeof(nombre), stdin);
    nombre[strcspn(nombre, "\n")] = 0; // quitar salto de linea

    printf("Ingrese cantidad en stock: ");
    scanf("%d", &stock);

    printf("Ingrese precio unitario: ");
    scanf("%f", &precio);

    do
    {
        // Menu
        printf("\n===========| MENU |===========\n");
        printf("(1) Vender producto\n");
        printf("(2) Reabastecer producto\n");
        printf("(3) Consultar informacion del producto\n");
        printf("(4) Consultar ganancias acumuladas\n");
        printf("(5) Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        // Caso 1: Vender producto
        case 1:
            printf("\nIngrese la cantidad a vender: ");
            scanf("%d", &cantidad);

            if (cantidad <= 0)
            {
                printf("==========| ERROR |==========\n");
                printf("No se puede vender cantidades negativas o cero\n");
                printf("===========================\n");
                printf("Operacion cancelada.\n");
                printf("===========================\n");
            }
            else if (cantidad > stock)
            {
                printf("==========| ERROR |==========\n");
                printf("Stock insuficiente para completar la venta\n");
                printf("===========================\n");
                printf("Unidades Disponibles: %d\n", stock);
                printf("===========================\n");
                printf("Operacion cancelada.\n");
                printf("===========================\n");
            }
            else
            {
                float venta = cantidad * precio;
                stock = stock - cantidad;
                ganancias = ganancias + venta;
                printf("=======| Venta realizada con EXITO |=======\n");
                printf("Total venta: $%.2f\n", venta);
                printf("===========================================\n");
            }
            break;

        case 2:
            // Caso 2: Reabastecer producto
            printf("\nIngrese cantidad a reabastecer: ");
            scanf("%d", &cantidad);

            if (cantidad <= 0)
            {
                printf("==========| ERROR |==========\n");
                printf("No se puede reabastecer con valores negativos o cero.\n");
                printf("===========================\n");
                printf("Operacion cancelada.\n");
                printf("===========================\n");
            }
            else
            {
                stock = stock + cantidad;
                printf("=====================================\n");
                printf("Stock actualizado correctamente.\n");
                printf("=====================================\n");
            }
            break;

        case 3:
            // Caso 3: Consultar informacion del producto
            printf("\n===== INFORMACION DEL PRODUCTO =====\n");
            printf("ID: %d\n", ID);
            printf("Nombre: %s\n", nombre);
            printf("Stock disponible: %d\n", stock);
            printf("Precio unitario: $%.2f\n", precio);
            break;

        case 4:
            // Caso 4: Consultar ganancias acumuladas
            printf("================================\n");
            printf("\nGanancias acumuladas: $%.2f\n", ganancias);
            printf("================================\n");
            break;

        case 5:
            // Caso 5: Salir
            printf("================================\n");
            printf("\nSaliendo del programa...\n");
            printf("================================\n");
            break;

        default:
            printf("=====================================\n");
            printf("Opcion invalida. Intente de nuevo.\n");
            printf("=====================================\n");
        }

    } while (opcion != 5);

    return 0;
}
