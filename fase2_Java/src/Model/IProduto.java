package Model;

import java.io.Serializable;
import java.util.List;

/**
 * Interface do Produto
 * */
public interface IProduto extends Serializable, Comparable<Produto>{

    /**
     * Verifica se é igual a um outro objecto
     * @param o Objecto a comparar
     * @return se é igual a um outro objecto
     * */
    public boolean equals(Object o);

    /**
     * Metodo que converte a informação da classe em String
     * @return informação da estrutura
     * */
    public String toString();

    /**
     * Metodo que cria uma cópia do Produto
     * @return cópia do Produto
     * */
    public Produto clone() throws CloneNotSupportedException;

    /**
     * Metodo que devolve o codigo de produto
     * @return codigo de produto
     * */
    public String getId();

    /**
     * Metodo que devolve se um produto foi vendido ou não
     * @return se um produto foi vendido ou não
     * */
    public boolean isVendido();

    /**
     * Metodo que devolve uma tabela em que se encontra a informação de
     * quantas vezes um produto foi vendido, por mês e por filial
     * @return tabela em que se encontra a informação de quantas vezes um produto foi vendido, por mês e por filial
     * */
    public int[][] getVezes_comprado();

    /**
     * Metodo que devolve uma tabela em que se encontra a informação de quantas
     * vezes um produto faturou, por mês e por filiale por compra normal ou promoção
     * @return tabela em que se encontra a informação de quantas vezes um produto faturou, por mês e por filiale por compra normal ou promoção
     * */
    public double[][][] getFaturado_in();

    /**
     * Metodo que devolve uma tabela em que se encontra a informação de
     * quantas vezes um produto foi vendido por compra normal, por mês e por filial
     * @return tabela em que se encontra a informação de quantas vezes um produto foi vendido por compra normal, por mês e por filial
     * */
    public int[][] getVezes_N();

    /**
     * Metodo que devolve uma tabela em que se encontra a informação de
     * quantas vezes um produto foi vendido por compra em promoção, por mês e por filial
     * @return tabela em que se encontra a informação de quantas vezes um produto foi vendido por compra em promoção, por mês e por filial
     * */
    public int[][] getVezes_P();

    /**
     * Realiza o update da estrutura
     * @param cliente código de cliente
     * @param filial número da filial
     * @param mes número do mês
     * @param preco preço da venda
     * @param unidades unidades vendidas
     * @param NP código correspondente a vendas normais/promoção
     * */
    public void update_registo(String cliente, int filial, int mes, double preco, int unidades, char NP);

    /**
     * Metodo que devolve se um produto foi vendido num certo mês ou não
     * @param mes mês que se pretende verificar
     * @return se um produto foi vendido num certo mês ou não
     * */
    public boolean vendeu_mes(int mes);

    /**
     * Metodo que devolve quantos clientes distintos um produto foi comprado por
     * @return quantos clientes distintos um produto foi comprado por
     * */
    public int[] clientes_d();

    /**
     * Metodo que devolve a faturação de um produto num determinado mês, filial e tipo de compra
     * @param np tipo de compra
     * @param mes mês que se pretende verificar
     * @param filial filial que se pretende verificar
     * @return faturação de um produto num determinado mês, filial e tipo de compra
     * */
    public double total_faturado (int np, int mes, int filial);

    /**
     * Metodo que implementa um comparable para Produtos
     * @param p produto a comparar
     * */
    public int compareTo(Produto p);

    /**
     * Metodo que finaliza a estrutura produto, deve ser chamado depois do ultimo update
     * */
    public void finalizar_p();

    /**
     * Metodo que devolve uma lista de produtos correspondente aos X mais vendidos
     * @param X inteiro para o tamanho da lista
     * @return lista de produtos correspondente aos X mais vendidos
     * */
    public List<String> mais_compraram_s(int X);

    /**
     * Metodo que devolve uma lista de faturações correspondente aos X mais vendidos
     * @param X inteiro para o tamanho da lista
     * @return lista de faturações correspondente aos X mais vendidos
     * */
    public List<Double> mais_compraram_d(int X);

    /**
     * Metodo que devolve quantos clientes distintos um produto foi comprado por no total
     * @return quantos clientes distintos um produto foi comprado por no total
     * */
    public int clientes_distintos();

    /**
     * Metodo que devolve quantas unidades um produto vendeu, no total
     * @return quantas unidades um produto vendeu, no total
     * */
    public int quantas_vendeu();
}
