package Model;

import java.io.*;

public class Model implements GestVendasModel, Validacao {
    private ICatalogo_Clientes cat_clientes;
    private ICatalogo_Produtos cat_produtos;
    private IFilial filial;
    private IFaturacao faturacao;


    private final File root = new File(getClass().getProtectionDomain().getCodeSource().getLocation().getPath());
    private final File c_file = new File(root, "Files/Clientes.txt");
    private final File p_file = new File(root, "Files/Produtos.txt");
    private final File v_file_1M = new File(root,"Files/Vendas_1M.txt");
    private final File v_file_3M = new File(root,"Files/Vendas_3M.txt");
    private final File v_file_5M = new File(root,"Files/Vendas_5M.txt");

    private int registos_errados;
    private int total_produtos;
    private int produtos_comprados;
    private int total_clientes;
    private int clientes_compraram;
    private int compras_0;
    private double faturacao_total;

    public Model(){
        this.cat_clientes = new Catalogo_Clientes();
        this.cat_produtos = new Catalogo_Produtos();
        this.filial = new Filial();
        this.faturacao = new Faturacao();

        registos_errados = 0;
        total_produtos = 0;
        produtos_comprados = 0;
        total_clientes = 0;
        clientes_compraram = 0;
        compras_0 = 0;
        faturacao_total = 0;
    }

    public Model(Model m){
        cat_clientes = m.cat_clientes.clone();
        cat_produtos = m.cat_produtos.clone();
        filial = m.filial.clone();
        faturacao = m.faturacao.clone();

        registos_errados = m.registos_errados;
        total_produtos = m.total_produtos;
        produtos_comprados = m.produtos_comprados;
        total_clientes = m.total_clientes;
        clientes_compraram = m.clientes_compraram;
        compras_0 = m.compras_0;
        faturacao_total = m.faturacao_total;
    }

    public GestVendasModel clone(){
        return new Model(this);
    }

    public void clear(){
        this.cat_clientes = new Catalogo_Clientes();
        this.cat_produtos = new Catalogo_Produtos();
        this.faturacao = new Faturacao();
        this.filial = new Filial();
        System.gc();
    }

    private void startCC (File file) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader(file));
            String line = null;
            while ((line = br.readLine()) != null) {
                if (Validacao.validaCliente(line)) {
                    cat_clientes.add(line);
                    filial.addRC(line);
                    this.total_clientes++;
                }
            }

    }

    private void startCP (File file) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader(file));
            String line = null;
            while ((line = br.readLine()) != null) {
                if (Validacao.validaProduto(line)) {
                    cat_produtos.add(line);
                    filial.addRP(line);
                    this.total_produtos++;
                }
            }
    }


    private void startVendas (File file) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader(file));
            String line = null;
            while ((line = br.readLine()) != null) {
                if (validaVenda(line, cat_produtos, cat_clientes)) {
                    String[] part = line.split(" ");

                    if (Double.parseDouble(part[1]) == 0) {
                        this.compras_0++;
                    }

                    faturacao.update_faturacao(Integer.parseInt(part[6]), Integer.parseInt(part[5]), Double.parseDouble(part[1]), Integer.parseInt(part[2]));
                    filial.update_filial(part[0], part[4], Integer.parseInt(part[6]), Integer.parseInt(part[5]), Double.parseDouble(part[1]), Integer.parseInt(part[2]), part[3].charAt(0));
                } else {
                    this.registos_errados++;
                }
            }
            filial.finalizar();
    }

    private boolean validaVenda(String s, ICatalogo_Produtos cp, ICatalogo_Clientes cc){
        boolean v = false;
        String[] part = s.split(" ");

        if(cp.contains(part[0]))
            if (cc.contains(part[4]))
                if (Double.parseDouble(part[1]) >= 0)
                    if (Integer.parseInt(part[2]) > 0)
                        if (part[3].equals("N") || part[3].equals("P"))
                            if (Integer.parseInt(part[5]) >= 1 && Integer.parseInt(part[5]) <= 12)
                                if (Integer.parseInt(part[6]) >= 1 && Integer.parseInt(part[6]) <= 3) v = true;

        return v;
    }

    public void start(int i) throws IOException {
        this.startCC(c_file);
        this.startCP(p_file);
        if(i == 1)
            this.startVendas(v_file_1M);
        if(i == 3)
            this.startVendas(this.v_file_3M);
        if(i == 5)
            this.startVendas(this.v_file_5M);

        this.produtos_comprados = filial.getRP().produtos_comprados();
        this.clientes_compraram = filial.getRC().clientes_compraram();
        this.faturacao_total = faturacao.getTotal_faturado();
    }

    public Catalogo_Clientes getCat_clientes(){
        return this.cat_clientes.clone();
    }

    public Catalogo_Produtos getCat_produtos() {
        return cat_produtos.clone();
    }

    public IFilial getFilial() {
        return filial.clone();
    }

    public IFaturacao getFaturacao() {
        return faturacao.clone();
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("Estatisticas do ficheiro: ").append("Vendas").append("\n")
                .append("Número de clientes: ").append(total_clientes).append("\n")
                .append("Número de clientes que compraram: ").append(clientes_compraram).append("\n")
                .append("Número de clientes que não compraram: ").append(total_clientes-clientes_compraram).append("\n")
                .append("Número de produtos: ").append(total_produtos).append("\n")
                .append("Número de produtos que compraram: ").append(produtos_comprados).append("\n")
                .append("Número de produtos que não compraram: ").append(total_produtos-produtos_comprados).append("\n")
                .append("Número de registos de vendas errados: ").append(registos_errados).append("\n")
                .append("Número de compras de preço 0: ").append(compras_0).append("\n")
                .append("Faturação total: ").append(faturacao_total).append("\n");
        return sb.toString();
    }
}
