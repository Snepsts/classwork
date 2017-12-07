=begin
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
=end

k_string = ""
k = 0
is_entered = true

puts "Please enter a k"
k_string = gets

k = k_string.to_i()
j = 0

case k
when 1..2
	j = 2 * k - 1
when 3, 5
	j = 3 * k + 1
when 4
	j = 4 * k - 1
when 6..8
	j = k - 2
else
	puts "Invalid k entered"
	is_entered = false
end

if is_entered then
	puts "j = #{j}"
end
