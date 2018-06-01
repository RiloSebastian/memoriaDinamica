#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
char nombre[50];
int id;

}ePersona;

ePersona* newpersona();
int epersona_setId(ePersona*, int);
int epersona_setNombre(ePersona*, char*);
int epersona_getId (ePersona*);
char* epersona_getnombre (ePersona*);
int main()
{
    ePersona* pPersona;//puntero


   /* pPersona= (ePersona*)para saber que tipo de dato recibe el puntero a void -- malloc(sizeof(ePersona));// malloc reserva una cantidad de bytes consecutivos en memoria para guardar el tipo de dato
    //dejo de apuntar al stack y ahora apunta al heap.
    es como hacer
    epersona= &persona
    */

    pPersona=newpersona();

    if(pPersona!=NULL){ //para asegurarse de que no sea null
     if(epersona_setId(pPersona,45)==-1){
      printf("id incorrecto\n");
     }
     else{
      if(epersona_setNombre(pPersona, "marta")==-1){
       printf("id incorrecto\n");
      }
      else{
       printf("%d--%s", epersona_getId(pPersona),epersona_getnombre(pPersona));
      }
     }
    }

    return 0;
}

int epersona_setId(ePersona* this, int id){// 'this': palabra reservada de c++.
int ret=-1;//dentro de un set nunca se muestra un mensaje
//por eso el set devuelve un entero

  if(this!= NULL && id>0){
   this->id = id; // this es un dato tipo persona que tiene su campo id propio.
   ret=1;
  }
 return ret;
}


int epersona_setNombre(ePersona* this, char* nombre){
int ret=-1;

  if(this!= NULL &&  nombre!= NULL && strlen(this->nombre)>3){
    strcpy(this->nombre,nombre);
     ret=1;
    }
 return ret;

}

int epersona_getId (ePersona* this){
int ret=-1;

    if(this!=NULL){
        ret= this->id;
    }
return ret;
}

char* epersona_getnombre (ePersona* this){
char* ret = NULL;

 if(this!=NULL){
  ret = this->nombre;
 }

return ret;
}

ePersona* newpersona(){

ePersona* persona;

persona = (ePersona*) malloc(sizeof(ePersona));

return persona;
}
