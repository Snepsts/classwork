'''
3. Rewrite the following code segment using a multiple-selection statement in the following languages:
if ((k == 1) || (k == 2)) j = 2 * k - 1
if ((k == 3) || (k == 5)) j = 3 * k + 1
if (k == 4) j = 4 * k - 1
if ((k == 6) || (k == 7) || (k == 8)) j = k - 2
a. Fortran 95 (you’ll probably need to look this one up)
b. Ada
c. C, C++, Java, or C#
d. Python
e. Ruby
Assume all variables are integer type. Discuss the relative merits of the use of these languages for this particular code.
'''
#using python3
def main():
	k = int(input("Please enter a k: "))
	j = 0
	is_entered = True

	if (k == 1 or k == 2):
		j = 2 * k - 1
	elif (k == 3 or k == 5):
		j = 3 * k + 1
	elif (k == 4):
		j = 4 * k - 1
	elif (k == 6 or k == 7 or k == 8):
		j = k - 2
	else:
		print("Invalid k was entered")
		is_entered = False

	if (is_entered):
		print("j =", j)

if __name__ == '__main__':
	main()
