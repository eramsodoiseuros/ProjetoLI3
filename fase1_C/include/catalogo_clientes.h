#ifndef __CATALOGO_CLIENTES_H__
#define __CATALOGO_CLIENTES_H__

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "AVL.h"
#include "filial.h"

#define PATH_C "./files/Clientes.txt"

typedef struct clientes* Clientes;


/**
 *	Função que verifica se um id existe na estrutura
 *	@param estrutura clientes e o id a verificar
 *	@param 1 caso exista, 0 caso não exista
 */
int search_C(Clientes c, char* id);

/**
 *	Função que valida um id de um cliente
 *	@param string a validar
 *	@param 1 caso seja valida, 0 caso seja inválida
 */
int valida_cliente(char* id);

/**
 *	Função que inicializa a estrutura Clientes, escreve na posição 0 e 1 do array
 *	@param o array para escrever e uma estrutura filial
 *	@param a estrutura que se criou
 */
Clientes iniciar_clientes(int* num, Filial f);

/**
 *	Função que liberta o espaço alocado para a estrutura
 *	@param a estrutura a libertar
 */
void free_clientes(Clientes c);


#endif
