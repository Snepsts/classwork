/*
A method that returns a special error code is usually better accomplished throwing an
exception instead. The following class maintains an account balance.
class Account
{
	private double balance;
	public Account()
	{
		balance = 0;
	}
	public Account( double initialDeposit)
	{
		balance = initialDeposit;
	}
	public double getBalance()
	{
		return balance;
	}
	// returns new balance or -1 if error
	public double deposit( double amount)
	{
		if (amount > 0)
			balance += amount;
		else
			return -1;// Code indicating error
		return balance;
	}
	// returns new balance or -1 if invalid amount
	public double withdraw(double amount)
	{
		if ((amount > balance) || (amount < 0))
			return -1;
		else
			balance -= amount;
		return balance;
	}
}
Rewrite the class so that it throws appropriate exceptions instead of returning −1
as an error code. Write test code that attempts to withdraw and deposit invalid
amounts and catches the exceptions that are thrown.
*/

import java.util.Scanner;
import java.util.InputMismatchException;

class Account
{
	private double balance;

	public Account()
	{
		balance = 0;
	}

	public Account(double initialDeposit) throws NegativeNumberException
	{
		if(initialDeposit < 0)
			throw new NegativeNumberException(initialDeposit);
		balance = initialDeposit;
	}

	public double getBalance()
	{
		return balance;
	}

	//throws NegativeNumberException in case of invalid amount
	public double deposit(double amount) throws NegativeNumberException
	{
		if (amount > 0)
			balance += amount;
		else
			throw new NegativeNumberException(amount); //code indicating error
		return balance;
	}

	//throws NegativeNumberException in case of invalid amount
	public double withdraw(double amount) throws NegativeNumberException, InvalidInputException
	{
		if (amount > balance)
			throw new InvalidInputException("Cannot withdraw more than you have.");
		else if (amount < 0)
			throw new NegativeNumberException(amount);
		else
			balance -= amount;
		return balance;
	}

	public static void printChoices()
	{
		System.out.println("d = deposit");
		System.out.println("w = withdraw");
		System.out.println("g = get the balance");
		System.out.println("e = exit program");
	}

	public static void main(String[] args)
	{
		Scanner s = new Scanner(System.in);

		Account a;

		while(true)
		{
			try
			{
				System.out.print("Please enter a value for the initialDeposit: ");

				double d = s.nextDouble();

				Account a2 = new Account(d); //test the explicit constructor

				a = a2; //store a2's value in a so it can go on after this block

				break; //break out of the while loop
			}

			catch(InputMismatchException ex)
			{
				System.out.println("Invalid input; please try again.");
				s.nextLine();
			}

			catch(NegativeNumberException ex)
			{
				System.out.println(ex);
				System.out.println("Please try again.");
			}
		} //end while

		printChoices(); //list choices once

		while(true)
		{
			try
			{
				double d;
				boolean end = false; //flag for ending the program
				System.out.print("Please enter your choice: ");

				char c = s.next().charAt(0);

				if(c != 'd' && c != 'w' && c != 'g' && c != 'e')
					throw new InvalidInputException(c);

				switch(c)
				{
					case 'd':
						System.out.print("Please enter the amount you would like to deposit: ");
						d = s.nextDouble();
						a.deposit(d);
						break;
					case 'w':
						System.out.print("Please enter the amount you would like to withdraw: ");
						d = s.nextDouble();
						a.withdraw(d);
						break;
					case 'g':
						System.out.println("Current Balance: " + Double.toString(a.getBalance()));
						break;
					default: //e and all other cases that slip past
						end = true;
						break;
				}

				if(end)
					break; //break out of the while loop
			}

			catch(InputMismatchException ex)
			{
				System.out.println("Invalid input; please try again.");
				s.nextLine();
			}

			catch(NegativeNumberException ex)
			{
				System.out.println(ex);
				System.out.println("Please try again.");
			}

			catch(InvalidInputException ex)
			{
				System.out.println(ex);
				s.nextLine(); //clear the buffer
				System.out.println("Please try again: ");
				printChoices(); //relist choices incase user needs to see them again
			}
		} //end while

		s.close(); //end scanner
	} //end main
}
