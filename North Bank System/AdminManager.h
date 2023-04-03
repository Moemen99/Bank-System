#pragma once
#include "EmployeeManager.h"
class AdminManager : public EmployeeManager
{
public:
	static void printAdminMenu() {
		system("cls");
		cout << "\t\t\t\t\t\t\t\tAdmin Menu\n";
		cout << "1-Add new Client\n";
		cout << "2-List of all clients\n";
		cout << "3-Search for a client\n";
		cout << "4-Edit client\n";
		cout << "5-Add new Employee\n";
		cout << "6-List of all Employees\n";
		cout << "7-Search for an Employee\n";
		cout << "8-Edit Employee\n";
		cout << "9-Display\n";
		cout << "10-UpdatePassword\n";
		cout << "11- Logout\n";
		cout << endl;
	}
	static void newEmployee(Admin* admin) {
		Employee employee;
		string name, password;
		double salary;
		int id;
		cout << "Enter new Employee \n\n";
		cout << "Name : ";
		cin >> name;
		cout << "Password : ";
		cin >> password;
		cout << "Salary :";
		cin >> salary;
		if (employee.setName(name) && employee.setPassword(password) && employee.setSalary(salary)) {
			id = FilesHelper::getLast("EmployeeLastId.txt");

			employee.setId(id + 1);
			FilesHelper::saveLast("EmployeeLastId.txt", id + 1);
			admin->addEmployee(employee);
			cout << "\n*******************\n";
			cout << "Employee Accepted\n";
			cout << "*******************\n\n";
		}
		else {
			cout << "\n*******************\n";
			cout << "Employee Not Accepted\n";
			cout << "*******************\n\n";
		}

	}

	static void listAllEmployees(Admin* admin) {
		admin->listEmployee();

	}

	static void searchForEmployee(Admin* admin) {
		int id;
		cout << " Id : ";
		cin >> id;
		Employee* employee = admin->searchEmployee(id);
		if (employee == NULL) {
			cout << "\n**************************\n";
			cout << "Employee Not Found\n";
			cout << "**************************\n\n";
		}
		else {
			employee->display();
		}
	}

	static void editEmployeeInfo(Admin* admin) {
		int x;
		int id;
		string name, password;
		double balance;
		cout << "Enter Id : ";
		cin >> id;
		Employee* employee = admin->searchEmployee(id);
		if (employee != NULL) {
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
				admin->editEmployee(id, name, password, balance);
				break;

			}
			case 2:
			{
				cout << "\nEnter new name : ";
				cin >> name;
				password = employee->getPassword();
				balance = employee->getSalary();
				admin->editEmployee(id, name, password, balance);
				break;
			}
			case 3:
			{
				cout << "\nEnter new password : ";
				cin >> password;
				name = employee->getName();
				balance = employee->getSalary();
				admin->editEmployee(id, name, password, balance);
				break;
			}
			case 4: {
				cout << "\nEnter new Balance : ";
				cin >> balance;
				name = employee->getName();
				password = employee->getPassword();
				admin->editEmployee(id, name, password, balance);
				break;
			}
			default:
			{
				cout << "\n******************************************\n";
				cout << "Your Choice Not Found In the List\n";
				cout << "******************************************\n\n";
				editEmployeeInfo(admin);
				break;

			}


			}

		}
		else {
			cout << "\n****************************\n";
			cout << "employee not found \n\n";
			cout << "****************************\n\n";
			cout << "\n1- Try Again \n";
			cout << "2- Return\n";
			int x;
			cout << "Enter your Choice";
			cin >> x;
			system("cls");
			if (x == 1) {
				editEmployeeInfo(admin);
			}
			else if (x == 2) {
				printAdminMenu();
				adminOptions(admin);
			}
			else {
				cout << "\n*****************************************\n";
				cout << "Your Choice Not Found In The List\n";
				cout << "*****************************************\n\n";
				system("pause");
				printAdminMenu();
				adminOptions(admin);

			}
		}
	}
	static bool adminOptions(Admin* admin) {
		int x = 0;
		cout << "Enter your choice : ";
		cin >> x;
		switch (x) {
		case 1: {
			system("cls");
			newClient(admin);
			break; }
		case 2: {
			system("cls");
			listAllClients(admin);
			break;

		}
		case 3: {
			system("cls");
			searchForClient(admin);
			break;
		}
		case 4:
		{
			system("cls");
			editClientInfo(admin);
			break;
		}
		case 5: {
			system("cls");
			newEmployee(admin);
			break; }
		case 6: {
			system("cls");
			listAllEmployees(admin);
			break;

		}
		case 7: {
			system("cls");
			searchForEmployee(admin);
			break;
		}
		case 8:
		{
			system("cls");
			
			editEmployeeInfo(admin);
	
			break;
		}
		case 9:
		{
			system("cls");
			cout << "  Id " << setw(20) << "Name " << setw(20) << "Password " << setw(20) << "Salary " << endl << endl;
			admin->display();
			cout << endl;
			break;
		}
		case 10:
		{
			system	("cls");
			updatePassword(admin);
			break;
		}
		case 11:
		{
			return true;
		}
		default: {
			cout << "Your Choice Not Found In The List \n";
			adminOptions(admin);

		}
		}
		Back(admin);
	}
	static void Back(Admin* admin) {
		system("Pause");
		printAdminMenu();
		adminOptions(admin);
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
	static Admin* searchAdmin(int id) {
		for (aIt = allAdmins.begin(); aIt != allAdmins.end(); aIt++) {
			if (aIt->getId() == id) {
				return aIt._Ptr;
			}
		}
	}
	static Admin* login(int id, string password) {
		Admin admin;
		Admin* adminPtr = searchAdmin(id);
		if (adminPtr == NULL) {
			cout << "\nIncorrect Id or Password\n";
			return NULL;
		}
		else {
			if (adminPtr->getPassword() == password) {
				return adminPtr;
			}
			else {
				cout << "Incorrect Id or Password\n";
				return NULL;
			}
		}
	}
};