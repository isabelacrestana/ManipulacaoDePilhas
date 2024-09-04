#include <stdio.h>
#include <stdlib.h>
#include "bibliotecaAula4.h"

int main()
{
    Pilha *PILHA, *PILHA2, *PILHA3;
    PILHA = Cria();
    Push(PILHA, 5);
    Push(PILHA, Pop(PILHA));
    Push(PILHA, 20);
    Push(PILHA, 7);
    Push(PILHA, 8);
    Imprime(PILHA);

    printf("\n%d", ContaElementos(PILHA));

    printf("\nInvertendo pilha\n");
    InvertePilha(PILHA);
    Imprime(PILHA);

    printf("\nRemovendo o numero 6 da pilha...\n");
    RemoveElemento(PILHA, 6);
    Imprime(PILHA);

    PILHA2 = Cria();
    Push(PILHA2, 1);
    Push(PILHA2, 3);
    Push(PILHA2, 5);
    Push(PILHA2, 5);

    printf("Pilha que tem mais elementos: %d", Compara(PILHA, PILHA2));

    PILHA3 = Digitos(123);
    printf("\n");
    Imprime(PILHA3);

    ImprimeNumero(PILHA3 -> TOPO);
    Libera(PILHA);
    Libera(PILHA2);
    Libera(PILHA3);

    return 0;
}
