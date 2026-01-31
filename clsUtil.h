#pragma once

#include <iostream>
#include <cstdlib>
#include"clsDate.h"
using namespace std;
class clsUtil
{
	
	static string DeleteZeroInTheEnd(string Word)
	{

		while (!Word.empty() && Word.back() == '0')
		{
			Word.pop_back();
		}

		return Word;
	}
	static int  ConvertingDecimal(string Number)
	{

		short pos = 0;
		pos = Number.find(".");
		string NewNumber = Number.substr(pos + 1, Number.length());
		return stoi(NewNumber);
	}
public:
	
	static void Srand() {

		srand((unsigned)time(NULL));

	}
	static int RandomNumber(int from, int to) {

		return rand() % (to - from + 1) + from;
	}
	enum enCharTayp { SmallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, Digit = 4 ,All=5};
	static char GetRandomCharacter(enCharTayp CharType) {

		switch (CharType)
		{
		case enCharTayp::SmallLetter:
		{
			return char(RandomNumber(97, 122)); // char( 110 ) = n
			break;
		}
		case enCharTayp::CapitalLetter:
		{
			return char(RandomNumber(65, 90));
			break;
		}
		case enCharTayp::SpecialCharacter:
		{
			return char(RandomNumber(33, 47));
			break;
		}
		case enCharTayp::Digit:
		{
			return char(RandomNumber(48, 57));
			break;
		}
		case enCharTayp::All:
			return char(RandomNumber(33, 122));
			break;


		}
	}
static string GenerateWord(enCharTayp CharType, short Length)
	{
		string Word="";
		for (int i = 1; i <= Length; i++) 
		{
			Word += GetRandomCharacter(CharType);
		}
		return Word;
	}
static string GenerateKey(enCharTayp CharType, short LengthWord=4,short LengthKey=4) {

	string word="";
	for (short i = 1; i <= LengthKey; i++) {
		
		word += GenerateWord(CharType, LengthWord) + "-";
	}
	return word.substr(0,word.length() - 1);

}
static void GenerateKeys(short HowManyKeys,enCharTayp CharType, short LengthWord=4, short LengthKey=4) {

	for (int i = 1; i <= HowManyKeys; i++)
	{
		cout << "Key [" << i << "] = " << GenerateKey(CharType, LengthWord, LengthKey) << endl;

	}

}
static void FillArrayWithRandomNumbers(int arr[100], int arrLength,int from ,int to)
{
	
	for (int i = 0; i < arrLength; i++)
	{
		arr[i] = RandomNumber(from, to);

	}

}
static void FillArrayWithRandomWords(string arr[100], int arrLength, enCharTayp Chartype, short Lengthword)
{

	for (int i = 0; i < arrLength; i++)
	{
		arr[i] = GenerateWord(Chartype, Lengthword);

	}

}
static void FillArrayWithRandomKeys(string arr[100], int arrLength, enCharTayp Chartype) {

	for (int i = 0; i < arrLength; i++)
	{
		arr[i] = GenerateKey(Chartype);

	}


}
static void PrintFillArrayWithRandomNumbers(int arr[100], int& arrLength)
{
	
	for (int i = 0; i < arrLength; i++)
	{
		cout << arr[i] << " ";

	}

}

static void Swap(int& Num, int& Num2) {

	int temp=0;
	temp = Num;
	Num = Num2;
	Num2 = temp;
}
static void Swap(float& Num, float& Num2) {

	float temp=0;
	temp = Num;
	Num = Num2;
	Num2 = temp;
}
static void Swap(string& Num, string& Num2) {

	string temp="";
	temp = Num;
	Num = Num2;
	Num2 = temp;
}
static void Swap(char& Num, char& Num2) {

	char temp = ' ';
	temp = Num;
	Num = Num2;
	Num2 = temp;
}
static void Swap(double& Num, double& Num2) {

	double temp =0;
	temp = Num;
	Num = Num2;
	Num2 = temp;
}
static void Swap(bool& Num, bool& Num2) {

	bool temp;
	temp = Num;
	Num = Num2;
	Num2 = temp;
}
static void Swap(clsDate& Date, clsDate& Date2) {


	clsDate::SwapDates(Date, Date2);
}
static void ShuffleArray(int arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
	}
}
static void ShuffleArray(string arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
	}
}
static string Tabs(int num) {

	string Tab = "";
	for (int i = 1; i <= num; i++)
	{
		Tab += "\t";
	}
	return Tab;
}
static string EncryptText(string Text, short EncryptionKey)
{
	for (int i = 0; i < Text.length(); i++)
	{
		Text[i] = (char)int(Text[i]) + EncryptionKey;
	}
	return Text;
}
static string DecryptText(string Text, short EncryptionKey)
{
	for (int i = 0; i < Text.length(); i++)
	{
		Text[i] = (char)int(Text[i]) - EncryptionKey;
	}
	return Text;
}
static string NumberToText(int   Number)
{

	if (Number == 0)
	{
		return "";
	}

	if (Number >= 1 && Number <= 19)
	{
		string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
	"Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
	  "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

		return  arr[Number] + " ";

	}

	if (Number >= 20 && Number <= 99)
	{
		string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
		return  arr[Number / 10] + " " + NumberToText(Number % 10);
	}

	if (Number >= 100 && Number <= 199)
	{
		return  "One Hundred " + NumberToText(Number % 100);
	}

	if (Number >= 200 && Number <= 999)
	{
		return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
	}

	if (Number >= 1000 && Number <= 1999)
	{
		return  "One Thousand " + NumberToText(Number % 1000);
	}

	if (Number >= 2000 && Number <= 999999)
	{
		return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
	}

	if (Number >= 1000000 && Number <= 1999999)
	{
		return  "One Million " + NumberToText(Number % 1000000);
	}

	if (Number >= 2000000 && Number <= 999999999)
	{
		return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
	}

	if (Number >= 1000000000 && Number <= 1999999999)
	{
		return  "One Billion " + NumberToText(Number % 1000000000);
	}
	else
	{
		return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
	}


}
static string NumberToText(double Number)
{
	int IntegarNumber = (int)Number;
	double Decimal = Number - IntegarNumber;

	string WordOfNumber = to_string(Decimal);
	WordOfNumber = DeleteZeroInTheEnd(WordOfNumber);
	

		return NumberToText(IntegarNumber) +
			ColorText(" Point ",clsUtil::Green) +
			NumberToText(ConvertingDecimal(WordOfNumber));
	
}
enum encolor { Red = 1, Green = 2, Yellow=3,Blue=4, Cyan=5,BRed=6,BGreen=7,BYellow=8,BBlue=9,BCyan=10};
static string ColorText(string text,encolor color=encolor::Red) {
#define RESET       "\033[0m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define BLUE        "\033[34m"
#define CYAN        "\033[36m"

#define BRIGHT_RED     "\033[91m"
#define BRIGHT_GREEN   "\033[92m"
#define BRIGHT_YELLOW  "\033[93m"
#define BRIGHT_BLUE    "\033[94m"
#define BRIGHT_CYAN    "\033[96m"

	switch (color)
	{
	case clsUtil::Red:
		text = RED + text + RESET;
		break;
	case clsUtil::Green:
		text = GREEN + text + RESET;
		break;
	case clsUtil::Yellow:
		text = YELLOW + text + RESET;
		break;
	case clsUtil::Blue:
		text = BLUE + text + RESET;
		break;
	case clsUtil::Cyan:
		text = CYAN + text + RESET;
		break;
	case clsUtil::BRed:
		text = BRIGHT_RED + text + RESET;
		break;
	case clsUtil::BGreen:
		text = BRIGHT_GREEN + text + RESET;
		break;
	case clsUtil::BYellow:
		text = BRIGHT_YELLOW + text + RESET;
		break;
	case clsUtil::BBlue:
		text = BRIGHT_BLUE + text + RESET;
		break;
	case clsUtil::BCyan:
		text = BRIGHT_CYAN + text + RESET;
		break;
	}

	
	return text;

}



};

