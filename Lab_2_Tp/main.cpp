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
	// ������� 1
	char SwVal = '0';
	do {
		cout << "������� ���������� ���������: " << endl;
		cin >> n;
	} while (n <= 0);
	students = new Student[n];
	while (SwVal != '7')
	{
		try
		{
			cout << "1 - ������ ������� \n2 - ����� ���� ��������� \n3 - ������������� ������� \n4 - ������� ������� \n5 - ������� 2 \n6 - ����� ��������� � 4 � 5 \n7 - �����\n����� ���� : ";
			cin >> SwVal;
			if (SwVal == '1')
			{
				if (id == n)
					throw exception("������ ��� ��������");
				cin >> students[id];
				id++;
				sort();
			}
			else if (SwVal == '2')
			{
				if (id == 0)
					throw exception("������ ����");
				for (int i = 0; i < id; i++)
					cout << i + 1 << ": " << students[i];
			}
			else if (SwVal == '3')
			{
				int i;
				cout << "������� ����� ��������: ";
				cin >> i;
				i--;
				if (i < 0 || i >= id)
					throw exception("�������� �����");
				cout << "������������� ����: \n\t1 - ������� \n\t2 - ��������\n\t3 - ������ \n\t4 - ������� � ������\n\t����� ���� : ";
				cin >> SwVal;
				switch (SwVal)
				{
				case '1':
				{
					string str;
					cout << "����� �������: ";
					cin >> str;
					students[i].setStudName(str);
				}
				break;
				case '2':
				{
					string str;
					cout << "����� ��������: ";
					cin >> str;
					students[i].setInitials(str);
				}
				break;
				case '3':
				{
					int c;
					cout << "����� ������: ";
					cin >> c;
					students[i].setGroup(c);
				}
				break;
				case '4':
				{
					string strVal1, strVal2, strVal3;
					int intVal1, intVal2, intVal3;
					char buf;
					cout << "������� ����� �������� �� 1 �� 3: ";
					cin >> buf;
					students[i].getEducation(strVal1, intVal1, strVal2,
						intVal2, strVal3, intVal3);
					if (buf == '1')
					{
						cout << "������� ����� �������: ";
						cin >> strVal1;
						cout << "������� ����� ������: ";
						cin >> intVal1;
					}
					else if (buf == '2')
					{
						cout << "������� ����� �������: ";
						cin >> strVal2;
						cout << "������� ����� ������: ";
						cin >> intVal2;
					}
					else if (buf == '3')
					{
						cout << "������� ����� �������: ";
						cin >> strVal3;
						cout << "������� ����� ������: ";
						cin >> intVal3;
					}
					else
						throw exception("�������� ����� ��������");
					students[i].setEducation(strVal1, intVal1, strVal2,
						intVal2, strVal3, intVal3);
				}
				break;
				default:
					throw exception("�������� ����� ����");
				}
				SwVal = '3';
			}
			else if (SwVal == '4')
			{
				int i;
				cout << "������� ����� ��������: ";
				cin >> i;
				i--;
				if (i < 0 || i >= id)
					throw exception("�������� �����");
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
				throw exception("�������� ����� ����");
			}
		}
		catch (const exception& exp)
		{
			cout << "����������: " << exp.what() << endl;
		}
		system("pause");
		system("cls");
	}
	exc();
	delete[]students;
	// ������� 2
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
		cout << "��������, ������� ������ 4 � 5: " << endl;
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
			cout << "\t����� ��������� ���" << endl;
	}