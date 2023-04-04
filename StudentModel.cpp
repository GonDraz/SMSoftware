#include "pch.h"
#include "StudentModel.h"


void StudentModel::addStudent(
	int const& idStudent,
	string const& codeStudent,
	string const& nameStudent,
	string const& classStudent,
	string const& birthdayStudent,
	string const& sexStudent,
	string const& phoneNumberStudent,
	string const& mailStudent)
{
	listStudentModel.push_back(StudentModel(
		idStudent,
		codeStudent,
		nameStudent,
		classStudent,
		birthdayStudent,
		sexStudent,
		phoneNumberStudent,
		mailStudent));
}

void StudentModel::editStudent(
int const& idStudent,
string const& codeStudent,
string const& nameStudent,
string const& classStudent,
string const& birthdayStudent,
string const& sexStudent,
string const& phoneNumberStudent,
string const& mailStudent)
{
	listStudentModel[(idStudent - 1)].idStudent = idStudent;
	listStudentModel[(idStudent - 1)].codeStudent = codeStudent;
	listStudentModel[(idStudent - 1)].nameStudent = nameStudent;
	listStudentModel[(idStudent - 1)].classStudent = classStudent;
	listStudentModel[(idStudent - 1)].birthdayStudent = birthdayStudent;
	listStudentModel[(idStudent - 1)].sexStudent = sexStudent;
	listStudentModel[(idStudent - 1)].phoneNumberStudent = phoneNumberStudent;
	listStudentModel[(idStudent - 1)].mailStudent = mailStudent;
}

void StudentModel::removeStudent(int const& idStudent )
{
	For(listStudentModel.size())
	{
		if (listStudentModel[i].idStudent == idStudent)
		{
			listStudentModel.erase(listStudentModel.begin() + i);
		}
	}
}