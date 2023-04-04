#pragma once
#include "pch.h"
#include "SubjectModel.h"

class ScoreModel
{
public:
	int idSubject = 0;
	string codeSubject;
	string nameSubject;
	int creditsSubject;
	int lessonSubject;


public:
	ScoreModel() {}
	ScoreModel(
		int idSubject,
		string codeSubject,
		string nameSubject,
		int creditsSubject,
		int lessonSubject) :
		idSubject(idSubject),
		codeSubject(codeSubject),
		nameSubject(nameSubject),
		creditsSubject(creditsSubject),
		lessonSubject(lessonSubject) {}


	vector<ScoreModel> listScoreModel;
};

