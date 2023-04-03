#pragma once
#include "AdminManager.h"
#include "FileManager.h"
#include "ClientManager.h"
#include <windows.h>



class Screens
{
public:

	static void loginOptions() {
		cout << "\t\t\t\t\t\tLogin As\n";
		cout << "1- Client\n\n";
		cout << "2- Employee\n\n";
		cout << "3- Admin\n\n";
		cout << "4- Exist\n\n";
	}
	static int loginAs() {
		int x;
		cout << "Login As : ";
		cin >> x;
		switch (x) {
		case 1: {
			return 1;
			break;
		}
		case 2: {
			return 2;
			break; }

		case 3: {
			return 3;
			break; }

		case 4: {
			return 4;
			break;
		}
		default: {
			Invalid(x);
			break;
		}
		}
	}
	static void Invalid(int c) {
		cout << "\n\n************************************\n";
		cout << "your Choice Not found In List\n";
		cout << "*************************************\n\n";
		loginAs();
	}

	static void loginscreen(int c) {
		switch (c) {
		case 1: {
			system("cls");
			loginClient();
			break;
		}
		case 2:
		{
			system("cls");
			loginEmployee();
			break;
		}
		case 3:
		{
			system("cls");
			loginAdmin();
			break;
		}
		case 4:
		{
			thankYou();
			FileManager::updateClients();
			FileManager::updateEmployees();
			FileManager::updateAdmins();
		}
		}
	}

	static void loginClient() {
		cout << "\t\t\t\t\t\tLogin Client Page\n";
		int id;
		string password, name;
		cout << "Id : ";
		cin >> id;
		cout << "Password : ";
		cin >> password;
		Client* client = ClientManger::login(id, password);
		if (client != NULL) {
			ClientManger::printClientMenu();
			if (ClientManger::clientOptions(client)) {
				system("cls");
				name = client->getName();
				loginOptions();
				loginscreen(loginAs());

			}
		}
		else {
			cout << "\n1- Try Again\n";
			cout << "2- Return\n";
			int x;
			cout << "Enter your choice : ";
			cin >> x;
			system("cls");
			if (x == 1) {
				loginClient();
			}
			else if (x == 2) {
				system("cls");
				loginOptions();
				loginscreen(loginAs());
			}
			else {
				cout << "\n\n*************************************\n";
				cout << "Your Coice Not Found In List \n";
				cout << "***************************************\n\n";
				system("Pause");
				system("cls");
				loginOptions();
				loginscreen(loginAs());
			}
		}

	}
	static void loginEmployee() {
		cout << "\t\t\t\t\t\tLogin Employee Page\n";
		int id;
		string password, name;
		cout << "Id : ";
		cin >> id;
		cout << "Password : ";
		cin >> password;
		Employee* employee = EmployeeManager::login(id, password);
		if (employee != NULL) {
			EmployeeManager::printEmployeeMenu();
			if (EmployeeManager::employeeOptions(employee)) {
				system("cls");
				name = employee->getName();
				loginOptions();
				loginscreen(loginAs());

			}
		}
		else {
			cout << "\n1- Try Again\n";
			cout << "2- Return\n";
			int x;
			cout << "Enter your choice : ";
			cin >> x;
			system("cls");
			if (x == 1) {
				loginEmployee();
			}
			else if (x == 2) {
				system("cls");
				loginOptions();
				loginscreen(loginAs());
			}
			else {
				cout << "\n\n*************************************\n";
				cout << "Your Coice Not Found In List \n";
				cout << "***************************************\n\n";
				system("Pause");
				system("cls");
				loginOptions();
				loginscreen(loginAs());
			}
		}

	}

	static void loginAdmin() {
		cout << "\t\t\t\t\t\tLogin Admin Page\n";
		int id;
		string password, name;
		cout << "Id : ";
		cin >> id;
		cout << "Password : ";
		cin >> password;
		Admin* admin = AdminManager::login(id, password);
		if (admin != NULL) {
			AdminManager::printAdminMenu();
			if (AdminManager::adminOptions(admin)) {
				system("cls");
				name = admin->getName();
				loginOptions();
				loginscreen(loginAs());

			}
		}
		else {
			cout << "\n1- Try Again\n";
			cout << "2- Return\n";
			int x;
			cout << "Enter your choice : ";
			cin >> x;
			system("cls");
			if (x == 1) {
				loginAdmin();
			}
			else if (x == 2) {
				system("cls");
				loginOptions();
				loginscreen(loginAs());
			}
			else {
				cout << "\n\n*************************************\n";
				cout << "Your Coice Not Found In List \n";
				cout << "***************************************\n\n";
				system("Pause");
				system("cls");
				loginOptions();
				loginscreen(loginAs());
			}
		}

	}

	static void thankYou() {
		system("cls");
		system("Color f4");
		cout << "\n\n\n\n\n\n\n\n\n";
		cout << "\t\t\t########### ###   ###   ########    ####      ##   ##     ##     ####   ####  ##########   ###    ###\n";
		cout << "\t\t\t   ###      ###   ###   ##    ##    ##  ##    ##   ##  ###         ##   ##    ###    ###   ###    ###\n";
		cout << "\t\t\t   ###      #########   ########    ##   ##   ##   ####              ###      ###    ###   ###    ###\n";
		cout << "\t\t\t   ###      ###   ###   ##    ##    ##     ## ##   ##  ###           ###      ###    ###   ###    ###\n";
		cout << "\t\t\t   ###      ###   ###   ##    ##    ##      ####   ##     ##         ###      ##########   ##########\n";
		Sleep(2500);
	}

	static void welcome() {
		cout << "\n\n\n\n\n\n\n\n\n";
		cout << "\t\t\t##       ##     ######    ##         #######     ########     ##       ##    ###### \n";
		cout << "\t\t\t##   #   ##     ##        ##         ##          ##    ##     ###     ###    ##\n";
		cout << "\t\t\t##  # #  ##     ######    ##         ##          ##    ##     ## #   # ##    ###### \n";
		cout << "\t\t\t## #   # ##     ##        ##         ##          ##    ##     ##  # #  ##    ##\n";
		cout << "\t\t\t###     ###     ######    ######     #######     ########     ##   #   ##    ###### \n";
		Sleep(2500);
	}
	static void bankName() {
		cout << "\n\n\n\n\n\n\n\n\n";
		cout << "\t\t       ###      ##    ########    ##########   ############  ###   ###     #########     ########     ###      ##   ##   ###\n";
		cout << "\t\t       ## ##    ##    ##    ##    ##     ###       ###       ###   ###     ##      ##    ##    ##     ## ##    ##   ##   ##\n";
		cout << "\t\t       ##  ##   ##    ##    ##    ##     ###       ###       ###   ###     ##      ##    ##    ##     ##  ##   ##   #####\n";
		cout << "\t\t       ##   ##  ##    ##    ##    ##########       ###       #########     ##########    ########     ##   ##  ##   ##   ##\n";
		cout << "\t\t       ##    ## ##    ##    ##    ##   ##          ###       ###   ###     ##      ##    ##    ##     ##    ## ##   ##    ##\n";
		cout << "\t\t       ##     ####    ########    ##   #####       ###       ###   ###     #########     ##    ##     ##     ####   ##    ###\n";
		Sleep(5000);
	}

	static void runApp() {
		system("color f4");
		bankName();
		system("cls");
		welcome();
		system("cls");
		system("color f4");
		FileManager::getAllData();
		loginOptions();
		loginscreen(loginAs());


	}
};
