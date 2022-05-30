#include <stdio.h>
#include <stdlib.h>
#include "listaencadeada.h"


/**
 * @brief Inicializa uma lista vazia
 * 
 * @return ListaEncadeada* retorna NULL para uma lista vazia
 */
ListaEncadeada* CriarLista()
{
    return NULL;
}

/**
 * @brief Verifica se uma dada lista encadeada está vazia ou não
 * 
 * @param listaEncadeada Lista para ser verificada
 * @return int 1 para caso a lista esteja vazia, 0 caso contrario
 */
int EstaVazia(ListaEncadeada* listaEncadeada)
{
    int estaVazia = (listaEncadeada == NULL);
    return estaVazia;
}

/**
 * @brief Adiciona um novo elemento à listaEncadeada*
 * 
 * @param listaEncadeada Endereço de memória do ponteiro de listaEncadeada*
 * @param novoValor Novo valor para ser inserido à listaEncadeada*
 */
void AdicionarElemento(ListaEncadeada** listaEncadeada, int novoValor)
{
    ListaEncadeada* novoElemento = (ListaEncadeada*) malloc(sizeof(ListaEncadeada));
    
    if(novoElemento == NULL)
    {
        printf("Erro: não foi possivel alocar memória para a criação de um novo elemento de ListaEncadeada*\n");
        return;
    }

    novoElemento->valor = novoValor;
    novoElemento->proximo = *listaEncadeada;
    *listaEncadeada = novoElemento;
}

/**
 * @brief Imprime todos os valores de listaEncadeada*
 * 
 * @param listaEncadeada Ponteiro para o endereço de memoria de listaEncadeada*
 */
void ImprimirLista(ListaEncadeada** listaEncadeada)
{
    if(EstaVazia(*listaEncadeada))
    {
        printf("Gay\n");
        return;
    }

    ListaEncadeada* iterador = *listaEncadeada;

    while (iterador != NULL)
    {
        printf("Valor: %d\n", iterador->valor);
        iterador = iterador->proximo;
    }
    
}

/**
 * @brief Procura na lista encadeada um nó com o valor especificado
 * 
 * @param listaEncadeada Lista encadeada para ser buscada
 * @param valor Valor a ser buscado
 * @return ListaEncadeada* Ponteiro para o nó com o valor buscado
 */
ListaEncadeada* ProcurarPorValor(ListaEncadeada** listaEncadeada, int valor)
{
    ListaEncadeada* iterador = *listaEncadeada;

    while(iterador != NULL)
    {
        if(iterador->valor == valor)
            return iterador;
        
        iterador = iterador->proximo;
    }

    return NULL;
}


/**
 * @brief Remove um nó dado um valor valor da lista encadeada sem afetar os sequentes
 * 
 * @param listaEncadeada Lista Encadeada para remover o nó com o valor
 * @param valor Valor a ser procurado para a remoção do nó
 */
void RemoverPorValor(ListaEncadeada** listaEncadeada, int valor)
{
    ListaEncadeada* iterador = *listaEncadeada;
    ListaEncadeada* iteradorAnterior = NULL;

    while(iterador != NULL && iterador->valor != valor)
    {
        iteradorAnterior = iterador;
        iterador = iterador->proximo;
    }

    if(iterador == NULL)
    {
        printf("Valor %d não encontrado\n", valor);
        return;
    }

    if(iteradorAnterior == NULL)
    {
        *listaEncadeada = iterador->proximo;
        return;
    }

    iteradorAnterior->proximo = iterador->proximo;
    iterador->proximo = NULL;

    free(iterador);
}


/**
 * @brief Insere um elemento na lista baseado em seu valor, em ordem decrescente
 * 
 * @param listaEncadeada Lista para inserir o valor
 * @param valor Novo valor do nó para ser inserido
 */
void AdicionarElementoEmOrdem(ListaEncadeada** listaEncadeada, int valor)
{
    ListaEncadeada* novoNo = (ListaEncadeada*) malloc(sizeof(ListaEncadeada));
    
    if(novoNo == NULL)
    {
        printf("Uh Oh, gay alert \n");
        return;
    }

    novoNo->valor = valor;
    ListaEncadeada* iteradorAnterior = NULL;
    ListaEncadeada* iterador = *listaEncadeada;

    while(iterador != NULL && iterador->valor >= valor)
    {
        iteradorAnterior = iterador;
        iterador = iterador->proximo;
    }

    if(iteradorAnterior == NULL)
    {
        *listaEncadeada = novoNo;
        novoNo->proximo = iterador;
        return;
    }

    iteradorAnterior->proximo = novoNo;
    novoNo->proximo = iterador;
}