void main()
{
    printf("Digite o nome do arquivo: \n");
    scanf("%s", nome_arq);
    FILE* fil = fopen(nome_arq, "r");

    if(fil == NULL)
        printf("Deu ruim!");
    else
    {
        int tamanhoDaMatriz;
        fscanf(fil,"%i", &tamanhoDaMatriz);

        matriz =(float*)malloc(tamanhoDaMatriz*sizeof(float));

    }
}
