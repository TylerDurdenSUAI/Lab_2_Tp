#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include "Student.h"
using namespace std;
Student* students;
int n, id = 0;
void sort();
void exc();
void scantext();
int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	// Задание 1
	char SwVal = '0';
	do {
		cout << "Введите количество студентов: " << endl;
		cin >> n;
	} while (n <= 0);
	students = new Student[n];
	while (SwVal != '7')
	{
		try
		{
			cout << "1 - Ввести элемент \n2 - Вывод всех элементов \n3 - Редактировать элемент \n4 - Удалить элемент \n5 - Задание 2 \n6 - Вывод студентов с 4 и 5 \n7 - Выход\nПункт меню : ";
			cin >> SwVal;
			if (SwVal == '1')
			{
				if (id == n)
					throw exception("Массив уже заполнен");
				cin >> students[id];
				id++;
				sort();
			}
			else if (SwVal == '2')
			{
				if (id == 0)
					throw exception("Массив пуст");
				for (int i = 0; i < id; i++)
					cout << i + 1 << ": " << students[i];
			}
			else if (SwVal == '3')
			{
				int i;
				cout << "Введите номер элемента: ";
				cin >> i;
				i--;
				if (i < 0 || i >= id)
					throw exception("Неверный номер");
				cout << "Редактируемое поле: \n\t1 - Фамилия \n\t2 - Инициалы\n\t3 - Группа \n\t4 - Предмет и оценку\n\tПункт меню : ";
				cin >> SwVal;
				switch (SwVal)
				{
				case '1':
				{
					string str;
					cout << "Новая фамилия: ";
					cin >> str;
					students[i].setStudName(str);
				}
				break;
				case '2':
				{
					string str;
					cout << "Новые инициалы: ";
					cin >> str;
					students[i].setInitials(str);
				}
				break;
				case '3':
				{
					int c;
					cout << "Новая группа: ";
					cin >> c;
					students[i].setGroup(c);
				}
			}
		}
	}

		