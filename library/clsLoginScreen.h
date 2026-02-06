#pragma once
#include<iostream>
#include"clsUser.h"
#include"clsScreen.h"
#include<string>
#include"Global.h"
#include"clsMainScreen.h"
#include"clsInputValidate.h"
#include<fstream>
class clsLoginScreen:protected clsScreen
{

	
	static bool _login() {

		short Count = 3;
		bool MarkIsFound = false;
		
		do {

			if (MarkIsFound) {

				Count--;
				cout << "\n Invalid UserName/Password\n\n";
				cout << " You have " << Count << " Trials to login.\n\n";
			}
			if (Count == 0) {

				cout << "You are lock after 3 faild trails \n";

				return false;
			}

			string UserName, Password;
			cout << "Enter The UserName :";
			UserName = clsInputValidate::ReadString();
			cout << "Enter The Password :";
			Password = clsInputValidate::ReadString();

			CurrentUser = clsUser::Find(UserName, Password);
			MarkIsFound = CurrentUser.IsEmpty();





		} while (MarkIsFound);
		CurrentUser.RegisterLogin();
		clsMainScreen::ShowMainMenueScreen();
		return true;
	}

public:


public:
	static bool ShowLoginScreen() {
		system("cls");
		_DrawScreenHeader("\t\t Login Screen");
	return _login();
	

		




	}
};

