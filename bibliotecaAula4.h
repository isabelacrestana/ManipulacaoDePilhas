#ifndef BIBLIOTECAAULA4_H_INCLUDED
#define BIBLIOTECAAULA4_H_INCLUDED
#include "stackPackage.h"


int ContaElementos(Pilha* p)
{
    NO* aux;
    int cont = 0;

    if (p == NULL)
    {
        printf("Pilha vazia...");
        exit(1);
    }

    aux = p -> TOPO;

    while(aux != NULL)
    {
        cont++;
        aux = aux -> prox;
    }
    return cont;
}

void aux_invPilha(Pilha* p, Pilha* pilhaAux)
{

}

void InvertePilha(Pilha* p)
{
    Pilha* pilhaAux;
    pilhaAux = Cria();

    while(!PilhaVazia(p))
    {
        Push(pilhaAux, Pop(p));
    }

    p -> TOPO = pilhaAux -> TOPO;
    free(pilhaAux);
}

void RemoveElemento(Pilha* p, int num)
{
    Pilha* pilhaAux;
    pilhaAux = Cria();
    int elem;
    printf("Num = %d", num);

    while(!PilhaVazia(p))
    {
        elem = Pop(p);
        if(elem != num)
        {
            Push(pilhaAux, elem);
        }

    }

    while(!PilhaVazia(pilhaAux))
    {
        Push(p, Pop(pilhaAux));
    }

}

int Compara(Pilha* P1, Pilha* P2)
{
    int contP1 = 0, contP2 = 0;
    NO* auxP1 = P1 -> TOPO;
    NO* auxP2 = P2 -> TOPO;

    while(auxP1 != NULL)
    {
        contP1++;
        auxP1 = auxP1 -> prox;
    }

    while(auxP2 != NULL)
    {
        contP2++;
        auxP2 = auxP2 -> prox;
    }

    if (contP1 > contP2)
        return 1;

    else if (contP2 > contP1)
        return 2;

    return 0;
}

Pilha* Digitos(int num)
{
    Pilha* p1 = Cria();
    while(num > 0)
    {
        Push(p1, num % 10);
        num /= 10;
    }

    return p1;
}

void ImprimeNumero(NO* elem)
{
    while(elem)
    {
        printf("%d", elem -> valor);
        elem = elem -> prox;
    }
}
#endif // BIBLIOTECAAULA4_H_INCLUDED
