public class number2
{
	static int fun(int k)
	{
		k += 4;

		return 3 * k - 1;
	}

	public static void Main(string[] args)
	{
		int i = 10, j = 10, sum1, sum2;
		sum1 = (i / 2) + fun(i);
		sum2 = fun(j) + (j / 2);

		System.Console.WriteLine("sum1 = " + sum1);
		System.Console.WriteLine("sum2 = " + sum2);
	}
}
