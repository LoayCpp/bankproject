#pragma once
#include"clsScreen.h"
#include"clsUtil.h"
#include"clsCurrency.h"
#include"clsInputValidate.h"
class clsCurrencyCalculatorScreen :protected clsScreen
{


	static clsCurrency _ReadCode(string Message) {
		string code = "";
		cout << Message;
		code = clsInputValidate::ReadString();
		while (!clsCurrency::IsCurrencyExist(code)) {
			cout << "\nPlease Enter The valid Code:";
			code = clsInputValidate::ReadString();

		}
		clsCurrency Currency = clsCurrency::FindByCode(code);


		return Currency;
	}
	static	float _ReadAmountCurrency() {

		float Num = 0;

		cout << "\nEnter Amount to Exchange:";
		Num = clsInputValidate::ReadFloatNumber();


		return Num;
	}
	static void _PrintCurrencyInfo(clsCurrency C,string Message="Currency Card") {

		cout << Message << endl;
		cout << "----------------------------------------\n\n";
		cout << clsUtil::ColorText("Country           :", clsUtil::BGreen) << C.Country() << endl;
		cout << clsUtil::ColorText("Code              :", clsUtil::BGreen) << C.CurrencyCode() << endl;
		cout << clsUtil::ColorText("Currency Country  :", clsUtil::BGreen) << C.CurrencyCountry() << endl;
		cout << clsUtil::ColorText("Rate              :", clsUtil::BGreen) << C.Rate() << endl;

		cout << "----------------------------------------\n\n";

	}
	
	static void  _PrintCalculator(float Amount, clsCurrency CurrencyFrom, clsCurrency CurrencyTo) {
		
		_PrintCurrencyInfo(CurrencyFrom, clsUtil::ColorText("Convert From :", clsUtil::Cyan));

		float Dollar = CurrencyFrom.ConvertToDollar(Amount);

		cout << Amount << " " << CurrencyFrom.CurrencyCode() << "=" << Dollar << " " << "USD" << endl;

		if (CurrencyTo.CurrencyCode() == "USD") {

			return;
		}

			
			_PrintCurrencyInfo(CurrencyTo, clsUtil::ColorText("\nConverting from USD To: \n\n", clsUtil::Cyan));

			float FromDollarToCurrency = CurrencyFrom.ExchangeFromDollarToCurrencyCountry(Amount, CurrencyTo);

			cout << Amount << " " << CurrencyFrom.CurrencyCode() << "=" << FromDollarToCurrency << " " << CurrencyTo.CurrencyCode() << endl;
		}



	 
	static bool _CheckAgain() {

		bool Again = false;
		char ch = 'n';
		cout << "\n\nDo you want to perform another calculation? y/n ?";
		cin >> ch;
		if (tolower(ch) == 'y') {

			Again = true;
			return Again;
		}

		return false;
	}
public:
	static void _ShowCurrencyCalculator() {

			bool Again = false;

		do{
			system("cls");
			_DrawScreenHeader("\t Calculator Currency Screen");
			clsCurrency CurrencyFrom = _ReadCode("\n Please Enter Currency1 Code:");

			clsCurrency CurrencyTo = _ReadCode("\n Please Enter Currency2 Code:");

			float Amount = _ReadAmountCurrency();

			_PrintCalculator(Amount, CurrencyFrom, CurrencyTo);
		
			Again = _CheckAgain();
			

		} while (Again);
	}
};

