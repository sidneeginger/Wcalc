
// MedCalcMDlg.h : 头文件
//

#pragma once
#include "afxdtctl.h"


// CMedCalcMDlg 对话框
class CMedCalcMDlg : public CDialogEx
{
// 构造
public:
	CMedCalcMDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MEDCALCM_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CDateTimeCtrl m_dtStart;
	CDateTimeCtrl m_dtEnd;
	afx_msg void OnDtnDatetimechangeDatetimepicker1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDtnDatetimechangeDatetimepicker2(NMHDR *pNMHDR, LRESULT *pResult);
	int CalcTime();
	int CleanAll();
	int CalcTotal(CTimeSpan &timeSpan);
};
