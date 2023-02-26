#include <Employee/Employee.h>

#include <cassert>
#include <cmath>
#include <stdexcept>
#include <ctime>

using namespace Employee;
using namespace std;

FullTime FullTime::create_FullTime(string Name, string SurName, string Patronymic, int day, int month, int year, int salary) {
	return FullTime(Type::FullTime, Name, SurName, Patronymic, day, month, year, salary);
}
//просто данные вносим
Type FullTime::get_type() const {
	return _type;
}
string FullTime::get_name() const {
	return _Name;
}
string FullTime::get_surname() const {
	return _SurName;
}
string FullTime::get_patronymic() const {
	return _Patronymic;
}
int FullTime::get_day() const {
	return _day;
}
int FullTime::get_month() const {
	return _month;
}
int FullTime::get_year() const {
	return _year;
}
int FullTime::get_salary() const {
	return _salary;
}

int FullTime::Payroll_calculation() const {
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
		
	}

}
//возможно на подобии тут делаем парт тайм

