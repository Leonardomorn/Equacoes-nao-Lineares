#include <stdio.h>
#include <math.h>

#include "utils.h"
#include "ZeroFuncao.h"

/*!
	\brief funcao que retorna o módulo do erro relativo aproximado entre dois numeros
	\param xProx é o próximo x da iteração
	\param xi é o x atual da iteração
*/
double erro_relativo_aproximado(double xProx, double xi)
{
	double erro = fabs	(((xProx - xi) / xProx) * 100);
	return erro;
}

/*!
	\brief funcao que aplica o método newtonRaphson para descobrir uma raiz de um 
	polinômio de grau n e retorna o erro relativo aproximado
	\param p estrutura que possui os coeficientes do polinômio e o grau
	\param x0 chute inicial
	\param eps tolerância máxima
	\param *it número de iterações
	\param *raiz raiz do polinomio 
	\return erro relativo aproximado
*/
double newtonRaphson (Polinomio p, double x0, double eps,
		   int *it, double *raiz, int tipo, double tempo)
{
	double erro = 1.0 + eps;
	double xi = x0; double xProx; double px, dpx;
	*it = 0;
	while (*it < MAXIT && erro > eps) 
	{
		*it = *it + 1;
		if (tipo == RAPIDO)
		calcPolinomio_rapido(p,xi, &px, &dpx);
		else
		calcPolinomio_lento(p,xi,&px,&dpx);
		xProx = xi - (px / dpx);
		// printf("\nx:%f dx:%f ", px, dpx);
		erro = erro_relativo_aproximado(xProx, xi);
		imprime_resumo_newton(it, xi, px, dpx, erro);
		xi = xProx;
	}
	*raiz = xProx;
	return erro;
}


double secante (Polinomio p, double x0, double x1, double eps,
	     int *it, double *raiz)
{

}


void calcPolinomio_rapido(Polinomio p, double x, double *px, double *dpx)
{
	double pxAux = 0.0, dpxAux = 0.0;
	for (int i = p.grau; i > 0; --i)
	{
		pxAux = pxAux * x  + p.p[i];
		dpxAux = dpxAux * x + pxAux;
	}

	pxAux = pxAux * x + p.p[0];
	*px = pxAux;
	*dpx = dpxAux;
}


void calcPolinomio_lento(Polinomio p, double x, double *px, double *dpx)
{
	double pxAux = 0.0, dpxAux = 0.0;

	for (int i = p.grau; i > 0; --i)
	{
		pxAux = pxAux + p.p[i] * pow(x,i);
		dpxAux = dpxAux + p.p[i] * i * pow(x, (i-1) );
	}
	pxAux = pxAux + p.p[0];
	*px = pxAux;
	*dpx = dpxAux;
}

void aloca_e_inicializa_polinomio( gerenciadorEntrada* io, Polinomio* p)
{

  p->grau = io->grau;
  for (int i = 0; i <= p->grau; i++)
  {
	p->p[i] = io->polinomio[i];
	
  }
  
}

void imprime_polinomio (Polinomio *p)
{
	printf("\n grau: %d \n",p->grau);
	printf("\n O polinomio eh: ");
	for (int i = 0; i <= p->grau; i++)
	{
		 printf("%f ", p->p[i]);
	}
	
}

void imprime_resumo_newton(int *it, double xi, double px, double dpx, double erro)
{
	printf("%10d|%10g|%14g|%14g|%16g\n", *it,xi,px,dpx,erro);
}