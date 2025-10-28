class HiloParImpar implements Runnable {
	int tipo; 
	public void run() {
		if(Thread.currentThread().getName()=="Hilo 1"){tipo = 1;}else{tipo = 2;}
		if(tipo == 1){
			for (int i = 0; i <= 100; i += 2){
				System.out.println("HILO xx generando número par " + i);
			}
		}else{
			for (int i = 101; i <= 200; i += 2){
				System.out.println("HILO yy generando número impar " + i);
			}
		}
	}
}

public class ej1 {
	public static void main(String[]args){
		new Thread(new HiloParImpar(), "Hilo 1").start();
		new Thread(new HiloParImpar(), "Hilo 2").start();
	}
}
