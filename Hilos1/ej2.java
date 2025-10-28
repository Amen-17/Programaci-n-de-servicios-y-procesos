class HiloSumasRestas implements Runnable {
	private int numero=1000;
	int numveces;
	String operacion;
	
	 //Constructor de la clase
	 public HiloSumasRestas (int numveces, String operacion){
	 this.numveces = numveces;
	 this.operacion = operacion;
	 }
	 //Incrementará numero el numvece indicado
	 public int incrementar (int numveces)	 {
	 for(int i = 0; i < numveces;i++){
	 	numero++;
	 }
	 }
	 //Decrementará numero el numvece indicado
	 public int decrementar (int numveces)	 {
	  for(int i = 0; i < numveces;i++){
	 	numero--;
	 }
	 }
	 public void run() {
	 //Si la operación es “+” se invocará al método incrementar
	 //Si la operación es “-” se invocará al método decrementar
	}

}


public class ej2(){
	public static class main(String[]args){
		new Thread(new HiloSumasRestas("+",100), "HiloSuma1").start();
		new Thread(new HiloSumasRestas("-",100), "HiloResta2").start();
		new Thread(new HiloSumasRestas("+",1), "HiloSuma3").start();
		new Thread(new HiloSumasRestas("-",1), "HiloResta4").start();
	}
}
