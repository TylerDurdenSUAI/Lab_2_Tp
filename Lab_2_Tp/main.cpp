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
				break;
				case '4':
				{
					string strVal1, strVal2, strVal3;
					int intVal1, intVal2, intVal3;
					char buf;
					cout << "Введите номер предмета от 1 до 3: ";
					cin >> buf;
					students[i].getEducation(strVal1, intVal1, strVal2,
						intVal2, strVal3, intVal3);
					if (buf == '1')
					{
						cout << "Введите новый предмет: ";
						cin >> strVal1;
						cout << "Введите новую оценку: ";
						cin >> intVal1;
					}
					else if (buf == '2')
					{
						cout << "Введите новый предмет: ";
						cin >> strVal2;
						cout << "Введите новую оценку: ";
						cin >> intVal2;
					}
					else if (buf == '3')
					{
						cout << "Введите новый предмет: ";
						cin >> strVal3;
						cout << "Введите новую оценку: ";
						cin >> intVal3;
					}
					else
						throw exception("Неверный номер предмета");
					students[i].setEducation(strVal1, intVal1, strVal2,
						intVal2, strVal3, intVal3);
				}
				break;
				default:
					throw exception("Неверный пункт меню");
				}
				SwVal = '3';
			}
			else if (SwVal == '4')
			{
				int i;
				cout << "Введите номер элемента: ";
				cin >> i;
				i--;
				if (i < 0 || i >= id)
					throw exception("Неверный номер");
				for (int j = i; j < id; j++)
					students[j] = students[j + 1];
				id--;
			}
			else if (SwVal == '5')
			{
				scantext();
			}
			else if (SwVal == '6')
			{
				exc();
			}
			else if (SwVal == '7')
			{
				break;
			}
			else
			{
				throw exception("Неверный пункт меню");
			}
		}
		catch (const exception& exp)
		{
			cout << "Исключение: " << exp.what() << endl;
		}
		system("pause");
		system("cls");
	}
	exc();
	delete[]students;
	// Задание 2
	system("pause");
	system("cls");
}
	void scantext()
	{
		try
		{
			string word;
			cout << "Enter your word - ";
			cin >> word;
			ifstream inp("data.txt");
			while (inp.peek() != EOF)
			{
				string per_word;
				for (string line; getline(inp, line);)
				{
					if (line.find(word) == string::npos)
					{
						break;
					}
					else
					{
						cout << line << endl;
					}
				}

			}
		}
		catch (const char* ex) { cout << "Error: " << ex << endl; }
		cout << endl;
	}
	void sort() {
		string strVal1, strVal2, strVal3;
		int intVal1, intVal2, intVal3;
		float sr1, sr2;
		Student bufStudent;
		for (int i = 0; i < id - 1; i++)
		{
			for (int j = 0; j < id - i - 1; j++)
			{
				students[j].getEducation(strVal1, intVal1, strVal2, intVal2, strVal3,
					intVal3);
				sr1 = (float)(intVal1 + intVal2 + intVal3) / 3;
				students[j + 1].getEducation(strVal1, intVal1, strVal2, intVal2,
					strVal3, intVal3);
				sr2 = (float)(intVal1 + intVal2 + intVal3) / 3;
				if (sr1 > sr2)
				{
					bufStudent = students[j];
					students[j] = students[j + 1];
					students[j + 1] = bufStudent;
				}
			}
		}
	}
	void exc() {
		string strVal1, strVal2, strVal3;
		int intVal1, intVal2, intVal3;
		int cnt = 0;
		cout << "Студенты, имеющие оценку 4 и 5: " << endl;
		for (int i = 0; i < id; i++)
		{
			students[i].getEducation(strVal1, intVal1, strVal2, intVal2, strVal3,
				intVal3);
			if ((intVal1 == 4 && intVal2 == 5) || (intVal1 == 5 && intVal2 == 4) || (intVal2 == 4 && intVal3 == 5) || (intVal2 == 5 && intVal3 == 4) || (intVal1 == 4 && intVal3 == 5) || (intVal1 == 5 && intVal3 == 4))
			{
				cout << "\t" << cnt + 1 << ": " << students[i].getStudName() << ", "
					<< students[i].getGroup() << endl;
				cnt++;
			}
		}
		if (cnt == 0)
			cout << "\tТаких студентов нет" << endl;
	}