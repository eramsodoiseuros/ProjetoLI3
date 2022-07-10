package Controller;


import Model.*;
import View.*;

import java.io.*;
import java.util.*;
import java.util.stream.*;

public class Controler implements GestVendasControler {

    // FAZER FILE CONFIG PROPERTIES - ?

    private boolean estado;
    private GestVendasModel model;
    private GestVendasView view;
    private Input input;

    public Controler(){
        this.estado = false;
        this.input = new Input();
        this.view = new View();
        this.model = new Model();
    }

    public void setModel(GestVendasModel m){
        this.model = m;
    }

    public void setView(GestVendasView v){
        this.view = v;
    }

    public void isEstado() throws NoDataException{
        if(!this.estado){
            throw new NoDataException();
        }

    }

    ///////////////////////////////////////////////////////////////////////////////////////
    // salva dados
    public void salvar_dados() throws IOException, NoDataException {
        isEstado();
        this.view.print("Escolha um file path (Enter para default): ");
        String path = input.lerString();
        ObjectOutputStream oos = null;
        Crono.start();
        if(path.length() == 0) {
            oos = new ObjectOutputStream(new FileOutputStream("gestVendas.dat"));
        }
        else{
            oos = new ObjectOutputStream(new FileOutputStream(path));
        }
        oos.writeObject(this.model);
        oos.flush();
        double tempo = Crono.stop();
        this.view.print("Tempo de execução: " + tempo);
    }

    // dá load de dados
    public void load_dados() throws IOException,ClassNotFoundException{
        if(this.estado){
            this.model.clear();
        }
        this.view.print("Escolha um file path (Enter para default): ");
        String path = input.lerString();
        Crono.start();
        ObjectInputStream ois = null;
        if(path.length()==0) {
            ois = new ObjectInputStream(new FileInputStream("gestVendas.dat"));
        }
        else {
            ois = new ObjectInputStream(new FileInputStream(path));
        }
        this.model = (GestVendasModel) ois.readObject();
        double tempo = Crono.stop();
        this.view.print("Tempo de execução: " + tempo);
    }

    // NOT DONE
    private void ler_dados(){
        this.view.print("Escolha um file 1 - [Vendas 1] 3 - [Vendas 3] 5 - [Vendas 5] : ");
        int i = input.lerInt();
        try{
            Crono.start();
            this.model.start(i);

            double temp = Crono.stop();
            this.estado = true;
            this.view.print("Dados iniciados com sucesso!");
            this.view.print("Tempo de execução: " + temp);
        }
        catch (Exception e){
            this.view.print(e);
        }
    }
    /////////////////////////////////////////////////////////////////////////////////////////////

    public void menu(){

        int r = 1, i = 1;
        this.view.printMenu();

        while(i != 0){
            i = input.lerInt();
            switch (i){
                case 1:
                    model.clear();
                    ler_dados();
                    break;
                case 2:
                    try {
                        load_dados();
                    } catch (IOException | ClassNotFoundException e) {
                        e.printStackTrace();
                    }
                    break;
                case 3:
                    try {
                        salvar_dados();
                    } catch (NoDataException | IOException noData) {
                        view.print(noData.toString());
                        break;
                    }
                    break;
                case 4:
                    try {
                        isEstado();
                    } catch (NoDataException e) {
                        view.print(e.toString());
                        break;
                    }
                    while (r!=0) {
                        this.view.printMenuEstat();
                        r = input.lerInt();
                        menuEstat(r);
                    }
                    menu();
                    break;
                case 5:
                    try {
                        isEstado();
                    } catch (NoDataException e) {
                        view.print(e.toString());
                        break;
                    }
                    while(r != 0){
                        this.view.printQueries();
                        r = input.lerInt();
                        menuQueries(r);
                    }
                    menu();
                    break;
            }
        }
        this.model.clear();
    }

    public void menuEstat(int r){
        int m = 0;
        double t = 0;
            switch (r) {
                case 1:
                    this.view.print(model.toString());
                    break;
                case 2:
                    this.view.print("Insira um mês:");
                    m = input.lerInt();
                    if(scanMes(m)){
                        Crono.start();
                        this.view.print(numero_compras_mes(m));
                        t = Crono.stop();
                        view.print(Crono.toString(t));
                    }else menuEstat(1);
                    break;
                case 3:
                    this.view.print("Insira um mês:");
                    m = input.lerInt();
                    if(scanMes(m)){
                        Crono.start();
                        this.view.print(faturacao_mes(m));
                        t = Crono.stop();
                        view.print(Crono.toString(t));
                    }else menuEstat(2);
                    break;
                case 4:
                    this.view.print("Insira um mês:");
                    m = input.lerInt();
                    if(scanMes(m)){
                        Crono.start();
                        this.view.print(clientes_distintos_mes(m));
                        t = Crono.stop();
                        view.print(Crono.toString(t));
                    }else menuEstat(3);
                    break;

            }

    }

    public void menuQueries(int r){
        char letra;
        int m ,f;
        String cod;
        List<String> s = null;
        int[][] q2 = new int[2][3];
        double t = 0;

            switch (r) {
                case 1:
                    this.view.print("Pode navegar a lista por inteiro ou por letra");
                    this.view.print("Lista inteira [qualquer tecla] Lista por letra [1]");
                    letra = input.lerString().charAt(0);
                    if (letra == '1') {
                        this.view.print("Introduza uma letra:");
                        letra = input.lerString().charAt(0);
                        Crono.start();
                        s = query1(letra);
                        t = Crono.stop();
                        this.view.navegadorS("Há " + s.size() + " Produtos não comprados com a letra " + letra, s);
                        view.print(Crono.toString(t));
                        s.clear();
                    } else {
                        Crono.start();
                        s = query1();
                        t = Crono.stop();
                        this.view.navegadorS("Há " + s.size() + " Produtos não comprados", s);

                        view.print(Crono.toString(t));
                        s.clear();
                    }
                    break;
                case 2:
                    System.out.println("Insira um mês:");
                    m = input.lerInt();
                    this.view.print("Pode navegar os dados por inteiro ou por filial");
                    this.view.print("Ler todos os dados [qualquer tecla] Ler por filial [1]");
                    letra = input.lerString().charAt(0);
                    if (letra == '1') {
                        if (scanMes(m)) {
                            System.out.println("Insira uma filial (1 a 3):");
                            f = input.lerInt();

                            if (scanFilial(f)) {
                                Crono.start();
                                q2 = query2(m);
                                t = Crono.stop();
                                this.view.printquery2(q2, f - 1);
                                view.print(Crono.toString(t));
                            }
                        }
                        break;
                    } else {
                        Crono.start();
                        q2 = query2(m);
                        t = Crono.stop();
                        for (int i = 0; i < 3; i++)
                            this.view.printquery2(q2, i);
                        view.print(Crono.toString(t));
                    }
                    break;

                case 3:
                    this.view.print("Introduza um codigo de cliente:");
                    cod = input.lerCliente(model.getCat_clientes());
                    this.view.print("Pode navegar os dados por inteiro ou por mês");
                    this.view.print("Ler todos os dados [qualquer tecla] Ler por mês [1]");
                    letra = input.lerString().charAt(0);
                    if(letra == '1'){
                        System.out.println("Insira um mês:");
                        m = input.lerInt();
                        if (scanMes(m)) {
                            Crono.start();
                            int[] x = query3_compras(cod);
                            int[] y = query3_produtos(cod);
                            double[] z = query3_gastou(cod);
                            t = Crono.stop();
                            this.view.printquery3(x, y, z, m-1);
                            view.print(Crono.toString(t));
                        }
                    }
                    else {
                        Crono.start();
                        int[] x = query3_compras(cod);
                        int[] y = query3_produtos(cod);
                        double[] z = query3_gastou(cod);
                        t = Crono.stop();
                        this.view.printquery3(x, y, z);
                        view.print(Crono.toString(t));
                    }
                    break;
                case 4:
                    this.view.print("Introduza um codigo de produto:");
                    cod = input.lerProduto(model.getCat_produtos());
                    this.view.print("Pode navegar os dados por inteiro ou por mês");
                    this.view.print("Ler todos os dados [qualquer tecla] Ler por mês [1]");
                    letra = input.lerString().charAt(0);
                    if(letra == '1'){
                        System.out.println("Insira um mês:");
                        m = input.lerInt();
                        if(scanMes(m)) {
                            Crono.start();
                            int[] x = query4_comprado(cod);
                            int[] y = query4_clientes(cod);
                            double[] z = query4_faturou(cod);
                            t = Crono.stop();
                            this.view.printquery4(x, y, z, m-1);
                            view.print(Crono.toString(t));
                        }
                    }
                    else {
                        Crono.start();
                        int[] x = query4_comprado(cod);
                        int[] y = query4_clientes(cod);
                        double[] z = query4_faturou(cod);
                        t = Crono.stop();
                        this.view.printquery4(x, y, z);
                        view.print(Crono.toString(t));
                    }
                    break;
                case 5:
                    this.view.print("Introduza um codigo de cliente:");
                    cod = input.lerCliente(model.getCat_clientes());
                    Crono.start();
                    Map<String,Integer> novo_mapa = query5(cod);
                    t = Crono.stop();
                    this.view.navegadorS("Produtos e quantidades compradas", mapToList(novo_mapa));
                    view.print(Crono.toString(t));
                    novo_mapa.clear();
                    break;
                case 6:
                    this.view.print("Introduza o numero desejado:");
                    m = input.lerInt();
                    Crono.start();
                    List<Produto> lista = query6_init(m);
                    List<String> l1 = query6_s(lista);
                    List<Integer> l2 = query6_quantidades(lista);
                    List<Integer> l3 = query6_clientes_distintos(lista);
                    t = Crono.stop();
                    this.view.navegadorI("Os X produtos mais vendidos", l1, l2, l3);
                    view.print(Crono.toString(t));
                    lista.clear();
                    l1.clear(); l2.clear(); l3.clear();
                    break;
                case 7:
                    this.view.print("Pode navegar os dados por inteiro ou por mês");
                    this.view.print("Ler todos os dados [qualquer tecla] Ler por filial [1]");
                    letra = input.lerString().charAt(0);
                    if(letra == '1'){
                        System.out.println("Insira uma filial (1 a 3):");
                        f = input.lerInt();

                        if (scanFilial(f)) {
                            Crono.start();
                            List<Cliente> l5 = query7_init(f);
                            l1 = query7_s(l5);
                            List<Double> l4 = query7_faturado(l5,f);
                            t = Crono.stop();
                            this.view.navegador7("Os 3 maiores compradores em termos de faturação ", l1, l4);
                            view.print(Crono.toString(t));
                            l1.clear(); l4.clear(); l5.clear();
                        }
                        break;
                    } else{

                        for(f = 1; f <= 3; f++) {
                            Crono.start();
                            List<Cliente> l5 = query7_init(f);
                            l1 = query7_s(l5);
                            List<Double> l4 = query7_faturado(l5,f);
                            t += Crono.stop();
                            this.view.navegador7("Os 3 maiores compradores em termos de faturação da filial " + f, l1, l4);
                            l1.clear(); l4.clear(); l5.clear();
                        }
                        view.print(Crono.toString(t));
                        break;
                    }
                case 8:
                    this.view.print("Introduza o numero desejado:");
                    m = input.lerInt();
                    Crono.start();
                    List<Cliente> l5 = query8_init(m);
                    l1 = query8_s(l5);
                    l2 = query8_numeros(l5);
                    t = Crono.stop();
                    this.view.navegador8("Clientes que mais produtos diferentes compraram ", l1, l2);
                    view.print(Crono.toString(t));
                    l1.clear(); l2.clear(); l5.clear();
                    break;
                case 9:
                    this.view.print("Introduza um codigo de produto:");
                    cod = input.lerProduto(model.getCat_produtos());
                    this.view.print("Introduza o numero desejado:");
                    m = input.lerInt();
                    Crono.start();
                    l1 = query9_init(cod, m);
                    List<Double> l4 = query9_gasto(cod, m);
                    t = Crono.stop();
                    this.view.navegador9("Clientes que mais compraram e os seus gastos", l1,l4);
                    view.print(Crono.toString(t));
                    l1.clear(); l4.clear();
                    break;
                case 10:
                    Crono.start();
                    Map<String, Double[][]> novo = query10();
                    t = Crono.stop();
                    this.view.navegadorMap("Lista de produtos e a sua faturação ", novo);
                    view.print(Crono.toString(t));
                    novo.clear();
                    break;
        }
    }



    public boolean scanMes(int m){

        if(m>0 && m<13) return true;
        else {
            System.out.println("Mes invalido. Insira um mes de 1 a 12.");

        }
        return false;
    }

    public boolean scanFilial(int f){

        if(f>0 && f<4) return true;
        else {
            System.out.println("Model.Filial invalida. Insira uma filial de 1 a 3.");

        }
        return false;
    }


    /////////////////////////////////////////////////////////////////////////////////////////////
    // DONE
    private String numero_compras_mes(int mes){
        int vendas = 0;
        for(int i = 0; i < 3; i++){
            vendas += model.getFaturacao().getTabela_vendas()[mes-1][i];
        }
        StringBuilder sb = new StringBuilder();
        sb.append("No mês ").append(mes).append(" foram feitas ").append(vendas).append(" compras. \n");
        return sb.toString();
    }

    // DONE
    private String faturacao_mes(int mes){
        double f = 0;
        for(int i = 0; i < 3; i++){
            f += model.getFaturacao().getTabela_faturacao()[mes-1][i];
        }
        StringBuilder sb = new StringBuilder();
        sb.append("No mês ").append(mes).append(" a faturação total foi de ").append(f).append(" . \n")
                .append("A filial 1 faturou ").append(model.getFaturacao().getTabela_faturacao()[mes-1][0]).append(" . \n")
                .append("A filial 2 faturou ").append(model.getFaturacao().getTabela_faturacao()[mes-1][1]).append(" . \n")
                .append("A filial 3 faturou ").append(model.getFaturacao().getTabela_faturacao()[mes-1][2]).append(" . \n");
        return sb.toString();
    }

    // DONE
    private String clientes_distintos_mes(int mes){
        StringBuilder sb = new StringBuilder();
        int c_in_mes = model.getFilial().getRC().produtos_distintos_mes(mes);

        int c_in_1 = model.getFilial().getRC().produtos_distintos_fm(mes, 1);
        int c_in_2 = model.getFilial().getRC().produtos_distintos_fm(mes, 2);
        int c_in_3 = model.getFilial().getRC().produtos_distintos_fm(mes, 3);

        sb.append("No mês ").append(mes).append(" houve ").append(c_in_mes).append(" clientes distintos. \n")
                .append("Na filial 1 houve ").append(c_in_1).append(" clientes distintos. \n")
                .append("Na filial 2 houve ").append(c_in_2).append(" clientes distintos. \n")
                .append("Na filial 3 houve ").append(c_in_3).append(" clientes distintos. \n");
        return sb.toString();
    }

    //////////////////////////////////////////////////////////////////////////////////

    //Lista ordenada alfabeticamente com os códigos dos produtos nunca comprados e o seu respetivo total;

    //DONE
    private List<String> query1(char letra){
        List<String> lista = new ArrayList<>();
        for (Produto p: this.model.getFilial().getRP().letra(letra)) {
            if (!p.isVendido()) {
                lista.add(p.getId());
            }
        }
        return lista.stream().sorted().collect(Collectors.toList());
    }

    private List<String> query1(){
        List<String> lista = new ArrayList<>();
        for (Produto p: this.model.getFilial().getRP().getTabela_produtos().values()) {
            if (!p.isVendido()) {
                lista.add(p.getId());
            }
        }
        return lista.stream().sorted().collect(Collectors.toList());
    }

    /*
    Dado um mês válido, determinar o número total global de vendas realizadas e o
    número total de clientes distintos que as fizeram; Fazer o mesmo mas para cada uma das filiais
    */

    private int[][] query2(int mes){
        int[][] i = new int[2][3];
        for (int f = 0; f < 3; f++) {
            i[0][f] = model.getFaturacao().getTabela_vendas()[mes - 1][f];
        }

        for (Cliente c: this.model.getFilial().getRC().getTabela_clientes().values()) {
            for (int f = 0; f < 3; f++) {
                if(c.getVolume_compras()[mes - 1][f] != 0){
                    i[1][f]++;
                }
            }
        }

        return i;
    }

    /*
    Dado um código de cliente, determinar, para cada mês, quantas compras fez,
    quantos produtos distintos comprou e quanto gastou no total.
    */

    //DONE
    private int[] query3_compras(String c){
        int[][] aux = this.model.getFilial().getRC().getTabela_clientes().get(c).getVolume_compras();
        int[] i = new int[12];
        int r;
        for (int mes = 0; mes < 12; mes++) {
            r = 0;
            for (int f = 0; f < 3; f++) {
                r += aux[mes][f];
            }
            i[mes] = r;
        }
        return i;
    }

    //DONE
    private int[] query3_produtos(String c){
        return this.model.getFilial().getRC().getTabela_clientes().get(c).produtos_d();
    }

    //DONE
    private double[] query3_gastou(String c){
        double[][] aux = this.model.getFilial().getRC().getTabela_clientes().get(c).getDespeza_compras();
        double[] i = new double[12];
        double r;
        for (int mes = 0; mes < 12; mes++) {
            r = 0;
            for (int f = 0; f < 3; f++) {
                r += aux[mes][f];
            }
            i[mes] = r;
        }
        return i;
    }

    /*
    Dado o código de um produto existente, determinar, mês a mês, quantas vezes foi
    comprado, por quantos clientes diferentes e o total faturado;
    */

    //DONE
    private int[] query4_comprado(String p){
        int[][] aux = this.model.getFilial().getRP().getTabela_produtos().get(p).getVezes_comprado();
        int[] i = new int[12];
        int r;
        for (int mes = 0; mes < 12; mes++) {
            r = 0;
            for (int f = 0; f < 3; f++) {
                r += aux[mes][f];
            }
            i[mes] = r;
        }
        return i;
    }

    //DONE
    private int[] query4_clientes(String p){
        return this.model.getFilial().getRP().getTabela_produtos().get(p).clientes_d();
    }

    //DONE
    private double[] query4_faturou(String p){
        double[][][] aux = this.model.getFilial().getRP().getTabela_produtos().get(p).getFaturado_in();
        double[] i = new double[12];
        double r;
        for (int mes = 0; mes < 12; mes++) {
            r = 0;
            for (int f = 0; f < 3; f++) {
                r += aux[mes][f][0] + aux[mes][f][1];
            }
            i[mes] = r;
        }
        return i;
    }

    /*
    Dado o código de um cliente determinar a lista de códigos de produtos que mais
    comprou (e quantos), ordenada por ordem decrescente de quantidade e, para
    quantidades iguais, por ordem alfabética dos códigos;
    */

    //DONE
    private Map<String, Integer> query5(String c){
        return model.getFilial().getRC().getTabela_clientes().get(c).getProdutos_Unidades();
        //map.size() para obter quantos produtos comprou
    }

    public List<String> mapToList(Map<String, Integer> map){
        List<String> lista = new ArrayList<>();
        for (String s: map.keySet()){
            lista.add(s +" ------> " + map.get(s).toString());
        }
        return lista;
    }

    /*
    Determinar o conjunto dos X produtos mais vendidos em todo o ano (em numero de unidades vendidas)
    indicando o número total de distintos clientes que o compraram (X é um inteiro dado pelo utilizador);
    */

    //DONE
    private List<Produto> query6_init(int X){
        return model.getFilial().getRP().x_mais_vendidos(X);
    }

    private List<String> query6_s(List<Produto> produtos){
        List<String> novo = new ArrayList<>();
        for (Produto p: produtos) {
            novo.add(p.getId());
        }
        return novo;
    }

    //DONE
    private List<Integer> query6_quantidades(List<Produto> produtos){
        return model.getFilial().getRP().quantidades(produtos);
    }

    //DONE
    private List<Integer> query6_clientes_distintos(List<Produto> produtos){
        return model.getFilial().getRP().clientes_distintos(produtos);
    }

    /*
    Determinar, para cada filial, a lista dos três maiores compradores em termos de
    dinheiro faturado;
    */

    //DONE
    private List<Cliente> query7_init(int filial){
        return model.getFilial().getRC().maiores_compradores(3, filial-1);
    }

    private List<String> query7_s(List<Cliente> clientes){
        List<String> novo = new ArrayList<>();
        for (Cliente c: clientes) {
            novo.add(c.getId());
        }
        return novo;
    }

    private List<Double> query7_faturado(List<Cliente> clientes, int filial){
        List<Double> novo = new ArrayList<>();
        for (Cliente c: clientes) {
            novo.add(c.quanto_faturou(filial-1));
        }
        return novo;
    }

    /*
    Determinar os códigos dos X clientes (sendo X dado pelo utilizador) que compraram
    mais produtos diferentes (não interessa a quantidade nem o valor), indicando
    quantos, sendo o critério de ordenação a ordem decrescente do número de
    produtos;
    */

    // quando um cliente tem o mesmo nr que outro ele milagrosamente desaparece
    private List<Cliente> query8_init(int X){
        return model.getFilial().getRC().mais_produtos_comprados(X);
    }

    private List<String> query8_s(List<Cliente> clientes){
        List<String> novo = new ArrayList<>();
        for (Cliente c: clientes) {
            novo.add(c.getId());
        }
        return novo;
    }

    //DONE
    private List<Integer> query8_numeros(List<Cliente> clientes){
        List<Integer> novo = new ArrayList<>();
        for (Cliente c: clientes) {
            novo.add(c.produtos_distintos());
        }
        return novo;
    }

    /*
    Dado o código de um produto que deve existir, determinar o conjunto dos X clientes
    que mais o compraram e, para cada um, qual o valor gasto (ordenação cf. 5);
    */

    //DONE
    private List<String> query9_init(String produto, int X){
        return model.getFilial().getRP().x_mais_compraram_s(produto,X);
    }

    //DONE
    private List<Double> query9_gasto(String produto, int X){
        return model.getFilial().getRP().x_mais_compraram_d(produto,X);
    }

    /*
    Determinar mês a mês, e para cada mês filial a filial, a faturação total com cada
    produto.
    */

    //DONE
    private Map<String, Double[][]> query10(){
        return model.getFilial().getRP().mapa_faturacao_produto();
    }


}
