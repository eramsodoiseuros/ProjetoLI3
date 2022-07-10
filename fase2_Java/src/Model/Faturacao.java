package Model;

import java.util.*;
import java.text.DecimalFormat;

public class Faturacao implements IFaturacao{
    private double[][] tabela_faturacao;
    private int[][] tabela_vendas;
    private double total_faturado;

    public Faturacao() {
        this.tabela_faturacao = new double[12][4];
        this.tabela_vendas = new int[12][3];
        this.total_faturado = 0;

        for (int i = 0; i < 12; i++) {
            for(int j = 0; j < 4; j++){
                this.tabela_faturacao[i][j] =0;
            }
        }

        for (int i = 0; i < 12; i++) {
            for(int j = 0; j < 3; j++){
                this.tabela_vendas[i][j] = 0;
            }
        }
    }

    public Faturacao(Faturacao f) {

        this.tabela_faturacao = new double[12][4];
        this.tabela_vendas = new int[12][3];
        for (int i = 0; i < 12; i++) {
            System.arraycopy(f.tabela_faturacao[i], 0, this.tabela_faturacao[i], 0, 4);
        }

        for (int i = 0; i < 12; i++) {
            System.arraycopy(f.tabela_vendas[i], 0, this.tabela_vendas[i], 0, 3);
        }

        this.total_faturado = f.total_faturado;
    }

    public Faturacao clone(){
        return new Faturacao(this);
    }

    public boolean equals(Object o){
        if(this == o) return true;
        if(o == null || this.getClass() != o.getClass()) return false;
        Faturacao f  = (Faturacao) o;     
        return this.total_faturado == f.getTotal_faturado()
                && Arrays.deepEquals(this.tabela_vendas, f.getTabela_vendas())
                && Arrays.deepEquals(this.tabela_faturacao, f.getTabela_faturacao());
    }

    public String toString(){

        DecimalFormat df = new DecimalFormat("#.##");

        StringBuilder s = new StringBuilder();
        s.append("Total global faturado:").append(total_faturado).append("\n");
        s.append("Faturação em Janeiro: ").append("Model.Filial 1 -> ").append(df.format(tabela_faturacao[0][0])).append(". Model.Filial 2 -> ").append(df.format(tabela_faturacao[0][1])).append(". Model.Filial 3 -> ").append(df.format(tabela_faturacao[0][2])).append("\n");
        s.append("Faturação em Fevereiro: ").append("Model.Filial 1 -> ").append(df.format(tabela_faturacao[1][0])).append(". Model.Filial 2 -> ").append(df.format(tabela_faturacao[1][1])).append(". Model.Filial 3 -> ").append(df.format(tabela_faturacao[1][2])).append("\n");
        s.append("Faturação em Março: ").append("Model.Filial 1 -> ").append(df.format(tabela_faturacao[2][0])).append(". Model.Filial 2 -> ").append(df.format(tabela_faturacao[2][1])).append(". Model.Filial 3 -> ").append(df.format(tabela_faturacao[2][2])).append("\n");
        s.append("Faturação em Abril: ").append("Model.Filial 1 -> ").append(df.format(tabela_faturacao[3][0])).append(". Model.Filial 2 -> ").append(df.format(tabela_faturacao[3][1])).append(". Model.Filial 3 -> ").append(df.format(tabela_faturacao[3][2])).append("\n");
        s.append("Faturação em Maio: ").append("Model.Filial 1 -> ").append(df.format(tabela_faturacao[4][0])).append(". Model.Filial 2 -> ").append(df.format(tabela_faturacao[4][1])).append(". Model.Filial 3 -> ").append(df.format(tabela_faturacao[4][2])).append("\n");
        s.append("Faturação em Junho: ").append("Model.Filial 1 -> ").append(df.format(tabela_faturacao[5][0])).append(". Model.Filial 2 -> ").append(df.format(tabela_faturacao[5][1])).append(". Model.Filial 3 -> ").append(df.format(tabela_faturacao[5][2])).append("\n");
        s.append("Faturação em Julho: ").append("Model.Filial 1 -> ").append(df.format(tabela_faturacao[6][0])).append(". Model.Filial 2 -> ").append(df.format(tabela_faturacao[6][1])).append(". Model.Filial 3 -> ").append(df.format(tabela_faturacao[6][2])).append("\n");
        s.append("Faturação em Agosto: ").append("Model.Filial 1 -> ").append(df.format(tabela_faturacao[7][0])).append(". Model.Filial 2 -> ").append(df.format(tabela_faturacao[7][1])).append(". Model.Filial 3 -> ").append(df.format(tabela_faturacao[7][2])).append("\n");
        s.append("Faturação em Setembro: ").append("Model.Filial 1 -> ").append(df.format(tabela_faturacao[8][0])).append(". Model.Filial 2 -> ").append(df.format(tabela_faturacao[8][1])).append(". Model.Filial 3 -> ").append(df.format(tabela_faturacao[8][2])).append("\n");
        s.append("Faturação em Outubro: ").append("Model.Filial 1 -> ").append(df.format(tabela_faturacao[9][0])).append(". Model.Filial 2 -> ").append(df.format(tabela_faturacao[9][1])).append(". Model.Filial 3 -> ").append(df.format(tabela_faturacao[9][2])).append("\n");
        s.append("Faturação em Novembro: ").append("Model.Filial 1 -> ").append(df.format(tabela_faturacao[10][0])).append(". Model.Filial 2 -> ").append(df.format(tabela_faturacao[10][1])).append(". Model.Filial 3 -> ").append(df.format(tabela_faturacao[10][2])).append("\n");
        s.append("Faturação em Dezembro: ").append("Model.Filial 1 -> ").append(df.format(tabela_faturacao[11][0])).append(". Model.Filial 2 -> ").append(df.format(tabela_faturacao[11][1])).append(". Model.Filial 3 -> ").append(df.format(tabela_faturacao[11][2])).append("\n");
        s.append("\n");
        s.append("Número de Vendas em Janeiro: ").append(tabela_vendas[0][0]+tabela_vendas[0][1]+tabela_vendas[0][2]).append("\n");
        s.append("Número de Vendas em Fevereiro: ").append(tabela_vendas[1][0]+tabela_vendas[1][1]+tabela_vendas[1][2]).append("\n");
        s.append("Número de Vendas em Março: ").append(tabela_vendas[2][0]+tabela_vendas[2][1]+tabela_vendas[2][2]).append("\n");
        s.append("Número de Vendas em Abril: ").append(tabela_vendas[3][0]+tabela_vendas[3][1]+tabela_vendas[3][2]).append("\n");
        s.append("Número de Vendas em Maio: ").append(tabela_vendas[4][0]+tabela_vendas[4][1]+tabela_vendas[4][2]).append("\n");
        s.append("Número de Vendas em Junho: ").append(tabela_vendas[5][0]+tabela_vendas[5][1]+tabela_vendas[5][2]).append("\n");
        s.append("Número de Vendas em Julho: ").append(tabela_vendas[6][0]+tabela_vendas[6][1]+tabela_vendas[6][2]).append("\n");
        s.append("Número de Vendas em Agosto: ").append(tabela_vendas[7][0]+tabela_vendas[7][1]+tabela_vendas[7][2]).append("\n");
        s.append("Número de Vendas em Setembro: ").append(tabela_vendas[8][0]+tabela_vendas[8][1]+tabela_vendas[8][2]).append("\n");
        s.append("Número de Vendas em Outubro: ").append(tabela_vendas[9][0]+tabela_vendas[9][1]+tabela_vendas[9][2]).append("\n");
        s.append("Número de Vendas em Novembro: ").append(tabela_vendas[10][0]+tabela_vendas[10][1]+tabela_vendas[10][2]).append("\n");
        s.append("Número de Vendas em Dezembro: ").append(tabela_vendas[11][0]+tabela_vendas[11][1]+tabela_vendas[11][2]).append("\n");
        s.append("\n");
        return s.toString();
    }

    public double[][] getTabela_faturacao() {
        return tabela_faturacao;
    }

    public int[][] getTabela_vendas() {
        return tabela_vendas;
    }

    public double getTotal_faturado() {
        return total_faturado;
    }

    public void update_faturacao(int filial, int mes, double preco, int unidades){
        this.tabela_faturacao[mes-1][3] += preco*unidades;
        this.tabela_faturacao[mes-1][filial-1] += preco*unidades;
        this.tabela_vendas[mes-1][filial-1]++;
        this.total_faturado += preco*unidades;
    }
}
