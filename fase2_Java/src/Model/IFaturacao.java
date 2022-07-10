package Model;

import java.io.Serializable;

public interface IFaturacao extends Serializable{

    /**
     * Duplica uma Estrutura Faturação
     * */
    public Faturacao clone();

    /**
     * Verifica se um catalogo é igual a um outro objeto
     * @param o Objecto
     * @return se um catalogo é igual a um outro objeto
     * */
    public boolean equals(Object o);

    /**
     * Metodo que converte a informação da classe em String
     * @return informação da estrutura
     * */
    public String toString();

    /**
     * Metodo que devolve uma tabela com as respetivas faturações por mês e filial
     * @return tabela com as respetivas faturações por mês e filial
     * */
    public double[][] getTabela_faturacao();

    /**
     * Metodo que devolve uma tabela com as respetivas vendas por mês e filial
     * @return tabela com as respetivas vendas por mês e filial
     * */
    public int[][] getTabela_vendas();

    /**
     * Metodo que devolve o total faturado
     * @return total faturado
     * */
    public double getTotal_faturado();

    /**
     * Realiza o update da estrutura
     * @param filial número da filial
     * @param mes número do mês
     * @param preco preço da venda
     * @param unidades unidades vendidas
     * */
    public void update_faturacao(int filial, int mes, double preco, int unidades);
}
