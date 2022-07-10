package Model;

import java.util.*;

@SuppressWarnings("unchecked")
public class Cliente implements ICliente {
    private String id;
    private boolean comprou;

    private double[] faturacao;
    private int[][] volume_compras;
    private double[][] despeza_compras;

    private Map[] produto_unidades;
    private Map[] produto_faturacao;


    public Cliente(String c) {
        this.id = c;
        this.comprou = false;
        this.produto_unidades = new Map[12];
        this.produto_faturacao = new Map[12];
        this.despeza_compras = new double[12][3];
        this.volume_compras = new int[12][3];
        this.faturacao = new double[3];

        for (int i = 0; i < 12; i++) {
            this.produto_faturacao[i] = new HashMap<String, Double>();
        }

        for (int i = 0; i < 12; i++) {
            this.produto_unidades[i] = new HashMap<String, Integer>();
        }

        for (int i = 0; i < 12; i++) {
            for(int j = 0; j < 3; j++){
                this.volume_compras[i][j] = 0;
            }
        }

        for (int i = 0; i < 12; i++) {
            for(int j = 0; j < 3; j++){
                this.despeza_compras[i][j] = 0.0;
            }
        }

        for(int j = 0; j < 3; j++){
            this.faturacao[j] = 0;
        }
    }

    public Cliente(Cliente c) {
        this.produto_unidades = new Map[12];
        this.produto_faturacao = new Map[12];
        this.despeza_compras = new double[12][3];
        this.volume_compras = new int[12][3];
        this.faturacao = new double[3];

        this.id = c.id;
        this.comprou = c.comprou;
        this.produto_unidades = c.produto_unidades;
        this.produto_faturacao = c.produto_faturacao;

        System.arraycopy(c.faturacao, 0, this.faturacao, 0, 3);

        for (int i = 0; i < 12; i++) {
            System.arraycopy(c.volume_compras[i], 0, this.volume_compras[i], 0, 3);
        }

        for (int i = 0; i < 12; i++) {
            System.arraycopy(c.despeza_compras[i], 0, this.despeza_compras[i], 0, 3);
        }

        for (int i = 0; i < 12; i++) {
            this.produto_unidades[i].putAll(c.produto_unidades[i]);
        }

        for (int i = 0; i < 12; i++) {
            this.produto_faturacao[i].putAll(c.produto_faturacao[i]);
        }
    }

    @Override
    public Cliente clone(){
        return new Cliente(this);
    }

    @Override
    public boolean equals(Object o){ 
        if (o == this)return true;
        if (o == null || this.getClass() != o.getClass()) return false;
        Cliente c = (Cliente) o;        
        return this.id.equals(c.getId());
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("ClientID:").append(id)
                .append("Comprou? ").append(comprou).append("\n");
        return sb.toString();
    }

    public int compareTo(Cliente c) {
        return (int)(c.produtos_distintos() - this.produtos_distintos());
    }

    public int sort_by_faturado_1(Cliente c){
        return (int) (c.quanto_faturou(0)-this.faturacao[0]);
    }
    public int sort_by_faturado_2(Cliente c){
        return (int) (c.quanto_faturou(1)-this.faturacao[1]);
    }
    public int sort_by_faturado_3(Cliente c){
        return (int) (c.quanto_faturou(3)-this.faturacao[2]);
    }

    public String getId() {
        return id;
    }

    public boolean isComprou() {
        return comprou;
    }

    public int[][] getVolume_compras() {
        return volume_compras;
    }

    public double[][] getDespeza_compras() {
        return despeza_compras;
    }

    public void update_registo(String produto, int filial, int mes, double preco, int unidades, char NP){
        int aux1 = 0;
        double aux2 = 0;

        this.comprou = true;
        this.volume_compras[mes-1][filial-1]++;
        this.despeza_compras[mes-1][filial-1] += unidades*preco;
        if(this.produto_unidades[mes-1].containsKey(produto)){
            aux1 = (int) this.produto_unidades[mes-1].get(produto);
            this.produto_unidades[mes-1].replace(produto, aux1+unidades);
            aux2 = (double) this.produto_faturacao[mes-1].get(produto);
            this.produto_faturacao[mes-1].replace(produto, aux2+(unidades*preco));
        } else {
            this.produto_unidades[mes-1].put(produto, unidades);
            this.produto_faturacao[mes-1].put(produto, unidades*preco);
        }
        this.faturacao[filial-1] += unidades*preco;
    }

    public double quanto_faturou(int i){
        return this.faturacao[i];
    }

    public int produtos_distintos(){
        HashMap<String, Integer> novo = new HashMap<String, Integer>();
        for(Map<String, Integer> cur : this.produto_unidades)
            cur.forEach((key, value) -> {
                novo.compute(key, (k,v)->{
                    return (v==null) ? value : v + value;
                });
            });
        return novo.size();
    }

    public int[] produtos_d(){
        int[] r = new int[12];
        for(int i = 0; i < 12; i++){
            r[i] = produto_unidades[i].size();
        }
        return r;
    }

    public static <K, V extends Comparable<? super V>> Map<K, V> sortByValue(Map<K, V> map) {
        List<Map.Entry<K, V>> list = new ArrayList<>(map.entrySet());
        list.sort(Map.Entry.comparingByValue(Comparator.reverseOrder()));

        Map<K, V> result = new LinkedHashMap<>();
        for (Map.Entry<K, V> entry : list) {
            result.put(entry.getKey(), entry.getValue());
        }
        return result;
    }

    public Map<String, Integer> getProdutos_Unidades(){
        HashMap<String, Integer> novo = new HashMap<String, Integer>();
        for(Map<String, Integer> cur : this.produto_unidades)
            cur.forEach((key, value) -> {
                novo.compute(key, (k,v)->{
                    return (v==null) ? value : v + value;
                });
            });
        return sortByValue(novo);
    }

    public boolean comprou_mes(int mes){
        boolean idk = false;
        for(int i = 0; i < 3; i++){
            if(this.volume_compras[mes-1][i] != 0)
                return true;
        }
        return idk;
    }

    public boolean comprou_fm(int mes, int filial){
        return this.volume_compras[mes - 1][filial-1] != 0;
    }

}
