#pragma once
#include "Person.h"
class Client : public Person {
private:
	//Attribute
	double balance;
public:
	//Constructors
	Client() : Person() {
		this->balance = 0.0;
	}
	Client(int id, string name, string password, double balance) : Person(id, name, password) {
		setBalance(balance);
	}
	//Setter

	bool setBalance(double balance) {
		if (Validation::ValidateBalance(balance)) {
			this->balance = balance;
			return true;
		}

		else {
			if (balance < 1500) {
				cout << "Min balance is 1500!!!\n";
			}
			return false;
		}

	}


	//Getter
	double getBalance() {
		return balance;
	}
	//Methods
	void display() {
		
		cout << setw(4) << getId() << setw(20) << getName() << setw(20) << getPassword() << setw(20) << getBalance();
	}
	void deposit(double amount) {
		this->balance += amount;
		cout << "\nSuccessful transaction.\n";
	}
	void withdraw(double amount) {
		if (amount <= this->balance) {
			this->balance -= amount;
			cout << "\nSuccessful transaction.\n";
		}
		else cout << "\nAmount Exceeded.\n";
	}
	void transferTo(double amount, Client& recipient) {
		if (amount <= balance) {
			this->balance -= amount;
			recipient.balance += amount;
			cout << "\nSuccessful transaction.\n";
		}
		else cout << "\nAmount Exceeded.\n";
	}
	void checkBalance() {
		cout << "Balance: " << balance << endl;
	}
};

static vector <Client> allClients;
static vector <Client>::iterator clIt;