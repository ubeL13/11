
#include <functions/functions.h>
#include <stdexcept>
#include <cmath>
#include <string>


using namespace employee;
using namespace std;




employee::Employee::Employee(std::string _surname, std::string _name, std::string _patroname, int _day, int _month, int _year, int _base_rate) :_type(employee::EmployeeTypes::FullTime)
{

}

//штатный
//Employee Employee::full_t(const double _base_rate_month)
//{
//    return Employee(EmployeeTypes::FullTime, _base_rate_month);
//}
//
//Employee Employee::full_t(const char _name)
//{
//    return Employee(EmployeeTypes::FullTime, _name);
//}
//
//Employee Employee::full_t(const int _date)
//{
//    return Employee(EmployeeTypes::FullTime, _date);
//}
//Employee Employee::full_t(const int _base_rate_month)
//{
//    return Employee(EmployeeTypes::FullTime, _base_rate_month);
//}
//
//
//
////совместитель
//
//Employee Employee::by_work(const double _per_ind_all)
//{
//    return Employee(EmployeeTypes::ByWorker, _per_ind_all);
//}
//
//Employee Employee::by_work(const int _hour_last_mont)
//{
//    return Employee(EmployeeTypes::ByWorker, _hour_last_mont);
//}
//
//Employee Employee::by_work(const double _base_rate_hour)
//{
//    return Employee(EmployeeTypes::ByWorker, _base_rate_hour);
//}
//
//Employee Employee::by_work(const char _name)
//{
//    return Employee(EmployeeTypes::ByWorker, _name);
//}
//
//Employee Employee::by_work(const int _date)
//{
//    return Employee(EmployeeTypes::ByWorker, _date);
//}



//геттеры
EmployeeTypes Employee::get_type() const
{
    return _type;
}

int Employee::get_day() const
{
    return _day;
}
int Employee::get_month() const
{
    return _month;
}
int Employee::get_year() const
{
    return _year;
}

std::string Employee::get_name() const
{
    return _name;
}
std::string Employee::get_surname() const
{
    return _surname;
}
std::string Employee::get_patroname() const
{
    return _patroname;
}

int Employee::get_hour_last_mont() const
{
    return _hour_last_mont;
}


//сеттеры
EmployeeTypes Employee::set_type() const
{
    return _type;
}

double Employee::set_per_ind_all() const
{
    return _per_ind_all;
}

int Employee::set_base_rate() const
{
    return _base_rate;
}





double Employee::sallary_by_workl() const 
{
    return _base_rate * _hour_last_mont * _per_ind_all;
}

double Employee::sallary_full_time() const
{
//    return _base_rate*pow(1.5, _work_experience);
//}
