// dialogDlg.cpp : implementation file
//

#include "stdafx.h"
#include "dialog.h"
#include "dialogDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CdialogDlg dialog
// file -> new project -> visual c++ -> MFC smart device application -> dialog based


CdialogDlg::CdialogDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CdialogDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CdialogDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, tb1);
	DDX_Control(pDX, IDC_EDIT2, tb2);
	DDX_Control(pDX, IDC_CHECK1, cb_hide);
	DDX_Control(pDX, IDC_CHECK2, cb_valid);
	DDX_Control(pDX, IDC_BUTTON1, btn);
}

BEGIN_MESSAGE_MAP(CdialogDlg, CDialog)
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	ON_WM_SIZE()
#endif
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CdialogDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CdialogDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CdialogDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_CHECK1, &CdialogDlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_CHECK2, &CdialogDlg::OnBnClickedCheck2)
END_MESSAGE_MAP()


// CdialogDlg message handlers

BOOL CdialogDlg::OnInitDialog()
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
void CdialogDlg::OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/)
{
	if (AfxIsDRAEnabled())
	{
		DRA::RelayoutDialog(
			AfxGetResourceHandle(), 
			this->m_hWnd, 
			DRA::GetDisplayMode() != DRA::Portrait ? 
			MAKEINTRESOURCE(IDD_DIALOG_DIALOG_WIDE) : 
			MAKEINTRESOURCE(IDD_DIALOG_DIALOG));
	}
}
#endif


void CdialogDlg::OnBnClickedButton1()
{
	if(!cb_valid.GetCheck())  // verificare stare check box (si negare)
	{
		CString text_tb1, output_text;  // declarare variabila pentru stocare text
		tb1.GetWindowTextW(text_tb1);  // preluare text din prima caseta

		output_text.Format(_T(" Textul este: %s"), text_tb1);  // adaugare text  <=>  output_text = "Textul este: " + text_tb1
		tb2.SetWindowTextW(output_text);  // scriere text in a doua caseta
	}
}

void CdialogDlg::OnBnClickedButton2()
{
	CString text_tb1, output_text;  // declarare variabila pentru stocare text
	char buffer[10];  // variabila pentru stocare text sub forma de sir de caractere
	float numar;  // declarare variabila de stocare a numarului 

	tb1.GetWindowTextW(text_tb1);  // preluare text din prima caseta
	
	wcstombs(buffer, text_tb1, 10);  // transormarea textului preluat in sir de caractere
	numar = (atof(buffer));  // transformarea sirului de caractere in valoare float
	numar *= 2;  // calcul dublul valorii
		
	output_text.Format(_T("2 x float: %f"), numar);  // adaugare text  <=>  output_text = "2 x float: " + numar
	tb2.SetWindowTextW(output_text);  // scriere text in a doua caseta
}

void CdialogDlg::OnBnClickedButton3()
{
	CString text_tb1, output_text;  // declarare variabila pentru stocare text
	char buffer[10];  // variabila pentru stocare text sub forma de sir de caractere
	int numar;  // declarare variabila de stocare a numarului 

	tb1.GetWindowTextW(text_tb1);  // preluare text din prima caseta
	
	wcstombs(buffer, text_tb1, 10);  // transormarea textului preluat in sir de caractere
	numar = (int) (atof(buffer));  // transformarea sirului de caractere in valoare float, apoi fortata in tip intreg
	numar *= 3;  // calcul triplul valorii
		
	output_text.Format(_T("3 x int: %d"), numar);  // adaugare text  <=>  output_text = "3 x int: " + numar
	tb2.SetWindowTextW(output_text);  // scriere text in a doua caseta
}

void CdialogDlg::OnBnClickedCheck1()
{
	if(cb_hide.GetCheck())  // verificare stare check box - este bifat
	{
		// ascunde butonul - cb e bifat
		btn.ShowWindow(0);
	}
	else  // nu este bifat
	{
		// afiseaza butonul
		btn.ShowWindow(1);
	}
}

void CdialogDlg::OnBnClickedCheck2()
{
	// TODO: Add your control notification handler code here
}
