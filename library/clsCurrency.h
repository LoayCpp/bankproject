#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include"clsString.h"
using namespace std;
class clsCurrency
{
	enum enMode
	{
eEmptyMode=1,
eUpdateMode=2
	};

	enMode _Mode;
	string _Country;
	string _CurrencyCode;
	string _CurrencyCountry;
	float _Rate;

static clsCurrency _ConvertLineToCurrencyObject(string Line,string Delim="#//#") {

		vector<string>vCurrencyLine = clsString::Split(Line, Delim);

		return clsCurrency(enMode::eUpdateMode, vCurrencyLine[0], vCurrencyLine[1], vCurrencyLine[2],stof(vCurrencyLine[3]));

	}

static string _ConvertCurrencyObjectToLine(clsCurrency C, string Delim = "#//#") {

	string Line = "";
	Line += C.Country() + Delim;
	Line += C.CurrencyCode() + Delim;
	Line += C.CurrencyCountry() + Delim;
	Line += to_string(C.Rate());
	return Line;

	}

static vector<clsCurrency>_LoadCurrencysDataFromFile() {

		fstream MyFile;
		vector<clsCurrency>vAllCurrencies;
		MyFile.open("Currencies.txt", ios::in);
		if (MyFile.is_open()) {
			string Line;
			while (getline(MyFile, Line)) {


				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);

				vAllCurrencies.push_back(Currency);
			}

			MyFile.close();

		}
		return vAllCurrencies;

	}



	
static	void _SaveCurrencyDataToFile(vector<clsCurrency> vCurrency) {

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::out);
		string Line;
		if (MyFile.is_open()){

			for (clsCurrency &C : vCurrency) {

				Line = _ConvertCurrencyObjectToLine(C);

				MyFile << Line << endl;
			}
			


		}
		MyFile.close();

	}

	static clsCurrency _GetEmptyCurrency() {

		return clsCurrency(enMode::eEmptyMode, "", "", "", 0);

	}

	void _Update() {

		vector<clsCurrency>vCurrency = _LoadCurrencysDataFromFile();
		for (clsCurrency& C : vCurrency) {

			if (C.Country() == Country()) {

				C = *this;
				break;
			}


		}
		_SaveCurrencyDataToFile(vCurrency);

	}

public:

	clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyCountry, float Rate) {

		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyCountry = CurrencyCountry;
		_Rate = Rate;


	}

	

	static vector <clsCurrency> GetCurrenciesList()
	{

		return _LoadCurrencysDataFromFile();

	}

	bool IsEmpty() {


		return (_Mode == enMode::eEmptyMode);
	}

	string CurrencyCode() {

		return _CurrencyCode;
	}

	string Country() {

		return _Country;
	}

	string CurrencyCountry() {

		return _CurrencyCountry;
	}

	void UpdateRate(float Rate) {

		_Rate = Rate;

		_Update();
	}

	float Rate() {


		return _Rate;
	}

	static clsCurrency FindByCode(string CurrencyCode) {

		CurrencyCode = clsString::UpperAllString(CurrencyCode);

		fstream myfile;
		myfile.open("Currencies.txt", ios::in);
		if (myfile.is_open()) {
			string Line;
			while (getline(myfile, Line)) {

				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
				if (clsString::UpperAllString(Currency.CurrencyCode()) == CurrencyCode) {

					myfile.close();
					return Currency;

				}



			myfile.close();
			}


			return _GetEmptyCurrency();
		}
	}

	static clsCurrency FindByCountry(string Country) {

		Country = clsString::UpperAllString(Country);

		fstream myfile;
		myfile.open("Currencies.txt", ios::in);
		if (myfile.is_open()) {
			string Line;
			while (getline(myfile, Line)) {

				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
				if (clsString::UpperAllString( Currency.Country() )== Country) {

					myfile.close();
					return Currency;

				}



			}
			myfile.close();
			return _GetEmptyCurrency();
		}
	}
	static bool IsCurrencyExist(string CurrencyCode) {
		
		 clsCurrency C = clsCurrency::FindByCode(CurrencyCode);
		 return (!C.IsEmpty());
	}
};

