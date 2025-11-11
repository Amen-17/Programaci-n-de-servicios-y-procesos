class HiloSumasRestas implements Runnable {
	private static int numero=1000;
	int numveces;
	String operacion;
	
	 //Constructor de la clase
	 public HiloSumasRestas (String operacion,int numveces){
	 this.numveces = numveces;
	 this.operacion = operacion;
	 }
	 
	 //Incrementará numero el numvece indicado
	 public void incrementar (int numveces)	 {
		 for(int i = 0; i < numveces;i++){
		 	numero++;
		 }
	 }
	 //Decrementará numero el numvece indicado
	 public void decrementar (int numveces)	 {
		 for(int i = 0; i < numveces;i++){
		 	numero--;
		 }
	 }
	 public void run() {
		if(operacion.equals("+")){
			incrementar(numveces);
		}else{
			decrementar(numveces);
		}
		System.out.println(Thread.currentThread().getName() + " número: " + numero);
	}
}


public class ej2{
	public static void main(String[]args) throws InterruptedException{
		Thread t1 = new Thread(new HiloSumasRestas("+",100), "HiloSuma1");
		t1.start();
		t1.join();
		Thread t2 = new Thread(new HiloSumasRestas("-",100), "HiloResta2");
		t2.start();
		t2.join();
		Thread t3 = new Thread(new HiloSumasRestas("+",1), "HiloSuma3");
		t3.start();
		t3.join();
		Thread t4 = new Thread(new HiloSumasRestas("-",1), "HiloResta4");
		t4.start();
	}
}
