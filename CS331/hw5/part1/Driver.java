import java.util.Scanner;

public class Driver
{
	public static void main(String[] args)
	{
		//create a truck
		Truck t = new Truck();

		//test our initial values
		System.out.println(t.getLoad());
		System.out.println(t.getTow());
		System.out.println(t.getCylinders());
		System.out.println(t.getOwner());
		System.out.println(t.getMan());

		//test explicit constructor
		Person p = new Person("John");
		System.out.println(p.getName());

		//test setName
		p.setName("Jarold");

		//test other explicit constructor
		Person p2 = new Person(p);

		//test output
		if(p.equals(p2))
			System.out.println("The two people are the same");

		//test setting new values
		t.setLoad(4.453361);
		t.setTow(10000);
		t.setCylinders(6);
		t.setOwner(p);
		t.setMan("Ford");

		//test our new values
		System.out.println(t.getLoad());
		System.out.println(t.getTow());
		System.out.println(t.getCylinders());
		System.out.println(t.getOwner());
		System.out.println(t.getMan());
	}
}
