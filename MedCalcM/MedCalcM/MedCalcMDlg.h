
// MedCalcMDlg.h : ͷ�ļ�
//

#pragma once
#include "afxdtctl.h"


// CMedCalcMDlg �Ի���
class CMedCalcMDlg : public CDialogEx
{
// ����
public:
	CMedCalcMDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MEDCALCM_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	double m_dTotalRoomHours;
	int nMinChange;
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
	afx_msg void OnDeltaposSpin1(NMHDR *pNMHDR, LRESULT *pResult);
	void OnSpinChange(int nID, int nDelta);
	afx_msg void OnDeltaposSpin2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpin3(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpin4(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpin5(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpin6(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpin7(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpin8(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpin9(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpin10(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpin11(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpin12(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpin13(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpin14(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpin15(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpin16(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpin29(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpin30(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpin31(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpin17(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpin18(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpin19(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpin20(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpin21(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpin22(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpin23(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpin24(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpin25(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpin26(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpin27(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpin28(NMHDR *pNMHDR, LRESULT *pResult);
};
