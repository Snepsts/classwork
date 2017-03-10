import java.util.Scanner;

public class Driver
{
	public static void main(String[] args)
	{
		Scanner s = new Scanner(System.in);

		//default constructors
		CreditCardPayment ccp = new CreditCardPayment();
		CashPayment cp = new CashPayment();

		//test accessors for creditcard
		System.out.println("Name: " + ccp.getName());
		System.out.println("Card Number: " + Long.toString(ccp.getNumber()));
		System.out.println("Expiration Date: " + Integer.toString(ccp.getMonth())
		+ "/" + Integer.toString(ccp.getYear()));
		System.out.println("Payment amount: " + Double.toString(ccp.getPayment()));

		//test mutator for payment
		System.out.print("Please enter the amount you'd like to pay: ");
		ccp.setPayment(s.nextDouble());
		System.out.print("Please enter the amount you'd like to pay (in cash): ");
		cp.setPayment(s.nextDouble());

		//test accessor for payment
		System.out.println("The amount you entered was: " + cp.getPayment());

		//test paymentDetails
		cp.paymentDetails();

		System.out.print("Please enter the amount you'd like to pay (in cash): ");

		CashPayment cp2 = new CashPayment(s.nextDouble()); //test explicit

		cp2.paymentDetails();

		//test mutators for creditcard
		System.out.print("Please enter the expiration month: ");
		ccp.setMonth(s.nextInt());
		System.out.print("Please enter the expiration year: ");
		ccp.setYear(s.nextInt());
		System.out.print("Please enter the card holder's name: ");
		s.nextLine(); //consume current \n
		ccp.setName(s.nextLine());
		System.out.print("Please enter the card number: ");
		ccp.setNumber(s.nextLong());

		//test paymentDetails, getNumberFormat and getExpire
		ccp.paymentDetails();

		int month, year;
		long number;
		double payment;

		System.out.print("Please enter the payment amount: ");
		payment = s.nextDouble();
		System.out.print("Please enter the card number: ");
		number = s.nextLong();
		System.out.print("Please enter the expiration month: ");
		month = s.nextInt();
		System.out.print("Please enter the expiration year: ");
		year = s.nextInt();
		System.out.print("Please enter the cardholder name: ");
		s.nextLine(); //consume current \n
		String name = s.nextLine();

		CreditCardPayment ccp2 = new CreditCardPayment(month, year, name, number);
		ccp2.setPayment(payment);

	}
}
