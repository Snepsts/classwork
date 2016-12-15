/* Author: Michael Ranciglio
School: Southeast Missouri State
Class: Computer Science III
*/

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "employee.h"
#include "salariedEmployee.h"
#include "hourlyEmployee.h"

std::ostream& operator<<(std::ostream& out, const employee& emp){
	out << emp.getName() << ": " << emp.getAge() << " " << emp.pay();
	return out;
}

int main(){
	std::vector<std::shared_ptr<employee>> emps;

	emps.emplace_back(std::make_shared<hourlyEmployee>("Michael",  19, 28.43, 7.65));
	emps.emplace_back(std::make_shared<hourlyEmployee>("Derek",  21, 18.72, 11.43));
	emps.emplace_back(std::make_shared<hourlyEmployee>("Will",  22, 31.5, 15.00));
    emps.emplace_back(std::make_shared<salariedEmployee>("Dolphin", 37, 50000));
	emps.emplace_back(std::make_shared<salariedEmployee>("Dolphin2", 42, 84000));

	for(auto e : emps){
		std::cout << *e << '\n';
	}

	for (auto e : emps){
		std::cout << e.use_count() << '\n';
	}

	for (auto& e : emps){
		std::cout << e.use_count() << '\n';
	}

	return 0;
}

/* Output:
Michael: 19 217.49
Derek: 21 213.97
Will: 22 472.5
Dolphin: 37 4166.67
Dolphin2: 42 7000
2
2
2
2
2
1
1
1
1
1

Explanation:
The use_count refers to how many uses/counts of the object exist
Since there is two when we use for each normally vs one when we use
it with a memory (&) operator must mean that it is referring to the
copy made when there is no & operator, so there are 2 in use vs
the memory being passed means there is only 1 in use.
*/
