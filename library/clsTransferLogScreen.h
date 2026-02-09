#pragma once
#include"clsScreen.h"
#include"clsBankClient.h"
class clsTransferLogScreen:protected clsScreen
{
	static void _PrintRecordTransfer(clsBankClient::stRecordTransfer Record ) {

		cout << setw(10) << left << " " <<"|" << setw(20) << left << Record.Date;
		cout << "|" << setw(7) << left << Record.SourceAccountNumber;
		cout << "|" << setw(7) << left << Record.DestinationAccountNumber;
		cout << "|" << setw(10) << left << Record.Amount ;
		cout << "|" << setw(15) << left << Record.SourceAmount;
		cout << "|" << setw(15) << left << Record.DestinationAmount;
		cout << "|" << setw(15) << left << Record.UserName;


	}

public:
	static void ShowTransferLogScreen() {

		vector<clsBankClient::stRecordTransfer>vRecord = clsBankClient::LoadRecordTransferFromFile();
		string Title = "\t\tTransfer Log List Screen";
		string SubTilte ="\t\t( " + to_string(vRecord.size())+" ) Record(s)";
		_DrawScreenHeader(Title, SubTilte);

		cout << setw(10) << left << " " << "---------------------------------------------------------------------------------------\n";
		cout << setw(10) << left << " " << "|" << setw(20) << left << "Date/Time";
		cout << "|" << setw(7) << left << "s.Acct";
		cout << "|" << setw(7) << left << "d.Acct";
		cout << "|" << setw(10) << left << "Amoutn";
		cout << "|" << setw(15) << left << "s.Balance";
		cout << "|" << setw(15) << left << "d.Balance";
		cout << "|" << setw(15) << left << "User"<<endl;
		cout << setw(10) << left << " " << "----------------------------------------------------------------------------------------\n";
		if (vRecord.size() == 0) {


			cout << "\nIs Empty Recoord\n\n";
		}
		else {

			for (clsBankClient::stRecordTransfer Record : vRecord) {


				_PrintRecordTransfer(Record);
				cout << endl;

			}
		}

	}
};

