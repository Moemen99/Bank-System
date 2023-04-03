#pragma once
#include "Admin.h"
#include "FilesHelper.h"

class EmployeeManager
{
public:
	static void printEmployeeMenu() {
		system("cls");
		cout << "\t\t\t\t\t\t\t\tEmployee Menu\n";
		cout << "1-Add new Client\n";
		cout << "2-List of all clients\n";
		cout << "3-Search for a client\n";
		cout << "4-Edit client\n";
		cout << "5-Display\n";
		cout << "6-UpdatePassword\n";
		cout << "7-Logout\n";
		cout << endl;
	}

	static void newClient(Employee* employee) {
		Client client;
		string name, password;
		double balance;
		int id;
		cout << "Enter new Client \n\n";
		cout << "Name : ";
		cin >> name;
		cout << "Password : ";
		cin >> password;
		cout << "Balance :";
		cin >> balance;
		if (client.setName(name) && client.setPassword(password) && client.setBalance(balance)) {
			id = FilesHelper::getLast("ClientLastId.txt");

			client.setId(id + 1);
			FilesHelper::saveLast("ClientLastId.txt", id + 1);
			employee->addClient(client);
			cout << "\n*******************\n";
			cout << "Client Accepted\n";
			cout << "*******************\n\n";
		}
		else {
			cout << "\n*******************\n";
			cout << "Client Not Accepted\n";
			cout << "*******************\n\n";
		}

	}
	static void listAllClients(Employee* employee) {
		employee->listClient();

	}

	static void searchForClient(Employee* employee) {
		int id;
		cout << "Client Id : ";
		cin >> id;
		Client* client = employee->searchClient(id);
		if (client == NULL) {
			cout << "\n**************************\n";
			cout << "Client Not Found\n";
			cout << "**************************\n\n";
		}
		else {
			client->display();
		}
	}

	static void editClientInfo(Employee* employee) {
		int x;
		int id;
		string name, password;
		double balance;
		cout << "Enter Id : ";
		cin >> id;
		Client* client = employee->searchClient(id);
		if (client != NULL) {
			cout << "\n What you want to edit : \n";
			cout << "1-All data : \n";
			cout << "2-Name : \n";
			cout << "3-Password : \n";
			cout << "4-Balance : \n";
			cout << "Enter your choice : ";
			cin >> x;
			switch (x)
			{
			case 1:
			{
				cout << "\nEnter new name : ";
				cin >> name;
				cout << "\nEnter new password : ";
				cin >> password;
				cout << "\nEnter new Balance : ";
				cin >> balance;
				employee->editClient(id, name, password, balance);
				break;

			}
			case 2:
			{
				cout << "\nEnter new name : ";
				cin >> name;
				password = client->getPassword();
				balance = client->getBalance();
				employee->editClient(id, name, password, balance);
				break;
			}
			case 3:
			{
				cout << "\nEnter new password : ";
				cin >> password;
				name = client->getName();
				balance = client->getBalance();
				employee->editClient(id, name, password, balance);
				break;
			}
			case 4: {
				cout << "\nEnter new Balance : ";
				cin >> balance;
				name = client->getName();
				password = client->getPassword();
				employee->editClient(id, name, password, balance);
				break;
			}
			default:
			{
				cout << "\n******************************************\n";
				cout << "Your Choice Not Found In the List\n";
				cout << "******************************************\n\n";
				editClientInfo(employee);
				break;

			}


			}

		}
		else {
			cout << "\n****************************\n";
			cout << "Client not found \n\n";
			cout << "****************************\n\n";
			cout << "\n1- Try Again \n";
			cout << "2- Return\n";
			int x;
			cin >> x;
			system("cls");
			if (x == 1) {
				editClientInfo(employee);
			}
			else if (x == 2) {
				printEmployeeMenu();
				employeeOptions(employee);
			}
			else {
				cout << "\n*****************************************\n";
				cout << "Your Choice Not Found In The List\n";
				cout << "*****************************************\n\n";
				system("pause");
				printEmployeeMenu();
				employeeOptions(employee);

			}
		}
	}
	static bool employeeOptions(Employee* employee) {
		int x = 0;
		cout << "Enter your choice : ";
		cin >> x;
		switch (x) {
		case 1: {
			system("cls");
			newClient(employee);
			break; }
		case 2: {
			system("cls");
			listAllClients(employee);
			break;

		}
		case 3: {
			system("cls");
			searchForClient(employee);
			break;
		}
		case 4:
		{
			system("cls");
			editClientInfo(employee);
			break;
		}
		case 5:
		{
			system("cls");
			cout << "  Id " << setw(20) << "Name " << setw(20) << "Password " << setw(20) << "Salary " << endl << endl;
			employee->display();
			break;
		}
		case 6:
		{
			system("cls");
			updatePassword(employee);
			break;
		}
		case 7:
		{
			return true;
		}
		default: {
			cout << "Your Choice Not Found In The List \n";
			employeeOptions(employee);

		}
		}
		Back(employee);
	}
	static void Back(Employee* employee) {
		system("Pause");
		printEmployeeMenu();
		employeeOptions(employee);
	}
	static void updatePassword(Person* pesrson) {
		string password;
		cout << "Enter new password : ";
		cin >> password;

		if (pesrson->setPassword(password)) {
			cout << "\n***********************\n";
			cout << "Password updated\n";
			cout << "***********************\n\n";
		}
		    
	}
	static Employee* login(int id, string password) {
		Admin admin;
		Employee* employeePtr = admin.searchEmployee(id);
		if (employeePtr == NULL) {
			cout << "\nIncorrect Id or Password\n";
			return NULL;
		}
		else {
			if (employeePtr->getPassword() == password) {
				return employeePtr;
			}
			else {
				cout << "Incorrect Id or Password\n";
				return NULL;
			}
		}
	}

};

