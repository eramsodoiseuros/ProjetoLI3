package View;

import java.util.*;
public interface GestVendasView {
    /**
     * Faz print de um Object, que terá obrigatóriamente de ter um metodo toString)
     * @param o Objeto
     * */
    public void print(Object o);

    /**
     * Permite navegar por uma estrutura, segmentando-a em paginas e permitindo ao utilizador página a página.
     * Recebe também um titulo, header, a ser colocado no topo de cada pagina.
     * @param header String a ser colocada no topo de cada pagina
     * @param lista Lista de Strings
     * */
    public void navegadorS(String header, List<String> lista);

    /**
     * Permite navegar por uma estrutura, segmentando-a em paginas e permitindo ao utilizador página a página.
     * Recebe também um titulo, header, a ser colocado no topo de cada pagina.
     * @param header String a ser colocada no topo de cada pagina
     * @param vendidos Lista de Strings
     * @param lista Lista de inteiros
     * @param clientes Lista de inteiros
     * */
    public void navegadorI (String header, List<String> vendidos, List<Integer> lista, List<Integer> clientes);

    /**
     * Permite navegar por uma estrutura, segmentando-a em paginas e permitindo ao utilizador página a página.
     * Recebe também um titulo, header, a ser colocado no topo de cada pagina.
     * @param header String a ser colocada no topo de cada pagina
     * @param lista Lista de Strings
     * @param vendidos Lista de Doubles
     * */
    public void navegador7 (String header, List<String> lista, List<Double> vendidos);

    /**
     * Permite navegar por uma estrutura, segmentando-a em paginas e permitindo ao utilizador página a página.
     * Recebe também um titulo, header, a ser colocado no topo de cada pagina.
     * @param header String a ser colocada no topo de cada pagina
     * @param lista Lista de Strings
     * @param vendidos Lista de inteiros
     * */
    public void navegador8 (String header, List<String> lista, List<Integer> vendidos);

    /**
     * Permite navegar por uma estrutura, segmentando-a em paginas e permitindo ao utilizador página a página.
     * Recebe também um titulo, header, a ser colocado no topo de cada pagina.
     * @param header String a ser colocada no topo de cada pagina
     * @param lista Lista de Strings
     * @param vendidos Lista de Doubles
     * */
    public void navegador9(String header, List<String> lista, List<Double> vendidos);

    /**
     * Permite navegar por uma estrutura, segmentando-a em paginas e permitindo ao utilizador página a página.
     * Recebe também um titulo, header, a ser colocado no topo de cada pagina.
     * @param header String a ser colocada no topo de cada pagina
     * @param map Mapa para imprimir
     * */
    public void navegadorMap (String header, Map<String,Double[][]> map);

    /**
     * Imprime o menu incial no ecra
     * */
    public void printMenu();

    /**
     * Imprime o menu da estatistica
     * */
    public void printMenuEstat();

    /**
     * Imprime o menu de queries no ecra
     * */
    public void printQueries();

    /**
     * Imprime a query 2 no ecra
     * @param q
     * @param f
     * */
    public void printquery2(int[][] q, int f);

    /**
     * Imprime a query 3 no ecra, dependendo de um mês
     * @param q1
     * @param q2
     * @param q3
     * @param m
     * */
    public void printquery3(int[] q1, int[] q2, double[] q3, int m);

    /**
     * Imprime a query 3 no ecra
     * @param q1
     * @param q2
     * @param q3
     * */
    public void printquery3(int[] q1, int[] q2, double[] q3);

    /**
     * Imprime a query 4 no ecra, dependendo de um mês
     * @param q1
     * @param q2
     * @param q3
     * @param m
     * */
    public void printquery4(int[] q1, int[] q2, double[] q3, int m);

    /**
     * Imprime a query 4 no ecra
     * @param q1
     * @param q2
     * @param q3
     * */
    public void printquery4(int[] q1, int[] q2, double[] q3);

}
