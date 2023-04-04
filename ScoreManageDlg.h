#pragma once
#include "afxdialogex.h"
#include "Store.h"
// ScoreManageDlg dialog

const int lowScore= -1;
const int highScore = 10;

class ScoreManageDlg : public CDialogEx, Store
{
	DECLARE_DYNAMIC(ScoreManageDlg)

public:
	ScoreManageDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~ScoreManageDlg();

	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Dlg_ScoreManage };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
		afx_msg
		BOOL OnInitDialog();
public:
	void OnBnClickedBtnEditscore();

	afx_msg void OnBnClickedBtnSeachscore();


private:
	void clearSroceListController();
	void searchStudent(CString const& strSearch, CString const& strCbSearch, bool const& inputState);

	void addScoreToListControler(int const& i);

protected:
	CEdit edtScore;
	CSpinButtonCtrl spinScore;
	CEdit edtSearch;
	CComboBox cbSearch;
	CListCtrl listScoreController;
	CComboBox cbSubject;
};
