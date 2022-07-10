#include "../include/catalogo_produtos.h"
#include "../include/filial.h"

#define LETRAS 26
#define HASHNUMBER 151

struct produtos{
	AVL tabela_produtos[LETRAS][LETRAS][HASHNUMBER];
};


// Função que dado uma string (valor), devolve uma posição (index, hash key)
void hF_produtos(int index[3], char value[]){
	int s = 0, c = 0;
	for(int i = 2; i < strlen(value); i++){
		s = value[i]; c+=s; c*=s;
	}

	c = abs(c % HASHNUMBER);

	index[0] = value[0] - 65;
	index[1] = value[1] - 65;
	index[2] = c;
}

// Função que insere um index, de tipologia Produto, numa estrutura de dados
int insert_produto(Produtos p, char* id){
	int index[3]; index[0] = 0, index[1] = 0, index[2] = 0;
	int nID = num_(id,2);
	hF_produtos(index, id);

	p->tabela_produtos[index[0]][index[1]][index[2]] = insert_tree(p->tabela_produtos[index[0]][index[1]][index[2]] , nID, id, 'b');
	return index[0];
}

// Função que, aplicando a Hash Funtion, verifica se uma posição da Treetable existe
int search_P(Produtos p, char* id){
	int r = 0, nID = num_(id,2);
	int index[3]; index[0] = 0, index[1] = 0, index[2] = 0;

	if(atoi(id)==0){
		hF_produtos(index,id);
		r = search_tree(p->tabela_produtos[index[0]][index[1]][index[2]], nID);
	}
	else r=0;

	return r;
}

// Função que valida um id de um produto
int valida_produto(char* id){
	int r = 0;

	if(strlen(id) != 6) return 0;

	if(isupper(id[0]) && isupper(id[1]))							
		if(('1'<=id[2]) && (id[2]<='9'))
			for(int n = 3; n < 6; n++){
				if(isdigit(id[n])) r = 1;
				else return 0;
			}

	return r;
}

// Função que lê de um ficheiro de produtos
void load_produtos(Produtos p, char* path, int num[2], Filial f){
	char linha[7];
	int i1 = 0, i2 = 0;
	FILE* file = fopen(path , "r");
	
	while( fgets(linha, 7, file) ){
		if(valida_produto(linha)){
			insert_produto(p, linha);
			f_produto(f, linha);
			i1++;
		}
		i2++;
	}


	num[0] = i1;
	num[1] = i2; 
	fclose(file);
}

//Função que inicializa as estruturas, escreve na posição 2 e 3 do array
Produtos iniciar_produtos(int* num, Filial f){
	Produtos p = malloc(sizeof(struct produtos));
	int valores[2];

	for (int i = 0; i < LETRAS; i++){
		for (int j = 0; j < LETRAS; j++)
			for(int k = 0; k < HASHNUMBER; k++)
				p->tabela_produtos[i][j][k] = NULL;
	}
	
	load_produtos(p,PATH_P, valores, f);

	num[2] = valores[0];
	num[3] = valores[1];
	return p;
}

// Função que
void print_simples(Lista_Strings lista, AVL a){

	if(a){
		print_simples(lista,esq(a));
		if(valor(a)){
			add_lista(lista, codigo(a));
		}
		print_simples(lista,dir(a));
	}
}

// Função que
void lista_produtos(Produtos p, char letra, Lista_Strings lista){
	int l1  = letra - 'A';

	for(int l2 = 0; l2 < LETRAS; l2++)
		for(int h = 0; h < HASHNUMBER; h++)
			print_simples(lista, p->tabela_produtos[l1][l2][h]);
}

// Função que liberta o espaço alocado para a estrutura
void free_produtos(Produtos p){
	
	for (int i = 0; i < LETRAS; i++){
		for (int j = 0; j < LETRAS; j++)
			for(int k = 0; k < HASHNUMBER; k++)
				free_AVL(p->tabela_produtos[i][j][k], 'b');
	}
}
