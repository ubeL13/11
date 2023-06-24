#include <employee/employee.h>
#include <windows.h>
#include <string>
#include <conio.h>
using namespace employee;
using namespace std;
void app() {
	cout << " ____________________________________________________________________" << endl;
	cout << " |                                Меню                               |" << endl;
	cout << " —-------------------------------------------------------------------" << endl;
	cout << " | 1 - добавить транспорт											  |" << endl;
	cout << " | 2 - вставить транспорт по индексу                                 |" << endl;
	cout << " | 3 - удалить транспорт по индексу                                  |" << endl;
	cout << " | 4 - вывести список транспорта                                     |" << endl;
	cout << " | 5 - рассчитать стоимость перевозки                                |" << endl;
	cout << " | 6 - выйти из системы                                              |" << endl;
	cout << "  -------------------------------------------------------------------" << endl;
}
shared_ptr<Employee> create_employee() {
	string name;
	int type;
	double k, a, proc, chis;
	int typeeng, yoh, cury;
	cout << "Введите тип (Staff-1,Freelance-2): ";
	cin >> type;
	if (type != 1 and type != 2)
		throw runtime_error("Unknown type");
	cout << "Введите имя: ";
	getline(cin >> ws, name);
	cout << "Введите базоую ставку : ";
	cin >> k;
	switch (type)
	{
	case 1:
		cout << "Текущий год: ";
		cin >> cury;
		cout << "Год найма: ";
		cin >> yoh;
		return make_shared<Staff>(name, k, yoh, cury);
	case 2:
		cout << "Процент надбавки: ";
		cin >> proc;
		cout << "Отработанные часы: ";
		cin >> chis;
		cout << "Год найма: ";
		cin >> yoh;
		return make_shared<Freelance>(name, k, proc, chis, yoh);
	
	}
}
int main()
{
	SetConsoleTitle("Employee");
	setlocale(LC_ALL, "");
	SetConsoleCP(1251);
	EmployeeList employee;
	app();
	while (true)
	{
		int k;
		cin >> k;
		int index = 0;
		float m, d;
		system("cls");
		app();
		if (k == 6) {
			employee.clear();
			break;
		}
		switch (k)
		{
		case 1:
			system("cls");
			employee.add_employer(create_employee());
			system("cls");
			app();
			break;
		case 2:
			cout << "Введите индекс для вставки : ";
			cin >> index;
			employee.insert_index(create_employee(), index);
			break;
		case 3:
			cout << "Введите индекс, который нужно удалить: ";
			cin >> index;
			employee.del_employer(index);
			break;
		case 4:
			employee.print();
			break;
		case 5:
			cout << "Введите индекс транспорта, стоимость перевозки которого нужно посчитать: ";
			cin >> index;
			cout << employee[index]->compute_salary();
			break;
		
		}
	}
	return 0;
}
