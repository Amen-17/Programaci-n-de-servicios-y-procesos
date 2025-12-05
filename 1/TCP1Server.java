import java.io.*;
import java.net.*;

public class TCP1Server {
	public static void main(String[] args) throws IOException {
		int numeroPuerto = 6666;// Puerto
		ServerSocket servidor = new ServerSocket(numeroPuerto);
		Socket cliente1 = servidor.accept();

		// Creación flujo de entrada del cliente1
		InputStream entrada = cliente1.getInputStream();
		DataInputStream flujoEntrada = new DataInputStream(entrada);

		// Recibiendo datos del cliente1
		int num = flujoEntrada.readInt();
		System.out.println("Recibiendo del cliente1: " + num);

		// Creación flujo de salida del cliente2
		Socket cliente2 = servidor.accept();
		OutputStream salida = cliente2.getOutputStream();
		DataOutputStream flujoSalida = new DataOutputStream(salida);
		flujoSalida.writeInt(num);

		// Creación flujo de entrada del cliente2
		entrada = cliente2.getInputStream();
		flujoEntrada = new DataInputStream(entrada);
		System.out.println("Recibiendo la factorización del cliente2...");

		// Creación flujo de salida del cliente1
		salida = cliente1.getOutputStream();
		flujoSalida = new DataOutputStream(salida);
		flujoSalida.writeInt(flujoEntrada.readInt());

		// Cierre streams y sockets
		entrada.close();
		flujoEntrada.close();

		salida.close();
		flujoSalida.close();

		cliente1.close();
		cliente2.close();
		servidor.close();
	}
}
