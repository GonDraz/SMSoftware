// StudentManageDlg.cpp : implementation file
//
#include "pch.h"
#include "StudentManageDlg.h"

// StudentManageDlg dialog

IMPLEMENT_DYNAMIC(StudentManageDlg, CDialogEx)

StudentManageDlg::StudentManageDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Dlg_StudentManage, pParent)
{
}

StudentManageDlg::~StudentManageDlg()
{
}

void StudentManageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_NameStudent, edtNameStudent);
	DDX_Control(pDX, IDC_EDIT_IDStudent, edtCodeStudent);
	DDX_Control(pDX, IDC_EDIT_ClassStudent, edtClassStudent);
	DDX_Control(pDX, IDC_EDIT_BirthdayStudent, edtBirthdayStudent);
	DDX_Control(pDX, IDC_EDIT_PhoneNumberStudent, edtPhoneNumberStudent);
	DDX_Control(pDX, IDC_EDIT_MailAddressStudent, edtMailStudent);
	DDX_Control(pDX, IDC_COMBO1, cbSexStudent);
	DDX_Control(pDX, IDC_LIST_Student, listStudentController);
	DDX_Control(pDX, IDC_EDIT_SeachStudent, edtSearch);
	DDX_Control(pDX, IDC_COMBO_SearchStudent, cbSearchStudent);
}


BEGIN_MESSAGE_MAP(StudentManageDlg, CDialogEx)
	ON_BN_CLICKED(IDC_Btn_AddStudent, &StudentManageDlg::OnBnClickedBtnAddstudent)
	ON_BN_CLICKED(IDC_Btn_EditStudent, &StudentManageDlg::OnBnClickedBtnEditstudent)
	ON_BN_CLICKED(IDC_Btn_RemoveStudent, &StudentManageDlg::OnBnClickedBtnRemovestudent)
	ON_BN_CLICKED(IDC_Btn_SeachStudent, &StudentManageDlg::OnBnClickedBtnSeachstudent)
END_MESSAGE_MAP()

BOOL StudentManageDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	//set up combo box tim kiem
	cbSearchStudent.AddString(_T("họ và tên"));
	cbSearchStudent.AddString(_T("mã"));
	cbSearchStudent.AddString(_T("lớp"));
	cbSearchStudent.AddString(_T("mail"));
	cbSearchStudent.AddString(_T("số điện thoại"));
	cbSearchStudent.SetCurSel(0);


	//set up combo box giới tính 
	cbSexStudent.AddString(_T(""));
	cbSexStudent.AddString(_T("Nam"));
	cbSexStudent.AddString(_T("Nu"));

	//cbSexStudent.SetCurSel(0);


	//set up phần list student 
	listStudentController.SetExtendedStyle(listStudentController.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	listStudentController.InsertColumn(0, _T("stt"), LVCFMT_LEFT, 50);
	listStudentController.InsertColumn(1, _T("mã"), LVCFMT_LEFT, 70);
	listStudentController.InsertColumn(2, _T("họ và tên"), LVCFMT_LEFT, 150);
	listStudentController.InsertColumn(3, _T("lớp"), LVCFMT_LEFT, 50);
	listStudentController.InsertColumn(4, _T("ngày sinh"), LVCFMT_LEFT, 70);
	listStudentController.InsertColumn(5, _T("giới tính"), LVCFMT_LEFT, 50);
	listStudentController.InsertColumn(6, _T("số điện thoại"), LVCFMT_LEFT, 80);
	listStudentController.InsertColumn(7, _T("mail"), LVCFMT_LEFT, 150);


	loadDataStudent();
	For(listStudentModel.size()) addStudentToListControler(i);


	return TRUE;  // return TRUE  unless you set the focus to a control
}

// nút thêm sinh viên 
void StudentManageDlg::OnBnClickedBtnAddstudent()
{

	UpdateData(TRUE);


	int intIDStudent = listStudentModel.size();

	// lấy dữ diệu 
	CString strCodeStudent;
	edtCodeStudent.GetWindowText(strCodeStudent);

	CString strNameStudent;
	edtNameStudent.GetWindowText(strNameStudent);

	CString strClassStudent;
	edtClassStudent.GetWindowText(strClassStudent);

	CString strBirthdayStudent;
	edtBirthdayStudent.GetWindowText(strBirthdayStudent);

	CString strPhoneNumberStudent;
	edtPhoneNumberStudent.GetWindowText(strPhoneNumberStudent);

	CString strSexStudent;
	cbSexStudent.GetWindowText(strSexStudent);

	CString strMailStudent;
	edtMailStudent.GetWindowText(strMailStudent);

	//kiểm tra dữ liệu mã, tên, lớp 
	if (checkNullEdit(strCodeStudent) || checkNullEdit(strNameStudent) || checkNullEdit(strClassStudent) || checkNullEdit(strNameStudent) || checkNullEdit(strSexStudent)) {
		MessageBox(L"vui lòng điền đầy đủ thông tin ");
	}
	else
	{
		//tạo số thứ tự sinh viên 
		intIDStudent++;

		//thêm vào model 
		addStudent(
			intIDStudent,
			getCsToString(strCodeStudent),
			getCsToString(strNameStudent),
			getCsToString(strClassStudent),
			getCsToString(strBirthdayStudent),
			getCsToString(strSexStudent),
			getCsToString(strPhoneNumberStudent),
			getCsToString(strMailStudent));

		//lưu file 
		saveFileStudent();

		// thêm sinh viên vào list 
		listStudentController.InsertItem(0, getIntToCS(intIDStudent));
		listStudentController.SetItemText(0, 1, strCodeStudent);
		listStudentController.SetItemText(0, 2, strNameStudent);
		listStudentController.SetItemText(0, 3, strClassStudent);
		listStudentController.SetItemText(0, 4, strBirthdayStudent);
		listStudentController.SetItemText(0, 5, strSexStudent);
		listStudentController.SetItemText(0, 6, strPhoneNumberStudent);
		listStudentController.SetItemText(0, 7, strMailStudent);

		//xóa editer trên màn hình 
		edtCodeStudent.SetWindowText(_T(""));
		edtNameStudent.SetWindowText(_T(""));
		edtClassStudent.SetWindowText(_T(""));
		edtPhoneNumberStudent.SetWindowText(_T(""));
		edtMailStudent.SetWindowText(_T(""));
		cbSexStudent.SetCurSel(0);
	}


	// lấy dữ diệu 
	CString strSearch;
	edtSearch.GetWindowText(strSearch);

	CString strCbSearch;
	cbSearchStudent.GetWindowText(strCbSearch);

	searchStudent(strSearch, strCbSearch, false);


	UpdateData(FALSE);

}

void StudentManageDlg::clearStudentListController()
{
	//xóa list controller
	back:
	for (int j = 0; j < listStudentController.GetItemCount(); j++)
	{
		listStudentController.DeleteItem(j);
	}
	if (listStudentController.GetItemCount() != 0) {
		goto back;
	}
}


void StudentManageDlg::OnBnClickedBtnEditstudent()
{
	UpdateData(TRUE);

	int intIDStudent = -1;

	// lấy dữ diệu 
	CString strCodeStudent;
	edtCodeStudent.GetWindowText(strCodeStudent);

	CString strNameStudent;
	edtNameStudent.GetWindowText(strNameStudent);

	CString strClassStudent;
	edtClassStudent.GetWindowText(strClassStudent);

	CString strBirthdayStudent;
	edtBirthdayStudent.GetWindowText(strBirthdayStudent);

	CString strPhoneNumberStudent;
	edtPhoneNumberStudent.GetWindowText(strPhoneNumberStudent);

	CString strSexStudent;
	cbSexStudent.GetWindowText(strSexStudent);

	CString strMailStudent;
	edtMailStudent.GetWindowText(strMailStudent);
	For(listStudentController.GetItemCount())
	{
		if (listStudentController.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED)
		{
			intIDStudent = getStringToInt(getCsToString(listStudentController.GetItemText(i, 0)));

			//check null
			if (checkNullEdit(strCodeStudent)) {
				strCodeStudent = getStringToCS(listStudentModel[(intIDStudent - 1)].codeStudent);
			}
			if (checkNullEdit(strNameStudent)) {
				strNameStudent = getStringToCS(listStudentModel[(intIDStudent - 1)].nameStudent);
			}
			if (checkNullEdit(strClassStudent)) {
				strClassStudent = getStringToCS(listStudentModel[(intIDStudent - 1)].classStudent);
			}
			if (getCsToString(strBirthdayStudent) == loadTime()) {
				strBirthdayStudent = getStringToCS(listStudentModel[(intIDStudent - 1)].birthdayStudent);
			}
			if (checkNullEdit(strSexStudent)) {
				strSexStudent = getStringToCS(listStudentModel[(intIDStudent - 1)].sexStudent);
			}
			if (checkNullEdit(strPhoneNumberStudent)) {
				strPhoneNumberStudent = getStringToCS(listStudentModel[(intIDStudent - 1)].phoneNumberStudent);
			}
			if (checkNullEdit(strMailStudent)) {
				strMailStudent = getStringToCS(listStudentModel[(intIDStudent - 1)].mailStudent);
			}

			//Sủa trong model 
			editStudent(
				intIDStudent,
				getCsToString(strCodeStudent),
				getCsToString(strNameStudent),
				getCsToString(strClassStudent),
				getCsToString(strBirthdayStudent),
				getCsToString(strSexStudent),
				getCsToString(strPhoneNumberStudent),
				getCsToString(strMailStudent));

			//lưu file 
			saveFileStudent();

			// Sủa sinh viên vào list 
			listStudentController.SetItemText(i, 0, getIntToCS(intIDStudent));
			listStudentController.SetItemText(i, 1, strCodeStudent);
			listStudentController.SetItemText(i, 2, strNameStudent);
			listStudentController.SetItemText(i, 3, strClassStudent);
			listStudentController.SetItemText(i, 4, strBirthdayStudent);
			listStudentController.SetItemText(i, 5, strSexStudent);
			listStudentController.SetItemText(i, 6, strPhoneNumberStudent);
			listStudentController.SetItemText(i, 7, strMailStudent);
		}
	}

	//kiểm tra xem đã chọn sinh viên chưa
	if (intIDStudent == -1)
	{
		MessageBox(L"Vui lòng chọn sinh viên !");
	}
	else
	{
		//xóa editer trên màn hình 
		edtNameStudent.SetWindowText(_T(""));
		edtCodeStudent.SetWindowText(_T(""));
		edtClassStudent.SetWindowText(_T(""));
		edtPhoneNumberStudent.SetWindowText(_T(""));
		edtMailStudent.SetWindowText(_T(""));
		cbSexStudent.SetCurSel(0);
	}

	// lấy dữ diệu 
	CString strSearch;
	edtSearch.GetWindowText(strSearch);

	CString strCbSearch;
	cbSearchStudent.GetWindowText(strCbSearch);

	searchStudent(strSearch, strCbSearch, false);


	UpdateData(FALSE);
}

void StudentManageDlg::OnBnClickedBtnRemovestudent()
{

	UpdateData(TRUE);

	int intIDStudent = -1;

	For(listStudentController.GetItemCount())
	{
		if (listStudentController.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED)
		{
			intIDStudent = getStringToInt(getCsToString(listStudentController.GetItemText(i, 0)));

			removeStudent(intIDStudent);

			clearStudentListController();

			removeStudent(intIDStudent);

			saveFileStudent();

			listStudentModel.clear();

			loadDataStudent();

			For(listStudentModel.size()) addStudentToListControler(i);

		}
	}

	if (intIDStudent == -1) {
		MessageBox(L"Vui lòng chọn sinh viên !");
	}


	// lấy dữ diệu 
	CString strSearch;
	edtSearch.GetWindowText(strSearch);

	CString strCbSearch;
	cbSearchStudent.GetWindowText(strCbSearch);

	searchStudent(strSearch, strCbSearch, false);

	UpdateData(FALSE);
}

void StudentManageDlg::searchStudent(CString const& strSearch, CString const& strCbSearch, bool const& inputState) {

	// bien luu giu do dai cua chuoi can tim kiem
	int len = getCsToString(strSearch).size();

	if (checkNullEdit(strSearch)) {
		if (inputState)
		{
			clearStudentListController();

			For(listStudentModel.size()) addStudentToListControler(i);
		}
	}
	else if (len >= 30) {
		MessageBox(L"tìm kiếm quá dài");
	}
	else {
		char charSearch[30];
		strcpy(charSearch, CStringA(strSearch).GetString());

		clearStudentListController();
		char str[30];

		int n = 0;
		int m = 0;

		For(listStudentModel.size()) {
			n = 0;
			m = 0;

			if (strCbSearch == L"họ và tên")
				strcpy(str, (listStudentModel[i].nameStudent).c_str());
			else if (strCbSearch == L"mã")
				strcpy(str, (listStudentModel[i].codeStudent).c_str());
			else if (strCbSearch == L"lớp")
				strcpy(str, (listStudentModel[i].classStudent).c_str());
			else if (strCbSearch == L"mail")
				strcpy(str, (listStudentModel[i].mailStudent).c_str());
			else if (strCbSearch == L"số điện thoại")
				strcpy(str, (listStudentModel[i].phoneNumberStudent).c_str());
			else {
				cbSearchStudent.SetCurSel(0);
				strcpy(str, (listStudentModel[i].nameStudent).c_str());
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

						addStudentToListControler(i);
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

void StudentManageDlg::addStudentToListControler(int const& i)
{
	listStudentController.InsertItem(0, getIntToCS(listStudentModel[i].idStudent));
	listStudentController.SetItemText(0, 1, getStringToCS(listStudentModel[i].codeStudent));
	listStudentController.SetItemText(0, 2, getStringToCS(listStudentModel[i].nameStudent));
	listStudentController.SetItemText(0, 3, getStringToCS(listStudentModel[i].classStudent));
	listStudentController.SetItemText(0, 4, getStringToCS(listStudentModel[i].birthdayStudent));
	listStudentController.SetItemText(0, 5, getStringToCS(listStudentModel[i].sexStudent));
	listStudentController.SetItemText(0, 6, getStringToCS(listStudentModel[i].phoneNumberStudent));
	listStudentController.SetItemText(0, 7, getStringToCS(listStudentModel[i].mailStudent));
}


void StudentManageDlg::OnBnClickedBtnSeachstudent()
{
	UpdateData(TRUE);


	// lấy dữ diệu 
	CString strSearch;
	edtSearch.GetWindowText(strSearch);

	CString strCbSearch;
	cbSearchStudent.GetWindowText(strCbSearch);

	searchStudent(strSearch, strCbSearch, true);


	UpdateData(FALSE);

}
