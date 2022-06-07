#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada_com_cabeça_calda.h"

void CriarLista(ListaEncadeada* listaEncadeada)
{
    listaEncadeada->head = (NoLista*) malloc(sizeof(NoLista));
    listaEncadeada->tail = (NoLista*) malloc(sizeof(NoLista));

    listaEncadeada->head->proximo = listaEncadeada->tail;
    listaEncadeada->tail->proximo = NULL;
}

int EstaVazia(ListaEncadeada* listaEncadeada)
{
    if(listaEncadeada->head->proximo == listaEncadeada->tail)
        return 1;
    else
        return 0;
}

void InserirElemento(ListaEncadeada* listaEncadeada, int novoValor)
{
    NoLista* novoElemento = (NoLista*) malloc(sizeof(NoLista));

    if(novoElemento == NULL)
    {
        printf("Deu Ruim");
        return;
    }

    novoElemento->valor = novoValor;

    novoElemento->proximo = listaEncadeada->head->proximo;
    listaEncadeada->head->proximo = novoElemento;
}

NoLista* ProcurarPorValor(ListaEncadeada* listaEncadeada, int valor)
{
    NoLista* iterador = listaEncadeada->head->proximo;

    while(iterador != listaEncadeada->tail && iterador->valor != valor)
    {
        iterador = iterador->proximo;
    }

    if(iterador == listaEncadeada->tail)
    {
        printf("Elemento não encontrado\n");
        return NULL;
    }

    return iterador;
}

void ImprimirLista(ListaEncadeada* listaEncadeada)
{
    NoLista* iterador = listaEncadeada->head->proximo;

    while(iterador != listaEncadeada->tail)
    {
        printf("Mau Elemento: %d\n", iterador->valor);
        iterador = iterador->proximo;
    }
}

void RemoverElementoPorValor(ListaEncadeada* listaEncadeada, int valor)
{
    NoLista* iterador = listaEncadeada->head->proximo;
    NoLista* iteradorAnterior = listaEncadeada->head;

    while(iterador != listaEncadeada->tail && iterador->valor != valor)
    {
        iteradorAnterior = iterador;
        iterador = iterador->proximo;
    }

    if(iterador == listaEncadeada->tail)
    {
        printf("elemento inexistente\n");
        return;
    }
    
    iteradorAnterior->proximo = iterador->proximo;
    iterador->proximo = NULL;
    free(iterador);
}