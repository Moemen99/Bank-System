#pragma once
#include "Validation.h"
#include <vector>
class Person {

protected:
	//Attributes
	string name;
	int id;
	string password;
public:
	//Constructors
	Person() {
		this->name = " ";
		this->id = 0;
		this->password = " ";
	}
	Person(int id, string name,  string password) {

		setName(name);
		setPassword(password);
		setId(id);
	}
	//Setters
	bool setName(string name) {
		if (Validation::ValidateName(name)) {
			this->name = name;
			return true;
		}
		else
			if (name.size() < 5) {
				cout << "Password less than 5 \n";
			}
			else {
				if (name.size() > 20) {
					cout << "Name greater than  20\n";
				}
				return false;
			}
	}
	void setId(int id) {
		this->id = id;
	}
	bool setPassword(string password) {
		if (Validation::ValidatePassword(password)) {
			this->password = password;
			return true;

		}
		else
		{
			if (password.size() < 8) {
				cout << "Password less than 8 \n";
			}
			else if (password.size() > 20) {
				cout << "Password greater than  20\n";
			}
			return false;
		}
	}
	//Getters
	string getName() {
		return name;
	}
	int getId() {
		return id;
	}
	string getPassword() {
		return password;
	}
	//Method
	virtual void display() = 0;


};
