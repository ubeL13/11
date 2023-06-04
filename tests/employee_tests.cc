#include <gtest/gtest.h>
#include <employee/employee.h>
#define CAPACITY 10

using namespace employee;
TEST(EmployeeTests, EmployeeDefaultConstructorNameTest) {
    Employee person1 = Employee();
    EXPECT_EQ(person1.get_full_name(), "");
}
TEST(EmployeeTests, EmployeeDefaultConstructorYearOfHiringTest) {
    Employee person1 = Employee();
    EXPECT_EQ(person1.get_year_of_hiring(), 0);
}
TEST(EmployeeTests, EmployeeDefaultConstructorBasicRateForMonthTest) {
    Employee person1 = Employee();
    EXPECT_EQ(person1.get_basic_rate_for_month(), 0);
}
TEST(EmployeeTests, EmployeeDefaultConstructorBasicRateForHourTest) {
    Employee person1 = Employee();
    EXPECT_EQ(person1.get_basic_rate_for_hour(), 0);
}
TEST(EmployeeTests, EmployeetConstructorTest) {
    Employee person1 = Employee("Vladimir Petrov", 2020, Staff, 45000, 2023);
    EXPECT_EQ(person1.get_full_name(), "Vladimir Petrov");
}
TEST(EmployeeTests, EmployeetConstructorTest2) {
    Employee person1 = Employee("Vladimir Petrov", 2020, Staff, 45000, 2023);
    EXPECT_EQ(person1.get_current_year(), 2023);
}
TEST(EmployeeTests, EmployeetConstructorTest3) {
    Employee person1 = Employee("Sergey Smirnov", 2020, Freelance, 200, 2.5, 150);
    EXPECT_EQ(person1.get_type(), Freelance);
}
TEST(EmployeeTests, EmployeetConstructorTest4) {
    Employee person1 = Employee("Sergey Smirnov", 2020, Freelance, 200, 2.5, 150);
    EXPECT_EQ(person1.get_percent_of_individual_allowance(), 2.5);
}
TEST(EmployeeTests, EmployeeSetterTest) {
    Employee person1;
    person1.set_type(Staff);
    EXPECT_EQ(person1.get_type(), Staff);
}
TEST(EmployeeTests, EmployeeSetterTest2) {
    Employee person1;
    person1.set_year_of_hiring(2019);
    EXPECT_EQ(person1.get_year_of_hiring(), 2019);
}
TEST(EmployeeTests, EmployeeSetterTest3) {
    Employee person1;
    person1.set_basic_rate_for_month(37500);
    EXPECT_EQ(person1.get_basic_rate_for_month(), 37500);
}
TEST(EmployeeTests, EmployeeSetterTest4) {
    Employee person1;
    person1.set_full_name("Vitaliy Ivanov");
    EXPECT_EQ(person1.get_full_name(), "Vitaliy Ivanov");
}
TEST(EmployeeTests, EmployeeComputeSalaryTest) {
    Employee person1("Konstantin Jukov", 2021, Staff, 30000.0, 2023);
    EXPECT_EQ(person1.compute_salary(), 30300);
}
TEST(EmployeeTests, EmployeeComputeSalaryTest2) {
    Employee person1("Ivan Krilov", 2021, Freelance, 150.4, 2.7, 140);
    EXPECT_EQ(person1.compute_salary(), 21624);
}
TEST(EmployeeListTests, EmployeeListDefaultConstructorTest) {
    EmployeeList EL = EmployeeList();
    EXPECT_EQ(EL.get_size(), 0);
}

TEST(EmployeeListTests, EmployeeListClearTest) {
    EmployeeList EL = EmployeeList();
    EL.clear();
    EXPECT_EQ(EL.get_size(), 0);
}
