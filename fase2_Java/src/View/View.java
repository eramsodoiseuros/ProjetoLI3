package View;

import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class View implements GestVendasView {

    public View(){
    }

    public void print(Object o){
        System.out.println(o);
    }

    public void navegadorS (String header, List<String> lista) {

        int exit = 0;
        Scanner scanner = new Scanner(System.in);

        String scanout = null;
        int pag = 1, count = 0, i =0;
        int pagnum = 1;
        int tamanho = lista.size();

        if (tamanho % 10 == 0) pagnum = tamanho / 10;
        else pagnum = (tamanho / 10) + 1;

        System.out.println(header);

        while (exit != 1) {

            if (pag > pagnum || pag == 0) {

                System.out.println("Página inválida ou não existente\n");

            } else {
                System.out.println("************ Página " + pag + " de " + pagnum + " ************\n");
                System.out.println("Existem " + tamanho + " resultados\n");

                for(i=(pag*10)-10; count<10 && count<tamanho && i<tamanho; i++){
                    if(lista.get(i)!=null){
                        System.out.println(lista.get(i));
                        count++;
                    }
                    else break;
                }
                count = 0;
            }

            if(pagnum == 1)
                return;

            System.out.println("\n");
            System.out.println("D para Proxima página \n");
            System.out.println("A para Página Anterior \n");
            System.out.println("E para sair\n");
            System.out.println("Inserir número página: \n");

            if (scanner.hasNextInt()) {
                pag = scanner.nextInt();
            } else {
                scanout = scanner.nextLine();

                if (scanout.equals("e") || scanout.equals("E")) {
                    exit = 1;
                } else if ((scanout.equals("d") || scanout.equals("D")) && pag < pagnum) pag++;
                else if ((scanout.equals("a") || scanout.equals("A")) && pag > 1) pag--;
            }
        }
    }

    public void navegadorI (String header, List<String> vendidos, List<Integer> lista, List<Integer> clientes) {

        int exit = 0;
        Scanner scanner = new Scanner(System.in);

        String scanout = null;
        int pag = 1, count = 0, i =0;
        int pagnum = 1;
        int tamanho = lista.size();

        if (tamanho % 10 == 0) pagnum = tamanho / 10;
        else pagnum = (tamanho / 10) + 1;

        System.out.println(header);

        while (exit != 1) {

            if (pag > pagnum || pag == 0) {
                System.out.println("Página inválida ou não existente\n");
            } else {
                System.out.println("************ Página " + pag + " de " + pagnum + " ************\n");
                System.out.println("Existem " + tamanho + " resultados\n");

                for(i=(pag*10)-10; count<10 && count<tamanho && i<tamanho; i++){
                    if(lista.get(i)!=null){
                        System.out.println(vendidos.get(i)+ "       " + lista.get(i) + "    " + clientes.get(i));
                        count++;
                    }
                    else break;
                }
                count = 0;
            }

            if(pagnum == 1)
                return;

            System.out.println("\n");
            System.out.println("D para Proxima página \n");
            System.out.println("A para Página Anterior \n");
            System.out.println("E para sair\n");
            System.out.println("Inserir número página: \n");

            if (scanner.hasNextInt()) {
                pag = scanner.nextInt();

            } else {
                scanout = scanner.nextLine();

                if (scanout.equals("e") || scanout.equals("E")) {
                    exit = 1;
                } else if ((scanout.equals("d") || scanout.equals("D")) && pag < pagnum) pag++;
                else if ((scanout.equals("a") || scanout.equals("A")) && pag > 1) pag--;
            }
        }
    }

    public void navegador7 (String header, List<String> lista, List<Double> vendidos) {
        System.out.println(header);
        for(int i= 0; i < 3; i++) {
            if (lista.get(i) != null) {
                System.out.println(lista.get(i) + "       " + vendidos.get(i));
            }
        }
    }


    public void navegador9(String header, List<String> lista, List<Double> vendidos) {

        int exit = 0;
        Scanner scanner = new Scanner(System.in);

        String scanout = null;
        int pag = 1, count = 0, i =0;
        int pagnum = 1;
        int tamanho = lista.size();

        if (tamanho % 10 == 0) pagnum = tamanho / 10;
        else pagnum = (tamanho / 10) + 1;

        System.out.println(header);

        while (exit != 1) {
            if (pag > pagnum || pag == 0) {
                System.out.println("Página inválida ou não existente\n");
            } else {
                System.out.println("************ Página " + pag + " de " + pagnum + " ************\n");
                System.out.println("Existem " + tamanho + " resultados\n");

                for(i=(pag*10)-10; count<10 && count<tamanho && i<tamanho; i++){
                    if(lista.get(i)!=null){
                        System.out.println(lista.get(i)+ "       " + vendidos.get(i) );
                        count++;
                    }
                    else break;
                }
                count = 0;
            }

            if(pagnum == 1)
                return;

            System.out.println("\n");
            System.out.println("D para Proxima página \n");
            System.out.println("A para Página Anterior \n");
            System.out.println("E para sair\n");
            System.out.println("Inserir número página: \n");

            if (scanner.hasNextInt()) {
                pag = scanner.nextInt();

            } else {
                scanout = scanner.nextLine();

                if (scanout.equals("e") || scanout.equals("E")) {
                    exit = 1;
                } else if ((scanout.equals("d") || scanout.equals("D")) && pag < pagnum) pag++;
                else if ((scanout.equals("a") || scanout.equals("A")) && pag > 1) pag--;
            }
        }
    }

    public void navegador8 (String header, List<String> lista, List<Integer> vendidos) {

        int exit = 0;
        Scanner scanner = new Scanner(System.in);

        String scanout = null;
        int pag = 1, count = 0, i =0;
        int pagnum = 1;
        int tamanho = lista.size();

        if (tamanho % 10 == 0) pagnum = tamanho / 10;
        else pagnum = (tamanho / 10) + 1;

        System.out.println(header);

        while (exit != 1) {
            if (pag > pagnum || pag == 0) {
                System.out.println("Página inválida ou não existente\n");
            } else {
                System.out.println("************ Página " + pag + " de " + pagnum + " ************\n");
                System.out.println("Existem " + tamanho + " resultados\n");

                for(i=(pag*10)-10; count<10 && count<tamanho && i<tamanho; i++){
                    if(lista.get(i)!=null){
                        System.out.println(lista.get(i)+ "       " + vendidos.get(i) );
                        count++;
                    }
                    else break;
                }
                count = 0;
            }

            if(pagnum == 1)
                return;

            System.out.println("\n");
            System.out.println("D para Proxima página \n");
            System.out.println("A para Página Anterior \n");
            System.out.println("E para sair\n");
            System.out.println("Inserir número página: \n");

            if (scanner.hasNextInt()) {
                pag = scanner.nextInt();

            } else {
                scanout = scanner.nextLine();

                if (scanout.equals("e") || scanout.equals("E")) {
                    exit = 1;
                } else if ((scanout.equals("d") || scanout.equals("D")) && pag < pagnum) pag++;
                else if ((scanout.equals("a") || scanout.equals("A")) && pag > 1) pag--;
            }
        }
    }

    public void navegadorMap (String header, Map<String,Double[][]> map) {

        int exit = 0;
        Scanner scanner = new Scanner(System.in);

        String scanout = null;
        int pag = 1, count = 0, i =0;
        int tamanho = map.size();
        int pagnum = tamanho;
        int t =0;

        System.out.println(header);

        while (exit != 1) {
            if (pag > pagnum || pag == 0) {
                System.out.println("Página inválida ou não existente\n");
            } else {
                System.out.println("************ Página " + pag + " de " + pagnum + " ************\n");
                System.out.println("Existem " + tamanho + " resultados\n");
                System.out.println("Produto | Mês | Model.Filial | Faturação |");

                for(i=(pag*36)-36;  i<map.keySet().size() && i<tamanho; i++) {
                    while (count<1) {
                        String h = String.valueOf(map.keySet().toArray()[i]);
                        for (int m = 0; m < 12; m++) {
                            for (int k = 0; k < 3; k++) {
                                System.out.println(h + " | " + (m + 1) + " | " + (k + 1) + " | " + map.get(h)[m][k] + " |");
                            }
                        }
                        count++;
                    }
                }
            }
            count=0;

            if(pagnum == 1)
                return;

            System.out.println("\n");
            System.out.println("D para Proxima Produto \n");
            System.out.println("A para Produto Anterior \n");
            System.out.println("E para sair\n");
            System.out.println("Inserir número página: \n");

            if (scanner.hasNextInt()) {
                pag = scanner.nextInt();

            } else {
                scanout = scanner.nextLine();

                if (scanout.equals("e") || scanout.equals("E")) {
                    exit = 1;
                } else if ((scanout.equals("d") || scanout.equals("D")) && pag < pagnum) pag++;
                else if ((scanout.equals("a") || scanout.equals("A")) && pag > 1) pag--;
            }
        }
    }

    public void printMenu(){
        System.out.println("1. Inicializar os dados apartir de ficheiros de texto");
        System.out.println("2. Load : Carrega dados de um ficheiro binario");
        System.out.println("3. Save : Guarda o estado actual num ficheiro binario");
        System.out.println("4. Estatisticas : Mostra informações sobre o ultimo ficheiro de vendas lido");
        System.out.println("5. Resolução de Queries");
        System.out.println("0. Sair");
    }

    public void printMenuEstat(){
        System.out.println("1. Estatistica do Ficheiro de Vendas");
        System.out.println("2. Numero de compras por mês");
        System.out.println("3. Faturação mensal");
        System.out.println("4. Numero de clientes distintos por mês");
        System.out.println("0. Sair");
    }

    public void printQueries(){
        System.out.println("1. Lista ordenada alfabeticamente com os códigos dos produtos nunca comprados e o seu respetivo total");
        System.out.println("2. Dado um mês válido, determinar o número total global de vendas realizadas e o número total de clientes distintos que as fizeram, numa ou em todas as filiais");
        System.out.println("3. Dado um código de cliente, determinar, para cada mês, quantas compras fez, quantos produtos distintos comprou e quanto gastou no total");
        System.out.println("4. Dado o código de um produto existente, determinar, mês a mês, quantas vezes foi comprado, por quantos clientes diferentes e o total faturado");
        System.out.println("5. Dado o código de um cliente determinar a lista de códigos de produtos que mais comprou (e quantos), ordenada por ordem decrescente de quantidade e, para quantidades iguais, por ordem alfabética dos códigos;");
        System.out.println("6. Determinar o conjunto dos X produtos mais vendidos em todo o ano (em número de unidades vendidas) indicando o número total de distintos clientes que o compraram (X é um inteiro dado pelo utilizador);");
        System.out.println("7. Determinar, para cada filial, a lista dos três maiores compradores em termos de dinheiro faturado");
        System.out.println("8. Determinar os códigos dos X clientes que compraram mais produtos diferentes, indicando quantos");
        System.out.println("9. Dado o código de um produto que deve existir, determinar o conjunto dos X clientes que mais o compraram e, para cada um, qual o valor gasto");
        System.out.println("10.Determinar mês a mês, e para cada mês filial a filial, a faturação total com cada produto");
        System.out.println("0. Sair");
    }

    public void printquery2(int[][] q, int f){
        System.out.println("Total de vendas nessa filial: " + q[0][f]);
        System.out.println("Numero de clientes distintos nessa filial: " + q[1][f]+"\n");
    }


    public void printquery3(int[] q1, int[] q2, double[] q3, int m){
        System.out.println("Compras realizadas nesse mês : " + q1[m]);
        System.out.println("Numero de produtos distintos comprados: " + q2[m]);
        System.out.println("Total gasto: " + q3[m] + "\n");
    }

    public void printquery3(int[] q1, int[] q2, double[] q3){
        for(int m = 0; m < 12; m++){
            System.out.println("Compras realizadas no mês" + (m+1) + " : " + q1[m]);
            System.out.println("Numero de produtos distintos comprados: " + q2[m]);
            System.out.println("Total gasto: " + q3[m] + "\n");
        }
    }

    public void printquery4(int[] q1, int[] q2, double[] q3, int m){
        System.out.println("Vendas realizadas nesse mês : " + q1[m]);
        System.out.println("Numero de clientes distintos que compraram: " + q2[m]);
        System.out.println("Total faturado: " + q3[m] + "\n");
    }

    public void printquery4(int[] q1, int[] q2, double[] q3){
        for(int m = 0; m < 12; m++) {
            System.out.println("Vendas realizadas no mês " + (m + 1) + " : " + q1[m]);
            System.out.println("Numero de clientes distintos que compraram: " + q2[m]);
            System.out.println("Total faturado: " + q3[m] + "\n");
        }
    }
}




