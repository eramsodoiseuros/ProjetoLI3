package Model;

import java.io.Serializable;
import java.util.*;

/**
 * Interface do Model.Cliente
 * */
public interface ICliente extends Serializable, Comparable<Cliente> {

    /**
     * Verifica se o cliente é igual a um outro objceto
     * @param o Objecto
     * @return se o cliente é igual a um outro objceto
     * */
    public boolean equals(Object o);

    /**
     * Metodo que converte a informação da classe em String
     * @return informação do cliente e se ele comprou
     * */
    public String toString();

    /**
     * Metodo que cria uma cópia do Model.Cliente
     * */
    public ICliente clone();

    /**
     * Metodo que devolve o codigo do cliente
     * @return ID do cliente
     * */
    public String getId();

    /**
     * Metodo que devolve se o cliente realizou compras
     * @return se o cliente realizou compras
     * */
    public boolean isComprou();

    /**
     * Metodo que devolve uma tabela com as compras realizadas pelo cliente, por mês e por filial
     * @return tabela com as compras realizadas pelo cliente, por mês e por filial
     * */
    public int[][] getVolume_compras();

    /**
     * Metodo que devolve uma tabela com os gastos de um cliente, por mês e por filial
     * @return tabela com os gastos de um cliente, por mês e por filial
     * */
    public double[][] getDespeza_compras();

    /**
     * Realiza o update da estrutura
     * @param produto código de produto
     * @param filial número da filial
     * @param mes número do mês
     * @param preco preço da venda
     * @param unidades unidades vendidas
     * @param NP token de compras normais ou de promoção
     * */
    public void update_registo(String produto, int filial, int mes, double preco, int unidades, char NP);

    /**
     * Metodo que devolve quantos produtos distintos um cliente comprou
     * @return quantos produtos distintos um cliente comprou
     * */
    public int[] produtos_d();

    /**
     * Metodo que devolve um mapa com os Produtos comprados por um cliente e as unidades compradas desse produto
     * @return mapa com os Produtos comprados por um cliente e as unidades compradas desse produto
     * */
    public Map<String, Integer> getProdutos_Unidades();

    /**
     * Metodo que verifica se um cliente comprou num certo mês e filial
     * @return se um cliente comprou num certo mês e filial
     * */
    public boolean comprou_fm(int mes, int filial);

    /**
     * Metodo que devolve quanto um cliente faturou num dado mês
     * @return quanto um cliente faturou num dado mês
     * */
    public double quanto_faturou(int i);

    /**
     * Metodo que devolve os produtos distintos do cliente
     * @return produtos distintos do cliente
     * */
    public int produtos_distintos();

    /**
     * Metodo que verifica se um cliente comprou num certo mês
     * @return verifica se um cliente comprou num certo mês
     * */
    public boolean comprou_mes(int mes);
}
