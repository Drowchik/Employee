#include <Employee/Employee.h>
#include <stdexcept>

using namespace employee;
using namespace std;

int EmployeeList::size() const {
	return _data.size();
}
EmployeeList::EmployeeList(const EmployeeList& other)
{
	_data.reserve(other.size());
	for (const auto& ptr : other._data)
	{
		_data.push_back(ptr->clone());
	}
}
EmployeeList& EmployeeList::operator=(const EmployeeList& other)
{
	EmployeeList copy(other);
	copy.swap(*this);
	return *this;
}
void EmployeeList::swap(EmployeeList& other)
{
	std::swap(this->_data, other._data);

}
WorkerPtr EmployeeList :: operator[](const int index) const {
	if (index < 0)
	{
		throw out_of_range("[EmployeeList::operator[]] Index is out of range.");
	}
	return _data[index];
 }
void EmployeeList::add(WorkerPtr f) {
	_data.push_back(f);
}
void EmployeeList::delete_person(int index)
{
	if (index < 0)
	{
		throw out_of_range("[EmployeeList::operator[]] Index is out of range.");
	}
	auto iter = _data.cbegin();
	_data.erase(iter + index);
}	

void EmployeeList::insert_person(WorkerPtr people, int index)
{
	if (index < 0)
	{
		throw out_of_range("[EmployeeList::operator[]] Index is out of range.");
	}
	auto iter = _data.cbegin();
	_data.emplace(iter + index, people);
}
int employee::search_max_salary(const EmployeeList& _Worker)
{
	int max_index = -1;
	float max_sallary = 0;

	auto n = _Worker.size();

	for (int i = 0; i < n; i++)
	{
		auto value = _Worker[i]->payroll_calculation();
		if (value > max_sallary || max_index == -1)
		{
			max_index = i;
			max_sallary = value;
		}
	}
	return max_index;
}