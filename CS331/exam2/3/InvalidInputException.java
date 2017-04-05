public class InvalidInputException extends Exception
{
	public InvalidInputException()
	{
		super("The input provided was invalid.");
	}

	public InvalidInputException(char op)
	{
		super(Character.toString(op) + " is invalid.");
	}

	public InvalidInputException(String ex)
	{
		super(ex);
	}
}
