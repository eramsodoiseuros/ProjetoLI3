#include "../include/registos_produto.h"

#define LETRAS 26
#define HASHNUMBER 151

struct registos_produto{
	AVL tabela_produto[LETRAS][LETRAS][HASHNUMBER];
};


struct produto{
    int vendido_in[5];
    int vezes_comprado[12][3];
    int unidades_vendidas[3];
    int faturado_in[12][3][2];
    int vezes_N[12][3];
    int vezes_P[12][3];
    Lista_Strings N[4];
    Lista_Strings P[4];
};

// Função que dado uma string (valor), devolve uma posição (index, hash key)
void hF_p(int index[3], char value[]){
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
int insert_p(RP p, char* id){
	int index[3]; index[0] = 0, index[1] = 0, index[2] = 0;
	int nID = num_(id,2);
	hF_p(index, id);

	p->tabela_produto[index[0]][index[1]][index[2]] = insert_tree(p->tabela_produto[index[0]][index[1]][index[2]] , nID, id, 'p');
	return index[0];
}

// Função que
Produto iniciar_produto(int pos){
	Produto p = malloc(sizeof(struct produto));

	for(int i = 0; i < 5; i++)
		p->vendido_in[i] = 0;
	
	for(int i = 0; i < 3; i++)
		p->unidades_vendidas[i] = 0;

	for(int m = 0; m < 12; m++)
		for(int i = 0; i < 3; i++)
			p->vezes_comprado[m][i] = 0;
	
	for(int m = 0; m < 12; m++)
		for(int i = 0; i < 3; i++)
			for(int t = 0; t < 2; t++)
				p->faturado_in[m][i][t] = 0;
	
	for(int m = 0; m < 12; m++)
		for(int i = 0; i < 3; i++)
			p->vezes_N[m][i] = 0;

	for(int m = 0; m < 12; m++)
		for(int i = 0; i < 3; i++)
			p->vezes_P[m][i] = 0;

	for(int i = 0; i < 4; i++)
		p->N[i] = NULL;
	
	for(int i = 0; i < 4; i++)
		p->P[i] = NULL;

	return p;
}

// Função que liberta o espaço alocado para a estrutura
void free_produto(Produto p){
	free(p->vendido_in);
	free(p->vezes_comprado);
	free(p->vezes_comprado);
    free(p->unidades_vendidas);
    free(p->faturado_in);
    free(p->vezes_N);
    free(p->vezes_P);

    for(int i = 0; i < 4; i++){
    	delete_lista(p->P[i]);
    	delete_lista(p->N[i]);
    }
    
	free(p);
}

// Função que
void update_registo_p(Produto p, int filial, int mes, double preco, int unidades, char* cliente, char NP){

	p->vendido_in[0]++;
	p->vendido_in[filial]++;

	if(p->vendido_in[1] && p->vendido_in[2] && p->vendido_in[3])
		p->vendido_in[4] = 1;

	p->unidades_vendidas[filial-1] += unidades;

	p->vezes_comprado[mes-1][filial-1]++;

	if(NP == 'N')
		p->faturado_in[mes-1][filial-1][0] += unidades*preco;
	
	if(NP == 'P')
		p->faturado_in[mes-1][filial-1][1] += unidades*preco;

	if(NP == 'N'){
		if(!p->N[filial])
			p->N[filial] = iniciar_lista(5);
		add_lista(p->N[filial], cliente);

		if(!p->N[0])
			p->N[0] = iniciar_lista(5);
		add_lista(p->N[0], cliente);

		p->vezes_N[mes-1][filial-1]++;
	}
	if (NP == 'P'){
		if(!p->P[filial])
			p->P[filial] = iniciar_lista(5);
		add_lista(p->P[filial], cliente);

		if(!p->P[0])
			p->P[0] = iniciar_lista(5);
		add_lista(p->P[0], cliente);

		p->vezes_P[mes-1][filial-1]++;
	}
}

// Função que
void update_produto(RP p, char* produto, int filial, int mes, double preco, int unidades, char* cliente, char NP){
	int nID = num_(produto,2);
	int index[3]; index[0] = 0, index[1] = 0, index[2] = 0;
	hF_p(index,produto);

	search_update(p->tabela_produto[index[0]][index[1]][index[2]], nID, 'p', cliente, filial, mes, preco, unidades, produto, NP);
}

// Função que
RP iniciar_RP(){
	RP p = malloc(sizeof(struct registos_produto));

	for (int i = 0; i < LETRAS; i++)
		for (int j = 0; j < LETRAS; j++)
			for(int k = 0; k < HASHNUMBER; k++)
				p->tabela_produto[i][j][k] = NULL;

	return p;
}

void free_rp(RP p){
	
	for (int i = 0; i < LETRAS; i++){
		for (int j = 0; j < LETRAS; j++)
			for(int k = 0; k < HASHNUMBER; k++)
				free_AVL(p->tabela_produto[i][j][k], 'p');
	}
}


// Função que
int produto_vendido(RP p, char* produto, int x){
	int nID = num_(produto,2);
	int index[3]; index[0] = 0, index[1] = 0, index[2] = 0;
	hF_p(index,produto);

	Produto p2 = search_info(p->tabela_produto[index[0]][index[1]][index[2]], nID);

	return p2->vendido_in[x];
}

// Função que
int p_vezes_comprado(RP p, char* produto, int m, int f){
	int nID = num_(produto, 2);
	int index[3]; index[0] = 0, index[1] = 0, index[2] = 0;

	hF_p(index, produto);

	Produto p2 = search_info(p->tabela_produto[index[0]][index[1]][index[2]], nID);

	return p2->vezes_comprado[m-1][f-1];
}

// Função que
int p_faturado_in(RP p, char* produto, int m, int f, char NP){
	int nID = num_(produto,2), c = 42;
	int index[3]; index[0] = 0, index[1] = 0, index[2] = 0;
	hF_p(index,produto);

	Produto p2 = search_info(p->tabela_produto[index[0]][index[1]][index[2]], nID);
	
	if(NP == 'N')
		c = 0;
	if(NP == 'P')
		c = 1;

	return p2->faturado_in[m-1][f-1][c];
}

// Função que
int p_NP_vezes(RP p, char* produto, char NP, int filial, int mes){
	int r = 0;
	int nID = num_(produto,2);
	int index[3]; index[0] = 0, index[1] = 0, index[2] = 0;
	hF_p(index,produto);

	Produto p2 = search_info(p->tabela_produto[index[0]][index[1]][index[2]], nID);

	if(NP == 'N'){
		r = p2->vezes_N[mes-1][filial-1];
	}

	if(NP == 'P'){
		r = p2->vezes_P[mes-1][filial-1];
	}

	return r;
}

// Função que
int vendeu(Produto p){
	return (p->vendido_in[0] == 0);
}

// Função que
int vendeu_in(Produto p, int x){
	return (p->vendido_in[x] == 0);
}

void p_vendeu_todas(RP p, Lista_Strings lista, int x){
	char l1 = 'A', l2 = 'A';

	for (int i = 0; i < LETRAS; i++)
		for (int j = 0; j < LETRAS; j++)
			for(int k = 0; k < HASHNUMBER; k++)
				search_p(p->tabela_produto[i][j][k], lista, l1+i, l2+j, x);
}

// Função que
int p_nao_vendeu(RP p){
	int r = 0;

	for (int i = 0; i < LETRAS; i++)
		for (int j = 0; j < LETRAS; j++)
			for(int k = 0; k < HASHNUMBER; k++)
				r += search_n(p->tabela_produto[i][j][k], 'p');

	return r;
}

int get_lista_NP(RP rp, char* produto, char NP, int filial, Lista_Strings X){
	int nID = num_(produto, 2);
	int index[3]; index[0] = 0, index[1] = 0, index[2] = 0;
	int r = 0;

	hF_p(index, produto);

	Produto p = search_info(rp->tabela_produto[index[0]][index[1]][index[2]], nID);

	if(NP == 'N'){
		if(filial != 4){
			if(!p->N[filial]){
				return 0;
			}
			else{
				r = size_lista(p->N[filial]);
				for(int i = 0; i < r; i++){
					add_lista(X, get_elem(p->N[filial], i));
				}
			}
		}

		else{
			if(!p->N[0]){
				return 0;
			}
			else{
				r = size_lista(p->N[0]);
				for(int i = 0; i < r; i++){
					add_lista(X, get_elem(p->N[0], i));
				}
			}
		}
	}

	if(NP == 'P'){
		if(filial != 4){
			if(!p->P[filial]){
				return 0;
			}
			else{
				r = size_lista(p->P[filial]);
				for(int i = 0; i < r; i++){
					add_lista(X, get_elem(p->P[filial], i));
				}
			}
		}

		else{
			if(!p->P[0]){
				return 0;
			}
			else{
				r = size_lista(p->P[0]);
				for(int i = 0; i < r; i++){
					add_lista(X, get_elem(p->P[0], i));
				}
			}
		}
	}

	return r;
}

//
int unidades_vendidas(Produto p, int filial){
	return p->unidades_vendidas[filial-1];
}



//
void query11(int n, RP p, Lista_N LP, int filial){

	for (int i = 0; i < LETRAS; i++)
		for (int j = 0; j < LETRAS; j++)
			for(int k = 0; k < HASHNUMBER; k++)
				search_u(p->tabela_produto[i][j][k], i, j, 'p', filial, LP, n);
}