#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsBankClient.h"
using namespace std;
class clsFindClientScreen : protected clsScreen
{
	static void _PrintClientInfo(clsBankClient Client) {

		cout << "\n-----Info Client----------\n";
		cout << "FirstName        :" << Client.FirstName << endl;
		cout << "LastName         :" << Client.LastName << endl;
		cout << "FullName         :" << Client.FullName << endl;
		cout << "Email            :" << Client.Email << endl;
		cout << "Phone            :" << Client.Phone << endl;
		cout << "AccountNumber    :" << Client.AccountNumber << endl;
		cout << "PinCode          :" << Client.PinCode << endl;
		cout << "Balance          :" << Client.Balance << endl;
		cout << "------------------------------\n";


	}


public:
	static void ShowFindClientScreen() {
		_DrawScreenHeader("\t\tFine Client Screen");
		string AccountNumber = "";
		cout << "Enter The Account Number for Find Clinet: ";
		AccountNumber = clsInputValidate::ReadString();

		clsBankClient Client = clsBankClient::Find(AccountNumber);

		if (!Client.IsEmpty()) {
			cout << "\n\n--------------------\n";
			cout << "|  Client Found    |\n";
			cout << "--------------------\n";
			_PrintClientInfo(Client);

			
		}
		else {
			cout << "\n\n--------------------\n";
			cout << "| Not Client Found |\n";
			cout << "--------------------\n";
		}





	}


};

