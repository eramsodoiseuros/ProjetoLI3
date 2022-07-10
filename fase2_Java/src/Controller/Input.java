package Controller;

import Model.Catalogo_Clientes;
import Model.Catalogo_Produtos;
import Model.Validacao;
import View.*;

import static java.lang.System.in;
import java.util.Scanner;
import java.util.InputMismatchException;

public class Input implements Validacao {

    private GestVendasView view = new View();
    public String lerString() {
        Scanner input = new Scanner(in);
        boolean ok = false;
        String txt = "";
        while(!ok) {
            try {
                txt = input.nextLine();
                ok = true;
            }
            catch(InputMismatchException e) {
                this.view.print("Texto Invalido");
                this.view.print("Novo valor: ");
                input.nextLine();
            }
        }
        //input.close();
        return txt;
    }

    public String lerCliente(Catalogo_Clientes c) {
        Scanner input = new Scanner(in);
        boolean ok = false;
        String txt = "";
        while(!ok) {
            try {
                txt = input.nextLine();
                if(Validacao.validaCliente(txt))
                    if(c.contains(txt))
                        ok = true;
            }
            catch(InputMismatchException e) {
                this.view.print("Model.Cliente Invalido");
                this.view.print("Novo valor: ");
                input.nextLine();
            }
        }
        //input.close();
        return txt;
    }

    public String lerProduto(Catalogo_Produtos p) {
        Scanner input = new Scanner(in);
        boolean ok = false;
        String txt = "";
        while(!ok) {
            try {
                txt = input.nextLine();
                if(Validacao.validaProduto(txt))
                    if(p.contains(txt))
                        ok = true;
            }
            catch(InputMismatchException e) {
                this.view.print("Produto Invalido");
                this.view.print("Novo valor: ");
                input.nextLine();
            }
        }
        //input.close();
        return txt;
    }

    public int lerInt() {
        Scanner input = new Scanner(in);
        boolean ok = false;
        int i = 0;
        while(!ok) {
            try {
                i = input.nextInt();
                ok = true;
            }
            catch(InputMismatchException e){
                this.view.print("Inteiro Invalido");
                this.view.print("Novo valor: ");
                input.nextLine();
            }
        }
        //input.close();
        return i;
    }

    public double lerDouble() {
        Scanner input = new Scanner(in);
        boolean ok = false;
        double d = 0.0;
        while(!ok) {
            try {
                d = input.nextDouble();
                ok = true;
            }
            catch(InputMismatchException e){
                this.view.print("Valor real Invalido");
                this.view.print("Novo valor: ");
                input.nextLine();
            }
        }
        //input.close();
        return d;
    }

    public float lerFloat() {
        Scanner input = new Scanner(in);
        boolean ok = false;
        float f = 0.0f;
        while(!ok) {
            try {
                f = input.nextFloat();
                ok = true;
            }
            catch(InputMismatchException e){
                this.view.print("Valor real Invalido");
                this.view.print("Novo valor: ");
                input.nextLine();
            }
        }
        //input.close();
        return f;
    }

    public boolean lerBoolean() {
        Scanner input = new Scanner(in);
        boolean ok = false;
        boolean b = false;
        while(!ok) {
            try {
                b = input.nextBoolean();
                ok = true;
            }
            catch(InputMismatchException e){
                this.view.print("Booleano Invalido");
                this.view.print("Novo valor: ");
                input.nextLine();
            }
        }
        //input.close();
        return b;
    }

    public short lerShort() {
        Scanner input = new Scanner(in);
        boolean ok = false;
        short s = 0;
        while(!ok) {
            try {
                s = input.nextShort();
                ok = true;
            }
            catch(InputMismatchException e){
                this.view.print("Short Invalido");
                this.view.print("Novo valor: ");
                input.nextLine();
            }
        }
        //input.close();
        return s;
    }
}