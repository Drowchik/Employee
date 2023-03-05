#include <gtest/gtest.h>
#include <Employee/Employee.h>

using namespace Employee;

TEST(EmployeeListTests, CapacityCheck) {
    EmployeeList _Worker;
    WorkTime worker1 = WorkTime::create_FullTime("Денис", "Сергеев", "Андреевич", 13, 12, 2003, 54000);
        for (int i = 0; i < EmployeeList::CAPACITY; i++) {
            _Worker.add(worker1);
        }
    ASSERT_ANY_THROW(_Worker.add(worker1));

}
TEST(EmployeeListTests, deletePerson)
{
    EmployeeList _Worker;
    WorkTime worker1 = WorkTime::create_PartTime("Денис", "Сергеев", "Андреевич", 13, 12, 2003, 400, 5, 80);
    _Worker.add(worker1);
    _Worker.add(worker1);
    _Worker.add(worker1);

    _Worker.deletePerson(1);

    Type a = _Worker[1].get_type();

    EXPECT_EQ(a, PartTime);
}
TEST(EmployeeListTests, insertPerson)
{
    EmployeeList _Worker;
    WorkTime worker1 = WorkTime::create_FullTime("Денис", "Сергеев", "Андреевич", 13, 12, 2003, 54000);
    WorkTime worker2 = WorkTime::create_PartTime("Денис", "Сергеев", "Андреевич", 13, 12, 2013, 700, 3, 40);
    _Worker.add(worker1);
    _Worker.insertPerson(worker2, 0);
    Type a = _Worker[0].get_type();
    EXPECT_EQ(a, PartTime);

}
TEST(EmployeeListTests, deletePerson1)
{
    EmployeeList _Worker;
    WorkTime worker1 = WorkTime::create_PartTime("Денис", "Сергеев", "Андреевич", 13, 12, 2003, 400, 5, 80);
    _Worker.add(worker1);
    _Worker.add(worker1);
    _Worker.add(worker1);

    _Worker.deletePerson(-1);

    Type a = _Worker[1].get_type();

    EXPECT_EQ(a, PartTime);
}
TEST(EmployeeListTests, insertPerson1)
{
    EmployeeList _Worker;
    WorkTime worker1 = WorkTime::create_FullTime("Денис", "Сергеев", "Андреевич", 13, 12, 2003, 54000);
    WorkTime worker2 = WorkTime::create_PartTime("Денис", "Сергеев", "Андреевич", 13, 12, 2013, 700, 3, 40);
    _Worker.add(worker1);
    _Worker.insertPerson(worker2, -1);
    Type a = _Worker[0].get_type();
    EXPECT_EQ(a, PartTime);

}
TEST(EmployeeListTests, CapacityCheck1) {
    EmployeeList _Worker;
    WorkTime worker1 = WorkTime::create_FullTime("Денис", "Сергеев", "Андреевич", 13, 12, 2003, 54000);
    for (int i = 0; i < EmployeeList::CAPACITY+2; i++) {
        _Worker.add(worker1);
    }
    ASSERT_ANY_THROW(_Worker.add(worker1));

}