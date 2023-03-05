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

WorkTime::WorkTime() : _type(Type::PartTime), _Name("Денис"), _SurName("Сергеев"), _Patronymic("Андреевич"), _day(13), _month(12), _year(2003), _salary_hour(400), _add_salary(5), _hours(80) {}
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
float WorkTime::set_salary()
{
	float salaryItog = _salary;
	return salaryItog;
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


float WorkTime::Payroll_calculation() {
	//википедия Юлианская_дата
	//сделать обработку ошибки, если сюда херню передал
	//сделаю пока войдовой, потом на тестах проверю, если что сделать флот и вернуть зарплату
	time_t t;
	time(&t);
	int a1 = (14 - _month) / 12;
	int y1 = _year + 4800 - a1;
	int m1 = _month + 12 * a1 - 3;
	int jdn1 = _day + (153 * m1 + 2) / 5 + 365 * y1 + y1 / 4 - y1 / 100 + y1 / 400 - 32045;
	int nowday = localtime(&t)->tm_mday;
	int nowmonth = localtime(&t)->tm_mon+1;
	int nowyear = localtime(&t)->tm_year + 1900;
	int a = (14 - nowmonth) / 12;
	int y = nowyear + 4800 - a;
	int m = nowmonth + 12 * a - 3;
	int jdn = nowday + (153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 + y / 400 - 32045;
	int res = jdn - jdn1;
	float res_salary= _salary * (1 + 0.005 * (res / 365));
	return res_salary;
}
float WorkTime::Payroll_parttime()
{
	float res_salary = _salary_hour * _hours * (1 + _add_salary * 1.0 / 100);
	return res_salary;
}
float WorkTime::Getting_res()
{
	switch (_type)
	{
	case::Type::FullTime:
		return Payroll_calculation();
	case::Type::PartTime:
		return Payroll_parttime();
	default:
		throw runtime_error("[Function::compute_derivative] Invalid function type.");
	}
}
//возможно на подобии тут делаем парт тайм

