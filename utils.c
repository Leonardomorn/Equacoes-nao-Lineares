#include <stdio.h>
#include <string.h>
#include <math.h>

#include "utils.h"

/*  Retorna tempo em milisegundos

    Forma de uso:
 
    double tempo;
    tempo = timestamp();
    <trecho de programa do qual se deseja medir tempo>
    tempo = timestamp() - tempo;
*/

double timestamp(void)
{
  struct timespec tp;
  clock_gettime(CLOCK_MONOTONIC_RAW, &tp);
  return((double)(tp.tv_sec*1.0e3 + tp.tv_nsec*1.0e-6));
}

void preenche_entrada(gerenciadorEntrada* io, int argc, char** argv)
{
  if (argc <= 3)
  {
    imprime_exemplo_entrada_padrao();
    exit(1);
  }  
  if(strcmp (argv[1], "newton") == 0)
  //newton
    io->metodo = NEWTONRAPHSON;
  else if (strcmp(argv[1], "secante") == 0)
  //secante
    io->metodo = SECANTE;
  else
  //nenhum metodo valido
    {
      imprime_exemplo_entrada_padrao(); exit(1);
    }
  if (atoi(argv[2]) < 1)
  {
    imprime_exemplo_entrada_padrao(); exit(1);
  }

  io->grau = atoi(argv[2]);
  if(argc != (io->grau +1 + 3 ))
  {
    imprime_exemplo_entrada_padrao(); exit(1);
  }

  io->polinomio = malloc ((io->grau+1) * sizeof(double));

  for (size_t i = 0; i <= io->grau; i++)
  {
    io->polinomio[i] = atof(argv[i+3]);
  }
    
}

void imprime_exemplo_entrada_padrao ()
{
    printf("\n Método do parâmetro de entrada incorreto");
    printf("\n a entrada deve ser: ./labZero metodo grau_polinomio coeficientes_polinomios. Grau deve ser um inteiro > 0\n\n");
    printf("\n exemplo1: newton 3 15 23 14 10 seleciona newton-raphson para um polinomio de grau 3 com \ncoeficiente de x³ igual a 10\n");
    printf("\n exemplo2: secante 3 5 2 0 10 seleciona secante para um polinomio de grau 3 com \ncoeficiente de x³ igual a 10\n");
}

void imprime_entrada(gerenciadorEntrada* io)
{
  if(io->metodo == NEWTONRAPHSON)
    printf("\n Metodo: Newton-Raphson");
  else
    printf("\n Método: Secante");
  printf("\n grau: %d", io->grau);
  printf("\n polinomio: ");
  for (int i = 0; i <= io->grau; i++)
    printf("%f ", io->polinomio[i]);
  printf("\n");
}

//imrpime cabecario na ordem iteracao/x/Fx/Fx'/erro
void imprime_cabecario(gerenciadorEntrada* io, int tipo)
{
  if (io->metodo == NEWTONRAPHSON)
    printf("\nNewton-Raphson:");
  else
    printf("\nSecante: ");
  
  if (tipo == RAPIDO)
    printf("Rapido");
  else
    printf("Lento");
  if(io->metodo == NEWTONRAPHSON)
    printf("\n Iteracao |    x     |     F(x)     |     F(x)'    |      erro      \n");
  else
    printf("\n Iteracao |   xi-1   |    xi    |    F(xi-1)   |    F(xi)'    |   xi+1   |      erro      \n");


}