#pragma once
#include <iostream>
#include"clsUtil.h"
#include"clsUser.h"
#include "Global.h"
using namespace std;
class clsScreen
{

protected:
    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout<<clsUtil::Tabs(5) <<"___________________________________________";
        cout << "\n\n"<< clsUtil::Tabs(5) << Title;
        if (SubTitle != "")
        {
            cout << "\n "<< clsUtil::Tabs(5) << SubTitle;
        }
        cout << "\n"<<clsUtil::Tabs(5) <<"___________________________________________\n\n";
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

