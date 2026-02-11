#pragma once
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsCurrency.h"

class clsUpdateCurrencyRate : protected clsScreen
{




	static clsCurrency fFindByCode() {

		cout << "Please Enter Currency Code:";
		string Code = clsInputValidate::ReadString();
		while (!clsCurrency::IsCurrencyExist(Code)) {

			cout << "Please Enter Currency Code:";
			 Code = clsInputValidate::ReadString();


		}
		return clsCurrency::FindByCode(Code);

	}

	static void _PrintCurrencyInfo(clsCurrency C) {

		cout << clsUtil::ColorText("\n--------Currency Card--------",clsUtil::Cyan) << endl;

		cout << clsUtil::ColorText("Country           :" ,clsUtil::BGreen)<< C.Country() << endl;
		cout << clsUtil::ColorText("Code              :" ,clsUtil::BGreen) << C.CurrencyCode() << endl;
		cout << clsUtil::ColorText("Currency Country  :", clsUtil::BGreen) << C.CurrencyCountry() << endl;
		cout << clsUtil::ColorText("Rate              :", clsUtil::BGreen)<< C.Rate() << endl;

		cout << "----------------------------------------\n\n";
	}

	static void _UpdateCurrencyRate(clsCurrency& Currency) {


		float Rate = 0;
		cout << "\nUpdate Currency Rate:\n";
		cout << "\n---------------------------------\n";
		cout << "\nEnter New Rate:";
		Rate = clsInputValidate::ReadFloatNumber();
		Currency.UpdateRate(Rate);

	}

public:

	static void _ShowUpdateCurrencyRate() {

		_DrawScreenHeader("\t\tUpdate Currency Screen");

		 
		clsCurrency Currency = fFindByCode();
		_PrintCurrencyInfo(Currency);

		char ch = 'n';
		cout << "\nAre you sure you want to update the rate of this Currency y/n?";
		cin >> ch;
		if (tolower(ch) == 'y') {
			
			_UpdateCurrencyRate(Currency);
			cout << "\nRate Updated Successfully :- )\n";
			_PrintCurrencyInfo(Currency);

		}
		else {



			cout << "\nCancel UpDate :-(\n";
		}



	}



};

