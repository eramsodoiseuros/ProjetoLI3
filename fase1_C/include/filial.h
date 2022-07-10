#ifndef __FILIAL_H__
#define __FILIAL_H__

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "../include/registos_cliente.h"
#include "../include/registos_produto.h"

typedef struct filial* Filial;

/**
 *	Função que inicia a estrutura filial com os respetivos valores a zero
 *	@param a estrutura filial a iniciar
*/
Filial iniciar_filial();

/**
 *	Função que insere um produto nos registos da filial
 *	@param estrutura filial e o produto a inserir
 */
void f_produto(Filial f, char* id);

/**
 *	Função que insere um cliente nos registos da filial
 *	@param estrutura filial e o cliente a inserir
 */
void f_cliente(Filial f, char* id);

/**
 *	Função que devolve um Registo de Produtos presente na estrutura filial
 *	@param Filial
 *	@param Registo de Produtos
 */
RP get_produtos(Filial f);

/**
 *	Função que devolve um Registo de Clientes presente na estrutura filial
 *	@param Filial
 *	@param Registo de Clientes
 */
RC get_clientes(Filial f);

/**
 *	Função que liberta o espaço alocado para a estrutura
 *	@param a estrutura a libertar
 */
void free_filial(Filial f);

#endif
