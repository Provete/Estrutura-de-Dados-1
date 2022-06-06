#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada_com_descritor.h"

int main()
{
    Descritor listaEncadeada;
    CriarLista(&listaEncadeada);

    InserirElementoPelaFrente(&listaEncadeada, 5);
    ImprimirLista(&listaEncadeada);

    InserirElementoPelaFrente(&listaEncadeada, 95);
    InserirElementoPelaFrente(&listaEncadeada, 1120);
    InserirElementoPelaFrente(&listaEncadeada, -558);
    InserirElementoPorTras(&listaEncadeada, 9988);
    InserirElementoPorTras(&listaEncadeada, -998756);

    ImprimirLista(&listaEncadeada);

    return 0;
}