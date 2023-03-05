#include <gtest/gtest.h>

#include <Employee/Employee.h>

using namespace Employee;

TEST(EmployeeTests, Getting_res1) {
    static auto worker1 = WorkTime::create_FullTime("Денис", "Сергеев", "Андреевич", 13, 12, 2003, 54000);
    float res = worker1.Getting_res();
    EXPECT_EQ(res, 124512);
}

