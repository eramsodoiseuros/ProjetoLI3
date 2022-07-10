package Model;

import java.io.*;

/**
 * Interface do Model
 * */
public interface GestVendasModel extends Serializable {
    /**
     * Metodo que realiza a leitura dos dados e preenche o Model
     * @param i inteiro que representa o ficheiro de vendas
     * */
    public void start(int i) throws IOException;

    /**
     * Metodo que devolve o Catalogo de Clientes
     * @return estrutura Catalogo de Clientes
     * */
    public Catalogo_Clientes getCat_clientes();

    /**
     * Metodo que devolve o Catalogo de Produtos
     * @return estrutura Catalogo de Produtos
     * */
    public Catalogo_Produtos getCat_produtos();

    /**
     * Metodo que devolve uma Estrutura Model.Filial
     * @return estrutura Filial
     * */
    public IFilial getFilial();

    /**
     * Metodo que devolve uma Estrutura Faturação
     * @return estrutura Faturação
     * */
    public IFaturacao getFaturacao();

    /**
     * Metodo que limpa a estrutura
     * */
    public void clear();
}
