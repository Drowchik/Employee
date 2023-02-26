#pragma once
#include <string>

namespace Employee {
	enum class Type {
		FullTime,
		PartTime
	};
	class FullTime {
		private:
			Type _type;
			std::string _Name;
			std::string _SurName;
			std::string _Patronymic;
			int _day;
			int _month;
			int _year;
			int _salary;
			FullTime(Type type, std::string Name, std::string SurName, std::string _Patronymic, int day, int month, int year, int salary);

		public:
			static FullTime create_FullTime(std::string Name, std::string SurName, std::string _Patronymic, int day, int month, int year, int salary);
			FullTime();
			Type get_type() const;
			std::string get_name() const;
			std::string get_surname() const;
			std::string get_patronymic() const;
			int get_day() const;
			int get_month() const;
			int get_year() const;
			int get_salary() const;
			
			int Payroll_calculation() const;


	};
	/* class PartTime {
	private:
		std::string _Name;
		std::string _SurName;
		std::string _Patronymic;
		int _day;
		int _month;
		int _year;
		int _salary_hour;
		int _add_salary;
		int _hours;
		PartTime(Type type, std::string Name, std::string SurName, int day, int month, int year, int _salary_hour, int _add_salary, int _hours);
	};*/
}
