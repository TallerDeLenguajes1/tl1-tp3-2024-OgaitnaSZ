#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CANT_NOMBRES 5
#define LONG_NOMBRE 30

char *listadoNombres[5];

void main(){
    
    //Ingreso de nombres
    printf("Escribe 5 nombres: ");
    for (int i=0; i<CANT_NOMBRES; i++){
        listadoNombres[i] = (char *)malloc(LONG_NOMBRE * sizeof(char));
        scanf("%s", listadoNombres[i]);
    }

    //Mostrar nombres
    printf("Los nombres son:");
    for (int i=0; i<CANT_NOMBRES; i++){
        printf("\n%s", listadoNombres[i]);
        free(listadoNombres[i]); //Liberar memoria
    }

}