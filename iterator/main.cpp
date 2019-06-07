#include"Header.h"
int main() {

	Department acs("Automated Control Systems");
	acs.add("CS-101");
	acs.add("CS-102");
	acs.add("CS-103");
	acs.add("CS-104");

	DepartmentIterator iter(acs);

	while (iter())
	{
		cout << *iter << endl;
		iter++;
	}
	system("pause");
	return 0;
}
