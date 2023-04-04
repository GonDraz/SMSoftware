#pragma once
#include "afxdialogex.h"
#include "Store.h"

// StudentManageDlg dialog

class StudentManageDlg : public CDialogEx, Store

{
	DECLARE_DYNAMIC(StudentManageDlg)

public:
	StudentManageDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~StudentManageDlg();

	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Dlg_StudentManage };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()


protected:
	virtual BOOL OnInitDialog();

	afx_msg void OnBnClickedBtnAddstudent();

private:
	void clearStudentListController();

	void searchStudent(CString const& strSearch, CString const& strCbSearch, bool const& inputState);

	void addStudentToListControler(int const& i);
protected:
	// edit tên sinh viên
	CEdit edtNameStudent;

	// edit mã sinh viên
	CEdit edtCodeStudent;

	// edit lớp sinh viên
	CEdit edtClassStudent;

	// edit ngày sinh sinh viên
	CDateTimeCtrl edtBirthdayStudent;

	// edit số điện thoại sinh viên
	CEdit edtPhoneNumberStudent;

	// list của trang quản lý sinh viên
	CListCtrl listStudentController;

	// edit mail sinh viên
	CEdit edtMailStudent;

	// //combo box tim kiem sinh vien
	CComboBox cbSearchStudent;

	CComboBox cbSexStudent;

	// // edit tìm kiếm
	CEdit edtSearch;
public:
	afx_msg void OnBnClickedBtnEditstudent();

	afx_msg void OnBnClickedBtnRemovestudent();

	afx_msg void OnBnClickedBtnSeachstudent();
};
