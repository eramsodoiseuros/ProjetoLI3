#include "../include/AVL.h"
#include "../include/registos_cliente.h"
#include "../include/registos_produto.h"


struct arvore{
	int valor;             // valor para se poder gerir
    void* info;            // info que realmente se guarda
	struct arvore *esq, *dir;
	int altura;
};


struct lista_strings{
    int in_use;
    int size;
    int free_space;
    char** lista;
};


struct lista_ordenada{
    int in_use;
    int size;
    int free_space;
    char** lista;
    int* unidades;
};

struct lista_12{
    int in_use;
    int size;
    int free_space;
    char** lista;
    double* faturado;
};

struct lista_n{
    int N;
    int in_use;
    char** lista;
    int* unidades;
    int* n_clientes;
};


// Função strdup criada para evitar warnings
char* sdup(const char *s){
    size_t tamanho = strlen (s) + 1;
    void *novo = malloc(tamanho);
    if(novo == NULL)
        return NULL;
    return (char *) memcpy (novo, s, tamanho);
}

// Função que transforma uma substring num numero
int num_(char string[], int index){
    return atoi(string+index);
}

//////////////////////////////////////////////////
// STRINGS

// Função que inicia uma Lista de Strings
Lista_Strings iniciar_lista(int size){
    Lista_Strings s = (Lista_Strings) malloc(sizeof(struct lista_strings));
    
    s->in_use = 0;
    s->size = size;
    s->free_space = size;
    s->lista = (char**) malloc(sizeof(char*) * s->free_space);

    return s;
}

// Função que verifica se a Lista está cheia, aloca memória se estiver
void is_full(Lista_Strings s){

    if(s->in_use >= s->free_space){
        s->free_space += s->size;
        s->lista = realloc(s->lista, sizeof(char*) * s->free_space);
    }
}

// Função que insere uma string no fim do array Strings (alocando memória se necessário)
void add_lista(Lista_Strings s, char* c){
    is_full(s);
    s->lista[s->in_use++] = sdup(c);
}

// Função que
int size_lista(Lista_Strings s){
    return s->in_use;
}

// Função que
char* get_elem(Lista_Strings s, int i){
    return s->lista[i];
}

// Função que
void delete_lista(Lista_Strings s){

    for (int i = 0; i < s->in_use; ++i){
        free((char*) s->lista[i]);
    }
    free((char**) s->lista);
    free(s);
}


//////////////////////////////////////////////////
// STRINGS ORDENADAS de inteiros

// Função que inicia uma Lista Ordenada
Lista_Ordenada iniciar_lista_ordenada(int size){
    Lista_Ordenada s = (Lista_Ordenada) malloc(sizeof(struct lista_ordenada));
    
    s->in_use = 0;
    s->size = size;
    s->free_space = size;
    s->lista = (char**) malloc(sizeof(char*) * size);
    s->unidades = (int*) malloc(sizeof(int) * size);

    return s;
}

// Função que verifica se a Lista está cheia, aloca memória se estiver
void is_full_(Lista_Ordenada s){

    if(s->in_use >= s->free_space){
        s->free_space += s->size;
        s->lista = realloc(s->lista, sizeof(char*) * s->free_space);
        s->unidades = realloc(s->unidades, sizeof(int) * s->free_space);
    }
}

// Função que
int existe_in(Lista_Ordenada s, char* c, char tipo){
    int r = -1;

    if(tipo == 'c'){
        for(int aux = 1; aux < s->in_use; aux++)
            if(num_(c, 1) == num_(s->lista[aux], 1))
                if(c[0] == s->lista[aux][0])
                    r = aux;
    }

    if(tipo == 'p'){
        for(int aux = 0; aux < s->in_use; aux++)
            if(c[0] == s->lista[aux][0])
                if(c[1] == s->lista[aux][1])
                    if(num_(c, 2) == num_(s->lista[aux], 2))
                        r = aux;
    }

    return r;
}

// Função que insere uma string no fim do array Strings (alocando memória se necessário)
void add_lista_ordenada(Lista_Ordenada s, char* c, int unidades, char tipo){
    int r = 0, aux = 0;
    is_full_(s);
    if(s->in_use == 0){
        s->lista[0] = sdup(c);
        s->unidades[0] = unidades;
        s->in_use++;
    }
    else if( (r = existe_in(s, c, 'p'))  == -1 ){
        aux = s->in_use++;
        s->lista[aux] = sdup(c);
        s->unidades[aux] = unidades;
    }
    else{
        s->lista[r] = sdup(c);
        s->unidades[r] += unidades;
    }
}

// Função que
int size_lista_ordenada(Lista_Ordenada s){
    return s->in_use;
}

// Função que
char* get_elem_(Lista_Ordenada s, int i){
    return s->lista[i];
}

// Função que
int get_unit(Lista_Ordenada s, int i){
    return s->unidades[i];
}

// Função que
void delete_lista_ordenada(Lista_Ordenada s){
    
    for (int i = 0; i < s->in_use; ++i){
        free((char*) s->lista[i]);
    }
    free((char**) s->lista);
    free(s->unidades);
    free(s);
}


//////////////////////////////////////////////////
// STRINGS ORDENADAS de doubles

// Função que inicia uma Lista Ordenada
Lista_12 iniciar_lista_12(int size){
    Lista_12 s = (Lista_12) malloc(sizeof(struct lista_12));
    
    s->in_use = 0;
    s->size = size;
    s->free_space = size;
    s->lista = (char**) malloc(sizeof(char*) * size);
    s->faturado = (double*) malloc(sizeof(double) * size);

    return s;
}

// Função que verifica se a Lista está cheia, aloca memória se estiver
void is_full_12(Lista_12 s){

    if(s->in_use >= s->free_space){
        s->free_space += s->size;
        s->lista = realloc(s->lista, sizeof(char*) * s->free_space);
        s->faturado = realloc(s->faturado, sizeof(double) * s->free_space);
    }
}

// Função que
int existe_in_12(Lista_12 s, char* c){
    int r = -1;

    for(int aux = 0; aux < s->in_use; aux++)
        if(c[0] == s->lista[aux][0])
            if(c[1] == s->lista[aux][1])
                if(num_(c, 2) == num_(s->lista[aux], 2))
                    r = aux;

    return r;
}

// Função que insere uma string no fim do array Strings (alocando memória se necessário)
void add_lista_12(Lista_12 s, char* c, double faturado){
    int r = 0, aux = 0;
    is_full_12(s);
    if(s->in_use == 0){
        s->lista[0] = sdup(c);
        s->faturado[0] = faturado;
        s->in_use++;
    }
    else if( (r = existe_in_12(s, c))  == -1 ){
        aux = s->in_use++;
        s->lista[aux] = sdup(c);
        s->faturado[aux] = faturado;
    }
    else{
        s->lista[r] = sdup(c);
        s->faturado[r] += faturado;
    }
}

// Função que
int size_lista_12(Lista_12 s){
    return s->in_use;
}

// Função que
char* get_elem_12(Lista_12 s, int i){
    return s->lista[i];
}

// Função que
double get_faturado_12(Lista_12 s, int i){
    return s->faturado[i];
}

// Função que
void delete_lista_12(Lista_12 s){
    
    for (int i = 0; i < s->in_use; i++){
        free((char*) s->lista[i]);
    }
    free((char**) s->lista);
    free(s->faturado);
    free(s);
}


//////////////////////////////////////////////////
// LISTA DE N MAIORES

// Função que inicia uma Lista Ordenada
Lista_N iniciar_nm(int size){
    Lista_N s = (Lista_N) malloc(sizeof(struct lista_n));
    
    s->in_use = 0;
    s->N = size;
    s->lista = (char**) malloc(sizeof(char*) * size);
    s->unidades = (int*) malloc(sizeof(int) * size);
    s->n_clientes = (int*) malloc(sizeof(int) * size);

    return s;
}

void preenche_nm(Lista_N s){
    for(int i = 0; i < s->N; i++){
        s->lista[i] = "__";
        s->unidades[i] = 0;
        s->n_clientes[i] = 0;
    }
}

void set_n_clientes(Lista_N s, int i, int num){
    s->n_clientes[i] = num;
}

// Função que
char* get_elem_nm(Lista_N s, int i){
    return s->lista[i];
}

// Função que
int get_unit_nm(Lista_N s, int i){
    return s->unidades[i];
}

int get_n_clientes(Lista_N s, int i){
    return s->n_clientes[i];
}

// Função que
void delete_lista_nm(Lista_N s){
    for (int i = 0; i < s->N; ++i){
        free((char*) s->lista[i]);
    }
    
    free(s->unidades);
    free(s->n_clientes);
    free(s);
}

///////////////////////////////////////////////////////////
// ALGORITMO DE ORDENAÇÃO das listas ordenadas por ordem decrescente

void swap(Lista_Ordenada s, int a, int b){
    char* aux = sdup(s->lista[a]);
    int aux2 = s->unidades[a];

    s->lista[a] = sdup(s->lista[b]);
    s->unidades[a] = s->unidades[b];

    s->lista[b] = sdup(aux);
    s->unidades[b] = aux2;

    free((char*) aux);
}

//
void heapify(Lista_Ordenada s, int n, int i){
    int smallest = i; // Initialize smallest as root 
    int l = 2*i + 1; // left = 2*i + 1 
    int r = 2*i + 2; // right = 2*i + 2 
  
    // If left child is smaller than root 
    if (l < n && s->unidades[l] < s->unidades[smallest])
        smallest = l;
  
    // If right child is smaller than smallest so far 
    if (r < n && s->unidades[r] < s->unidades[smallest])
        smallest = r;
  
    // If smallest is not root 
    if (smallest != i){
        swap(s, i, smallest);
  
        // Recursively heapify the affected sub-tree 
        heapify(s, n, smallest);
    }
}
  
// main function to do heap sort 
void heapSort(Lista_Ordenada s){
    // Build heap (rearrange array) 
    for (int i = s->in_use / 2 - 1; i >= 0; i--)
        heapify(s, s->in_use, i);
  
    // One by one extract an element from heap 
    for (int i = s->in_use - 1; i > 0; i--){
        // Move current root to end 
        swap(s, 0, i);
  
        // call max heapify on the reduced heap 
        heapify(s, i, 0);
    }
}

void swap_f(Lista_12 s, int a, int b){
    char* aux = sdup(s->lista[a]);
    int aux2 = s->faturado[a];

    s->lista[a] = sdup(s->lista[b]);
    s->faturado[a] = s->faturado[b];

    s->lista[b] = sdup(aux);
    s->faturado[b] = aux2;

    free((char*) aux);
}

//
void heapify_f(Lista_12 s, int n, int i){
    int smallest = i; // Initialize smallest as root 
    int l = 2*i + 1; // left = 2*i + 1 
    int r = 2*i + 2; // right = 2*i + 2 
  
    // If left child is smaller than root 
    if (l < n && s->faturado[l] < s->faturado[smallest])
        smallest = l;
  
    // If right child is smaller than smallest so far 
    if (r < n && s->faturado[r] < s->faturado[smallest])
        smallest = r;
  
    // If smallest is not root 
    if (smallest != i){
        swap_f(s, i, smallest);
  
        // Recursively heapify the affected sub-tree 
        heapify_f(s, n, smallest);
    }
}
  
// main function to do heap sort 
void heapSort_f(Lista_12 s){
    // Build heap (rearrange array) 
    for (int i = s->in_use / 2 - 1; i >= 0; i--)
        heapify_f(s, s->in_use, i);
  
    // One by one extract an element from heap 
    for (int i = s->in_use - 1; i > 0; i--){
        // Move current root to end 
        swap_f(s, 0, i);
  
        // call max heapify on the reduced heap 
        heapify_f(s, i, 0);
    }
}

//////////////////////////////////////////////////
// AVL

// Função que devolve o lado esquerdo de uma arvore
AVL esq(AVL t){
    return t->esq;
}

// Função que devolve o lado direito de uma arvore
AVL dir(AVL t){
    return t->dir;
}

// Função que devolve o valor de uma arvore
int valor(AVL t){
    return t->valor;
}

// Função que devolve a string de uma arvore
char* codigo(AVL t){
    return (char*) t->info;
}

// Função que indica o maior de dois números
int max(int a, int b){ 
    return (a > b)? a : b;
}

// Função que indica a altura de uma arvore
int altura(AVL a){
    return (a == NULL)? 0 : a->altura;
}

// Função que cria um Nodo novo da arvore, ou até mesmo uma arvore nova, com um dado valor
AVL create_nodo(int valor, char* id, char tipo){
    AVL new = malloc(sizeof(struct arvore));

    new->valor = valor;

    if(tipo == 'b'){
        new->info = sdup(id);
    }

    if(tipo == 'c'){
        new->info = iniciar_cliente();
    }

    if(tipo == 'p'){
        new->info = iniciar_produto();
    }

    new->esq = NULL;
    new->dir = NULL;
    new->altura = 1;

    return(new);
}

// Função que liberta o espaço alocado para a estrutura
void free_AVL(AVL a, char tipo){
    free_AVL(a->esq, tipo);
    free_AVL(a->dir, tipo);

    if(tipo == 'b'){
        free((char*) a->info);
        free(a);
    }

    if(tipo == 'c'){
        free_cliente(a->info);
        free(a);
    }

    if(tipo == 'p'){
        free_produto(a->info);
        free(a);
    }
}

// Função que balança a arvore para a direita
AVL rotate_dir(AVL y){
    AVL x = y->esq;
    AVL T2 = x->dir;

    x->dir = y;
    y->esq = T2;

    y->altura = max(altura(y->esq), altura(y->dir))+1;
    x->altura = max(altura(x->esq), altura(x->dir))+1;

    return x; 
}
  
// Função que balança a arvore para a esquerda
AVL rotate_esq(AVL x){ 
    AVL y = x->dir;
    AVL T2 = y->esq;

    y->esq = x;
    x->dir = T2;

    x->altura = max(altura(x->esq), altura(x->dir))+1;
    y->altura = max(altura(y->esq), altura(y->dir))+1;

    return y;
}

// Função que indica a diferença do balanceamento da arvore
int difBalance(AVL a){
    return (a == NULL)? 0 : altura(a->esq) - altura(a->dir);
}

// Função que recursivamente insere um valor numa AVL
AVL insert_tree(AVL a, int val, char* id, char tipo){
	int balance;

    if(a == NULL){
        AVL new = create_nodo(val, id, tipo);
    	return(new);
    }

    if(val < a->valor) a->esq = insert_tree(a->esq, val, id, tipo);
    else if(val > a->valor) a->dir = insert_tree(a->dir, val, id, tipo);
    else return a;
        
    a->altura = 1 + max(altura(a->esq),altura(a->dir));
    balance = difBalance(a);

    if(balance > 1 && val < a->esq->valor)
        return rotate_dir(a);

    if(balance < -1 && val > a->dir->valor)
        return rotate_esq(a);

    if(balance > 1 && val > a->esq->valor){ 
        a->esq = rotate_esq(a->esq);
        return rotate_dir(a);
    }

    if(balance < -1 && val < a->dir->valor){
        a->dir = rotate_dir(a->dir);
        return rotate_esq(a);
    }

    return a;
} 


/////////////////////////////////////////////////////
// SEARCH_FUNTIONS

// Função que procura um elemento numa arvore binaria
int search_tree(AVL a, int id){
	int r;
	if(a == NULL) r = 0;
	else{
		if(id == a->valor) r = 1;
		else{
			if(id < a->valor) r = search_tree(a->esq, id);
			else r = search_tree(a->dir, id);
		}
	}

	return r;
}

// Função que procura um elemento numa arvore binaria
void search_update(AVL a, int id, char tipo, char* cliente, int filial, int mes, double preco, int unidades, char* produto, char NP){

    if(tipo == 'c'){
        if(a == NULL);
        else{
            if(id == a->valor){
                update_registo_c( (Cliente) a->info, filial, mes, preco, unidades, produto, NP);
            }
            else{
                if(id < a->valor) search_update(a->esq, id, tipo, cliente, filial, mes, preco, unidades, produto, NP);
                else search_update(a->dir, id, tipo, cliente, filial, mes, preco, unidades, produto, NP);
            }
        }
    }
    
    if(tipo == 'p'){
        if(a == NULL);
        else{
            if(id == a->valor){
                update_registo_p( (Produto) a->info, filial, mes, preco, unidades, cliente, NP);
            }
            else{
                if(id < a->valor) search_update(a->esq, id, tipo, cliente, filial, mes, preco, unidades, produto, NP);
                else search_update(a->dir, id, tipo, cliente, filial, mes, preco, unidades, produto, NP);
            }
        }
    }
}

// Função que
int search_n(AVL a, char tipo){
    int r = 0;
    if(tipo == 'c'){
        if(a == NULL) r = 0;
        else{
            if(comprou(a->info))
                r++; 
            r += search_n(a->esq,'c');
            r += search_n(a->dir,'c');
        }
    }
    
    if(tipo == 'p'){
        if(a == NULL) r = 0;
        else{
            if(vendeu(a->info))
                r++; 
            r += search_n(a->esq,'p');
            r += search_n(a->dir,'p');
        }
    }
    return r;
}

// Função que
void search_c(AVL a, Lista_Strings lista, char l1){

    char* s = malloc(sizeof(char)*6);
    
    if(a == NULL);
    else{
        if(comprou_tudo(a->info)){
            sprintf(s,"%c%d", l1, a->valor);
            add_lista(lista, s); 
        }
        search_c(a->esq, lista, l1);
        search_c(a->dir, lista, l1);
    }

    free((char*) s);
}

// Função que
void search_p(AVL a, Lista_Strings lista, char l1, char l2, int x){

    char* s = malloc(sizeof(char)*7);
    
    if(a == NULL);
    else{
        if(vendeu_in(a->info, x)){
            sprintf(s,"%c%c%d", l1, l2, a->valor);
            add_lista(lista, s);
        }
        search_p(a->esq, lista, l1, l2, x);
        search_p(a->dir, lista, l1, l2, x);
    }

    free((char*) s);
}

// Função que
void* search_info(AVL a, int id){
    void* r = NULL;

    if(a == NULL);
    else{
        if(id == a->valor){
            r = a->info;
        }
        else{
            if(id < a->valor) r = search_info(a->esq, id);
            else r = search_info(a->dir, id);
        }
    }

    return r;
}


void maior_que(int a, int valor, char l1, char l2, Lista_N lista, int size){
    int r = 0;
    char* s = malloc(sizeof(char)*7);
    sprintf(s,"%c%c%d", l1, l2, valor);
    char* aux = malloc(sizeof(char)*7);

    for(int i = 0; i < size; i++)
        if(a > lista->unidades[i]){
            r = lista->unidades[i];
            aux = sdup(lista->lista[i]);

            lista->unidades[i] = a;
            lista->lista[i] = sdup(s);
            
            a = r;
            s = sdup(aux);
        }

    free((char*) aux);
    free((char*) s);
}

// Função que
void search_u(AVL a, int l1, int l2, char tipo, int filial, Lista_N maiores, int n){
    char a1 = l1+'A', b2 = l2+'A';

    if(tipo == 'p'){
        if(a == NULL);
        else{
            maior_que(unidades_vendidas(a->info, filial), a->valor, a1, b2, maiores, n);
            search_u(a->esq, l1, l2, 'p', filial, maiores, n);
            search_u(a->dir, l1, l2, 'p', filial, maiores, n);
        }
    }
}