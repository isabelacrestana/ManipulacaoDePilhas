#ifndef STACKPACKAGE_H_INCLUDED
#define STACKPACKAGE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

/* Criando uma bibioteca de manipulação de pilhas em C */

//Estrutura dos elementos da pilha
typedef struct no
{
    int valor;
    struct no *prox;  //aponta para o próx elemento
} NO;

// Estrutura que guarda o endereço do primeiro elemento do tipo struct NO
typedef struct pilha
{
    NO *TOPO;
} Pilha;

// Função que cria a pilha (aloca espaço para Struct que guarda o topo da pilha)
Pilha* Cria()
{
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p -> TOPO = NULL;  // aponta inicialmente para um endereço nulo
    return p;   //retorna o endereço
}

// Funcão auxiliar que realiza a inserção do elemento novo
NO* ins_ini(NO *p, int num)
{
    NO* aux = (NO*) malloc(sizeof(NO));   // Aloca espaço para a nova Struct (elemento novo da pilha)
    aux -> valor = num;  //campo valor recebe número
    aux -> prox = p;     //campo próx recebe o endereço de p para ligar os elementos
    return aux;          //retorna o ponteiro de estrutura
}

// Função que irá alterar o endereço do topo da pilha e chamará a funco ins_ini
void Push(Pilha *p, int v)
{
    p -> TOPO = ins_ini(p -> TOPO, v);  //topo da pilha receberá o retorno da função ins_ini
                                        // o retorno será o ponteiro que aponta para a prx struct da pilha
}

// Função auxiliar que realiza a remoção do elemento no topo da pilha
NO* del_inic(NO* p)
{
    NO* aux;   //cria um ponteiro do tipo NO* (elemento da pilha)
    aux = p -> prox;   //ponteiro recebe o endereço do próximo elemento da pilha
    free(p);    // desaloca p (estrutura a ser removida da pilha)
    return aux; //retorna aux (que contém será retornado para o ponteiro do topo da pilha)
}

// Função que irá retornar o valor do num removido da pilha e fará o pont do topo da pilha apontar para o próximo elemento
// Também chamará a função del_inic
int Pop(Pilha* p)
{
    int var;   // variável cirada para guardar o valor do num removido da pilha
    if (p -> TOPO == NULL)      // verifica se a pilha está vazia)
    {
        printf("Pilha Vazia...");
        exit(1);
    }

    var = p -> TOPO -> valor;
    p -> TOPO = del_inic(p -> TOPO);  //receberá o endereço do próximo elemento (para assim remover o elem que estava no topo)
    return var;   //retorna valor removido
}

// Função que imprime a pilha
void Imprime(Pilha* p)
{
    NO* aux;

    if (p == NULL)    //verificação...
    {
        printf("\nPilha vazia...");
    }

    else
    {
        printf("Impressao da pilha...\n");
        for (aux = p -> TOPO; aux != NULL ; aux = aux -> prox)  //loop para percorrrer todos os elementos
        // condição de parada é o ponteiro ser nulo
        {
            printf("%d ", aux -> valor);
        }
    }

}

// Função que desaloca pilha
Pilha* Libera(Pilha* p)
{
    NO* aux = p -> TOPO;  // aux recebe o endereço do topo da pilha

    while(aux != NULL)    //loop que desaloca elemento por elemento
    {
        NO* q = aux -> prox;  //variável que guarda endereço do próx elemento
        free(aux);            //libera estrutura NO
        aux = q;              //aux recebe end do próximo elemento
    }

    free(p);  //Libera estutura que guardava o end do topo da pilha
    return NULL;   // Pilha aponta para nulo
}

// Função que verifica se a pilha está vazia
int PilhaVazia(Pilha* p)
{
    if (p -> TOPO == NULL)   // Se topo for nulo significa que está vazia
    {
        return 1;
    }

    else
    {
        return 0;
    }
}
#endif // STACKPACKAGE_H_INCLUDED
