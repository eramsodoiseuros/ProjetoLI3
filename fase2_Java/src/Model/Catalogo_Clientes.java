package Model;

import java.util.*;

public class Catalogo_Clientes implements ICatalogo_Clientes{
    private Set<String> tabela_clientes;

    public Catalogo_Clientes() {
        this.tabela_clientes = new HashSet<String>();
    }

    public Catalogo_Clientes(Set<String> tabela_clientes) {
        this.tabela_clientes = tabela_clientes;
    }

    public Set<String> getTabela_clientes() {
        return new HashSet<String>(this.tabela_clientes);
    }

    public void setTabela_clientes(Set<String> tabela_clientes) {
        this.tabela_clientes.clear();
        this.tabela_clientes.addAll(tabela_clientes);
    }

    @Override
    public Catalogo_Clientes clone(){
        return new Catalogo_Clientes(this.tabela_clientes);
    }

    @Override
    public boolean equals(Object o){
        if(this == o) return true;
        if(o == null || this.getClass() != o.getClass()) return false;
        Catalogo_Clientes c  = (Catalogo_Clientes) o;
        return this.tabela_clientes.equals(c.tabela_clientes);
    }

    @Override
    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append("Catalogo de Clientes: \n").append(tabela_clientes).append("\n");
        return sb.toString();
    }

    public void add(String c){
        this.tabela_clientes.add(c);
    }

    public boolean contains(String c){
        return this.tabela_clientes.contains(c);
    }

    public int size(){
        return this.tabela_clientes.size();
    }
}
