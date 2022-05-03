#include <stdio.h>

int Fatorial(int x)
{
    if(x == 1) 
        return 1;

    return x * Fatorial(x-1);
}

/**
 * @brief Calcula a sequencia de Fibbonacci de forma iterativa
 * 
 * @param x Posição do elemento da sequencia para ser calculado
 * @return double Número de fibbonacci na posição x
 */
double FibbonacciIterativa(int x)
{
    if(x == 0)
        return 0;

    double anterior = 0;
    double proximo = 1;
    double temporario = 0;

    for(int i=1; i < x; i++)
    {
        temporario = proximo;
        proximo += anterior;
        anterior = temporario;
    }

    return proximo;
}

/**
 * @brief Calcula a Sequencia de Fibbonacci por meio da recursividade
 * 
 * @param x Posição do elemento da sequencia de Fibbonacci a ser calculado
 * @return int Valor da sequencia de Fibbonacci na posição x
 */
int FibbonacciRecursiva(int x)
{
    if(x == 1 || x == 2) 
        return (x-1);

    return FibbonacciRecursiva(x-1) + FibbonacciRecursiva(x-2);
}

/**
 * @brief roda o programa
 * 
 * @return int 
 */
int main()
{
    int x = 10;
    printf("O Numero de Fibbonacci na posição %d é: %d\n", x, FibbonacciRecursiva(x));
    return 0;
}