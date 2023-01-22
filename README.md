# Equacoes-nao-Lineares
Feito por Leonardo da Silva Camargo 

Utiliza os métodos Newton Raphson ou Secante para obter a raiz de um polinômio

Makefile: Para executar o makefile usa-se make e para limpar make faxina

Entrada: 

    a entrada deve ser: ./labZero metodo grau_polinomio coeficientes_polinomios. 
    
    Grau deve ser um inteiro > 0
    
    exemplo1: newton 3 15 23 14 10 seleciona newton-raphson para um polinomio de grau 3 com \ncoeficiente de x³ igual a 10\n");
    
    exemplo2: secante 3 5 2 0 10 seleciona secante para um polinomio de grau 3 com \ncoeficiente de x³ igual a 10\n");

    Depois da entrada inicial, dependendo do método será necessário um (newton-raphson) ou dois(secante) valores como chutes iniciais

Observações: o método não trata nenhuma forma de divisão por zero, caso resulte, é recomendado obter com outros chutes iniciais