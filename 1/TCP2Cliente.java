import java.io.*;
import java.net.*;

public class TCP2Cliente{
	public static void main(String[] args) throws IOException {
		String Host = "192.168.204.107";
		int Puerto = 6666;//puerto remoto	

		Socket Cliente = new Socket(Host, Puerto);

		// Creación flujo de entrada desde el servidor
		DataInputStream flujoEntrada = new  DataInputStream(Cliente.getInputStream());
		int num = flujoEntrada.readInt();
		System.out.print("Cliente 2: Calculando factorial del número "+num+"...\n");


		// Creación flujo de salida hacia el servidor
		DataOutputStream flujoSalida = new DataOutputStream(Cliente.getOutputStream());
		int num2 = calcFactorial(num);
		flujoSalida.writeInt(num2);

		// CERRAR STREAMS Y SOCKETS	
		flujoEntrada.close();	
		flujoSalida.close();	
		Cliente.close();	
	}

	public static int calcFactorial(int z){
		int num = 1;
		for(int i = 1; i <= z; i++){
			num *= i;
		}
		System.out.println("La factorización es "+num);
		return num;
	}
}
