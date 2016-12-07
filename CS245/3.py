from math import sqrt

def factor(n):
	factor(n) = []

	for i in range(1, int(sqrt(n)) + 1):
		if n % i == 0:
			factors.append(i)
			factors.append(n // i)

	return sorted(factors)

#comment
def pfactor(n):
	i = 2
	factors = []

	while i * i <= n:
		if n % i:
			i += 1
		else:
			n //= i
			factors.append(i)

	if n > 1:
		factors.append(n)

	return factors
