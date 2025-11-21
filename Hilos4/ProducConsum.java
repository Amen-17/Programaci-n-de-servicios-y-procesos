import java.util.concurrent.ArrayBlockingQueue;
import java.util.Random;

public class ProducConsum{
	public static void main(String[] args) {
		Cola cola = new Cola();  

    	Consumidor c1 = new Consumidor(cola,"C1");
    	Consumidor c2 = new Consumidor(cola,"C2");
    	Productor p = new Productor(cola);

    	c1.start();
    	c2.start();
    	p.start();
    	try {
			c1.join();
			c2.join();
			p.join();
    	} catch (InterruptedException e) {}
	}
}

class Productor extends Thread{
	Cola c;

	public Productor (Cola c){
		this.c = c;
	}
	public void run(){
		int num;
		try {
			for (int i = 1; i <= 30 i++) {
				num = obtenerAleatorio();
			    c.ponerDatos(num);
			    System.out.println("P1: Producido: " + num);
			}
			c.ponerDatos(13);
			c.ponerDatos(13);
		} catch (InterruptedException e) {}
	}
	
	public int obtenerAleatorio(){
		Random r = new Random();
		return (r.nextInt(10)+1);
	}
}

class Consumidor extends Thread{
	int num, operacion=0;
	Cola c;
	String nombre;

	public Consumidor (Cola c, String nombre){
		this.c = c;
		this.nombre = nombre;
	}
	public void run(){
			try {
				while (true) {
				this.sleep(50);
					num = c.comprobarDatos();
						if ((nombre.equals("C1") && num % 2 == 0) || (nombre.equals("C2") && num % 2 != 0) || (num == 13)) {
							num = c.cogerDatos();
							if(num == 13){
								System.out.println("Break" + num);
								break;
							}else{
								System.out.println(nombre+": Consumido: " + num);
								operacion += num;
							}
						}else{System.out.println("No pasas");}
				}
				this.sleep(1000);
				System.out.println(nombre+": Resultado: "+operacion);
			} catch (Exception e) {}
	}
}

class Cola{

	static ArrayBlockingQueue<Integer> cola = new ArrayBlockingQueue<>(5);
	
	void ponerDatos(int i) throws InterruptedException{
		cola.put(i);
	}
	
 	int cogerDatos() throws InterruptedException{
		return cola.take();
	}
	
	synchronized int comprobarDatos() throws NullPointerException{
		return cola.peek();
	}
}
