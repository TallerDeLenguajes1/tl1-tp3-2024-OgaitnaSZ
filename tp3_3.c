#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *listadoNombres[5];

void main(){
    printf("Escribe 5 nombres: ");

    for (int i=0; i<5; i++){
        scanf("%s", listadoNombres[i]);
    }

    printf("Los nombres son:");
    for (int i=0; i<5; i++){
        printf("%s", listadoNombres[i]);
    }

    //liberar memoria
    for (int i=0; i<5; i++){
        free(listadoNombres[i]);
    }
   
}