#include <iostream>

int fun(int *k); //could also do by reference like: int fun(int &k);
                 //that way, the call would be fun(i); instead of fun(&i);
int main()
{
	int i = 10, j = 10, sum1, sum2;
	sum1 = (i / 2) + fun(&i);
	sum2 = fun(&j) + (j / 2);

	std::cout << "sum1 = " << sum1 << '\n';
	std::cout << "sum2 = " << sum2 << '\n';

	return 0;
}

int fun(int *k)
{
	*k += 4;

	return 3 * (*k) - 1;
}
