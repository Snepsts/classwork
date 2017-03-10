/*CS 331 homework project

Due: Friday, 03/10

1. Create a class called Vehicle that has:
 - the manufacturer’s name (type String ),
 - number of cylinders in the engine (type int )
 - and owner (type Person given next).

Then, create a class called Truck that is derived from Vehicle and has the
following additional properties:
the load capacity in tons (type double since it may contain a fractional part)
and towing capacity in pounds (type int ).

Be sure your class has a reasonable complement of constructors,
accessor and mutator methods, and suitably defined equals and toString methods.
Write a program to test all your methods. The definition of the class Person
follows. Completing the definitions of the methods is part of this programming
project. */

public class Vehicle
{
	protected String m_name; //manufacturer name
	protected int cylinders; //number of cylinders
	protected Person owner; //owner of vehicle

	public Vehicle(){
		m_name = "undefined"; cylinders = 4; owner = new Person();
	}

	public String getMan(){
		return m_name;
	}

	public int getCylinders(){
		return cylinders;
	}

	public Person getOwner(){
		return owner;
	}

	public void setMan(String m_name){
		this.m_name = m_name;
	}

	public void setCylinders(int cylinders){
		this.cylinders = cylinders;
	}

	public void setOwner(Person owner){
		this.owner.setName(owner.toString());
	}
}
