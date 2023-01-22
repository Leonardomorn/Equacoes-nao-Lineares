#include <stdio.h>
#include <math.h>

#include "utils.h"
#include "ZeroFuncao.h"

int main(int argc, char** argv) 
{
  gerenciadorEntrada gE;
  Polinomio* p;
  int it; double raiz;
  double tempo;
  p = malloc (sizeof(Polinomio));
  p->p = malloc (sizeof(double) * (gE.grau +1));

  preenche_entrada(&gE, argc, argv); //faz uma alocação dinamica 

  aloca_e_inicializa_polinomio(&gE, p);

  if(gE.metodo == NEWTONRAPHSON)
  {
    imprime_cabecario(&gE, RAPIDO);
    newtonRaphson(*p, 3, EPS, &it, &raiz, RAPIDO, &tempo);
      printf("\n numero de iteracoes : %d tempo total: %5g", it, tempo); 
    imprime_cabecario(&gE, LENTO);
    newtonRaphson(*p, 3, EPS, &it, &raiz, LENTO, &tempo);
      printf("\n numero de iteracoes : %d tempo total: %5g", it, tempo); 

  }

  printf("\n");



  return 0;
}

