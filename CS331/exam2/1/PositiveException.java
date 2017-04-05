public class PositiveException extends Exception
{
	public PositiveException()
	{
		super("N must be positive");
	}

	public PositiveException(String ex)
	{
		super(ex);
	}
}
