#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "paciente.h"

int main()
{
    int opcion;
    int salir=0;
    int idTramiteUrgente=0;
    int idTramiteregular=0;
    char* dni;
    int i;
    int len;

    ArrayList* listaTramiteUrgente;
    ArrayList* listaTramiteRegular;

    ArrayList* atendidosUrgentes;
    ArrayList* atendidosRegulares;

    ePaciente* pacienteActual;

    listaTramiteUrgente=al_newArrayList();
    listaTramiteRegular=al_newArrayList();
    atendidosUrgentes=al_newArrayList();
    atendidosRegulares=al_newArrayList();

    printf("\n 1. TRAMITE URGENTE\n 2. TRAMITE REGULAR\n 3. LISTAR\n 4. MOSTRAR ATENDIDOS\n 5. SALIR \n");
    scanf("%d", &opcion);


    do
    {
        switch(opcion)
        {
        case 1:

            idTramiteUrgente++;
            printf("INGRESE DNI: \n");
            fflush(stdin);
            gets(dni);
            cargarTramite(listaTramiteUrgente, idTramiteUrgente ,dni)
            break;
        case 2:

             idTramiteregular++;
            printf("INGRESE DNI: \n");
            fflush(stdin);
            gets(dni);
            cargarTramite(listaTramiteRegular, idTramiteregular ,dni)
            break;
        case 3:

            if(!listaTramiteUrgente->isEmpty(listaTramiteUrgente))
            {
                pacienteActual = (ePaciente*) listaTramiteUrgente->pop(listaTramiteUrgente,0);

                printf("paciente a ser atendido (URGENTE)\n");
                atendidosUrgentes->add(atendidosUrgentes, pacienteActual);
                mostrarPaciente(pacienteActual);
            }
            else
            {
                if(!listaTramiteRegular->isEmpty(listaTramiteRegular))
            {
                pacienteActual = (ePaciente*) listaTramiteRegular->pop(listaTramiteRegular,0);
                printf("paciente a ser atendido (REGULAR) \n");
                atendidosRegulares->add(atendidosRegulares,pacienteActual);
                mostrarPaciente(pacienteActual);
            }
            }
            break;
        case 4:

            if(!listaTramiteUrgente->isEmpty(listaTramiteUrgente))
            {
                len=listaTramiteUrgente->len(listaTramiteUrgente);
            }
            printf("TRAMITES URGENTES\n");
            for(i=0; i<listaTramiteUrgente->len(listaTramiteUrgente); i++)
            {
                pacienteActual= (ePaciente*) listaTramiteUrgente->get(listaTramiteUrgente, i);
                mostrarPaciente(pacienteActual);
            }
            printf("TRAMITES regular\n");
            for(i=0; i<listaTramiteRegular->len(listaTramiteRegular); i++)
            {
                pacienteActual= (ePaciente*) listaTramiteRegular->get(listaTramiteRegular, i);
                mostrarPaciente(pacienteActual);
            }
            break;
        case 5:
            if(!atendidosUrgentes->isEmpty(atendidosUrgentes))
            {
                len=atendidosUrgentes->len(atendidosUrgentes);

                atendidosUrgentes->sort(atendidosUrgentes,compararPorDni,0);
            }
            printf("TRAMITES URGENTES\n");
           mostrarListaTramite(listaTramiteUrgente);
            if(!atendidosRegulares->isEmpty(atendidosRegulares))
            {
                len=atendidosRegulares->len(atendidosRegulares);
                atendidosRegulares->sort(atendidosRegulares,compararPorDni,0);
            }
            printf("TRAMITES regular\n");
            mostrarListaTramite(listaTramiteRegular)

            break;
        case 6:
            salir=1;
            break;
        default:

            break;
        }
    }
    while(salir==0);





    return 0;
}
