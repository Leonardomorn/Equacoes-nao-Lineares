#ifndef __ZEROFUNCAO_H__
#define __ZEROFUNCAO_H__

#include <float.h>

// Aproximação aceitável como valor zero
#define ZERO DBL_EPSILON

// Parâmetros para teste de convergência
#define MAXIT 500
#define EPS 1.0e-8

/*!
  \brief Estrutura de um polinomio 
  \param grau é o grau do polinomio
  \param p é o vetor dos coeficientes do polinômio
*/
typedef struct {
  double *p;
  int grau;
} Polinomio;


double newtonRaphson (Polinomio p, double x0, double eps, int *it, double *raiz);
double secante (Polinomio p, double x0, double x1, double eps, int *it, double *raiz);

void calcPolinomio_rapido(Polinomio p, double x, double *px, double *dpx );
void calcPolinomio_lento(Polinomio p, double x, double *px, double *dpx );

#endif // __ZEROFUNCAO_H__

