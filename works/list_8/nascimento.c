#include <stdio.h>
#include <time.h>
#include "nascimento.h"

int dias_de_vida(data_t nasc){
    time_t t;
    struct tm *dataAtual;
    time(&t);
    dataAtual = localtime(&t);
    dataAtual->tm_mon += 1;
    dataAtual->tm_year += 1900;
    dataAtual->tm_mon *= 30;
    dataAtual->tm_year *= 365;
    nasc.ano *= 365;
    nasc.mes *= 30;
    nasc.dia += nasc.ano + nasc.mes;
    dataAtual->tm_mday += + dataAtual->tm_mon + dataAtual->tm_year;
    int diasDEvida = dataAtual->tm_mday - nasc.dia;
    return diasDEvida;
}
