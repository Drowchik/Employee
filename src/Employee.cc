#include <Employee/Employee.h>
#include<iostream>
#include <memory>
#include <cassert>
#include <cmath>
#include <stdexcept>
#include <ctime>

using namespace employee;
using namespace std;


Worker::Worker(const string Name, const string SurName, const string Patronymic, const int day, const int month, const int year) : _name(Name), _surname(SurName), _patronymic(Patronymic), _day(day), _month(month), _year(year) {}
Full_time::Full_time(const string Name, const string SurName, const string Patronymic, const int day, const int month, const int year, float salary) : Worker(Name, SurName, Patronymic, day, month, year), _salary(salary) {}
Part_time::Part_time(const string Name, const string SurName, const string Patronymic, const int day, const int month, const int year, float salary_hour, const int add_salary, const int hours) : Worker(Name, SurName, Patronymic, day, month, year), _salary_hour(salary_hour), _add_salary(add_salary), _hours(hours) {}

string Worker::get_name() const {
	return _name;
}
string Worker::get_surname() const {
	return _surname;
}
string Worker::get_patronymic() const {
	return _patronymic;
}
int Worker::get_day() const {
	return _day;
}
int Worker::get_month() const {
	return _month;
}
int Worker::get_year() const {
	return _year;
}
float Full_time::get_salary()const {
	return _salary;
}
float Part_time::get_salary_hour()const {
	return _salary_hour;
}
int Part_time::get_add_salary()const {
	return _add_salary;
}
int Part_time::get_hours()const
{
	return _hours;
}

void Worker::set_name(string name)
{
	_name = name;
}
void Worker::set_surname(string surname)
{
	_surname = surname;
}
void Worker::set_patronymic(string patronymic) {
	_patronymic = patronymic;
}
void Worker::set_day(int day)
{
	_day = day;
}
void Worker::set_month(int month)
{
	_month = month;
}
void Worker::set_year(int year) {
	_year = year;
}
void Full_time::set_salary(float salary)
{
	_salary = salary;
}
void Part_time::set_salary_hour(float slary_hour)
{
	_salary_hour = slary_hour;
}
void Part_time::set_add_salary(int add_salary)
{
	_add_salary = add_salary;
}
void Part_time::set_hours(int hours)
{
	_hours = hours;
}



double Full_time::payroll_calculation() {
	//википедия Юлианская_дата
	time_t t;
	time(&t);
	int a1 = (14 - get_month()) / 12;
	int y1 = get_year() + 4800 - a1;
	int m1 = get_month() + 12 * a1 - 3;
	int jdn1 = get_day() + (153 * m1 + 2) / 5 + 365 * y1 + y1 / 4 - y1 / 100 + y1 / 400 - 32045;
	int nowday = localtime(&t)->tm_mday;
	int nowmonth = localtime(&t)->tm_mon+1;
	int nowyear = localtime(&t)->tm_year + 1900;
	int a = (14 - nowmonth) / 12;
	int y = nowyear + 4800 - a;
	int m = nowmonth + 12 * a - 3;
	int jdn = nowday + (153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 + y / 400 - 32045;
	int res = jdn - jdn1;
	double res_salary= _salary * (1 + 0.005 * (res / 365));
	return res_salary;
}
double Part_time::payroll_calculation()
{
	double res_salary = _salary_hour * _hours * (1 + _add_salary * 1.0 / 100);
	return res_salary;
}
unique_ptr<Worker> Full_time::clone() const {
	return make_unique<Full_time>(_name, _surname, _patronymic, _day, _month, _year, _salary);
}
unique_ptr<Worker> Part_time::clone() const {
	return make_unique<Part_time>(_name, _surname, _patronymic, _day, _month, _year, _salary_hour, _add_salary, _hours);
}
std::ostream& Full_time::print(std::ostream& oc) const {
	oc << "\t Фул-тайм рабочий\t\n" << "Фамилия: " << get_surname() << endl << "Имя: " << get_name() << endl
		<< "Отчество: " << get_patronymic() <<endl<< "Дата наёма на работу: " << get_day() << '.' << get_month() <<'.'
		<< get_year() << endl << "Зарплата: " << get_salary() << endl;
	return oc;
}
std::ostream& Part_time::print(std::ostream& oc) const {
	oc << "\t Парт-тайм рабочий\t\n" << "Фамилия: " << get_surname() << endl << "Имя: " << get_name() << endl
		<< "Отчество: " << get_patronymic() <<endl<< "Дата наёма на работу: " << get_day() << '.' << get_month() <<'.'
		<< get_year() << endl << "Почасовая ставка: " << get_salary_hour() << endl << "Процент надбавки: " <<
		get_add_salary() << "Количество часов: " << get_hours() << endl;
	return oc;
}
