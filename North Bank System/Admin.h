#pragma once
#include "Employee.h"

class Admin : public Employee {
private:


public:
	//Constructors
	Admin() : Employee() {}
	Admin(int id, string name, string password, double salary) : Employee(id, name, password, salary) {}
	//Methods
	/*void display() {
		Employee::display();
	}*/


	void addEmployee(Employee& employee) {
		allEmployees.push_back(employee);
	}
	
	Employee* searchEmployee(int id) {
		cout << "  Id " << setw(20) << "Name " << setw(20) << "Password " << setw(20) << "Salary " << endl << endl;
		for (auto eIt = allEmployees.begin(); eIt != allEmployees.end(); eIt++) {
			if (eIt->getId() == id) {
				return eIt._Ptr;
			}
		}
		return NULL;
	}

	void listEmployee() {
		cout << "  Id " << setw(20) << "Name " << setw(20) << "Password " << setw(20) << "salary " <<endl<< endl;
		for (auto eIt = allEmployees.begin(); eIt != allEmployees.end(); eIt++) {
			eIt->display();
			cout << "\n-------------------------------------------------------------------------------\n";
		}
	}
	void editEmployee(int id, string name, string password, double salary) {
		searchEmployee(id)->setName(name);
		searchEmployee(id)->setPassword(password);
		searchEmployee(id)->setSalary(salary);
	}

};


static vector <Admin> allAdmins;
static vector <Admin>::iterator aIt;

