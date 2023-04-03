#pragma once
#include "Person.h"
#include "Client.h"
class Employee : public Person {
protected:
	//Attribute
	double salary;
public:
	//Constructors
	Employee() : Person() {
		this->salary = 0.0;
	}
	Employee(int id, string name, string password, double salary) : Person(id, name, password) {
		setSalary(salary);
	}
	//Setter

	bool setSalary(double salary) {
		if (Validation::ValidateSalary(salary)) {
			this->salary = salary;
			return true;
		}

		else {
			if (salary < 5000) {
				cout << "Min Salary 5000!!!\n";
			}
			return false;
		}


	}
	//Getter
	double getSalary() {
		return salary;
	}
	//Methods
	void display() {
		
		cout << setw(4) << getId() << setw(20) << getName() << setw(20) << getPassword() << setw(20) << getSalary()<<endl;


	}
	void addClient(Client& client) {
		allClients.push_back(client);
	}
	Client* searchClient(int id) {
		cout << "  Id " << setw(20) << "Name " << setw(20) << "Password " << setw(20) << "Balance " << endl << endl;

		for (auto clIt = allClients.begin(); clIt != allClients.end(); clIt++) {
			if (clIt->getId() == id) {

				return clIt._Ptr;
			}
		}
		return NULL;
	}

	void listClient() {
		cout << "  Id " << setw(20) << "Name " << setw(20) << "Password " << setw(20) << "Balance " << endl << endl;
		for (auto clIt = allClients.begin(); clIt != allClients.end(); clIt++) {
			
			clIt->display();
			cout << "\n----------------------------------------------------------------------------------\n";
		}
	}
	void editClient(int id, string name, string password, double balance) {
		searchClient(id)->setName(name);
		searchClient(id)->setPassword(password);
		searchClient(id)->setBalance(balance);
	}
};

static vector <Employee> allEmployees;
static vector <Employee>::iterator eIt;