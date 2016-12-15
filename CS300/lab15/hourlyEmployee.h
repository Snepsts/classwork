#ifndef __HOURLY_EMPLOYEE_H__
#define __HOURLY_EMPLOYEE_H__

#include <string>
#include "employee.h"

class hourlyEmployee : public employee{
public:
	hourlyEmployee(){
		rate = 0; hours = 0;
	}

	hourlyEmployee(const std::string& name, const int& age, const double& rate, const double& hours){
		this->name = name; this->age = age; this->rate = rate; this->hours = hours;
	}

	void setHours(const double& hours){
		this->hours = hours;
	}

	void setRate(const double& rate){
		this->rate = rate;
	}

	double pay() const { return (hours * rate); }
private:
	double rate, hours;
};

#endif
