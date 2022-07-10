#ifndef __QUERIES_H__
#define __QUERIES_H__


#define RST  "\x1B[0m"   // RESET
#define KRED  "\x1B[31m" // RED
#define KGRN  "\x1B[32m" // GREEN
#define KYEL  "\x1B[33m" // YELLOW
#define KBLU  "\x1B[34m" // BLUE
#define KMAG  "\x1B[35m" // MAGENTA
#define KCYN  "\x1B[36m" // CYAN
#define KWHT  "\x1B[37m" // WHITE


#include "catalogo_vendas.h"
#include "catalogo_clientes.h"
#include "catalogo_produtos.h"

#define buffsize 10


typedef struct sgv* SGV;

SGV initSGV ();

void destroySGV(SGV s);

/*1*/	SGV loadSGVFromFiles(SGV sgv, char* filesFolderPath);
/*2*/	Lista_Strings getProductsStartedByLetter(SGV sgv, char letter);
/*3*/	double* getProductSalesAndProfit(SGV sgv, char* productID, int month);
/*4*/	Lista_Strings getProductsNeverBought(SGV sgv, int branchID);
/*5*/	Lista_Strings getClientsOfAllBranches(SGV sgv);
/*6*/	int* getClientsAndProductsNeverBoughtCount(SGV sgv);
/*7*/	int** getProductsBoughtByClient(SGV sgv, char* clientID);
/*8*/ 	double* getSalesAndProfit(SGV sgv, int minMonth, int maxMonth);
/*9*/ 	Lista_Strings* getProductBuyers(SGV sgv, char* productID, int branchID);
/*10*/ 	Lista_Ordenada getClientFavoriteProducts(SGV sgv, char* clientID, int month);
/*11*/ 	Lista_N* getTopSelledProducts(SGV sgv, int limit);
/*12*/	Lista_12 getClientTopProfitProducts(SGV sgv, char* clientID, int limit);


Clientes get_clientes_(SGV s);

Produtos get_produtos_(SGV s);

Filial get_filial_(SGV s);

Faturacao get_faturacao_(SGV s);

/**
 * 	Lê e inicializa os valores das estruturas através dos ficheiros
 	Opcionalmente, assumidos por omissão (sendo neste caso os ficheiros anteriormente referidos).
 	O resultado desta leitura deverá ser a apresentação imediata ao utilizador do nome do ficheiro lido e que vai ser usado, o número total de linhas lidas e validadas.
 	Note-se que qualquer nova leitura destes ficheiros deverá de imediato reiniciar e refazer as estruturas de dados em memória como se de uma reinicialização so tratasse.

 *	@param estrutura clientes a preencher, estrutura produtos a preencher, array de valores a preencher, inteiro que verifica as ações a tomar
 */
void query_1(SGV s, int num[6], int r);

/**
 * 	Determinar a lista e o nº total de produtos cujo código se inicia por uma dada letra (maiúscula);

 *	@param os Produtos existentes e a Letra pretendida
*/
int query_2(SGV s, char letra, Lista_Strings ls);

/**
 *	Dado um mês e um código de produto, ambos válidos, determinar e apresentar o número total de vendas (nº de registos de venda)
 	e o total facturado com esse produto em tal mês, distinguindo os totais em modo N e os totais em modo P.
	O utilizador deverá decidir se pretende o resultado global ou os resultados filial a filial para todas as 3 filiais.

 *	@param O QUE RECEBE
 *	@param O QUE RETORNA
*/
void query_3 (SGV s, char* produto, int mes, int vendas[3], double faturado[3], int filial);

/**
 *	Determinar a lista ordenada dos códigos dos produtos (e o seu número total) que ninguém comprou.
	O utilizador deverá decidir se pretende o resultado global ou os resultados filial a filial para todas as 3 filiais.

 *	@param O QUE RECEBE
 *	@param O QUE RETORNA
*/
int query_4(SGV s, Lista_Strings ls, int filial);

/**
 *	Determinar a lista ordenada de códigos de clientes que realizaram compras em todas as filiais;

 *	@param O QUE RECEBE
 *	@param O QUE RETORNA
*/
int query_5(SGV s, Lista_Strings ls);

/**
 *	Determinar o número de clientes registados que não realizaram compras bem como o número de produtos que ninguém comprou.

 *	@param O QUE RECEBE
 *	@param O QUE RETORNA
*/
void query_6(SGV s, int c[1], int p[1]);

/**
 *	Dado um código de cliente, criar uma tabela com o número total de produtos comprados (ou seja a soma das quantidades de todas as vendas do produto),
 	mês a mês (para meses em que não comprou a entrada deverá ficar a 0).
	A tabela deverá ser apresentada em ecrã organizada por filial.

 *	@param O QUE RECEBE
 *	@param O QUE RETORNA
*/
void query_7(SGV s, char* cliente, int vendas[12][3]);

/**
 *	Dado um intervalo fechado de meses, por exemplo [1..3], determinar o total de vendas (nº de registos de venda) registadas nesse intervalo e o total facturado;

 *	@param O QUE RECEBE
 *	@param O QUE RETORNA
*/
void query_8(SGV s, int m1, int m2, int v[1] , double f[1]);

/**
 *	Dado um código de produto e uma filial, determinar os códigos (e número total) dos clientes que o compraram, distinguindo entre compra N e compra P;

 *	@param O QUE RECEBE
 *	@param O QUE RETORNA
*/
int query_9(SGV s, char* produto, int filial, Lista_Strings N, Lista_Strings P);

/**
 *	Dado um código de cliente e um mês, determinar a lista de códigos de produtos que mais comprou por quantidade e não por facturação), por ordem descendente;

 *	@param O QUE RECEBE
 *	@param O QUE RETORNA
*/
void query_10(SGV s, char* cliente, int mes, Lista_Ordenada P);

/**
 *	Criar uma lista dos N produtos mais vendidos em todo o ano, indicando o número total de clientes e o número de unidades vendidas, filial a filial;

 *	@param O QUE RECEBE
 *	@param O QUE RETORNA
*/
void query_11(SGV s, int n, Lista_N F1, Lista_N F2, Lista_N F3);

/**
 *	Dado um código de cliente determinar quais os códigos dos N produtos em que mais gastou dinheiro durante o ano;

 *	@param O QUE RECEBE
 *	@param O QUE RETORNA
*/
int query_12(SGV s, int N, Lista_12 ls, char* cliente);

#endif
