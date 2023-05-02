package Combate;

public abstract class Piece {
    protected String name;
    protected int rank;
    protected int imovel;
    
    
    public Piece(String name, int rank, int imovel){
        this.name = name;
        this.rank = rank;
        this.imovel = imovel;
    }
    
   public String getName() {
       return name;
   }
   
   public int getRank(){
       return rank;
   }
}

public class Bomb extends Piece {
    public Bomb(){
        super("Bomb", -1, 1);
    }
}

public class Spy extends Piece {
    public Spy(){
        super("Spy", 1, 0);
    }
}

public class Marechal extends Piece {
    public Marechal(){
        super("Marechal", 10, 0);
    }
}

public class General extends Piece {
    public General(){
        super("General", 9, 0);
    }
}

public class Coronel extends Piece {
    public Coronel(){
        super("Coronel", 8, 0);
    }
}

public class Major extends Piece {
    public Major(){
        super("Major", 7, 0)
    }
}


public class Capitao extends Piece {
    public Capitao(){
        super("Capitao", 6, 0);
    }
}

public class Tenente extends Piece {
    public Tenente(){
        super("Tenente", 5, 0);
    }
}

public class Sargento extends Piece {
    public Sargeanto(){
        super("Sargento", 4, 0);
    }
}

public class Cabo extends Piece {
    public Cabo(){
        super("Cabo", 3, 0);
    }
}

public class Soldado extends Piece {
    public Soldado(){
        super("Soldado", 2, 0);
    }
}

