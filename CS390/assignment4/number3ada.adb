--if ((k == 1) || (k == 2)) j = 2 * k - 1
--if ((k == 3) || (k == 5)) j = 3 * k + 1
--if (k == 4) j = 4 * k - 1
--if ((k == 6) || (k == 7) || (k == 8)) j = k - 2
--Assume all variables are integer type. Discuss the relative merits of the use of these languages for this particular code.

with Ada.Text_IO; use Ada.Text_IO;
procedure number3ada is
k, j : Integer;
is_entered : Boolean;
begin
	Put("Please enter a k: ");
	k := Integer'Value(Get_Line);
	is_entered := true;

	case k is
		when 1 | 2 => j := 2 * k - 1;
		when 3 | 5 => j := 3 * k + 1;
		when 4 => j := 4 * k - 1;
		when 6 | 7 | 8 => j := k - 2;
		when others => Put_Line("No valid k inputted."); is_entered := false;
	end case;

	if is_entered then
		Put("J = ");
		Put(Integer'Image(j));
		New_Line(1);
	end if;
end number3ada;
