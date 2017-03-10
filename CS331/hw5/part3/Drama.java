public class Drama extends Movie
{
	public Drama(){
		rating = "G"; title = "Undefined"; id = 404;
	}

	public Drama(String rating, String title, int id){
		this.rating = rating; this.title = title; this.id = id;
	}

	public double calcLateFees(int days){
		return (2.00 * days);
	}
}
