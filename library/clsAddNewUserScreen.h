#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"
#include"clsInputValidate.h"
class clsAddNewUserScreen:protected clsScreen
{

    static int _ReadPermissionsToSet()
    {

        int Permissions = 0;
        char Answer = 'n';


        cout << "\nDo you want to give full access? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            return -1;
        }

        cout << "\nDo you want to give access to : \n ";

        cout << "\nShow Client List? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {


            Permissions += clsUser::enPermissions::pListClients;
        }

        cout << "\nAdd New Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pAddNewClient;
        }

        cout << "\nDelete Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pDeleteClient;
        }

        cout << "\nUpdate Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pUpdateClients;
        }

        cout << "\nFind Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pFindClient;
        }

        cout << "\nTransactions? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pTranactions;
        }

        cout << "\nManage Users? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pManageUsers;
        }
        cout << "\Register Show Users? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pRegister;
        }

        return Permissions;

    }

    
        static void _ReadUserInfo(clsUser & User)
        {
            cout << "\nEnter FirstName: ";
            User.FirstName = clsInputValidate::ReadString();

            cout << "\nEnter LastName: ";
            User.LastName = clsInputValidate::ReadString();

            cout << "\nEnter Email: ";
            User.Email = clsInputValidate::ReadString();

            cout << "\nEnter Phone: ";
            User.Phone = clsInputValidate::ReadString();

            cout << "\nEnter Password: ";
            User.Password = clsInputValidate::ReadString();

            cout << "\nEnter Permission: ";
            User.Permissions = _ReadPermissionsToSet();
        }

        static void _PrintUser(clsUser User)
        {
            cout << "\nUser Card:";
            cout << "\n___________________";
            cout << "\nFirstName   : " << User.FirstName;
            cout << "\nLastName    : " << User.LastName;
            cout << "\nFull Name   : " << User.FullName();
            cout << "\nEmail       : " << User.Email;
            cout << "\nPhone       : " << User.Phone;
            cout << "\nUser Name   : " << User.UserName;
            cout << "\nPassword    : " << User.Password;
            cout << "\nPermissions : " << User.Permissions;
            cout << "\n___________________\n";

        }
    
    


public :
	static void ShowAddUserScreen() {

        _DrawScreenHeader("\t\tAdd New User Screen");
        string UserName = "";
        cout << "Enter The Number Client To Add in File :";
        UserName = clsInputValidate::ReadString();
        while (clsUser::IsUserExist(UserName)) {
            cout << " The Number is Exists in File Please Enter The Number again  :";
            UserName = clsInputValidate::ReadString();
        }


        clsUser User = clsUser::GetAddNewUserObject(UserName);
        _ReadUserInfo(User);

        clsUser::enSaveResults SaveResult = User.Save();
        switch (SaveResult)
        {
        case clsUser::enSaveResults::svFaildEmptyObject:
            cout << "Is Empty Client please try again\n";
            break;

        case clsUser::enSaveResults::svSucceeded:
            cout << "Client Add successfully\n";
            _PrintUser(User);
            break;

        case clsUser::enSaveResults::svFaildUserExists:
            cout << "this client is found in file please enter another account number\n";
            break;
        }




	}

};

