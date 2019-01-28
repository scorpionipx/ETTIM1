// zcDlg.cpp : implementation file
//

#include "stdafx.h"
#include "zc.h"
#include "zcDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CzcDlg dialog

CzcDlg::CzcDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CzcDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CzcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, eb1);
	DDX_Control(pDX, IDC_EDIT2, eb2);
	DDX_Control(pDX, IDC_CHECK2, cb2);
	DDX_Control(pDX, IDC_CHECK1, cb1);
	DDX_Control(pDX, IDC_PROGRESS1, pb);
}

BEGIN_MESSAGE_MAP(CzcDlg, CDialog)
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	ON_WM_SIZE()
#endif
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CzcDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CzcDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CzcDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_CHECK1, &CzcDlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_BUTTON4, &CzcDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CzcDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_CHECK2, &CzcDlg::OnBnClickedCheck2)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CzcDlg message handlers

BOOL CzcDlg::OnInitDialog()
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
void CzcDlg::OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/)
{
	if (AfxIsDRAEnabled())
	{
		DRA::RelayoutDialog(
			AfxGetResourceHandle(), 
			this->m_hWnd, 
			DRA::GetDisplayMode() != DRA::Portrait ? 
			MAKEINTRESOURCE(IDD_ZC_DIALOG_WIDE) : 
			MAKEINTRESOURCE(IDD_ZC_DIALOG));
	}
}
#endif

// se scriu numele functiilor definite de utilizator la inceputul fisierului pentru a fi visibile in tot codul
void load_pb_slow(void);
void load_pb_fast(void);

// declare obiect pentru sectiunea critica de cod
CRITICAL_SECTION hLock;

HANDLE thread_load_slow, thread_load_fast;

// declarare variabila pentru a stoca adresa elementului de tip progress bar
// deoarece elementul apartine clasei dialog, acesta nu va putea fi folosit in functiile declarate de
// utilizator decat prin intermediul adresei
CProgressCtrl * pb_adr;

// declarare variabile de stocare ale id-urilor celor doua fire de executie (thread-uri)
DWORD id_thread_slow, id_thread_fast;




// Btn Create
void CzcDlg::OnBnClickedButton1()
{
	// se creaza cele doua fire de executie ce vor manipula elemetul progress control
	thread_load_slow = CreateThread( NULL, 0, (LPTHREAD_START_ROUTINE) load_pb_slow, 0, CREATE_SUSPENDED, &id_thread_slow );
	thread_load_fast = CreateThread( NULL, 0, (LPTHREAD_START_ROUTINE) load_pb_fast, 0, CREATE_SUSPENDED, &id_thread_fast );

	// initializez element progress control
	pb.SetRange(0, 100);  // se seteaza valoarea minima 0 si valoarea maxima 100
    pb.SetStep(1);  // se seteaza pragul de incrementare 1 (folosit la apelarea functiei StepIt)
	pb.SetPos(0);  // se seteaza nivelul de incarcare initial la 0
	pb_adr = &pb;  // se stocheaza adresa elementului progress control in pointerul anterior definit 

	InitializeCriticalSection(&hLock);  // initializare zona critica de cod


}

// Btn Start
void CzcDlg::OnBnClickedButton2()
{
	ResumeThread(thread_load_slow);  // se porneste firul de executie responsabil cu incarcarea pb in mod lent
	ResumeThread(thread_load_fast);  // se porneste firul de executie responsabil cu incarcarea pb in mod rapid
}

// Btn Free
void CzcDlg::OnBnClickedButton3()
{
	// se opresc cele doua fire de executie
	CloseHandle(thread_load_slow);  // se libereaza resursele alocate firului de executie responsabil cu incarcarea lenta a pb
	CloseHandle(thread_load_fast);  // se libereaza resursele alocate firului de executie responsabil cu incarcarea rapida a pb
}

// CB stop slow thread
void CzcDlg::OnBnClickedCheck1()
{
	if (cb1.GetCheck())  // verificare stare check box
	{
		// check box-ul este bifat
		SuspendThread(thread_load_slow);  // se suspenda firul de executie responsabil cu incarcarea lenta a pb
	}
	else
	{
		// check box-ul nu este bifat
		ResumeThread(thread_load_slow);  // se reporneste firul de executie responsabil cu incarcarea lenta a pb
	}
}

// Btn show quantum
void CzcDlg::OnBnClickedButton4()
{
	CString text;  // declarare variabila pentru stocare text
	int thread_slow_quantum;  // declarare variabila pentru stocarea quantumului firului de executie
	thread_slow_quantum = CeGetThreadQuantum(thread_load_slow);  // citire quantum fir de executie
	text.Format(_T("%d"), thread_slow_quantum);  // transformarea valorii quantumului in text
	eb1.SetWindowTextW(text);  // afisare text pe elementul edit control
}

// Btn show priority
void CzcDlg::OnBnClickedButton5()
{
	CString text;  // declarare variabila pentru stocare text
	int thread_slow_priority;  // declarare variabila pentru stocarea prioritatii firului de executie
	thread_slow_priority = CeGetThreadPriority(thread_load_slow);  // citire prioritate fir de executie
	text.Format(_T("%d"), thread_slow_priority);  // transformarea valorii firului de executie in text
	eb2.SetWindowTextW(text);  // afisare text pe elementul edit control
}

// CB UP
void CzcDlg::OnBnClickedCheck2()
{
	if (cb2.GetCheck())  // verificare stare check box
	{
		// check box-ul este bifat
		CeSetThreadPriority (thread_load_slow, 250);  // se creste prioritatea firului de executie
		// un numar mai mic inseamna o prioritate mai mare
	}
	else
	{
		// check box-ul nu este bifat
		CeSetThreadPriority (thread_load_slow, 251);  // se scade prioritatea firului de executie
		// un numar mai mare inseamna o prioritate mai mica
	}
}

// functie pentru incarcare progress control in mod lent
void load_pb_slow(void)
{
	int slow_cnt = 0;  // contor pentru a numara de cate ori se incarca pb in modul lent

	do{
		EnterCriticalSection(&hLock);  // se intra in zona critica de cod <=> se blocheaza accesul altor fire de executie la resursa pb
		for (int i=0; i<100; i++)  // se incarca pb de 100 de ori cu o unitate, aspteptand dupa fiecare incrementare 30 ms => total time de incarcare 3 secunde
		{
			pb_adr->StepIt();  // se incarca pb cu o unitate
			Sleep(30);  // se asteapta 30 milisecunde
		}
		LeaveCriticalSection(&hLock);  // se iese din zona critica de cod <=> se deblocheaza accesul altor fire de executie la resursa pb
		slow_cnt ++;  // incrementare contor
	} while(slow_cnt < 5);  // verificare contor
}


// functie pentru incarcare progress control in mod rapid
void load_pb_fast(void)
{
	int fast_cnt = 0;  // contor pentru a numara de cate ori se incarca pb in modul rapid

	do{
		EnterCriticalSection(&hLock);  // se intra in zona critica de cod <=> se blocheaza accesul altor fire de executie la resursa pb
		for (int i=0; i<100; i++)  // se incarca pb de 100 de ori cu o unitate, aspteptand dupa fiecare incrementare 10 ms => total time de incarcare 1 secunda
		{
			pb_adr->StepIt();  // se incarca pb cu o unitate
			Sleep(10);  // se asteapta 10 milisecunde
		}
		LeaveCriticalSection(&hLock);  // se iese din zona critica de cod <=> se deblocheaza accesul altor fire de executie la resursa pb
		fast_cnt ++;  // incrementare contor
	} while(fast_cnt < 5);  // verificare contor
}
void CzcDlg::OnDestroy()
{
	CDialog::OnDestroy();
	// se opresc cele doua fire de executie
	CloseHandle(thread_load_slow);  // se libereaza resursele alocate firului de executie responsabil cu incarcarea lenta a pb
	CloseHandle(thread_load_fast);  // se libereaza resursele alocate firului de executie responsabil cu incarcarea rapida a pb
}
