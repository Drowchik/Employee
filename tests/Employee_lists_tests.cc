#include <gtest/gtest.h>
#include <Employee/Employee.h>

using namespace employee;
using namespace std;

TEST(EmployeeListTests, deletePerson)
{
    EmployeeList _Worker;
    _Worker.add(make_shared<Full_time>("Денис", "Сергеев", "Андреевич", 7, 9, 1995, 37000));
    _Worker.add(make_shared<Part_time>("Денис", "Сергеев", "Андреевич", 13, 12, 2013, 700, 3, 40));
    _Worker.add(make_shared<Full_time>("Денис", "Сергеев", "Андреевич", 13, 12, 2013, 20000));
    _Worker.delete_person(0);
    int data = _Worker[0]->get_year();
    EXPECT_EQ(data, 2013);
}

TEST(EmployeeListTests, size)
{
   
    EmployeeList _Worker;
    _Worker.add(make_shared<Full_time>("Денис", "Сергеев", "Андреевич", 13, 12, 2003, 54000));
    _Worker.add(make_shared<Part_time>("Денис", "Сергеев", "Андреевич", 13, 12, 2013, 700, 3, 40));
    _Worker.add(make_shared<Full_time>("Денис", "Сергеев", "Андреевич", 13, 12, 2013, 20000));
    _Worker.add(make_shared<Full_time>("Денис", "Сергеев", "Андреевич", 13, 12, 2003, 54000));
    _Worker.add(make_shared<Part_time>("Денис", "Сергеев", "Андреевич", 13, 12, 2013, 700, 3, 40));
    _Worker.add(make_shared<Full_time>("Денис", "Сергеев", "Андреевич", 13, 12, 2013, 20000));
    _Worker.add(make_shared<Part_time>("Денис", "Сергеев", "Андреевич", 13, 12, 2013, 700, 3, 40));
    _Worker.add(make_shared<Full_time>("Денис", "Сергеев", "Андреевич", 13, 12, 2013, 20000));

    ASSERT_EQ(_Worker.size(), 8);
}

TEST(EmployeeListTests, size1)
{
    EmployeeList _Worker;
    _Worker.add(make_shared<Full_time>("Денис", "Сергеев", "Андреевич", 13, 12, 2003, 54000));
    _Worker.add(make_shared<Part_time>("Денис", "Сергеев", "Андреевич", 13, 12, 2013, 700, 3, 40));
    _Worker.add(make_shared<Full_time>("Денис", "Сергеев", "Андреевич", 13, 12, 2013, 20000));
    _Worker.add(make_shared<Full_time>("Денис", "Сергеев", "Андреевич", 13, 12, 2003, 54000));
    _Worker.add(make_shared<Part_time>("Денис", "Сергеев", "Андреевич", 13, 12, 2013, 700, 3, 40));
    _Worker.add(make_shared<Full_time>("Денис", "Сергеев", "Андреевич", 13, 12, 2013, 20000));
    _Worker.add(make_shared<Part_time>("Денис", "Сергеев", "Андреевич", 13, 12, 2013, 700, 3, 40));
    _Worker.add(make_shared<Full_time>("Денис", "Сергеев", "Андреевич", 13, 12, 2013, 20000));
    _Worker.delete_person(0);
    ASSERT_EQ(_Worker.size(), 7);
}

TEST(EmployeeListTests, size2)
{
    EmployeeList _Worker;
    _Worker.add(make_shared<Full_time>("Денис", "Сергеев", "Андреевич", 13, 12, 2003, 54000));
    _Worker.add(make_shared<Part_time>("Денис", "Сергеев", "Андреевич", 13, 12, 2013, 700, 3, 40));
    _Worker.delete_person(0);
    ASSERT_EQ(_Worker.size(), 1);
}

TEST(EmployeeListTests, insertPerson)
{
    EmployeeList _Worker;
    _Worker.add(make_shared<Full_time>("Денис", "Сергеев", "Андреевич", 13, 12, 2003, 54000));
    _Worker.add(make_shared<Part_time>("Денис", "Сергеев", "Андреевич", 13, 12, 2013, 700, 3, 40));
    auto person = make_shared<Full_time>("Денис", "Сергеев", "Андреевич", 7, 9, 1995, 37000);
    _Worker.insert_person(person, 0);
    int salary = _Worker[0]->get_year();
    EXPECT_EQ(salary, 1995);

}

TEST(EmployeeListTests, search_max_salary)
{
    EmployeeList _Worker;
    _Worker.add(make_shared<Full_time>("Денис", "Сергеев", "Андреевич", 13, 12, 2003, 54000));
    _Worker.add(make_shared<Part_time>("Денис", "Сергеев", "Андреевич", 13, 12, 2013, 700, 3, 40));
    _Worker.add(make_shared<Full_time>("Денис", "Сергеев", "Андреевич", 13, 12, 2013, 20000));
    ASSERT_EQ(search_max_salary(_Worker), 0);

}

TEST(EmployeeListTests, search_max_salary1)
{
    EmployeeList _Worker;
    _Worker.add(make_shared<Full_time>("Денис", "Сергеев", "Андреевич", 13, 12, 2003, 54000));
    _Worker.add(make_shared<Part_time>("Денис", "Сергеев", "Андреевич", 13, 12, 2013, 900, 3, 120));
    _Worker.add(make_shared<Full_time>("Денис", "Сергеев", "Андреевич", 13, 12, 2013, 20000));
    ASSERT_EQ(search_max_salary(_Worker), 1);

}