#include <stdlib.h>

int main()
{
    printf("Digite o nome do arquivo: \n");
    scanf("%s", nome_arq);
    FILE* file = fopen(nome_arq, "r");

    if(fil == NULL)
        printf("Deu ruim!");
    else
    {
    	float** matriz;
        int ordem;

        fscanf(file,"%i", &ordem);
        char a = fgetc(file);
        printf("%c", acmd);

        matriz =(float**)malloc(ordem*sizeof(float*));

        int i;
        for(i=0; i<ordem;i++)
        	*(matriz + i) = (float*)malloc(ordem*sizeof(float));

        for(;;)
        {
            char a = fgetc(file);

            if(a == EOF)
                break;
            if(a == '\n')
                continue;

        }
    }

    return 0;
}
