#include <gtest/gtest.h>
#include <Employee/Employee.h>

using namespace employee;


TEST(EmployeeListTests, deletePerson)
{
    EmployeeList _Worker;
    WorkTime person;
    _Worker.add(person.create_full_time("Денис", "Сергеев", "Андреевич", 13, 12, 2003, 54000));
    _Worker.add(person.create_part_time("Денис", "Сергеев", "Андреевич", 13, 12, 2013, 700, 3, 40));
    _Worker.add(person.create_full_time("Денис", "Сергеев", "Андреевич", 13, 12, 2013, 20000));

    _Worker.delete_person(0);

    Type a = _Worker[0]->get_type();

    EXPECT_EQ(a, PartTime);
}
TEST(EmployeeListTests, size)
{
    EmployeeList _Worker;
    WorkTime person;
    _Worker.add(person.create_full_time("Денис", "Сергеев", "Андреевич", 13, 12, 2003, 54000));
    _Worker.add(person.create_part_time("Денис", "Сергеев", "Андреевич", 13, 12, 2013, 700, 3, 40));
    _Worker.add(person.create_full_time("Денис", "Сергеев", "Андреевич", 13, 12, 2013, 20000));
    _Worker.add(person.create_full_time("Денис", "Сергеев", "Андреевич", 13, 12, 2003, 54000));
    _Worker.add(person.create_part_time("Денис", "Сергеев", "Андреевич", 13, 12, 2013, 700, 3, 40));
    _Worker.add(person.create_full_time("Денис", "Сергеев", "Андреевич", 13, 12, 2013, 20000));
    _Worker.add(person.create_part_time("Денис", "Сергеев", "Андреевич", 13, 12, 2013, 700, 3, 40));
    _Worker.add(person.create_full_time("Денис", "Сергеев", "Андреевич", 13, 12, 2013, 20000));

    ASSERT_EQ(_Worker.size(), 8);
}
TEST(EmployeeListTests, size1)
{
    EmployeeList _Worker;
    WorkTime person;
    _Worker.add(person.create_full_time("Денис", "Сергеев", "Андреевич", 13, 12, 2003, 54000));
    _Worker.add(person.create_part_time("Денис", "Сергеев", "Андреевич", 13, 12, 2013, 700, 3, 40));
    _Worker.add(person.create_full_time("Денис", "Сергеев", "Андреевич", 13, 12, 2013, 20000));
    _Worker.add(person.create_full_time("Денис", "Сергеев", "Андреевич", 13, 12, 2003, 54000));
    _Worker.add(person.create_part_time("Денис", "Сергеев", "Андреевич", 13, 12, 2013, 700, 3, 40));
    _Worker.add(person.create_full_time("Денис", "Сергеев", "Андреевич", 13, 12, 2013, 20000));
    _Worker.add(person.create_part_time("Денис", "Сергеев", "Андреевич", 13, 12, 2013, 700, 3, 40));
    _Worker.add(person.create_full_time("Денис", "Сергеев", "Андреевич", 13, 12, 2013, 20000));
    _Worker.delete_person(0);
    ASSERT_EQ(_Worker.size(), 7);
}
TEST(EmployeeListTests, size2)
{
    EmployeeList _Worker;
    WorkTime person;
    _Worker.add(person.create_full_time("Денис", "Сергеев", "Андреевич", 13, 12, 2003, 54000));
    _Worker.add(person.create_part_time("Денис", "Сергеев", "Андреевич", 13, 12, 2013, 700, 3, 40));
    _Worker.delete_person(0);
    _Worker.delete_person(1);
    ASSERT_EQ(_Worker.size(), 0);
}
TEST(EmployeeListTests, insertPerson)
{
    EmployeeList _Worker;
    WorkTimePtr worker1 = WorkTime::create_full_time("Денис", "Сергеев", "Андреевич", 13, 12, 2003, 54000);
    WorkTimePtr worker2 = WorkTime::create_part_time("Денис", "Сергеев", "Андреевич", 13, 12, 2013, 700, 3, 40);
    _Worker.insert_person(worker2, 0);
    Type a = _Worker[0]->get_type();
    EXPECT_EQ(a, PartTime);

}

TEST(EmployeeListTests, search_max_salary)
{
    EmployeeList _Worker;
    WorkTime person;
    _Worker.add(person.create_full_time("Денис", "Сергеев", "Андреевич", 13, 12, 2003, 54000));
    _Worker.add(person.create_part_time("Денис", "Сергеев", "Андреевич", 13, 12, 2013, 700, 3, 40));
    _Worker.add(person.create_full_time("Денис", "Сергеев", "Андреевич", 13, 12, 2013, 20000));
    ASSERT_EQ(search_max_salary(_Worker), 0);

}

TEST(EmployeeListTests, search_max_salary1)
{
    EmployeeList _Worker;
    _Worker.add(WorkTime::create_full_time("Денис", "Сергеев", "Андреевич", 13, 12, 2003, 54000));
    _Worker.add(WorkTime::create_part_time("Денис", "Сергеев", "Андреевич", 13, 12, 2013, 900, 3, 120));
    _Worker.add(WorkTime::create_full_time("Денис", "Сергеев", "Андреевич", 13, 12, 2013, 20000));
    ASSERT_EQ(search_max_salary(_Worker), 1);

}
TEST(EmployeeListTests, deletePerson1) //исключения
{
    EmployeeList _Worker;
    _Worker.add(WorkTime::create_part_time("Денис", "Сергеев", "Андреевич", 13, 12, 2003, 400, 5, 80));
    _Worker.add(WorkTime::create_full_time("Денис", "Сергеев", "Андреевич", 13, 12, 2003, 54000));
    _Worker.add(WorkTime::create_part_time("Денис", "Сергеев", "Андреевич", 13, 12, 2013, 900, 3, 120));
    _Worker.add(WorkTime::create_full_time("Денис", "Сергеев", "Андреевич", 13, 12, 2013, 20000));

    _Worker.delete_person(-1);

    Type a = _Worker[1]->get_type();

    EXPECT_EQ(a, PartTime);
}

TEST(EmployeeListTests, insertPerson1)//иссключение
{
    EmployeeList _Worker;
    WorkTimePtr worker1 = WorkTime::create_full_time("Денис", "Сергеев", "Андреевич", 13, 12, 2003, 54000);
    WorkTimePtr worker2 = WorkTime::create_part_time("Денис", "Сергеев", "Андреевич", 13, 12, 2013, 700, 3, 40);
    _Worker.insert_person(worker2, -1);
    Type a = _Worker[0]->get_type();
    EXPECT_EQ(a, PartTime);
}