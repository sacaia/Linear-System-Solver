#include <stdio.h>
#include <stdlib.h>

typedef
struct No
{
    char*  variavel;
    int*      valor;
    struct No* prox;
}
        No;

typedef
struct Lista
{
    No*  inicio;
    //int  (*compareTo) (void*,void*);
    //void (*print)     (void*);
}
        Lista;
int sarrus (int** matriz, int ordem);
int menorComplementar(int** matriz, int ordem, int linha, int coluna);
int cofator(int** matriz, int ordem, int linha, int coluna);
int laPlace(int** matriz, int ordem);
void cramer (Lista lista, int** matrizPrincipal, int** matrizIndependente, int ordem);

int main (int argc, char **argv) {

    int det = 0;

    int ordem = 5; // depende do tamanho da matriz

    int** matriz;

    matriz = (int**)malloc(ordem*sizeof(int*));

    int i;
    for(i=0; i < ordem; i++)
        *(matriz + i) = (int*)malloc(ordem*sizeof(int));

                ( *(*(matriz + 0) + 0) ) = 1;
                ( *(*(matriz + 0) + 1) ) = 2;
                ( *(*(matriz + 0) + 2) ) = 3;
                ( *(*(matriz + 0) + 3) ) = 4;
                ( *(*(matriz + 0) + 4) ) = 5;
            ( *(*(matriz + 1) + 0) ) = 2;
            ( *(*(matriz + 1) + 1) ) = 4;
            ( *(*(matriz + 1) + 2) ) = 6;
            ( *(*(matriz + 1) + 3) ) = 8;
            ( *(*(matriz + 1) + 4) ) = 10;
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



   det = laPlace(matriz, ordem);


    printf("%d\n", det);



    return 0;
}

int sarrus (int** matriz, int ordem) { //only if(ordem in{1, 2, 3})

    int det = 0;
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

int menorComplementar(int** matriz, int ordem, int linha, int coluna) {

    int** matrizAux;

    matrizAux = (int**)malloc((ordem-1)*sizeof(int*));

    int i;
    for(i=0; i < (ordem-1); i++)
        *(matrizAux + i) = (int*)malloc((ordem-1)*sizeof(int));

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

int cofator(int** matriz, int ordem, int linha, int coluna) {

    int sinal;

    if((linha+coluna) % 2 == 0)
        sinal = 1;
    else
        sinal = -1;

    return (sinal * menorComplementar(matriz, ordem, linha, coluna) );
}

int laPlace(int** matriz, int ordem) { // ainda n é definitivo

    int i, ret;
    ret = 0;
    for(i=0; i < ordem; i++)
    {
        ret += ( ( *(*(matriz + i) + 0) )*cofator(matriz, ordem, i, 0) );
    }

    return ret;
}

void cramer (Lista lista, int** matrizPrincipal, int** matrizIndependente, int ordem) {

    int** matrizAux;

    matrizAux = (int**)malloc(ordem*sizeof(int*));

    int i;
    for(i=0; i < ordem; i++)
        *(matrizAux + i) = (int*)malloc(ordem*sizeof(int));

    int j;
    for(i =0; i < ordem; i++)
    {
        for(j=0; j<ordem; j++)
        {
            ( *(*(matrizAux + i) + j) ) = ( *(*(matrizPrincipal + i) + j) );
        }

    }
}
