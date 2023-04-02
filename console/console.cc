#include <Employee/Employee.h>
#include<iostream>
#include <conio.h>

using namespace employee;
using namespace std;

int GetKey()
{
	int key = _getch();
	if ((key == 0) || (key == 224))
	{
		key = _getch();
	}
	return key;
}
void Arrow(int position_real, int position)
{
	if (position_real == position)
	{
		printf("-->");
	}
	else
	{
		printf("   ");
	}
}
int Menu()
{
	int position = 1;
	int KeyPres = 0;
	while (KeyPres != 13)
	{
		cout<<"\t����\t"<< endl;
		Arrow(1, position); cout<<"�������� ������� � ������ �� ���������� �������"<<endl;
		Arrow(2, position); cout << "������� ������� �� ������ �� ��������� �������" << endl;
		Arrow(3, position); cout << "������� ������ �� �����"<<endl;
		Arrow(4, position); cout << "����� �� ������������ ��������" << endl;
		Arrow(5, position); cout << "�����" << endl << endl;
		KeyPres = GetKey();
		system("cls");
		if (KeyPres == 72 && position != 1)
			position--;
		else if (KeyPres == 80 && position != 5)
		{
			position++;
		}


	}
	return position;
}

int main() {
	setlocale(LC_ALL, "Russian");
	EmployeeList _Worker;
	WorkTimePtr worker1;
	while (true)
	{
		int choice1 = Menu();
		switch (choice1)
		{
			case 1: 
			{
				cout << "�� ������ � ������� ������� �������� � ������ �� ��������� �������" << endl;
				int index = 0;
				cout << "������� ������ ������ ��� ������� ��������" << endl;
				cin >> index;
				cout << "�������� ������ ��������� �� ������ ��������: FullTime - 1, PartTime - 2" << endl;
				int choice2=0;
				cin >> choice2;
				if (choice2 != 1 && choice2 != 2)
				{
					cout << "�� ����� ����������� ������!";
					break;
				}
				std::string name;
				std::string _surname;
				std::string _patronymic;
				int _day;
				int _month;
				int _year;
				switch (choice2)
				{

					case 1:
					{
						float _salary;
						cout << "������� ���: " << endl;
						cin >> name;
						cout << "������� �������: " << endl;
						cin >> _surname;
						cout << "������� ��������: " << endl;
						cin >> _patronymic;
						cout << "������� ����, ����� ���������� �� ������, � �������: ���� ����� ��� " << endl;
						cin >> _day >> _month >> _year;
						cout << "������� ���� ��������: ";
						cin >> _salary;
						worker1=WorkTime::create_full_time(name, _surname, _patronymic, _day, _month, _year, _salary);
					}
					case 2:
					{
						float _salary_hour;
						int _add_salary;
						int _hours;
						cout << "������� ���: " << endl;
						cin >> name;
						cout << "������� �������: " << endl;
						cin >> _surname;
						cout << "������� ��������: " << endl;
						cin >> _patronymic;
						cout << "������� ����, ����� ���������� �� ������, � �������: ���� ����� ��� " << endl;
						cin >> _day >> _month >> _year;
						cout << "������� ��������� ������: " << endl;
						cin >> _salary_hour;
						cout << "������� ������� �������������� �������� �� 0 �� 5% " << endl;
						cin >> _add_salary;
						cout << "������� ���-�� ������� ����� �� ��������� �����: " << endl;
						cin >> _hours;
						worker1 = WorkTime::create_part_time(name, _surname, _patronymic, _day, _month, _year, _salary_hour, _add_salary, _hours);

					}
				}
				_Worker.insert_person(worker1, index);
				break; 
			}
			case 2: {
				cout << "�� ������ � ������� �������� �������" << endl;
				cout << "������� ������ �������, ������� ������ �������" << endl;
				int index = -1;
				cin >> index;
				_Worker.delete_person(index);
				break; 
			}
			case 3: 
				int size=_Worker.size();
				for (int i = 0; i < size; i++)
				{
					cout << _Worker[i];
				}
				break;
			case 4:
				int index=search_max_salary(_Worker);
				cout << "�������� � ������������ ���������� ������: " << endl;
				cout << _Worker[index];
				break;
			case 5: 
				return 0;
		}
	}
	/*EmployeeList _Worker;
	WorkTimePtr worker1 = WorkTime::create_full_time("�����", "�������", "���������", 13, 12, 2003, 54000);
	cout << worker1;*/
	return 0;
}