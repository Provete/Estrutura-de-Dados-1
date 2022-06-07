#ifndef lista_cabeca_calda
#define lista_cabeca_calda

typedef struct noLista
{
    int valor;
    struct noLista* proximo;
} NoLista;

typedef struct listaEncadeada
{
    NoLista* head;
    NoLista* tail;
} ListaEncadeada;

void CriarLista(ListaEncadeada* listaEncadeada);
void InserirElemento(ListaEncadeada* listaEncadeada, int novoValor);
void ImprimirLista(ListaEncadeada* listaEncadeada);
NoLista* ProcurarPorValor(ListaEncadeada* listaEncadeada, int valor);

#endif