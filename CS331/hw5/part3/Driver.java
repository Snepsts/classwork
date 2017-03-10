public class Driver
{
	public static void main(String[] args)
	{
		Action a = new Action(); //test defaults
		Comedy c = new Comedy();
		Drama d = new Drama("PG", "All My Worries", 1234); //test explicit

		//test mutators
		a.setRating("R");
		a.setTitle("Die Hard");
		a.setID(1234);

		c.setRating("PG");
		c.setTitle("Comedy Movie Title");
		c.setID(1264);

		//test accessors
		System.out.println("Action movie: ");
		System.out.println("Title: " + a.getTitle());
		System.out.println("Rating: " + a.getRating());
		System.out.println("ID: " + Integer.toString(a.getID()));

		System.out.println("Comedy movie: ");
		System.out.println("Title: " + c.getTitle());
		System.out.println("Rating: " + c.getRating());
		System.out.println("ID: " + Integer.toString(c.getID()));

		System.out.println("Drama movie: ");
		System.out.println("Title: " + d.getTitle());
		System.out.println("Rating: " + d.getRating());
		System.out.println("ID: " + Integer.toString(d.getID()));

		//test equals
		if(a.equals(d))
			System.out.println("The two movies are the same!");

		//Test calcLateFees
		System.out.println("Here are the late fees for each movie at a week:");
		System.out.println(a.getTitle() + " rated " + a.getRating() + " has a late fee of "
		+ Double.toString(a.calcLateFees(7)));
		System.out.println(c.getTitle() + " rated " + c.getRating() + " has a late fee of "
		+ Double.toString(c.calcLateFees(7)));
		System.out.println(d.getTitle() + " rated " + d.getRating() + " has a late fee of "
		+ Double.toString(d.calcLateFees(7)));
	}
}
