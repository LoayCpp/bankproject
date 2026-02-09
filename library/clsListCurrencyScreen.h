#pragma once
#include"clsScreen.h"
#include<iomanip>
#include"clsCurrency.h"
class clsListCurrencyScreen: protected clsScreen
{
	static void _PrintCurrencyInfo(clsCurrency C) {
		cout << setw(8) << left << "" << "|" << setw(30) << left << C.Country();
		cout << "|" << setw(8) << left << C.CurrencyCode();
		cout << "|" << setw(30) << left <<C.CurrencyCountry();
		cout << "|" << setw(8) << left << C.Rate();

	}

public:
	static void ShowListCurrencyScreen() {

		vector <clsCurrency>vCurrency = clsCurrency::GetCurrenciesList();
		string Title = "\t\tCurrencies List Screen";
		string SubTitle = "\t\t ( " + to_string(vCurrency.size()) + " ) Currency.";
		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "---------------------------------------------------------------------------------------\n";
		cout << setw(8) << left << "" << "|" << setw(30) << left << " Country";
		cout << "|" << setw(8) << left << " Code";
		cout << "|" << setw(30) << left << " Name";
		cout << "|" << setw(8) << left << " Rate/(1$)"<<endl;
		cout << setw(8) << left << "" << "---------------------------------------------------------------------------------------\n";

		if (vCurrency.size() == 0) {

			cout << "This empty File \n";
		}
		else {
			for (clsCurrency& C : vCurrency)
			{
				_PrintCurrencyInfo(C);
				cout << endl;

			}

		}
		cout << setw(8) << left << "" << "-------------------------------------------------------------------------------------\n";
	}
};

