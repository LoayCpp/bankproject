#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsBankClient.h"
using namespace std;
class clsUpdateClientScreen:protected clsScreen
{

	static void _ReadClientInfo(clsBankClient& Client) {

		cout << "First Name   : ";
		Client.FirstName = clsInputValidate::ReadString();

		cout << "Last Name    : ";
		Client.LastName = clsInputValidate::ReadString();


		cout << "Email        : ";
		Client.Email = clsInputValidate::ReadString();

		cout << "phone        : ";
		Client.Phone = clsInputValidate::ReadString();

		cout << "PinCode      : ";
		Client.PinCode = clsInputValidate::ReadString();

		cout << "Balance        :";
		Client.Balance = clsInputValidate::ReadDblNumber();

	}
	static void _PrintClientInfo(clsBankClient Clinet) {

		cout << "\n-----Info Client----------\n";
		cout << "FirstName        :" << Clinet.FirstName << endl;
		cout << "LastName         :" << Clinet.LastName << endl;
		cout << "FullName         :" << Clinet.FullName << endl;
		cout << "Email            :" << Clinet.Email << endl;
		cout << "Phone            :" << Clinet.Phone << endl;
		cout << "AccountNumber    :" << Clinet.AccountNumber << endl;
		cout << "PinCode          :" << Clinet.PinCode << endl;
		cout << "Balance          :" << Clinet.Balance << endl;
		cout << "------------------------------\n";


	}

public:

	static void ShowUpdateClientScreen() {


		_DrawScreenHeader("\t\t Update Client Screen");
	    string Account = "";
	    cout << "Enter The Account Number With Update: ";
	    Account = clsInputValidate::ReadString();
	
	    while (!clsBankClient::IsExitsClient(Account)) {
	        cout << "Account number is not found, choose another one: ";
	        Account = clsInputValidate::ReadString();
	    }
	
	
	    clsBankClient Client = clsBankClient::Find(Account);
		_PrintClientInfo(Client);
	
	    _ReadClientInfo(Client);
	   
	
	    clsBankClient::enSaveResult Result = Client.Save();
	    switch (Result)
	    {
	    case clsBankClient::enFieldEmptyObject: {
	        cout << "This Error the Client Empty\n";
	
	        break;
	    }
	    case clsBankClient::enSucceded: {
			cout << "\n------------------------------\n";
	        cout<< "\n\nClient Update client Successfully :-)\n";
	
			_PrintClientInfo(Client);
	
	        break;
	    }
	
	    }
	
	
	}
	

};

