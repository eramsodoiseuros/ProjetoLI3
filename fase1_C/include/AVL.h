#ifndef __AVL_H__
#define __AVL_H__

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef struct arvore* AVL;

typedef struct lista_strings* Lista_Strings;

typedef struct lista_ordenada* Lista_Ordenada;

typedef struct lista_12* Lista_12;

typedef struct lista_n* Lista_N;

typedef struct lista_n12* Lista_N12;

/**
 *	Função strdup criada para evitar warnings
 *	@param string 
 *	@param string
 */
char* sdup(const char *s);

/**
 *	Função que transforma uma substring num numero
 *	@param string e um inteiro
 *	@param inteiro
 */
int num_(char string[], int index);

///////////////////////////////////////////////////////////
// LISTA

/**
 *	Função que 
 *	@param 
 */
Lista_Strings iniciar_lista(int size);

/**
 *	Função que insere uma string no fim do array Strings
 *	@param estrutura lista e a string a adicionar
 */
void add_lista(Lista_Strings s, char* c);

/**
 *	Função que devolve uma string numa dada posição da lista
 *	@param estrutura lista e a posição pertendida
 *	@param string pretendida
 */
char* get_elem(Lista_Strings s, int i);

/**
 *	Função que 
 *	@param 
 */
int size_lista(Lista_Strings s);

/**
 *	Função que 
 *	@param 
 */
void delete_lista(Lista_Strings s);

///////////////////////////////////////////////////////////
// LISTA ORDENADA de inteiros

/**
 *	Função que 
 *	@param 
 */
Lista_Ordenada iniciar_lista_ordenada(int size);

/**
 *	Função que insere uma string no fim do array Strings
 *	@param estrutura lista e a string a adicionar
 */
void add_lista_ordenada(Lista_Ordenada s, char* c, int unidades, char tipo);

/**
 *	Função que devolve uma string numa dada posição da lista
 *	@param estrutura lista e a posição pertendida
 *	@param string pretendida
 */
char* get_elem_(Lista_Ordenada s, int i);

/**
 *	Função que 
 *	@param 
 */
int get_unit(Lista_Ordenada s, int i);

/**
 *	Função que 
 *	@param 
 */
int size_lista_ordenada(Lista_Ordenada s);

/**
 *	Função que 
 *	@param 
 */
void delete_lista_ordenada(Lista_Ordenada s);


///////////////////////////////////////////////////////////
// LISTA ORDENADA de doubles

/**
 *	Função que 
 *	@param 
 */
Lista_12 iniciar_lista_12(int size);

/**
 *	Função que insere uma string no fim do array Strings
 *	@param estrutura lista e a string a adicionar
 */
void add_lista_12(Lista_12 s, char* c, double faturado);

/**
 *	Função que devolve uma string numa dada posição da lista
 *	@param estrutura lista e a posição pertendida
 *	@param string pretendida
 */
char* get_elem_12(Lista_12 s, int i);

/**
 *	Função que 
 *	@param 
 */
double get_faturado_12(Lista_12 s, int i);

/**
 *	Função que 
 *	@param 
 */
int size_lista_12(Lista_12 s);

/**
 *	Função que 
 *	@param 
 */
void delete_lista_12(Lista_12 s);

//////////////////////////////////////////////////
// LISTA DE N MAIORES

/**
 *	Função que 
 *	@param 
 */
Lista_N iniciar_nm(int size);

/**
 *	Função que 
 *	@param 
 */
void preenche_nm(Lista_N);

/**
 *	Função que 
 *	@param 
 */
void set_n_clientes(Lista_N s, int i, int num);

/**
 *	Função que 
 *	@param 
 */
char* get_elem_nm(Lista_N s, int i);

/**
 *	Função que 
 *	@param 
 */
int get_unit_nm(Lista_N s, int i);

/**
 *	Função que 
 *	@param 
 */
int get_n_clientes(Lista_N s, int i);

/**
 *	Função que 
 *	@param 
 */
void delete_lista_nm(Lista_N s);

///////////////////////////////////////////////////////////
// ALGORITMO DE ORDENAÇÃO

/**
 *	Função que 
 *	@param 
 */
void heapSort(Lista_Ordenada s);

/**
 *	Função que 
 *	@param 
 */
void heapSort_f(Lista_12 s);

///////////////////////////////////////////////////////////
// AVL

/**
 *	Função que cria um Nodo novo da arvore, ou até mesmo uma arvore nova, com um dado valor
 *	@param valor a inserir na arvore, tipo da arvore
 *	@param apontador para a estrutura
 */
AVL create_nodo(int valor, char* id, char tipo);

/**
 *	Função que liberta o espaço alocado para a estrutura
 *	@param apontador para a estrutura e o tipo da arvore
 */
void free_AVL(AVL a, char tipo);

/**
 *	Função que recursivamente insere um valor numa AVL
 *	@param a arvore e um valor a adicionar na arvore, tipo da arvore
 *	@param apontador para a estrutura
 */
AVL insert_tree(AVL a, int val, char* id, char tipo);

/**
 *	Função que devolve o lado esquerdo de uma arvore
 *	@param o apontador para a estrutura
 *	@param o apontador para a arvore da esquerda
 */
AVL esq(AVL a);

/**
 *	Função que devolve o lado direito de uma arvore
 *	@param o apontador para a estrutura
 *	@param o apontador para a arvore da direita
 */
AVL dir(AVL a);

/**
 *	Função que devolve o valor de uma arvore
 *	@param o apontador para a estrutura
 *	@param o valor da raiz da arvore
 */
int valor(AVL a);

/**
 *	Função que devolve a string de uma arvore
 *	@param o apontador para a estrutura
 *	@param a string da raiz da arvore
 */
char* codigo(AVL a);

///////////////////////////////////////////////////////////
// SEARCG_FUNCTIONS

/**
 *	Função que procura um elemento numa arvore binaria
 *	@param a arvore e um valor a procurar na arvore
 *	@param 1 caso o valor exista, 0 caso não exista
 */
int search_tree(AVL a, int id);

/**
 *	Função que 
 *	@param 
 */
void search_update(AVL a, int id, char tipo, char* cliente, int filial, int mes, double preco, int unidades, char* produto, char NP);

/**
 *	Função que 
 *	@param 
 */
void* search_info(AVL a, int id);

/**
 *	Função que 
 *	@param 
 */
int search_n(AVL a, char tipo);

/**
 *	Função que 
 *	@param 
 */
void search_c(AVL a, Lista_Strings lista, char l1);

/**
 *	Função que 
 *	@param 
 */
void search_p(AVL a, Lista_Strings lista, char l1, char l2, int x);

void search_u(AVL a, int l1, int l2, char tipo, int filial, Lista_N maiores, int n);

#endif
