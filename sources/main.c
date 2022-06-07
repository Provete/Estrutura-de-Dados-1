#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada_com_cabeça_calda.h"

int main()
{
    ListaEncadeada lista;
    CriarLista(&lista);
    ImprimirLista(&lista);
    InserirElemento(&lista, 96);
    InserirElemento(&lista, 5543);
    InserirElemento(&lista, 543);
    ImprimirLista(&lista);


    return 0;
}