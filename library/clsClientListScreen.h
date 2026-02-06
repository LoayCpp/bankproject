#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsScreen.h"
#include<iomanip>
#include"clsUtil.h"
#include<string>
#include"clsUser.h"
using namespace std;

class clsClientListScreen :protected clsScreen
{
private:
    static void PrintClientInfo(clsBankClient Client) {

        cout << setw(8) << left << "" << "| " << setw(15) << left << Client.GetAccountNumber();
        cout << "| " << setw(20) << left << Client.FullName;
        cout << "| " << setw(12) << left << Client.Phone;
        cout << "| " << setw(30) << left << Client.Email;
        cout << "| " << setw(10) << left << Client.PinCode;
        cout << "| " << setw(12) << left << Client.Balance;

    }
    

public:
 static   void PrintListClient() {

     if (!clsScreen::_CheckPermissionsOfUser(clsUser::pListClients)) {

         return;
     }
        vector<clsBankClient>vClient = clsBankClient::GetListClient();

        cout << ("\t\t-----------------------------------------------------------------------\n");
       
        string Title = "\tClient List Screen ";
        string SubTitle = "\t(" + to_string(vClient.size()) + ")" + "Client(s) ";
        _DrawScreenHeader(Title, SubTitle);


        cout << setw(8) << left << "" << "\n\t_______________________________________________________________";
        cout << "________________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(30) << "Email";
        cout << "| " << left << setw(10) << "Pin Code";
        cout << "| " << left << setw(12) << "Balance";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________________";
        cout << "________________________________________________\n" << endl;
        if (vClient.size() == 0) {

            cout << "\t\t\t\tNot Found Client :-)" << endl;

        }
        else {
            for (clsBankClient& C : vClient) {
                PrintClientInfo(C);
                cout << endl;
            }

        }
        cout << "\t-----------------------------------------------------------------------------------------------------------\n";

    }
};

