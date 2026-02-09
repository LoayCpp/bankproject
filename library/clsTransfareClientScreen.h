#pragma once
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsBankClient.h"
#include"clsDate.h"
class clsTransfareClientScreen:protected clsScreen
{
	
	static void _PrintCardClient(clsBankClient Client) {

		cout << "\n\n----client Card:----\n";
		cout << "Full Name  :" << Client.FullName << endl;
		cout << "Acc.Number :" << Client.AccountNumber << endl;
		cout << "Balance    :" << Client.Balance << endl;
		cout << "\n-----------------------------------\n";
	}

	static string _ReadAccountNumber(string Message) {

		cout << Message;
		string AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsExitsClient(AccountNumber)) {

			cout << "\nNot Fount This Account Number ( " << AccountNumber << " ) ,Please Enter Account Number to Transfer From:";
			AccountNumber = clsInputValidate::ReadString();
		}

		return AccountNumber;

	}
	static double _ReadAmountBalance(clsBankClient ClientSource) {


		cout << "\nEnter Transfer Amount :";
		double Amount = clsInputValidate::ReadDblNumber();
		while (Amount > ClientSource.Balance) {

			cout << "\nAmount Exceeds the available Balance, Enter another Amount ? ";
			Amount = clsInputValidate::ReadDblNumber();

		}
		return Amount;
	}

public:
	static void ShowTransferScreen() {

		
		_DrawScreenHeader("\t\t Transfer Screen");
		
		clsBankClient ClientFrom = clsBankClient::Find(_ReadAccountNumber("\nPlease Enter Account Number to Transfer From : "));
		_PrintCardClient(ClientFrom);

		

		clsBankClient ClientTo = clsBankClient::Find(_ReadAccountNumber("\nPlease Enter Account Number to Transfer To:"));
		_PrintCardClient(ClientTo);
		
		while (ClientFrom.AccountNumber == ClientTo.AccountNumber) {

			cout << "\nYou Can`t Send Balance To your self Try Again enter the Cleint Distination :-)\n";
			 ClientTo = clsBankClient::Find(_ReadAccountNumber("\nPlease Enter Account Number to Transfer to:"));

		}
		
		double AmountBalance = _ReadAmountBalance(ClientFrom);
	
		char ch = 'n';
		cout << "\nAre You Sure To complete Transfer (y/n) :";
		cin >> ch;
		if (tolower(ch) == 'y') {

			if (ClientFrom.TransferClient(AmountBalance, ClientTo,CurrentUser.UserName)) {
		
				cout << "\nDone Successfully \n";
				_PrintCardClient(ClientFrom);
				_PrintCardClient(ClientTo);

			}
			else {

				cout << "\nAmount Exceeds the available Balance\n";
			}
			
		}
		else {

			cout << "\nCancel Transfer\n";
		}



}

};

