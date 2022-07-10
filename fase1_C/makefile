INC = ./include/
OBJ = ./src/


objects = $(OBJ)main.o $(OBJ)IO.o $(OBJ)interface.o $(OBJ)catalogo_vendas.o $(OBJ)catalogo_produtos.o $(OBJ)catalogo_clientes.o $(OBJ)AVL.o $(OBJ)faturacao.o $(OBJ)filial.o $(OBJ)registos_cliente.o $(OBJ)registos_produto.o
CFLAGS = -g -Wall -ansi -std=c99 -pedantic -O2 
CC = gcc


SGV : $(objects)
	$(CC) $(CFLAGS) -o SGV $(objects) 


main.o : $(INC)main.h $(INC)catalogo_vendas.h $(INC)IO.o
IO.o : $(INC)IO.h $(INC)interface.h 
interface.o : $(INC)interface.h $(INC)catalogo_vendas.h $(INC)catalogo_produtos.h $(INC)catalogo_clientes.h
catalogo_vendas.o : $(INC)catalogo_vendas.h $(INC)catalogo_produtos.h $(INC)catalogo_clientes.h $(INC)AVL.h $(INC)faturacao.h $(INC)filial.h
catalogo_produtos.o : $(INC)catalogo_produtos.h $(INC)AVL.h
catalogo_clientes.o : $(INC)catalogo_clientes.h $(INC)AVL.h
AVL.o : $(INC)AVL.h
faturacao.o : $(INC)faturacao.h 
filial.o : $(INC)filial.h
registos_cliente.o : $(INC)registos_produto.h $(INC)AVL.h
registos_produto.o : $(INC)registos_cliente.h $(INC)AVL.h




.PHONY : clean
clean : 
	rm SGV $(objects)