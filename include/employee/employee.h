#pragma once
#pragma once
#include <string>
#include <iostream>
#include <stdexcept>


namespace employee {
	enum EmployeeType {
		Staff,
		Freelance
	};
	

	class Employee {
	private:
		std::string full_name;
		int year_of_hiring;
		int current_year;
		EmployeeType type;
		double basic_rate_for_month;
		double basic_rate_for_hour;
		double percent_of_individual_allowance;
		int number_of_hours_in_month;
	public:
		void set_full_name(std::string full_name) ;
		void set_year_of_hiring(int year_of_hiring) ;
		void set_current_year(int current_year) ;
		void set_type(EmployeeType type);
		void set_basic_rate_for_month(int basic_rate_for_month) ;
		void set_basic_rate_for_hour(int basic_rate_for_hour) ;
		void set_percent_of_individual_allowance(double percent_of_individual_allowance) ;
		void set_number_of_hours_in_month(int number_of_hours_in_month) ;
		std::string get_full_name() const;
		int get_year_of_hiring() const;
		int get_current_year() const;
		EmployeeType get_type() const;
		std::string get_type1() const;
		double get_basic_rate_for_month()const;
		double get_basic_rate_for_hour() const;
		double get_percent_of_individual_allowance()const;
		int get_number_of_hours_in_month() const;

		Employee();
		Employee(std::string full_name, int year_of_hiring, EmployeeType type, double basic_rate_for_month, int current_year);
		Employee(std::string full_name, int year_of_hiring, EmployeeType type, double basic_rate_for_hour, double percent_of_individual_allowance, int number_of_hours_in_month);

		//Employee* clone() const;

		int compute_salary() const;

		
	};
	std::ostream& operator<<(std::ostream& stream, const Employee& employee);
	
	class EmployeeList {
		Employee** _employee;
		int _size;

	public:
		EmployeeList();
		EmployeeList(const EmployeeList& list);
		~EmployeeList();
		const Employee& operator[](int index) const;
		Employee& operator[](int index);
		EmployeeList& operator=(EmployeeList list);
		void add_employer(Employee employee);
		void insert_index(Employee employee, int index);
		int get_size() const;
		void swap(EmployeeList& list) noexcept;
		
		void del_employer(int index);
		void clear();
	
		int find_with_max_salary(Employee* employees[]);
		const Employee& get_employee(int index) const;
		void display();
		
	};
	
	std::ostream& operator<<(std::ostream& stream, const EmployeeList& employee);
}
