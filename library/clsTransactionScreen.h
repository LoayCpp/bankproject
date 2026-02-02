#pragma once
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"iomanip"
#include"clsUtil.h"
#include"clsDepositScreen.h"
#include"clsWithdrawScreen.h"
#include"clsTotalBalanceScreen.h"
using namespace std;
class clsTransactionScreen:protected clsScreen
{
private:
	enum enTransactionOption{eDeposit=1,eWithdrow=2,eTotalBalance=3,eMainMenue=4};
	static short _ReadTransactionOption() {
		
		cout << setw(45) << left << " " <<"Choose what do you want to do? [1 to 4]? :";
		short num = clsInputValidate::ReadIntNumberBetween(1, 4, "Enter The Number between 1-4 :");
		return num;


	}
	static void _GoToTransactionScreen() {

		cout << "\n\npress Any key to go Transaction Menue Screen...";
		system("pause>0");
		ShowTransactionScreen();

	}
	static void _ShowDepositScreen() {

		clsDepositScreen::ShowDepositScreen();

	}
	static void _ShowWithdrawScreen() {

		clsWithdrawScreen::ShowWithdrawScreen();

	}
	static void _ShowTotalBalanceScreen() {
		clsTotalBalnceScreen::_ShowTotalBalancesScreen();

	}
	static void _PerformanceTransaction(enTransactionOption Option) {

		switch (Option)
		{
		case clsTransactionScreen::eDeposit:
			system("cls");
			_ShowDepositScreen();
			_GoToTransactionScreen();
			break;
		case clsTransactionScreen::eWithdrow:
			system("cls");
			_ShowWithdrawScreen();
			_GoToTransactionScreen();
			break;
		case clsTransactionScreen::eTotalBalance:
			system("cls");
			_ShowTotalBalanceScreen();
			_GoToTransactionScreen();
			break;

		case clsTransactionScreen::eMainMenue: {


		}
		
		}



	}

public:
	static void ShowTransactionScreen() {
		system("cls");
		_DrawScreenHeader("\t\tTransaction Screen ");

		cout << clsUtil::Tabs(5) << "===========================================\n";
		cout <<clsUtil::Tabs(5) << "\t\tTransaction Menue\n";
		cout << clsUtil::Tabs(5) << "===========================================\n";
		cout << setw(45) << left << " " << "[1]Deposite" << endl;
		cout << setw(45) << left << " " << "[2]Withdraw" << endl;
		cout << setw(45) << left << " " << "[3]Total Balance" << endl;
		cout << setw(45) << left << " " << "[4]Main Menue" << endl;
		cout << clsUtil::Tabs(5) << "===========================================\n";
		_PerformanceTransaction((enTransactionOption)_ReadTransactionOption());


	}



};

