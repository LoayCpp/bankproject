#pragma once
#include <iostream>
#include"clsUtil.h"
#include"clsUser.h"
#include "Global.h"
#include"clsDate.h"
#include<string>
using namespace std;
class clsScreen
{

protected:
    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout<<clsUtil::Tabs(5) <<"___________________________________________";
        cout << "\n\n"<< clsUtil::Tabs(5) << clsUtil::ColorText(Title,clsUtil::Cyan);
        if (SubTitle != "")
        {
            cout << "\n "<< clsUtil::Tabs(5) << clsUtil::ColorText(SubTitle, clsUtil::Cyan);
        }
        cout << "\n"<<clsUtil::Tabs(5) <<"___________________________________________\n";
        cout << "\n" << clsUtil::Tabs(5) <<"Date:"<< clsDate::DateToString(clsDate());
        cout << "\n\n" << clsUtil::Tabs(5) <<"User:"<<CurrentUser.UserName<<endl;
    }
    static bool _CheckPermissionsOfUser(clsUser::enPermissions permissions) {

        if (!CurrentUser.CheckPermissions(permissions)) {

            _DrawScreenHeader("\t Don`t Have permissions");
            return false;

        }
        else {



            return true;
        }



    }

	
};

