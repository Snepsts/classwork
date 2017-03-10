/*
4. Extend the previous problem with a Rental class. This class should store a Movie
that is rented, an integer representing the ID of the customer that rented the
movie, and an integer indicating how many days late the movie is. Add a method
that calculates the late fees for the rental. In your main method, create an array of
type Rental filled with sample data of all types of movies. Then, create a method
named lateFeesOwed that iterates through the array and returns the total amount
of late fees that are outstanding.
*/

public class Rental
{
	Movie rented;
	int c_id; //customer ID
	int late; //days late

	public Rental(){
		c_id = 1001; late = 0; rented = new Movie();
	}

	public Rental(int c_id, int late, String rating, String title, int id){
		this.c_id = c_id; this.late = late; rented = new Movie(rating, title, id);
	}

	public int getID(){
		return c_id;
	}

	public int getLate(){
		return late;
	}

	public void setID(int c_id){
		this.c_id = c_id;
	}

	public void setLate(int late){
		this.late = late;
	}

	public double calcLateFees(){
		return rented.calcLateFees(late);
	}

	public static double lateFeesOwed(Rental[] r){
		double d = 0;

		for(int i = 0; i < r.length; i++)
			d += r[i].calcLateFees();

		return d;
	}

	public static void main(String[] args)
	{
		Rental[] r = new Rental[20];

		for(int i = 0; i < r.length; i++)
			r[i] = new Rental(1010, 7, "R", "Dolphins", 2354); //make each rental a week late

		System.out.println(Double.toString(lateFeesOwed(r))); //should print out 280
	}
}
