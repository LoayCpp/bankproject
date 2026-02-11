#pragma once
#include"clsScreen.h"
#include<iomanip>
#include"clsInputValidate.h"
#include"clsListCurrencyScreen.h"
#include"clsFindCurrencyScreen.h"
#include"clsUpdateCurrencyRate.h"
#include"clsCurrencyCalculatorScreen.h"
class clsCurrencyExchangeMainScreen :protected clsScreen
{
	enum enoption
	{
		eListCurrency = 1,
		eFindCurrency = 2,
		eUpdateCurrency = 3,
		eCurrencyCalculator = 4,
		eMainMenue = 5

	};
	static short _ReadNumberToChoseTheOption() {
		short Num = 0;
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
		Num = clsInputValidate::ReadShortNumberBetween(1, 5, "Invalid Number To Enter between 1-5 : ");

		return Num;
	}
	static void _GoToCurrencyScreen() {


		cout << "Press Any Key To Go Currency Screen\n";
		system("pause>0");
		ShowCurrencyScreen();
	}
	static void _ShowListCurrencyScreen() {


		clsListCurrencyScreen::ShowListCurrencyScreen();


	}
	static void _ShowFindCurrencyScreen() {


		clsFindCurrencyScreen::_ShowFindCurrencyScreen();


	}
	static void _ShowUpdateCurrencyScreen() {


		
		clsUpdateCurrencyRate::_ShowUpdateCurrencyRate();

	}
	static void _ShowCurrencyCalculatorScreen() {


		clsCurrencyCalculatorScreen::_ShowCurrencyCalculator();


	}


	static void _PerformanceOption(enoption option) {

		switch (option)
		{
		case clsCurrencyExchangeMainScreen::eListCurrency:
			system("cls");
			_ShowListCurrencyScreen();
			_GoToCurrencyScreen();
			break;

		case clsCurrencyExchangeMainScreen::eFindCurrency:
			system("cls");
			_ShowFindCurrencyScreen();
			_GoToCurrencyScreen();
			break;

		case clsCurrencyExchangeMainScreen::eUpdateCurrency:
			system("cls");
			_ShowUpdateCurrencyScreen();
			_GoToCurrencyScreen();
			break;
		case clsCurrencyExchangeMainScreen::eCurrencyCalculator:
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_GoToCurrencyScreen();

			break;

		case clsCurrencyExchangeMainScreen::eMainMenue: {


		}

		}



	}

public:
	static void ShowCurrencyScreen() {
		system("cls");
		_DrawScreenHeader("\t\t Currency Exhange Main Screen");

		cout << setw(37) << left << "" << "========================================================\n";
		cout << setw(50) << left << "" << "\tCurrency Exchange Menue\n";
		cout << setw(37) << left << "" << "========================================================\n";
		cout << setw(50) << left << "" << "[1] List Currencies.\n";
		cout << setw(50) << left << "" << "[2] Find Currency.\n";
		cout << setw(50) << left << "" << "[3] Update Rate.\n";
		cout << setw(50) << left << "" << "[4] Currency Calculator.\n";
		cout << setw(50) << left << "" << "[5] Main Menue\n";
		cout << setw(37) << left << "" << "========================================================\n";

		_PerformanceOption(enoption(_ReadNumberToChoseTheOption()));
	}
};

