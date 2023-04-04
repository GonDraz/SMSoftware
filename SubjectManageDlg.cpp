// SubjectManageDlg.cpp : implementation file
//

#include "pch.h"
#include "SubjectManageDlg.h"


// SubjectManageDlg dialog

IMPLEMENT_DYNAMIC(SubjectManageDlg, CDialogEx)

SubjectManageDlg::SubjectManageDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Dlg_SubjectManage, pParent)
{

}

SubjectManageDlg::~SubjectManageDlg()
{
}

void SubjectManageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_Subject, listSubjectController);
	DDX_Control(pDX, IDC_EDIT_SeachSubject, edtSearch);
	DDX_Control(pDX, IDC_COMBO_SearchSubject, cbSearch);
	DDX_Control(pDX, IDC_EDIT_NameSubject, edtNameSubject);
	DDX_Control(pDX, IDC_EDIT_CodeSubject, edtCodeSubject);
	DDX_Control(pDX, IDC_SPIN_CreditsSubject, spinCreditsSubject);
	DDX_Control(pDX, IDC_EDIT_CreditsSubject, edtCreditsSubject);
	DDX_Control(pDX, IDC_EDIT_LessonSubject, edtLessonSubject);
	DDX_Control(pDX, IDC_SPIN_LessonSubject, spinLessonSubject);
}


BEGIN_MESSAGE_MAP(SubjectManageDlg, CDialogEx)
	ON_BN_CLICKED(IDC_Btn_AddSubject, &SubjectManageDlg::OnBnClickedBtnAddsubject)
	ON_BN_CLICKED(IDC_Btn_EditSubject, &SubjectManageDlg::OnBnClickedBtnEditsubject)
	ON_BN_CLICKED(IDC_Btn_SeachSubject, &SubjectManageDlg::OnBnClickedBtnSeachsubject)
	ON_BN_CLICKED(IDC_Btn_RemoveSubject, &SubjectManageDlg::OnBnClickedBtnRemovesubject)
END_MESSAGE_MAP()


// SubjectManageDlg message handlers

void SubjectManageDlg::clearSubjectListController()
{
	//xóa list controller
back:
	for (int j = 0; j < listSubjectController.GetItemCount(); j++)
	{
		listSubjectController.DeleteItem(j);
	}
	if (listSubjectController.GetItemCount() != 0) {
		goto back;
	}
}

void SubjectManageDlg::addSubjectToList(int const& i)
{
	listSubjectController.InsertItem(0, getIntToCS(listSubjectModel[i].idSubject));
	listSubjectController.SetItemText(0, 1, getStringToCS(listSubjectModel[i].codeSubject));
	listSubjectController.SetItemText(0, 2, getStringToCS(listSubjectModel[i].nameSubject));
	listSubjectController.SetItemText(0, 3, getIntToCS(listSubjectModel[i].creditsSubject));
	listSubjectController.SetItemText(0, 4, getIntToCS(listSubjectModel[i].lessonSubject));
}

BOOL SubjectManageDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	//set up combo box tim kiem
	cbSearch.AddString(_T("tên môn"));
	cbSearch.AddString(_T("mã môn"));
	cbSearch.AddString(_T("số tín"));
	cbSearch.AddString(_T("số tiết"));
	cbSearch.SetCurSel(0);

	//set up phần list Subject 
	listSubjectController.SetExtendedStyle(listSubjectController.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	listSubjectController.InsertColumn(0, _T("stt"), LVCFMT_LEFT, 50);
	listSubjectController.InsertColumn(1, _T("mã môn"), LVCFMT_LEFT, 70);
	listSubjectController.InsertColumn(2, _T("tên môn"), LVCFMT_LEFT, 150);
	listSubjectController.InsertColumn(3, _T("số tín"), LVCFMT_LEFT, 60);
	listSubjectController.InsertColumn(4, _T("số tiết"), LVCFMT_LEFT, 60);


	spinCreditsSubject.SetRange(lowSpinCreditsSubject, highSpinCreditsSubject);
	spinCreditsSubject.SetPos(lowSpinCreditsSubject);

	spinLessonSubject.SetRange(lowSpinLessonSubject, highSpinLessonSubject);
	spinLessonSubject.SetPos(lowSpinLessonSubject);

	//load màn hình 

	loadDataSubject();
	For(listSubjectModel.size()) addSubjectToList(i);
	return TRUE;  // return TRUE unless you set the focus to a control
}



void SubjectManageDlg::OnBnClickedBtnAddsubject()
{

	UpdateData(TRUE);


	int intIDSubject = listSubjectModel.size();

	// lấy dữ diệu 
	CString strCodeSubject;
	edtCodeSubject.GetWindowText(strCodeSubject);

	CString strNameSubject;
	edtNameSubject.GetWindowText(strNameSubject);

	CString strCreditsSubject;
	edtCreditsSubject.GetWindowText(strCreditsSubject);
	int intCreditsSubject = getStringToInt(getCsToString(strCreditsSubject));

	CString strLessonSubject;
	edtLessonSubject.GetWindowText(strLessonSubject);
	int intLessonSubject = getStringToInt(getCsToString(strLessonSubject));

	//kiểm tra dữ liệu mã, tên, lớp 
	if (checkNullEdit(strCodeSubject) || checkNullEdit(strNameSubject))
	{
		MessageBox(L"vui lòng điền đầy đủ thông tin ");
	}
	else if ((intCreditsSubject < lowSpinCreditsSubject || intCreditsSubject >= highSpinCreditsSubject) ||
		(intLessonSubject < lowSpinLessonSubject || intLessonSubject >= highSpinLessonSubject)) {
		MessageBox(L"thông tin bị sai");
		edtCreditsSubject.SetWindowText(getIntToCS(lowSpinCreditsSubject));
		edtLessonSubject.SetWindowText(getIntToCS(lowSpinLessonSubject));
	}
	else {

		//tạo số thứ tự sinh viên 
		intIDSubject++;

		//thêm vào model 
		addSubject(
			intIDSubject,
			getCsToString(strCodeSubject),
			getCsToString(strNameSubject),
			intCreditsSubject,
			intLessonSubject);

		//lưu file 
		saveFileSubject();

		// thêm sinh viên vào list 
		listSubjectController.InsertItem(0, getIntToCS(intIDSubject));
		listSubjectController.SetItemText(0, 1, strCodeSubject);
		listSubjectController.SetItemText(0, 2, strNameSubject);
		listSubjectController.SetItemText(0, 3, strCreditsSubject);
		listSubjectController.SetItemText(0, 4, strLessonSubject);

		//xóa editer trên màn hình 
		edtCodeSubject.SetWindowText(_T(""));
		edtNameSubject.SetWindowText(_T(""));
		edtCreditsSubject.SetWindowText(getIntToCS(lowSpinCreditsSubject));
		edtLessonSubject.SetWindowText(getIntToCS(lowSpinLessonSubject));

	}


	// lấy dữ diệu 
	CString strSearch;
	edtSearch.GetWindowText(strSearch);

	CString strCbSearch;
	cbSearch.GetWindowText(strCbSearch);

	searchSubject(strSearch, strCbSearch, false);


	UpdateData(FALSE);
}

void SubjectManageDlg::addSubjectToListControler(int const& i)
{
	listSubjectController.InsertItem(0, getIntToCS(listSubjectModel[i].idSubject));
	listSubjectController.SetItemText(0, 1, getStringToCS(listSubjectModel[i].codeSubject));
	listSubjectController.SetItemText(0, 2, getStringToCS(listSubjectModel[i].nameSubject));
	listSubjectController.SetItemText(0, 3, getIntToCS(listSubjectModel[i].creditsSubject));
	listSubjectController.SetItemText(0, 4, getIntToCS(listSubjectModel[i].lessonSubject));

}

void SubjectManageDlg::searchSubject(CString const& strSearch, CString const& strCbSearch, bool const& inputState) {

	// bien luu giu do dai cua chuoi can tim kiem
	int len = getCsToString(strSearch).size();

	if (checkNullEdit(strSearch)) {
		if (inputState)
		{
			clearSubjectListController();

			For(listSubjectModel.size()) addSubjectToListControler(i);
		}
	}
	else if (len >= 30) {
		MessageBox(L"tìm kiếm quá dài");
	}
	else {
		char charSearch[30];
		strcpy(charSearch, CStringA(strSearch).GetString());

		clearSubjectListController();
		char str[30];

		int n = 0;
		int m = 0;

		For(listSubjectModel.size()) {
			n = 0;
			m = 0;

			if (strCbSearch == L"tên môn")
				strcpy(str, (listSubjectModel[i].nameSubject).c_str());
			else if (strCbSearch == L"mã môn")
				strcpy(str, (listSubjectModel[i].codeSubject).c_str());
			else if (strCbSearch == L"số tín")
				strcpy(str, (getCsToString(getIntToCS(listSubjectModel[i].creditsSubject)).c_str()));
			else if (strCbSearch == L"số tiết")
				strcpy(str, (getCsToString(getIntToCS(listSubjectModel[i].lessonSubject)).c_str()));
			else {
				cbSearch.SetCurSel(0);
				strcpy(str, (listSubjectModel[i].nameSubject).c_str());
			}
			while (str[n] != '\0') {

				if (str[n] == charSearch[m]) {    // neu ky tu dau tien la giong nhau

					// tiep tuc tim kiem
					while (str[n] == charSearch[m] && str[n] != '\0') {
						n++;
						m++;
					}

					// Neu day ky tu nay co do dai bang chuoi tim kiem
					if (m == len && (str[n] == ' ' || str[n] == '\0')) {

						addSubjectToListControler(i);
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

void SubjectManageDlg::OnBnClickedBtnEditsubject()
{
	UpdateData(TRUE);

	int intIDSubject = -1;

	// lấy dữ diệu 
	CString strCodeSubject;
	edtCodeSubject.GetWindowText(strCodeSubject);

	CString strNameSubject;
	edtNameSubject.GetWindowText(strNameSubject);

	CString strCreditsSubject;
	edtCreditsSubject.GetWindowText(strCreditsSubject);
	int intCreditsSubject = getStringToInt(getCsToString(strCreditsSubject));

	CString strLessonSubject;
	edtLessonSubject.GetWindowText(strLessonSubject);
	int intLessonSubject = getStringToInt(getCsToString(strLessonSubject));

	For(listSubjectController.GetItemCount())
	{
		if (listSubjectController.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED)
		{
			intIDSubject = getStringToInt(getCsToString(listSubjectController.GetItemText(i, 0)));

			//check null
			if (checkNullEdit(strCodeSubject)) {
				strCodeSubject = getStringToCS(listSubjectModel[(intIDSubject - 1)].codeSubject);
			}
			if (checkNullEdit(strNameSubject)) {
				strNameSubject = getStringToCS(listSubjectModel[(intIDSubject - 1)].nameSubject);
			}
			if (intCreditsSubject == lowSpinCreditsSubject) {
				intCreditsSubject = listSubjectModel[(intIDSubject - 1)].creditsSubject;
			}
			if (intLessonSubject == lowSpinLessonSubject) {
				intLessonSubject = listSubjectModel[(intIDSubject - 1)].lessonSubject;
			}



			//Sủa trong model 
			editSubject(
				intIDSubject,
				getCsToString(strCodeSubject),
				getCsToString(strNameSubject),
				intCreditsSubject,
				intLessonSubject);

			//lưu file 
			saveFileSubject();

			// Sủa sinh viên vào list 
			listSubjectController.SetItemText(i, 0, getIntToCS(intIDSubject));
			listSubjectController.SetItemText(i, 1, strCodeSubject);
			listSubjectController.SetItemText(i, 2, strNameSubject);
			listSubjectController.SetItemText(i, 3, getIntToCS(intCreditsSubject));
			listSubjectController.SetItemText(i, 4, getIntToCS(intLessonSubject));

		}
	}

	//kiểm tra xem đã chọn sinh viên chưa
	if (intIDSubject == -1)
	{
		MessageBox(L"Vui lòng chọn sinh viên !");
	}
	else
	{
		//xóa editer trên màn hình 
		edtNameSubject.SetWindowText(_T(""));
		edtCodeSubject.SetWindowText(_T(""));
		edtCreditsSubject.SetWindowText((getIntToCS(lowSpinCreditsSubject)));
		edtLessonSubject.SetWindowText((getIntToCS(lowSpinLessonSubject)));
	}

	// lấy dữ diệu 
	CString strSearch;
	edtSearch.GetWindowText(strSearch);

	CString strCbSearch;
	cbSearch.GetWindowText(strCbSearch);

	searchSubject(strSearch, strCbSearch, false);


	UpdateData(FALSE);
}


void SubjectManageDlg::OnBnClickedBtnSeachsubject()
{
	UpdateData(TRUE);

	// lấy dữ diệu 
	CString strSearch;
	edtSearch.GetWindowText(strSearch);

	CString strCbSearch;
	cbSearch.GetWindowText(strCbSearch);

	searchSubject(strSearch, strCbSearch, true);


	UpdateData(FALSE);
}


void SubjectManageDlg::OnBnClickedBtnRemovesubject()
{



	UpdateData(TRUE);

	int intIDSubject = -1;

	For(listSubjectController.GetItemCount())
	{
		if (listSubjectController.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED)
		{
			intIDSubject = getStringToInt(getCsToString(listSubjectController.GetItemText(i, 0)));

			removeSubject(intIDSubject);

			clearSubjectListController();

			removeSubject(intIDSubject);

			saveFileSubject();

			listSubjectModel.clear();

			loadDataSubject();

			For(listSubjectModel.size()) addSubjectToListControler(i);

		}
	}

	if (intIDSubject == -1) {
		MessageBox(L"Vui lòng chọn sinh viên !");
	}


	// lấy dữ diệu 
	CString strSearch;
	edtSearch.GetWindowText(strSearch);

	CString strCbSearch;
	cbSearch.GetWindowText(strCbSearch);

	searchSubject(strSearch, strCbSearch, false);

	UpdateData(FALSE);
}
