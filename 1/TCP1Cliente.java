import java.io.*;
import java.net.*;
import java.util.Scanner;

public class TCP1Cliente{
	public static void main(String[] args) throws IOException {
		String Host = "192.168.204.107";
		int Puerto = 6666;//puerto remoto	

		Scanner sc = new Scanner(System.in);
		Socket Cliente = new Socket(Host, Puerto);

		System.out.print("Dame un número: ");
		int num = sc.nextInt();

		// Creación flujo de salida hacia el servidor
		DataOutputStream flujoSalida = new DataOutputStream(Cliente.getOutputStream());
		flujoSalida.writeInt(num);

		// Creación flujo de entrada desde el servidor
		DataInputStream flujoEntrada = new  DataInputStream(Cliente.getInputStream());
		int factorizado = flujoEntrada.readInt();
		System.out.println("Recibiendo del servidor la factorización: " + factorizado+"\n");

		// CERRAR STREAMS Y SOCKETS	
		flujoEntrada.close();	
		flujoSalida.close();	
		Cliente.close();	
	}
}
