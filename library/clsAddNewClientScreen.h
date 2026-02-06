#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsBankClient.h"
#include"clsUser.h"
using namespace std;
class clsAddNewClientScreen:protected clsScreen
{

private:
   static void _ReadClientInfo(clsBankClient& Client) {

        cout << "First Name   : ";
        Client.FirstName = clsInputValidate::ReadString();

        cout << "Last Name    : ";
        Client.LastName = clsInputValidate::ReadString();


        cout << "Email        : ";
        Client.Email = clsInputValidate::ReadString();

        cout << "phone        : ";
        Client.Phone = clsInputValidate::ReadString();

        cout << "PinCode      : ";
        Client.PinCode = clsInputValidate::ReadString();

        cout << "Balance        :";
        Client.Balance = clsInputValidate::ReadDblNumber();

    }

   static void _PrintClientInfo(clsBankClient Clinet){

		cout << "\n-----Info Client----------\n";
		cout << "FirstName        :" << Clinet.FirstName << endl;
		cout << "LastName         :" << Clinet.LastName << endl;
		cout << "FullName         :" << Clinet.FullName << endl;
		cout << "Email            :" << Clinet.Email << endl;
		cout << "Phone            :" << Clinet.Phone << endl;
		cout << "AccountNumber    :" << Clinet.AccountNumber << endl;
		cout << "PinCode          :" << Clinet.PinCode << endl;
		cout << "Balance          :" << Clinet.Balance << endl;
		cout << "------------------------------\n";


	}

public:



   static void ShowAddNewClientScreen() {

     if(!_CheckPermissionsOfUser(clsUser::pAddNewClient) ){


           return;
       }
       _DrawScreenHeader("\t\tAdd Client Screen");
        string AccountNumber = "";
        cout << "Enter The Number Client To Add in File :";
        AccountNumber = clsInputValidate::ReadString();
        while (clsBankClient::IsExitsClient(AccountNumber)) {
            cout << " The Number is Exists in File Please Enter The Number again  :";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient client = clsBankClient::GetAddClientModeAndAccount(AccountNumber);
        _ReadClientInfo(client);

        clsBankClient::enSaveResult SaveResult = client.Save();
        switch (SaveResult)
        {
        case clsBankClient::enFieldEmptyObject:
            cout << "Is Empty Client please try again\n";
            break;

        case clsBankClient::enSucceded:
            cout << "Client Add successfully\n";
            _PrintClientInfo(client);
            break;

        case clsBankClient::enClientAddIsExists:
            cout << "this client is found in file please enter another account number\n";
            break;
        }

    }
};

