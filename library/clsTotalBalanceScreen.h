#pragma once
#include"clsBankClient.h"
#include"clsScreen.h"
#include<iomanip>
#include<string>
#include"clsUtil.h"
using namespace std;
class clsTotalBalnceScreen:protected clsScreen
{
private:
	static void _PrintClientRecordBalanceLine(clsBankClient Client) {

		cout << setw(35) << left << " "<<"| "<<setw(18) <<left<< Client.AccountNumber;
		cout <<"| " << setw(28) << left << Client.FullName;
		cout <<"| " <<setw(14) << left << Client.Balance;


	}


public:
	static void _ShowTotalBalancesScreen() {
		vector<clsBankClient> Clients = clsBankClient::GetListClient();
		string Title = "\t\tBalance List Screen";
		string SubTitle = "\t\t" + to_string(Clients.size()) + " Client(s)";
		_DrawScreenHeader(Title,SubTitle);
		cout << setw(30) << left << " " <<"---------------------------------------------------------------------\n";
		cout << setw(35) << left << " " <<setw(20)<<left <<"| Account Number";
		cout << setw(30) << left << "| Client Name";
		cout << setw(20) << left << "| Balance "<<endl;
		cout << setw(30) << left << " " << "---------------------------------------------------------------------\n";
		double amount = clsBankClient::TotalBalance();
		
		if (Clients.size() == 0) {

			cout << "We haven`t any client\n";
		}
		else {
			for (clsBankClient& C : Clients) {


				_PrintClientRecordBalanceLine(C);
				cout << endl;
			}
			cout << setw(30) << left << " " << "---------------------------------------------------------------------\n";
			
			cout << setw(30) << left << " " << "Total Balance is :" << amount << endl;
			cout << setw(30) << left << " " << clsUtil::NumberToText(amount) << endl;

		}


	}




};

