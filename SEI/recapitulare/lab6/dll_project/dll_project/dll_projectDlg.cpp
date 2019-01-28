// dll_projectDlg.cpp : implementation file
//

#include "stdafx.h"
#include "dll_project.h"
#include "dll_projectDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include "imported_functions.h"
#pragma comment(lib, "dll_fct1.lib")
#pragma comment(lib, "fct_mat2.lib")

float a, b, c;


// Cdll_projectDlg dialog

Cdll_projectDlg::Cdll_projectDlg(CWnd* pParent /*=NULL*/)
	: CDialog(Cdll_projectDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cdll_projectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, tb_a);
	DDX_Control(pDX, IDC_EDIT2, tb_b);
	DDX_Control(pDX, IDC_EDIT3, tb_c);
}

BEGIN_MESSAGE_MAP(Cdll_projectDlg, CDialog)
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	ON_WM_SIZE()
#endif
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &Cdll_projectDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Cdll_projectDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// Cdll_projectDlg message handlers

BOOL Cdll_projectDlg::OnInitDialog()
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
void Cdll_projectDlg::OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/)
{
	if (AfxIsDRAEnabled())
	{
		DRA::RelayoutDialog(
			AfxGetResourceHandle(), 
			this->m_hWnd, 
			DRA::GetDisplayMode() != DRA::Portrait ? 
			MAKEINTRESOURCE(IDD_DLL_PROJECT_DIALOG_WIDE) : 
			MAKEINTRESOURCE(IDD_DLL_PROJECT_DIALOG));
	}
}
#endif
/*
void update_values()
{
	CString text_tba, text_tbb;  // declarare variabila pentru stocare text
	char buffer[10];  // variabila pentru stocare text sub forma de sir de caractere

	tb_a.GetWindowTextW(text_tba);  // preluare text din prima caseta
	
	wcstombs(buffer, text_tba, 10);  // transormarea textului preluat in sir de caractere
	a = (atof(buffer));  // transformarea sirului de caractere in valoare float

	tb_b.GetWindowTextW(text_tbb);  // preluare text din prima caseta
	
	wcstombs(buffer, text_tbb, 10);  // transormarea textului preluat in sir de caractere
	b = (atof(buffer));  // transformarea sirului de caractere in valoare float
}*/

void Cdll_projectDlg::OnBnClickedButton1()
{
	CString text_output;
	CString text_tba, text_tbb;  // declarare variabila pentru stocare text
	char buffer[10];  // variabila pentru stocare text sub forma de sir de caractere

	tb_a.GetWindowTextW(text_tba);  // preluare text din prima caseta
	
	wcstombs(buffer, text_tba, 10);  // transormarea textului preluat in sir de caractere
	a = (atof(buffer));  // transformarea sirului de caractere in valoare float

	tb_b.GetWindowTextW(text_tbb);  // preluare text din a doua caseta
	
	wcstombs(buffer, text_tbb, 10);  // transormarea textului preluat in sir de caractere
	b = (atof(buffer));  // transformarea sirului de caractere in valoare float

	c = fct_mat1(a, b);  // utilizare functie DLL
	text_output.Format(_T("%f"), c);  // creare text de afisat in caseta 3
	tb_c.SetWindowTextW(text_output);  // afisare text
}

void Cdll_projectDlg::OnBnClickedButton2()
{
	CString text_output;
	CString text_tba, text_tbb;  // declarare variabila pentru stocare text
	char buffer[10];  // variabila pentru stocare text sub forma de sir de caractere

	tb_a.GetWindowTextW(text_tba);  // preluare text din prima caseta
	
	wcstombs(buffer, text_tba, 10);  // transormarea textului preluat in sir de caractere
	a = (atof(buffer));  // transformarea sirului de caractere in valoare float

	tb_b.GetWindowTextW(text_tbb);  // preluare text din a doua caseta
	
	wcstombs(buffer, text_tbb, 10);  // transormarea textului preluat in sir de caractere
	b = (atof(buffer));  // transformarea sirului de caractere in valoare float

	c = fct_mat2(a, b);  // utilizare functie DLL
	text_output.Format(_T("%f"), c);  // creare text de afisat in caseta 3
	tb_c.SetWindowTextW(text_output);  // afisare text
}
