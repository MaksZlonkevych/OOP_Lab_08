#pragma once
#include <iostream>
#include <string>

using namespace std;

class Group
{
	string name;
	string department;
public:
	Group(string n, string p)
	{
		name = n;
		department = p;
	}
	string getName()
	{
		return name;
	}
	friend ostream& operator<< (ostream& os, const Group& gr);
};
ostream& operator<< (ostream& os, const Group& gr)
{
	os << "Group: " + gr.name + "\t Department: " + gr.department;
	return os;
}

class Department
{
	Group *groups[30];
	string name;
	int number;
public:
	friend class DepartmentIterator;
	Department(string n)
	{
		name = n;
		number = 0;
	}

	string getName()
	{
		return name;
	}

	void add(string n)
	{
		groups[number++] = new Group(n, name);
	}
};

class DepartmentIterator
{
private:
	const Department& department;
	int index = 0;

public:
	DepartmentIterator(const Department &prg) : department(prg)
	{
		index = 0;
	}
	void operator++(int)
	{
		index++;
	}
	bool operator()()
	{
		return index != department.number;
	}
	Group& operator *()
	{
		return *department.groups[index];
	}
};
