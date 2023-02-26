#include <Employee/Employee.h>

#include <cassert>
#include <cmath>
#include <stdexcept>
#include <ctime>

using namespace Employee;
using namespace std;

WorkTime WorkTime::create_FullTime(string _Name, string SurName, string Patronymic, int day, int month, int year, float salary) {
	return WorkTime(Type::FullTime, _Name, SurName, Patronymic, day, month, year, salary);
}
WorkTime WorkTime::create_PartTime(string Name, string SurName, string Patronymic, int day, int month, int year, float _salary_hour, int _add_salary, int _hours) {
	return WorkTime(Type::PartTime, Name, SurName, Patronymic, day, month, year, _salary_hour, _add_salary, _hours);
}

WorkTime::WorkTime() : _type(Type::FullTime), _Name("Денис"), _SurName("Сергеев"), _Patronymic("Андреевич"), _day(13), _month(12), _year(2003), _salary(54000){}
WorkTime::WorkTime(const Type type, const string Name, const string SurName, const string Patronymic, const int day, const int month, const int year, float salary){}

WorkTime::WorkTime() : _type(Type::FullTime), _Name("Денис"), _SurName("Сергеев"), _Patronymic("Андреевич"), _day(13), _month(12), _year(2003), _salary_hour(400), _add_salary(5), _hours(80) {}
WorkTime::WorkTime(const Type type, const string Name, const string SurName, const string Patronymic, const int day, const int month, const int year, float _salary_hour, const int _add_salary, const int _hours) {}


Type WorkTime::get_type() const {
	return _type;
}
string WorkTime::get_name() const {
	return _Name;
}
string WorkTime::get_surname() const {
	return _SurName;
}
string WorkTime::get_patronymic() const {
	return _Patronymic;
}
int WorkTime::get_day() const {
	return _day;
}
int WorkTime::get_month() const {
	return _month;
}
int WorkTime::get_year() const {
	return _year;
}
float WorkTime::get_salary() {
	return _salary;
}
float WorkTime::get_salary_hour() {
	return _salary_hour;
}
int WorkTime::get_add_salary() {
	return _add_salary;
}
int WorkTime::get_hours()
{
	return _hours;
}

int WorkTime::Payroll_calculation() {
	time_t t;
	time(&t);

	int nowday = localtime(&t)->tm_mday;
	int nowmonth = localtime(&t)->tm_mon;
	int nowyear = localtime(&t)->tm_year + 1900;
	double countday = ((nowyear * 12) + nowmonth * 30.42) + nowday;
	double countdaywork = ((_year * 12) + _month * 30.42) + _day;
	int countwork = (countday - countdaywork) / (365);
	for (int i = 0; i <= countwork; i++)
	{
		_salary = _salary * 1.05;
	}
	return _salary;
}
//возможно на подобии тут делаем парт тайм

