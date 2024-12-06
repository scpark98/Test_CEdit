
// Test_CEditDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Test_CEdit.h"
#include "Test_CEditDlg.h"
#include "afxdialogex.h"

#include "../../Common/Functions.h"

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
public:
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


// CTest_CEditDlg dialog



CTest_CEditDlg::CTest_CEditDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TEST_CEDIT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTest_CEditDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT0, m_edit_cedit);
	DDX_Control(pDX, IDC_EDIT1, m_edit_sc);
	DDX_Control(pDX, IDC_EDIT2, m_edit_dim);
	DDX_Control(pDX, IDC_EDIT3, m_edit_trans);
	DDX_Control(pDX, IDC_RICH, m_edit_rich);
}

BEGIN_MESSAGE_MAP(CTest_CEditDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CTest_CEditDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_RADIO_ALIGN_LEFT, &CTest_CEditDlg::OnBnClickedRadioAlignLeft)
	ON_BN_CLICKED(IDC_RADIO_ALIGN_CENTER, &CTest_CEditDlg::OnBnClickedRadioAlignCenter)
	ON_BN_CLICKED(IDC_RADIO_ALIGH_RIGHT, &CTest_CEditDlg::OnBnClickedRadioAlighRight)
	ON_WM_WINDOWPOSCHANGED()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDCANCEL, &CTest_CEditDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CTest_CEditDlg message handlers

BOOL CTest_CEditDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// TODO: Add extra initialization here
	LOGFONT* lf;
	UINT lf_size = sizeof(LOGFONT);
	BOOL b = theApp.GetProfileBinary(_T("setting"), _T("log font"), reinterpret_cast<LPBYTE*>(&lf), &lf_size);

	/*
	CRequestUrlParams params;
	//CompanyFunction::flag_control_lock
	params = CRequestUrlParams(_T("posbank.linkmemine.com"), 80, _T(""), _T("POST"));
	params.sub_url.Format(_T("/agent/api/v1.0/GetLmmDeviceDuplicateCheck"));
	params.body.Format(_T("{\"device_name\":\"%s\", \"company_fk\":\"%d\"}"), _T("KOIaNO-TESTPC"), 10);
	params.request_id = 0;
	params.use_thread = false;
	request_url(&params);
	TRACE(_T("status = %d, result = %s\n"), params.status, params.result);
	*/




	//edit의 height를 구하고 글꼴의 높이를 구해서
	//텍스트가 edit의 세로 중앙에 표시되도록 rect를 조정한다.
	//단, SetRect는 반드시 edit의 속성이 Multiline으로 되어 있어야만 적용된다.
	/*
	CRect r;
	m_edit_color.GetRect(&r);
	int fs = m_edit_color.get_font_size(true);
	int def = (r.Height() - fs) / 2 - 2;

	r.DeflateRect(0, def);
	m_edit_color.SetRect(&r);
	*/

	CString str = _T("동해물과 abcde ありがとう 雰囲気");
	m_edit_cedit.SetWindowText(str);
	m_edit_sc.SetWindowText(str);
	m_edit_dim.SetWindowText(str);
	m_edit_trans.SetWindowText(str);
	//m_edit_rich.SetWindowText(str);

	m_edit_dim.SetDimText(_T("input text..."));

	m_edit_sc
		//.set_auto_font_size(true, 0.5)
		.set_text_color(blue)
		.set_back_color(lightblue)
		.set_text_color_disabled(red)
		.set_back_color_disabled(violet);

	m_edit_sc.set_line_align(DT_VCENTER);


	m_edit_trans.SetBackColor(red);

	RestoreWindowPosition(&theApp, this);

	m_tooltip.Create(this, TTS_ALWAYSTIP);
	m_tooltip.AddTool(GetDlgItem(IDC_EDIT0), _T("asldfk"));
	m_tooltip.AddTool(GetDlgItem(IDOK), _T("OK Button"));
	m_tooltip.Activate(TRUE);

	//SetTimer(timer_auto_add, 100, NULL);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTest_CEditDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTest_CEditDlg::OnPaint()
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
HCURSOR CTest_CEditDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTest_CEditDlg::OnBnClickedOk()
{
	m_edit_sc.EnableWindow(m_edit_sc.IsWindowEnabled() ? false : true);
	m_edit_trans.EnableWindow(m_edit_trans.IsWindowEnabled() ? false : true);

	for (int i = 0; i < 1; i++)
	{
		//m_show_time = true일 때의 동작 형태. false일때는 예상대로 출력됨.
		//m_edit_rich.append(-1, _T("111"));		//첫 컬럼이면 시간찍고 111, 아니면 이어서 111
		//m_edit_rich.append(-1, _T("\n222"));	//한칸띠고 시간+222
		//m_edit_rich.append(-1, _T("333\n"));	//첫 컬럼이면 시간찍고 333\n, 아니면 이어서 333찍고 \n
		//m_edit_rich.append(-1, _T("\n444\n"));	//한칸띠고 시간+444\n
		m_edit_rich.add(blue, _T("test string\n"));

		//CString str = _T("CString variable\n");
		//m_edit_rich.append(red, str);
	}
}


void CTest_CEditDlg::OnBnClickedRadioAlignLeft()
{
	m_edit_rich.set_align(PFA_LEFT);
}

void CTest_CEditDlg::OnBnClickedRadioAlignCenter()
{
	m_edit_rich.set_align(PFA_CENTER);
}


void CTest_CEditDlg::OnBnClickedRadioAlighRight()
{
	m_edit_rich.set_align(PFA_RIGHT);
}


void CTest_CEditDlg::OnWindowPosChanged(WINDOWPOS* lpwndpos)
{
	CDialogEx::OnWindowPosChanged(lpwndpos);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	SaveWindowPosition(&theApp, this);
}


void CTest_CEditDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (nIDEvent == timer_auto_add)
		OnBnClickedOk();

	CDialogEx::OnTimer(nIDEvent);
}


void CTest_CEditDlg::OnBnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	LOGFONT lf;
	BOOL b = theApp.WriteProfileBinary(_T("setting"), _T("log font"), (LPBYTE)&lf, sizeof(LOGFONT));

	CDialogEx::OnCancel();
}


BOOL CTest_CEditDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (m_tooltip && m_tooltip.m_hWnd)
		m_tooltip.RelayEvent(pMsg);

	return CDialogEx::PreTranslateMessage(pMsg);
}
