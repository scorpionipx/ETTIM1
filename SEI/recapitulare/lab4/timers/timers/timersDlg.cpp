// timersDlg.cpp : implementation file
//

#include "stdafx.h"
#include "timers.h"
#include "timersDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CtimersDlg dialog
#define WM_TIMER_1000MS WM_USER + 400
#define WM_TIMER_2500MS WM_USER + 401

UINT_PTR timer_1000ms;
UINT_PTR timer_2500ms;

int counter = 0;

CtimersDlg::CtimersDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CtimersDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CtimersDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, tb1);
	DDX_Control(pDX, IDC_EDIT2, tb2);
}

BEGIN_MESSAGE_MAP(CtimersDlg, CDialog)
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	ON_WM_SIZE()
#endif
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CtimersDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CtimersDlg::OnBnClickedButton2)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CtimersDlg message handlers

BOOL CtimersDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
void CtimersDlg::OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/)
{
	if (AfxIsDRAEnabled())
	{
		DRA::RelayoutDialog(
			AfxGetResourceHandle(), 
			this->m_hWnd, 
			DRA::GetDisplayMode() != DRA::Portrait ? 
			MAKEINTRESOURCE(IDD_TIMERS_DIALOG_WIDE) : 
			MAKEINTRESOURCE(IDD_TIMERS_DIALOG));
	}
}
#endif


void CtimersDlg::OnBnClickedButton1()
{
	timer_1000ms = SetTimer (WM_TIMER_1000MS, 1000, NULL); 
	timer_2500ms = SetTimer (WM_TIMER_2500MS, 2500, NULL); 
}

void CtimersDlg::OnBnClickedButton2()
{
	KillTimer(timer_1000ms);
	KillTimer(timer_2500ms);
	counter = 0;
	tb1.SetWindowTextW(NULL);
	tb2.SetWindowTextW(NULL);
}

void CtimersDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default

	CDialog::OnTimer(nIDEvent);
	if(nIDEvent == WM_TIMER_1000MS)
	{
		CTime ct=CTime::GetCurrentTime();
		int h, m, s;
		h = ct.GetHour();
		m = ct.GetMinute();
		s = ct.GetSecond();
		CString clock;
		clock.Format(_T("%02d:%02d:%02d"), h, m, s);
		tb1.SetWindowTextW(clock);

	}
	if(nIDEvent == WM_TIMER_2500MS)
	{
		counter ++;
		CString out;
		out.Format(_T("%d"), counter);
		tb2.SetWindowTextW(out);
	}
}
