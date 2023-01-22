#include <stdio.h>
#include <math.h>

#include "utils.h"
#include "ZeroFuncao.h"

int main(int argc, char** argv) 
{
  gerenciadorEntrada gE; double x0,x1;
  Polinomio* p;
  int it; double raiz;
  double tempo;
  p = malloc (sizeof(Polinomio));
  p->p = malloc (sizeof(double) * (gE.grau +1));

  preenche_entrada(&gE, argc, argv); //faz uma alocação dinamica 

  aloca_e_inicializa_polinomio(&gE, p);

  if(gE.metodo == NEWTONRAPHSON)
  {
    printf("Digite um chute inicial: \n");
    scanf("%lf", &x0);
    imprime_cabecario(&gE, RAPIDO);
    newtonRaphson(*p, x0, EPS, &it, &raiz, RAPIDO, &tempo);
    printf("\n numero de iteracoes : %d tempo total: %5g", it, tempo); 
    printf("\n raiz: %10g", raiz);
    imprime_cabecario(&gE, LENTO);
    newtonRaphson(*p, x0, EPS, &it, &raiz, LENTO, &tempo);
    printf("\n numero de iteracoes : %d tempo total: %5g", it, tempo);
    printf("\n raiz: %10g", raiz); 

  }
  else
   {
    printf("Digite o x0 : \n");
    scanf("%lf", &x0);
    printf("Digite o x1 : \n");
    scanf("%lf",&x1);
    imprime_cabecario(&gE, RAPIDO);
    secante(*p, x0, x1, EPS, &it, &raiz, RAPIDO, &tempo);
    printf("\n numero de iteracoes : %d tempo total: %5g", it, tempo); 
    printf("\n raiz: %10g", raiz);
    imprime_cabecario(&gE, LENTO);
    secante(*p, x0, x1, EPS, &it, &raiz, LENTO, &tempo);
    printf("\n numero de iteracoes : %d tempo total: %5g", it, tempo); 
    printf("\n raiz: %10g", raiz);
  } 


  printf("\n");



  return 0;
}

