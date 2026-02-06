#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>

class clsRegisterUsersScreen:protected clsScreen
{
    static void _PrintRegisterUsers(clsUser::stLoginRegister rUser) {


        cout << setw(8) << left << "" << "| " << left << setw(25) <<rUser.Date;
        cout << "| " << left << setw(20) << rUser.Username;
        cout << "| " << left << setw(12) <<rUser.Password;
        cout << "| " << left << setw(30) << rUser.Permissions;



   }
public:
	static void ShowRegisterUsersScreen() {

        if (!_CheckPermissionsOfUser(clsUser::enPermissions::pRegister)) {

            return;

        }
		vector<clsUser::stLoginRegister>vUsersReg = clsUser::GetUserRegister();
		string Title = "\t\t Login Register List Screen ";
		string SubTitle ="\t\t ( " + to_string(vUsersReg.size())+" )";
		_DrawScreenHeader(Title, SubTitle);



        cout <<setw(8) << left << "" << "\n\t_______________________________________________________________";
        cout << "________________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(25) << "Date/Time";
        cout << "| " << left << setw(20) << "UserName";
        cout << "| " << left << setw(12) << "Password";
        cout << "| " << left << setw(20) << "Permissions";
       
        cout << setw(8) << left << "" << "\n\t_______________________________________________________________";
        cout << "________________________________________________\n" << endl;
        if (vUsersReg.size() == 0) {

            cout << "\t\t\t\tNot Found Client :-)" << endl;

        }
        else {
            for (clsUser::stLoginRegister& U: vUsersReg) {
                _PrintRegisterUsers(U);
                cout << endl;
            }

        }
        cout << "\t-----------------------------------------------------------------------------------------------------------\n";

	}
};

