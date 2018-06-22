#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "paciente.h"

ePaciente* new_tramite()
{
    ePaciente* aux;
    aux= (ePaciente*) malloc(sizeof(ePaciente));
}


int setId(ePaciente* this, int id)
{
    int seteo=-1;
    if(this != NULL)
    {
        this->Turno=id;
        seteo=0;
    }

    return seteo;
}


int getId(ePaciente* this)
{
    int id=-1;

    if(this!= NULL)
    {

        id= this->Turno;
    }
    return id;
}

int setDni(ePaciente* this, char* dni)
{
    int seteo=-1;

    if(this!=NULL && dni!= NULL)
    {
        strcpy(this->Dni, dni);
        seteo=0;
    }

    return seteo;
}
char* getDni(ePaciente* this)
{
    char* dni=NULL;
    if(this!=NULL)
    {
        dni = this->Dni;
    }

    return dni;
}

int mostrarPaciente (ePaciente* this)
{
    int muestro=-1;
    if(this !=NULL)
    {
        printf("%d --- %s\n", getId(this), getDni(this));
        muestro=0;
    }
    return muestro;
}

int compararPorDni(void* tramiteA, void* tramiteB)
{
    ePaciente* tramite1;
    ePaciente* tramite2;


    tramite1= (ePaciente*) tramiteA;
    tramite2= (ePaciente*) tramiteB;



return strcmp(tramite1->Dni, tramite2->Dni);
}

int mostrarListaTramite(ArrayList* listado)
{
    int i,listo=-1;
    int len;
    ePaciente* pacienteActual;
    len=listado->len(listado);
    if(listado!= NULL)
    {
        for(i=0;i<len;i++)
        {
                        pacienteActual=(ePaciente*) listado->get(listado,i);
        mostrarPaciente(pacienteActual);
        }
listo=0;
    }
 return listo;
}

int cargarTramite(ArrayList* listado, int id, char* dni)
{
int cargo=-1;
ePaciente* pacienteActual;

    if(listado!= NULL && id>0 && dni != NULL)
    {
             pacienteActual= new_tramite();
            idTramiteUrgente++;
            setId(pacienteActual, id);
            setDni(pacienteActual,dni);
            listado->add(listado, pacienteActual);
            cargo=0
    }

return cargo;
}

int atenderTramite (ArrayList* listaPendientes, ArrayList* listaAtendidos)
{
    atendio=-1;
    ePaciente* pacienteActual;
    if(listaPendientes!= NULL && listaAtendidos != NULL)
    {
        pacienteActual = (ePaciente*) listaPendientes->pop(listaPendientes,0);
                listaAtendidos->add(listaAtendidos, pacienteActual);
                mostrarPaciente(pacienteActual);

    }


}





