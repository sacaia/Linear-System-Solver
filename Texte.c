#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX_LENGTH 100

typedef struct sNo
{
    void* info;
    struct sNo* prox;
} No;
typedef struct
{
    No* prim;
} Lista;

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

void inserirComeco(Lista* lista, void* info)
{
    No* novoPrim = (No*)malloc(sizeof(No));
    (*novoPrim).info = info;
    (*novoPrim).prox = (*lista).prim;

    (*lista).prim = novoPrim;
}

//É pra usar esse insira no  codigo
void insira(Lista* lista, void* info)
{
    if ((*lista).prim == NULL)
    {
        inserirComeco(lista, info);
        return;
    }

    No* atual = (*lista).prim;
    while ((*atual).prox != NULL)
        atual = (*atual).prox;

    No* novo = (No*)malloc(sizeof(No));
    (*novo).info = info;
    (*novo).prox = NULL;

    (*atual).prox = novo;
}
//---------------------------------------------

float sarrus (float** matriz, int ordem);
float menorComplementar(float** matriz, int ordem, int linha, int coluna);
float cofator(float** matriz, int ordem, int linha, int coluna);
float laPlace(float** matriz, int ordem);
float* cramer (float** matrizPrincipal, float* matrizIndependente, int ordem);


int main (int argc, char **argv) {
/*Le o arquivo*/
	char* nome_arq;

    printf("Digite o nome do arquivo: \n");

    scanf("%s", &nome_arq);
    FILE* file;
    file = fopen("c:\\Temp\\a.txt.txt"/*&nome_arq*/, "r");

    if(file == NULL)
        printf("Deu ruim!");
    else
    {
        float** matriz;
        float*  termosInd;
        int ordem;
        //;Lista* lis = (Lista*)malloc(sizeof(Lista));

        fscanf(file,"%i", &ordem);

        char** incogs= (char**)malloc(ordem*sizeof(char*));
        int z;
        for(z = 0; z<ordem; z++)
        {
            *(incogs +z) = (char*)malloc(20*sizeof(char));
            strcpy(*(incogs +z), "                   \0");
        }


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
        int qtasIncog = 0;
        char* elementoAtual = criarString();
        fgetc(file);
        for(;;) {
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
                    if(sinal)
                        *(*(matriz + Rctrl) + Cctrl) = atof(elementoAtual);
                    else
                        *(*(matriz + Rctrl) + Cctrl) = -atof(elementoAtual);

                    free(elementoAtual);
                    elementoAtual = criarString();
                    Cctrl++;

                    //printf("Saas: %s", elementoAtual);
                }

                if(estado == Sinal || estado == IndTerm)
                {
                    if(sinal)
                        *(*(matriz + Rctrl) + Cctrl)  = 1.0;
                    else
                        *(*(matriz + Rctrl) + Cctrl) = -1.0;

                    free(elementoAtual);
                    elementoAtual = criarString();
                    Cctrl++;
                }

                estado =  Incog;
                addChar(charAtual, elementoAtual);

                continue;
            }

            if (charAtual == '+')
            {
                if(estado == Incog)
                {
                    //insira(lis, elementoAtual);
                    if(qtasIncog <= ordem)
                    {
                         *(incogs + qtasIncog) = elementoAtual;
                         qtasIncog++;
                    }

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
                	if(qtasIncog <= ordem)
                    {
                    	//insira(lis, elementoAtual);
                    	*(incogs + qtasIncog) = elementoAtual;
                    	qtasIncog++;
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
                    if(qtasIncog <= ordem)
                    {
                    	//insira(lis, elementoAtual);
                    	*(incogs + qtasIncog) = elementoAtual;
                    	qtasIncog++;
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
/*-------------*/
/*
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
*/
    float det;

    float** matrizAux;

    matrizAux = (float**)malloc(ordem*sizeof(float*));


    for(i=0; i < ordem; i++)
        *(matrizAux + i) = (float*)malloc(ordem*sizeof(float));

    int j;
    for(i=0;i<ordem;i++)
    {
        for(j=0;j<ordem;j++)
        {
            ( *(*(matrizAux + i) + j) ) = ( *(*(matriz + i) + j) );
        }
    }

    if(ordem < 4)
        det = sarrus(matrizAux, ordem);
    else
        det = laPlace(matrizAux, ordem);

    float* determinantes;

    determinantes = cramer(matriz, termosInd, ordem);

    double result;
    for(i = 0; i < ordem; i++)
    {
        result = ((double)(*(determinantes + i))/(double)det);
        printf("%s: %.2f\n", *(incogs + i),result);

    }


    return 0;
}
}

float sarrus (float** matriz, int ordem) { //only if(ordem in{1, 2, 3})

    float det = 0;
    if(ordem == 1)
    {
        det = *(*(matriz + 0)+ 0);
        //free(matriz[0]);
        //free(matriz);
    }
    else
    if(ordem == 2)
    {
        det =    (   ( ( *(*(matriz + 0) + 0) )*( *(*(matriz + 1) + 1) ) )
                     - ( ( *(*(matriz + 0) + 1) )*( *(*(matriz + 1) + 0) ) )
        );
        //free(matriz[0]);
        //free(matriz[1]);
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
        //free(matriz[0]);
        //free(matriz[1]);
        //free(matriz[2]);
        //free(matriz);
    }

    return det;
}

float menorComplementar(float** matriz, int ordem, int linha, int coluna) {

    float** matrizAux;

    matrizAux = (float**)malloc((ordem-1)*sizeof(float*));

    int i;
    for(i=0; i < (ordem-1); i++)
        *(matrizAux + i) = (float*)malloc((ordem-1)*sizeof(float));

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

float cofator(float** matriz, int ordem, int linha, int coluna) {

    int sinal;

    if((linha+coluna) % 2 == 0)
        sinal = 1;
    else
        sinal = -1;

    return (sinal * menorComplementar(matriz, ordem, linha, coluna) );
}

float laPlace(float** matriz, int ordem) { // ainda n é definitivo

    int i;
    float ret;
    ret = 0;
    for(i=0; i < ordem; i++)
    {
        ret += ( ( *(*(matriz + i) + 0) )*cofator(matriz, ordem, i, 0) );
    }

    return ret;
}

float* cramer (float** matrizPrincipal, float* matrizIndependente, int ordem) {

    float* ret = (float*)malloc(ordem*sizeof(float));

    float** matrizAux;

    matrizAux = (float**)malloc(ordem*sizeof(float*));

    int i;
    for(i=0; i < ordem; i++)
        *(matrizAux + i) = (float*)malloc(ordem*sizeof(float));

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
            ( *(*(matrizAux + j) + i) ) = *(matrizIndependente + j);
        }
        if(ordem < 4)
            *(ret + i) = sarrus(matrizAux, ordem);
        else
            *(ret + i) = laPlace(matrizAux, ordem);
        for(j=0; j<ordem; j++)
        {
            ( *(*(matrizAux + j) + i) ) = ( *(*(matrizPrincipal + j) + i) );
        }
    }

    return ret;
}
