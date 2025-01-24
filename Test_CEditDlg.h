
// Test_CEditDlg.h : header file
//

#pragma once
#include "afxwin.h"

#include "../../Common/CEdit/SCEdit/SCEdit.h"
#include "../../Common/CEdit/DimEditCtrl/DimEditCtrl.h"
#include "../../Common/CEdit/EditTrans/EditTrans.h"
#include "../../Common/CEdit/RichEditCtrlEx/RichEditCtrlEx.h"

// CTest_CEditDlg dialog
class CTest_CEditDlg : public CDialogEx
{
// Construction
public:
	CTest_CEditDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TEST_CEDIT_DIALOG };
#endif

	enum TIMER
	{
		timer_auto_add = 0,
	};

protected:
	CToolTipCtrl	m_tooltip;

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
	CEdit m_edit_cedit;
	CSCEdit m_edit_sc;
	CDimEditCtrl m_edit_dim;
	CEditTrans m_edit_trans;
	CRichEditCtrlEx m_edit_rich;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedRadioAlignLeft();
	afx_msg void OnBnClickedRadioAlignCenter();
	afx_msg void OnBnClickedRadioAlighRight();
	afx_msg void OnWindowPosChanged(WINDOWPOS* lpwndpos);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedCancel();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CButton m_check_show_search_button;
	afx_msg void OnBnClickedCheckShowSearchButton();
};
