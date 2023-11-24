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
			}
		}
	}

		