public class Action extends Movie
{
	public Action(){
		rating = "PG-13"; title = "Undefined"; id = 404;
	}

	public Action(String rating, String title, int id){
		this.rating = rating; this.title = title; this.id = id;
	}

	public double calcLateFees(int days){
		return (3.00 * days);
	}
}
