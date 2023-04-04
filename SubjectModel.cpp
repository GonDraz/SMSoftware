#include "pch.h"
#include "SubjectModel.h"

void SubjectModel::addSubject(
	int const& idSubject,
	string const& codeSubject,
	string const& nameSubject,
	int const& creditsSubject,
	int const& lessonSubject)
{
	listSubjectModel.push_back(SubjectModel(
		idSubject,
		codeSubject,
		nameSubject,
		creditsSubject,
		lessonSubject));
}

void SubjectModel::editSubject(
	int const& idSubject,
	string const& codeSubject,
	string const& nameSubject,
	int const& creditsSubject,
	int const& lessonSubject)
{
	listSubjectModel[(idSubject - 1)].idSubject = idSubject;
	listSubjectModel[(idSubject - 1)].codeSubject = codeSubject;
	listSubjectModel[(idSubject - 1)].nameSubject = nameSubject;
	listSubjectModel[(idSubject - 1)].creditsSubject = creditsSubject;
	listSubjectModel[(idSubject - 1)].lessonSubject = lessonSubject;

}

void SubjectModel::removeSubject(int const& idSubject)
{

	For(listSubjectModel.size())
	{
		if (listSubjectModel[i].idSubject == idSubject)
		{
			listSubjectModel.erase(listSubjectModel.begin() + i);
		}
	}

}
