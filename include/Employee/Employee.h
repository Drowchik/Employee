#pragma once
#include<iostream>
#include <string>
#include <memory>
#include <vector>
namespace employee {
	class Worker;
	using WorkerPtr = std::shared_ptr<Worker>;
	class Worker
	{
		private:
		public:
			virtual double payroll_calculation() = 0;
			virtual std::unique_ptr<Worker> clone() const = 0;
			virtual std::ostream& print(std::ostream& os = std::cout) const = 0;
			virtual ~Worker() = default;
			std::string get_name() const;
			std::string get_surname() const;
			std::string get_patronymic() const;
			int get_day() const;
			int get_month() const;
			int get_year() const;
			void set_name(std::string name);
			void set_surname(std::string surname);
			void set_patronymic(std::string patronymic) ;
			void set_day(int day);
			void set_month(int month);
			void set_year(int year);
			Worker(std::string _name, std::string _surname, std::string _patronymic, int _day, int _month, int _year);
 		protected:
			std::string _name;
			std::string _surname;
			std::string _patronymic;
			int _day;
			int _month;
			int _year;
			Worker() = default;
			Worker(const Worker&) = default;
			Worker& operator=(const Worker&) = default;
	};
	class Full_time : public Worker
	{
		private:
			float _salary;
		public: 
			double payroll_calculation() override;
			std::unique_ptr<Worker> clone() const override;
			std::ostream& print(std::ostream& os) const override;
			float get_salary() const;
			void set_salary(float salary);
			Full_time(std::string Name, std::string SurName, std::string _Patronymic, int _day, int _month, int _year, float salary);
		
	};
	class Part_time : public Worker
	{
		private:
			float _salary_hour;
			int _add_salary;
			int _hours;
	    public: 
			double payroll_calculation() override;
			std::unique_ptr<Worker> clone() const override;
			std::ostream& print(std::ostream& os) const override;
			Part_time(std::string Name, std::string SurName, std::string _Patronymic, int day, int month, int year, float _salary_hour, int _add_salary, int _hours);
			float get_salary_hour() const;
			int get_add_salary() const;
			int get_hours() const;
			void set_salary_hour(float slary_hour);
			void set_add_salary(int add_salary);
			void set_hours(int hours);
	};

	class EmployeeList {
		public:
			EmployeeList() = default;
			EmployeeList(const EmployeeList& other);
			EmployeeList& operator=(const EmployeeList & other);
			int size() const;
			void swap(EmployeeList& other);
			WorkerPtr operator[](int index) const;
			void add(WorkerPtr const f);
			void delete_person(int index);
			void insert_person(WorkerPtr people, int index);
	private:
		std::vector <WorkerPtr> _data;
	};
	int search_max_salary(const EmployeeList& _Worker);
}
