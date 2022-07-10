#include "../include/faturacao.h"

struct faturacao{
	double tabela_faturacao[12][4]; 
	int tabela_vendas[12];
	double total_faturado;
};

// Função que devolve o numero de vendas num mês
int numero_vendas(Faturacao f1, int mes){
	return f1->tabela_vendas[mes-1];
}

// Função que devolve o total faturado
double total_faturado(Faturacao f1){
	return f1->total_faturado;
}

// Função que devolve o total faturado num certo mês
double faturado_mes(Faturacao f1, int mes){
	double r = -1;
	
	if(mes<=12 && mes>=0) r = f1->tabela_faturacao[mes][3];

	return r;
}

// Função que devolve o total faturado num certo mês e numa certa filial
double faturado_in(Faturacao f1, int mes, int filial){
	double r = -1;
	
	if(mes<=12 && mes>=0)
		if(filial<=3 && filial>=0)
			r = f1->tabela_faturacao[mes][filial];

	return r;
}

// Função que dado os parametros de uma venda dá update na estrutura faturação
void update_faturacao(Faturacao f1, int filial, int mes, double preco, int unidades){
	f1->tabela_faturacao[mes-1][3] += preco*unidades;
	f1->tabela_faturacao[mes-1][filial-1] += preco*unidades;
	f1->tabela_vendas[mes-1]++;
	f1->total_faturado += preco*unidades;
}

// Função que inicia a estrutura faturação com os respetivos valores a zero
Faturacao iniciar_faturacao(){
	Faturacao f1 = malloc(sizeof(struct faturacao));

	for(int m = 0; m < 12; m++)
		for(int f = 0; f < 4; f++)
			f1->tabela_faturacao[m][f] = 0.0;
	
	for(int m = 0; m < 12; m++)
		f1->tabela_vendas[m] = 0;

	f1->total_faturado = 0.0;

	return f1;
}

// Função que liberta o espaço alocado para a estrutura
void free_faturacao(Faturacao f){
	free(f);
}
