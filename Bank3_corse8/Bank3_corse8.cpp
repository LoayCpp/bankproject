

#include <iostream>
#include<vector>
#include<string>
#include <fstream>
#include<iomanip>
#include<cstdlib>
using namespace std;
enum enMainMenueOptions { ShowAllUser = 1, AddClient = 2, Delete = 3, Update = 4, find = 5, Transaction = 6,ManageUsers=7 ,logout = 8 };
enum enTransactionOptions { enDeposit = 1, enWithdrow = 2, enTotalBalance = 3, enMainMenue = 4 };
enum enManageUsersOption{enListUsers=1,enAddUsers=2,enDeleteUsers=3 ,enUpdateUsers=4,enFindUsers=5,enMainMenueScreen=6 };
enum enPermaission{enAllPermission=-1,enShowClientPermission=1,enAddClientPermission=2,enDeleteClientPermassion=4,enUpdateClientPermassion=8,enFindClientPermassion=16,enTransactionpermission=32,enManageUsers=64};
const string FileClient = "loay2w.txt";
const string UsersFlie = "Users.txt";
struct stinfo {
    string account, name;
    string pincode;
    string phoneNumber;
    float countbalance;
    bool flag = false;


};
struct stUsers
{
    string Name;
    string Password;
    enPermaission Permission;
    bool flag = false;

};
void ShowTransAction();
void ShowMainMenue();
void ShowManageUsersScreen();
void  login();
stUsers CurrentUser;
bool isfound(string account, stinfo& client, vector<stinfo>& Vword)
{



    for (stinfo& s : Vword) {

        if (account == s.account) {

            client = s;
            return true;

        }


    }

    return false;






}
bool isfound(string Name, stUsers& User, vector<stUsers>& Vuser)
{



    for (stUsers& s : Vuser) {

        if (Name == s.Name) {

            User = s;
            return true;

        }


    }

    return false;






}

string space(short num) {
    string s = "";
    for (short i = 0; i <= num; i++)
    {
        s += "\t";
    }

    return s;
}
vector <stinfo>Vinfo() {
    stinfo information;
    vector<stinfo>Vinformation;
    cout << "enter acount number :";
    cin >> information.account;
    cout << "enter name :";
    cin >> information.name;
    cout << "enter pincode :";
    cin >> information.pincode;
    cout << "enter phonenumber :";
    cin >> information.phoneNumber;
    cout << "enter countbalance :";
    cin >> information.countbalance;
    Vinformation.push_back(information);
    return Vinformation;
}
string Joinstring(vector<stinfo> infor, string delim) {

    string s = "";
    for (stinfo& line : infor) {


        s += line.account + delim;
        s += line.name + delim;
        s += line.pincode + delim;
        s += line.phoneNumber + delim;
        s += to_string(line.countbalance) + delim;
    }


    return s.substr(0, s.length() - delim.length());

}

void printinfo(vector<stinfo> in) {


    for (stinfo& i : in) {

        cout << i.name << endl;
        cout << i.account << endl;
        cout << i.pincode << endl;
        cout << i.phoneNumber << endl;
        cout << i.countbalance << endl;
    }





}


stinfo Read_stinfo() {

    stinfo info;

    cout << "enter acount number :";
    getline(cin >> ws, info.account);
    cout << "enter name :";
    getline(cin, info.name);
    cout << "enter pincode :";
    getline(cin, info.pincode);
    cout << "enter phonenumber :";
    getline(cin, info.phoneNumber);
    cout << "enter countbalance :";
    cin >> info.countbalance;

    return info;




}
string JoinStringUserToStructUs(stUsers user, string delim = "#//#") {


    string s = "";
    s += user.Name + delim;
    s += user.Password + delim;
    s += to_string(user.Permission) + delim;
    

    return s.substr(0, s.length() - delim.length());

}
string JoinString_struct(stinfo strinfo, string delim = "#//#") {


    string s = "";
    s += strinfo.account + delim;
    s += strinfo.name + delim;
    s += (strinfo.pincode) + delim;
    s += (strinfo.phoneNumber) + delim;
    s += to_string(strinfo.countbalance) + delim;

    return s.substr(0, s.length() - delim.length());

}
vector <string> split(string name, string delim = "#//#") {
    vector<string> Vword;
    short pos = 0;
    string s = "";
    while ((pos = name.find(delim)) != std::string::npos) {

        s = name.substr(0, pos);
        if (s != "") {

            Vword.push_back(s);

        }

        name = name.erase(0, pos + delim.length());


    }
    if (name != "") {


        Vword.push_back(name);
    }


    return Vword;


}
stUsers ConvertFromFileUsersToStructUsers(string name, string delim = "#//#") {
    stUsers User;
    vector<string>Vusers = split(name, delim);
    User.Name = Vusers[0];
    User.Password = Vusers[1];
    User.Permission = enPermaission(stoi(Vusers[2])) ;


    return User;

}
stinfo converFromVectorToStruct(string name, string delim = "#//#") {
    stinfo info;
    vector<string> Vword = split(name, delim);

    info.account = Vword[0];
    info.name = (Vword[1]);
    info.pincode = Vword[2];
    info.phoneNumber = (Vword[3]);
    info.countbalance = stof(Vword[4]);

    return info;

}
void printstruct(stinfo st) {




    cout << "account=" << st.account << endl;
    cout << "name=" << st.name << endl;
    cout << "pincode=" << st.pincode << endl;
    cout << "phoneNumber=" << st.phoneNumber << endl;
    cout << "countbalance=" << st.countbalance << endl;

}
void Readinfile(string namefile, string word) {

    fstream file;
    file.open(namefile, ios::out | ios::app);
    if (file.is_open()) {

        file << word << endl;





    }


    file.close();
}

vector<stUsers> LoadFomeUsersFile(string file) {
    vector<stUsers>Vusers;
    fstream myfile;
    string line;
    stUsers user;

    myfile.open(file, ios::in);
    if (myfile.is_open()) {


        while (getline(myfile, line)) {

            user = ConvertFromFileUsersToStructUsers(line);
            Vusers.push_back(user);


        }



        myfile.close();

    }





    return Vusers;

}

vector<stinfo> loadfromfile(string file) {
    vector<stinfo>Vclien;
    fstream myfile;
    string line;
    stinfo stclient;

    myfile.open(file, ios::in);
    if (myfile.is_open()) {


        while (getline(myfile, line)) {

            stclient = converFromVectorToStruct(line);
            Vclien.push_back(stclient);


        }



        myfile.close();

    }





    return Vclien;

}

void PrintUsersInformation(stUsers information) {

    cout << "|" << setw(17) << left << information.Name;
    cout << "|" << setw(17) << left << information.Password;
    cout << "|" << setw(17) << left << information.Permission;
  
  

}
void printoi(stinfo informa) {

    cout << "|" << setw(17) << left << informa.account;
    cout << "|" << setw(17) << left << informa.name;
    cout << "|" << setw(17) << left << informa.pincode;
    cout << "|" << setw(17) << left << informa.phoneNumber;
    cout << "|" << setw(20) << left << informa.countbalance;

}
void printoTotal(stinfo informa) {

    cout << "|" << setw(17) << left << informa.account;
    cout << "|" << setw(17) << left << informa.name;

    cout << "|" << setw(20) << left << informa.countbalance;

}
void PrintAllUsersInSystem() {
    
    vector<stUsers>Vusers = LoadFomeUsersFile(UsersFlie);
    cout << space(4) << "Users List (" << Vusers.size() << ")  " << "Users(s)" << endl;
    cout << "-----------------------------------------------------------------------------\n";
   
    cout << "|" << left << setw(17) << "User Name";
    cout << "|" << left << setw(17) << "Password";
    cout << "|" << left << setw(17) << "Permission";
    
    cout << "\n----------------------------------------------------------------------------\n";

   
     {
        for (stUsers vline : Vusers) {


            PrintUsersInformation(vline);
            cout << endl;

        }
    }
     cout << "\n----------------------------------------------------------------------------\n";





}
void printAllVectors() {
    vector<stinfo>Vword = loadfromfile(FileClient);
    cout << space(4) << "Client List (" << Vword.size() << ")  " << "Client(s)" << endl;
    cout << "--------------------------------------------------------------------------------------------------------\n";
    cout << "|" << left << setw(17) << "acount_number";
    cout << "|" << left << setw(17) << " Name";
    cout << "|" << left << setw(17) << "pincode";
    cout << "|" << left << setw(17) << "phonenumber";
    cout << "|" << left << setw(20) << "countbalance" << endl;
    cout << "---------------------------------------------------------------------------------------------\n";

    if (Vword.size() == 0) {


        cout << "\t\t\t\tNo Clients Available In the System!\n";

    }
    else {
        for (stinfo vline : Vword) {


            printoi(vline);
            cout << endl;

        }
    }
    cout << "--------------------------------------------------------------------------------------------------------\n";

}
void PrintCardClient(stinfo client) {
    cout << "--------------------------------------------------------------------------------------------------------\n";
    cout << "Name Acount  :" << client.account << endl;
    cout << "User Name    :" << client.name << endl;
    cout << "pincode      :" << client.pincode << endl;
    cout << "phoneNumber  :" << client.phoneNumber << endl;
    cout << "countbalance :" << client.countbalance << endl;
    cout << "--------------------------------------------------------------------------------------------------------\n";
}
void PrintCardUsers(stUsers User) {
    cout << "--------------------------------------------------------------------------------------------------------\n";
    cout << "User Name:" << User.Name << endl;
    cout << "Password:" << User.Password << endl;
    cout << "permmission:" << User.Permission << endl;

    cout << "--------------------------------------------------------------------------------------------------------\n";
}

string ReadStringAnyThing(string message) {

    string Anything;
    cout <<message;
    cin >> Anything;
    return Anything;

}
bool MarkforStruct(string account, vector<stinfo>& Vname) {

    for (stinfo& S : Vname) {
        if (account == S.account) {

            S.flag = true;

            return  true;
        }




    }

    return false;


}
bool MarkFlagToUsers(string Name, vector<stUsers>& Vname) {

    for (stUsers& S : Vname) {
        if (Name == S.Name) {

            S.flag = true;

            return  true;
        }




    }

    return false;


}
void loadVectorTofile(vector<stinfo>& Vname) {

    fstream myfile;
    string word = "";
    myfile.open(FileClient, ios::out);

    if (myfile.is_open()) {
        for (stinfo& S : Vname) {

            if (S.flag == false) {



                word = JoinString_struct(S);
                myfile << word << endl;
            }


        }




        myfile.close();
    }
    else {


        cout << "this file not open\n";

    }

}
void WriteVectorInToUsersFile(vector<stUsers>& Vname) {

    fstream myfile;
    string word = "";
    myfile.open(UsersFlie, ios::out);

    if (myfile.is_open()) {
        for (stUsers& S : Vname) {

            if (S.flag == false) {



                word = JoinStringUserToStructUs(S);
                myfile << word << endl;
            }


        }




        myfile.close();
    }
    else {


        cout << "this file not open\n";

    }

}

bool DeleteClient(vector<stinfo>& Vname) {
    string account = ReadStringAnyThing("Enter the Account");
    stinfo client;
    char ch = 'n';
    if (isfound(account, client, Vname)) {

        PrintCardClient(client);
        cout << "do you want delete this item (y/n):";
        cin >> ch;
        if (tolower(ch) == 'y') {
            MarkforStruct(account, Vname);
            loadVectorTofile(Vname);
            cout << "Delete successfuly\n";
        }

        Vname = loadfromfile(FileClient);

        return true;
    }
    else {


        cout << "Client with Account Number( " << account << ") is Not Found\n";
    }
    return false;
}
bool DeleteUser(vector<stUsers>& Vuser) {
    string Name = ReadStringAnyThing("Enter The Name:\t");
    stUsers User;
    if (Name == "Admin") {
        cout << "Cannot delete this account because it is an administrator.";
        return false;
    }
    char ch = 'n';
    if (isfound(Name, User, Vuser)) {

        PrintCardUsers(User);
        cout << "Are you sure you want delete this User?(y/n):";
        cin >> ch;
        if (tolower(ch) == 'y') {
            MarkFlagToUsers(Name, Vuser);
            WriteVectorInToUsersFile(Vuser);
            cout << "Delete successfuly\n";
        }

        Vuser = LoadFomeUsersFile(UsersFlie);

        return true;
    }
    else {


        cout << "Client with Account Number( " << Name << ") is Not Found\n";
    }
    return false;
}
bool IsAccountFindInFile(string account, string filename) {

    vector<stinfo>Vword;
    fstream myfile;
    myfile.open(filename, ios::in);
    string word;
    stinfo client;
    if (myfile.is_open()) {
        while (getline(myfile, word)) {


            client = converFromVectorToStruct(word);
            if (client.account == account) {
                myfile.close();
                return true;

            }




            Vword.push_back(client);
        }

        myfile.close();



    }



    return false;



}
bool IsNameFindInFile(string Name, string filename) {

    vector<stUsers>Vword;
    fstream myfile;
    myfile.open(filename, ios::in);
    string word;
    stUsers user;
    if (myfile.is_open()) {
        while (getline(myfile, word)) {


            user = ConvertFromFileUsersToStructUsers(word);
            if (user.Name == Name) {
                myfile.close();
                return true;

            }




            Vword.push_back(user);
        }

        myfile.close();



    }



    return false;



}
enPermaission ReadPermissionUsers() {
    char ch = 'n';
    enPermaission permission=(enPermaission)0;
    cout << "Do you want give full access? (y/n)?";
    cin >> ch;
    if (tolower(ch) =='y') {

     return  enPermaission::enAllPermission;
    }
    else
    {
            cout << "Do you want to give access to :\n";
            cout << "Show Client List? y/n?";
            cin >> ch;
            if (tolower(ch) == 'y')
            { permission = (enPermaission)(permission | enPermaission::enShowClientPermission); }
            cout << "Add New Client ? y / n ?";
            cin >> ch;
            if (tolower(ch) == 'y')
            {
                permission = (enPermaission) (permission | enPermaission::enAddClientPermission);
            }
            cout << "Delete Client ? y / n ?";
            cin >> ch;
            if (tolower(ch) == 'y')
            {
                permission = (enPermaission)(permission | enPermaission::enDeleteClientPermassion);
            }
            cout << "Update Client ? y / n?";
            cin >> ch;
            if (tolower(ch) == 'y')
            {
                permission = (enPermaission)(permission | enPermaission::enUpdateClientPermassion);
            }
            cout << "Find Client ? y / n?";
            cin >> ch;
            if (tolower(ch) == 'y')
            {
                permission = (enPermaission)(permission | enPermaission::enFindClientPermassion);
            }
            cout << "Transactions ? y / n ?";
            cin >> ch;
            if (tolower(ch) == 'y')
            {
                permission = (enPermaission)(permission | enPermaission::enTransactionpermission);
            }
            cout << "Manage Users ? y / n ?";
            cin >> ch;
            if (tolower(ch) == 'y')
            {
                permission = (enPermaission)(permission | enPermaission::enManageUsers);
            }

    }

    return permission;


}
stUsers ReadUser() {

    stUsers user;

    cout << "Enter UserName :";
    getline(cin >> ws, user.Name);
    while (IsNameFindInFile(user.Name,UsersFlie)) {
        cout << "Client with [" << user.Name << "] already Exists,Enter another Name again:\n Enter The Name:";
        getline(cin >> ws, user.Name);

    }
    cout << "Enter Password :";
    getline(cin >> ws, user.Password);
    user.Permission = ReadPermissionUsers();
   

    return user;
}

stinfo ReadClient() {

    stinfo info;

    cout << "enter the count number :";
    getline(cin >> ws, info.account);
    while (IsAccountFindInFile(info.account, FileClient)) {
        cout << "Client with [" << info.account << "] already Exists,Enter another Number again:\t";
        getline(cin >> ws, info.account);

    }
    cout << "enter name :";
    getline(cin >> ws, info.name);
    cout << "enter pincode :";
    getline(cin, info.pincode);
    cout << "enter phonenumber :";
    getline(cin, info.phoneNumber);
    cout << "enter countbalance :";
    cin >> info.countbalance;

    return info;
}
stinfo ReadClient(string account) {

    stinfo info;

    info.account = account;
    cout << "enter name :";
    getline(cin >> ws, info.name);
    cout << "enter pincode :";
    getline(cin, info.pincode);
    cout << "enter phonenumber :";
    getline(cin, info.phoneNumber);
    cout << "enter countbalance :";
    cin >> info.countbalance;

    return info;
}

void AddNewUsers() {
    stUsers user = ReadUser();

    Readinfile(UsersFlie, JoinStringUserToStructUs(user));

}
void AddNewclient() {
   
    stinfo info = ReadClient();
    Readinfile(FileClient, JoinString_struct(info));

}

void Addclient() {

    char ch = 'y';
    string name;
    do {
        system("cls");
        cout << "Add new client:\n\n";
        AddNewclient();

        cout << "do you want to write in file:(y/n):";
        cin >> ch;

    } while (tolower(ch) == 'y');

}
void AddUsers() {

    char ch = 'y';
    string name;
    do {
       
        cout << "Adding New Users:\n\n";
        AddNewUsers();

        cout << "Add User Successfully,do you want to write in file:(y/n):";
        cin >> ch;

    } while (tolower(ch) == 'y');

}
bool EditUser(vector<stUsers>&Vuser) {
   
    string Name = ReadStringAnyThing("Enter the Name");
    if (Name == "Admin") {
        cout << "Cannot update this account because it is an administrator.";
        return false;
    }

        char ch = 'n';
        stUsers user;
        if (isfound(Name, user, Vuser)) {

            PrintCardUsers(user);
            cout << "do you want edit this user (y/n):";
            cin >> ch;
            if (tolower(ch) == 'y') {


                for (stUsers& S : Vuser) {
                    if (S.Name == Name) {
                        cout << "Enter Password :";
                        getline(cin >> ws, user.Password);
                        S.Password = user.Password;
                        S.Permission = ReadPermissionUsers();
                        WriteVectorInToUsersFile(Vuser);
                        break;
                    }

                }
                cout << "Update successfuly\n";
                Vuser = LoadFomeUsersFile(UsersFlie);
                return true;
            }

        }
        else {


            cout << "Client with Account Number( " << Name << ") is Not Found\n";
        }

        return false;
    }




void UpdateUserScreen() {
    vector<stUsers>Vuser = LoadFomeUsersFile(UsersFlie);

    cout << "==========================================================\n";
    cout << space(1) << "Update Users Screen\n";
    cout << "==========================================================\n";

    EditUser(Vuser);


}
bool EditClient(vector<stinfo>& Vname) {
    string account = ReadStringAnyThing("Enter Account \n");
    char ch = 'n';
    stinfo client;
    if (isfound(account, client, Vname)) {

        PrintCardClient(client);
        cout << "do you want edit this item (y/n):";
        cin >> ch;
        if (tolower(ch) == 'y') {


            for (stinfo& S : Vname) {
                if (S.account == account) {
                    S = ReadClient(account);
                    loadVectorTofile(Vname);
                    break;
                }

            }
            cout << "Update successfuly\n";
            Vname = loadfromfile(FileClient);
            return true;
        }

    }
    else {


        cout << "Client with Account Number( " << account << ") is Not Found\n";
    }

    return false;
}
void UpdateClientScreen() {
    vector<stinfo>Vword = loadfromfile(FileClient);
    cout << "==========================================================\n";
    cout << space(1) << "Update Client Screen\n";
    cout << "==========================================================\n";

    EditClient(Vword);


}
void DeleteClientScreen() {
    vector<stinfo>Vword = loadfromfile(FileClient);
    cout << "==========================================================\n";
    cout << space(1) << "Delete Client Screen\n";
    cout << "==========================================================\n";

    (DeleteClient(Vword));


}
void AddClientAndCheck() {

    cout << "==========================================================\n";
    cout << space(1) << "Add New Client Screen\n";
    cout << "==========================================================\n";
    Addclient();








}
void AddUserInSystem() {

    cout << "==========================================================\n";
    cout << space(1) << "Add New Users Screen\n";
    cout << "==========================================================\n";
    



    AddUsers();




}
void DeleteUsersScreen() {
    vector<stUsers>Vword = LoadFomeUsersFile(UsersFlie);
    cout << "==========================================================\n";
    cout << space(1) << "Delete Users Screen\n";
    cout << "==========================================================\n";

    (DeleteUser(Vword));


}
void FindUserInFile() {
    vector<stUsers>Vuser = LoadFomeUsersFile(UsersFlie);
    cout << "==========================================================\n";
    cout << space(1) << "Find Users Screen\n";
    cout << "==========================================================\n";
    stUsers user;
    string Name = ReadStringAnyThing("Enter the Name:");
    if (isfound(Name, user, Vuser)) {
        PrintCardUsers(user);
    }
    else {


        cout << "Client with Account Number( " << Name << ") is Not Found\n";
    }



}
void Select() {
    vector<stinfo>Vword = loadfromfile(FileClient);
    cout << "==========================================================\n";
    cout << space(1) << "Find Client Screen\n";
    cout << "==========================================================\n";
    stinfo client;
    string account = ReadStringAnyThing("Enter the Account \n");
    if (isfound(account, client, Vword)) {
        PrintCardClient(client);
    }
    else {


        cout << "Client with Account Number( " << account << ") is Not Found\n";
    }



}
void GoToMainMenue() {


    cout << "\n\nPress any key to go back to Main Menue...";
    system("pause>0");
    ShowMainMenue();


}
void TheEnd() {


    cout << "----------------------------------------\n";
    cout << space(2) << "Project End :-)\n";

    cout << "----------------------------------------\n";





}
double ReadAmount(string message) {

    double ammount = 0;
    cout << message;
    cin >> ammount;
    return ammount;

}
void GoToTransactoinMenue() {


    cout << "\n\nPress any key to go back to Transaction Menue...";
    system("pause>0");
    ShowTransAction();


}
void GoToManageUsersMenue() {


    cout << "\n\nPress any key to go back to ManageUsers Menue...";
    system("pause>0");
    ShowManageUsersScreen();


}
void sumammount(string account, double ammount, vector<stinfo>& Vword) {

    for (stinfo& C : Vword) {
        if (C.account == account) {
            C.countbalance += ammount;
            loadVectorTofile(Vword);
            cout << "Ammount successfuly\n this ammount is=" << C.countbalance << endl;

            break;

        }

    }





}
bool Deposits(string account, double ammount, vector<stinfo>& Vword) {

    char ch = 'y';


    cout << "do you want to write in file:(y/n):";
    cin >> ch;
    if (tolower(ch) == 'y') {
        for (stinfo& C : Vword) {


            if (C.account == account) {

                C.countbalance += ammount;

                loadVectorTofile(Vword);
                cout << "Done Successfuly .NEW balance is :" << C.countbalance << endl;
                return true;
            }

        }

    }
    return false;

}






void DepositScreen() {

    cout << "==========================================================\n";
    cout << space(1) << "Deposit Screen\n";
    cout << "==========================================================\n";
    vector<stinfo>Vword = loadfromfile(FileClient);
    stinfo client;
    string account = ReadStringAnyThing("Enter Account \n");
    while (!isfound(account, client, Vword)) {
        cout << "Client with Account Number( " << account << ") is Not Found\n";
        account = ReadStringAnyThing("Enter Account \n");
    }
    PrintCardClient(client);
    double ammount = ReadAmount("\n please Enter The dopisit amount?");
    Deposits(account, ammount, Vword);






}
bool checkwithdrow(stinfo client, double ammount) {

    return (client.countbalance >= ammount) ? true : false;

}




void WithDrowScreen() {

    cout << "==========================================================\n";
    cout << space(1) << "Withdrow Screen\n";
    cout << "==========================================================\n";
    vector<stinfo>Vword = loadfromfile(FileClient);
    stinfo client;
    string account = ReadStringAnyThing("Enter Account \n");
    while (!isfound(account, client, Vword)) {
        cout << "Client with Account Number( " << account << ") is Not Found\n";
        account = ReadStringAnyThing("Enter Account \n");
    }
    PrintCardClient(client);
    double ammount = ReadAmount("\n please Enter The dopisit amount?");

    while (!checkwithdrow(client, ammount)) {

        cout << "Amount Exceeds the Balance ,you Can withdrow up to" << client.countbalance << endl;
        ammount = ReadAmount("\n please Enter The dopisit amount?");


    }
    Deposits(account, ammount * -1, Vword);






}

void PrintTotalBalance() {
    vector<stinfo>Vword = loadfromfile(FileClient);
    double sum = 0;
    cout << space(4) << "Client List (" << Vword.size() << ")  " << "Client(s)" << endl;
    cout << "--------------------------------------------------------------------------------------------------------\n";
    cout << "|" << left << setw(17) << "acount_number";
    cout << "|" << left << setw(17) << " Name";
    cout << "|" << left << setw(20) << "countbalance" << endl;
    cout << "---------------------------------------------------------------------------------------------\n";

    if (Vword.size() == 0) {


        cout << "\t\t\t\tNo Clients Available In the System!\n";

    }
    else {
        for (stinfo vline : Vword) {



            sum += vline.countbalance;



            printoTotal(vline);
            cout << endl;

        }
    }
    cout << "--------------------------------------------------------------------------------------------------------\n";
    cout << space(4) << "Total Balance=" << sum << endl;
}




void PerfromMangeUsersOption(enManageUsersOption choose) {

    switch (choose) {

    case enManageUsersOption::enListUsers:
        system("cls");
        PrintAllUsersInSystem();
        GoToManageUsersMenue();
        break;
    case enManageUsersOption::enAddUsers:
        system("cls");
        AddUserInSystem();
        GoToManageUsersMenue();
        break;
    case enManageUsersOption::enDeleteUsers:
        system("cls");
        DeleteUsersScreen();
        GoToManageUsersMenue();
        break;
    case enManageUsersOption::enUpdateUsers:
        system("cls");
        UpdateUserScreen();
        GoToManageUsersMenue();
    case enManageUsersOption::enFindUsers:
        system("cls");
        FindUserInFile();
        GoToManageUsersMenue();
        
        break;
    case enManageUsersOption::enMainMenueScreen:
        system("cls");
        ShowMainMenue();
        
        break;
    }
    }

void PerfromTransaction(enTransactionOptions choose) {

    switch (choose) {

    case enTransactionOptions::enDeposit:
        system("cls");
        DepositScreen();
        GoToTransactoinMenue();
        break;
    case enTransactionOptions::enWithdrow:
        system("cls");
        WithDrowScreen();
        GoToTransactoinMenue();
        break;
    case enTransactionOptions::enTotalBalance:
        system("cls");
        PrintTotalBalance();
        GoToTransactoinMenue();
    case enTransactionOptions::enMainMenue:

        GoToMainMenue();
       
        break;


    }





}

bool CheckPermission(enPermaission check) {
    if (CurrentUser.Permission == enPermaission::enAllPermission) {
        return true;

    }
    return (CurrentUser.Permission & check);
}
void MessagePermission() {
    cout << "-------------------------------------------------------------------------------\n";
    cout << "Access Denied,\n You dont Have Permission To Do this,\n Please Conact Your Admin.\n";
    cout << "-------------------------------------------------------------------------------\n";


}
void PerfromMainMenueOption(enMainMenueOptions enchoose) {



    switch (enchoose) {

    case enMainMenueOptions::ShowAllUser:

        system("cls");
       
       CheckPermission(enPermaission::enShowClientPermission)?printAllVectors():MessagePermission();
        
        GoToMainMenue();
        break;
    case enMainMenueOptions::AddClient:
        system("cls");
        CheckPermission(enPermaission::enAddClientPermission)? AddClientAndCheck():MessagePermission();
        GoToMainMenue();
        break;
    case enMainMenueOptions::Delete:
        system("cls");
       CheckPermission(enPermaission::enDeleteClientPermassion)? DeleteClientScreen():MessagePermission();
        GoToMainMenue();
        break;
    case enMainMenueOptions::Update:
        system("cls");
      CheckPermission(enPermaission::enUpdateClientPermassion)?UpdateClientScreen():MessagePermission();

        GoToMainMenue();
        break;
    case enMainMenueOptions::find:
        system("cls");
        CheckPermission(enPermaission::enFindClientPermassion)?Select():MessagePermission();
        GoToMainMenue();
        break;
    case enMainMenueOptions::Transaction:
        system("cls");
       CheckPermission(enPermaission::enTransactionpermission)?ShowTransAction():MessagePermission();
       GoToMainMenue();
        break;
    case enMainMenueOptions::ManageUsers:
        system("cls");
      CheckPermission(enPermaission::enManageUsers)?ShowManageUsersScreen():MessagePermission();
      GoToMainMenue();
        break;
    case enMainMenueOptions::logout:
        system("cls");
        login();
        
        break;
    default:cout << "your Chose invalid";
    }




}
short ReadNumberFromMenue(string Message) {
    short num = 0;
    cout << Message;
    cin >> num;
    return num;
}




void ShowTransAction() {

    system("cls");
    cout << "================================================================================================\n";
    cout << space(4) << "Transaction Menue Screen\n";
    cout << "================================================================================================\n";
    cout << space(4) << "[1] Deposit\n";
    cout << space(4) << "[2] Withdrow \n";
    cout << space(4) << "[3] Total Balances \n";
    cout << space(4) << "[4] Main Menue  \n";
    cout << "================================================================================================\n";

    PerfromTransaction(enTransactionOptions(ReadNumberFromMenue("choose what do you want to do ? ![1 - 4] ?\t")));

}



void ShowMainMenue() {

    system("cls");
    cout << "================================================================================================\n";
    cout << space(4) << "Main Menue Screen\n";
    cout << "================================================================================================\n";
    cout << space(4) << "[1] Show Client List\n";
    cout << space(4) << "[2] Add New Client \n";
    cout << space(4) << "[3] Delete Client \n";
    cout << space(4) << "[4] Update Client  \n";
    cout << space(4) << "[5] Find Client  \n";
    cout << space(4) << "[6] Transaction  \n";
    cout << space(4) << "[7] ManageUsers  \n";
    cout << space(4) << "[8] logout  \n";
    cout << "================================================================================================\n";
    PerfromMainMenueOption(enMainMenueOptions(ReadNumberFromMenue("choose what do you want to do ? ![1 - 8] ? \t")));


}
void ShowManageUsersScreen() {

    system("cls");
    cout << "================================================================================================\n";
    cout << space(4) << "Manage Users Main Menue \n";
    cout << "================================================================================================\n";
    cout << space(4) << "[1] List Users \n";
    cout << space(4) << "[2] Add New Users \n";
    cout << space(4) << "[3] Delete Users \n";
    cout << space(4) << "[4] Update Users  \n";
    cout << space(4) << "[5] Find Users  \n";
    cout << space(4) << "[6] Main Menue  \n";

    cout << "================================================================================================\n";
    
    PerfromMangeUsersOption(enManageUsersOption(ReadNumberFromMenue("Choose What Do You Want To Do ?[1 - 6] ? \t")));

}
void loginUser() {


    vector<stUsers>Vuser = LoadFomeUsersFile(UsersFlie);
    string Name, Password;
   
    bool found = true;
    do {

        if (!found) {



            cout << "invlaid Username / Password\n";


        }

        cout << "Enter Username?";
        getline(cin >> ws, Name);
        cout << "Enter Password?";
        getline(cin >> ws, Password);
        found = false;
        for (stUsers& s : Vuser) {
            if ((Name == s.Name && Password == s.Password)) {
                CurrentUser = s;
                found = true;
                break;
            }


        }




    } while (!found);

   
}
void login() {

  
  
        system("cls");
        cout << "================================================================================================\n";
        cout << space(4) << " login Screen \n";
        cout << "================================================================================================\n";
        loginUser();
    ShowMainMenue();

}

int main()
{


    login();
    system("pause>0");
}





