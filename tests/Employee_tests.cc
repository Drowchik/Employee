#include <gtest/gtest.h>

#include <Employee/Employee.h>

using namespace employee;
using namespace std;

TEST(EmployeeTests, Getting_salary_full_time1) {
    auto person = make_shared<Full_time>("Денис", "Сергеев", "Андреевич", 7, 9, 1995, 37000);
    EXPECT_EQ(person->get_salary(), 37000);
}
TEST(EmployeeTests, Getting_salary_part_time1) {
    auto person = make_shared<Part_time>("Денис", "Сергеев", "Андреевич", 13, 12, 2003, 400, 5, 80);
    EXPECT_EQ(person->get_add_salary(), 5);
}
TEST(EmployeeTests, Getting_res_full_time2) {
    auto person = make_shared<Full_time>("Денис", "Сергеев", "Андреевич", 7, 9, 1995, 37000);
    float res = person->payroll_calculation();
    EXPECT_EQ(res, 41995);
}
TEST(EmployeeTests, Getting_res_part_time) {
    auto person = make_shared<Part_time>("Денис", "Сергеев", "Андреевич", 13, 12, 2003, 400, 5, 80);
    EXPECT_EQ(person->payroll_calculation(), 33600);
}
TEST(EmployeeTests, Getting_res_part_time2) {
    auto person = make_shared<Part_time>("Денис", "Сергеев", "Андреевич", 13, 12, 2013, 700, 3, 40);
    EXPECT_EQ(person->payroll_calculation(), 28840);
}
TEST(EmployeeTests, Getting_res_full_time3) {
    auto person = make_shared<Full_time>("Денис", "Сергеев", "Андреевич", 7, 9, 1955, 37777);
    EXPECT_NEAR(person->payroll_calculation(), 50432.3, 0.1);
}
TEST(EmployeeTests, Getting_res_part_time3) {
    auto person = make_shared<Part_time>("Денис", "Сергеев", "Андреевич", 13, 12, 2013, 700, 3, 0);
    EXPECT_EQ(person->payroll_calculation(), 0);
}
TEST(EmployeeTests, Getting_res_part_time4) {
    auto person = make_shared<Part_time>("Денис", "Сергеев", "Андреевич", 13, 12, 2013, 333, 3, 33);
    EXPECT_NEAR(person->payroll_calculation(), 11318.67, 0.1);
}
