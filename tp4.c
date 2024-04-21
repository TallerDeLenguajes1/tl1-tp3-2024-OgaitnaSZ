#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

struct{
    int ProductoID;
    int Cantidad;
    char *TipoProducto;
    float PrecioUnitario;
}typedef Producto;

struct{
    int ClienteID;
    char *NombreCliente;
    int CantidadProductosAPedir;
    Producto *Productos;
}typedef Cliente;

Producto crearProducto(int id){    //Funcion para crear productos de manera aleatoria
    Producto producto;
    producto.ProductoID = id;
    producto.Cantidad = rand() % 10+1;
    producto.TipoProducto = TiposProductos[rand() % 5];
    producto.PrecioUnitario = (float)(rand() % 90+10); 
    return producto;
}

//Funcion para calcular el total de un producto
float calcularCostoTotal(Producto producto){return producto.Cantidad * producto.PrecioUnitario;}

void main(){
    int cantClientes = 0;
    printf("Escriba la cantidad de clientes (Max 5): ");
    scanf("%d", &cantClientes);

    //Reserva para cada cliente
    Cliente *clientes = (Cliente *)malloc(cantClientes * sizeof(Cliente));

    //Carga de datos
    for(int i=0 ; i<cantClientes ; i++){
        clientes[i].ClienteID = i + 1;
        clientes[i].NombreCliente = (char *)malloc(50 * sizeof(char));  //Reserva para el nombre
        printf("Ingrese el nombre del cliente %d: ", i+1);
        scanf("%s", clientes[i].NombreCliente);
        clientes[i].CantidadProductosAPedir = rand() % 5+1;
        clientes[i].Productos = (Producto *)malloc(clientes[i].CantidadProductosAPedir * sizeof(Producto));  //Reserva para los productos
        for (int j=0; j<clientes[i].CantidadProductosAPedir; j++) {
            clientes[i].Productos[j] = crearProducto(j + 1);
        }
    }

    //Mostrar informacion
    for(int i=0 ; i<cantClientes ; i++){
        float totalCliente = 0;
        printf("\nDATOS DEL CLIENTE:");
        printf("\n  ID: %d \n  Nombre: %s", clientes[i].ClienteID, clientes[i].NombreCliente);
    
        printf("\n  PRODUCTOS DE %s:", clientes[i].NombreCliente);
        for(int j=0 ; j<clientes[i].CantidadProductosAPedir ; j++){  //Mostrar productos del cliente
            Producto producto = clientes[i].Productos[j];
            printf("\n   -ID: %d",producto.ProductoID);
            printf("\n    Cantidad %d",producto.Cantidad);
            printf("\n    Tipo de producto: %s",producto.TipoProducto);
            printf("\n    Precio por unidad: $%.2f",producto.PrecioUnitario);
            printf("\n    Costo total: $%.2f",calcularCostoTotal(producto));
            totalCliente += calcularCostoTotal(producto);
        }
        printf("\n  El total de %s es: $%.2f\n",clientes[i].NombreCliente, totalCliente);
    }

    //Liberar memoria
    for(int i=0 ; i<cantClientes ; i++){
        free(clientes[i].NombreCliente);
        free(clientes[i].Productos);
    }
    free(clientes);
}