#include <employee/employee.h>
#include <windows.h>
#include <string>
#include <conio.h>
using namespace employee;
using namespace std;
void app() {
	cout << " ____________________________________________________________________" << endl;
	cout << " |                                ����                               |" << endl;
	cout << " �-------------------------------------------------------------------" << endl;
	cout << " | 1 - �������� ���������											  |" << endl;
	cout << " | 2 - �������� ��������� �� �������                                 |" << endl;
	cout << " | 3 - ������� ��������� �� �������                                  |" << endl;
	cout << " | 4 - ������� ������ ����������                                     |" << endl;
	cout << " | 5 - ���������� ��������� ���������                                |" << endl;
	cout << " | 6 - ����� �� �������                                              |" << endl;
	cout << "  -------------------------------------------------------------------" << endl;
}
shared_ptr<Employee> create_employee() {
	string name;
	int type;
	double k, a, proc, chis;
	int typeeng, yoh, cury;
	cout << "������� ��� (Staff-1,Freelance-2): ";
	cin >> type;
	if (type != 1 and type != 2)
		throw runtime_error("Unknown type");
	cout << "������� ���: ";
	getline(cin >> ws, name);
	cout << "������� ������ ������ : ";
	cin >> k;
	switch (type)
	{
	case 1:
		cout << "������� ���: ";
		cin >> cury;
		cout << "��� �����: ";
		cin >> yoh;
		return make_shared<Staff>(name, k, yoh, cury);
	case 2:
		cout << "������� ��������: ";
		cin >> proc;
		cout << "������������ ����: ";
		cin >> chis;
		cout << "��� �����: ";
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
			cout << "������� ������ ��� ������� : ";
			cin >> index;
			employee.insert_index(create_employee(), index);
			break;
		case 3:
			cout << "������� ������, ������� ����� �������: ";
			cin >> index;
			employee.del_employer(index);
			break;
		case 4:
			employee.print();
			break;
		case 5:
			cout << "������� ������ ����������, ��������� ��������� �������� ����� ���������: ";
			cin >> index;
			cout << employee[index]->compute_salary();
			break;
		
		}
	}
	return 0;
}
