#pragma once
#include "cls_date.h"
#include <regex>
#include <sstream>

using namespace std; 

class cls_input_validate
{
public : 
	static bool is_number_between(int num, int from, int to)
	{
		if (num >= from && num <= to)
			return true;
		else
			return false;
	}
	static bool is_number_between(double num, double from, double to)
	{
		if (num >= from && num <= to)
			return true;
		else
			return false;
	}	
	static bool is_number_between(float num, float from, float to)
	{
		if (num >= from && num <= to)
			return true;
		else
			return false;
	}
	static bool is_date_between(cls_date date, cls_date date1, cls_date date2)
	{
		if (cls_date::check_if_date1_before_date2(date2, date1))
		{
			cls_date::swip(date1, date2);
		}

		if (cls_date::check_if_date1_after_date2(date, date1) && cls_date::check_if_date1_before_date2(date, date2))
			return true; 

		return false; 
	}
	static int read_number_input(string msg)
	{
		int num = 0 ;
		
		cout << "Please enter a number : ";
		cin >> num; 

		while (cin.fail())
		{
			cin.clear(); 
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
			cout << msg << endl;
			cin >> num;
		}

		return num;
	}
	static double read_double_number_input(string msg)
	{
		string input;
		double num;

		regex doublePattern(R"(^[+-]?\d*\.\d+$)");

		while (true)
		{
			cout << "Please enter a number: ";
			cin >> input;

			if (regex_match(input, doublePattern))
			{
				stringstream ss(input);
				ss >> num;
				if (!ss.fail()) return num;
			}

			cout << msg << endl;

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
	static int read_int_number_between(short from, short to, string message)
	{
		int number = 0; 
		cout << "please enter number between " << from << " and " << to << " : ";
		cin >> number;

		while (number < from || number > to)
		{
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << message << endl;
			cin >> number; 
		}
		return number; 

	}
	static bool is_validate_date(cls_date date)
	{
		date.is_validate_date();
	}
	static int read_double_between_input(double from, double to, string message)
	{
		double num = read_double_number_input("wrong data type try again");
		while (num < from || num > to)
		{
			cout << message << endl;
			num = read_double_number_input("wrong data type try again");
		}
		return num; 
	}
};

