#ifndef __CATALOGO_PRODUTOS_H__
#define __CATALOGO_PRODUTOS_H__

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "AVL.h"
#include "filial.h"

#define PATH_P "./files/Produtos.txt"

typedef struct produtos* Produtos;

/**
 *	Função que verifica se um id existe na estrutura
 *	@param estrutura produtos e o id a verificar
 *	@param 1 caso exista, 0 caso não exista
 */
int search_P(Produtos p, char* id);

/**
 *	Função que valida um id de um produto
 *	@param string a validar
 *	@param 1 caso seja valida, 0 caso seja inválida
 */
int valida_produto(char * id);

/**
 *	Função que inicializa a estrutura Produtos, escreve na posição 2 e 3 do array
 *	@param o array para escrever e uma estrutura filial
 *	@param a estrutura a criar
 */
Produtos iniciar_produtos(int* num, Filial f);

/**
 *	Função que cria uma lista de produtos validos
 *	@param estrutura com os produtos, a letra dos produtos pretendidos e a estrutura a preencher
 */
void lista_produtos(Produtos p, char letra, Lista_Strings lista);

/**
 *	Função que cria uma lista de produtos validos
 *	@param estrutura com os produtos e a estrutura a preencher
 */
void lista_total_produtos(Produtos p, Lista_Strings lista);

/**
 *	Função que liberta o espaço alocado para a estrutura
 *	@param a estrutura a libertar
 */
void free_produtos(Produtos p);

#endif
