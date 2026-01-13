package tres;

import java.io.Serializable;

public class Factura implements Serializable{
    private int num;
    private String fecha;
    private double importe;
    private String tipIva;
    private double iva;
    private double total;

    public Factura(int num, String fecha, double importe, String tip) {
        super();
        this.num = num;
        this.fecha = fecha;
        this.importe = importe;
        this.tipIva = tip;
    }

    public int getNum() {
        return num;
    }

    public String getFecha() {
        return fecha;
    }

    public String getTipIva() {
        return tipIva;
    }

    public double getImporte() {
        return importe;
    }

    public double getIva() {
        return iva;
    }

    public double getTotal() {
        return total;
    }

    public void setNum(int n) {
        num = n;
    }

    public void setFecha(String f) {
        fecha = f;
    }

    public void setTipIva(String t) {
        tipIva = t;
    }

    public void setImporte(double i) {
        importe = i;
    }

    public void setIva(double i) {
        iva = i;
    }

    public void setTotal(double t) {
        total = t;
    }

}
