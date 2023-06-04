#include <employee/employee.h>
#include <windows.h>
#include <string>
#include <conio.h>
using namespace employee;
using namespace std;
int main() {
	SetConsoleTitle("Employee");
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	int s = 0;
	EmployeeList employee;
	string type;
	int t;
	int index;
	int f = 0;

	while (f == 0) {

		system("cls");
		cout << " ____________________________________________________________________" << endl;
		cout << " |                                Меню                               |" << endl;
		cout << " —-------------------------------------------------------------------" << endl;
		cout << " | 1 - добавить работника                                            |" << endl;
		cout << " | 2 - добавить новый работник по индексу                            |" << endl;
		cout << " | 3 - удалить работника по индексу                                  |" << endl;
		cout << " | 4 - выйти из системы                                              |" << endl;
		cout << "  -------------------------------------------------------------------" << endl;
		employee.display();

		cin >> t;

		switch (t) {
		case 1:
			
			cout << "Введите тип (Freelance, Staff): ";
			cin >> type;
			if (type == "Freelance") {
				EmployeeType vtype = Freelance;
				string name;
				double k;
				double proc;
				int chis;
				int yoh;

				cout << "Введите имя: ";
				cin >> name;
				cout << "Введите базовый тариф: ";
				cin >> k;
				cout << "Процент надбавки: ";
				cin >> proc;
				cout << "Отработанные часы: ";
				cin >> chis;
				cout << "Год найма: ";
				cin >> yoh;

				auto v = Employee(name, yoh, vtype, k, proc, chis);
				employee.add_employer(v);
				s++;
			}
			else if (type == "Staff") {
				EmployeeType vtype = Staff;
				string name;
				double k;
				int cury;
				int yoh;

				cout << "Введите имя: ";
				cin >> name;
				cout << "Введите базовый тариф: ";
				cin >> k;
				cout << "Текущий год: ";
				cin >> cury;
				cout << "Год найма: ";
				cin >> yoh;

				auto v = Employee(name, yoh, vtype, k, cury);
				employee.add_employer(v);
				s++;
			}

			else {
				cout << "Неверный тип";
				s = 0;
			}
			break;
			system("cls");
		case 2:
			
			cout << "Введите индекс: ";
			cin >> index;
			
				cout << "Введите тип (Freelance, Staff): ";
				cin >> type;
				if (type == "Freelance") {
					EmployeeType vtype = Freelance;
					string name;
					double k;
					double proc;
					int chis;
					int yoh;

					cout << "Введите имя: ";
					cin >> name;
					cout << "Введите базовый тариф: ";
					cin >> k;
					cout << "Процент надбавки: ";
					cin >> proc;
					cout << "Отработанные часы: ";
					cin >> chis;
					cout << "Год найма: ";
					cin >> yoh;

					auto v = Employee(name, yoh, vtype, k, proc, chis);
					employee.insert_index(v, index);
					s++;
				}
				else if (type == "Staff") {
					EmployeeType vtype = Staff;
					string name;
					double k;
					int cury;
					int yoh;

					cout << "Введите имя: ";
					cin >> name;
					cout << "Введите базовый тариф: ";
					cin >> k;
					cout << "Текущий год: ";
					cin >> cury;
					cout << "Год найма: ";
					cin >> yoh;

					auto v = Employee(name, yoh, vtype, k, cury);
					employee.insert_index(v, index);
					s++;
				}

				else {
					cout << "Неверный тип";
					s = 0;
				}
			
			break;
		case 3:
			
			cout << "Введите индекс: ";
			cin >> index;
			employee.del_employer(index);
			break;
		case 4:
			if (t == 4)
			{
				return 0;
			}
			break;
		
		}

	}	
		



}
