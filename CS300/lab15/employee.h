#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__

#include <string>
#include <iostream>

using std::string;

class employee{
public:
	string getName() const {
		return name;
	}

	int getAge() const {
		return age;
	}

	void setName(const string& name){
		this->name = name; //also to be (*this).name
	}

	void setAge(const int& age){
		this->age = age;
	}

	virtual double pay() const = 0;

	friend std::ostream& operator<<(std::ostream& out, const employee& emp);
protected:
	employee(){
		name = "";
		age = -1;
	}

	string name;
	int age;
};

#endif
