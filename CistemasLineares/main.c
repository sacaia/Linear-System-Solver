#include <stdio.h>
#include <stdlib.h>

int sarrus (int** matriz, int ordem);
int menorComplementar(int** matriz, int ordem, int linha, int coluna);
int cofator(int** matriz, int ordem, int linha, int coluna);
int laPlace(int** matriz, int ordem);

typedef
    enum
    {
        Coef,
        Incog,
        IndTerm,
        Sinal
    }Estado;

typedef
    enum
    {
        false,
        true
    }boolean;

void addChar(char c, char *s) {
    int len = strlen(s);
    *(s + len) = c;
    *(s + len + 1) = '\0';
}

char* criarString() {
    char *s = malloc(MAX_LENGTH);
    *s = '\0';
    return s;
}

int main (int argc, char **argv) {

/*------------------------------------Le o arquivo------------------------------------*/
    char* nome_arq;

    printf("Digite o nome do arquivo: \n");
    scanf("%s", &nome_arq);
    FILE* file;
    file = fopen(nome_arq, "r");

    if(file == NULL)
        printf("Deu ruim!");
    else
    {
        float** matriz;
        float*  termosInd;
        int ordem;

        fscanf(file,"%i", &ordem);

        termosInd = (float*)malloc(ordem* sizeof(float));
        matriz =(float**)malloc(ordem*sizeof(float*));

        int i;
        for(i=0; i<ordem;i++)
            *(matriz + i) = (float*)malloc(ordem*sizeof(float));

        Estado estado = Coef;
        boolean sinal = true;
        char charAtual;
        int Rctrl = 0;
        int Cctrl = 0;
        char* elementoAtual = criarString();
        fgetc(file);
        for(;;) {
            int qtasIncog = 0;
            charAtual = fgetc(file);

            if(charAtual == EOF)
            {
                if(sinal)
                    *(termosInd+Rctrl) = atof(elementoAtual);
                else
                    *(termosInd+Rctrl) = -atof(elementoAtual);
                free(elementoAtual);

                break;
            }

            if(charAtual == ' ' || charAtual == '*')
                continue;

            if (isdigit(charAtual) || charAtual=='.')
            {
                addChar(charAtual, elementoAtual);
                estado = Coef;
                continue;
            }

            if (isalpha(charAtual)) {
                if (estado == Coef) {
                    //printf("Chegou no coefinho?: %s", elementoAtual);
                    if(sinal)
                        *(*(matriz + Rctrl) + Cctrl) = atof(elementoAtual);
                    else
                        *(*(matriz + Rctrl) + Cctrl) = -atof(elementoAtual);

                    //printf("\n %f",  *(*(matriz + Rctrl) + Cctrl));
                    free(elementoAtual);
                    elementoAtual = criarString();
                    Cctrl++;
                }

                if(estado == Sinal || estado == IndTerm)
                {
                    if(sinal)
                        *(*(matriz + Rctrl) + Cctrl)  = 1.0;
                    else
                        *(*(matriz + Rctrl) + Cctrl) = -1.0;

                   // printf("\n %f",  *(*(matriz + Rctrl) + Cctrl));
                    free(elementoAtual);
                    elementoAtual = criarString();
                    Cctrl++;
                }

                //printf("Chegou no finalzinho?");
                estado =  Incog;
                addChar(charAtual, elementoAtual);

                continue;
            }

            if (charAtual == '+')
            {
                if(estado == Incog)
                {
                    //lista.insira(incog);
                    free(elementoAtual);
                    elementoAtual = criarString();
                }
                if(estado == Sinal)
                {
                    printf("\n Erro de sintaxe!");
                    exit(666);
                }

                sinal = true;
                estado = Sinal;

                continue;
            }

            if (charAtual == '-')
            {
                if(estado == Incog)
                {
                    if(qtasIncog < ordem)
                    {
                        //lista.insira(incog);
                        qtasIncog++
                    }

                    free(elementoAtual);
                    elementoAtual = criarString();
                }
                if(estado == Sinal)
                {
                    printf("\n Erro de sintaxe!");
                    exit(666);
                }

                sinal = false;
                estado = Sinal;

                continue;
            }

            if(charAtual == '=')
            {
                if(estado == Incog)
                {
                    if(qtasIncog < ordem)
                    {
                        //lista.insira(incog);
                        qtasIncog++
                    }
                    free(elementoAtual);
                    elementoAtual = criarString();
                }

                estado = IndTerm;

                continue;
            }

            if (charAtual == '\n') {
                if(sinal)
                    *(termosInd+Rctrl) = atof(elementoAtual);
                else
                    *(termosInd+Rctrl) = -atof(elementoAtual);
                free(elementoAtual);
                elementoAtual = criarString();
                Rctrl++;
                Cctrl = 0;
                estado = IndTerm;
                continue;
            }
        }
/*------------------------------------------------------------------------*/

    int det = 0;

    /*int ordem = 5; // depende do tamanho da matriz

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
( *(*(matriz + 4) + 4) ) = 4;*/



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

