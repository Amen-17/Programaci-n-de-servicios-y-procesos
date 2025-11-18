public class Gimnasio{
	public static void main(String[] args) { 
		Sala a = new Sala();
		for(int i = 0; i< 20;i++){
			Cliente c = new Cliente(i,a);
			c.start();
		}
	}
}

class Cliente extends Thread{
	private int num;
	private Sala sala;
	
	public Cliente(int n, Sala s){
		num = n;
		sala = s;
	}
	
	public void run(){
		sala.entrarSala(this);
		try {
			this.sleep(2000);
		} catch (InterruptedException e) { }
		sala.salirSala(this);
	}
	
	public int getID(){
		return num;
	}
}

class Sala{

	int aforo = 0;
	void aumentarAforo(){aforo++;}
	void disminuirAforo(){aforo--;}
	
	synchronized void entrarSala(Cliente c){
		while(aforo == 5){
			 try {
    	          wait();
    	    } catch (InterruptedException e) { }
		}
		aumentarAforo();
		System.out.println("El cliente "+c.getID()+" entró a la sala");
	} 
	
	synchronized void salirSala(Cliente c){
		System.out.println("El cliente "+c.getID()+" salió a la sala");
		disminuirAforo();
		notifyAll();
	}
}
