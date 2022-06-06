#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada_com_descritor.h"

int main()
{
    Descritor listaEncadeada;
    CriarLista(&listaEncadeada);

    InserirElementoPelaFrente(&listaEncadeada, 5);

    InserirElementoPelaFrente(&listaEncadeada, 95);
    InserirElementoPelaFrente(&listaEncadeada, 1120);
    InserirElementoPelaFrente(&listaEncadeada, -558);

    LimparLista(&listaEncadeada);

    ImprimirLista(&listaEncadeada);

    return 0;
}