#pragma once

typedef struct ListaEncadeada
{
    int valor;
    struct ListaEncadeada* proximo;
} ListaEncadeada;

int EstaVazia(ListaEncadeada* listaEncadeada);
int CalcularTamanho(ListaEncadeada** listaEncadeada);
void AdicionarElemento(ListaEncadeada** listaEncadeada, int novoValor);
void ImprimirLista(ListaEncadeada** listaEncadeada);
void RemoverPorValor(ListaEncadeada** listaEncadeada, int valor);
void AdicionarElementoEmOrdem(ListaEncadeada** ListaEncadeada, int valor);
ListaEncadeada* CriarLista();
ListaEncadeada* ProcurarPorValor(ListaEncadeada** listaEncadeada, int valor);
ListaEncadeada* PegarUltimoElemento(ListaEncadeada** listaEncadeada);