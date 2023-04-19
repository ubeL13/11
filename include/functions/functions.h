#pragma once
#include <string>

namespace employee {

	enum class EmployeeTypes
	{
		FullTime, //штаный
		ByWorker, //—овместитель
	};

	class Employee
	{
	private:
		EmployeeTypes _type;
		double _per_ind_all;// процент индивижуальной надбавки 0-5%(совместитель)
		int _hour_last_mont;//кол-во отработанных часов за прошлый мес€ц(совместитель)
		double _base_rate;
		//int  _work_experience;
		std::string _surname;
		std::string _name;
		std::string _patroname;
		int _day;
		int _month;
		int _year;

		/*Employee(EmployeeTypes type, double per_ind_all);
		Employee(EmployeeTypes type, int hour_last_mont);
		Employee(EmployeeTypes type, double  base_rate_month);
		Employee(EmployeeTypes type, double base_rate_hour);
		Employee(EmployeeTypes type, double _work_experience);*/

	public:
		Employee(std::string _surname, std::string _name, std::string _patroname, int _day, int _month, int _year, int _base_rate);

		//Ўтатный
		//static Employee full_t(double base_rate_month);
		//static Employee full_t(char name);
		//static Employee full_t(int date);
		//static Employee full_t(int _work_experience);

		////—овместитель
		//static Employee by_work(double per_ind_all);   
		//static Employee by_work(int hour_last_mont);
		//static Employee by_work(double base_rate_hour);
		//static Employee by_work(char name);
		//static Employee by_work(int date);

		

		EmployeeTypes get_type() const;

		std::string get_name() const;
		std::string get_surname() const;
		std::string get_patroname() const;
		
		int get_day() const;
		int get_month() const;
		int get_year() const;

		int get_hour_last_mont() const;

		EmployeeTypes set_type() const;

		double set_per_ind_all() const;
		int set_base_rate() const;
		
		
		double sallary_full_time() const;
		double sallary_by_workl() const;






	};

	class EmployeeList 
	{
	public:
		static const int CAPACITY = 10;

	private:
		Employee _employee[CAPACITY];
		int _size;
	public:
		EmployeeList();

		int get_size() const;

		Employee operator[](int index) const;

		void insert(Employee p,int index);

		void delete_(int index);
	};

	int search_state_with_max_salary(const EmployeeList& employee);
}
