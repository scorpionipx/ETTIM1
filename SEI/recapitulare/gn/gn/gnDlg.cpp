// gnDlg.cpp : implementation file
//

#include "stdafx.h"
#include "gn.h"
#include "gnDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CgnDlg dialog

CgnDlg::CgnDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CgnDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CgnDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, eb);
	CString text;
	text.Format(_T("Mesaj de bun venit"));
	eb.SetWindowTextW(text);
}

BEGIN_MESSAGE_MAP(CgnDlg, CDialog)
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	ON_WM_SIZE()
#endif
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CgnDlg message handlers

BOOL CgnDlg::OnInitDialog()
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
void CgnDlg::OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/)
{
	if (AfxIsDRAEnabled())
	{
		DRA::RelayoutDialog(
			AfxGetResourceHandle(), 
			this->m_hWnd, 
			DRA::GetDisplayMode() != DRA::Portrait ? 
			MAKEINTRESOURCE(IDD_GN_DIALOG_WIDE) : 
			MAKEINTRESOURCE(IDD_GN_DIALOG));
	}
}
#endif

