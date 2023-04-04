
// SMSoftwareDlg.h : header file
//

#pragma once


// CSMSoftwareDlg dialog
class CSMSoftwareDlg : public CDialogEx
{
// Construction
public:
	CSMSoftwareDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SMSOFTWARE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnExit();
	afx_msg void OnBnClickedBtnScoremanage();
	afx_msg void OnBnClickedBtnStudentmanage();
	afx_msg void OnBnClickedBtnSettingmanage();
	afx_msg void OnBnClickedBtnSubjectmanage();
};
