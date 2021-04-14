typedef struct produto produto;

produto *cria_produto(char *nome, float preco, int qtd);
int destroi_produto(produto *prod);

int get_prod_info(produto *prod, char *nome, float *preco, int *qtd);

int altera_preco(produto *prod, float porcentagem);
 