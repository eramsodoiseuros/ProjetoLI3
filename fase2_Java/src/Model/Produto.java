package Model;

import java.util.*;
import java.util.stream.Collectors;

@SuppressWarnings({"unchecked"})
public class Produto implements IProduto{
    private final String id;
    private boolean vendido;

    private int unidades_compradas;
    private int[][] vezes_comprado_in;
    private double[][][] faturado_in;
    private int[][] vezes_N;
    private int[][] vezes_P;

    private Map[] cliente_unidades;
    private Map[] cliente_faturacao;
    private TreeMap<String, Double> sorted_cliente_faturacao;

    public Produto(String c) {
        this.id = c;
        this.vendido = false;
        this.vezes_comprado_in = new int[12][3];
        this.faturado_in = new double[12][3][2];
        this.vezes_N = new int[12][3];
        this.vezes_P = new int[12][3];
        this.cliente_unidades = new Map[12];
        this.cliente_faturacao = new Map[12];
        this.sorted_cliente_faturacao = new TreeMap<>();
        this.unidades_compradas = 0;

        for (int i = 0; i < 12; i++) {
            for(int j = 0; j < 3; j++){
                this.vezes_comprado_in[i][j] = 0;
            }
        }

        for (int i = 0; i < 12; i++) {
            for(int j = 0; j < 3; j++){
                for(int k = 0; k < 2; k++) {
                    this.faturado_in[i][j][k] = 0.0;
                }
            }
        }

        for (int i = 0; i < 12; i++) {
            for(int j = 0; j < 3; j++){
                this.vezes_N[i][j] = 0;
            }
        }

        for (int i = 0; i < 12; i++) {
            for(int j = 0; j < 3; j++){
                this.vezes_P[i][j] = 0;
            }
        }

        for (int i = 0; i < 12; i++) {
            this.cliente_faturacao[i] = new HashMap<String, Double>();
        }

        for (int i = 0; i < 12; i++) {
            this.cliente_unidades[i] = new HashMap<String, Integer>();
        }
    }

    public Produto(Produto p) {
        this.id = p.id;
        this.vendido = p.vendido;
        this.vezes_comprado_in = new int[12][3];
        this.faturado_in = new double[12][3][2];
        this.vezes_N = new int[12][3];
        this.vezes_P = new int[12][3];
        this.unidades_compradas = p.unidades_compradas;
        this.cliente_unidades = new Map[12];
        this.cliente_faturacao = new Map[12];
        this.sorted_cliente_faturacao = new TreeMap<>();
        this.sorted_cliente_faturacao.putAll(p.sorted_cliente_faturacao);

        for (int i = 0; i < 12; i++) {
            System.arraycopy(p.vezes_comprado_in[i], 0, this.vezes_comprado_in[i], 0, 3);
        }

        for (int i = 0; i < 12; i++) {
            for(int j = 0; j < 3; j++){
                System.arraycopy(p.faturado_in[i][j], 0, this.faturado_in[i][j], 0, 2);
            }
        }

        for (int i = 0; i < 12; i++) {
            System.arraycopy(p.vezes_N[i], 0, this.vezes_N[i], 0, 3);
        }

        for (int i = 0; i < 12; i++) {
            System.arraycopy(p.vezes_P[i], 0, this.vezes_P[i], 0, 3);
        }

        for (int i = 0; i < 12; i++) {
            this.cliente_unidades[i].putAll(p.cliente_unidades[i]);
        }

        for (int i = 0; i < 12; i++) {
            this.cliente_faturacao[i].putAll(p.cliente_faturacao[i]);
        }
    }

    @Override
    public Produto clone() throws CloneNotSupportedException {
        return new Produto(this);
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Produto produto = (Produto) o;
        return id.equals(produto.id);
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("ProdID:").append(id)
                .append("Foi vendido? ").append(vendido).append("\n");
        return sb.toString();
    }

    @Override
    public int compareTo(Produto p) {
        return ( p.quantas_vendeu()-this.unidades_compradas);
    }

    public String getId() {
        return id;
    }

    public boolean isVendido() {
        return vendido;
    }

    public int[][] getVezes_comprado() {
        return vezes_comprado_in;
    }

    public double[][][] getFaturado_in() {
        return faturado_in;
    }

    public int[][] getVezes_N() {
        return vezes_N;
    }

    public int[][] getVezes_P() {
        return vezes_P;
    }

    public void update_registo(String cliente, int filial, int mes, double preco, int unidades, char NP){
        int aux1 = 0;
        double aux2 = 0;
        double aux3 = 0;

        this.vendido = true;
        this.vezes_comprado_in[mes-1][filial-1]++;
        this.unidades_compradas += unidades;
        if(NP == 'N'){
            this.vezes_N[mes-1][filial-1]++;
            this.faturado_in[mes-1][filial-1][0] += unidades*preco;
        }

        if (NP == 'P'){
            this.vezes_P[mes-1][filial-1]++;
            this.faturado_in[mes-1][filial-1][1] += unidades*preco;
        }
        if(this.cliente_unidades[mes-1].containsKey(cliente)){
            aux1 = (int) this.cliente_unidades[mes-1].get(cliente);
            this.cliente_unidades[mes-1].replace(cliente, aux1+unidades);
            aux2 = (double) this.cliente_faturacao[mes-1].get(cliente);
            this.cliente_faturacao[mes-1].replace(cliente, aux2+(unidades*preco));
            aux3 = (double) this.sorted_cliente_faturacao.get(cliente);
            this.sorted_cliente_faturacao.replace(cliente, aux3+(unidades*preco));
        } else {
            this.cliente_unidades[mes-1].put(cliente, unidades);
            this.cliente_faturacao[mes-1].put(cliente, unidades*preco);
            this.sorted_cliente_faturacao.put(cliente,unidades*preco);
        }
    }
    
    public void finalizar_p(){
        for (Map.Entry<String,Double> entry : sorted_cliente_faturacao.entrySet()) {
            sorted_cliente_faturacao.entrySet().stream().sorted(Map.Entry.comparingByValue());
        }
    }

    public List<String> mais_compraram_s(int X){
        return sorted_cliente_faturacao.keySet().stream().limit(X).collect(Collectors.toList());
    }

    public List<Double> mais_compraram_d(int X){
        return sorted_cliente_faturacao.values().stream().limit(X).collect(Collectors.toList());
    }

    public boolean vendeu_mes(int mes){
        boolean idk = false;
        for(int i = 0; i < 3; i++){
            if(this.vezes_comprado_in[mes-1][i] != 0)
                return true;
        }
        return idk;
    }

    public int clientes_distintos(){
        HashMap<String, Integer> novo = new HashMap<String, Integer>();
        for(Map<String, Integer> cur : this.cliente_unidades)
            cur.forEach((key, value) -> {
                novo.compute(key, (k,v)->{
                    return (v==null) ? value : v + value;
                });
            });
        return novo.size();
    }

    public int[] clientes_d(){
        int[] r = new int[12];
                for(int i = 0; i < 12; i++){
                    r[i] = cliente_unidades[i].size();
                }
        return r;
    }

    public int quantas_vendeu(){
        return unidades_compradas;
    }

    public double total_faturado (int np, int mes, int filial){
        return this.faturado_in[mes][filial][np];
    }
}
