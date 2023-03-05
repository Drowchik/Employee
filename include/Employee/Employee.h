#pragma once
#include <string>

namespace Employee {
	enum Type {
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
			
			
			double Payroll_calculation();
			double Payroll_parttime();
			double Getting_res();

	};

	class EmployeeList {
		public:
			static const int CAPACITY = 10;
			EmployeeList();
			int size() const;
			WorkTime operator[](int index) const;
			void add(WorkTime f);
			void deletePerson(int index);
			void insertPerson(WorkTime people, int index);
			//insert(int index, WorkTime f);
			void remove (int index);
			//инсерт, ремове
	private:
		WorkTime _Worker[CAPACITY];
		int _size;
	};
	int search_max_salary(const EmployeeList& _Worker);
}
