#include"singleton.h"

int main() {

	//Database db("mydb");//  конструктор з параметрами недоступний
	Database& database = Database::getInstance("products");

	cout << "This is the " << database.getName() << " database.\n";

	database = Database::getInstance("employees");

	cout << "This is the " << database.getName() << " database.\n";
	system("pause");
	return 0;
}
