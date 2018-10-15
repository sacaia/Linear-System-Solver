#include <stdio.h>
#include <stdlib.h>

typedef
struct No
{
    void* info;
    struct No* prox;
}
        No;

typedef
struct Lista
{
    No*  inicio;
    //int  (*compareTo) (void*,void*);
    //void (*print)     (void*);
} Lista;
//É pra usar esse insira no  codigo
void insira(Lista * lis, void* inf)
{
    if (lis->inicio==NULL)
    {
        lis->inicio       = (No*)malloc(sizeof(No));
        lis->inicio->info = inf;
    }

    No* atual = lis->inicio;
    while(atual->prox != NULL)
        atual = atual->prox;

    No* novo    = (No*)malloc(sizeof(No));
    novo ->info = inf;
    atual->prox = novo;
}
//---------------------------------------------

double sarrus (double** matriz, int ordem);
double menorComplementar(double** matriz, int ordem, int linha, int coluna);
double cofator(double** matriz, int ordem, int linha, int coluna);
double laPlace(double** matriz, int ordem);
double* cramer (double** matrizPrincipal, double* matrizIndependente, int ordem);


int main (int argc, char **argv) {

double det;

    int ordem = 5; // depende do tamanho da matriz

    double** matriz;

    matriz = (double**)malloc(ordem*sizeof(double*));

    int i;
    for(i=0; i < ordem; i++)
        *(matriz + i) = (double*)malloc(ordem*sizeof(double));

                ( *(*(matriz + 0) + 0) ) = 1;
                ( *(*(matriz + 0) + 1) ) = 2;
                ( *(*(matriz + 0) + 2) ) = 0;
                ( *(*(matriz + 0) + 3) ) = 4;
                ( *(*(matriz + 0) + 4) ) = 5;
            ( *(*(matriz + 1) + 0) ) = 1;
            ( *(*(matriz + 1) + 1) ) = 4;
            ( *(*(matriz + 1) + 2) ) = 6;
            ( *(*(matriz + 1) + 3) ) = 8;
            ( *(*(matriz + 1) + 4) ) = 9;
        ( *(*(matriz + 2) + 0) ) = 3;
        ( *(*(matriz + 2) + 1) ) = 1;
        ( *(*(matriz + 2) + 2) ) = 2;
        ( *(*(matriz + 2) + 3) ) = 9;
        ( *(*(matriz + 2) + 4) ) = 5;
    ( *(*(matriz + 3) + 0) ) = 6;
    ( *(*(matriz + 3) + 1) ) = 0;
    ( *(*(matriz + 3) + 2) ) = 1;
    ( *(*(matriz + 3) + 3) ) = 5;
    ( *(*(matriz + 3) + 4) ) = 0;
( *(*(matriz + 4) + 0) ) = 7;
( *(*(matriz + 4) + 1) ) = 0;
( *(*(matriz + 4) + 2) ) = 1;
( *(*(matriz + 4) + 3) ) = 3;
( *(*(matriz + 4) + 4) ) = 4;

    double* matrizIndependente = (double*)malloc(ordem*sizeof(double));

    *(matrizIndependente + 0) = 0;
    *(matrizIndependente + 1) = 1;
    *(matrizIndependente + 2) = 2;
    *(matrizIndependente + 3) = 3;
    *(matrizIndependente + 4) = 4;

    Lista lista;

   det = laPlace(matriz, ordem);

    double* determinantes;

    determinantes = cramer(lista, matriz, matrizIndependente, ordem);

    double result;
    double a;
    for(i = 0; i < ordem; i++)
    {
        a = (double)*(determinantes + i);
        result = (a/(double)det);
        printf("%d\n", *(determinantes + i));
        printf("%d\n", det);
        printf("%d\n", result);

    }


    return 0;
}

double sarrus (double** matriz, int ordem) { //only if(ordem in{1, 2, 3})

    double det = 0;
    if(ordem == 1)
    {
        det = *(*(matriz + 0)+ 0);
        free(matriz[0]);
        //free(matriz);
    }
    else
    if(ordem == 2)
    {
        det =    (   ( ( *(*(matriz + 0) + 0) )*( *(*(matriz + 1) + 1) ) )
                     - ( ( *(*(matriz + 0) + 1) )*( *(*(matriz + 1) + 0) ) )
        );
        free(matriz[0]);
        free(matriz[1]);
        //free(matriz);
    }

    else
    if(ordem == 3)
    {
        det = (     ( ( *(*(matriz + 0) + 0) )*( *(*(matriz + 1) + 1) )*( *(*(matriz + 2) + 2) ) )
                    + ( ( *(*(matriz + 0) + 1) )*( *(*(matriz + 1) + 2) )*( *(*(matriz + 2) + 0) ) )
                    + ( ( *(*(matriz + 0) + 2) )*( *(*(matriz + 1) + 0) )*( *(*(matriz + 2) + 1) ) )
                    - ( ( *(*(matriz + 0) + 2) )*( *(*(matriz + 1) + 1) )*( *(*(matriz + 2) + 0) ) )
                    - ( ( *(*(matriz + 0) + 0) )*( *(*(matriz + 1) + 2) )*( *(*(matriz + 2) + 1) ) )
                    - ( ( *(*(matriz + 0) + 1) )*( *(*(matriz + 1) + 0) )*( *(*(matriz + 2) + 2) ) )
        );
        free(matriz[0]);
        free(matriz[1]);
        free(matriz[2]);
        //free(matriz);
    }

    return det;
}

double menorComplementar(double** matriz, int ordem, int linha, int coluna) {

    double** matrizAux;

    matrizAux = (double**)malloc((ordem-1)*sizeof(double*));

    int i;
    for(i=0; i < (ordem-1); i++)
        *(matrizAux + i) = (double*)malloc((ordem-1)*sizeof(double));

    int lAtual = 0;
    int cAtual = 0;

    int j;
    for(i=0; i < ordem; i++)
    {
        if(i != linha)
        {
            for(j=0; j < ordem; j++)
            {
                if(j != coluna)
                {
                    ( *(*(matrizAux + lAtual) + cAtual) ) = ( *(*(matriz + i) + j) );
                    cAtual++;
                }

            }
            cAtual=0;
            lAtual++;
        }

    }

    if((ordem-1) <= 3)
        return sarrus(matrizAux, (ordem-1));
    else
        return laPlace(matrizAux, (ordem-1));

}

double cofator(double** matriz, int ordem, int linha, int coluna) {

    int sinal;

    if((linha+coluna) % 2 == 0)
        sinal = 1;
    else
        sinal = -1;

    return (sinal * menorComplementar(matriz, ordem, linha, coluna) );
}

double laPlace(double** matriz, int ordem) { // ainda n é definitivo

    int i;
    double ret;
    ret = 0;
    for(i=0; i < ordem; i++)
    {
        ret += ( ( *(*(matriz + i) + 0) )*cofator(matriz, ordem, i, 0) );
    }

    return ret;
}

double* cramer (double** matrizPrincipal, double* matrizIndependente, int ordem) {

    double* ret = (double*)malloc(ordem*sizeof(double));

    double** matrizAux;

    matrizAux = (double**)malloc(ordem*sizeof(double*));

    int i;
    for(i=0; i < ordem; i++)
        *(matrizAux + i) = (double*)malloc(ordem*sizeof(double));

    int j;
    for(i =0; i < ordem; i++)
    {
        for(j=0; j<ordem; j++)
        {
            ( *(*(matrizAux + i) + j) ) = ( *(*(matrizPrincipal + i) + j) );
        }

    }

    for(i=0; i < ordem; i++)
    {
        for(j=0; j<ordem; j++)
        {
            ( *(*(matrizAux + i) + j) ) = *(matrizIndependente + j);
        }
        *(ret + i) = laPlace(matrizAux, ordem);
        for(j=0; j<ordem; j++)
        {
            ( *(*(matrizAux + i) + j) ) = ( *(*(matrizPrincipal + i) + j) );
        }
    }

    return ret;
}
