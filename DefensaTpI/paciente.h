#ifndef PACIENTE_H_INCLUDED
#define PACIENTE_H_INCLUDED
#include "ArrayList.h"

typedef struct
{
    char Dni[10];
    int Turno;
} ePaciente;

ePaciente* new_tramite();
int setId(ePaciente*, int);
int getId(ePaciente*);

int setDni(ePaciente*, char*);
char* getDni(ePaciente*);

int mostrarPaciente (ePaciente*);

int compararPorDni(void*, void*);

int mostrarListaTramite(ArrayList*);

int cargarTramite(ArrayList*, int, char*);

int atenderTramite (ArrayList*, ArrayList*);
#endif // PACIENTE_H_INCLUDED
