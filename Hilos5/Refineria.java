import java.util.Random;

public class Refineria{
	public static void main(String[] args){
		Cisterna c = new Cisterna();
			Productor p = new Productor(c);
			Camion c1 = new Camion(1,c);
			Camion c2 = new Camion(2,c);
			Camion c3 = new Camion(3,c);
			p.start();
			c1.start();
			c2.start();
			c3.start();
		
		try{
			p.join();
			c1.join();
			c2.join();
			c3.join();
		}catch(InterruptedException e){}
		System.out.println("Operaciones realizadas.");
	}
}

class Camion extends Thread{
	private int deposito = 0;
	private Cisterna c;
	private int nombre;
	
	public Camion(int i, Cisterna c){
		this.nombre = i;
		this.c = c;
	}
	
	public void run(){
		int carga;
		for(int i = 0 ; i < 5; i++){
			try{
				this.sleep(250);
				synchronized(c){
					while(!c.isFilled()){
						c.wait();
					}
					carga = c.descargaDeposito();
					deposito += carga;
					System.out.println("Camión "+nombre+" carga "+carga+" litros.");
				}
			}catch(InterruptedException e){}
			synchronized(c){
				c.notifyAll();
			}
		}
		System.out.println("El camión "+nombre+" sale con "+deposito+" litros.");
	}
}

class Productor extends Thread{
	
	private Cisterna c;
	
	public Productor(Cisterna c){
		this.c = c;
	}
	
	public void run(){
		for(int i = 0 ; i < 15; i++){
			llenarDeposito();
			synchronized(c){
				c.notifyAll();
				try{
					while(c.isFilled()){
						c.wait();
					}
				}catch(InterruptedException e){}
			}
		}
	}
	
	void llenarDeposito(){
		int cantidad = obtenerAleatorio();
		c.llenadoDeposito(cantidad);
		System.out.println("Productor llena "+cantidad+" litros de combustible.");
	}
	
	int obtenerAleatorio(){
		Random r = new Random();
		return r.nextInt(1000);
	}
}

class Cisterna{
	
	private int deposito;
	private boolean rellenado = false;
	
	public void llenadoDeposito(int cantidad){
		deposito = cantidad;
		rellenado = true;
	}
	
	synchronized public int descargaDeposito(){
		rellenado = false;
		return deposito;
	}
	
	public boolean isFilled(){
		return rellenado;
	}


}
