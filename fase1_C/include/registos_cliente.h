#ifndef __REGISTOS_CLIENTE_H__
#define __REGISTOS_CLIENTE_H__

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "AVL.h"

typedef struct registos_cliente* RC;
typedef struct cliente* Cliente;

/**
 *	Função que inicializa um registo cliente
 *	@param o cliente
 */
Cliente iniciar_cliente();

/**
 *	Função que liberta o espaço alocado para a estrutura
 *	@param apontador para a estrutura Cliente
 */
void free_cliente(Cliente c);

/**
 *	Função que insere um index, de tipologia Cliente, numa estrutura de dados
 *	@param estrutura de Registo, string id a inserir
 */
void insert_c(RC c, char* id);

/**
 *	Função que 
 *	@param 
 */
void update_registo_c(Cliente c, int filial, int mes, double preco, int unidades, char* produto, char NP);

/**
 *	Função que 
 *	@param 
 */
void update_cliente(RC c, char* cliente, int filial, int mes, double preco, int unidades, char* produto, char NP);

/**
 *	Função que inicializa os Registos dos Clientes
 *	@param o registo de clientes
 */
RC iniciar_RC();

/**
 *	Função que liberta o espaço alocado para a estrutura
 *	@param apontador para a estrutura Registos de Cliente
 */
void free_rc(RC c);

/**
 *	Função que 
 *	@param 
 */
int cliente_comprou(RC c, char* cliente, int x);

/**
 *	Função que 
 *	@param 
 */
int c_quantos_comprou(RC c, char* cliente);

/**
 *	Função que 
 *	@param 
 */
int c_vezes_comprou(RC c, char* cliente, int m, int f);


/**
 *	Função que 
 *	@param 
 */
int comprou(Cliente c);

/**
 *	Função que 
 *	@param 
 */
int comprou_tudo(Cliente c);

/**
 *	Função que 
 *	@param 
 */
void c_comprou_tudo(RC c, Lista_Strings s);

/**
 *	Função que 
 *	@param 
 */
int c_nao_comprou(RC c);

/**
 *	Função que 
 *	@param 
 */
void get_lista_P(RC rc, char* cliente, int mes, Lista_Ordenada X);

/**
 *	Função que 
 *	@param 
 */
int get_lista_F(RC rc, char* cliente, Lista_12 X, int N);

#endif
