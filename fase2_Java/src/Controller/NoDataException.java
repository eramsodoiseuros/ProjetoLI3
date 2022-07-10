package Controller;

public class NoDataException extends Exception {

    private static final String data_warning = "O estado não foi iniciado.";

    public NoDataException(){
    }

    @Override
    public String toString() {
        return data_warning;
    }
}
