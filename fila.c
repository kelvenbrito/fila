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

/* fun��o auxiliar: insere no fim */
No* ins_fim (No* fim, float v)
{
    No* p = (No*) malloc(sizeof(No));
    p->info = v;
    p->prox = NULL;
    if (fim != NULL) /* verifica se lista n�o estava vazia */
        fim->prox = p;
    return p;
}

/* fun��o auxiliar: retira do in�cio */
No* ret_ini (No* ini)
{
    No* p = ini->prox;
    free(ini);
    return p;
}

void insereBensMaterial (Fila* f, float v)
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

/* imprime: vers�o com lista */
void imprime (Fila* f)
{
    No* q;
    for (q=f->ini; q!=NULL; q=q->prox)
        printf("%5.2f\n",q->info);
}

/* M�dulo para ilustrar utiliza��o da fila */
int main (void)
{
    int esc, n=0,n1;





    do{
            printf("Veja as op��es abaixo e digite o numero correspondente a op��o\n\n");
            printf("1. Retirar Senha Para Obter Ben��o Material\n\n");
            printf("2. Retirar Senha Para Obter Ben��o Espiritual\n\n");
            printf("3. Conceder Ben��o Material\n\n");
            printf("4. Conceder Ben��o Espiritual\n\n");
            printf("5. Mostrar Lista Para Ben��o Material\n\n");
            printf("6. Mostrar Lista Para Ben��o Espiritua\n\n");
            printf("0. Fechar tenda dos milagres\n\n");

            scanf("%d", esc);

           switch(esc){
            case 1:

            for(n=1; n==10; n++){
                Fila* f = cria();

                insereBensMaterial(f,20.8);
                printf("\n\n receba a senha");

            break;


                }
            }

    }while((esc!=0));




   /* printf("Configuracao da fila:\n");
    imprime(f);
    printf("\n\nRetira Primeiro elemento: %5.2f\n", retira(f));
    printf("Retira Segundo elemento: %5.2f\n", retira(f));
    printf("\n\nConfiguracao da fila:\n");
    imprime(f);
    libera(f);
*/
    return 0;
}
