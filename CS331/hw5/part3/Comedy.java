public class Comedy extends Movie
{
	public Comedy(){
		rating = "PG"; title = "Undefined"; id = 404;
	}

	public Comedy(String rating, String title, int id){
		this.rating = rating; this.title = title; this.id = id;
	}

	public double calcLateFees(int days){
		return (2.50 * days);
	}
}
