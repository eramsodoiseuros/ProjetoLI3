#ifndef __REGISTOS_PRODUTO_H__
#define __REGISTOS_PRODUTO_H__

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "AVL.h"

typedef struct registos_produto* RP;
typedef struct produto* Produto;


/**
 *	Função que inicializa um registo produto
 *	@param o produto
 */
Produto iniciar_produto();

/**
 *	Função que liberta o espaço alocado para a estrutura
 *	@param apontador para a estrutura Produto
 */
void free_produto(Produto p);

/**
 *	Função que insere um index, de tipologia Produto, numa estrutura de dados
 *	@param 
 */
int insert_p(RP p, char* id);

/**
 *	Função que 
 *	@param 
 */
void update_registo_p(Produto p, int filial, int mes, double preco, int unidades, char* cliente, char NP);

/**
 *	Função que 
 *	@param 
 */
void update_produto(RP p, char* produto, int filial, int mes, double preco, int unidades, char* cliente, char NP);

/**
 *	Função que 
 *	@param 
 */
RP iniciar_RP();

void free_rp(RP p);

/**
 *	Função que 
 *	@param 
 */
int produto_vendido(RP p, char* produto, int x);

/**
 *	Função que 
 *	@param 
 */
int p_vezes_comprado(RP p, char* produto, int m, int f);

/**
 *	Função que 
 *	@param 
 */
int p_faturado_in(RP p, char* produto, int m, int f, char NP);

/**
 *	Função que 
 *	@param 
 */
int p_NP_vezes(RP p, char* produto, char NP, int filial, int mes);

/**
 *	Função que 
 *	@param 
 */
int vendeu(Produto p);

/**
 *	Função que 
 *	@param 
 */
int p_nao_vendeu(RP p);

/**
 *	Função que 
 *	@param 
 */
int vendeu_todas(Produto p);

/**
 *	Função que 
 *	@param 
 */
void p_vendeu_todas(RP p, Lista_Strings lista, int x);

/**
 *	Função que 
 *	@param 
 */
int vendeu_in(Produto p, int x);

/**
 *	Função que 
 *	@param 
 */
int get_lista_NP(RP p, char* produto, char NP, int filial, Lista_Strings X);

/**
 *	Função que 
 *	@param 
 */
int unidades_vendidas(Produto p, int filial);

/**
 *	Função que 
 *	@param 
 */
void query11(int n, RP p, Lista_N LP, int filial);

#endif
