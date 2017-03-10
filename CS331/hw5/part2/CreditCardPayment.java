public class CreditCardPayment extends Payment
{
	private int ex_month, ex_year;
	private long card_num;
	private String name;

	CreditCardPayment(){
		ex_month = 01; ex_year = 57;
		card_num = 1111111111111111L; name = "undefined";
	}

	CreditCardPayment(int ex_month, int ex_year, String name, long card_num){
		this.ex_month = ex_month; this.ex_year = ex_year;
		this.card_num = card_num; this.name = name;
	}

	public void setExpire(int ex_month, int ex_year){
		this.ex_month = ex_month; this.ex_year = ex_year;
	}

	public void setMonth(int ex_month){
		this.ex_month = ex_month;
	}

	public void setYear(int ex_year){
		this.ex_year = ex_year;
	}

	public void setName(String name){
		this.name = name;
	}

	public void setNumber(long card_num){
		this.card_num = card_num;
	}

	public long getNumber(){
		return card_num;
	}

	public String getNumberFormat(){
		String s = Long.toString(card_num);
		String r = s.substring(0,4) + " " + s.substring(4,8) + " " + s.substring(8,12) + " " + s.substring(12,16);
		return r;
	}

	public String getExpire(){
		return Integer.toString(ex_month) + "/" + Integer.toString(ex_year);
	}

	public String getName(){
		return name;
	}

	public int getMonth(){
		return ex_month;
	}

	public int getYear(){
		return ex_year;
	}

	public void paymentDetails(){
		System.out.println("Name on card: " + name);
		System.out.println("Card Number: " + getNumberFormat());
		System.out.println("Expiration date: " + getExpire());
		System.out.println("Payment amount: " + getPayment());
	}
}
