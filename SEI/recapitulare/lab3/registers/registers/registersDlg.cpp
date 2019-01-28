// registersDlg.cpp : implementation file
//

#include "stdafx.h"
#include "registers.h"
#include "registersDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CregistersDlg dialog
CString szVarsta, szNume;  // reprezentarea textuala a numelui si varstei
HKEY myKey;
long error;  // stocheaza rezultatul operatiunilor facute cu registre
wchar_t *endStr;
DWORD disp;
int varsta;

CregistersDlg::CregistersDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CregistersDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CregistersDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, tb1);
	DDX_Control(pDX, IDC_EDIT2, tb2);
}

BEGIN_MESSAGE_MAP(CregistersDlg, CDialog)
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	ON_WM_SIZE()
#endif
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON4, &CregistersDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON1, &CregistersDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CregistersDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CregistersDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CregistersDlg message handlers

BOOL CregistersDlg::OnInitDialog()
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
void CregistersDlg::OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/)
{
	if (AfxIsDRAEnabled())
	{
		DRA::RelayoutDialog(
			AfxGetResourceHandle(), 
			this->m_hWnd, 
			DRA::GetDisplayMode() != DRA::Portrait ? 
			MAKEINTRESOURCE(IDD_REGISTERS_DIALOG_WIDE) : 
			MAKEINTRESOURCE(IDD_REGISTERS_DIALOG));
	}
}
#endif


void CregistersDlg::OnBnClickedButton4()
{
	tb1.SetWindowTextW(NULL);  // stergere text caseta nume
	tb2.SetWindowTextW(NULL);  // stergere text caseta varsta
}

void CregistersDlg::OnBnClickedButton1()
{
	error = RegCreateKeyEx(HKEY_LOCAL_MACHINE, L"STUDENT", 0, NULL, REG_OPTION_NON_VOLATILE, 0, NULL, &myKey, &disp);  // creare cheie in registru	
	if(error == ERROR_SUCCESS)  // verificare eroare
	{
		AfxMessageBox(_T("Cheia a fost creata cu succes!"), MB_OK, 0);  // nu exista erori
	}
	else
	{
		AfxMessageBox(_T("A aparut o eroare la crearea cheii!"), MB_OK, 0);  // a aparut o eroare
	}
	
	if ((tb2.GetWindowTextLengthW() == 0))  // text box gol
	{
		AfxMessageBox(_T("Varsta nu a fost specificata!"), MB_OK, 0);  // afisare mesaj
		return;  // iesire
	}
	else if (tb1.GetWindowTextLengthW() == 0)  // text box gol
	{
		AfxMessageBox(_T("Numele nu a fost specificat!"), MB_OK, 0);  // afisare mesaj
		return;  // iesire
	}
	else  // datele introduse sunt ok
	{
		tb2.GetWindowTextW(szVarsta);  // citire varsta din caseta
		varsta = wcstoul(szVarsta,&endStr,10);  // conversie varsta din cstring in unsigned long
		error = RegSetValueEx(myKey, _T("Varsta"), 0, REG_DWORD,(LPBYTE)&varsta, sizeof(varsta));  // scriere varsta in registru
		if ((error == ERROR_SUCCESS) && (varsta > 0))  // verificare erori
		{
			AfxMessageBox(_T("S-a inregistrat varsta!"), MB_OK, 0);  // nu exista erori
		}
		else
		{
			AfxMessageBox(_T("A aparut o eroare la inregistrarea varstei!"), MB_OK, 0);  // a aparut o eroare
		}
		
		tb1.GetWindowTextW(szNume);  // citire nume din caseta
		error = RegSetValueEx(myKey, _T("Nume"), 0, REG_SZ,(LPBYTE)szNume.GetBuffer(),(DWORD)(lstrlen(szNume.GetBuffer()) + 1)*sizeof(TCHAR));  // scriere nume in registru
		if (error == ERROR_SUCCESS)  // verificare erori
		{
			AfxMessageBox(_T("S-a inregistrat numele!"), MB_OK, 0);  // nu exista erori
		}
		else
		{
			AfxMessageBox(_T("A aparut o eroare la inregistrarea numelui!"), MB_OK, 0);  // a aparut o eroare
		}
	}
	RegCloseKey(myKey);  // inchidere registru
	RegCloseKey(HKEY_LOCAL_MACHINE);  // inchidere registru
}

void CregistersDlg::OnBnClickedButton2()
{
	CString Output;
	TCHAR nume[20];  // stocare nume
	DWORD dwType, dwVarsta, dwCati = sizeof (DWORD);
	RegOpenKeyEx(HKEY_LOCAL_MACHINE, L"STUDENT", 0, KEY_READ, &myKey);  // deschidere registru
	
	error = RegQueryValueEx(myKey, L"Varsta", NULL, &dwType,(LPBYTE) &dwVarsta, &dwCati);  // citire varsta din registru
	Output.Format(_T("%d"),dwVarsta);  // formatare text
	tb2.SetWindowTextW(Output);  // afisare varsta in caseta
	
	error = RegQueryValueEx(myKey, L"Nume", NULL, &dwType, NULL, &dwCati);  // citire lungime nume din registru
	error = RegQueryValueEx(myKey,L"Nume", NULL, &dwType, (LPBYTE) &nume, &dwCati);  // citire nume din registru
	tb1.SetWindowTextW(nume);  // afisare nume in caseta

	RegCloseKey(myKey);  // inchidere registru
	RegCloseKey(HKEY_LOCAL_MACHINE);  // inchidere registru
}

void CregistersDlg::OnBnClickedButton3()
{
	error = RegDeleteKey(HKEY_LOCAL_MACHINE, L"STUDENT");  // stergere registru
	if (error == ERROR_SUCCESS)  // verificare erori
	{
		AfxMessageBox(_T("Registrul a fost sters!"), MB_OK, 0);  // nu exista erori
	}
	else
	{
		AfxMessageBox(_T("Cheie inexistenta!!"), MB_OK, 0);  // a aparut o eroare
	}
}
