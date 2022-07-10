package Model;

import java.io.Serializable;
import java.util.*;
import java.util.stream.Collectors;

public class Registo_Clientes implements Serializable {
    private HashMap<String, Cliente> tabela_clientes;
    private List[] sorted_mais_faturado;
    private List<Cliente> sorted_produtos_distintos;

    public Registo_Clientes() {
        this.tabela_clientes = new HashMap<String, Cliente>();
        this.sorted_mais_faturado = new List[3];
        this.sorted_produtos_distintos = new ArrayList<>();

        for(int i = 0; i < 3; i++){
            sorted_mais_faturado[i] = new ArrayList<Cliente>();
        }
    }

    public Registo_Clientes(Registo_Clientes rc) {
        this.tabela_clientes = new HashMap<String, Cliente>();
        this.sorted_mais_faturado = new List[3];
        this.sorted_produtos_distintos = new ArrayList<>();

        this.tabela_clientes.putAll(rc.tabela_clientes);
        for (int i = 0; i < 3; i++){
            this.sorted_mais_faturado[i].addAll(rc.sorted_mais_faturado[i]);
        }
        this.sorted_produtos_distintos.addAll(rc.sorted_produtos_distintos);
    }

    public HashMap<String, Cliente> getTabela_clientes() {
        return tabela_clientes;
    }

    public void add(String c){
        Cliente c1 = new Cliente(c);
        this.tabela_clientes.putIfAbsent(c,c1);
    }

    public void finalizar_RC(){
        for (Map.Entry<String,Cliente> entry : tabela_clientes.entrySet()) {
            for(int i = 0; i < 3; i++){
                sorted_mais_faturado[i].add(entry.getValue());
            }
            sorted_mais_faturado[0].sort(new Comparator<Cliente>() {
                @Override
                public int compare(Cliente c1, Cliente c2) {
                    return (int) (c2.quanto_faturou(0) - c1.quanto_faturou(0));
                }
            });
            sorted_mais_faturado[1].sort(new Comparator<Cliente>() {
                @Override
                public int compare(Cliente c1, Cliente c2) {
                    return (int) (c2.quanto_faturou(1) - c1.quanto_faturou(1));
                }
            });
            sorted_mais_faturado[2].sort(new Comparator<Cliente>() {
                @Override
                public int compare(Cliente c1, Cliente c2) {
                    return (int) (c2.quanto_faturou(2) - c1.quanto_faturou(2));
                }
            });
            sorted_produtos_distintos.add(entry.getValue());
        }
        sorted_produtos_distintos.sort(Comparator.naturalOrder());
    }

    public List<Cliente> mais_produtos_comprados(int X){
        return sorted_produtos_distintos.stream().limit(X).collect(Collectors.toList());
    }

    public List<Cliente> maiores_compradores(int X, int i){
        return (List<Cliente>) sorted_mais_faturado[i].stream().limit(X).collect(Collectors.toList());
    }

    public int produtos_distintos_mes(int mes){
        int r = 0;
        for (Map.Entry<String,Cliente> entry : tabela_clientes.entrySet()) {
            if(entry.getValue().comprou_mes(mes)){
                r++;
            }
        }
        return r;
    }

    public int produtos_distintos_fm(int mes, int filial){
        int r = 0;
        for (Map.Entry<String,Cliente> entry : tabela_clientes.entrySet()) {
            if(entry.getValue().comprou_fm(mes, filial)){
                r++;
            }
        }
        return r;
    }

    public int clientes_compraram(){
        int r = 0;
        for (Map.Entry<String,Cliente> entry : tabela_clientes.entrySet()) {
            if(entry.getValue().isComprou()){
                r++;
            }
        }
        return r;
    }

}
