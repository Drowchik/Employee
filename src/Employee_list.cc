#include <Employee/Employee.h>
#include <stdexcept>

using namespace employee;
using namespace std;

EmployeeList:: EmployeeList () :_ptr(nullptr), _size(0) {}

int EmployeeList::size() const {
	return _size;
}
EmployeeList::EmployeeList(const EmployeeList& other) : _ptr(new WorkTimePtr[other._size]), _size(other._size)
{
	for (int i = 0; i < _size; i++)
	{
		_ptr[i] = other[i]->clone();
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
	std::swap(this->_ptr, other._ptr);
	std::swap(this->_size, other._size);

}
WorkTimePtr EmployeeList :: operator[](const int index) const {
	if (index < 0 || _size <= index)
	{
		throw out_of_range("[EmployeeList::operator[]] Index is out of range.");
	}
	return _ptr[index];
 }
void EmployeeList::add(WorkTimePtr const f) {
	auto new_employe = new WorkTimePtr[_size + 1];
	for (int i = 0; i < _size; i++)
	{
		new_employe[i] = _ptr[i];
	}
	new_employe[_size] = f;
	delete[] _ptr;
	_ptr = new_employe;
	_size++;
}
EmployeeList::~EmployeeList()
{
	for (int i = 0; i < _size; i++)
	{
		delete _ptr[i];
	}
	delete[]_ptr;
}
void EmployeeList::delete_person(int index)
{
	if (index < 0)
	{
		throw out_of_range("[EmployeeList::operator[]] Index is out of range.");
	}
	auto copy = new WorkTimePtr[_size - 1];

	for (int i = 0; i != _size-1; i++)
	{
		if (i < index)
		{
			copy[i] = _ptr[i];
		}
		else
			copy[i] = _ptr[i + 1];
	}
	delete [] _ptr;
	_ptr = copy;
	_size--;
}	

void EmployeeList::insert_person(WorkTimePtr people, int index)
{
	if (index < 0)
	{
		throw out_of_range("[EmployeeList::operator[]] Index is out of range.");
	}
	auto copy = new WorkTimePtr[_size + 1];
	for (int i = 0; i < _size; i++)
	{
		if (i < index)
		{
			copy[i] = _ptr[i];
		}
		else
			copy[i+1] = _ptr[i];
	}
	copy[index] = people;
	delete[] _ptr;
	_ptr = copy;
	_size++;
}
int employee:: search_max_salary(const EmployeeList& _Worker)
{
	int max_index = -1;
	float max_sallary = 0;

	auto n = _Worker.size();

	for (int i = 0; i < n; i++)
	{
		auto value = _Worker[i]->getting_res();
		if (value > max_sallary || max_index == -1)
		{
			max_index = i;
			max_sallary = value;
		}
	}
	return max_index;
}