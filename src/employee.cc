#include <employee/employee.h>
#include<string>
#include <cassert>
#include <cmath>
#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <cstdio>

using namespace std;
using namespace employee;



Employee::Employee() {
	full_name = "";
	year_of_hiring = 0;
	current_year = 0;
	type = Staff;
	basic_rate_for_month = 0;
	basic_rate_for_hour = 0;
	percent_of_individual_allowance = 0;
	number_of_hours_in_month = 0;
}

void Employee::set_full_name(string full_name) 
{ 
	this->full_name = full_name;
}
void Employee::set_year_of_hiring(int year_of_hiring)  
{ 
	this->year_of_hiring = year_of_hiring;
}
void Employee::set_current_year(int current_year) 
{
	this->current_year = current_year;
}
void Employee::set_type(EmployeeType type) 
{
	this->type = type; 
}
void Employee::set_basic_rate_for_month(int basic_rate_for_month) 
{
	this->basic_rate_for_month = basic_rate_for_month;
}
void Employee::set_basic_rate_for_hour(int basic_rate_for_hour) 
{ 
	this->basic_rate_for_hour = basic_rate_for_hour; 
}
void Employee::set_percent_of_individual_allowance(double percent_of_individual_allowance) 
{ 
	this->percent_of_individual_allowance = percent_of_individual_allowance; 
}
void Employee::set_number_of_hours_in_month(int number_of_hours_in_month) 
{ 
	this->number_of_hours_in_month = number_of_hours_in_month; 
}


string Employee::get_full_name() const
{
	return full_name; 
}
int Employee::get_year_of_hiring() const
{
	return year_of_hiring; 
}
int Employee::get_current_year() const 
{ 
	return current_year; 
}
EmployeeType Employee::get_type() const
{
	return type;
}
std::string Employee::get_type1() const {
	switch (type)
	{
	case EmployeeType::Freelance:
		return "Freelance";
	case EmployeeType::Staff:
		return "Staff";
	default:
		throw runtime_error("Unknown type");
	}
}
double Employee::get_basic_rate_for_month() const
{
	return basic_rate_for_month; 
}
double Employee::get_basic_rate_for_hour() const
{ 
	return basic_rate_for_hour;
}
double Employee::get_percent_of_individual_allowance() const
{
	return percent_of_individual_allowance; 
}
int Employee::get_number_of_hours_in_month() const
{
	return number_of_hours_in_month;
}

Employee::Employee(string full_name, int year_of_hiring, EmployeeType type,double basic_rate_for_month, int current_year) {
	this->full_name = full_name;
	this->year_of_hiring = year_of_hiring;
	this->type = type;
	this->basic_rate_for_month = basic_rate_for_month;
	this->current_year = current_year;
}

Employee::Employee(string full_name, int year_of_hiring, EmployeeType type, double basic_rate_for_hour,
	double percent_of_individual_allowance, int number_of_hours_in_month) {
	this->full_name = full_name;
	this->year_of_hiring = year_of_hiring;
	this->type = type;
	this->basic_rate_for_hour = basic_rate_for_hour;
	this->percent_of_individual_allowance = percent_of_individual_allowance;
	this->number_of_hours_in_month = number_of_hours_in_month;
}



int Employee::compute_salary() const {
	if (type == Staff) {
		int salary = basic_rate_for_month + ((double(current_year) - double(year_of_hiring)) * 0.005) * basic_rate_for_month;
		return salary;
	}
	if (type == Freelance) {
		int salary = ((1.0 + (0.01 * percent_of_individual_allowance)) * basic_rate_for_hour) * double(number_of_hours_in_month);
		return salary;
	}
	else {
		throw runtime_error("the method is not for that type.");
	}
}

//3лаба
//Employee* Employee::clone() const {
//	if (type == Staff) {
//		return new Employee(full_name, year_of_hiring, type, basic_rate_for_month, current_year);
//	}
//	else if (type == Freelance) {
//		return new Employee(full_name, year_of_hiring, type, basic_rate_for_hour, percent_of_individual_allowance, number_of_hours_in_month);
//	}
//	else {
//		throw runtime_error("invalid employee type");
//	}
//}


std::ostream& employee::operator<<(std::ostream& stream, const Employee& employee)
{
	if (employee.get_type1() == "Staff")
		stream << " Name: " << employee.get_full_name() << "\n" << " Year of hiring" << employee.get_year_of_hiring()<< "\n" <<  "Employee Type: " << employee.get_type() << "\n" << " Basic Rate: " << employee.get_basic_rate_for_month() <<  "\n" << "Current Year" << employee.get_current_year();
	else if (employee.get_type1() == "Freelance")
		stream << " Name: " << employee.get_full_name() << "\n" << " Year of hiring" << employee.get_year_of_hiring() << "\n" << "Employee Type: " << employee.get_type() << "\n" << " Basic Rate: " << employee.get_basic_rate_for_hour() << "\n" << "Procent of individual allowance " << employee.get_percent_of_individual_allowance() << "\n" << "number_of_hours_in_month " << employee.get_number_of_hours_in_month();
	return stream;;
	
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////

EmployeeList::EmployeeList() :_employee(nullptr), _size(0) {}

EmployeeList::EmployeeList(const EmployeeList& list) :_employee(new Employee* [list._size]), _size(list._size) {
	for (int i = 0; i < _size; ++i) {
		_employee[i] = new Employee(*list._employee[i]);
	}
}




int EmployeeList::get_size() const {
	return _size;
}

void EmployeeList::swap(EmployeeList& list) noexcept {
	std::swap(this->_employee, list._employee);
	std::swap(this->_size, list._size);
}



EmployeeList& EmployeeList::operator=(EmployeeList list)
{
	swap(list);
	return *this;
}
EmployeeList::~EmployeeList() {
	clear();
}
void EmployeeList::clear()
{
	if (_employee == nullptr)
		return;
	for (int i = 0; i < _size; ++i)
		delete _employee[i];
	_size = 0;
	delete[] _employee;
	_employee = nullptr;
}



const Employee& EmployeeList::operator[]( int index) const
{
	if (index < 0 || index <= _size)
	{
		throw runtime_error("Index out of range.");
	}
	return *_employee[index];
}
Employee& EmployeeList::operator[](int index)
{
	if (index < 0 || index <= _size)
	{
		throw runtime_error("Index out of range.");
	}
	return *_employee[index];
}

//добавление
void EmployeeList::add_employer(Employee employee)
{
	auto new_employee = new Employee*[_size + 1];
	for (int i = 0; i < _size; ++i) {
		new_employee[i] = _employee[i];
	}
	new_employee[_size] = new Employee(employee);
	delete[] _employee;
	_employee = new_employee;
	++_size;
}


void EmployeeList::insert_index(Employee employee, int index)
{
	++_size;
	if (index < 0 || index>_size) {
		throw runtime_error("Index out of range.");
	}
	auto new_employee = new Employee*[_size];
	for (int i = 0; i < _size; ++i)
	{
		new_employee[i] = _employee[i];
	}
	for (int i = _size-1; i > index; --i)
	{
		new_employee[i] = new_employee[i - 1];
	}
	new_employee[index] = new Employee(employee);
	delete[] _employee;
	_employee = new_employee;

}



//удаление 
void EmployeeList::del_employer(int index)
{
	if (_size == 0) {
		throw runtime_error("EmployeeList is empty");
	}
	if (index < 0 || index >= _size) {
		throw runtime_error("Index out of range.");
	}
	auto new_employee = new Employee*[_size - 1];
	/*for (int i = 0; i < index; i++)
	{
		new_employee[i] = _employee[i];
	}*/
	for (int i = index; i < _size-1; ++i)
	{
		new_employee[i] = _employee[i+1];
	}
	delete[] _employee;
	_employee = new_employee;
	--_size;
}

//Вычисление макимума 
int EmployeeList::find_with_max_salary(Employee* employees[]) 
{
	
	int index = 0;
	double max_salary = employees[0]->compute_salary();
	for (int i = 1; i <= _size - 1; ++i)
	{
		double cur_salary = employees[i]->compute_salary();
		if (cur_salary > max_salary)
		{
			index = i;
			max_salary = cur_salary;
		}
	}
	return index;
}


const Employee& EmployeeList::get_employee(int index) const {
	if (index < 0 or index >= _size)
		throw runtime_error("error");
	return *_employee[index];
}
//////////////////////////////////////////

std::ostream& employee::operator<<(std::ostream& stream, const EmployeeList& employee)
{
	setlocale(LC_ALL, " ");
	stream << employee.get_size() << " Employee:  " << endl;
	for (int i = 0; i < employee.get_size(); i++) cout << "  " << i + 1 << ") " << employee.get_employee(i);
	return stream;
}

void EmployeeList::display() {

	cout << "База данных сотрудников:" << endl;
	


	for (int i = 0; i < _size; ++i) {

		cout << i << " " << *_employee[i] << endl;
	}
}








