public class NegativeNumberException extends Exception
{
	public NegativeNumberException()
	{
		super("You entered a negative number, that is unacceptable.");
	}

	public NegativeNumberException(String ex)
	{
		super(ex);
	}

	public NegativeNumberException(double d)
	{
		super(Double.toString(d) + " is a negative number where a positive number was expected.");
	}
}
