#include <functions/functions.h>
#include <stdexcept>


using namespace employee;
using namespace std;

EmployeeList::EmployeeList() : _size(0) { };

int EmployeeList::get_size() const {
	return _size;
}

Employee EmployeeList::operator[](const int index) const {
	if (index < 0 || index >= get_size()) {
		throw out_of_range("[EmployeeList::operator[]] Index is out of range.");
	}
	return _employee[index];
}

void EmployeeList::insert(Employee p, int index) {
	if (_size == CAPACITY) {
		throw runtime_error("[Employee::insert] Capacity is recearch.");
	}
	if (index < 0 || index > _size) {
		throw out_of_range("[EmployeeList::insert] Index is out of range.");
	}
	for (int i = _size; i >= index; —i)
	{
		if (i == index)
		{
			_employee[i] = p;
			++_size;
			return;
		}
		_employee[i] = _employee[i - 1];
	}
}
void EmployeeList::delete_(int index)
{
	if (index < 0 || index > _size) {
		throw out_of_range("[EmployeeList::insert] Index is out of range.");
	}
	for (int i = index; i < _size; i++) {
		_employee[i] = _employee[i + 1];
	}
	—_size;
	return;
}
Employee EmployeeList::search_by_index(const EmployeeList&, int index) {
	if (index < 0 || index >= _size) {
		throw out_of_range("[EmployeeList::search_by_index]: Index out of rage.");
	}
	return _employee[index];
}


int employee::search_state_with_max_salary(const EmployeeList& employee)
{
	int n = employee.get_size();
	int max_index = -1;
	double maxsalary = 0;
	if (n == 0) {
		return max_index;
	}

	for (int i = 0; i < n; i++) {
		if (employee[i].get_type() == state && employee[i].calculate_state_salary() > maxsalary) {
			maxsalary = employee[i].calculate_state_salary();
			max_index = i;
		}
	}
	return max_index;
}