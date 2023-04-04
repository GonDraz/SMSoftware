#pragma once
#include "pch.h"


class StudentModel
{
public:
	int idStudent = 0;
	string codeStudent;
	string nameStudent;
	string classStudent;
	string birthdayStudent;
	string sexStudent;
	string phoneNumberStudent;
	string mailStudent;

public:
	StudentModel() {}
	StudentModel(
		int idStudent,
		string codeStudent,
		string nameStudent,
		string classStudent,
		string birthdayStudent,
		string sexStudent,
		string phoneNumberStudent,
		string mailStudent) :
		idStudent(idStudent),
		codeStudent(codeStudent),
		nameStudent(nameStudent),
		classStudent(classStudent),
		birthdayStudent(birthdayStudent),
		sexStudent(sexStudent),
		phoneNumberStudent(phoneNumberStudent),
		mailStudent(mailStudent) {}

	void addStudent(
		int const& intIDStudent,
		string const& strCodeStudent,
		string const& strNameStudent,
		string const& strClassStudent,
		string const& strBirthdayStudent,
		string const& strSexStudent,
		string const& strPhoneNumberStudent,
		string const& strMailStudent);

	void editStudent(
		int const& intIDStudent,
		string const& strCodeStudent,
		string const& strNameStudent,
		string const& strClassStudent,
		string const& strBirthdayStudent,
		string const& strSexStudent,
		string const& strPhoneNumberStudent,
		string const& strMailStudent);

	void removeStudent(int const& idStudent);

	vector<StudentModel> listStudentModel;

};

