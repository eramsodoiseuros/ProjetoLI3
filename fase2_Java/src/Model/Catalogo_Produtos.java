package Model;

import java.util.*;

public class Catalogo_Produtos implements ICatalogo_Produtos{
    private Set<String> tabela_produtos;

    public Catalogo_Produtos() {
        this.tabela_produtos = new HashSet<String>();
    }

    public Catalogo_Produtos(Set<String> tabela_produtos) {
        this.tabela_produtos = tabela_produtos;
    }

    public Set<String> getTabela_Produtos() {
        return new HashSet<String>(this.tabela_produtos);
    }

    public void setTabela_produtos(Set<String> tabela_produtos) {
        this.tabela_produtos.clear();
        this.tabela_produtos.addAll(tabela_produtos);
    }

    @Override
    public Catalogo_Produtos clone(){
        return new Catalogo_Produtos(this.tabela_produtos);
    }

    @Override
    public boolean equals(Object o){
        if(this == o) return true;
        if(o == null || this.getClass() != o.getClass()) return false;
        Catalogo_Produtos c  = (Catalogo_Produtos) o;     
        return this.tabela_produtos.equals(c.tabela_produtos);
    }

    @Override
    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append("Catalogo de Produtos: \n").append(tabela_produtos).append("\n");
        return sb.toString();
    }

    public void add(String c){
        this.tabela_produtos.add(c);
    }

    public boolean contains(String c){
        return this.tabela_produtos.contains(c);
    }

    public int size(){
        return this.tabela_produtos.size();
    }
}
