package tres;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.ServerSocket;
import java.net.Socket;

public class TCP3Server {
    public static void main(String[] args) throws IOException, ClassNotFoundException {
		int numeroPuerto = 6666;// Puerto
		ServerSocket servidor = new ServerSocket(numeroPuerto);
		Socket cliente1 = servidor.accept();

        ObjectInputStream ou = new ObjectInputStream(cliente1.getInputStream());
        Factura f = (Factura) ou.readObject();

        String tipoIva = f.getTipIva();
        if (tipoIva.equalsIgnoreCase("IGC")) {
            f.setIva(0.7);
        }else if (tipoIva.equalsIgnoreCase("ESP")) {
            f.setIva(0.21);
        }else if (tipoIva.equalsIgnoreCase("EUR")) {
            f.setIva(0.15);
        }
        
        double total = (f.getImporte() * f.getIva())+f.getImporte();
        f.setTotal(total);

        ObjectOutputStream oo = new ObjectOutputStream(cliente1.getOutputStream());
        oo.writeObject(f);

        ou.close();
        oo.close();
        cliente1.close();
        servidor.close();
    }
}
