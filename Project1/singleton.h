#pragma once
#include <iostream>
#include <string>

using namespace std;


class Database
{
private:

	static Database *singleObject;//�������� �� ���� ����� Database
	static int count;// �������� ������� ����� ����� Database

	int record;
	string name; //

	Database(string n)//����������� private (� ������� main  �����������)
	{
		name = n;//��� ���� �����
		record = 0;// ������� ������
		count++;
	}

public:
	static Database& getInstance(string n)// ��������� ����� ���� ����������� ���� � ����� � �� � ����� �����
	{
		if (count == 0)
		{
			singleObject = new Database(n);// ��������� ������ ��������� ����� 
		}
		return *singleObject;// ��������� ��������� �� ������ �������� ��������� �����
	};

	string getName()
	{
		return name;
	}
};

