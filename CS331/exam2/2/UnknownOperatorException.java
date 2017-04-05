public class UnknownOperatorException extends Exception
{
	public UnknownOperatorException()
	{
		super("The operator provided is unknown or invalid.");
	}

	public UnknownOperatorException(char op)
	{
		super(Character.toString(op) + " is an unknown operation.");
	}

	public UnknownOperatorException(String ex)
	{
		super(ex);
	}
}
