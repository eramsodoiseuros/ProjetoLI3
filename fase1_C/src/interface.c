#include "../include/interface.h"
#include "../include/AVL.h"

///////////////////////////////////////////////////////////
// SGV

struct sgv {
	Clientes c;
 	Produtos p; 
	Filial f1;
 	Faturacao f2;
};

SGV initSGV (){

	SGV s = malloc(sizeof(struct sgv));

	s->c = NULL;
	s->p = NULL;
	s->f1 = NULL;
	s->f2 = NULL;

	return s;
}

void destroySGV(SGV s){
	free_clientes(s->c);
	free_produtos(s->p);
	free_filial(s->f1);
	free_faturacao(s->f2);
}


Clientes get_clientes_(SGV s){
	return s->c;
}

Produtos get_produtos_(SGV s){
	return s->p;
}

Filial get_filial_(SGV s){
	return s->f1;
}

Faturacao get_faturacao_(SGV s){
	return s->f2;
}

///////////////////////////////////////////////////////////
// QUERY 1

void query_1(SGV s, int num[6], int r){

	if(r == 1){
		s->f1 = iniciar_filial();
		s->c = iniciar_clientes(num,s->f1);
	}
	
	if(r == 2){
		s->f1 = iniciar_filial();
		s->p = iniciar_produtos(num,s->f1);
	}

	if (r == 3){
		s->f1 = iniciar_filial();
		s->c = iniciar_clientes(num,s->f1);
		s->p = iniciar_produtos(num,s->f1);
		s->f2 = iniciar_faturacao();
		init_Vendas(num, s->p, s->c, s->f1, s->f2, "./files/Vendas_1M.txt");
	}

	if(r == 4){
		s->f1 = iniciar_filial();
		s->c = iniciar_clientes(num,s->f1);
		s->p = iniciar_produtos(num,s->f1);
		s->f2 = iniciar_faturacao();
		init_Vendas(num, s->p, s->c, s->f1, s->f2, "./files/Vendas_3M.txt");
	}

	if(r == 5){
		s->f1 = iniciar_filial();
		s->c = iniciar_clientes(num,s->f1);
		s->p = iniciar_produtos(num,s->f1);
		s->f2 = iniciar_faturacao();
		init_Vendas(num, s->p, s->c, s->f1, s->f2, "./files/Vendas_5M.txt");
	}

	if(r == 6){
		s->p = iniciar_produtos(num,s->f1);
		s->f2 = iniciar_faturacao();
		init_Vendas(num, s->p, s->c, s->f1, s->f2, "./files/Vendas_1M.txt");
	}

	if(r == 7){
		s->c = iniciar_clientes(num,s->f1);
		s->f2 = iniciar_faturacao();
		init_Vendas(num, s->p, s->c, s->f1, s->f2, "./files/Vendas_1M.txt");
	}
}

SGV loadSGVFromFiles(SGV sgv, char* filesFolderPath){
	destroySGV(sgv);
	SGV s = initSGV ();
	
	int p[6];
	query_1(s,p,3);

	return s;
}

///////////////////////////////////////////////////////////
// QUERY 2

int query_2(SGV s, char letra, Lista_Strings ls){
	lista_produtos(s->p, letra, ls);

	return size_lista(ls);
}

Lista_Strings getProductsStartedByLetter(SGV sgv, char letter){
	Lista_Strings ls = iniciar_lista(600);

	lista_produtos(sgv->p, letter, ls);

	return ls;
}

///////////////////////////////////////////////////////////
// QUERY 3

void query_3(SGV s, char* produto, int mes, int vendas[3], double faturado[3], int filial){

   RP p = get_produtos(s->f1);

	for (int j = 0; j < 3; j++){
		vendas[j] = 0;
	}

	for (int k = 0; k < 3; k++){
		faturado[k] = 0.0;
	}

	if(filial == 4){
		for (int i = 1; i <= 3; i++){
			
			vendas[0] += p_vezes_comprado(p, produto, mes, i);
			vendas[1] += p_NP_vezes(p, produto,'N', i, mes);
			vendas[2] += p_NP_vezes(p, produto,'P', i, mes);

			faturado[1] += p_faturado_in(p, produto, mes, i, 'N');
			faturado[2] += p_faturado_in(p, produto, mes, i, 'P');
		}
		faturado[0] = faturado[1] + faturado[2];
	}
	else{
		vendas[0] = p_vezes_comprado(p, produto, mes, filial);
		vendas[1] = p_NP_vezes(p, produto, 'N', filial, mes);
		vendas[2] = p_NP_vezes(p, produto, 'P', filial, mes);

		faturado[1] = p_faturado_in(p, produto, mes, filial, 'N');
		faturado[2] = p_faturado_in(p, produto, mes, filial, 'P');
		faturado[0] = faturado[1] + faturado[2];	
	}
}

double* getProductSalesAndProfit(SGV sgv, char* productID, int month){
	double* vendas_faturacao = malloc(sizeof(double)*6);
	
	RP p = get_produtos(sgv->f1);

	for (int j = 0; j < 3; j++){
		vendas_faturacao[j] = 0;
	}


	for (int i = 1; i <= 3; i++){		
		vendas_faturacao[0] += p_vezes_comprado(p, productID, month, i);
		vendas_faturacao[1] += p_NP_vezes(p, productID,'N', i, month);
		vendas_faturacao[2] += p_NP_vezes(p, productID,'P', i, month);

		vendas_faturacao[3] += p_faturado_in(p, productID, month, i, 'N');
		vendas_faturacao[4] += p_faturado_in(p, productID, month, i, 'P');
		vendas_faturacao[5] += vendas_faturacao[3] + vendas_faturacao[4];
	}

	return vendas_faturacao;
}

///////////////////////////////////////////////////////////
// QUERY 4

int query_4(SGV s, Lista_Strings ls, int filial) {
	if(filial == 4)
		p_vendeu_todas(get_produtos(s->f1), ls, 0);
	else p_vendeu_todas(get_produtos(s->f1), ls, filial);

	return size_lista(ls);
}

Lista_Strings getProductsNeverBought(SGV sgv, int branchID){
	Lista_Strings ls = iniciar_lista(1000);

	query_4(sgv, ls, branchID);
	
	return ls;
}

///////////////////////////////////////////////////////////
// QUERY 5

int query_5(SGV s, Lista_Strings ls){
	c_comprou_tudo(get_clientes(s->f1), ls);

	return size_lista(ls);
}

Lista_Strings getClientsOfAllBranches(SGV sgv){
	Lista_Strings ls = iniciar_lista(1000);

	query_5(sgv, ls);

	return ls;
}

///////////////////////////////////////////////////////////
// QUERY 6

void query_6(SGV s, int c[1], int p[1]){

	RP produtos = get_produtos(s->f1);
	RC clientes = get_clientes(s->f1);

	c[0] = c_nao_comprou(clientes);
	p[0] = p_nao_vendeu(produtos);
}

int* getClientsAndProductsNeverBoughtCount(SGV sgv){
	int* r = malloc(sizeof(int)*2);

	query_6(sgv, r+0, r+1);

	return r;
}

///////////////////////////////////////////////////////////
// QUERY 7
void query_7(SGV s, char* cliente, int vendas[12][3]){
	
	RC cl = get_clientes(s->f1);
	
	for (int mes = 0; mes < 12; ++mes){
		for(int filial = 0; filial<3; filial++){
			vendas[mes][filial] = c_vezes_comprou(cl,cliente,mes,filial);
		}
	}
}

int** getProductsBoughtByClient(SGV sgv, char* clientID){
	int** vendas = malloc(sizeof(int*)*12);
	int vendas2[12][3];

	query_7(sgv, clientID, vendas2);
	
	for (int mes = 0; mes < 12; ++mes)
		for(int filial = 0; filial<3; filial++)
			vendas[mes][filial] = vendas2[mes][filial];

	return vendas;
}

///////////////////////////////////////////////////////////
// QUERY 8

void query_8 (SGV s, int mes1, int mes2, int v[1] , double f[1]){
	int vendas = 0;
	double faturado = 0;

	for(int i = mes1; i<=mes2; i++)
		vendas += numero_vendas(s->f2,i);

	for(int i = mes1; i<=mes2; i++)
		faturado += faturado_mes(s->f2,i);

	v[0] = vendas;
	f[0] = faturado;
}

double* getSalesAndProfit(SGV sgv, int minMonth, int maxMonth){
	double* pointer = malloc(sizeof(double)*2);
	int pointer1[1];

	query_8(sgv, minMonth, maxMonth, pointer1+0 , pointer+1);

	pointer[0] = (double) pointer1[0];

	return pointer;
}

///////////////////////////////////////////////////////////
// QUERY 9

int query_9(SGV s, char* produto, int filial, Lista_Strings N, Lista_Strings P){
	int r = 0;

	RP produtos = get_produtos(s->f1);
	
	r+= get_lista_NP(produtos, produto, 'N', filial, N);
	r+= get_lista_NP(produtos, produto, 'P', filial, P);

	return r;
}

Lista_Strings* getProductBuyers(SGV sgv, char* productID, int branchID){
	Lista_Strings* NP = malloc(sizeof(Lista_Strings)*2);

	NP[0] = iniciar_lista(5);
	NP[1] = iniciar_lista(5);

	query_9(sgv, productID, branchID, NP[0], NP[1]);

	return NP;
}

///////////////////////////////////////////////////////////
// QUERY 10

void query_10(SGV s, char* cliente, int mes, Lista_Ordenada P){
	
	RC clientes = get_clientes(s->f1);

	get_lista_P(clientes, cliente, mes, P);
	
	heapSort(P);
}

Lista_Ordenada getClientFavoriteProducts(SGV sgv, char* clientID, int month){
	Lista_Ordenada P = iniciar_lista_ordenada(10);
	
	query_10(sgv, clientID, month, P);

	return P;
}

///////////////////////////////////////////////////////////
// QUERY 11

void query_11(SGV s, int n, Lista_N F1, Lista_N F2, Lista_N F3){
	Lista_Strings N, P;

	RP rp = get_produtos(s->f1);
	
	query11(n, rp, F1, 1);
	query11(n, rp, F2, 2);
	query11(n, rp, F3, 3);
	
	for(int x = 0; x < n; x++){
		N = iniciar_lista(5);
		P = iniciar_lista(5);

		set_n_clientes(F1, x, query_9(s, get_elem_nm(F1,x), 4, N, P));
		
		delete_lista(N);
		delete_lista(P);
		
		N = iniciar_lista(5);
		P = iniciar_lista(5);

		set_n_clientes(F2, x, query_9(s, get_elem_nm(F2,x), 4, N, P));
		
		delete_lista(N);
		delete_lista(P);

		N = iniciar_lista(5);
		P = iniciar_lista(5);

		set_n_clientes(F3, x, query_9(s, get_elem_nm(F3,x), 4, N, P));
		
		delete_lista(N);
		delete_lista(P);
	}
}

Lista_N* getTopSelledProducts(SGV sgv, int limit){
	Lista_N* F = malloc(sizeof(Lista_N)*3);

	F[0] = iniciar_nm(limit);
	F[1] = iniciar_nm(limit);
	F[2] = iniciar_nm(limit);

	query_11(sgv, limit, F[0], F[1], F[2]);

	return F;
}

///////////////////////////////////////////////////////////
// QUERY 12

/*

Dado um código de cliente determinar quais os códigos dos N produtos em que mais gastou dinheiro durante o ano;

*/

int query_12(SGV s, int N, Lista_12 ls, char* cliente){

	RC rc = get_clientes(s->f1);

	int r = get_lista_F(rc, cliente, ls, N);

	return r;
}

Lista_12 getClientTopProfitProducts(SGV sgv, char* clientID, int limit){
	Lista_12 ls = iniciar_lista_12(limit);

	query_12(sgv, limit, ls, clientID);

	return ls;
}