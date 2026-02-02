#pragma once
#include"clsScreen.h"
#include"clsBankClient.h"
#include<string>
#include"clsInputValidate.h"
class clsWithdrawScreen:protected clsScreen
{
private:

	static void _PrintClientInfo(clsBankClient Client) {

		cout << "\n----- Client Card----------\n";
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

	static string _ReadAccountNumber() {

		string account = "";
		cout << "Please Enter the Account Number :";
		getline(cin >> ws, account);
		return account;
}



public:
	static void ShowWithdrawScreen() {


	_DrawScreenHeader("\t\t Withdraw Screen");
		string Account = _ReadAccountNumber();
		while (!clsBankClient::IsExitsClient(Account)) {

			cout << "\nClient With [" << Account << "]" << "does not Exist.\n\n";
			Account = _ReadAccountNumber();
		}
		
		clsBankClient Client = clsBankClient::Find(Account);
		_PrintClientInfo(Client);
		cout << "Please enter Withdraw amount?";
		double amount = clsInputValidate::ReadDblNumber();

		char Ch = 'n';
		cout << "Are you sure you want to perform this transaction?";
		cin >> Ch;
		if (tolower(Ch) == 'y') {

			if (Client.Withdraw(amount)) {

				cout << "\n Amount withdraw successfully  \n";
				cout << "New Balance is :" << Client.Balance << endl;


			}
			else {

				cout << "\nCannot withdraw, Insufficient  Balance!\n";
				cout << "\nAmount to withdraw is: " << amount << endl;
				cout << "\nYour Balance is :" << Client.Balance << endl;
			}

		}
		else {

			cout << "Cancel withdrawal process ";

		}




	}
};

