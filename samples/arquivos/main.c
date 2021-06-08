#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct aluno
{
    int matricula;
    char nome[30];
    float n1, n2, n3;
};

int main(int argc, char *argv[])
{

    for (int i = 0; i < argc; i++)
    {
        printf("\nParametro %d: %s\n", i, argv[i]);
    }

    if (strcmp(argv[1], "-ler") == 0)
    {
        FILE *fp;
        fp = fopen(argv[2], "rb");
        if (fp == NULL)
        {
            printf("Erro! Arquivo nao encontrado");
            exit(1);
        }
        char str1[20], str2[20];
        float vx;
        int a[5], b[2];
        int count;

        count = fread(str1, sizeof(char), 12, fp);
        printf("\nElementos lidos: %u", count);
        str1[12] = '\0';
        printf("\nValor lido: %s", str1);

        count = fread(str2, sizeof(char), 5, fp);
        printf("\nElementos lidos: %u", count);
        str2[5] = '\0';
        printf("\nValor lido: %s", str2);

        count = fread(&vx, sizeof(float), 1, fp);
        printf("\nElementos lidos: %u", count);
        printf("\nValor lido: %f", vx);

        count = fread(a, sizeof(int), 5, fp);
        printf("\nElementos lidos: %u", count);
        for (int i = 0; i < 5; i++)
            printf("\nValor lido: %d", a[i]);

        count = fread(b, sizeof(int), 2, fp);
        printf("\nElementos lidos: %u", count);
        for (int i = 0; i < 2; i++)
            printf("\nValor lido: %d", b[i]);

        fclose(fp);
    }
    else if (strcmp(argv[1], "-escrever") == 0)
    {

        FILE *fp;
        fp = fopen(argv[2], "wb");
        if (fp == NULL)
        {
            printf("Erro! Arquivo nao encontrado");
            exit(1);
        }
        else
        {
            printf("Arquivo aberto: %s", argv[2]);
        }
        char str[20] = "Hello World!";
        float x = 35;
        int vec[5] = {-1, -552, 44443, 654, 5};

        // gravando a string
        //           tam: 1       12 caracteres
        unsigned int count;
        count = fwrite(str, sizeof(char), strlen(str), fp);
        printf("\nElementos escritos: %u", count);

        // gravando os 5 primeiros da string
        count = fwrite(str, sizeof(char), 5, fp);
        printf("\nElementos escritos: %u", count);

        // grava x
        count = fwrite(&x, sizeof(float), 1, fp);
        printf("\nElementos escritos: %u", count);

        // gravar array vec
        count = fwrite(vec, sizeof(int), 5, fp);
        printf("\nElementos escritos: %u", count);

        // gravar 2 posicoes vec
        count = fwrite(&vec[2], sizeof(int), 2, fp);
        printf("\nElementos escritos: %u", count);

        fclose(fp);
    }
    else if (strcmp(argv[1], "-adicionar") == 0)
    {
        char v[12] = "modificado\n";
        FILE *fp = fopen(argv[2], "ab");
        if (fp == NULL)
        {
            printf("Erro!");
            exit(1);
        }
        fwrite(v, sizeof(char), strlen(v), fp);
        fclose(fp);
    }
    else if (strcmp(argv[1], "-aluno") == 0)
    {
        struct aluno a, b, c, d, temp;
        strcpy(a.nome, "Joao");
        a.matricula = 1;
        a.n1 = 0;
        a.n2 = 2;
        a.n3 = 0;

        strcpy(b.nome, "Maria");
        b.matricula = 2;
        b.n1 = 2;
        b.n2 = 0;
        b.n3 = 0;

        strcpy(c.nome, "Jose");
        c.matricula = 3;
        c.n1 = 0;
        c.n2 = 0;
        c.n3 = 4;

        strcpy(d.nome, "Ana");
        d.matricula = 4;
        d.n1 = 0;
        d.n2 = 0;
        d.n3 = 2;
       
        FILE *fp;
        fp = fopen(argv[2],"wb");

        fwrite(&a,sizeof(struct aluno),1,fp);
        fwrite(&b,sizeof(struct aluno),1,fp);
        fwrite(&c,sizeof(struct aluno),1,fp);
        fwrite(&d,sizeof(struct aluno),1,fp);                        
        fclose(fp);

        fp = fopen(argv[2],"rb");
        int pos;
        sscanf(argv[3],"%d", &pos);
        fseek(fp,sizeof(struct aluno)*(pos-1),SEEK_SET);
        fread(&temp,sizeof(struct aluno),1, fp);
        printf("(%d) Nome: %s", temp.matricula,  temp.nome);

        fseek(fp,sizeof(struct aluno)*1,SEEK_CUR);
        fread(&temp,sizeof(struct aluno),1, fp);
        printf("(%d) Nome: %s", temp.matricula,  temp.nome);

        fclose(fp);


        
    }

    /*
    {
        FILE *fp;
        fp = fopen("g:\\arq\\ed1.bin", "wb");
        if (fp == NULL)
        {
            printf("Erro!");
            exit(1);
        }
        fclose(fp);
    }

    {

        // criando um arquivo texto
        printf("\n\n========TESTE 2 ==========\n\n");

        // gravando a string, caracter por caracter
        FILE *arq;
        arq = fopen("g:\\arq\\ed1_ex2.txt", "w");
        if (arq == NULL)
        {
            printf("Erro");
            exit(1);
        }

        char string[100];
        printf("Digite o texto a ser salvo:");
        gets(string);

        int i = 0;
        printf("Escrevendo:");
        for (i = 0; i < strlen(string); i++)
        {
            fputc(string[i], arq);
            printf("%c", string[i]);
        }
        fclose(arq);
    }
    
    {

        // lendo um arquivo texto
        printf("\n\n========TESTE 3 ==========\n\n");

        FILE *arq;
        char c;
        arq = fopen("G:\\ARQ\\ed1_ex2.txt", "r");
        if (arq == NULL)
        {
            printf("Erro");
            exit(1);
        }
        int i;
        for (i = 0; i < 10; i++)
        {
            c = fgetc(arq);
            if (c == -1) printf("encontrado -1!!\n");
            if (c == EOF) printf("encontrado EOF!!\n");
            printf("%c", c);
        }
        fclose(arq);
    }

    {
        // criando um arquivo texto
        printf("\n\n========TESTE 3 EOF ==========\n\n");

        FILE *arq;
        char c;
        arq = fopen("g:\\arq\\ed1_ex2.txt", "r");
        if (arq == NULL)
        {
            printf("Erro");
            exit(1);
        }
        int i;
        while ((c = fgetc(arq)) != EOF)
        {
            printf("%c", c);
        }
        fclose(arq);
    }


    {

        // criando um arquivo texto
        printf("\n\n========TESTE 4 - FEOF ==========\n\n");

        FILE *arq;
        char c;
        arq = fopen("g:\\arq\\ed1_ex2.txt", "r");
        if (arq == NULL)
        {
            printf("Erro");
            exit(1);
        }
        int i;
        while (!feof(arq))
        {
            c = fgetc(arq);
            printf("%c", c);
        }
        fclose(arq);
    }


    {

        // criando um arquivo texto
        printf("\n\n========TESTE 5 - FEOF ==========\n\n");

        FILE *arq;
        char str[30] = "teste escrita string";
        arq = fopen("g:\\arq\\ed1_ex5.txt", "w");
        if (arq == NULL)
        {
            printf("Erro");
            exit(1);
        }

        int result;
        result = fputs(str, arq);

        if (result == EOF)
        {
            printf("Erro!");
            exit(1);
        }
        else
        {
            printf("Valor retornado: %d", result);
        }
        fclose(arq);
    }

    {

        // criando um arquivo texto
        printf("\n\n========TESTE 6 - fgets ==========\n\n");

        FILE *arq;
        char str[30];

        arq = fopen("g:\\arq\\ed1_ex5.txt", "r");
        if (arq == NULL)
        {
            printf("Erro");
            exit(1);
        }

        char *result;
        result = fgets(str, 7, arq);

        if (str == NULL)
        {
            printf("\nNão serão!");
        }
        if (result == NULL)
        {
            printf("Erro!");
            exit(1);
        }
        else
        {
            printf("\n|%s|", str);
        }
        fclose(arq);
    }
*/
    return 0;
}