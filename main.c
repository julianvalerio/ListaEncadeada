#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"
int main()
{
    Lista* l;
    l = lst_cria();
    l = lst_insere_ordenado(l, 23);
    l = lst_insere_ordenado(l, 45);
    l = lst_insere_ordenado(l, 50);
    l = lst_insere_ordenado(l, 30);
    l = lst_insere_ordenado(l, 10);
    printf("primeira impressão");
    lst_imprime(l);
    l = lst_retira(l, 45);
    printf("segunda impressão");
    lst_imprime(l);
    l = lst_retira(l, 10);
    printf("terceira impressão");
    lst_imprime(l);
    lst_busca(l, 30);
    printf("4 impressão");
    lst_imprime(l);
    lst_libera(l);
    return 0;
}
