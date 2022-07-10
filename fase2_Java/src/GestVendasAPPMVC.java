
import Controller.*;
import Model.*;
import View.*;

public class GestVendasAPPMVC{

    private static Object ObjectInput;
    private static Object ObjectOutput;

    public static void main(String[] args) {
        GestVendasModel model = new Model();
        GestVendasView view = new View();
        GestVendasControler controler = new Controler();

        controler.setModel(model);
        controler.setView(view);

        controler.menu();
    }
}
