#include <employee/employee.h>
#include<string>
#include <cassert>
#include <cmath>
#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <utility>
#include <vector>

using namespace std;
using namespace employee;



Employee::Employee() : full_name(""), year_of_hiring(0) {}
Employee::Employee(const std::string& full_name, int year_of_hiring): full_name(full_name), year_of_hiring(year_of_hiring){}
string Employee::get_full_name() const 
{
	return full_name;
}
int Employee::get_year_of_hiring() const
{
	return year_of_hiring;
}
void Employee::set_full_name(string full_name)
{
	this->full_name = full_name;
}
void Employee::set_year_of_hiring(int year_of_hiring)
{
	this->year_of_hiring = year_of_hiring;
}
///////////////
Staff::Staff() : Employee() , current_year (0), basic_rate_for_month (0) {}
Staff::Staff(const std::string& full_name, int year_of_hiring, int current_year, double basic_rate_for_month) : Employee(full_name, year_of_hiring), current_year(current_year), basic_rate_for_month(basic_rate_for_month){}

void Staff::set_current_year(int current_year) 
{
	this->current_year = current_year;
}
void Staff::set_basic_rate_for_month(double basic_rate_for_month) 
{
	this->basic_rate_for_month = basic_rate_for_month;
}
int Staff::get_current_year() const
{
	return current_year;
}
double Staff::get_basic_rate_for_month() const
{
	return basic_rate_for_month;
}
int Staff::compute_salary() {
	return basic_rate_for_month + ((double(current_year) - double(year_of_hiring)) * 0.005) * basic_rate_for_month;
}
void Staff::print() const { cout << " Name: " << full_name << "\n" << " Year of hiring" << year_of_hiring << "\n" << " Basic Rate: " << basic_rate_for_month << "\n" << "Current Year" << current_year << endl; }
shared_ptr<Employee> Staff::clone() const { return make_shared<Staff>(full_name, year_of_hiring, current_year, basic_rate_for_month); }


//////////
Freelance::Freelance() : Employee(), basic_rate_for_hour(0), percent_of_individual_allowance(0), number_of_hours_in_month(0){}
Freelance::Freelance(const std::string& full_name, int year_of_hiring, double basic_rate_for_hour, double percent_of_individual_allowance, int number_of_hours_in_month) : Employee(full_name, year_of_hiring), basic_rate_for_hour(basic_rate_for_hour), percent_of_individual_allowance(percent_of_individual_allowance), number_of_hours_in_month(number_of_hours_in_month){}

void Freelance::set_basic_rate_for_hour(int basic_rate_for_hour) 
{ 
	this->basic_rate_for_hour = basic_rate_for_hour; 
}
void Freelance::set_percent_of_individual_allowance(double percent_of_individual_allowance) 
{ 
	this->percent_of_individual_allowance = percent_of_individual_allowance; 
}
void Freelance::set_number_of_hours_in_month(int number_of_hours_in_month) 
{ 
	this->number_of_hours_in_month = number_of_hours_in_month; 
}
double Freelance::get_basic_rate_for_hour() const
{ 
	return basic_rate_for_hour;
}
double Freelance::get_percent_of_individual_allowance() const
{
	return percent_of_individual_allowance; 
}
int Freelance::get_number_of_hours_in_month() const
{
	return number_of_hours_in_month;
}

int employee::Freelance::compute_salary()
{
	return ((1.0 + (0.01 * percent_of_individual_allowance)) * basic_rate_for_hour) * double(number_of_hours_in_month);
}

void Freelance::print() const {cout << " Name: " << full_name << "\n" << " Year of hiring" << year_of_hiring << "\n" << " Basic Rate: " << basic_rate_for_hour << "\n" << "Procent of individual allowance " << percent_of_individual_allowance << "\n" << "number_of_hours_in_month " << number_of_hours_in_month << endl;}
shared_ptr<Employee> Freelance::clone() const { return make_shared<Freelance>(full_name, year_of_hiring, basic_rate_for_hour, percent_of_individual_allowance, number_of_hours_in_month); }



/////////////////////////////////////////////////////////////////////////////////////////////////////////

//EmployeeList::EmployeeList() :_employee(nullptr), _size(0) {}

EmployeeList::EmployeeList(const EmployeeList& employee) {
	for (int i = 0; i < _employee.size(); ++i) {
		_employee.push_back(employee[i]->clone());
	}
};

EmployeeList& EmployeeList::operator=(EmployeeList list)
{
	swap(list);
	return *this;
}

void EmployeeList::swap(EmployeeList& employee) noexcept {
	_employee.swap(employee._employee);
}

void EmployeeList::clear() {
	_employee.clear();
}


const EmployeePtr EmployeeList::operator[](size_t index) const
{
	if (index < 0 or _employee.size() <= index)
		throw out_of_range("Invalid index");
	return _employee[index];
}

EmployeePtr EmployeeList::operator[](size_t index)
{
	if (index < 0 or _employee.size() <= index)
		throw out_of_range("Invalid index");
	return _employee[index];
}

//добавление
void EmployeeList::add_employer(EmployeePtr employee) {
	_employee.push_back(employee);
}
size_t EmployeeList::get_size() const {
	return _employee.size();
}

void EmployeeList::insert_index(EmployeePtr vehicle, int index) {
	if (index < 0 or _employee.size() <= index)
		throw runtime_error("[EmployeeList::insert]Invalid index");

	_employee.insert(_employee.begin() + index, vehicle);
}



//удаление 
void EmployeeList::del_employer(int index) {
	if (index < 0 or _employee.size() <= index)
		throw runtime_error("[EmployeeList::remove]Invalid index");

	_employee.erase(_employee.begin() + index);
}

void EmployeeList::print() const {
	for (int i = 0; i < _employee.size(); ++i) {
		cout << " " << i + 1 << ")";
		_employee[i]->print();
	}
	cout << endl;
}
//¬ычисление макимума 
int EmployeeList::find_with_max_salary(EmployeePtr employees[]) 
{
	int s = _employee.size();
	int index = 0;
	double max_salary = employees[0]->compute_salary();
	for (int i = 1; i <= s; ++i)
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











