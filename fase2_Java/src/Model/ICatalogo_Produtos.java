package Model;

import java.io.Serializable;
import java.util.*;
/**
 * Interface para Catalogo de Produtos
 * */
public interface ICatalogo_Produtos extends Serializable {

    /**
     * Devolve um Set contendo copias de todos os Produtos presentes no catalogo
     * @return Tabela de Produtos num set de strings
     * */
    public Set<String> getTabela_Produtos();
    
    /**
     * Metodo que converte a informação da classe em String
     * @return informação da classe
     * */
    public String toString();

    /**
     * Verifica se um catalogo é igual a um outro objeto
     * @param o Objecto
     * @return se um catalogo é igual a outro objeto
     * */
    public boolean equals(Object o);

    /**
     * Duplica um produto
     * */
    public Catalogo_Produtos clone();

    /**
     * Adiciona um produto ao catalogo
     * @param p Codigo do produto a ser adicionado
     * */
    public void add(String p);
  
    /**
     * Dado um codigo de produto, verifica se um produto com esse codigo se encontra no catalogo
     * @param s Codigo do produto
     * @return se o catálogo contem o produto
     * */
    public boolean contains(String s);

    /**
     * Devolve o numero de Produtos presentes no catalogo
     * @return número de produtos
     * */
    public int size();
}