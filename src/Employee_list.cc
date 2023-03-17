#include <Employee/Employee.h>
#include <stdexcept>

using namespace employee;
using namespace std;

EmployeeList:: EmployeeList () : _size(0) {}

int EmployeeList::size() const {
	return _size;
}

WorkTime EmployeeList :: operator[](const int index) const {
	if (index < 0 || _size <= index)
	{
		throw out_of_range("[EmployeeList::operator[]] Index is out of range.");
	}
	return _Worker[index];
 }
void EmployeeList::add(const WorkTime f) {
	if (_size == CAPACITY) {
		throw runtime_error("[EmployeeList::add] Capacity is reached.");
	}
	_Worker[_size] = f;
	++_size;
}
void EmployeeList::remove(int index)
{
	_size = 0;
}
void EmployeeList::delete_person(int index)
{
	if (index < 0 || _size <= index)
	{
		throw out_of_range("[EmployeeList::operator[]] Index is out of range.");
	}
	WorkTime people;
	for (int i = index; i != CAPACITY-1; i++)
	{
		_Worker[i] = _Worker[i + 1];
	}
	_size--;
}	
void EmployeeList::insert_person(WorkTime people, int index)
{
	if (index < 0 || _size <= index)
	{
		throw out_of_range("[EmployeeList::operator[]] Index is out of range.");
	}
	else {
		for (int i = _size - 1; i != index; i--)
		{
			_Worker[i + 1] = _Worker[i];
		}
	}
	_Worker[index] = people;
	_size++;
}
int employee:: search_max_salary(const EmployeeList& _Worker)
{
	int max_index = -1;
	float max_sallary = 0;

	auto n = _Worker.size();

	for (int i = 0; i < n; i++)
	{
		auto value = _Worker[i].getting_res();
		if (value > max_sallary || max_index == -1)
		{
			max_index = i;
			max_sallary = value;
		}
	}
	return max_index;
}