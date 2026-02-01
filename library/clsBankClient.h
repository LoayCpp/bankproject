#pragma once
#include<iostream>
#include<clsperson.h>
#include<fstream>
#include<string>
#include"clsString.h"
#include<vector>
using namespace std;
class clsBankClient :public clsPerson
{
private:



	enum enMode{EmptyMode=0,UpdateMode=1,AddModeClient=2};
	string _AccountNumber;
	string _PinCode;
	double _Balance;
	enMode _Mode;
	bool _MarkDelete=false;
	static clsBankClient _ConvertLineClientToObject(string Line,string Delim="#//#") {

		vector<string> vClientData = clsString::Split(Line,Delim);
		return clsBankClient(UpdateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));

	}
	static clsBankClient _GetEmptyClientObject() {

		return clsBankClient(enMode::EmptyMode, " ", " ", " ", " ", " ", " ",0);

	}
	string _ConvertObjectToLine(clsBankClient Client,string Delim = "#//#") {

		string Word = "";
		Word += Client.FirstName + Delim;
		Word += Client.LastName + Delim;
		Word += Client.Email + Delim;
		Word += Client.Phone + Delim;
		Word += Client.GetAccountNumber() + Delim;
		Word += Client.PinCode + Delim;
		Word += to_string(Client.Balance);

		return Word;
	}
	static vector<clsBankClient>_UploadClinetFromFile() {

		vector<clsBankClient> Vclients;
		fstream Myfile;
		string Line;
		
		Myfile.open("Clients.txt", ios::in);
		if(Myfile.is_open()){

			while (getline(Myfile, Line)) {

				clsBankClient Client = _ConvertLineClientToObject(Line);
				Vclients.push_back(Client);

			}

			Myfile.close();
		}

		return Vclients;
	}
	void _AddClient() {



		_SaveAddClinetToFile(_ConvertObjectToLine(*this));

	}
	void _DeleteClient() {





	}
	void _SaveAddClinetToFile(string Info) {

		fstream myfile;
		myfile.open("Clients.txt", ios::out | ios::app);
		if (myfile.is_open()) {

			myfile << Info <<endl;


			}
		myfile.close();




	}
	void _SaveClinetToFile(vector<clsBankClient>Vclients) {

		fstream myfile;
		string Line;

		myfile.open("Clients.txt", ios::out);
		if (myfile.is_open()) {

			for (clsBankClient& C : Vclients) {
				if (C._MarkDelete == false) {
					Line = _ConvertObjectToLine(C);
					myfile << Line << endl;
				}
			}



			myfile.close();
		}


	}
	void _Update() {
		vector<clsBankClient> Vclinets = _UploadClinetFromFile();
		for (clsBankClient& C : Vclinets) {

			if (C.GetAccountNumber() == GetAccountNumber()) {

				C = *this;
				break;
			}


		}

		_SaveClinetToFile(Vclinets);

	}




public:
	clsBankClient(enMode Mode,string FirstName, string LastName, string Email, string Phone, string AccountNumber, string PinCode,double  Balance)
		:clsPerson(FirstName, LastName, Email, Phone) {
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_Balance = Balance;
	}
	bool IsEmpty() {

		return _Mode == enMode::EmptyMode;
	}
	string GetAccountNumber() {

		return _AccountNumber;
	}
	__declspec(property(get = GetAccountNumber))string AccountNumber;

	void SetPinCode(string PinCode) {
		_PinCode = PinCode;
	}
	string  GetPinCode() { return _PinCode; }
	__declspec(property(get = GetPinCode, put = SetPinCode))string PinCode;

	void SetBalance(double Balance) {
		_Balance = Balance;
	}
	double GetBalance() { return _Balance; }
	__declspec(property(get = GetBalance, put = SetBalance))double Balance;

	static clsBankClient GetAddClientModeAndAccount(string Account) {


		return clsBankClient(enMode::AddModeClient, "", "", "", "", Account, "", 0);
	}

	static clsBankClient Find(string AccountNumber) {


		fstream myfile;
		string Line;
		vector<clsBankClient> Vclient;
		myfile.open("Clients.txt", ios::in);
		if (myfile.is_open()) {

			while (getline(myfile, Line)) {

				clsBankClient Client = _ConvertLineClientToObject(Line);

				if (Client.GetAccountNumber() == AccountNumber) {
					myfile.close();
					return Client;

				}
			}
			myfile.close();
		}
		

		return _GetEmptyClientObject();
	}

	static clsBankClient Find(string AccountNumber,string PinCode) {


		fstream myfile;
		string Line;
		vector<clsBankClient> Vclient;
		myfile.open("Clients.txt", ios::in);
		if (myfile.is_open()) {

			while (getline(myfile, Line)) {

				clsBankClient Client = _ConvertLineClientToObject(Line);

				if (Client._AccountNumber == AccountNumber && Client.PinCode==PinCode) {
					myfile.close();
					return Client;

				}
			}
			myfile.close();
		}


		return _GetEmptyClientObject();
	}

	static bool IsExitsClient(string AccountNumber) {

		clsBankClient Client =clsBankClient::Find(AccountNumber);

		return (!Client.IsEmpty());
	}
	bool Delete() {
		vector<clsBankClient>Vclient=_UploadClinetFromFile();
		for (clsBankClient& c : Vclient) {

			if (c.GetAccountNumber() == GetAccountNumber()) {

				c._MarkDelete = true;
				break;
			}

		}
		_SaveClinetToFile(Vclient);
			*this = _GetEmptyClientObject();

			return true;

	}
	enum enSaveResult{enFieldEmptyObject=0 ,enSucceded=1,enClientAddIsExists=2};
	enSaveResult Save() {

		switch (_Mode)
		{

		case clsBankClient::EmptyMode:
			if (IsEmpty()) {
				return 	enSaveResult::enFieldEmptyObject;
				break;
			}

		case clsBankClient::UpdateMode:
			_Update();
			return enSaveResult::enSucceded;

			break;
		case AddModeClient:
			if (clsBankClient::IsExitsClient(GetAccountNumber())) {

				return enSaveResult::enClientAddIsExists;
			}
			else {
				_AddClient();
				_Mode = enMode::UpdateMode;
				return enSaveResult::enSucceded;
			}

	
		}




	}
	static vector<clsBankClient> GetListClient() {



		return _UploadClinetFromFile();
	}
	static double TotalBalance() {
	
		vector<clsBankClient>vClient = _UploadClinetFromFile();
		double Balance = 0;
		for (clsBankClient &c:vClient)
		{
			Balance += c.Balance;
		}

		return Balance;

	}
};

