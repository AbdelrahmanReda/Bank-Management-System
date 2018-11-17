// ass4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"

#include <chrono>
#include <thread>
#include <iostream>
#include <string>
#include <fstream>
using namespace std ; 

string data_container[5];




class birthday {

private:
	int month, day, year; 

public:
	
	birthday(int m, int d, int y)
	{
		day = d;
		month = m; 
		year = y;
	}


	void displayInfo() {


		cout << month << " " << day << " " << year << endl;

	}

};


class people {

private :
	birthday dataofbith; 
	string name; 
public:
	people(string x, birthday dayday) : name(x), dataofbith(dayday)
	{}


	people ( birthday dayday) : dataofbith(dayday)
	{

	}


	

	void presentation() {


		cout << name << " was born in: ";
		dataofbith.displayInfo(); 
	}
	~people(){}
};








class BankApplication
{

private:
	
	string name;
	string ID;
	string indicator = "1";


public:
	BankApplication(string name,string ID ) {
		this->name = name; 
		this->ID = ID; 
	
	}
	string getting() { return ID; }


	BankApplication()
	{

		name = "NULL";
		ID = "NULL";
		indicator = "NULL";
	}

	void inputs(string indicator)
	{

		if (indicator == "1")
		{

			cout << "adding new client" << endl;



		}
		else
		{


		}



	}

	
	string getName() { 
		
		
		
		return name;  }

};




class BankAccount 
{


protected:
	string ID; 
	
	float balance;
	BankApplication b1; 


public:
	BankAccount() {}
	BankAccount(float x , BankApplication bank1 ):balance(x),b1(bank1){}
	void testingforgetting() {

		b1.getting(); 
	}
	void setBalance		(float balance) { (*this).balance = balance; }
	float  getBalance() { return balance; }


	//process in money
	virtual void withdraw(float x) { balance = balance - x;  }
	virtual void deposit (float x) { balance = balance + x;  }

};



class SavingsBankAccount :public BankAccount {
private:
	float minimumBalance;
public:
	SavingsBankAccount() { minimumBalance = 0; }

	 void withdraw(float x)
	{

		if (balance - x > minimumBalance)
			cout << "please wait wile transaction is processing" << endl;
		balance = balance - x;


	}
	 void deposit(float x) {

		if (x >= 100)
		{
			cout << "please wait wile transaction is processing" << endl;
			balance = balance - x;

		}
		else
		{
			cout << "field process" << endl;

		}
		balance = balance + x;
	}

};





class Client {

private:

	string clientAdree;
	string phoneNumber;
	BankAccount type1bank;
	SavingsBankAccount type2bank; 
	BankApplication using1;

	




public:






	Client() {; clientAdree = "NULL"; phoneNumber = "NULL"; }
	Client (string y , string z , BankAccount dayday, BankApplication us1) : clientAdree(y), phoneNumber(z), type1bank(dayday), using1 (us1){}
	Client ( string y, string z, SavingsBankAccount daydayy) :  clientAdree(y), phoneNumber(z),  type2bank (daydayy) {}

	void withdraw(int x)
	{
		type1bank.withdraw(x);
		
	}


	void deposit(int x)
	{
		
		type1bank.deposit(x); 
	}


	

	void getClientData() {
		
		//cout << "User data is: \n" << "Name: " << using1.getName() << "\n" << "CLIENT ADDRESS " << clientAdree << " \n" << "Phone Number:" << phoneNumber << endl;
		//cout << "ID is: " << using1.getting() << endl;
		//cout <<"Balance is: "<< type1bank.getBalance() << endl;

		data_container[0] = using1.getName(); 
		data_container[1] = clientAdree;
		data_container[2] = phoneNumber;
		data_container[3] = using1.getting();
		data_container[4] = to_string(type1bank.getBalance());
		



		
	}

	
	


};





int main()
{
	string choicer="1" ;
	string globalName;
	string globalAdress;
	string globalphone;
	string globalID;
	string globalchoiceForAccount;
	int    globalBalance;
	
	fstream clients80("clients1.csv", ios::in | ios::out | ios::app);
	fstream clients87("clients2.csv", ios::in | ios::out | ios::app);


	if (choicer == "1")
	{
		cout << "Enter Yor Name: ";
		getline(cin, globalName);


		cout << "Enter Yor Adress: ";
		getline(cin, globalAdress);


		cout << "Enter Yor Phone Number: ";
		getline(cin, globalphone);

		cout << "Enter Yor Account type: ";
		getline(cin, globalchoiceForAccount);



		cout << "Enter balance: ";
		cin >> globalBalance;
		cout << endl;

	}

	else
	{
		cout << "Enter your ID: ";
		cin >> globalID; 
	}
	


	BankApplication b1(globalName, "20145 123456 8987 45165");
	BankAccount account1;
	account1.setBalance(globalBalance);
	Client cl(globalAdress, globalphone, account1, b1);
	cl.getClientData(); 
	clients80 << data_container[0] << ',' << data_container[1] << ',' << data_container[2] << ',' << data_container[3] << ',' << data_container[4] << endl;
	

	




	string reader, reader2, readr3, reader4;
	clients80.seekg(0);
	string line;
	while (!clients80.eof())
	{
			getline(clients87, reader, ',');
			getline(clients87, reader2, ',');
			getline(clients87, readr3, ',');
			getline(clients87, reader4, '\n');

		if (globalID == reader)
		{
			cout <<"name: " <<reader<<" adress: " << reader2 << " phone number: " << readr3 << " balance: " << reader4 << endl;


		}

		clients80.close(); 

	}





}

