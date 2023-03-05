#include <gtest/gtest.h>

#include <Employee/Employee.h>

using namespace Employee;

TEST(EmployeeTests, Getting_res_full_time) {
    WorkTime worker1=WorkTime::create_FullTime("Денис", "Сергеев", "Андреевич", 13, 12, 2003, 54000);
    float res = worker1.Getting_res();
    EXPECT_EQ(res, 59130);
}
TEST(EmployeeTests, Getting_res_full_time2) {
    WorkTime worker1 = WorkTime::create_FullTime("Денис", "Сергеев", "Андреевич", 7, 9, 1995, 37000);
    float res = worker1.Getting_res();
    EXPECT_EQ(res, 41995);
}
TEST(EmployeeTests, Getting_res_part_time) {
    WorkTime worker1 = WorkTime::create_PartTime("Денис", "Сергеев", "Андреевич", 13, 12, 2003, 400, 5, 80);
    float res = worker1.Getting_res();
    EXPECT_EQ(res, 33600);
}
TEST(EmployeeTests, Getting_res_part_time2) {
    WorkTime worker1 = WorkTime::create_PartTime("Денис", "Сергеев", "Андреевич", 13, 12, 2013, 700, 3, 40);
    float res = worker1.Getting_res();
    EXPECT_EQ(res, 28840); 

}
TEST(EmployeeTests, Getting_res_full_time3) {
    WorkTime worker1 = WorkTime::create_FullTime("Денис", "Сергеев", "Андреевич", 7, 9, 1955, 37777);
    double res = worker1.Getting_res();
    EXPECT_NEAR(res, 50432.3, 0.1);
}
TEST(EmployeeTests, Getting_res_part_time3) {
    WorkTime worker1 = WorkTime::create_PartTime("Денис", "Сергеев", "Андреевич", 13, 12, 2013, 700, 3, 0);
    float res = worker1.Getting_res();
    EXPECT_EQ(res, 0);
}
TEST(EmployeeTests, Getting_res_part_time4) {
    WorkTime worker1 = WorkTime::create_PartTime("Денис", "Сергеев", "Андреевич", 13, 12, 2013, 333, 3, 33);
    float res = worker1.Getting_res();
    EXPECT_NEAR(res, 11318.67, 0.1);
}

