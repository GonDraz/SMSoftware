#pragma once

#include "pch.h"
#include "SMSoftware.h"
#include "StudentModel.h"
#include "SubjectModel.h"
#include "ScoreModel.h"


class Store : public StudentModel, public SubjectModel, public ScoreModel
{

private:
	const string nameFile[3] = { "StudentData.txt", "SubjecData.txt" ,"ScoreData.txt" };

	fstream file;

public:


	bool checkNullEdit(CString const&  textCheck);

	void openFile(int const& input, ios_base::openmode mode);

	void closeFile();

	void saveFileStudent();

	void saveFileSubject();

	void saveFileScore();

	string loadTime();

	void loadDataStudent();

	void loadDataSubject();

	void loadDataScore();

	void errorMsg(CString const& str);

	CString getIntToCS(int const& getIntNumber);

	CString getStringToCS(string const& getString);

	string getCsToString(CString const& getCString);


	int getStringToInt(string const& getString);

};

