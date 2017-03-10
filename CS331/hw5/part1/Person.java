public class Person
{
	private String name;

	public Person(){
		name = "undefined";
	}

	public Person(String theName){
		name = theName;
	}

	public Person(Person theObject){
		this.name = theObject.name;
	}

	public String getName(){
		return name;
	}

	public void setName(String theName){
		name = theName;
	}

	public String toString(){
		return name;
	}

	public boolean equals(Person other){
		return (name.equals(other.name));
	}
}
