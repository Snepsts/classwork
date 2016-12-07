def monteCarloPi(n):
	inside = 0

	for i in range(n):
		x = random.random()
		y = random.random()
		d = math.sqrt

		if d <= 1:
			inside += 1

	return inside/n
