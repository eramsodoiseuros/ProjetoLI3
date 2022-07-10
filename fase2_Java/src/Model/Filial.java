package Model;

public class Filial implements IFilial {
    private Registo_Clientes RC;
    private Registo_Produtos RP;

    public Filial() {
        this.RC = new Registo_Clientes();
        this.RP = new Registo_Produtos();
    }

    public Filial(Registo_Clientes RC, Registo_Produtos RP){
        this.RC = new Registo_Clientes();
        this.RP = new Registo_Produtos();

        this.RC = RC;
        this.RP = RP;
    }

    public Filial(Filial f){
        this.RC = new Registo_Clientes();
        this.RP = new Registo_Produtos();

        this.RC = f.RC;
        this.RP = f.RP;
    }

    public void addRC(String c){
        this.RC.add(c);
    }

    public void addRP(String p){
        this.RP.add(p);
    }

    public Filial clone(){
        return new Filial(this);
    }
     
    public Registo_Clientes getRC(){
        return this.RC;
    }

    public Registo_Produtos getRP(){
        return this.RP.clone();
    }

    public void update_filial(String produto, String cliente, int filial, int mes, double preco, int unidades, char NP){
        this.RC.getTabela_clientes().get(cliente).update_registo(produto, filial, mes, preco, unidades, NP);
        this.RP.getTabela_produtos().get(produto).update_registo(cliente, filial, mes, preco, unidades, NP);
    }

    public void finalizar(){
        this.RC.finalizar_RC();
        this.RP.finalizar_RP();
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("Estrutura Model.Filial:\n")
                .append(RC.toString()).append("\n")
                .append(RP.toString()).append("\n");
        return sb.toString();
    }
}
