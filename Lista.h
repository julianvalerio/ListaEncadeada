#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct lista Lista;
Lista* lst_cria(void);
void lst_libera(Lista* l);
Lista* lst_insere(Lista* l, int i);
//Lista* lst_insere_ordenado (Lista* l, int v);
Lista* lst_retira(Lista* l, int v);
Lista* lst_busca(Lista* l, int v);
int lst_vazia(Lista* l);
void lst_imprime(Lista* l);

#endif // LISTA_H_INCLUDED
