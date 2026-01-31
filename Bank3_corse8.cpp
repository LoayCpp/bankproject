
#include <iostream>
#include"clsInputValidate.h"
#include"clsBankClient.h"
#include<cstdlib>
#include<iomanip>
#include"clsUtil.h"
#include"clsScreen.h"
#include"clsMainScreen.h"
using namespace std;

void ReadClientInfo(clsBankClient& Client) {

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
void UpdateClient() {
    string Account = "";
    cout << "Enter The Account Number With Update: ";
    Account = clsInputValidate::ReadString();

    while (!clsBankClient::IsExitsClient(Account)) {
        cout << "Account number is not found, choose another one: ";
        Account = clsInputValidate::ReadString();
    }


    clsBankClient Client = clsBankClient::Find(Account);
    Client.Print();

    ReadClientInfo(Client);


    clsBankClient::enSaveResult Result = Client.Save();
    switch (Result)
    {
    case clsBankClient::enFieldEmptyObject: {
        cout << "This Error the Client Empty\n";

        break;
    }
    case clsBankClient::enSucceded: {
        cout << "Clinet Update client Successfully :-)\n";

        Client.Print();

        break;
    }

    }


}
void AddNewClient() {
    string AccountNumber = "";
    cout << "Enter The Number Client To Add in File :";
    AccountNumber = clsInputValidate::ReadString();
    while (clsBankClient::IsExitsClient(AccountNumber)) {
        cout << " The Number is Exists in File Please Enter The Number again  :";
        AccountNumber = clsInputValidate::ReadString();
    }

    clsBankClient client = clsBankClient::GetAddClientModeAndAccount(AccountNumber);
    ReadClientInfo(client);
    clsBankClient::enSaveResult SaveResult = client.Save();
    switch (SaveResult)
    {
    case clsBankClient::enFieldEmptyObject:
        cout << "Is Empty Client please try again\n";
        break;

    case clsBankClient::enSucceded:
        cout << "Client Add successfully\n";
        client.Print();
        break;

    case clsBankClient::enClientAddIsExists:
        cout << "this client is found in file please enter another account number\n";
        break;
    }

}
void DeleteClient() {
    string AccountNumber = "";
    cout << "Enter The Number Client To Delete in File :";
    AccountNumber = clsInputValidate::ReadString();
    while (!clsBankClient::IsExitsClient(AccountNumber)) {

        cout << "This client isnot Find in file Enter The Number Client To Delete in File :";
        AccountNumber = clsInputValidate::ReadString();
    }
    clsBankClient client = clsBankClient::Find(AccountNumber);
    client.Print();
    char Chosse = 'n';
    cout << "Do you want delete this client \n";
    cin >> Chosse;
    if (tolower(Chosse) == 'y') {

        if (client.Delete()) {


            cout << "successfully Delete \n";
            client.Print();
        }



    }
    else {
        cout << "Cancel Delete\n";
    }


}

void PrintClientRecordBalanceLine(clsBankClient Client) {
    cout << "|" << left << setw(15) << Client.GetAccountNumber();
    cout << "|" << left << setw(25) << Client.FullName;
    cout << "|" << left << setw(12) << Client.Balance;


}
void ShowTotalBalance() {
    vector<clsBankClient>vClient = clsBankClient::GetListClient();
    cout << ("----------------------------------------------------------------------------------------------------------------------\n");
    cout << "\n\t\t\t\t   Client List (" << vClient.size() << ") Client(s)   \n\n";
    cout << clsUtil::clsUtil::ColorText("----------------------------------------------------------------------------------------------------------------------\n");
    cout << clsUtil::ColorText("|") << left << setw(15) << "Account Number";
    cout << clsUtil::ColorText("|") << left << setw(25) << "Client Name";
    cout << clsUtil::ColorText("|") << left << setw(12) << "Balance" << endl;
    cout << clsUtil::ColorText("----------------------------------------------------------------------------------------------------------------------\n");
    if (vClient.size() == 0) {

        cout << "Don`t Found Any Client \n";
    }
    else {

        for (clsBankClient& c : vClient) {

            PrintClientRecordBalanceLine(c);
            cout << endl;
        }
    }
    cout << clsUtil::ColorText("----------------------------------------------------------------------------------------------------------------------\n");
    double TotalBalance = clsBankClient::TotalBalance();
    cout << "Total Balanc = " << TotalBalance << endl;
    cout << clsUtil::ColorText(clsUtil::NumberToText(TotalBalance), clsUtil::Cyan) << endl;

}
int main()

{


    clsMainScreen::ShowMainMenueScreen();

    system("pause>0");
    return 0;

}