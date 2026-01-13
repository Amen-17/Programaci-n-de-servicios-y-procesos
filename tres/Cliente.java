package tres;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;

public class Cliente{
    public static void main(String[] args) throws IOException, ClassNotFoundException{
    
        Factura f = new Factura(555, "08/08/2004", 2500, "ESP");
        String Host = "192.168.204.107";
        int Puerto = 6666;//puerto remoto

        Socket cliente = new Socket(Host, Puerto);
        ObjectOutputStream ou = new ObjectOutputStream(cliente.getOutputStream());
        ou.writeObject(f);

        ObjectInputStream oi = new ObjectInputStream(cliente.getInputStream());
        f = (Factura) oi.readObject();
    
        System.out.println("El iva es :"+f.getIva());
        System.out.println("El total es :"+f.getTotal());
    }
}