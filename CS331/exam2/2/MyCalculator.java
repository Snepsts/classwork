/*
Write a program that can serve as a simple calculator. This calculator keeps
track of a single number (of type double ) that is called result and that starts
out as 0.0. Each cycle allows the user to repeatedly add, subtract, multiply, or
divide by a second number. The result of one of these operations becomes the new
value of result. The calculation ends when the user enters the letter R for
“result” (either in upper or lowercase). The user is allowed to do another
calculation from the beginning as often as desired. The input format is shown in
the following sample dialogue. If the user enters any operator symbol other than
+ , −, * , or / , then an UnknownOperatorException is thrown and the user is
asked to reenter that line of input. Defining the class UnknownOperatorException
is part of this project.*/

import java.util.Scanner;
import java.util.InputMismatchException;

public class MyCalculator
{
	public static double result;

	public static void addition(double x)
	{
		result += x;
	}

	public static void subtraction(double x)
	{
		result -= x;
	}

	public static void multiplication(double x)
	{
		result *= x;
	}

	public static void division(double x) throws DivideByZeroException
	{
		if(x == 0) //handle any attempt to divide by zero
			throw new DivideByZeroException("You tried to divide by zero, do not do that.");
		result /= x;
	}

	public static void main(String[] args)
	{
		Scanner s = new Scanner(System.in);

		System.out.println("Calculator is on.");

		System.out.println("Result = " + Double.toString(result));

		while(true) //start loop
		{
			try
			{
				char c = s.findInLine(".?").charAt(0); //reads _only_ first char
				//this way we can read both "+3" and "+ 3"

				if(c != '/' && c != '+' && c != '-' && c != '*' && c != 'r' && c != 'R')
					throw new UnknownOperatorException();

				if(c == 'r' || c == 'R') //Exit signal
				{
					System.out.println("Final Result = " + Double.toString(result));
					result = 0; //reset result

					try
					{
						System.out.println("Again? (y/n)");

						char cont = s.next().charAt(0);

						if (cont == 'y' || cont == 'Y')
						{
							System.out.println("Result = " + Double.toString(result));
							continue; //ensure it loops from the beginning
						}
						else
							break; //break out of the while loop
					}

					catch(InputMismatchException ex)
					{
						System.out.println("When it asks for a character, please answer with one. Exiting.");
						break; //break out of the while loop
					}
				}

				double d = s.nextDouble();

				double old = result;

				switch(c)
				{
					case '+':
					 	addition(d);
						break;
					case '-':
						subtraction(d);
						break;
					case '*':
						multiplication(d);
						break;
					case '/':
						division(d);
						break;
					default:
						throw new UnknownOperatorException();
				}

				System.out.println(Double.toString(old) + " " + Character.toString(c) + " " + Double.toString(d) + " = " + Double.toString(result));
				System.out.println("New Result = " + Double.toString(result));
			}

			catch(InputMismatchException ex)
			{
				System.out.println("Please enter an operator and number (+ 5) or r for result.");
				s.nextLine(); //clear the buffer
			}

			catch(NullPointerException ex)
			{ //allows us to catch errors that result from reading _only_ the first char from input
				s.nextLine(); //clear the buffer
			}

			catch(UnknownOperatorException ex)
			{
				System.out.println(ex.getMessage());
				s.nextLine(); //clear the buffer
				System.out.println("Please try again: ");
			}

			catch(DivideByZeroException ex)
			{
				System.out.println(ex.getMessage());
			}
		} //end loop

		System.out.println("Calculator powering off.");

		s.close(); //end scanner
	} //end main
}
