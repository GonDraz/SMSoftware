// ScoreManageDlg.cpp : implementation file
//

#include "pch.h"
#include "ScoreManageDlg.h"


// ScoreManageDlg dialog

IMPLEMENT_DYNAMIC(ScoreManageDlg, CDialogEx)

ScoreManageDlg::ScoreManageDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Dlg_ScoreManage, pParent)
{
	            
}

ScoreManageDlg::~ScoreManageDlg()
{
}

void ScoreManageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_SeachScore, edtSearch);
	DDX_Control(pDX, IDC_COMBO_SearchScore, cbSearch);
	DDX_Control(pDX, IDC_LIST_Score, listScoreController);
	DDX_Control(pDX, IDC_COMBO_Subject, cbSubject);
	DDX_Control(pDX, IDC_EDIT_Score, edtScore);
	DDX_Control(pDX, IDC_SPIN_Score, spinScore);
}


BEGIN_MESSAGE_MAP(ScoreManageDlg, CDialogEx)
	ON_BN_CLICKED(IDC_Btn_EditScore, &ScoreManageDlg::OnBnClickedBtnEditscore)
	ON_BN_CLICKED(IDC_Btn_SeachScore, &ScoreManageDlg::OnBnClickedBtnSeachscore)
END_MESSAGE_MAP()


BOOL ScoreManageDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	//set up combo box tim kiem
	cbSearch.AddString(_T("tên môn"));
	cbSearch.AddString(_T("điểm"));
	cbSearch.SetCurSel(0);

	//set up phần list Subject 
	listScoreController.SetExtendedStyle(listScoreController.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	listScoreController.InsertColumn(0, _T("stt"), LVCFMT_LEFT, 50);
	listScoreController.InsertColumn(1, _T("tên sinh viên"), LVCFMT_LEFT, 70);
	listScoreController.InsertColumn(2, _T("tên môn"), LVCFMT_LEFT, 150);
	listScoreController.InsertColumn(3, _T("số tín"), LVCFMT_LEFT, 60);
	listScoreController.InsertColumn(4, _T("số tiết"), LVCFMT_LEFT, 60);


	spinScore.SetRange(lowScore, highScore);
	spinScore.SetPos(lowScore);



	//load màn hình 

	loadDataSubject();
	loadDataStudent();
	For(listScoreModel.size()) addScoreToListControler(i);
	return TRUE;  // return TRUE unless you set the focus to a control
}

void ScoreManageDlg::OnBnClickedBtnEditscore()
{
}


void ScoreManageDlg::OnBnClickedBtnSeachscore()
{
	// TODO: Add your control notification handler code here
}


void ScoreManageDlg::addScoreToListControler(int const& i)
{
	//listStudentController.InsertItem(0, getIntToCS(listStudentModel[i].idStudent));
	//listStudentController.SetItemText(0, 1, getStringToCS(listStudentModel[i].codeStudent));
	//listStudentController.SetItemText(0, 2, getStringToCS(listStudentModel[i].nameStudent));
	//listStudentController.SetItemText(0, 3, getStringToCS(listStudentModel[i].classStudent));
	//listStudentController.SetItemText(0, 4, getStringToCS(listStudentModel[i].birthdayStudent));
	//listStudentController.SetItemText(0, 5, getStringToCS(listStudentModel[i].sexStudent));
	//listStudentController.SetItemText(0, 6, getStringToCS(listStudentModel[i].phoneNumberStudent));
	//listStudentController.SetItemText(0, 7, getStringToCS(listStudentModel[i].mailStudent));
}



void ScoreManageDlg::clearSroceListController()
{
	//xóa list controller
back:
	for (int j = 0; j < listScoreController.GetItemCount(); j++)
	{
		listScoreController.DeleteItem(j);
	}
	if (listScoreController.GetItemCount() != 0) {
		goto back;
	}
}

void ScoreManageDlg::searchStudent(CString const& strSearch, CString const& strCbSearch, bool const& inputState)
{
	// bien luu giu do dai cua chuoi can tim kiem
	int len = getCsToString(strSearch).size();

	if (checkNullEdit(strSearch)) {
		if (inputState)
		{
			clearSroceListController();

			For(listStudentModel.size()) addScoreToListControler(i);
		}
	}
	else if (len >= 30) {
		MessageBox(L"tìm kiếm quá dài");
	}
	else {
		char charSearch[30];
		strcpy(charSearch, CStringA(strSearch).GetString());

		clearSroceListController();
		char str[30];

		int n = 0;
		int m = 0;

		For(listScoreModel.size()) {
			n = 0;
			m = 0;

			//if (strCbSearch == L"họ và tên")
			//	strcpy(str, (listStudentModel[i].nameStudent).c_str());
			//else if (strCbSearch == L"mã")
			//	strcpy(str, (listStudentModel[i].codeStudent).c_str());
			//else if (strCbSearch == L"lớp")
			//	strcpy(str, (listStudentModel[i].classStudent).c_str());
			//else if (strCbSearch == L"mail")
			//	strcpy(str, (listStudentModel[i].mailStudent).c_str());
			//else if (strCbSearch == L"số điện thoại")
			//	strcpy(str, (listStudentModel[i].phoneNumberStudent).c_str());
			//else {
			//	cbSearch.SetCurSel(0);
			//	strcpy(str, (listStudentModel[i].nameStudent).c_str());
			//}

			while (str[n] != '\0') {

				if (str[n] == charSearch[m]) {    // neu ky tu dau tien la giong nhau

					// tiep tuc tim kiem
					while (str[n] == charSearch[m] && str[n] != '\0') {
						n++;
						m++;
					}

					// Neu day ky tu nay co do dai bang chuoi tim kiem
					if (m == len && (str[n] == ' ' || str[n] == '\0')) {

						addScoreToListControler(i);
					}
				}
				else {   // Neu ky tu dau tien khong giong nhau
					while (str[n] != ' ') {    //bo qua, tiep tuc tim kiem tu tiep theo
						n++;
						if (str[n] == '\0')
							break;
					}
				}
				n++;
				m = 0;  // reset bien dem
			}
		}
	}

}
