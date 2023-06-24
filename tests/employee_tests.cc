#include <gtest/gtest.h>
#include <employee/employee.h>


using namespace employee;

TEST(StaffTest, DefaultConstructor)
{
	Staff staff;
	EXPECT_EQ(staff.get_full_name(), "");
	EXPECT_EQ(staff.get_year_of_hiring(), 0);
	EXPECT_EQ(staff.get_current_year(), 0);
	EXPECT_EQ(staff.get_basic_rate_for_month(), 0);
}

TEST(StaffTest, ComputeSalary)
{
	Staff staff("John Smith", 2015, 2020, 1000);
	EXPECT_EQ(staff.compute_salary(), 1025);
}

TEST(FreelanceTest, DefaultConstructor)
{
	Freelance f;
	EXPECT_EQ(f.get_full_name(), "");
	EXPECT_EQ(f.get_year_of_hiring(), 0);
	EXPECT_EQ(f.get_basic_rate_for_hour(), 0);
	EXPECT_EQ(f.get_percent_of_individual_allowance(), 0);
	EXPECT_EQ(f.get_number_of_hours_in_month(), 0);
}

TEST(FreelanceTest, ComputeSalary)
{
	Freelance f("John Smith", 2015, 50, 10, 100);
	EXPECT_EQ(f.compute_salary(), 5500);
}
