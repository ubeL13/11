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
		cout << " |                                ����                               |" << endl;
		cout << " �-------------------------------------------------------------------" << endl;
		cout << " | 1 - �������� ���������                                            |" << endl;
		cout << " | 2 - �������� ����� �������� �� �������                            |" << endl;
		cout << " | 3 - ������� ��������� �� �������                                  |" << endl;
		cout << " | 4 - ����� �� �������                                              |" << endl;
		cout << "  -------------------------------------------------------------------" << endl;
		employee.display();

		cin >> t;

		switch (t) {
		case 1:
			
			cout << "������� ��� (Freelance, Staff): ";
			cin >> type;
			if (type == "Freelance") {
				EmployeeType vtype = Freelance;
				string name;
				double k;
				double proc;
				int chis;
				int yoh;

				cout << "������� ���: ";
				cin >> name;
				cout << "������� ������� �����: ";
				cin >> k;
				cout << "������� ��������: ";
				cin >> proc;
				cout << "������������ ����: ";
				cin >> chis;
				cout << "��� �����: ";
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

				cout << "������� ���: ";
				cin >> name;
				cout << "������� ������� �����: ";
				cin >> k;
				cout << "������� ���: ";
				cin >> cury;
				cout << "��� �����: ";
				cin >> yoh;

				auto v = Employee(name, yoh, vtype, k, cury);
				employee.add_employer(v);
				s++;
			}

			else {
				cout << "�������� ���";
				s = 0;
			}
			break;
			system("cls");
		case 2:
			
			cout << "������� ������: ";
			cin >> index;
			
				cout << "������� ��� (Freelance, Staff): ";
				cin >> type;
				if (type == "Freelance") {
					EmployeeType vtype = Freelance;
					string name;
					double k;
					double proc;
					int chis;
					int yoh;

					cout << "������� ���: ";
					cin >> name;
					cout << "������� ������� �����: ";
					cin >> k;
					cout << "������� ��������: ";
					cin >> proc;
					cout << "������������ ����: ";
					cin >> chis;
					cout << "��� �����: ";
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

					cout << "������� ���: ";
					cin >> name;
					cout << "������� ������� �����: ";
					cin >> k;
					cout << "������� ���: ";
					cin >> cury;
					cout << "��� �����: ";
					cin >> yoh;

					auto v = Employee(name, yoh, vtype, k, cury);
					employee.insert_index(v, index);
					s++;
				}

				else {
					cout << "�������� ���";
					s = 0;
				}
			
			break;
		case 3:
			
			cout << "������� ������: ";
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
