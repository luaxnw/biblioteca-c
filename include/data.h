#ifndef DATA_H
#define DATA_H

typedef struct Data
{
    int dia;
    int mes;
    int ano;
} Data;

Data criaData(
    int dia,
    int mes,
    int ano);

#endif