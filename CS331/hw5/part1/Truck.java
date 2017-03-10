/*
Then, create a class called Truck that is derived from Vehicle and has the
following additional properties:
the load capacity in tons (type double since it may contain a fractional part)
and towing capacity in pounds (type int ).
*/
public class Truck extends Vehicle
{
	private double load_c; //load capacity in tons
	private int tow_c; //towing capacity in pounds

	public Truck(){
		tow_c = 100; load_c = 5.32;
	}

	public int getTow(){
		return tow_c;
	}

	public double getLoad(){
		return load_c;
	}

	public void setTow(int tow_c){
		this.tow_c = tow_c;
	}

	public void setLoad(double load_c){
		this.load_c = load_c;
	}
}
