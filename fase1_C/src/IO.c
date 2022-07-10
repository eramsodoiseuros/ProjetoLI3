#include "../include/IO.h"
#include "../include/AVL.h"



// Print do menu, com a informação das queries
void print_menu(){
	printf("%s\n************************************************** Sistema de Gestão de Vendas ************************************************** %s\n", KCYN, RST);
	printf("%s\n\t->%s Query 2:  Determinar a lista e o nº total de produtos cujo código se inicia por uma dada letra (maiúscula).\n" , KCYN, RST);
	printf("%s\n\t->%s Query 3:  Dado um mês e um produto, determinar e apresentar o nº total de vendas,\n\t   O total facturado com esse produto nesse mês, tendo em conta a distinção N/P,\n\t   Escolhendo a apresentação dos resultados dividida por filial.\n" , KCYN, RST);
	printf("%s\n\t->%s Query 4:  Determinar a lista ordenada de produtos que ninguém comprou e o seu total,\n\t   Havendo a possibilidade de escolher a apresentação dos resultados dividida por filial.\n", KCYN, RST);
	printf("%s\n\t->%s Query 5:  Determinar a lista ordenada de clientes que realizaram compras em todas as filiais.\n", KCYN, RST);
	printf("%s\n\t->%s Query 6:  Determinar o nº de clientes registados que não realizaram compras.\n\t   Determinar o nº de produtos que ninguém comprou.\n", KCYN, RST);
	printf("%s\n\t->%s Query 7:  Dado um cliente, criar uma tabela com o nº total de produtos comprados, mês a mês, organizado por filial.\n", KCYN, RST);
	printf("%s\n\t->%s Query 8:  Dado um intervalo de tempo (de mês __ a mês __):\n\t   Determinar o total de vendas registadas nesse intervalo e o total facturado.\n", KCYN, RST);
	printf("%s\n\t->%s Query 9:  Dado um produto e uma filial, determinar os clientes e o nº de clientes que o compraram,\n\t   Distinguindo a compra entre N e P.\n", KCYN, RST);
	printf("%s\n\t->%s Query 10: Dado um cliente e um mês, determinar a lista de\n\t   Produtos que esse cliente mais comprou, por ordem decrescente.\n", KCYN, RST);
	printf("%s\n\t->%s Query 11: Criar uma lista dos N produtos mais vendidos em todo o ano,\n\t   Indicando o nº total de clientes e o nº total de unidades vendidas, filial a filial.\n", KCYN, RST);
	printf("%s\n\t->%s Query 12: Dado um cliente, determinar os N produtos em que gastou mais dinheiro durante o ano.\n\n", KCYN, RST);
	printf("%s********************************************************************************************************************************* %s\n", KCYN, RST);
}

// Função que
int escolhe_file(){
	int r=1;
	char* inpt = malloc(sizeof(char)*buffsize);
	printf("%s\n\tQue ficheiro pretende ler? %sClientes.txt [1], Produtos.txt [2], Vendas_1M.txt [3], Vendas_3M [4], Vendas_5M [5]\n\t->  ",KBLU,RST);
		
	if(scanf("%s", inpt)){
		r = atoi(inpt);
	}
 	if(r < 1 || r > 5){
 		printf("%sInput Inválido.%s\n",KRED,RST);
    	r = escolhe_file();
  	}

  	free(inpt);
	return r;
}

// Função que
void navegador(Lista_Strings lista, int tamanho){

	int val = 1, exit = 0;
	char* inpt = malloc(sizeof(char)*buffsize);
	int validstr = 1, scanout = 1;
	int pag = 1, i = 0, count = 0;
	int pagnum = 1;

	if(tamanho%10 == 0) pagnum = tamanho/10;
	else pagnum = (tamanho/10)+1;

	while(exit!=1){
		
		if(scanout==0 || pag>pagnum || pag<0 || val==0 || lista==NULL){
			val=1;
			printf("Página inválida ou não existente\n");
		}
		else{

			if(lista || pag < pagnum)
			printf("%s************ Página %d de %d ************%s\n",KBLU,(pag),pagnum, RST);
			printf("Existem %s%d%s resultados\n\n",KBLU, tamanho, RST);
	             
			for(i=(pag*10)-Pagsize; count<Pagsize && count<tamanho; i++){
				if(get_elem(lista,i)!=NULL){
					printf("%s \n", get_elem(lista,i));
					count++;
				}
				else break;			
			}
			count = 0;
		}

		printf("\n");

		if(pagnum == 1)
			return;

		printf("%s(D para Proxima página) \n",KBLU);
		printf("%s(A para Página Anterior) \n",KBLU);
		printf("%s(E para sair)%s \n",KRED,RST);
		printf("Inserir número página: \n");

		scanout = read(0,inpt,buffsize);
		inpt = strtok(inpt," \n");

		validstr = atoi(inpt);
		printf("\n");

		if(strcmp(inpt,"e") == 0 || strcmp(inpt,"E") == 0){exit = 1;}
		else if((strcmp(inpt,"d") == 0 || strcmp(inpt,"D") == 0) && pag<pagnum) pag++;
		else if((strcmp(inpt,"a") == 0 || strcmp(inpt,"A") == 0) && pag>1) pag--;
		else if(validstr==0) val = 0;
		else if(validstr!=0) pag = validstr;
    }

	free(inpt);
}

// Função que
void navegador_(Lista_Ordenada lista, int tamanho){

	int val = 1, exit = 0;
	char* inpt = malloc(sizeof(char)*buffsize);
	int validstr = 1, scanout = 1;
	int pag = 1, i = 0, count = 0;
	int pagnum = 1;

	if(tamanho%10 == 0) pagnum = tamanho/10;
	else pagnum = (tamanho/10)+1;


	while(exit!=1){
		
		if(scanout==0 || pag>pagnum || pag<0 || val==0 || lista==NULL){
			val=1;
			printf("Página inválida ou não existente\n");
		}
		else{

			if(lista || pag < pagnum)
			printf("%s************ Página %d de %d ************%s\n",KBLU,(pag),pagnum, RST);
			printf("Existem %s%d%s resultados\n\n",KBLU, tamanho, RST);
	             
			for(i = (pag*10) - Pagsize; count < Pagsize && count < tamanho; i++){
				if(get_elem_(lista,i) != NULL){
					printf("%s \t %d \n", get_elem_(lista,i), get_unit(lista,i));
					count++;
				}
				else break;			
			}
			count = 0;
		}

		printf("\n");

		if(pagnum == 1)
			return;

		printf("%s(D para Proxima página) \n",KBLU);
		printf("%s(A para Página Anterior) \n",KBLU);
		printf("%s(E para sair)%s \n",KRED,RST);
		printf("Inserir número página: \n");

		scanout = read(0,inpt,buffsize);
		inpt = strtok(inpt," \n");

		validstr = atoi(inpt);
		printf("\n");
		
		if(strcmp(inpt,"e") == 0 || strcmp(inpt,"E") == 0){exit = 1;}
		else if((strcmp(inpt,"d") == 0 || strcmp(inpt,"D") == 0) && pag<pagnum) pag++;
		else if((strcmp(inpt,"a") == 0 || strcmp(inpt,"A") == 0) && pag>1) pag--;
		else if(validstr==0) val = 0;
		else if(validstr!=0) pag = validstr;
    }

	free(inpt);
}

// Função que
void navegador_11(Lista_N lista, int tamanho, int filial){

	int val = 1, exit = 0;
	char* inpt = malloc(sizeof(char)*buffsize);
	int validstr = 1, scanout = 1;
	int pag = 1, i = 0, count = 0;
	int pagnum = 0;

	if(tamanho%10 == 0) pagnum = tamanho/10;
	else pagnum = (tamanho/10)+1;

	while(exit!=1){
		
		if(scanout==0 || pag>pagnum || pag<0 || val==0 || lista==NULL){
			val=1;
			printf("Página inválida ou não existente\n");
		}
		else{

			if(lista || pag < pagnum)
			printf("%s************ Página %d de %d ************%s\n",KBLU,(pag),pagnum, RST);
			printf("Existem %s%d%s resultados na filial %d\n\n",KBLU, tamanho, RST, filial);
	             
			for(i = (pag*10) - Pagsize; count < Pagsize && count < tamanho; i++){
				if(get_elem_nm(lista,i)!=NULL){
					printf("%sProduto:%s %s \t %sUnidades:%s %d \t %sClientes:%s %d \n",KBLU,RST, get_elem_nm(lista,i),KBLU,RST, get_unit_nm(lista,i),KBLU,RST, get_n_clientes(lista,i));
					count++;
				}
				else break;			
			}
			count = 0;
		}

		printf("\n");

		if(pagnum == 1)
			return;

		printf("%s(D para Proxima página) \n",KBLU);
		printf("%s(A para Página Anterior) \n",KBLU);
		printf("%s(E para sair)%s \n",KRED,RST);
		printf("Inserir número página: \n");

		scanout = read(0,inpt,buffsize);
		inpt = strtok(inpt," \n");

		validstr = atoi(inpt);
		printf("\n");
		
		if(strcmp(inpt,"e") == 0 || strcmp(inpt,"E") == 0){exit = 1;}
		else if((strcmp(inpt,"d") == 0 || strcmp(inpt,"D") == 0) && pag<pagnum) pag++;
		else if((strcmp(inpt,"a") == 0 || strcmp(inpt,"A") == 0) && pag>1) pag--;
		else if(validstr==0) val = 0;
		else if(validstr!=0) pag = validstr;
    }

	free(inpt);
}

void navegador_12(Lista_12 lista, int tamanho){

	int val = 1, exit = 0;
	char* inpt = malloc(sizeof(char)*buffsize);
	int validstr = 1, scanout = 1;
	int pag = 1, i = 0, count = 0;
	int pagnum = 1;

	if(tamanho%10 == 0) pagnum = tamanho/10;
	else pagnum = (tamanho/10)+1;
	while(exit!=1){
		
		if(scanout==0 || pag>pagnum || pag<0 || val==0 || lista==NULL){
			val=1;
			printf("Página inválida ou não existente\n");
		}
		else{

			if(lista || pag < pagnum)
			printf("%s************ Página %d de %d ************%s\n",KBLU,(pag),pagnum, RST);
			printf("Existem %s%d%s resultados\n\n",KBLU, tamanho, RST);
	             
			for(i = (pag*10) - Pagsize; count < Pagsize && count < tamanho; i++){
				if(get_elem_12(lista,i) != NULL){
					printf("%sProduto:%s %s \t %sFaturado:%s %f \n",KBLU,RST, get_elem_12(lista,i),KBLU,RST, get_faturado_12(lista,i));
					count++;
				}
				else break;			
			}
			count = 0;
		}

		printf("\n");

		if(pagnum == 1)
			return;

		printf("%s(D para Proxima página) \n",KBLU);
		printf("%s(A para Página Anterior) \n",KBLU);
		printf("%s(E para sair)%s \n",KRED,RST);
		printf("Inserir número página: \n");

		scanout = read(0,inpt,buffsize);
		inpt = strtok(inpt," \n");

		validstr = atoi(inpt);
		printf("\n");
		
		if(strcmp(inpt,"e") == 0 || strcmp(inpt,"E") == 0){exit = 1;}
		else if((strcmp(inpt,"d") == 0 || strcmp(inpt,"D") == 0) && pag<pagnum) pag++;
		else if((strcmp(inpt,"a") == 0 || strcmp(inpt,"A") == 0) && pag>1) pag--;
		else if(validstr==0) val = 0;
		else if(validstr!=0) pag = validstr;
    }

	free(inpt);
}

// Função que
int N_(){
	char* inpt = malloc(sizeof(char)*buffsize);
	int n = 0;
	printf("%sInsira um Número : %s\n",KBLU,RST);

	if(scanf("%s", inpt)){
		n = atoi(inpt);
	}

 	if(!n){
 		printf("%sInput Inválido.%s\n",KRED,RST);
    	n = N_();
  	}

  	free(inpt);
	return n;
}

// Função que
char letra_(){
	char* inpt = malloc(sizeof(char)*buffsize);
	char letra = '1';
	printf("%sInsira uma Letra [A...Z]: %s\n",KBLU,RST);

	if(scanf("%s", inpt)){
		letra = inpt[0];
		if(letra < 'A' || letra >'Z'){
			printf("%sInput Inválido.%s\n",KRED,RST);
			letra = letra_();
		}
	}

	free(inpt);
	return letra;
}


// Função que
int mes_(){
	char* inpt = malloc(sizeof(char)*buffsize);
	int mes = 0;
	printf("%sInsira um Mês [1...12]: %s\n",KBLU,RST);

	if(scanf("%s", inpt)){
		mes = atoi(inpt);
	}

 	if(mes < 1 || mes > 12){
 		printf("%sInput Inválido.%s\n",KRED,RST);
    	mes = mes_();
  	}

  	free(inpt);
	return mes;
}

// Função que
int deseja_sair(){
	char* inpt = malloc(sizeof(char)*buffsize);
	int decisao = 1;

	printf("%s[E para Sair] %s\n",KRED,RST);
	printf("%s[Qualquer outra letra para Ficar] %s\n",KBLU,RST);
	if(scanf("%s",inpt)){
		if(strcmp(inpt,"e") == 0 || strcmp(inpt,"E") == 0)
			decisao = 0;
	}

	free(inpt);
	return decisao;
}

//
char* produto_(Produtos p){
	char* produto = malloc(sizeof(char)*buffsize);

	printf("%sInsira um produto: %s\n",KBLU,RST);
    if(scanf("%s",produto)){
   	
   		while(search_P(p, produto)==0){
			printf("%sProduto Invalido%s\n",KRED,RST);
			produto = produto_(p);
		}
    }

    return produto;
}

//
char* cliente_(Clientes c){
	char* cliente = malloc(sizeof(char)*buffsize);

	printf("%sInsira um cliente: %s\n",KBLU,RST);
    if(scanf("%s",cliente)){
    	while(search_C(c, cliente)==0){
		printf("%sCliente Invalido%s\n",KRED,RST);
			cliente = cliente_(c);
		}
    }

    return cliente;
}

int filial_(){
	char* inpt = malloc(sizeof(char)*buffsize);
	int filial = 0;
	printf("%sInsira uma filial [1..3] ou [4] para valores globais: %s\n",KBLU,RST);
	
	if(scanf("%s",inpt)){
		filial=atoi(inpt);

		while(filial<=0 || filial>4){
			printf("%sOpção Invalida%s\n",KRED,RST);
			if(scanf("%s",inpt));
			filial=atoi(inpt);
		}
	}

	free(inpt);
	return filial;
}

//
void faz_tabela7(char* cliente, int vendas[12][3]){

	int venda_tot = 0;

	printf("%s#################################################################################################################################\n",KBLU);
	printf("%s##                                                                                                                             ##\n",KBLU);
	printf("%s##%s                                                         %s                                                              %s ##\n",KBLU,RST,cliente,KBLU);
	printf("%s##                                                                                                                             ##\n",KBLU);
	printf("%s#################################################################################################################################\n",KBLU);
	printf("%s##                     ##                          ##                       ##                        ##                       ##\n",KBLU);
	printf("%s##%s       Mês           %s##%s       Filial 1           %s##%s     Filial 2          %s##%s      Filial 3          %s##%s    Vendas Totais%s      ##%s\n",KBLU,RST,KBLU,RST,KBLU,RST,KBLU,RST,KBLU,RST,KBLU,RST);
	printf("%s##                     ##                          ##                       ##                        ##                       ##\n",KBLU);
	printf("%s#################################################################################################################################\n",KBLU);

		for (int mes = 0; mes < 12; ++mes){
			for (int i = 0; i < 3; ++i)
			{
				venda_tot += vendas[mes][i];
			}
			printf("%s##                     ##                          ##                       ##                        ##                       ##\n",KBLU);
			printf("%s##%s         %d                      %d                           %d                          %d                      %d         \n",KBLU,RST,mes+1,vendas[mes][0],vendas[mes][1],vendas[mes][2],venda_tot);
			printf("%s#################################################################################################################################%s\n",KBLU,RST);
			venda_tot = 0;
		}
}

//
void load_query2 (SGV s){

	clock_t inicio, fim;
  	double cpu_time_used;
  	char letra;
  	int tamanho;
  	Lista_Strings lista;

	letra = letra_();

	inicio = clock();

	lista = iniciar_lista(700);
	tamanho = query_2(s, letra, lista);

	fim = clock();

	navegador(lista, tamanho);
	delete_lista(lista);

	cpu_time_used = ((double) (fim-inicio) / CLOCKS_PER_SEC);
	printf("CPUTIME: %f\n",cpu_time_used);
}

//
void load_query3 (SGV s){

	clock_t inicio, fim;
  	double cpu_time_used, faturado[3];

  	char* inpt = malloc(sizeof(char)*buffsize);
  	int m1, filial, vendasProd[3];

   	Produtos p = get_produtos_(s);

	inpt = produto_(p);
    m1 = mes_();
    filial = filial_();
    
    inicio = clock();
	
	query_3(s, inpt, m1, vendasProd, faturado, filial);
	
	fim = clock();

	printf("\n");
	printf("%sA totalidade de vendas desse produto com preço normal nesse mês e nessa/nessas filial(ais) é:%s  %d\n",KBLU,RST,vendasProd[1] );
	printf("%sA totalidade de vendas desse produto em promoção nesse mês e nessa/nessas filial(ais) é:%s  %d\n",KBLU,RST,vendasProd[2] );
	printf("%sA totalidade de vendas desse produto nesse mês e nessa/nessas filial(ais) é:%s  %d\n",KBLU,RST,vendasProd[0] );
	printf("\n");
	printf("%sO total faturado desse produto com preço normal nesse mês e nessa/nessas filial(ais) é:%s  %f\n",KBLU,RST,faturado[1] );
	printf("%sO total faturado desse produto em promoção nesse mês e nessa/nessas filial(ais) é:%s  %f\n",KBLU,RST,faturado[2] );
	printf("%sO total faturado desse produto nesse mês e nessa/nessas filial(ais) é:%s  %f\n",KBLU,RST,faturado[0] );
	printf("\n");

	cpu_time_used = ((double) (fim-inicio) / CLOCKS_PER_SEC);
	printf("CPUTIME: %f\n",cpu_time_used);
}

//
void load_query4 (SGV s){

	clock_t inicio, fim;
	double cpu_time_used;

	int filial, tamanho;
	Lista_Strings lista;


	filial = filial_();
	inicio = clock();
		
	lista = iniciar_lista(1000);
	tamanho = query_4(s, lista, filial);

	fim = clock();
			
	navegador(lista, tamanho);
	delete_lista(lista);
				
	cpu_time_used = ((double) (fim-inicio) / CLOCKS_PER_SEC);
	printf("CPUTIME: %f\n", cpu_time_used);
}

//
void load_query5 (SGV s){

	clock_t inicio, fim;
  	double cpu_time_used;

  	Lista_Strings lista;
  	int tamanho;

	inicio = clock();

	lista = iniciar_lista(1500);
	tamanho = query_5(s,lista);

	fim = clock();
				
	navegador(lista, tamanho);
	delete_lista(lista);
				
	cpu_time_used = ((double) (fim-inicio) / CLOCKS_PER_SEC);
	printf("CPUTIME: %f\n",cpu_time_used);
}

//
void load_query6 (SGV s){

	clock_t inicio, fim;
	double cpu_time_used;
	int aux_c[1], aux_p[1];
	aux_c[0] = 0; aux_p[0] = 0;
  		
	inicio = clock();

	query_6(s,aux_c,aux_p);
				
	fim = clock();
				
	printf("%sClientes que não compraram:%s %d\n",KBLU,RST,aux_c[0]);
	printf("%sProdutos que não foram comprados:%s %d\n",KBLU,RST,aux_p[0]);
				
	cpu_time_used = ((double) (fim-inicio) / CLOCKS_PER_SEC);
	printf("CPUTIME: %f\n",cpu_time_used);
}

//
void load_query7 (SGV s){

	clock_t inicio, fim;
  	double cpu_time_used;
  	char* inpt = malloc(sizeof(char)*buffsize);
	int vendas[12][3];

	for (int mes = 0; mes < 12; ++mes){
		for(int filial = 0; filial<3; filial++){
			vendas[mes][filial] = 0;
		}
	}

	Clientes c = get_clientes_(s);
	inpt = cliente_(c);
	
	inicio = clock();
	query_7(s,inpt,vendas);
	fim = clock();

	faz_tabela7(inpt,vendas);
	cpu_time_used = ((double) (fim-inicio) / CLOCKS_PER_SEC);
	printf("CPUTIME: %f\n",cpu_time_used);
}

//
void load_query8 (SGV s){

	clock_t inicio, fim;
  	double cpu_time_used;
  	double f[1]; f[0] = 0;
  	int v[1]; v[0] = 0;
  	int m1, m2, decisao = 1;

	while(decisao){
		m1 = mes_();
		printf("%sAté: %s\n",KBLU,RST);
		m2 = mes_();

		inicio = clock();
		query_8(s, m1, m2, v, f);
		fim = clock();

		printf("%sTotal de vendas nesse intervalo é:%s %d\n",KBLU,RST,v[0]);
		printf("%sE o total faturado nesse intervalo é:%s %f\n",KBLU,RST,f[0]);
			
		cpu_time_used = ((double) (fim-inicio) / CLOCKS_PER_SEC);
		printf("CPUTIME: %f\n",cpu_time_used);		
		decisao = deseja_sair();
	}
}

//
void load_query9 (SGV s){

	clock_t inicio, fim;
	double cpu_time_used;
	int filial;
	char* inpt = malloc(sizeof(char)*buffsize);
	Lista_Strings N, P;

	Produtos p = get_produtos_(s);	 			
	inpt = produto_(p);
	
	filial = filial_();

	inicio = clock();

	N = iniciar_lista(5);
	P = iniciar_lista(5);

	query_9(s, inpt, filial, N, P);

	fim = clock();

	if(size_lista(N) > 0)
		navegador(N, size_lista(N));
	else printf("ha 0 clientes que compraram %s do tipo N\n", inpt);

	if(size_lista(P) > 0)
		navegador(P, size_lista(P));
	else printf("ha 0 clientes que compraram %s do tipo P\n", inpt);

	delete_lista(N);
	delete_lista(P);

	cpu_time_used = ((double) (fim-inicio) / CLOCKS_PER_SEC);
	printf("CPUTIME: %f\n",cpu_time_used);
}

//
void load_query10 (SGV s){

	clock_t inicio, fim;
	double cpu_time_used;

	int m1;
	char* inpt = malloc(sizeof(char)*buffsize);
	Lista_Ordenada P;

  	Clientes c = get_clientes_(s);

	inpt = cliente_(c);
	m1 = mes_();

	inicio = clock();

	P = iniciar_lista_ordenada(25);

	query_10(s, inpt, m1, P);

	fim = clock();

	if(size_lista_ordenada(P) > 0)
		navegador_(P, size_lista_ordenada(P));
	else printf("ha 0 produtos comprados por %s no mes %d\n", inpt, m1);
	
	delete_lista_ordenada(P);
		
	cpu_time_used = ((double) (fim-inicio) / CLOCKS_PER_SEC);
	printf("CPUTIME: %f\n",cpu_time_used);
}

//
void load_query11 (SGV s){

	clock_t inicio, fim;
	double cpu_time_used;

	int n;
	Lista_N F1, F2, F3;

	n = N_();
	if(n > 10 && n%2 == 1) n++;

	inicio = clock();

	F1 = iniciar_nm(n);
	F2 = iniciar_nm(n);
	F3 = iniciar_nm(n);
	
	preenche_nm(F1);
	preenche_nm(F2);
	preenche_nm(F3);

	query_11(s, n, F1, F2, F3);

	fim = clock();
	
	navegador_11(F1, n, 1);
	navegador_11(F2, n, 2);
	navegador_11(F2, n, 3);

	delete_lista_nm(F1);
	delete_lista_nm(F2);
	delete_lista_nm(F3);
		
	cpu_time_used = ((double) (fim-inicio) / CLOCKS_PER_SEC);
	printf("CPUTIME: %f\n",cpu_time_used);
}

//
void load_query12(SGV s){
	clock_t inicio, fim;
	double cpu_time_used;
	
	Clientes c = get_clientes_(s);
	
	int n = N_();
	if(n > 10 && n%2 == 1) n++;

	char* inpt = cliente_(c);

	inicio = clock();

	Lista_12 F1 = iniciar_lista_12(n);

	n = query_12(s, n, F1, inpt);

	fim = clock();
	
	navegador_12(F1, n);

	delete_lista_12(F1);
	
	cpu_time_used = ((double) (fim-inicio) / CLOCKS_PER_SEC);
	printf("CPUTIME: %f\n",cpu_time_used);
}

// Função que escolhe a query a realizar
void escolhe_query(SGV s){
	
	int tarefa;
	char* inpt = malloc(sizeof(char)*buffsize);

	printf("%sEscolha o numero da query que pretende executar%s [2...12]\n\t%sTerminar o programa:%s [1]   ",KBLU,RST,KRED,RST);
	if(scanf("%s", inpt)){
		tarefa = atoi(inpt);
		if(tarefa > 12 || tarefa < 1){
			printf("\n\n\t%sPara executar uma tarefa é necessário inserir um numero de%s [2...12]\n\n\t%sPara terminar o programa insira o número%s 1.\n\n",KBLU,RST,KRED,RST);
			escolhe_query(s);
		}

		switch(tarefa){
			case 1:
				exit(1);
				break;

			case 2:
				load_query2(s);
				break;

			case 3:
    			load_query3(s);
				break;
				
			case 4:
				load_query4(s);
				break;
			
			case 5:
				load_query5(s);
				break;

			case 6:
				load_query6(s);
				break;

			case 7:
				load_query7(s);
				break;

			case 8:
				load_query8(s);
				break;
				
			case 9:
				load_query9(s);
				break;

			case 10:
				load_query10(s);
				break;
	
			case 11:
				load_query11(s);
				break;

			case 12:
				load_query12(s);
				break;
		}
	}
	else{
		printf("\n\t%sO programa falhou na leitura de um número.%s\n",KRED,RST);
		escolhe_query(s);
	}

	free(inpt);
}

// Função que
void load_query1(SGV s){
	int r, num[6];
	
	clock_t i, f;
	double cpu_time_used;
	
	for(int i = 0; i <= 5; i++) num[i] = 0; 

	r = escolhe_file();
	if(r == 1){
		i = clock();
		query_1(s, num, 1);
		f = clock();
		printf("%s\n\tFicheiro lido: %sClientes.txt\n\t%sClientes válidos: %s%d\n\t%sClientes lidos: %s%d\n",KBLU,RST,KBLU,RST,num[0],KBLU,RST,num[1]);
		
		cpu_time_used = ((double) (f-i) / CLOCKS_PER_SEC);
		printf("CPUTIME: %f\n",cpu_time_used);

		query_1(s, num, 6);
	}

	if(r == 2){
		i = clock();
		query_1(s, num, 2);
		f = clock();

		printf("%s\n\tFicheiro lido: %sProdutos.txt\n\t%sProdutos válidos: %s%d\n\t%sProdutos lidos: %s%d\n",KBLU,RST,KBLU,RST,num[2],KBLU,RST,num[3]);

		cpu_time_used = ((double) (f-i) / CLOCKS_PER_SEC);
		printf("CPUTIME: %f\n",cpu_time_used);

		query_1(s, num, 7);
	}

	if (r == 3){
		i = clock();
		query_1(s, num, 3);
		f = clock();
		
		printf("%s\n\tFicheiro lido: %sClientes.txt\n\t%sClientes válidos: %s%d\n\t%sClientes lidos: %s%d\n",KBLU,RST,KBLU,RST,num[0],KBLU,RST,num[1]);
		printf("%s\n\tFicheiro lido: %sProdutos.txt\n\t%sProdutos válidos: %s%d\n\t%sProdutos lidos: %s%d\n",KBLU,RST,KBLU,RST,num[2],KBLU,RST,num[3]);
		printf("%s\n\tFicheiro lido: %sVendas_1M.txt\n\t%sVendas válidas: %s%d\n\t%sVendas lidas: %s%d\n",KBLU,RST,KBLU,RST,num[4],KBLU,RST,num[5]);

		cpu_time_used = ((double) (f-i) / CLOCKS_PER_SEC);
		printf("CPUTIME: %f\n",cpu_time_used);
	}

	if(r == 4){
		i = clock();
		query_1(s, num, 4);
		f = clock();

		printf("%s\n\tFicheiro lido: %sClientes.txt\n\t%sClientes válidos: %s%d\n\t%sClientes lidos: %s%d\n",KBLU,RST,KBLU,RST,num[0],KBLU,RST,num[1]);
		printf("%s\n\tFicheiro lido: %sProdutos.txt\n\t%sProdutos válidos: %s%d\n\t%sProdutos lidos: %s%d\n",KBLU,RST,KBLU,RST,num[2],KBLU,RST,num[3]);
		printf("%s\n\tFicheiro lido: %sVendas_3M.txt\n\t%sVendas válidas: %s%d\n\t%sVendas lidas: %s%d\n",KBLU,RST,KBLU,RST,num[4],KBLU,RST,num[5]);
		
		cpu_time_used = ((double) (f-i) / CLOCKS_PER_SEC);
		printf("CPUTIME: %f\n",cpu_time_used);
	}

	if(r == 5){
		i = clock();
		query_1(s, num, 5);
		f = clock();

		printf("%s\n\tFicheiro lido: %sClientes.txt\n\t%sClientes válidos: %s%d\n\t%sClientes lidos: %s%d\n",KBLU,RST,KBLU,RST,num[0],KBLU,RST,num[1]);
		printf("%s\n\tFicheiro lido: %sProdutos.txt\n\t%sProdutos válidos: %s%d\n\t%sProdutos lidos: %s%d\n",KBLU,RST,KBLU,RST,num[2],KBLU,RST,num[3]);
		printf("%s\n\tFicheiro lido: %sVendas_5M.txt\n\t%sVendas válidas: %s%d\n\t%sVendas lidas: %s%d\n",KBLU,RST,KBLU,RST,num[4],KBLU,RST,num[5]);
		
		cpu_time_used = ((double) (f-i) / CLOCKS_PER_SEC);
		printf("CPUTIME: %f\n",cpu_time_used);
	}
}

// to print or not to print
void menu(SGV s){
	char* r = malloc(sizeof(char*));
	printf("%sPretende dar print ao menu?%s Yes: [y] No: [n]\n",KBLU,RST);

	if(scanf("%s", r)){
		if((r[0] == 'y' || r[0] == 'Y') && atoi(r) == 0){
			print_menu();
			load_query1(s);
			while(1){
				escolhe_query(s);
			}
		}

		if((r[0] == 'n' || r[0] == 'N') && atoi(r) == 0){
			load_query1(s);
			while(1){
				escolhe_query(s);
			}
		}
		else {
			printf("%s\n\tO programa falhou na leitura da resposta. Yes: [y/Y] No: [n/N]%s\n",KRED,RST);
			printf("\n");
			menu(s);
		}
	}

	destroySGV(s);
	free(r);
}
