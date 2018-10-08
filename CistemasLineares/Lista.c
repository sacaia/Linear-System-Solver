//
// Created by Lucas R on 07/10/2018.
//

#include <stdlib.h>

typedef
struct No
{
    void*      info;
    struct No* prox;
}
        No;

typedef
struct Lista
{
    No*  inicio;
    int  (*compareTo) (void*,void*);
    void (*print)     (void*);
}
        Lista;

char/*boolean*/ insira (Lista* lis, void* inf)
{
    if (lis->inicio==NULL)
    {
        lis->inicio       = (No*)malloc(sizeof(No));
        lis->inicio->info = inf;
        return 1/*true*/;
    }

    int comp=*(lis->compareTo)(inf,lis->inicio->info);

    if (comp<0)
    {
        No* novo     = (No*)malloc(sizeof(No));
        novo->info   = inf;
        novo->prox   = lis->inicio;
        lis ->inicio = novo;
        return 1/*true*/;
    }

    if (comp==0)
        return 0/*false*/;

    No* atual = lis->inicio;

    for(;;) // parar ao achar onde inserir
    {
        if (atual->prox==NULL)
            break;

        comp=*(lis->compareTo)(inf,atual->prox->info);

        if (comp==0)
            return 0/*false*/;

        if (comp<0)
            break;

        //if (comp>0)
        atual=atual->prox;
    }

    No* novo    = (No*)malloc(sizeof(No));
    novo ->info = inf;
    novo ->prox = atual->prox;
    atual->prox = novo;
}

void remova (Lista* lis, void* inf)
{
    ...
}

void imprima (Lista lis)
{
    ...
}

int intCompareTo (int* a, int* b)
{
    if (*a<*b)
        return -666;

    if (*a==*b)
        return 0;

    //if (*a>*b)
    return 666;
}

void intPrint (int* i)
{
    prinft ("%d", *i);
}

Lista/*<int>*/ lis;

void insercao ()
{
    int* i=(int*)malloc(sizeof(int));
    printf ("Entre com o inteiro a inserir: ");
    scanf ("%d",i);
    char deuCerto = insira (&lis,(void*)i);
    if (!deuCerto)
        fprintf (stderr,"Valor repetido\n\n");
}

void remocao ()
{
    int* i=(int*)malloc(sizeof(int));
    printf ("Entre com o inteiro a remover: ");
    scanf ("%d",i);
    char deuCerto = remova (&lis,(void*)i);
    if (!deuCerto)
        fprintf (stderr,"Valor inexistente\n\n");
}

void impressao ()
{
    imprima (lis);
}

void termino ()
{
    exit(0);
}

int main ()
{
    static void (*funcao[4]) () =
            {&insercao, &remocao, &impressao, &termino};

    Lista lis;
    lis.inicio    = NULL;
    lis.compareTo = (int  (*) (void*,void*))&intCompareTo;
    lis.print     = (void (*) (void*))      &intPrint;

    for(;;)
    {
        unsigned int opcao;
        printf ("\nOpcao (0=insercao/1=remocao/2=impressao/3=termino): ");
        scanf  ("%u", &opcao);
        (*funcao[opcao]) ();
    }

    return 0;
}
