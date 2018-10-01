#include <stdlib.h>

int main (int argc, char **argv) {

    int det;

    int ordem; // depende do tamanho da matriz
    ordem = 3;

    int** matriz;
    matriz = (int**)malloc(ordem*sizeof(int*));

    int i;
    for(i=0; i < ordem; i++)
        *(matriz + i) = (int*)malloc(ordem*sizeof(int));

    if(ordem == 1)
        det = *(*(matriz + 0)+ 0);
    else
        if(ordem = 2)
            det = ( ( *(*(matriz + 0)+ 0) )*( *(*(matriz + 1) + 1) ) -( ( *(*(matriz + 0) + 1) )*( *(*(matriz + 1) + 0) ) ) )
        else
            if(ordem = 3)
                det = //agr vai fica gigante


   return 0;
}
