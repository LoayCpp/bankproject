#pragma once
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsBankClient.h"
#include<string>
using namespace std;
class clsDepositScreen :protected clsScreen
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

			string Account;
			cout << "\nPleas Enter Account Number :";
			getline(cin>>ws, Account);

			return Account;
		
		}



	

public:
	 static void ShowDepositScreen() {

		_DrawScreenHeader("\tDeposit Screen ");
	
		string Account = _ReadAccountNumber();
		while (!clsBankClient::IsExitsClient(Account)) {

			cout << "\nClient With [" << Account << "]" << "does not Exist.\n\n";
			Account = _ReadAccountNumber();
		}

		clsBankClient Client = clsBankClient::Find(Account);
		_PrintClientInfo(Client);
		cout << "Please Enter The Deposit Amount :";
		double Amount = clsInputValidate::ReadDblNumber();

		char Check = 'n';
		cout << "\nAre you sure you want to perform this transaction?";
		cin >> Check;
		if (tolower(Check) == 'y') {

			Client.Deposit(Amount);
			cout << "\nAmount Deposit Successfuly \n";
			cout << "\nNew Balance is:" << Client.Balance;


		}
		else {


			cout << "\nCancel Amount ";
		}

	}
};

