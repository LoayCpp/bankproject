#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsBankClient.h"
class clsDeleteClientScreen:protected clsScreen
{
private:
    static void _PrintClientInfo(clsBankClient Clinet) {

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
    static void ShowDeleteClientScreen() {
        if (!_CheckPermissionsOfUser(clsUser::pDeleteClient)) {


            return;
        }
        _DrawScreenHeader("\t\t Delete Clinet Screen");


        string AccountNumber = "";
        cout << "Enter The Number Client To Delete in File :";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsExitsClient(AccountNumber)) {

            cout << "This client isnot Find in file Enter The Number Client To Delete in File :";
            AccountNumber = clsInputValidate::ReadString();
        }
        clsBankClient client = clsBankClient::Find(AccountNumber);
        _PrintClientInfo(client);
        char Chosse = 'n';
        cout << "Do you want delete this client(y/n) :\t";
        cin >> Chosse;
        if (tolower(Chosse) == 'y') {

            if (client.Delete()) {


                cout << "successfully Delete \n";
                _PrintClientInfo(client);
            }



        }
        else {
            cout << "\n\t\t Cancel Delete\n";
        }


    }


};

