#pragma once
#include <iostream>
#include"clsUtil.h"
#include"clsInputValidate.h"
#include"clsScreen.h"
#include"iomanip"
#include"clsClientListScreen.h"
#include"clsAddNewClientScreen.h"
#include"clsDeleteClientScreen.h"
#include"clsUpdateClientScreen.h"
#include"clsFindClientScreen.h"
using namespace std;
class clsMainScreen :protected clsScreen
{
private:
	enum enMainMenueOptions {
		eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
		eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
		eManageUsers = 7, eExit = 8
	};

	static short _ReadMainManueOption() {


		cout << clsUtil::Tabs(4) << "Choose what do you want to do? [1 to 8]? :";
		short num = clsInputValidate::ReadIntNumberBetween(1, 8, "Enter The Number Between 1-8:");
		return num;
	}

	static void _GoToMainMenueScreen() {


		cout << "\n\npress Any key to go Main Menue Screen...";
		system("pause>0");
		ShowMainMenueScreen();
	}

	static void _ShowAllClientsScreen() {

		clsClientListScreen::PrintListClient();


	}
	static void _ShowAddNewClientsScreen() {

		clsAddNewClientScreen::ShowAddNewClientScreen();
	}
	static void ShowDeleteClientScreen() {

		clsDeleteClientScreen::ShowDeleteClientScreen();
	}
	static void _ShowUpdateClientScreen() {
		clsUpdateClientScreen::ShowUpdateClientScreen();
	}
	static void _ShowFindClientScreen() {
		clsFindClientScreen::ShowFindClientScreen();
	}
	static void _ShowTransactionClientScreen() {

		cout << "Transaction Clinet Screen Will Be here\n";


	}
	static void _ShowManageClientScreen() {

		cout << "Manage Clinet Screen Will Be here\n";


	}
	static void _ShowEndScreen() {
		cout << "End Screen  Will Be here\n";

	}
	static void _PerfromMainMenueOption(enMainMenueOptions Option) {

		switch (Option)
		{
		case clsMainScreen::eListClients:
			system("cls");
			_ShowAllClientsScreen();
			_GoToMainMenueScreen();
			break;
		case clsMainScreen::eAddNewClient:
			system("cls");
			_ShowAddNewClientsScreen();
			_GoToMainMenueScreen();
			break;
		case clsMainScreen::eDeleteClient:
			system("cls");
			ShowDeleteClientScreen();
			_GoToMainMenueScreen();
			break;
		case clsMainScreen::eUpdateClient:
			system("cls");
			_ShowUpdateClientScreen();
			_GoToMainMenueScreen();
			break;
		case clsMainScreen::eFindClient:
			system("cls");
			_ShowFindClientScreen();
			_GoToMainMenueScreen();
			break;
		case clsMainScreen::eShowTransactionsMenue:
			system("cls");
			_ShowTransactionClientScreen();
			_GoToMainMenueScreen();
			break;
		case clsMainScreen::eManageUsers:
			system("cls");
			_ShowManageClientScreen();
			_GoToMainMenueScreen();
			break;
		case clsMainScreen::eExit:
			system("cls");
			_ShowEndScreen();
			_GoToMainMenueScreen();
			break;

		}




	}

public:

	static void ShowMainMenueScreen() {

		system("cls");
		_DrawScreenHeader("\t\tMain Screen");

		cout << clsUtil::Tabs(4) << "==============================================================\n";
		cout << setw(60) << left << " " << "Main Menue\n";
		cout << clsUtil::Tabs(4) << "==============================================================\n\n";
		cout << setw(37) << " " << "[1] Show Client List\n";
		cout << setw(37) << " " << "[2] Add New Client\n";
		cout << setw(37) << " " << "[3] Delete Client\n";
		cout << setw(37) << " " << "[4] Update Client Info\n";
		cout << setw(37) << " " << "[5] Find Client\n";
		cout << setw(37) << " " << "[6] Transactions\n";
		cout << setw(37) << " " << "[7] Manage Users\n";
		cout << setw(37) << " " << "[8] Logout\n\n";
		cout << clsUtil::Tabs(4) << "==============================================================\n";
		_PerfromMainMenueOption(enMainMenueOptions(_ReadMainManueOption()));

	}
};

