#pragma once
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"iomanip"
#include"clsUtil.h"
#include"clsDepositScreen.h"
#include"clsWithdrawScreen.h"
#include"clsTotalBalanceScreen.h"
#include"clsTransfareClientScreen.h"
#include"clsTransferLogScreen.h"
using namespace std;
class clsTransactionScreen:protected clsScreen
{
private:
	enum enTransactionOption{eDeposit=1,eWithdrow=2,eTotalBalance=3,eTransfere=4,eTransferLog=5,eMainMenue=6};
	static short _ReadTransactionOption() {
		
		cout << setw(45) << left << " " <<"Choose what do you want to do? [1 to 6]? :";
		short num = clsInputValidate::ReadIntNumberBetween(1, 6, "Enter The Number between 1-6 :");
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
	static void _ShowTransferScreen() {
		clsTransfareClientScreen::ShowTransferScreen();


	}
	static void _ShowTransferLog() {

		
		clsTransferLogScreen::ShowTransferLogScreen();
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
		case clsTransactionScreen::eTransfere:
			system("cls");
			_ShowTransferScreen();
			_GoToTransactionScreen();
			break;
		case clsTransactionScreen::eTransferLog:
			system("cls");
			_ShowTransferLog();
			_GoToTransactionScreen();
		case clsTransactionScreen::eMainMenue: {


		}
		
		}



	}

public:
	static void ShowTransactionScreen() {

		if (!_CheckPermissionsOfUser(clsUser::pTranactions)) {


			return;
		}
		system("cls");
		_DrawScreenHeader("\t\tTransaction Screen ");

		cout << clsUtil::Tabs(5) << "===========================================\n";
		cout <<clsUtil::Tabs(5) << "\t\tTransaction Menue\n";
		cout << clsUtil::Tabs(5) << "===========================================\n";
		cout << setw(45) << left << " " << "[1]Deposite" << endl;
		cout << setw(45) << left << " " << "[2]Withdraw" << endl;
		cout << setw(45) << left << " " << "[3]Total Balance" << endl;
		cout << setw(45) << left << " " << "[4]Transfer" << endl;
		cout << setw(45) << left << " " << "[5]Transfer Log" << endl;
		cout << setw(45) << left << " " << "[6]Main Menue" << endl;
		cout << clsUtil::Tabs(5) << "===========================================\n";
		_PerformanceTransaction((enTransactionOption)_ReadTransactionOption());


	}



};

