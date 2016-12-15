#ifndef __SALARIED_EMPLOYEE_H__
#define __SALARIED_EMPLOYEE_H__

#include <string>
#include "employee.h"

class salariedEmployee : public employee{
public:
	salariedEmployee(){
		salary = 0;
	}

	salariedEmployee(const std::string& name, const int& age, const double& salary){
		this->name = name; this->age = age; this->salary = salary;
	}

	void setSalary(const double& salary){
		this->salary = salary;
	}

	double pay() const { return (salary / 12); }
private:
	double salary;
};

#endif
