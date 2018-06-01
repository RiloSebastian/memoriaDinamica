#include <stdio.h>
#include <stdlib.h>
#define TAM 5



int main()
{
int vector[5];
int* pVector;
int* aux;
int i;

pVector = vector;
pVector = (int*) malloc(sizeof(int) * 5);

 if(pVector!=NULL){
  for(i=0;i<TAM;i++){
   *(pVector+i) = i+1;
  }
  printf("\n antes del realloc--------------------------------------\n\n");
  for(i=0;i<TAM;i++){
  printf("%d\n", *(pVector+i));
 }

 }

 aux= (int*) realloc(pVector, sizeof(int) * (TAM*2));
 if(aux!=NULL){
    pVector=aux;
    for(i=TAM;i<TAM*2; i++){
        *(pVector+i)=i+1;
    }
    printf("\n\n luego del realloc---------------------------------------\n\n");
     for(i=0;i<TAM*2; i++){
        printf("\n%d", *(pVector+i));
     }
     printf("\n\n luego del realloc por menos----------------------------\n\n");
     aux= (int*) realloc(pVector, sizeof(int)*4);
     for(i=0;i<TAM*2;i++){
      printf("\n%d", *(pVector+i));
     }
 }
 free(aux);
 printf("\n\n luego de free------------------------------------------\n\n");
 for(i=0;i<TAM*2;i++){
      printf("\n%d", *(pVector+i));
     }
return 0;
}
