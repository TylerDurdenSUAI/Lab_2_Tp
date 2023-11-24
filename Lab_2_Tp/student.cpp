#include "Student.h"

Student::Student()
{
	cout << "Конструктор без параметров" << endl;
}

Student::Student(Student& obj)
{
	cout << "Конструктор копирования" << endl;
	string strVal1, strVal2, strVal3;
	int intVal1, intVal2, intVal3;
	setStudName(obj.getStudName());
	setInitials(obj.getInitials());
	setGroup(obj.getGroup());
	obj.getEducation(strVal1, intVal1, strVal2, intVal2, strVal2, intVal3);
	setEducation(strVal1, intVal1, strVal2, intVal2, strVal2, intVal3);
}

Student::~Student()
{
	cout << "Деструктор" << endl;
}

void Student::setStudName(string buf)
{
	if (buf == "")
		throw exception("Неверная фамилия");
	studName = buf;
}

string Student::getStudName()
{
	return studName;
}
void Student::setInitials(string buf)
{
	if (buf == "" || buf.size() != 4 || buf.find('.') == -1)
		throw exception("Неверные инициалы");
	initials = buf;
}

string Student::getInitials() { return initials; }
void Student::setGroup(int buf)
{
	if (buf < 1000 && buf > 0)
		throw exception("Неверный номер группы");
	group = buf;
}

int Student::getGroup() {
	return group;
}

void Student::setEducation(string strVal1, int intVal1, string strVal2, int intVal2, string strVal3, int intVal3) {
	if (strVal1 == "" || strVal2 == "" || strVal3 == "")
		throw exception("Неверный предмет");
	if (intVal1 < 2 || intVal1 > 5 || intVal2 < 2 || intVal2 > 5 || intVal3 < 2 || intVal3 > 5)
		throw exception("Неверная оценка для успеваемости");
	education[0].item = strVal1;
	education[0].grade = intVal1;
	education[1].item = strVal2;
	education[1].grade = intVal2;
	education[2].item = strVal3;
	education[2].grade = intVal3;
}

void Student::getEducation(string& strVal1, int& intVal1, string& strVal2, int& intVal2, string& strVal3, int& intVal3)
{
	strVal1 = education[0].item;
	intVal1 = education[0].grade;
	strVal2 = education[1].item;
	intVal2 = education[1].grade;
	strVal3 = education[2].item;
	intVal3 = education[2].grade;
}

istream& operator>> (istream& in, Student& object) {
	string strVal1, strVal2, strVal3;
	int intVal1, intVal2, intVal3;
	cout << "Введите фамилию: ";
	in >> strVal1;
	object.setStudName(strVal1);
	cout << "Введите инициалы (И.О.): ";
	in >> strVal1;
	object.setInitials(strVal1);
	cout << "Введите номер группы: ";
	in >> intVal1;
	object.setGroup(intVal1);
	cout << "Введите\n\tПредмет 1: ";
	in >> strVal1;
	cout << "\tУспеваемость 1: ";
	in >> intVal1;
	cout << "\tПредмет 2: ";
	in >> strVal2;
	cout << "\tУспеваемость 2: ";
	in >> intVal2;
	cout << "\tПредмет 3: ";
	in >> strVal3;
	cout << "\tУспеваемость 3: ";
	in >> intVal3;
	object.setEducation(strVal1, intVal1, strVal2, intVal2, strVal3, intVal3);
	cout << "Студент внесен в список" << endl;
	return in;
}

ostream& operator<< (ostream& out, Student& object) {
	string strVal1, strVal2, strVal3;
	int intVal1, intVal2, intVal3;
	out << "Студент: " << object.getStudName() << " " << object.getInitials() << endl;
	out << "Группа: " << object.getGroup() << endl;
	object.getEducation(strVal1, intVal1, strVal2, intVal2, strVal3, intVal3);
	out << "Предметы: " << "\n\t1 - " << strVal1 << "\t" << intVal1 <<
		"\n\t2 - " << strVal2 << "\t" << intVal2 <<
		"\n\t3 - " << strVal3 << "\t" << intVal3 << endl;
	return out;
}