#pragma once
#include <string>
#include <iostream>
using namespace std;
struct Education {
	string item;
	int grade;
};
class Student
{
	string studName;
	string initials;
	int group;
	Education education[3];//Предметы и их кол-во.
public:
	Student();
	Student(Student& obj);
	~Student();
	void setStudName(string str);
	string getStudName();
	void setInitials(string str);
	string getInitials();
	void setGroup(int val);
	int getGroup();
	void setEducation(string strVal1, int intVal1, string strVal2, int intVal2, string strVal3, int intVal3);
	void getEducation(string& strVal1, int& intVal1, string& strVal2, int& intVal2, string& strVal3, int& intVal3);
	friend istream& operator>> (istream& in, Student& object);
	friend ostream& operator<< (ostream& out, Student& object);
};
