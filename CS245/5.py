class Rational
	def __init__(self, num, den):
		self.num = num
		self.den = den

	def __add__(self, r):
		n = self.num * r.den + self.den * r.num
		d = self.den * r.den
		return Rational(n, d)

	def __mul__(self, r):
		n = self.num * r.num
		d = self.den * r.den
		return Rational(n, d)

	def __str__(self):
		return str(self.num) + "/" + str(self.den)

	def __eq__(self, r):
		first = self.num * r.den
		second = r.num * self.den
		return first == second
