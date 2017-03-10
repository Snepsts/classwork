/*
Define a class called Odometer that will be used to track fuel and mileage for
an automobile.

The class should have instance variables to track the miles driven and the fuel
efficiency of the vehicle in miles per gallon.

Include a mutator method to reset the odometer to zero miles,

a mutator method to set the fuel efficiency,

a mutator method that accepts miles driven for a trip and adds it to the
odometer’s total,

and an accessor method that returns the number of gallons of gasoline that the
vehicle has consumed since the odometer was last reset.

Use your class with a test program that creates several trips with different
fuel efficiencies. You should decide which variables should be public, if any.

Requirements:
1. Use the data of 200, 500, & 700 miles as the trips driven to get the values
in related to total miles driven, fuel efficiency, and gallons of gasoline
consumed since the odometer was last reset.

2. Upload your program code and the screen shot of the running results.
*/

import java.util.Scanner;

public class Odometer
{
	private double miles;
	private double fuel;

	public Odometer()
	{
		miles = 0; fuel = 25; //25 miles per gallon is the default
	}

	public Odometer(double miles)
	{
		this.miles = miles; fuel = 25; //default to 25
	}

	public Odometer(double miles, double fuel)
	{
		this.miles = miles; this.fuel = fuel;
	}

	public double getMiles()
	{
		return miles;
	}

	public double getFuel()
	{
		return fuel;
	}

	public void reset()
	{
		miles = 0;
	}

	public void setFuel(double fuel)
	{
		this.fuel = fuel;
	}

	public void addMiles(double miles)
	{
		this.miles += miles;
	}

	public double getGallons()
	{
		return miles/fuel;
	}

	public static void showchoices()
	{
		System.out.println("1 - Add miles");
		System.out.println("2 - See gallons consumed");
		System.out.println("3 - Change mpg (fuel efficiency)");
		System.out.println("4 - View current information");
		System.out.println("5 - Reset Odometer");
		System.out.println("6 - View this list again");
		System.out.println("7 - Quit");
	}

	public static void main(String[] args)
	{
		boolean whilevar = true;
		int choice;
		Scanner s = new Scanner(System.in);
		Odometer od = new Odometer(200);
		System.out.print("Current miles: ");
		System.out.println(od.getMiles());

		showchoices();

		while(whilevar == true)
		{
			choice = s.nextInt();
			switch(choice)
			{
				case 1:
					System.out.println("Please enter the amount you'd like to add: ");
					od.addMiles(s.nextDouble());
					break;
				case 2:
					System.out.print("Gallons consumed: ");
					System.out.println(od.getGallons());
					break;
				case 3:
					System.out.print("Please enter new mpg (fuel efficiency): ");
					od.setFuel(s.nextDouble());
					break;
				case 4:
					System.out.print("Current miles: ");
					System.out.println(od.getMiles());
					System.out.print("Current mpg (fuel efficiency): ");
					System.out.println(od.getFuel());
					break;
				case 5:
					od.reset();
					System.out.println("Odometer reset!");
					break;
				case 6:
					showchoices();
					break;
				default:
					whilevar = false;
					break;
			}
		}

		System.out.println("Have a good day!");
	}
}
