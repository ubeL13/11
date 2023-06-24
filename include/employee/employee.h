#pragma once
#pragma once
#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>


namespace employee {
	
	

	class Employee {
	protected:
		std::string full_name;
		int year_of_hiring;
		
	public:
		Employee();
		Employee(const std::string& full_name, int year_of_hiring/* EmployeeType type, double basic_rate_for_month, int current_year*/);
		Employee(const Employee&) = default;
		void set_full_name(std::string full_name);
		void set_year_of_hiring(int year_of_hiring);
		std::string get_full_name() const;
		int get_year_of_hiring() const;
		virtual int compute_salary() = 0;
		virtual void print() const = 0;
		virtual std::shared_ptr<Employee> clone() const = 0;
		virtual ~Employee() = default;
	};

	class Staff : public Employee {
	private:
		int current_year;
		double basic_rate_for_month;

	public:	
		Staff();
		Staff(const std::string& full_name, int year_of_hiring, int current_year, double basic_rate_for_month);
		void set_basic_rate_for_month(double basic_rate_for_month);
		void set_current_year(int current_year);
		int get_current_year() const;
		double get_basic_rate_for_month()const;
		int compute_salary() override;
		void print() const override;
		std::shared_ptr<Employee> clone() const override;


	};
	class Freelance : public Employee {
	private:
		double basic_rate_for_hour;
		double percent_of_individual_allowance;
		int number_of_hours_in_month;

	public:
		Freelance();
		Freelance(const std::string& full_name, int year_of_hiring, double basic_rate_for_hour, double percent_of_individual_allowance, int number_of_hours_in_month);
		void set_basic_rate_for_hour(int basic_rate_for_hour);
		void set_percent_of_individual_allowance(double percent_of_individual_allowance);
		void set_number_of_hours_in_month(int number_of_hours_in_month);
		double get_basic_rate_for_hour() const;
		double get_percent_of_individual_allowance()const;
		int get_number_of_hours_in_month() const;
		int compute_salary() override;
		void print() const override;
		std::shared_ptr<Employee> clone() const override;
	};

		
		
		
	using EmployeePtr = std::shared_ptr<Employee>;
	
	
	class EmployeeList {
	private:
		std::vector<EmployeePtr> _employee;

	public:
		EmployeeList()=default;
		EmployeeList(const EmployeeList& list);
		EmployeeList& operator=(EmployeeList list);
		void swap(EmployeeList& list) noexcept;
		const EmployeePtr operator[](size_t index) const;
		EmployeePtr operator[](size_t index);
		size_t get_size() const;
		void add_employer(EmployeePtr employee);
		void insert_index(EmployeePtr employee, int index);
		void del_employer(int index);
		void clear();
		void print() const;
		int find_with_max_salary(EmployeePtr employees[]);
		
		
	};
	
	
}
