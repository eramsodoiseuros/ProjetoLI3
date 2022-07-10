package Model;

public interface Validacao {

    /**
     * Metodo que devolve se uma string representa um cliente
     * @param s string a validar
     * */
    public static boolean validaCliente(String s){
        boolean v = false;
        String[] part = s.split("(?<=\\D)(?=\\d)");
        boolean isNumeric = false;

        if(part[1].chars().allMatch(Character::isDigit) && Integer.parseInt(part[1]) >= 1000 && Integer.parseInt(part[1]) <= 5000) {isNumeric = true;}
        char fst = s.charAt(0);
        char snd = s.charAt(1);

        if(s.length() == 5 && Character.isLetter(fst) && isNumeric) {v = true;}
        if(Character.isLetter(snd)) v = false;

        return v;
    }

    /**
     * Metodo que devolve se uma string representa um produto
     * @param s string a validar
     * */
    public static boolean validaProduto(String s){
        boolean v = false;
        String[] part = s.split("(?<=\\D)(?=\\d)");
        boolean isNumeric = false;

        if(part[1].chars().allMatch(Character::isDigit) && Integer.parseInt(part[1]) >= 1000 && Integer.parseInt(part[1]) <= 9999) {isNumeric = true;}

        char fst = s.charAt(0);
        char snd = s.charAt(1);

        if(s.length() == 6 && Character.isLetter(fst) && Character.isLetter(snd) && isNumeric) {v = true;}

        return v;
    }

}
