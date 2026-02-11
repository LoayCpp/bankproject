#pragma once
#include <iostream>

#include"clsScreen.h"
#include"Global.h"
#include"clsClientListScreen.h"
#include"clsAddNewClientScreen.h"
#include"clsDeleteClientScreen.h"
#include"clsUpdateClientScreen.h"
#include"clsFindClientScreen.h"
#include"clsTransactionScreen.h"
#include"clsManageUsers.h"
#include"clsRegisterUsersScreen.h"
#include"clsCurrencyExchangeMainScreen.h"
using namespace std;
class clsMainScreen:protected clsScreen
{
private:
	enum enMainMenueOptions {
		eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
		eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
		eManageUsers = 7,eRegister=8 ,eCarrency=9,eExit = 10
	};

	static short _ReadMainManueOption() {

		
		cout <<clsUtil::Tabs(4) <<"Choose what do you want to do? [1 to 10]? :";
		short num=clsInputValidate::ReadIntNumberBetween(1,10,"Enter The Number Between 1-8:");
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

		clsTransactionScreen::ShowTransactionScreen();
	

		}
	static void _ShowManageClientScreen() {

		
		clsManageUsers::ShowManageUsersMenue();

	}
	static void _ShowRegisterUsersScreen() {

		clsRegisterUsersScreen::ShowRegisterUsersScreen();
		
	}

	static void _ShowCurrencyExchange() {

		clsCurrencyExchangeMainScreen::ShowCurrencyScreen();


	}
	static void _Logout() {
	
		CurrentUser = clsUser::Find("", "");
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
		case clsMainScreen::eRegister:
			system("cls");
			_ShowRegisterUsersScreen();
			_GoToMainMenueScreen();
			break;
		case clsMainScreen::eCarrency:
			system("cls");
			_ShowCurrencyExchange();
			_GoToMainMenueScreen();
		case clsMainScreen::eExit:
			system("cls");
			_Logout();
			break;
		
		}




	}

public:

	static void ShowMainMenueScreen() {

		system("cls");
		_DrawScreenHeader("\t\tMain Screen");

		cout << clsUtil::Tabs(4) << "==============================================================\n";
		cout << setw(60)<<left<<" " <<clsUtil::ColorText("Main Menue\n",clsUtil::Cyan);
		cout << clsUtil::Tabs(4) << "==============================================================\n\n";
		cout << setw(37) << " " << clsUtil::ColorText("[1]  Show Client List\n",clsUtil::Green);
		cout << setw(37) << " " << clsUtil::ColorText("[2]  Add New Client\n",clsUtil::Green);
		cout << setw(37) << " " << clsUtil::ColorText("[3]  Delete Client\n",clsUtil::Green);
		cout << setw(37) << " " << clsUtil::ColorText("[4]  Update Client Info\n",clsUtil::Green);
		cout << setw(37) << " " << clsUtil::ColorText("[5]  Find Client\n",clsUtil::Green);
		cout << setw(37) << " " << clsUtil::ColorText("[6]  Transactions\n",clsUtil::Green);
		cout << setw(37) << " " << clsUtil::ColorText("[7]  Manage Users\n",clsUtil::Green);
		cout << setw(37) << " " << clsUtil::ColorText("[8]  Login Register\n",clsUtil::Green);
		cout << setw(37) << " " << clsUtil::ColorText("[9]  Currency Exhange\n",clsUtil::Green);
		cout << setw(37) << " " << clsUtil::ColorText("[10] Logout\n\n",clsUtil::Green);
		cout << clsUtil::Tabs(4) << "==============================================================\n";
		_PerfromMainMenueOption(enMainMenueOptions(_ReadMainManueOption()));

	}
};

