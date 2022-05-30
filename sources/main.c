#include <stdio.h>
#include <stdlib.h>
#include "listaencadeada.h"


int main()
{
    ListaEncadeada* lista = CriarLista();

    AdicionarElementoEmOrdem(&lista, 6);
    AdicionarElementoEmOrdem(&lista, -9);
    AdicionarElementoEmOrdem(&lista, 5598);
    AdicionarElementoEmOrdem(&lista, 0);

    //RemoverPorValor(&lista, 958);

    ImprimirLista(&lista);
    return 0;
}