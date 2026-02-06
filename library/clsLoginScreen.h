#pragma once
#include<iostream>
#include"clsUser.h"
#include"clsScreen.h"
#include<string>
#include"Global.h"
#include"clsMainScreen.h"
#include"clsInputValidate.h"
class clsLoginScreen:protected clsScreen
{

	static void _login() {

	
		bool MarkIsFound = false;

		do {

			if (MarkIsFound) {


				cout << "Invalid UserName/Password";

			}
			string UserName, Password;
			cout << "Enter The UserName :";
			UserName = clsInputValidate::ReadString();
			cout << "Enter The Password :";
			Password = clsInputValidate::ReadString();

			CurrentUser = clsUser::Find(UserName, Password);
			MarkIsFound = CurrentUser.IsEmpty();





		} while (MarkIsFound);

		clsMainScreen::ShowMainMenueScreen();
		
	}

public:


public:
	static void ShowLoginScreen() {
		system("cls");
		_DrawScreenHeader("\t\t Login Screen");
		_login();
	

		




	}
};

