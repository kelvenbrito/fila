#include <stdio.h>
#include <stdlib.h>

struct no {
    float info;
    struct no* prox;
};
typedef struct no No;

struct fila {
    No* ini;
    No* fim;
};

typedef struct fila Fila;

Fila* cria (void)
{
    Fila* f = (Fila*) malloc(sizeof(Fila));
    f->ini = f->fim = NULL;
    return f;
}

/* função auxiliar: insere no fim */
No* ins_fim (No* fim, float v)
{
    No* p = (No*) malloc(sizeof(No));
    p->info = v;
    p->prox = NULL;
    if (fim != NULL) /* verifica se lista não estava vazia */
        fim->prox = p;
    return p;
}

/* função auxiliar: retira do início */
No* ret_ini (No* ini)
{
    No* p = ini->prox;
    free(ini);
    return p;
}

void insere (Fila* f, float v)
{
    f->fim = ins_fim(f->fim,v);
    if (f->ini==NULL) /* fila antes vazia? */
        f->ini = f->fim;
}

float retira (Fila* f)
{
    float v;
    if (vazia(f)) {
        printf("Fila vazia.\n");
        exit(1); /* aborta programa */
    }
    v = f->ini->info;
    f->ini = ret_ini(f->ini);
    if (f->ini == NULL) /* fila ficou vazia? */
        f->fim = NULL;
    return v;
}

int vazia (Fila* f)
{
    return (f->ini==NULL);
}

void libera (Fila* f)
{
    No* q = f->ini;
    while (q!=NULL) {
        No* t = q->prox;
        free(q);
        q = t;
    }
    free(f);
}

/* imprime: versão com lista */
void imprime (Fila* f)
{
    No* q;
    for (q=f->ini; q!=NULL; q=q->prox)
        printf("%5.2f\n",q->info);
}

/* Módulo para ilustrar utilização da fila */
int main (void)
{
    Fila* f = cria();

    insere(f,20.8);
    insere(f,21.2);
    insere(f,24.3);
    printf("Configuracao da fila:\n");
    imprime(f);
    printf("\n\nRetira Primeiro elemento: %5.2f\n", retira(f));
    printf("Retira Segundo elemento: %5.2f\n", retira(f));
    printf("\n\nConfiguracao da fila:\n");
    imprime(f);
    libera(f);
    return 0;
}
