#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX_LENGTH 100

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

int main() {
    char* nome_arq;

    printf("Digite o nome do arquivo: \n");
    scanf("%s", nome_arq);
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

            if (isdigit(charAtual))
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
                    if(qtasIncog < ordem)
                    {
                    	//lista.insira(incog);
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

        /*int j;
        for(i = 0; i < ordem; i++)
        {
            for (j = 0; j < ordem; j++) {
                printf("%f", *(*(matriz +i)+j));
            }
            printf("\n");
        }

        printf("\n");
        for(i = 0; i<ordem; i++)
            printf("%f ", *(termosInd+i));*/
    }
}