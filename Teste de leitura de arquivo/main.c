#include <ctype.h>
#include <string.h>
#include <stdio.H>

int main()
{
    char* nome_arq;

    printf("Digite o nome do arquivo: \n");
    scanf("%s", &nome_arq);
    FILE* file;
    file = fopen("C:\\Users\\Luciano\\Desktop\\a.txt", "r");

    if(file == NULL)
        printf("Deu ruim!");
    else
    {
        float** matriz;
        int ordem;

        fscanf(file,"%i", &ordem);
        printf("%i", ordem);

        matriz =(float**)malloc(ordem*sizeof(float*));

        int i;
        for(i=0; i<ordem;i++)
            *(matriz + i) = (float*)malloc(ordem*sizeof(float));

        int j;
        int k;
        for(j=0;j<ordem;ordem++)
        {
            for(k=0;k<ordem;k++)
            {
                float coef;
                fscanf(file, "%f", &coef);
                *(*(matriz + j)+k) = coef;

                if(j==0)
                {
                    char incognita;
                    fscanf(file, "%c", &incognita);
                    //lista.insira(incognita);
                }
            }

            while(fgetc(file)!='='); //pega tudo até o igual

            float termInd;
            fscanf(file, "%f", &termInd);
            //coloca na matriz de termos independentes na posição j
        }
    }

    return 0;
}





/*char a = fgetc(file);
char* elementoAtual =  "";

if(a == EOF)
    break;

if(a == '\n')
    continue;

if(isdigit(a))
{
    if(coeficiente == 0)
    {
        //lista.inserir(elementoAtual);
        elementoAtual = "";
        coeficiente = 1;
    }
    elementoAtual += a;
}
if(isalpha(a))
{
    if(coeficiente == 1)
    {
        *(*(matriz + Rctrl)+ Cctrl) = atoi(elementoAtual);
    }

}
if(a == "+" || a == "-")
{

}*/
