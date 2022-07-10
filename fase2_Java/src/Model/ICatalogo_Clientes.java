package Model;

import java.io.Serializable;
import java.util.*;
/**
 * Interface para Catalogo de Clientes
 * */
public interface ICatalogo_Clientes extends Serializable {

    /**
     * Devolve um Set contendo copias de todos os clientes presentes no catalogo
     * @return Tabela de Clientes num set de strings
     * */
    public Set<String> getTabela_clientes();
    
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
     * Duplica um Model.Cliente
     * */
    public Catalogo_Clientes clone();

    /**
     * Adiciona um cliente ao catalogo
     * @param c Codigo do cliente a ser adicionado
     * */
    public void add(String c);
  
    /**
     * Dado um codigo de cliente, verifica se um cliente com esse codigo se encontra no catalogo
     * @param s Codigo do cliente
     * @return se o catálogo contem o cliente
     * */
    public boolean contains(String s);

    /**
     * Devolve o numero de clientes presentes no catalogo
     * @return número de clientes
     * */
    public int size();
}