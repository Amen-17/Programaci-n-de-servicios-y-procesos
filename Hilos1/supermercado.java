import java.util.ArrayList;

public class supermercado{
	public static void main(String[] args)
	{
		int cont = 0;
		String nombreCliente;
		ArrayList<caja> mercado = new ArrayList<caja>();
		caja c1 = new caja("Caja 1");
		caja c2 = new caja("Caja 2");
		caja c3 = new caja("Caja 3");
		mercado.add(c1);
		mercado.add(c2);
		mercado.add(c3);
		for (int i = 0; i < 8; i++){
			caja c = null;
			for (int z = 0 ; z < mercado.size(); z++){
				if(mercado.get(z).isEmpty()){
					c = mercado.get(z);
				}
			}
			if (c == null){
				c = mercado.get(cont);
				if(cont == mercado.size()-1){
					cont = 0;
				}else{
					cont++;
				}
			}
			nombreCliente = "Cliente "+(i+1);
			cliente cl1 = new cliente(nombreCliente, c);
			cl1.start();
		}
		System.out.println("Supermercado cerrado.");
	}
}

class cliente extends Thread{
	private String nombre;
	private caja caja;
	
	public cliente(String nom, caja c){
		nombre = nom;
		caja = c;
	}
	
	public void run(){
		caja.pagar(this);
	}
	
	public String getNombre(){
		return nombre;	 
	}
}

class caja {
	private String nombre;
	private boolean vacia;
	
	public caja(String nom){
		nombre = nom;
	}
	
	synchronized public void pagar(cliente c){
		vacia = false;
		System.out.println(this.nombre + " atendiendo al " + c.getNombre());
		try{
		c.sleep(5000);
		}catch(InterruptedException e){}
		System.out.println(this.nombre + " terminó con " + c.getNombre());
		vacia = true;
	}
	
	public boolean isEmpty(){
		return vacia;
	}
}
