#pragma once
#include<iostream>
#include <string>
//можно добавить стаж в отдельную переменную
namespace employee {
	enum Type {
		FullTime,
		PartTime
	};
	class WorkTime;
	using WorkTimePtr = WorkTime*;
	std::ostream& operator<<(std::ostream& stream, const WorkTimePtr& people);
	class WorkTime {
		private:
			Type _type;
			std::string _name;
			std::string _surname;
			std::string _patronymic;
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
			static WorkTimePtr create_full_time(std::string _Name, std::string SurName, std::string _Patronymic, int day, int month, int year, float salary);
			static WorkTimePtr create_part_time(std::string Name, std::string SurName, std::string _Patronymic, int day, int month, int year, float _salary_hour, int _add_salary, int _hours);
			WorkTime();
			Type get_type() const;
			std::string get_name() const;
			std::string get_surname() const;
			std::string get_patronymic() const;
			int get_day() const;
			int get_month() const;
			int get_year() const;
			float get_salary() const;
			float get_salary_hour() const;
			int get_add_salary() const;
			int get_hours() const;
			WorkTimePtr clone() const;
			
			void set_type(Type type);
			void set_name(std::string name);
			void set_surname(std::string surname);
			void set_patronymic(std::string patronymic);
			void set_day(int day);
			void set_month(int month);
			void set_year(int year);
			void set_salary(float salary);
			void set_salary_hour(float slary_hour);
			void set_add_salary(int add_salary);
			void set_hours(int hours);
			
			
			double payroll_calculation();
			double payroll_parttime();
			double getting_res();

	};

	class EmployeeList {
		public:
			EmployeeList();
			EmployeeList(const EmployeeList& other);
			EmployeeList& operator=(const EmployeeList & other);
			int size() const;
			void swap(EmployeeList& other);
			WorkTimePtr operator[](int index) const;
			void add(WorkTimePtr const f);
			~EmployeeList();
			void delete_person(int index);
			void insert_person(WorkTimePtr people, int index);
	private:
		WorkTimePtr* _ptr;
		int _size;
	};
	int search_max_salary(const EmployeeList& _Worker);
}
