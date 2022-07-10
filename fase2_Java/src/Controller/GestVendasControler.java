package Controller;

import Model.GestVendasModel;
import View.GestVendasView;

/**
 * Interface do Controller
 * */
public interface GestVendasControler {

    /**
     * Metodo que desencadeia o menu
     * */
    public void menu();

    /**
     * Metodo que dá set de um model
     * @param m Model a copiar
     * */
    public void setModel(GestVendasModel m);

    /**
     * Metodo que dá set de uma view
     * @param v View a copiar
     * */
    public void setView(GestVendasView v);
}
