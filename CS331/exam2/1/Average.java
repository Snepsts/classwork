/* 1.
Write a program that calculates the average of N integers. The program should
prompt the user to enter the value for N and then afterward must enter all N
numbers. If the user enters a non-positive value for N , then an exception
should be thrown (and caught) with the message “ N must be positive.” If there
is any exception as the user is entering the N numbers, an error message should
be displayed, and the user prompted to enter the number again. */

import java.util.Scanner;
import java.util.InputMismatchException;

public class Average
{
	private int n;

	public int getN(){
		return n;
	}

	public void setN(int n){
		this.n = n;
	}

	public static void main(String[] args)
	{
		int n;
		Scanner s = new Scanner(System.in);

		while(true)
		{
			try
			{
				System.out.print("Please enter an int N: ");
				n = s.nextInt();

				if(n < 0)
					throw new PositiveException();

				break; //break out of while
			}

			catch(PositiveException ex)
			{
				System.out.println(ex.getMessage());
			}

			catch(InputMismatchException ex)
			{
				System.out.println("Please enter an integer.");
				s.nextLine(); //clear the buffer
			}

		} //end while

		int i = 0; //for the for loop to retain which number it's on.
		int total = 0; //the total of the numbers in order to calculate the average

		while(true)
		{
			try
			{
				for(; i < n; i++)
				{
					System.out.print("Please enter a new integer: ");
					int a = s.nextInt();

					/* The following statement ensures there's no possible way
					that we can hit the 32 bit int limit. That is, if they
					cannot enter 2147483647 / n n times, they cannot hit it. */
					if(a > 2147483647 / n)
						throw new NumTooBigException();

					total += a;
				}

				break; //break out of while loop
			}

			catch(InputMismatchException ex)
			{
				System.out.println("Please enter an integer.");
				s.nextLine(); //clear the buffer
			}

			catch(NumTooBigException ex)
			{
				System.out.println(ex.getMessage());
			}
		} //end while

		total /= n;

		System.out.println("The average of the numbers you entered is: " + Integer.toString(total));

		s.close(); //end scanner
	}
}
