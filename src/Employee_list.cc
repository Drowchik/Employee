#include <Employee/Employee.h>
#include <stdexcept>

using namespace Employee;
using namespace std;

EmployeeList:: EmployeeList () : _size(0) {}

int EmployeeList::size() const {
	return _size;
}

WorkTime EmployeeList :: operator[](const int index) const {
	if (index < 0 || _size <= index)
	{
		throw out_of_range("[FunctionList::operator[]] Index is out of range.");
	}
	return _Worker[index];
 }
void EmployeeList::add(const WorkTime f) {
	if (_size == CAPACITY) {
		throw runtime_error("[FunctionList::add] Capacity is reached.");
	}
	_Worker[_size] = f;
	++_size;
}
void EmployeeList::remove(int index)
{
	_size = 0;
}
int search_max_salary(const EmployeeList& _Worker)
{
	int max_index = -1;
	float max_sallary = 0;

	const auto n = _Worker.size();

	for (int i = 0; i < n; i++)
	{
		const auto value = _Worker[i].Getting_res();
		if (value < max_sallary || max_index==-1)
		{
			max_index = i;
			max_sallary = value;
		}
	}
	return max_index;
}