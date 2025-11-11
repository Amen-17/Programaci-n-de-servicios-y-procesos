class CuentaBancaria {
 int saldo = 1000;

 void sacarDinero (String nombre, int importe)
 {
	if(saldo >= importe){
	saldo -= importe;
	System.out.println(nombre+" retira "+importe+"€");
	}else{
	System.out.println(nombre+" no puede retirar "+importe+"€");
	}
	consultarSaldo();
	//Después de la operación dormir el hilo
	 try {
	 Thread.sleep(1000);
	 }
	 catch (InterruptedException e) {
	 e.printStackTrace();
	 }

 }
	void consultarSaldo(){
		System.out.println("Saldo actual de la cuenta = "+saldo);
	}
 void ingresarDinero (String nombre, int importe)
 {
	saldo += importe;
	System.out.println(nombre+" ingresa "+importe+"€");
	consultarSaldo();
 //Después de la operación dormir el hilo
 try {
 Thread.sleep(1000);
 }
 catch (InterruptedException e) {
 e.printStackTrace();
 }
 }
}


class HiloSacarDinero extends Thread {

 private CuentaBancaria cuenta;
 private String nombre;
 private int cantidad;

 // Constructor de la clase
 HiloSacarDinero(CuentaBancaria micuenta, String nombre, int cantidad)
 {
	 this.cuenta = micuenta;
	 this.nombre = nombre;
	 this.cantidad = cantidad;
 }

 public void run() {
 	cuenta.sacarDinero(nombre,cantidad);
 }
}
class HiloIngresarDinero extends Thread {

 private CuentaBancaria cuenta;
 private String nombre;
 private int cantidad;
 // Constructor de la clase
 HiloIngresarDinero (CuentaBancaria micuenta, String nombre, int cantidad)
 {
	this.cuenta = micuenta;
	this.nombre = nombre;
	this.cantidad = cantidad;
 }

 public void run() {
	cuenta.ingresarDinero(nombre,cantidad);
 }
}
public class HiloCajeroAutomatico {

 public static void main(String[] args)
 {
	CuentaBancaria c = new CuentaBancaria();
	new HiloIngresarDinero(c,"Padre",200).start();
	new HiloSacarDinero(c,"Madre",800).start();
	new HiloIngresarDinero(c,"Hijo1",300).start();
	new HiloSacarDinero(c,"Hijo2",800).start();
	new HiloSacarDinero(c,"Abuelo",600).start();
 }
}
