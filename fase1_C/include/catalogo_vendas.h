#ifndef __CATALOGO_VENDAS_H__
#define __CATALOGO_VENDAS_H__

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "catalogo_produtos.h"
#include "catalogo_clientes.h"
#include "filial.h"
#include "faturacao.h"
#include "AVL.h"

/**
 *	Função que preenche as estruturas Filial e Faturação, escreve na posição 4 e 5 do array
 *	@param o array a preencher na posição 4 e 5, a estrutura de produtos válidos, a estrutura de clientes válidos,
 	a estrutura filial a preencher, a estrutura faturação a preencher e o path do ficheiro vendas
*/
void init_Vendas(int num[6], Produtos p, Clientes c, Filial f1, Faturacao f2, char* path);

#endif
