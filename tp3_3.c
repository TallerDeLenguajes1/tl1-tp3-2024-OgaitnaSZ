#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LONG_NOMBRE 30
int cantNombres = 0;

void main(){
    printf("Escriba la cantidad de nombres: ");
    scanf("%d", &cantNombres);

    char *listadoNombres[cantNombres];
    //Ingreso de nombres
    printf("Escribe 5 nombres: ");
    for (int i=0; i<cantNombres; i++){
        listadoNombres[i] = (char *)malloc(LONG_NOMBRE * sizeof(char));
        scanf("%s", listadoNombres[i]);
    }

    //Mostrar nombres
    printf("Los nombres son:");
    for (int i=0; i<cantNombres; i++){
        printf("\n%s", listadoNombres[i]);
        free(listadoNombres[i]); //Liberar memoria
    }

}