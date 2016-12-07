def fact(n):
	r = 1;
	if n > 1:
		r = n * fact(n - 1)
	return r;

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

if __name__ == '__main__':
	n = 100
	#print('n = ', fact(n))
	print('n = ', fib(n)) #takes forever
	#print('n = ', fib2(n)) #much faster

'''
or we can do this
def main():
	n = 100;
	print('n = ', fact(n))

main()
'''
