#pragma once
#include "afxdialogex.h"
#include "Store.h"

const int lowSpinCreditsSubject = 1;
const int highSpinCreditsSubject = 10;

const int lowSpinLessonSubject = 10;
const int highSpinLessonSubject = 100;

// SubjectManageDlg dialog

class SubjectManageDlg : public CDialogEx, Store
{
	DECLARE_DYNAMIC(SubjectManageDlg)

public:
	SubjectManageDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~SubjectManageDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Dlg_SubjectManage };
#endif

private:

	void addSubjectToListControler(int const& i);

	void clearSubjectListController();

	void addSubjectToList(int const& i);

	void searchSubject(CString const& strSearch, CString const& strCbSearch, bool const& inputState);

protected:
	virtual BOOL OnInitDialog();

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

protected:
	// khai báo 
	CListCtrl listSubjectController;

	CEdit edtSearch;

	CComboBox cbSearch;

	CEdit edtNameSubject;

	CEdit edtCodeSubject;

	CSpinButtonCtrl spinCreditsSubject;

	CEdit edtCreditsSubject;

	CEdit edtLessonSubject;

	CSpinButtonCtrl spinLessonSubject;

public:
	afx_msg void OnBnClickedBtnAddsubject();



	afx_msg void OnBnClickedBtnEditsubject();
	afx_msg void OnBnClickedBtnSeachsubject();
	afx_msg void OnBnClickedBtnRemovesubject();
};
