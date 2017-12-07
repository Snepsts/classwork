!if ((k == 1) || (k == 2)) j = 2 * k - 1
!if ((k == 3) || (k == 5)) j = 3 * k + 1
!if (k == 4) j = 4 * k - 1
!if ((k == 6) || (k == 7) || (k == 8)) j = k - 2
!Assume all variables are integer type. Discuss the relative merits of the use of these languages for this particular code.

program number3ftran
	Integer :: k, j
	Integer :: is_entered

	print *,"Please enter k: "
	read *,k

	is_entered = 1
	select case (k)
		case (1:2)
			j = 2 * k - 1
		case (3, 5)
			j = 3 * k + 1
		case (4)
			j = 4 * k - 1
		case (6:8)
			j = k - 2
		case default
			 print *, 'No valid k inputted'
			 is_entered = 0
	end select

	if (is_entered == 1) then
		print *,'j = ',j
	end if
end program number3ftran
