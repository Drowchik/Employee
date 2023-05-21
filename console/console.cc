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
		cout<<"\tМеню\t"<< endl;
		Arrow(1, position); cout<< "Вставить элемент в список по указанному индексу"<<endl;
		Arrow(2, position); cout << "Удалить элемент из списка по указаному индексу" << endl;
		Arrow(3, position); cout << "Вывести список на экран"<<endl;
		Arrow(4, position); cout << "Поиск по максимальной зарплате" << endl;
		Arrow(5, position); cout << "Добавить элемент в конец списка" << endl;
		Arrow(6, position); cout << "Выход" << endl << endl;
		KeyPres = GetKey();
		system("cls");
		if (KeyPres == 72 && position != 1)
			position--;
		else if (KeyPres == 80 && position != 6)
		{
			position++;
		}


	}
	return position;
}

int main() {
	setlocale(LC_ALL, "Russian");
	EmployeeList _Worker;
	while (true)
	{
		int choice1 = Menu();
		switch (choice1)
		{
		case 1:
		{
			cout << "Вы попали в подменю вставки элемента в список по указаному индексу" << endl;
			int index = 0;
			cout << "Введите индекс индекс для вставки элемента" << endl;
			cin >> index;
			cout << "Выберите какого работника вы хотите добавить: FullTime - 1, PartTime - 2" << endl;
			int choice2 = 0;
			cin >> choice2;
			if (choice2 != 1 && choice2 != 2)
			{
				cout << "Вы ввели некоректные данные!";
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
					cout << "Введите имя: " << endl;
					cin >> name;
					cout << "Введите фамилию: " << endl;
					cin >> _surname;
					cout << "Введите отчество: " << endl;
					cin >> _patronymic;
					cout << "Введите дату, когда устроились на работу, в формате: день месяц год " << endl;
					cin >> _day >> _month >> _year;
					cout << "Введите вашу зарплату: ";
					cin >> _salary;
					_Worker.insert_person(make_shared<Full_time>(name, _surname, _patronymic, _day, _month, _year, _salary), index);
					break;
				}
				case 2:
				{
					float _salary_hour;
					int _add_salary;
					int _hours;
					cout << "Введите имя: " << endl;
					cin >> name;
					cout << "Введите фамилию: " << endl;
					cin >> _surname;
					cout << "Введите отчество: " << endl;
					cin >> _patronymic;
					cout << "Введите дату, когда устроились на работу, в формате: день месяц год " << endl;
					cin >> _day >> _month >> _year;
					cout << "Введите почасовую ставку: " << endl;
					cin >> _salary_hour;
					cout << "Введите процент индивидуальной надбавки от 0 до 5% " << endl;
					cin >> _add_salary;
					cout << "Введите кол-во рабочих часов за последний месяц: " << endl;
					cin >> _hours;
					_Worker.insert_person(make_shared<Part_time>(name, _surname, _patronymic, _day, _month, _year, _salary_hour, _add_salary, _hours), index);
					break;

				}
			}	
	
			break;
		}
		case 2: {

			cout << "Вы попали в подменю удаление объекта" << endl;
			if (_Worker.size() == 0)
			{
				cout << "В вашем списке нет работников!" << endl << "Добавьте работников и попробуйте снова!" << endl << endl;
				break;
			}
			cout << "Введите индекс объекта, который хотите удалить" << endl;
			int index = -1;
			cin >> index;
			_Worker.delete_person(index);
			break;
		}
		case 3: {
			int size = _Worker.size();
			if (size == 0)
			{
				cout << "В вашем списке нет работников!" << endl << "Добавьте работников и попробуйте снова!" << endl << endl;
				break;
			}
			for (int i = 0; i < size; i++)
			{
				_Worker[i]->print();
			}
			break;
		}
		case 4: {
			if (_Worker.size() == 0)
			{
				cout << "В вашем списке нет работников!" << endl << "Добавьте работников и попробуйте снова!" << endl << endl;
				break;
			}
			int index = search_max_salary(_Worker);
			cout << "Работник с максимальной заработной платой: " << endl;
			cout << _Worker[index];
			break;
		}
		case 5:
		{
				cout << "Выберите какого работника вы хотите добавить: FullTime - 1, PartTime - 2" << endl;
				int choice2 = 0;
				cin >> choice2;
				if (choice2 != 1 && choice2 != 2)
				{
					cout << "Вы ввели некоректные данные!";
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
						cout << "Введите имя: " << endl;
						cin >> name;
						cout << "Введите фамилию: " << endl;
						cin >> _surname;
						cout << "Введите отчество: " << endl;
						cin >> _patronymic;
						cout << "Введите дату, когда устроились на работу, в формате: день месяц год " << endl;
						cin >> _day >> _month >> _year;
						cout << "Введите вашу зарплату: ";
						cin >> _salary;
						_Worker.add(make_shared <Full_time> (name, _surname, _patronymic, _day, _month, _year, _salary));
						break;
					}
					case 2:
					{
						float _salary_hour;
						int _add_salary;
						int _hours;
						cout << "Введите имя: " << endl;
						cin >> name;
						cout << "Введите фамилию: " << endl;
						cin >> _surname;
						cout << "Введите отчество: " << endl;
						cin >> _patronymic;
						cout << "Введите дату, когда устроились на работу, в формате: день месяц год " << endl;
						cin >> _day >> _month >> _year;
						if (_day > 31 || _month > 12 || _day < 1 || _month < 1)
						{
							cout << "Вы ввели неправильную дату, попробуйте заново" << endl;
						}
						cout << "Введите почасовую ставку: " << endl;
						cin >> _salary_hour;
						cout << "Введите процент индивидуальной надбавки от 0 до 5% " << endl;
						cin >> _add_salary;
						cout << "Введите кол-во рабочих часов за последний месяц: " << endl;
						cin >> _hours;
						_Worker.add(make_shared<Part_time>(name, _surname, _patronymic, _day, _month, _year, _salary_hour, _add_salary, _hours));
						break;

					}
				}
				break;
		}
			case 6: 
			{
				cout << "Работа программы завершена!" << endl;
				return 0;
			}
				
		}
	}
	return 0;
}