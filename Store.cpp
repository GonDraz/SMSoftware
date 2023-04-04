#include "pch.h"
#include "Store.h"



bool Store::checkNullEdit(CString const& textCheck) {
	if (textCheck == "")
	{
		return true;
	}
	return false;
}

void Store::openFile(int const& input, ios_base::openmode mode) {

	back:
	file.open(nameFile[input], mode);

	if (file.fail()) {
		fopen(nameFile[input].c_str(), "w");
		goto back;
	}
}

void Store::closeFile()
{
	file.close();
}

void Store::saveFileStudent() {
	openFile(0, ios::out);

	For(listStudentModel.size())
	{
		file << i + 1 << ";"
			<< listStudentModel[i].codeStudent << ";"
			<< listStudentModel[i].nameStudent << ";"
			<< listStudentModel[i].classStudent << ";"
			<< listStudentModel[i].birthdayStudent << ";"
			<< listStudentModel[i].sexStudent << ";"
			<< listStudentModel[i].phoneNumberStudent << ";"
			<< listStudentModel[i].mailStudent << ";"
			<< endl;
	}
	closeFile();
}

void Store::saveFileSubject() {
	openFile(1, ios::out);

	For(listSubjectModel.size())
	{
		file << i + 1 << ";"
			<< listSubjectModel[i].codeSubject << ";"
			<< listSubjectModel[i].nameSubject << ";"
			<< listSubjectModel[i].creditsSubject << ";"
			<< listSubjectModel[i].lessonSubject << ";"
			<< endl;
	}
	closeFile();
}

void Store::saveFileScore()
{
	openFile(2, ios::out);

	For(listScoreModel.size())
	{
		file << i + 1 << ";"
			//<< listStudentModel[i].codeStudent << ";"
			//<< listStudentModel[i].nameStudent << ";"
			//<< listStudentModel[i].classStudent << ";"
			//<< listStudentModel[i].birthdayStudent << ";"
			//<< listStudentModel[i].sexStudent << ";"
			//<< listStudentModel[i].phoneNumberStudent << ";"
			//<< listStudentModel[i].mailStudent << ";"
			<< endl;
	}
	closeFile();
}

string Store::loadTime()
{
	time_t realTime = time(0);
	tm* ltm = localtime(&realTime);
	string strTime;

	if (ltm->tm_mday < 10) {
		strTime = "0" + to_string(ltm->tm_mday);
	}
	else
	{
		strTime = to_string(ltm->tm_mday);
	}
	if (1 + ltm->tm_mon < 10) {
		strTime += "/0" + to_string(1 + ltm->tm_mon);
	}
	else
	{
		strTime += "/" + to_string(1 + ltm->tm_mon);
	}

	strTime += "/" + to_string(1900 + ltm->tm_year);

	return strTime;
}

void Store::loadDataStudent()
{
	openFile(0, ios::in);

	string line;
	int numerical = 0;

	int idStudent = 0;

	string codeStudent,
		nameStudent,
		classStudent,
		birthdayStudent,
		sexStudent,
		phoneNumberStudent,
		mailStudent;

	while (!file.eof())
	{
		numerical = 0;

		codeStudent = "";
		nameStudent = "";
		classStudent = "";
		birthdayStudent = "";
		sexStudent = "";
		phoneNumberStudent = "";
		mailStudent = "";

		getline(file, line);

		for (int i = 0; i <= line.size(); i++) {
			if (line[i] == 'ï' || line[i] == '»' || line[i] == '¿')
			{
			}
			else if (line[i] == ';') {

				numerical += 1;
			}
			else {
				switch (numerical)
				{
				case 1:
				{
					codeStudent += line[i];

					break;
				}
				case 2:
				{
					nameStudent += line[i];

					break;
				}
				case 3:
				{
					classStudent += line[i];
					break;
				}
				case 4:
				{
					birthdayStudent += line[i];
					break;
				}
				case 5:
				{
					sexStudent += line[i];
					break;
				}
				case 6:
				{
					phoneNumberStudent += line[i];
					break;

				}
				case 7:
				{
					mailStudent += line[i];
					break;
				}
				case 8:
				{
					idStudent += 1;
					addStudent(
						idStudent,
						codeStudent,
						nameStudent,
						classStudent,
						birthdayStudent,
						sexStudent,
						phoneNumberStudent,
						mailStudent);
					break;
				}
				default:
					break;
				}
			}
		}
	}
	closeFile();
}


//undone
void Store::loadDataSubject()
{
	openFile(1, ios::in);

	string line;
	int numerical = 0;

	int idSubject = 0;

	string codeSubject,
		nameSubject,
		creditsSubject,
		lessonSubject;

	while (!file.eof())
	{
		numerical = 0;

		codeSubject = "";
		nameSubject = "";
		creditsSubject = "";
		lessonSubject = "";

		getline(file, line);

		for (int i = 0; i <= line.size(); i++) {
			if (line[i] == 'ï' || line[i] == '»' || line[i] == '¿')
			{
			}
			else if (line[i] == ';') {

				numerical += 1;
			}

			else {
				switch (numerical)
				{
				case 1:
				{
					codeSubject += line[i];
					break;
				}
				case 2:
				{
					nameSubject += line[i];
					break;
				}
				case 3:
				{
					creditsSubject += line[i];
					break;
				}
				case 4:
				{
					lessonSubject += line[i];
					break;
				}
				case 5:
				{
					idSubject += 1;
					addSubject(
						idSubject,
						codeSubject,
						nameSubject, 
						getStringToInt(creditsSubject),
						getStringToInt(lessonSubject));
					break;
				}
				default:
					break;
				}
			}
		}
	}
	closeFile();
}

void Store::loadDataScore()
{

	string line;
	int numerical = 0;

	int idSubject = 0;

	string codeSubject,
		nameSubject,
		creditsSubject,
		lessonSubject;

	while (!file.eof())
	{
		numerical = 0;

		codeSubject = "";
		nameSubject = "";
		creditsSubject = "";
		lessonSubject = "";

		getline(file, line);

		for (int i = 0; i <= line.size(); i++) {
			if (line[i] == 'ï' || line[i] == '»' || line[i] == '¿')
			{
			}
			else if (line[i] == ';') {

				numerical += 1;
			}

			else {
				switch (numerical)
				{
				case 1:
				{
					codeSubject += line[i];
					break;
				}
				case 2:
				{
					nameSubject += line[i];
					break;
				}
				case 3:
				{
					creditsSubject += line[i];
					break;
				}
				case 4:
				{
					lessonSubject += line[i];
					break;
				}
				case 5:
				{ 
					//idSubject += 1;
					//addSubject(
					//	idSubject,
					//	codeSubject,
					//	nameSubject,
					//	getStringToInt(creditsSubject),
					//	getStringToInt(lessonSubject));
					break;
				}
				default:
					break;
				}
			}
		}
	}
	closeFile();
}

void Store::errorMsg(CString const& str) {
	MessageBox(NULL, str, _T("ERROR"), MB_OK);
}

CString Store::getIntToCS(int const& getIntNumber)
{
	return (CString)(to_wstring(getIntNumber).c_str());
}

CString Store::getStringToCS(string const& getString)
{
	CStringW wideStr(getString.c_str());
	return wideStr;
}

string Store::getCsToString(CString const& getCString)
{
	string STDStr(CW2A(getCString.GetString()));
	return STDStr;
}


int Store::getStringToInt(string const& getString)
{
	stringstream geek(getString);
	int x = 0;
	geek >> x;
	return x;
}