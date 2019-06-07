#pragma once
#include <iostream>
#include <string>

using namespace std;


class Database
{
private:

	static Database *singleObject;//вказ≥вник на обЇкт класу Database
	static int count;// л≥чильник к≥лькост≥ обЇкт≥в класу Database

	int record;
	string name; //

	Database(string n)//конструктор private (в функц≥њ main  недоступний)
	{
		name = n;//≥м€ бази даних
		record = 0;// к≥льк≥сть запис≥в
		count++;
	}

public:
	static Database& getInstance(string n)// статичний метод €кий викликаЇтьс€ лише з класу а не з обЇкта класу
	{
		if (count == 0)
		{
			singleObject = new Database(n);// створюЇмо Їдиний екземпл€р класу 
		}
		return *singleObject;// повертаЇмо посиланн€ на Їдиний ≥снуючий екземпл€р класу
	};

	string getName()
	{
		return name;
	}
};

