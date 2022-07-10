#ifndef __FATURACAO_H__
#define __FATURACAO_H__

typedef struct faturacao* Faturacao;


#include <stdlib.h>
#include <stdio.h>

/**
 *	unção que devolve o numero de vendas num mês
 *	@param a estrutura faturação e o mês pretendido
 *	@param o número de vendas realizado nesse mês
*/
int numero_vendas(Faturacao f1, int mes);

/**
 *	Função que devolve o total faturado
 *	@param a estrutura faturação
 *	@param o total faturado
*/
double total_faturado(Faturacao f1);

/**
 *	Função que devolve o total faturado num certo mês
 *	@param a estrutura faturação e o mês
 *	@param o total faturado num certo mês
*/
double faturado_mes(Faturacao f1, int mes);

/**
 *	Função que devolve o total faturado num certo mês e numa certa filial
 *	@param a estrutura faturação, o mês e a filial
 *	@param o total faturado num certo mês e numa certa filial
*/
double faturado_in(Faturacao f1, int mes, int filial);

/**
 *	Função que dado os parametros de uma venda dá update na estrutura faturação
 *	@param a estrutura faturação, a filial, o mês, o preço correspondente a um certo produto e o número de unidades
*/
void update_faturacao(Faturacao f1, int filial, int mes, double preco, int unidades);

/**
 *	Função que inicia a estrutura faturação com os respetivos valores a zero
 *	@param a estrutura faturação a iniciar
*/
Faturacao iniciar_faturacao();

/**
 *	Função que liberta o espaço alocado para a estrutura
 *	@param a estrutura a libertar
 */
void free_faturacao(Faturacao f);

#endif
