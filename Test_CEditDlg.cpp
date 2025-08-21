
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
	DDX_Control(pDX, IDC_CHECK_SHOW_SEARCH_BUTTON, m_check_show_search_button);
	DDX_Control(pDX, IDC_CHECK_ENABLE, m_check_enable);
	DDX_Control(pDX, IDC_EDIT6, m_edit6);
	DDX_Control(pDX, IDC_EDIT7, m_edit7);
	DDX_Control(pDX, IDC_EDIT8, m_edit8);
	DDX_Control(pDX, IDC_CHECK_BORDER, m_check_border);
	DDX_Control(pDX, IDC_EDIT_BORDER_WIDTH, m_edit_border_width);
	DDX_Control(pDX, IDC_SPIN_BORDER_WIDTH, m_spin_border_width);
	DDX_Control(pDX, IDC_BUTTON_BORDER_COLOR, m_button_border_color);
	//DDX_Control(pDX, IDC_COMBO_FONT, m_combo_font);
	DDX_Control(pDX, IDC_MFCFONTCOMBO, m_combo_font);
	DDX_Control(pDX, IDC_EDIT_FONT_SIZE, m_edit_font_size);
	DDX_Control(pDX, IDC_SPIN_FONT_SIZE, m_spin_font_size);
	DDX_Control(pDX, IDC_CHECK_READONLY, m_check_readonly);
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
	ON_BN_CLICKED(IDC_CHECK_SHOW_SEARCH_BUTTON, &CTest_CEditDlg::OnBnClickedCheckShowSearchButton)
	ON_BN_CLICKED(IDC_CHECK_ENABLE, &CTest_CEditDlg::OnBnClickedCheckEnable)
	ON_EN_CHANGE(IDC_EDIT1, &CTest_CEditDlg::OnEnChangeSCEdit)
	ON_BN_CLICKED(IDC_CHECK_BORDER, &CTest_CEditDlg::OnBnClickedCheckBorder)
	ON_BN_CLICKED(IDC_BUTTON_BORDER_COLOR, &CTest_CEditDlg::OnBnClickedButtonBorderColor)
	ON_WM_VSCROLL()
	ON_BN_CLICKED(IDC_RADIO_TOP, &CTest_CEditDlg::OnBnClickedRadioTop)
	ON_BN_CLICKED(IDC_RADIO_VCENTER, &CTest_CEditDlg::OnBnClickedRadioVcenter)
	ON_BN_CLICKED(IDC_RADIO_BOTTOM, &CTest_CEditDlg::OnBnClickedRadioBottom)
	ON_CBN_SELCHANGE(IDC_MFCFONTCOMBO, &CTest_CEditDlg::OnCbnSelchangeMfcFontCombo)
	ON_BN_CLICKED(IDC_CHECK_READONLY, &CTest_CEditDlg::OnBnClickedCheckReadOnly)
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
	m_resize.Create(this);
	m_resize.Add(IDC_RICH, 0, 0, 100, 100);
	m_resize.Add(IDOK, 100, 100, 0, 0);
	m_resize.Add(IDCANCEL, 100, 100, 0, 0);
	m_resize.Add(IDC_EDIT6, 0, 0, 100, 0);
	m_resize.Add(IDC_EDIT7, 100, 0, 0, 0);
	m_resize.Add(IDC_EDIT8, 0, 0, 100, 0);
	m_resize.Add(IDC_RADIO_ALIGN_LEFT, 0, 100, 0, 0);
	m_resize.Add(IDC_RADIO_ALIGN_CENTER, 0, 100, 0, 0);
	m_resize.Add(IDC_RADIO_ALIGN_RIGHT, 0, 100, 0, 0);
	//m_resize.Add(IDC_CHECK_SHOW_SEARCH_BUTTON, 100, 0, 0, 0);
	//m_resize.Add(IDC_CHECK_ENABLE, 100, 0, 0, 0);
	//m_resize.Add(IDC_EDIT1, 0, 0, 100, 0);

	//m_combo_font.Init();

	//GetProfileBinary()를 통해 값이 저장되는 변수는 정적변수가 아닌 포인터 변수로 선언해야 한다.
	//불러올 때 메모리를 할당받고 값이 채워진다. 모두 사용한 후 반드시 delete으로 release시켜야 한다.
	LOGFONT* lf;
	UINT lf_size = sizeof(LOGFONT);
	BOOL b = theApp.GetProfileBinary(_T("setting"), _T("log font"), reinterpret_cast<LPBYTE*>(&lf), &lf_size);
	//...
	delete lf;
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
	//m_edit_sc.SetWindowText(str);
	//m_edit_dim.SetWindowText(str);
	m_edit_trans.SetWindowText(str);
	//m_edit_rich.SetWindowText(str);

	m_edit_dim.SetDimText(_T("input text..."));

	CString font_name = AfxGetApp()->GetProfileString(_T("setting"), _T("font name"), _T("맑은 고딕"));
	m_combo_font.SelectFont(font_name);
	m_edit_sc.set_font_name(font_name);

	m_spin_font_size.SetRange(1, 50);
	int font_size = AfxGetApp()->GetProfileInt(_T("setting"), _T("font size"), 10);
	m_edit_sc.set_font_size(font_size);
	m_spin_font_size.SetPos(font_size);

	m_edit_sc.set_text(_T("Aaghq 한글123"));
	//m_edit_sc.set_auto_font_size(true, 0.65);
	m_edit_sc.set_text_color(gRGB(0, 0, 255));
	m_edit_sc.set_back_color(Gdiplus::Color::RoyalBlue);
	m_edit_sc.set_text_color_disabled(gRGB(128, 0, 0));
	m_edit_sc.set_back_color_disabled(gRGB(128, 128, 255));
	m_edit_sc.set_dim_text(_T("Enter here..."));


	m_check_enable.SetCheck(m_edit_sc.IsWindowEnabled() ? BST_CHECKED : BST_UNCHECKED);

	m_spin_border_width.SetRange(0, 15);
	bool draw_border = theApp.GetProfileInt(_T("setting"), _T("draw border"), m_edit_sc.get_draw_border());
	int border_width = theApp.GetProfileInt(_T("setting"), _T("border width"), m_edit_sc.get_border_width());
	Gdiplus::Color cr_border(theApp.GetProfileInt(_T("setting"), _T("border color"), m_edit_sc.get_border_color().GetValue()));
	m_edit_sc.set_draw_border(draw_border, border_width, cr_border);
	m_check_border.SetCheck(draw_border);
	m_edit_border_width.SetWindowText(i2S(border_width));
	m_spin_border_width.SetPos(border_width);
	m_button_border_color.SetColor(cr_border.ToCOLORREF());

	int valign = theApp.GetProfileInt(_T("setting"), _T("valign"), m_edit_sc.get_line_align());
	CheckDlgButton(IDC_RADIO_TOP, valign == DT_TOP);
	CheckDlgButton(IDC_RADIO_VCENTER, valign == DT_VCENTER);
	CheckDlgButton(IDC_RADIO_BOTTOM, valign == DT_BOTTOM);
	m_edit_sc.set_line_align(valign);

	m_edit6.set_text(_T("6test text"));
	m_edit7.set_text(_T("7test text"));
	m_edit8.set_text(_T("8test text"));
	//m_edit1.set_back_color(Gdiplus::Color::RosyBrown);
	//m_edit1.set_line_align(DT_VCENTER);

	m_edit_trans.SetBackColor(red);

	RestoreWindowPosition(&theApp, this);

	m_tooltip.Create(this, TTS_ALWAYSTIP);
	m_tooltip.AddTool(GetDlgItem(IDC_EDIT0), _T("asldfk"));
	m_tooltip.AddTool(GetDlgItem(IDOK), _T("OK Button"));
	m_tooltip.Activate(TRUE);

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
	//readonly일 때 배경색을 별도로 지정하는 테스트 코드
	m_edit_sc.set_back_color_readonly(gRGB(255, 255, 0));
	m_edit6.set_back_color_readonly(gRGB(255, 255, 0));

	//m_edit_sc.EnableWindow(m_edit_sc.IsWindowEnabled() ? false : true);
	//m_edit_trans.EnableWindow(m_edit_trans.IsWindowEnabled() ? false : true);

	return;

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

	theApp.WriteProfileInt(_T("setting"), _T("draw border"), m_edit_sc.get_draw_border());

	CDialogEx::OnCancel();
}


BOOL CTest_CEditDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (m_tooltip && m_tooltip.m_hWnd)
		m_tooltip.RelayEvent(pMsg);

	return CDialogEx::PreTranslateMessage(pMsg);
}


void CTest_CEditDlg::OnBnClickedCheckShowSearchButton()
{
	m_edit_sc.set_action_button(m_check_show_search_button.GetCheck() ? CSCEdit::action_find : 0);
}


void CTest_CEditDlg::OnBnClickedCheckEnable()
{
	m_edit_sc.EnableWindow(m_check_enable.GetCheck() == BST_CHECKED ? TRUE : FALSE);
	m_edit6.EnableWindow(m_check_enable.GetCheck() == BST_CHECKED ? TRUE : FALSE);
}


void CTest_CEditDlg::OnEnChangeSCEdit()
{
	CString text;
	m_edit_sc.GetWindowText(text);
	TRACE(_T("CTest_CEditDlg::OnEnChangeSCEdit(). text = %s\n"), text);
}

void CTest_CEditDlg::OnBnClickedCheckBorder()
{
	bool draw_border = (m_check_border.GetCheck() == BST_CHECKED);
	m_edit_sc.set_draw_border(draw_border);
}

void CTest_CEditDlg::OnBnClickedButtonBorderColor()
{
	COLORREF color = m_button_border_color.GetColor();
	Gdiplus::Color cr;

	cr.SetFromCOLORREF(color);
	theApp.WriteProfileInt(_T("setting"), _T("border color"), cr.GetValue());

	m_edit_sc.set_draw_border(true, -1, cr);
	m_check_border.SetCheck(BST_CHECKED);
}

void CTest_CEditDlg::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (pScrollBar == (CWnd*)&m_spin_border_width)
	{
		int pos = m_spin_border_width.GetPos();
		bool draw_border = (pos > 0);
		m_check_border.SetCheck(draw_border);
		m_edit_sc.set_draw_border(draw_border, pos);

		theApp.WriteProfileInt(_T("setting"), _T("draw border"), draw_border);
		theApp.WriteProfileInt(_T("setting"), _T("border width"), pos);
	}
	else if (pScrollBar == (CWnd*)&m_spin_font_size)
	{
		int pos = m_spin_font_size.GetPos();
		m_edit_sc.set_font_size(pos);

		theApp.WriteProfileInt(_T("setting"), _T("font size"), pos);
	}

	CDialogEx::OnVScroll(nSBCode, nPos, pScrollBar);
}

void CTest_CEditDlg::OnBnClickedRadioTop()
{
	m_edit_sc.set_line_align(DT_TOP);
	m_edit6.set_line_align(DT_TOP);
	theApp.WriteProfileInt(_T("setting"), _T("valign"), DT_TOP);
}

void CTest_CEditDlg::OnBnClickedRadioVcenter()
{
	m_edit_sc.set_line_align(DT_VCENTER);
	m_edit6.set_line_align(DT_VCENTER);
	theApp.WriteProfileInt(_T("setting"), _T("valign"), DT_VCENTER);
}

void CTest_CEditDlg::OnBnClickedRadioBottom()
{
	m_edit_sc.set_line_align(DT_BOTTOM);
	m_edit6.set_line_align(DT_BOTTOM);
	theApp.WriteProfileInt(_T("setting"), _T("valign"), DT_BOTTOM);
}

void CTest_CEditDlg::OnCbnSelchangeMfcFontCombo()
{
	CMFCFontInfo *fi = m_combo_font.GetSelFont();

	if (!fi)
		return;

	m_edit_sc.set_font_name(fi->m_strName);
	AfxGetApp()->WriteProfileString(_T("setting"), _T("font name"), fi->m_strName);
}


void CTest_CEditDlg::OnBnClickedCheckReadOnly()
{
	m_edit_sc.set_read_only(m_check_readonly.GetCheck() == BST_CHECKED);
	m_edit6.set_read_only(m_check_readonly.GetCheck() == BST_CHECKED);
}
