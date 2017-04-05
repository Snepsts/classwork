public class DivideByZeroException extends Exception
{
	public DivideByZeroException()
	{
		super("Division by zero detected.");
	}

	public DivideByZeroException(String ex)
	{
		super(ex);
	}
}
