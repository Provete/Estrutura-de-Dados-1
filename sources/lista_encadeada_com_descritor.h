#pragma once

typedef struct noLista
{
    int valor;
    struct listaEncadeada* proximo;
} NoLista;

typedef struct descritor
{
    NoLista* primeiro;
    NoLista* ultimo;
    int tamanho;
} Descritor;

void CriarLista(Descritor* listaEncadeada);
void InserirElementoPelaFrente(Descritor* listaEncadeada, int novoValor);
void InserirElementoPorTras(Descritor* listaEncadeada, int novoValor);
void ImprimirLista(Descritor* listaEncadeada);
int EstaVazia(Descritor* listaEncadeada);