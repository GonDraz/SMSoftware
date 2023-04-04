﻿
// SMSoftwareDlg.cpp : implementation file
//

#include "pch.h"
#include "SMSoftware.h"
#include "SMSoftwareDlg.h"
#include "StudentManageDlg.h"
#include "SubjectManageDlg.h"
#include "ScoreManageDlg.h"
#include "Store.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif



// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CSMSoftwareDlg dialog



CSMSoftwareDlg::CSMSoftwareDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SMSOFTWARE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSMSoftwareDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CSMSoftwareDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_Btn_Exit, &CSMSoftwareDlg::OnBnClickedBtnExit)
	ON_BN_CLICKED(IDC_Btn_ScoreManage, &CSMSoftwareDlg::OnBnClickedBtnScoremanage)
	ON_BN_CLICKED(IDC_Btn_StudentManage, &CSMSoftwareDlg::OnBnClickedBtnStudentmanage)
	ON_BN_CLICKED(IDC_Btn_SettingManage, &CSMSoftwareDlg::OnBnClickedBtnSettingmanage)
	ON_BN_CLICKED(IDC_Btn_SubjectManage, &CSMSoftwareDlg::OnBnClickedBtnSubjectmanage)
END_MESSAGE_MAP()


// CSMSoftwareDlg message handlers

BOOL CSMSoftwareDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	ShowWindow(SW_MINIMIZE);

	// TODO: Add extra initialization here



	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSMSoftwareDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CSMSoftwareDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CSMSoftwareDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}





void CSMSoftwareDlg::OnBnClickedBtnExit()
{
	CDialogEx::OnOK();
}



// mở dlg quản lý sinh viên
void CSMSoftwareDlg::OnBnClickedBtnStudentmanage()
{
	cin.ignore();
	StudentManageDlg studentManageDlg;
	studentManageDlg.DoModal();
}



// mở dlj quản lý điểm 
void CSMSoftwareDlg::OnBnClickedBtnSubjectmanage()
{
	cin.ignore();
	SubjectManageDlg subjectManageDlg;
	subjectManageDlg.DoModal();
}

// mở dlg setting 
void CSMSoftwareDlg::OnBnClickedBtnSettingmanage()
{
	MessageBox(_T("Hiện tính năng chưa được phát triển!"));
}

// mở dlg quản lý điểm 
void CSMSoftwareDlg::OnBnClickedBtnScoremanage()
{
	cin.ignore();
	ScoreManageDlg scoreManageDlg;
	scoreManageDlg.DoModal();
}
