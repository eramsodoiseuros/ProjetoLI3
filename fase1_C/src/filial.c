#include "../include/filial.h"
#include "../include/registos_cliente.h"
#include "../include/registos_produto.h"

struct filial{
	RP produtos;
	RC clientes;
};

// Função que inicia a estrutura filial com os respetivos valores a zero
Filial iniciar_filial(){
	Filial f = (Filial) malloc(sizeof(struct filial));

	f->produtos = iniciar_RP();
	f->clientes = iniciar_RC();

	return f;
}


// Função que insere um produto nos registos da filial
void f_produto(Filial f, char* id){
	insert_p(f->produtos, id);
}

// Função que insere um cliente nos registos da filial
void f_cliente(Filial f, char* id){
	insert_c(f->clientes, id);
}

// Função que devolve um Registo de Produtos presente na estrutura filial
RP get_produtos(Filial f){
	return f->produtos;
}

// Função que devolve um Registo de Clientes presente na estrutura filial
RC get_clientes(Filial f){
	return f->clientes;
}

// Função que liberta o espaço alocado para a estrutura
void free_filial(Filial f){
	free_rp(f->produtos);
	free_rc(f->clientes);
}