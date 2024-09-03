#include <stdio.h>
#include <stdlib.h>
#include "stackPackage.h"

int main()
{
    Pilha *PILHA;
    PILHA = Cria();
    Push(PILHA, 5);
    Push(PILHA, Pop(PILHA));
    Push(PILHA, 20);
    Push(PILHA, 7);
    Push(PILHA, 8);
    Imprime(PILHA);
    PILHA = Libera(PILHA);
    Imprime(PILHA);

    return 0;
}
