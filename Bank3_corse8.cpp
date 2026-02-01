
#include <iostream>
#include"clsInputValidate.h"
#include"clsBankClient.h"
#include<cstdlib>
#include<iomanip>
#include"clsUtil.h"
#include"clsScreen.h"
#include"clsMainScreen.h"
using namespace std;


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