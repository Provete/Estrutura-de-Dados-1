#include "lista_encadeada_com_descritor.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Inicializa uma lista vazia
 * 
 * @param listaEncadeada Lista para esvaziar
 */
void CriarLista(Descritor* listaEncadeada)
{
    listaEncadeada->primeiro = NULL;
    listaEncadeada->ultimo = NULL;
    listaEncadeada->tamanho = 0;
}

/**
 * @brief Verifica se a lista encadeada está vazia ou não
 * 
 * @param listaEncadeada Lista para verificar se está vazia
 * @return int Retorna 1 caso a lista esteja vazia, e 0 caso contrário
 */
int EstaVazia(Descritor* listaEncadeada)
{
    int estaVazia = listaEncadeada->tamanho == 0? 1 : 0;
    return estaVazia;
}

/**
 * @brief Insere um elemento na lista pela frente
 * 
 * @param listaEncadeada Lista para inserir o elemento
 * @param novoValor  Valor do novo elemento
 */
void InserirElementoPelaFrente(Descritor* listaEncadeada, int novoValor)
{
    NoLista* novoElemento = (NoLista*) malloc(sizeof(NoLista));
    
    if(novoElemento == NULL)
    {
        printf("PC de pobre kikkkkkkkkkkkkkkkkkkkkkkkkkk\n");
        return;
    }

    novoElemento->valor = novoValor;
    novoElemento->proximo = listaEncadeada->primeiro;
    listaEncadeada->primeiro = novoElemento;

    if(EstaVazia(&listaEncadeada))
    {
        listaEncadeada->ultimo = listaEncadeada->primeiro;
    }

    listaEncadeada->tamanho++;
}

void InserirElementoPorTras(Descritor* listaEncadeada, int novoValor)
{
    NoLista* novoElemento = (NoLista*) malloc(sizeof(NoLista));

    if(novoElemento == NULL)
    {
        printf("PC de pobre kikkkkkkkkkkkkkkkkkkkkkkkkkk\n");
        return;
    }

    novoElemento->valor = novoValor;
    listaEncadeada->ultimo->proximo = novoElemento;
    listaEncadeada->ultimo = novoElemento;

    if(EstaVazia(listaEncadeada))
    {
        listaEncadeada->primeiro = listaEncadeada->ultimo;
    }

    listaEncadeada->tamanho++;
}

/**
 * @brief Imprime os valores da lista encadeada
 * 
 * @param listaEncadeada Lista para imprimir seus valores
 */
void ImprimirLista(Descritor* listaEncadeada)
{
    NoLista* iterador = listaEncadeada->primeiro;

    if(EstaVazia(listaEncadeada))
    {
        printf("Vazia\n");
        return;
    }

    while(iterador != NULL)
    {
        printf("Mal Elemento: %d\n", iterador->valor);
        iterador = iterador->proximo;
    }
}