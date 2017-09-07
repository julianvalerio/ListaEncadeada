#include <stdlib.h>
struct lista
{
    int info;
    struct lista *prox;
};

//descomentartypedef struct lista Lista;

//criar lista vazia
Lista* lst_cria(void)
{
    return NULL;
}

//insere elementos na lista
Lista* lst_insere(Lista *l, int i)
{
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->info = i;
    novo->prox = l;
    return novo;
}

Lista* lst_insere_ordenado (Lista* l, int v){
    Lista* novo;
    Lista* ant = NULL; /* ponteiro para elemento anterior */
    Lista* p = l; /* ponteiro para percorrer a lista */
    /* procura posição de inserção */
    while (p != NULL && p->info < v)
    {
        ant = p;
        p = p->prox;
    }
    /* cria novo elemento */
    novo = (Lista*) malloc(sizeof(Lista));
    novo->info = v;
    /* encadeia elemento */
    if (ant == NULL)
    {
        /* insere elemento no início */
        novo->prox = l;
        l = novo;
    }
    else   /* insere elemento no meio da lista */
    {
        novo->prox = ant->prox;
        ant->prox = novo;
    }
    return l;
}

//imprime os elementos da lista
void lst_imprime(Lista* l)
{
    Lista* p; //variável auxiliar para percorrer a lista
    for(p=l; p!= NULL; p=p->prox)
        printf("info = %d\n", p->info);
}
//verificar se a lista esta vazia
int lst_vazia(Lista* l)
{
    return(l == NULL);
}
//função de busca
Lista* lst_busca(Lista* l, int v)
{
    Lista* p;
    for(p=l; p!=NULL; p=p->prox)
    {
        if(p->info == v)
        {
            printf("encontrado");
            return p;
        }
    }
    return NULL;
}

//função que retira um elemento
Lista* lst_retira(Lista* l, int v)
{
    Lista* ant = NULL; //ponteiro para elemento anterior
    Lista* p = l; //ponteiro para percorrer lista
    //procurar elemento na lista guardando o anteiror
    while(p != NULL & p->info != v)
    {
        ant = p;
        p = p->prox;
    }
    //verifica se achou o elemento
    if(p == NULL)
        return l;
    //retira o elemento
    if(ant == NULL)
        l = p->prox; //retira elemento do início
    else
        ant->prox = p->prox; //retira elemento do meio ou final

    free(p);
    return l;
}

//função para liberar lista
void lst_libera(Lista* l)
{
    Lista* p = l;
    Lista* tmp;
    while (p != NULL)
    {
        tmp = p->prox; //guarda ref para prox elemento
        free(p); //libera memória
        p=tmp; // aponta para o próximo
    }
}
