#pragma once
#include "Client.h"
#include "Employee.h"
class ClientManger
{
public:
	static void printClientMenu() {
		system("cls");
		cout << "\t\t\t\t\t\t\t\tClient Menu\n";
		cout << "1-Deposit\n";
		cout << "2-Withdraw\n";
		cout << "3-TransfetTo\n";
		cout << "4-CheckBalance\n";
		cout << "5-Display\n";
		cout << "6-UpdatePassword\n";
		cout << "7-Logout\n";
		cout << endl;
	}
	static bool clientOptions(Client* client) {
		int x = 0;
		cout << "Enter your Choice: ";
		cin >> x;
		switch (x) {
		case 1:
		{
			system("cls");
			double amount = 1500;
			cout << "Enter amount to Deposit: ";
			cin >> amount;
			client->deposit(amount);
			break;
		}

		case 2:
		{
			system("cls");
			double amount = 1500;
			cout << "Enter amount to Withdraw: ";
			cin >> amount;
			client->withdraw(amount);
			break;

		}
		case 3:
		{
			system("cls");
			double amount = 1500;
			Client* transferClient;
			int id = 0;
			cout << "Enter client Id you want TransferTo :";
			cin >> id;
			Employee employee;
			transferClient = employee.searchClient(id);
			cout << "Enter amount To transferTo : ";
			cin >> amount;
			if (transferClient != NULL)
			{
				client->transferTo(amount, *transferClient);
			}
			else
			{
				cout << "\n*************************************\n";
				cout << "The Other Client Not Found In System\n";
				cout << "**************************************\n\n";
			}
			break;
		}
		case 4:
		{
			system("cls");
			client->checkBalance();
			break;

		}

		case 5:
		{
			system("cls");
			cout << "  Id " << setw(20) << "Name " << setw(20) << "Password " << setw(20) << "Balance " << endl << endl;
			client->display() ;
			cout << endl;
			break;
		}

		case 6:
		{
			system("cls");
			updatePassword(client);
			break;
		}
		case 7:
		{
			return true;
		}

		default:
		{
			cout << "\n**************************************\n";
			cout << "Your Choice Not Found In List:\n";
			cout << "**************************************\n\n";
			clientOptions(client);
		}
		}
		Back(client);
	}
	static void Back(Client* client) {
		system("pause");
		printClientMenu();
		clientOptions(client);
	}
	static void updatePassword(Person* person) {
		string password;
		cout << "Enter New Password : ";
		cin >> password;
		if (person->setPassword(password)) {
			cout << "\n*********************\n";
			cout << "Password Updated \n";
			cout << "\n*******************\n\n";
		}
	}
	static Client* login(int id, string password) {
		Employee employee;
		Client* clientPtr = employee.searchClient(id);
		if (clientPtr == NULL) {
			cout << "\n****************************\n";
			cout << "Incorrect Id or Password\n";
			cout << "****************************\n\n";
			return NULL;
		}
		else {
			if (clientPtr->getPassword() == password) {
				return clientPtr;

			}
			else {
				cout << "\n****************************\n";
				cout << "Incorrect Id or Password\n";
				cout << "****************************\n\n";
				return NULL;
			}
		}
	}




};
