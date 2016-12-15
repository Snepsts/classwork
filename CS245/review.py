#first part
if __name__ == '__main__':
	print("This is how you main.")

#second part
def fact(n):
	r = 1;
	if n > 1:
		r = n * fact(n - 1)
	return r

def fib(n):
	if n < 2:
		r = n
	else:
		print(n)
		r = fib(n-1) + fib(n-2)
	return r

def fib2(n):
	prv, cur, nxt = -1, 0, 1
	for i in range(1,n):
		prv, cur, nxt = cur, nxt, cur + nxt
	return nxt

#third part
from math import sqrt
def factor(n):
	factor(n) = []

	for i in range(1, int(sqrt(n)) + 1):
		if n % i == 0:
			factors.append(i)
			factors.append(n // i)

	return sorted(factors)

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

#fourth part
def monteCarloPi(n):
	inside = 0

	for i in range(n):
		x = random.random()
		y = random.random()
		d = math.sqrt

		if d <= 1:
			inside += 1

	return inside/n
