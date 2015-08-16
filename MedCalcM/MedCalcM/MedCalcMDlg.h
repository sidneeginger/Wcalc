
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
private:
	double m_dTotalRoomHours;
public:
	CDateTimeCtrl m_dtStart;
	CDateTimeCtrl m_dtEnd;
	afx_msg void OnDtnDatetimechangeDatetimepicker1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDtnDatetimechangeDatetimepicker2(NMHDR *pNMHDR, LRESULT *pResult);
	int CalcTime();
	int CleanAll();
	int CalcTotal(CTimeSpan &timeSpan);
	CDateTimeCtrl m_dtpVentFrom;
	CDateTimeCtrl m_dtpVentTo;
	CDateTimeCtrl m_dtpArteryFrom;
	CDateTimeCtrl m_dtpArteryTo;
	CDateTimeCtrl m_dtpVeinFrom;
	CDateTimeCtrl m_dtpVeinTo;
	CDateTimeCtrl m_dtpGIDECFrom;
	CDateTimeCtrl m_dtpGIDECTo;
	CDateTimeCtrl m_dtpCVVTFrom;
	CDateTimeCtrl m_dtpCVVTTo;
	afx_msg void OnDtnDatetimechangeDtpVentFrom(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDtnDatetimechangeDtpVentTo(NMHDR *pNMHDR, LRESULT *pResult);
	void CalcVent();
	afx_msg void OnDtnDatetimechangeDtpArteryFrom(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDtnDatetimechangeDtpArteryTo(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDtnDatetimechangeDtpVeinFrom(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDtnDatetimechangeDtpVeinTo(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDtnDatetimechangeDtpGidecFrom(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDtnDatetimechangeDtpGidecTo(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDtnDatetimechangeDtpCvvtFrom(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDtnDatetimechangeDtpCvvtTo(NMHDR *pNMHDR, LRESULT *pResult);
	void CalcVein();
	void CalcArtery();
	void CalcGIDEC();
	void CalcCVVT();
};
