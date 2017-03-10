public class CashPayment extends Payment
{
	public CashPayment(){
		payment = 0;
	}

	public CashPayment(double payment){
		this.payment = payment;
	}

	public void paymentDetails(){
		System.out.println("The current payment amount is: $" + Double.toString(payment) + " in cash.");
	}
}
