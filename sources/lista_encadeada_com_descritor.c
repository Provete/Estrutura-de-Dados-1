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

    if(EstaVazia(listaEncadeada))
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
    (listaEncadeada->ultimo)->proximo = novoElemento;
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

/**
 * @brief Remove a primeira ocorrência de um elemento da lista dado seu valor.
 * 
 * @param listaEncadeada Lista para ter um valor removido.
 * @param valor Valor para remover.
 */
void RemoverElemento(Descritor* listaEncadeada, int valor)
{
    NoLista* iterador = listaEncadeada->primeiro;
    NoLista* iteradorAnterior = NULL;

    while(iterador != NULL && iterador->valor != valor)
    {
        iteradorAnterior = iterador;
        iterador = iterador->proximo;
    }

    if(iterador == NULL)
    {
        printf("Elemento não encontrado\n");
        return;
    }

    if(iteradorAnterior == NULL)
    {
        listaEncadeada->primeiro = iterador->proximo;
        free(iterador);
        listaEncadeada->tamanho--;
    
        if(listaEncadeada->primeiro == NULL)
            listaEncadeada->ultimo = NULL;
        return;
    }

    iteradorAnterior->proximo = iterador->proximo;
    iterador->proximo = NULL;
    free(iterador);

    listaEncadeada->tamanho--;
}

/**
 * @brief Libera o espaço de todos os elementos da lista e a inicializa de novo.
 * 
 * @param listaEncadeada Lista a ser liberada.
 */
void LimparLista(Descritor* listaEncadeada)
{
    if(EstaVazia(listaEncadeada))
    {
        printf("A lista está vazia\n");
        return;
    }

    NoLista* iterador = listaEncadeada->primeiro;
    NoLista* iteradorAnterior = NULL;

    while(iterador != NULL)
    {
        iteradorAnterior = iterador;
        iterador = iterador->proximo;
        free(iteradorAnterior);
    }

    CriarLista(listaEncadeada);
}