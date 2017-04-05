public class NumTooBigException extends Exception
{
	public NumTooBigException()
	{
		super("The number you attempted to enter is too large.");
	}

	public NumTooBigException(String ex)
	{
		super(ex);
	}
}
