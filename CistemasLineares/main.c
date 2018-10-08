#include <stdio.h>
#include <stdlib.h>



int sarrus (int** matriz, int ordem) { //only if(ordem in{1, 2, 3})

    int det = 0;
    if(ordem == 1)
        det = *(*(matriz + 0)+ 0);
    else
    if(ordem == 2)
        det =    (   ( ( *(*(matriz + 0) + 0) )*( *(*(matriz + 1) + 1) ) )
                   - ( ( *(*(matriz + 0) + 1) )*( *(*(matriz + 1) + 0) ) )
                 );
    else
    if(ordem == 3)
        det = (     ( ( *(*(matriz + 0) + 0) )*( *(*(matriz + 1) + 1) )*( *(*(matriz + 2) + 2) ) )
                  + ( ( *(*(matriz + 0) + 1) )*( *(*(matriz + 1) + 2) )*( *(*(matriz + 2) + 0) ) )
                  + ( ( *(*(matriz + 0) + 2) )*( *(*(matriz + 1) + 0) )*( *(*(matriz + 2) + 1) ) )
                  - ( ( *(*(matriz + 0) + 2) )*( *(*(matriz + 1) + 1) )*( *(*(matriz + 2) + 0) ) )
                  - ( ( *(*(matriz + 0) + 0) )*( *(*(matriz + 1) + 2) )*( *(*(matriz + 2) + 1) ) )
                  - ( ( *(*(matriz + 0) + 1) )*( *(*(matriz + 1) + 0) )*( *(*(matriz + 2) + 2) ) )
        );
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
        return 0;//laPlace(matrizAux, (ordem-1));
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

int main (int argc, char **argv) {

    int det = 0;

    int ordem = 3; // depende do tamanho da matriz

    int** matriz;

    matriz = (int**)malloc(ordem*sizeof(int*));

    int i;
    for(i=0; i < ordem; i++)
        *(matriz + i) = (int*)malloc(ordem*sizeof(int));


        ( *(*(matriz + 0) + 0) ) = 1;
        ( *(*(matriz + 0) + 1) ) = 2;
        ( *(*(matriz + 0) + 2) ) = 3;
    ( *(*(matriz + 1) + 0) ) = 4;
    ( *(*(matriz + 1) + 1) ) = 0;
    ( *(*(matriz + 1) + 2) ) = 7;
( *(*(matriz + 2) + 0) ) = 3;
( *(*(matriz + 2) + 1) ) = 1;
( *(*(matriz + 2) + 2) ) = 2;


    det = sarrus(matriz, ordem);

   int lPlace;

   lPlace = laPlace(matriz, ordem);

    printf("%d\n", lPlace);



    return 0;
}
