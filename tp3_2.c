#include <stdio.h>
#include <stdlib.h>

int prod[5][12];
float promGanancias;
int valMin[3];
int valMax[3];

void main(){
    int random = rand()%40000 + 10000;
    valMin[0] = random;
    valMin[1] = 2025;
    valMin[2] = 1;
    for(int i=0 ; i<5 ; i++){
        for(int j=0 ; j<12 ; j++){
            prod[i][j] = random;
            random = rand()%40000 + 10000;
            if(valMax[0] < prod [i][j]){
                valMax[0] = prod[i][j];
                valMax[1] = 2025+i;
                valMax[2] = j+1;
            }
            if(valMin[0] > prod[i][j]){
                valMin[0] = prod[i][j];
                valMin[1] = 2025+i;
                valMin[2] = j+1;
            }
        } 
    }

    //Mostrar todos los valores
    for(int i=0 ; i<5 ; i++){
        for(int j=0 ; j<12 ; j++){
            printf("%d ",prod[i][j]);
        } 
        printf("\n");
    }    

    //Promedio en anios
    printf("Promedio en anios:\n");
    for (int i=0; i<5; i++){
        for(int j=0 ; j<12 ; j++){
            promGanancias += prod[i][j];
        }
        printf("%d: $%.2f\n",i+2024 ,promGanancias/12);
        promGanancias = 0;
    }

    printf("\nValor maximo obtenido: $%d", valMax[0]);
    printf(" en la fecha %d/%d", valMax[2], valMax[1]);
    printf("\nValor minimo obtenido: $%d", valMin[0]);
    printf(" en la fecha %d/%d", valMin[2], valMin[1]);
}