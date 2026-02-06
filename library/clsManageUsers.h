#pragma once
#include"clsScreen.h"
#include<iostream>
#include<iomanip>
#include"clsInputValidate.h"
#include"clsListUsersScreen.h"
#include"clsAddNewUserScreen.h"
#include"clsDeleteUserScreen.h"
#include"clsUpdateUserScreen.h"	
#include"clsFindUserScreen.h"
class clsManageUsers:protected clsScreen
{

private:
	enum enManageUsersMenueOption{eListUsers=1,eAddUsers=2,eDeleteUsers=3,eUpdateUsers=4,eFindUsers=5,eMainMenue=6};
	static short _ReadOptionMangeUsers() {
		short Num = 0;
		cout  << setw(37) << left << "" <<"Choose what do you want to do? [1 to 6]?";
		Num = clsInputValidate::ReadShortNumberBetween(1,6,"Enter The Number Between 1-6 :");
		return Num;

	}
	static void _GoToManageUsersScreen() {

		cout << setw(37) << left << "" <<"Press any key to go Manage Menue Screen ....";
		system("pause>0");
		ShowManageUsersMenue();

	}
	static void _ShowListUsersScreen() {

		clsListUsersScreen::ShowUsersList();

	}
	static void _ShowAddUsersScreen() {

		clsAddNewUserScreen::ShowAddUserScreen();
	}
	static void _ShowDeleteUsersScreen() {

		clsDeleteUserScreen::ShowDeleteUserScreen();

	}
	static void _ShowUpdateUsersScreen() {

		clsUpdateUserScreen::ShowUpdateUserScreen();

	}
	static void _ShowFindUsersScreen() {

		clsFindUserScreen::ShowFindUserScreen();

	}
	static void _PerformManageUsersMenueOption(enManageUsersMenueOption Option) {

		switch (Option)
		{
		case clsManageUsers::eListUsers:
			system("cls");
			_ShowListUsersScreen();
			_GoToManageUsersScreen();
			break;
		case clsManageUsers::eAddUsers:
			system("cls");
			_ShowAddUsersScreen();
			_GoToManageUsersScreen();
			break;
		case clsManageUsers::eDeleteUsers:
			system("cls");
			_ShowDeleteUsersScreen();
			_GoToManageUsersScreen();
			break;
		case clsManageUsers::eUpdateUsers:
			system("cls");
			_ShowUpdateUsersScreen();
			_GoToManageUsersScreen();
			break;
		case clsManageUsers::eFindUsers:
			system("cls");
			_ShowFindUsersScreen();
			_GoToManageUsersScreen();
			break;

		case clsManageUsers::eMainMenue: {



		}


			
		
		}

	}
public:
	static void ShowManageUsersMenue() {
		if (!_CheckPermissionsOfUser(clsUser::pManageUsers)) {


			return;
		}
		system("cls");
		_DrawScreenHeader("\t\t Manage User Screen ");
		cout << setw(37) << left << "" << "===========================================================================\n";
		cout << setw(37) << left << "" << "\t\t\tManage User Menue\n";
		cout << setw(37) << left << "" << "===========================================================================\n";
		cout << setw(37) << left << "" << "\t[1] List Users.\n";
		cout << setw(37) << left << "" << "\t[2] Add New User.\n";
		cout << setw(37) << left << "" << "\t[3] Delete User.\n";
		cout << setw(37) << left << "" << "\t[4] Update User.\n";
		cout << setw(37) << left << "" << "\t[5] Find User.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================================================\n";


		_PerformManageUsersMenueOption((enManageUsersMenueOption)_ReadOptionMangeUsers());

	}
};

