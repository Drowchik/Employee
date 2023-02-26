#pragma once
#include <string>

namespace Employee {
	enum class Type {
		FullTime,
		PartTime
	};
	class WorkTime {
		private:
			Type _type;
			std::string _Name;
			std::string _SurName;
			std::string _Patronymic;
			int _day;
			int _month;
			int _year;
			float _salary;
			float _salary_hour;
			int _add_salary;
			int _hours;
			WorkTime(Type type, std::string Name, std::string SurName, std::string _Patronymic, int day, int month, int year, float salary);
			WorkTime(Type type, std::string Name, std::string SurName, std::string _Patronymic, int _day, int _month, int _year, float _salary_hour, int _add_salary, int _hours);

		public:
			static WorkTime create_FullTime(std::string _Name, std::string SurName, std::string _Patronymic, int day, int month, int year, float salary);
			static WorkTime create_PartTime(std::string Name, std::string SurName, std::string _Patronymic, int day, int month, int year, float _salary_hour, int _add_salary, int _hours);
			WorkTime();
			Type get_type() const;
			std::string get_name() const;
			std::string get_surname() const;
			std::string get_patronymic() const;
			int get_day() const;
			int get_month() const;
			int get_year() const;
			float get_salary();
			float get_salary_hour();
			int get_add_salary();
			int get_hours();
			//добавить парт тайм сами функции
			
			int Payroll_calculation();


	};

	class EmployeeList {
		public:
			static const int CAPACITY = 10;
		private:
			WorkTime _Worker[CAPACITY];
			int _size;
		public:
			EmployeeList();
			int size() const;
			WorkTime operator[](int index) const;
			void add(WorkTime f);
			//инсерт, ремове
	};

}
