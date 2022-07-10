package Model;

import java.io.Serializable;
import java.util.*;

public interface IFilial extends Serializable {

    /**
     * Adiciona um cliente à estrutura Registo de Model.Cliente, presente na filial
     * @param c Codigo do cliente a ser adicionado
     * */
    public void addRC(String c);

    /**
     * Adiciona um produto à estrutura Registo de Produto, presente na filial
     * @param p Codigo do produto a ser adicionado
     * */
    public void addRP(String p);

    /**
     * Duplica uma Model.Filial
     * */
    public Filial clone();

    /**
     * Devolve um Registo de Clientes contendo copias de todos os clientes
     * */
    public Registo_Clientes getRC();

    /**
     * Devolve um Registo de Produtos contendo copias de todos os produtos
     * */
    public Registo_Produtos getRP();

    /**
     * Realiza o update da estrutura
     * @param produto Codigo do produto
     * @param cliente Codigo do cliente
     * @param filial número da filial
     * @param mes número do mês
     * @param preco preço da venda
     * @param unidades unidades vendidas
     * @param NP código correspondente a vendas normais/promoção
     * */
    public void update_filial(String produto, String cliente, int filial, int mes, double preco, int unidades, char NP);

    /**
     * Metodo que finaliza a estrutura filial
     * */
    public void finalizar();

    /**
     * Metodo que converte a informação da classe em String
     * @return informação da estrutura
     * */
    public String toString();
}
