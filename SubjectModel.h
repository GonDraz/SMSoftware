#pragma once
#include "pch.h"
#include "SubjectModel.h"

class SubjectModel
{
public:
	int idSubject = 0;
	string codeSubject;
	string nameSubject;
	int creditsSubject;
	int lessonSubject;


public:
	SubjectModel() {}
	SubjectModel(
		int idSubject,
		string codeSubject,
		string nameSubject,
		int creditsSubject,
		int lessonSubject) :
		idSubject(idSubject),
		codeSubject(codeSubject),
		nameSubject(nameSubject),
		creditsSubject(creditsSubject),
		lessonSubject(lessonSubject){}

	void addSubject(
		int const& idSubject,
		string const& codeSubject,
		string const& nameSubject,
		int const& creditsSubject,
		int const& lessonSubject);


	void editSubject(
		int const& idSubject,
		string const& codeSubject,
		string const& nameSubject,
		int const& creditsSubject,
		int const& lessonSubject);

	void removeSubject(int const& idSubject);

	vector<SubjectModel> listSubjectModel;
};

