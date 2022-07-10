#include "../include/catalogo_clientes.h"
#include "../include/AVL.h"

/*

No ficheiro Clientes.txt cada linha representa o código de um cliente identificado no hipermercado, sendo cada
código de cliente formado por uma letra maiúscula e 4 dígitos que representam um inteiro entre 1000 e 5000, cf. os exemplos:

F2916 / W1219 / F4999

*/

#define LETRAS 26
#define HASHNUMBER 599

struct clientes{
	AVL tabela_clientes[LETRAS][HASHNUMBER];
};


// Função que dado uma string (valor), devolve uma posição (index, hash key)
void hF_clientes(int index[2], char value[]){
	int s = 0, c = 0;
	for(int i = 1; i < strlen(value); i++){
		s = value[i]; c+=s; c*=s;
	}

	c = abs(c % HASHNUMBER);

	index[0] = value[0] - 65;
	index[1] = c;
}

// Função que insere um index, de tipologia Cliente, numa estrutura de dados
void insert_cliente(Clientes c, char* id){
	int index[2]; index[0] = 0, index[1] = 0;
	int nID = num_(id,1);

	hF_clientes(index, id);

	c->tabela_clientes[index[0]][index[1]] = insert_tree(c->tabela_clientes[index[0]][index[1]], nID, id, 'b');
}

// Função que verifica se um id existe na estrutura
int search_C(Clientes c, char* id){
	int r = 0, nID = num_(id,1);
	int index[2]; index[0] = 0, index[1] = 0;

	if(id[0] >  'Z' || id[0] < 'A')
		return 0;

	hF_clientes(index,id);

	r = search_tree(c->tabela_clientes[index[0]][index[1]], nID);
	return r;
}

// Função que valida um id de um cliente
int valida_cliente(char * id){
	int r = 0;

	if(strlen(id) != 5) return 0;

	if(isupper(id[0])){
		if(('1'<=id[1]) && (id[1]<='4'))
			for(int n = 2; n < 5; n++){
				if(isdigit(id[n])) r = 1;
				else return 0;
			}

		if('5'<=id[1])
			for(int n = 2; n < 5; n++){
				if(id[n] != '0') return 0;
				else r = 1;
			}
	}

	return r;
}

// Função que lê de um ficheiro de clientes
void load_clientes(Clientes c, char* path, int num[2], Filial f){
	char linha[6];
	int i1 = 0, i2 = 0;
	FILE* file = fopen(path , "r");

	while(fgets(linha, 6, file)){
		if(valida_cliente(linha)){
			insert_cliente(c,linha);
			f_cliente(f, linha);
			i1++;
		}
		i2++;
	}

	num[0] = i1;
	num[1] = i2;
	fclose(file);

}


// Função que inicializa a estrutura, escreve na posição 0 e 1 do array
Clientes iniciar_clientes(int* num, Filial f){
	Clientes c = malloc(sizeof(struct clientes));
	int valores[2];

	for (int i = 0; i < LETRAS; i++)
		for(int j = 0; j < HASHNUMBER; j++)
			c->tabela_clientes[i][j] = NULL;

	load_clientes(c, PATH_C, valores, f);

	num[0] = valores[0];
	num[1] = valores[1];
	return c;
}

// Função que liberta o espaço alocado para a estrutura
void free_clientes(Clientes c){
	for (int i = 0; i < LETRAS; i++)
		for(int j = 0; j < HASHNUMBER; j++)
			free_AVL(c->tabela_clientes[i][j], 'b');
}
