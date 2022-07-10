package Model;

import java.io.Serializable;
import java.util.*;
import java.util.stream.Collectors;

public class Registo_Produtos implements Serializable {
    private HashMap<String, Produto> tabela_produtos;
    private TreeSet<Produto> sorted_mais_comprados;

    public Registo_Produtos() {
        this.tabela_produtos = new HashMap<>();
        this.sorted_mais_comprados = new TreeSet<>();
    }

    public Registo_Produtos(Registo_Produtos rp) {
        this.tabela_produtos = new HashMap<>();
        this.sorted_mais_comprados = new TreeSet<>();

        this.tabela_produtos.putAll(rp.tabela_produtos);
        this.sorted_mais_comprados.addAll(rp.sorted_mais_comprados);
    }

    public HashMap<String,  Produto> getTabela_produtos() {
        return tabela_produtos;
    }

    @Override
    public Registo_Produtos clone(){
        return new Registo_Produtos(this);
    }

    @Override
    public String toString() {
        return "Model.Registo_Produtos{" +
                "tabela_produtos=" + tabela_produtos +
                '}';
    }

    public void add(String p){
        Produto p1 = new Produto(p);
        this.tabela_produtos.put(p,p1);
    }

    public void finalizar_RP(){
        sorted_mais_comprados.addAll(this.tabela_produtos.values());
        for (Map.Entry<String,Produto> entry : tabela_produtos.entrySet()){
            entry.getValue().finalizar_p();
        }
    }

    public List<Produto> letra(char letra){
        return this.tabela_produtos.values().stream().filter(s -> s.getId().charAt(0) == letra).sorted().collect(Collectors.toList());
    }

    public List<Produto> x_mais_vendidos(int X){
        return sorted_mais_comprados.stream().limit(X).collect(Collectors.toList());
    }

    public List<Integer> quantidades(List<Produto> produtos){
        List<Integer> lista = new ArrayList<>();
        for (Produto p: produtos) {
            lista.add(p.quantas_vendeu());
        }
        return lista;
    }

    public List<Integer> clientes_distintos(List<Produto> produtos){
        List<Integer> lista = new ArrayList<>();
        for (Produto p: produtos) {
            lista.add(p.clientes_distintos());
        }
        return lista;
    }

    public List<String> x_mais_compraram_s(String p, int X){
        return tabela_produtos.get(p).mais_compraram_s(X);
    }

    public List<Double> x_mais_compraram_d(String p, int X){
        return tabela_produtos.get(p).mais_compraram_d(X);
    }

    public Map<String, Double[][]> mapa_faturacao_produto(){
        Map<String, Double[][]> r = new TreeMap<>();
        Double[][] d = new Double[12][3];
        for (Map.Entry<String,Produto> entry : tabela_produtos.entrySet()) {
            for(int m = 0; m < 12; m++){
                for(int f = 0; f < 3; f++){
                    d[m][f] = entry.getValue().getFaturado_in()[m][f][0]+entry.getValue().getFaturado_in()[m][f][1];
                }
            }
            r.put(entry.getKey(), d);
        }
        return r;
    }

    public int produtos_comprados(){
        int r = 0;
        for (Map.Entry<String,Produto> entry : tabela_produtos.entrySet()) {
            if(entry.getValue().isVendido()){
                r++;
            }
        }
        return r;
    }

}
