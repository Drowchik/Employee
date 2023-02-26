#include <Employee/Employee.h>
#include <stdexcept>

using namespace Employee;
using namespace std;

EmployeeList:: EmployeeList () : _size(0) {}

int EmployeeList::size() const {
	return _size;
}

FullTime EmployeeList :: operator[](const int index) const {
	if (index < 0 || _size <= index)
	{
		throw out_of_range("[FunctionList::operator[]] Index is out of range.");
	}
	return _Worker[index];
 }
void EmployeeList::add(const FullTime f) {
	if (_size == CAPACITY) {
		throw runtime_error("[FunctionList::add] Capacity is reached.");
	}
	_Worker[_size] = f;
	++_size;
}