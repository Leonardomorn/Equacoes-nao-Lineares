#ifndef __UTILS_H__
#define __UTILS_H__

#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NEWTONRAPHSON 1
#define SECANTE 2
#define RAPIDO 1
#define LENTO 2
typedef double real_t;
typedef double rtime_t;
typedef char * string_t;

double timestamp(void);

// Estruturas de dados
typedef struct gerenciadorEntrada
{
    uint metodo; // qual método utilizado (newton raphson ou secante)
    uint grau; // grau do polinomio 
    uint chute_x0; // chute inicial de x0 
    uint chute_x1; // chute inicial de x1 
    double *polinomio; // polinomio a ser coletado
}gerenciadorEntrada;

void preenche_entrada(gerenciadorEntrada* io, int argc, char** argv);
void imprime_exemplo_entrada_padrao ();
void imprime_entrada(gerenciadorEntrada* io);
void imprime_cabecario(gerenciadorEntrada* io, int tipo);



#endif // __UTILS_H__

