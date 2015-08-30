
// MedCalcSView.cpp : CMedCalcSView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MedCalcS.h"
#endif

#include "MedCalcSDoc.h"
#include "MedCalcSView.h"
#include <locale> 

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMedCalcSView

IMPLEMENT_DYNCREATE(CMedCalcSView, CFormView)

BEGIN_MESSAGE_MAP(CMedCalcSView, CFormView)
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DATETIMEPICKER1, &CMedCalcSView::OnDtnDatetimechangeDatetimepicker1)
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DATETIMEPICKER2, &CMedCalcSView::OnDtnDatetimechangeDatetimepicker2)
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DTP_VENT_FROM, &CMedCalcSView::OnDtnDatetimechangeDtpVentFrom)
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DTP_VENT_TO, &CMedCalcSView::OnDtnDatetimechangeDtpVentTo)
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DTP_ARTERY_FROM, &CMedCalcSView::OnDtnDatetimechangeDtpArteryFrom)
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DTP_ARTERY_TO, &CMedCalcSView::OnDtnDatetimechangeDtpArteryTo)
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DTP_VEIN_FROM, &CMedCalcSView::OnDtnDatetimechangeDtpVeinFrom)
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DTP_VEIN_TO, &CMedCalcSView::OnDtnDatetimechangeDtpVeinTo)
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DTP_GIDEC_FROM, &CMedCalcSView::OnDtnDatetimechangeDtpGidecFrom)
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DTP_GIDEC_TO, &CMedCalcSView::OnDtnDatetimechangeDtpGidecTo)
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DTP_CVVT_FROM, &CMedCalcSView::OnDtnDatetimechangeDtpCvvtFrom)
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DTP_CVVT_TO, &CMedCalcSView::OnDtnDatetimechangeDtpCvvtTo)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN1, &CMedCalcSView::OnDeltaposSpin1)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN2, &CMedCalcSView::OnDeltaposSpin2)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN3, &CMedCalcSView::OnDeltaposSpin3)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN4, &CMedCalcSView::OnDeltaposSpin4)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN5, &CMedCalcSView::OnDeltaposSpin5)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN6, &CMedCalcSView::OnDeltaposSpin6)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN7, &CMedCalcSView::OnDeltaposSpin7)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN8, &CMedCalcSView::OnDeltaposSpin8)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN9, &CMedCalcSView::OnDeltaposSpin9)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN10, &CMedCalcSView::OnDeltaposSpin10)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN11, &CMedCalcSView::OnDeltaposSpin11)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN12, &CMedCalcSView::OnDeltaposSpin12)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN13, &CMedCalcSView::OnDeltaposSpin13)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN14, &CMedCalcSView::OnDeltaposSpin14)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN15, &CMedCalcSView::OnDeltaposSpin15)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN16, &CMedCalcSView::OnDeltaposSpin16)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN29, &CMedCalcSView::OnDeltaposSpin29)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN30, &CMedCalcSView::OnDeltaposSpin30)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN31, &CMedCalcSView::OnDeltaposSpin31)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN17, &CMedCalcSView::OnDeltaposSpin17)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN18, &CMedCalcSView::OnDeltaposSpin18)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN19, &CMedCalcSView::OnDeltaposSpin19)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN20, &CMedCalcSView::OnDeltaposSpin20)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN21, &CMedCalcSView::OnDeltaposSpin21)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN22, &CMedCalcSView::OnDeltaposSpin22)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN23, &CMedCalcSView::OnDeltaposSpin23)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN24, &CMedCalcSView::OnDeltaposSpin24)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN25, &CMedCalcSView::OnDeltaposSpin25)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN26, &CMedCalcSView::OnDeltaposSpin26)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN27, &CMedCalcSView::OnDeltaposSpin27)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN28, &CMedCalcSView::OnDeltaposSpin28)
	ON_COMMAND(ID_FILE_SAVE, &CMedCalcSView::OnFileSave)
END_MESSAGE_MAP()

// CMedCalcSView 构造/析构

CMedCalcSView::CMedCalcSView()
	: CFormView(IDD_MEDCALCS_FORM)
{
	// TODO: 在此处添加构造代码
	m_dTotalRoomHours = 0.0;
	nMinChange = 0;

}

CMedCalcSView::~CMedCalcSView()
{
}

void CMedCalcSView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DATETIMEPICKER1, m_dtStart);
	DDX_Control(pDX, IDC_DATETIMEPICKER2, m_dtEnd);
	DDX_Control(pDX, IDC_DTP_VENT_FROM, m_dtpVentFrom);
	DDX_Control(pDX, IDC_DTP_VENT_TO, m_dtpVentTo);
	DDX_Control(pDX, IDC_DTP_ARTERY_FROM, m_dtpArteryFrom);
	DDX_Control(pDX, IDC_DTP_ARTERY_TO, m_dtpArteryTo);
	DDX_Control(pDX, IDC_DTP_VEIN_FROM, m_dtpVeinFrom);
	DDX_Control(pDX, IDC_DTP_VEIN_TO, m_dtpVeinTo);
	DDX_Control(pDX, IDC_DTP_GIDEC_FROM, m_dtpGIDECFrom);
	DDX_Control(pDX, IDC_DTP_GIDEC_TO, m_dtpGIDECTo);
	DDX_Control(pDX, IDC_DTP_CVVT_FROM, m_dtpCVVTFrom);
	DDX_Control(pDX, IDC_DTP_CVVT_TO, m_dtpCVVTTo);
}

BOOL CMedCalcSView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CFormView::PreCreateWindow(cs);
}

void CMedCalcSView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	m_dtStart.SetFormat(_T("yyyy-MM-dd HH:mm:ss"));
	m_dtEnd.SetFormat(_T("yyyy-MM-dd HH:mm:ss"));
	m_dtpArteryFrom.SetFormat(_T("yyyy-MM-dd HH:mm:ss"));
	m_dtpArteryTo.SetFormat(_T("yyyy-MM-dd HH:mm:ss"));
	m_dtpVentFrom.SetFormat(_T("yyyy-MM-dd HH:mm:ss"));
	m_dtpVentTo.SetFormat(_T("yyyy-MM-dd HH:mm:ss"));
	m_dtpVeinFrom.SetFormat(_T("yyyy-MM-dd HH:mm:ss"));
	m_dtpVeinTo.SetFormat(_T("yyyy-MM-dd HH:mm:ss"));
	m_dtpGIDECFrom.SetFormat(_T("yyyy-MM-dd HH:mm:ss"));
	m_dtpGIDECTo.SetFormat(_T("yyyy-MM-dd HH:mm:ss"));
	m_dtpCVVTFrom.SetFormat(_T("yyyy-MM-dd HH:mm:ss"));
	m_dtpCVVTTo.SetFormat(_T("yyyy-MM-dd HH:mm:ss"));
}


// CMedCalcSView 诊断

#ifdef _DEBUG
void CMedCalcSView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMedCalcSView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMedCalcSDoc* CMedCalcSView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMedCalcSDoc)));
	return (CMedCalcSDoc*)m_pDocument;
}
#endif //_DEBUG


// CMedCalcSView 消息处理程序


void CMedCalcSView::OnDtnDatetimechangeDatetimepicker1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	CalcTime();
	*pResult = 0;
}


void CMedCalcSView::OnDtnDatetimechangeDatetimepicker2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	CalcTime();
	*pResult = 0;
}


int CMedCalcSView::CalcTime()
{
	CTime tStart;
	m_dtStart.GetTime(tStart);
	CTime tEnd;
	m_dtEnd.GetTime(tEnd);

	if (tEnd <= tStart)
	{
		//SetDlgItemText(IDC_TXT_NOTE, _T("注意：结束时间要大于开始时间！"));
		AfxMessageBox(_T("结束时间要大于开始时间！"));
		CleanAll();
	}
	else
	{
		auto tDiff = tEnd - tStart;
		CalcTotal(tDiff);
		//SetDlgItemText(IDC_TXT_NOTE, _T(""));
	}

	return 0;
}


void CMedCalcSView::OnDtnDatetimechangeDtpVentFrom(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	CalcVent();
	*pResult = 0;
}


void CMedCalcSView::OnDtnDatetimechangeDtpVentTo(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	CalcVein();
	*pResult = 0;
}


void CMedCalcSView::OnDtnDatetimechangeDtpArteryFrom(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	CalcArtery();
	*pResult = 0;
}


void CMedCalcSView::OnDtnDatetimechangeDtpArteryTo(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	CalcArtery();
	*pResult = 0;
}


void CMedCalcSView::OnDtnDatetimechangeDtpVeinFrom(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	CalcVein();
	*pResult = 0;
}


void CMedCalcSView::OnDtnDatetimechangeDtpVeinTo(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	CalcVein();
	*pResult = 0;
}


void CMedCalcSView::OnDtnDatetimechangeDtpGidecFrom(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	CalcGIDEC();
	*pResult = 0;
}


void CMedCalcSView::OnDtnDatetimechangeDtpGidecTo(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	CalcGIDEC();
	*pResult = 0;
}


void CMedCalcSView::OnDtnDatetimechangeDtpCvvtFrom(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	CalcCVVT();
	*pResult = 0;
}


void CMedCalcSView::OnDtnDatetimechangeDtpCvvtTo(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	CalcCVVT();
	*pResult = 0;
}


int CMedCalcSView::CleanAll()
{
	return 0;
}

int CMedCalcSView::CalcTotal(CTimeSpan &timeSpan)
{
	auto nTotalMins = timeSpan.GetTotalMinutes();
	double dTotalHours = (double)nTotalMins / 60.0;
	m_dTotalRoomHours = dTotalHours;

	CString strTemp;
	strTemp.Format(_T("%.2f"), dTotalHours);
	SetDlgItemText(IDC_EDIT_TotalHours, strTemp);

	strTemp.Format(_T("%.2f"), dTotalHours / 24.0);
	SetDlgItemText(IDC_EDIT_TotalDays, strTemp);

	strTemp.Format(_T("%.2f"), dTotalHours / 24.0);
	SetDlgItemText(IDC_EDIT_ICU, strTemp);

	strTemp.Format(_T("%.2f"), dTotalHours / 24.0);
	SetDlgItemText(IDC_EDIT_SpongeBath, strTemp);

	strTemp.Format(_T("%.2f"), dTotalHours / 6.0);
	SetDlgItemText(IDC_EDIT_Mouth, strTemp);

	strTemp.Format(_T("%.2f"), dTotalHours / 24.0);
	SetDlgItemText(IDC_EDIT_AirBed, strTemp);

	strTemp.Format(_T("%.2f"), dTotalHours / 24.0);
	SetDlgItemText(IDC_EDIT_ECG, strTemp);

	strTemp.Format(_T("%.2f"), dTotalHours);
	SetDlgItemText(IDC_EDIT_ECGM, strTemp);

	strTemp.Format(_T("%.2f"), dTotalHours / 3.0);
	SetDlgItemText(IDC_EDIT_Glycemic, strTemp);

	return 0;
}


void CMedCalcSView::CalcVent()
{
	CTime tStart;
	m_dtpVentFrom.GetTime(tStart);
	CTime tEnd;
	m_dtpVentTo.GetTime(tEnd);

	if (tEnd <= tStart)
	{
		//SetDlgItemText(IDC_TXT_NOTE, _T("注意：结束时间要大于开始时间！"));
		AfxMessageBox(_T("结束时间要大于开始时间！"));
		CString strNull = _T("");
		SetDlgItemText(IDC_EDIT_TotalVent, strNull);
		SetDlgItemText(IDC_EDIT_OxyNormal, strNull);
		SetDlgItemText(IDC_EDIT_Mist, strNull);
	}
	else
	{
		auto tDiff = tEnd - tStart;

		auto nTotalMins = tDiff.GetTotalMinutes();
		double dTotalHours = (double)nTotalMins / 60.0;

		CString strTemp;
		strTemp.Format(_T("%.2f"), dTotalHours);
		SetDlgItemText(IDC_EDIT_TotalVent, strTemp);

		strTemp.Format(_T("%.2f"), m_dTotalRoomHours - dTotalHours);
		SetDlgItemText(IDC_EDIT_OxyNormal, strTemp);

		strTemp.Format(_T("%.2f"), (m_dTotalRoomHours - dTotalHours) / 4);
		SetDlgItemText(IDC_EDIT_Mist, strTemp);
	}
}


void CMedCalcSView::CalcVein()
{
	CTime tStart;
	m_dtpVeinFrom.GetTime(tStart);
	CTime tEnd;
	m_dtpVeinTo.GetTime(tEnd);

	if (tEnd <= tStart)
	{
		//SetDlgItemText(IDC_TXT_NOTE, _T("注意：结束时间要大于开始时间！"));
		AfxMessageBox(_T("结束时间要大于开始时间！"));
		CString strNull = _T("");
		SetDlgItemText(IDC_EDIT_TotalVein, strNull);
	}
	else
	{
		auto tDiff = tEnd - tStart;

		auto nTotalMins = tDiff.GetTotalMinutes();
		double dTotalHours = (double)nTotalMins / 60.0;

		CString strTemp;
		strTemp.Format(_T("%.2f"), dTotalHours);
		SetDlgItemText(IDC_EDIT_TotalVein, strTemp);
	}
}


void CMedCalcSView::CalcArtery()
{
	CTime tStart;
	m_dtpArteryFrom.GetTime(tStart);
	CTime tEnd;
	m_dtpArteryTo.GetTime(tEnd);

	if (tEnd <= tStart)
	{
		//SetDlgItemText(IDC_TXT_NOTE, _T("注意：结束时间要大于开始时间！"));
		AfxMessageBox(_T("结束时间要大于开始时间！"));
		CString strNull = _T("");
		SetDlgItemText(IDC_EDIT_TotalArtery, strNull);
	}
	else
	{
		auto tDiff = tEnd - tStart;

		auto nTotalMins = tDiff.GetTotalMinutes();
		double dTotalHours = (double)nTotalMins / 60.0;

		CString strTemp;
		strTemp.Format(_T("%.2f"), dTotalHours);
		SetDlgItemText(IDC_EDIT_TotalArtery, strTemp);
	}
}


void CMedCalcSView::CalcGIDEC()
{
	CTime tStart;
	m_dtpGIDECFrom.GetTime(tStart);
	CTime tEnd;
	m_dtpGIDECTo.GetTime(tEnd);

	if (tEnd <= tStart)
	{
		//SetDlgItemText(IDC_TXT_NOTE, _T("注意：结束时间要大于开始时间！"));
		AfxMessageBox(_T("结束时间要大于开始时间！"));
		CString strNull = _T("");
		SetDlgItemText(IDC_EDIT_TotalGIDEC, strNull);
		SetDlgItemText(IDC_EDIT_TotalGIDECDay, strNull);
		SetDlgItemText(IDC_EDIT_NoseInject, strNull);
		SetDlgItemText(IDC_EDIT_NosePump, strNull);
	}
	else
	{
		auto tDiff = tEnd - tStart;

		auto nTotalMins = tDiff.GetTotalMinutes();
		double dTotalHours = (double)nTotalMins / 60.0;

		CString strTemp;
		strTemp.Format(_T("%.2f"), dTotalHours);
		SetDlgItemText(IDC_EDIT_TotalGIDEC, strTemp);

		strTemp.Format(_T("%.2f"), dTotalHours / 24.0);
		SetDlgItemText(IDC_EDIT_TotalGIDECDay, strTemp);

		strTemp.Format(_T("%.2f"), (m_dTotalRoomHours - dTotalHours) / 24.0);
		SetDlgItemText(IDC_EDIT_NoseInject, strTemp);

		strTemp.Format(_T("%.2f"), m_dTotalRoomHours - dTotalHours);
		SetDlgItemText(IDC_EDIT_NosePump, strTemp);
	}
}


void CMedCalcSView::CalcCVVT()
{
	CTime tStart;
	m_dtpCVVTFrom.GetTime(tStart);
	CTime tEnd;
	m_dtpCVVTTo.GetTime(tEnd);

	if (tEnd <= tStart)
	{
		//SetDlgItemText(IDC_TXT_NOTE, _T("注意：结束时间要大于开始时间！"));
		AfxMessageBox(_T("结束时间要大于开始时间！"));
		CString strNull = _T("");
		SetDlgItemText(IDC_EDIT_TotalCVVT, strNull);
	}
	else
	{
		auto tDiff = tEnd - tStart;

		auto nTotalMins = tDiff.GetTotalMinutes();
		double dTotalHours = (double)nTotalMins / 60.0;

		CString strTemp;
		strTemp.Format(_T("%.2f"), dTotalHours);
		SetDlgItemText(IDC_EDIT_TotalCVVT, strTemp);
	}
}

void CMedCalcSView::OnSpinChange(int nID, int nDelta)
{
	CString str;
	GetDlgItemText(nID, str);
	int n = _wtoi(str);
	if (nDelta == 1)
	{
		n--;
		if (n <= 0)
		{
			n = 0;
		}
	}
	else if (nDelta == -1)
	{
		n++;
	}

	str.Format(_T("%d"), n);
	SetDlgItemText(nID, str);
}


void CMedCalcSView::OnDeltaposSpin1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	OnSpinChange(IDC_EDIT2, pNMUpDown->iDelta);
	*pResult = 0;
}


void CMedCalcSView::OnDeltaposSpin2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	OnSpinChange(IDC_EDIT3, pNMUpDown->iDelta);
	*pResult = 0;
}


void CMedCalcSView::OnDeltaposSpin3(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	OnSpinChange(IDC_EDIT4, pNMUpDown->iDelta);
	*pResult = 0;
}


void CMedCalcSView::OnDeltaposSpin4(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	OnSpinChange(IDC_EDIT5, pNMUpDown->iDelta);
	*pResult = 0;
}


void CMedCalcSView::OnDeltaposSpin5(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	OnSpinChange(IDC_EDIT6, pNMUpDown->iDelta);
	*pResult = 0;
}


void CMedCalcSView::OnDeltaposSpin6(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	OnSpinChange(IDC_EDIT7, pNMUpDown->iDelta);
	*pResult = 0;
}


void CMedCalcSView::OnDeltaposSpin7(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	OnSpinChange(IDC_EDIT8, pNMUpDown->iDelta);
	*pResult = 0;
}


void CMedCalcSView::OnDeltaposSpin8(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	OnSpinChange(IDC_EDIT9, pNMUpDown->iDelta);
	*pResult = 0;
}


void CMedCalcSView::OnDeltaposSpin9(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	OnSpinChange(IDC_EDIT10, pNMUpDown->iDelta);
	*pResult = 0;
}


void CMedCalcSView::OnDeltaposSpin10(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	OnSpinChange(IDC_EDIT11, pNMUpDown->iDelta);
	*pResult = 0;
}


void CMedCalcSView::OnDeltaposSpin11(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	OnSpinChange(IDC_EDIT12, pNMUpDown->iDelta);
	*pResult = 0;
}


void CMedCalcSView::OnDeltaposSpin12(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	OnSpinChange(IDC_EDIT13, pNMUpDown->iDelta);
	*pResult = 0;
}


void CMedCalcSView::OnDeltaposSpin13(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	OnSpinChange(IDC_EDIT14, pNMUpDown->iDelta);
	*pResult = 0;
}


void CMedCalcSView::OnDeltaposSpin14(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	OnSpinChange(IDC_EDIT15, pNMUpDown->iDelta);
	*pResult = 0;
}


void CMedCalcSView::OnDeltaposSpin15(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	OnSpinChange(IDC_EDIT16, pNMUpDown->iDelta);
	*pResult = 0;
}


void CMedCalcSView::OnDeltaposSpin16(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	OnSpinChange(IDC_EDIT17, pNMUpDown->iDelta);
	*pResult = 0;
}


void CMedCalcSView::OnDeltaposSpin29(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	OnSpinChange(IDC_EDIT30, pNMUpDown->iDelta);
	*pResult = 0;
}


void CMedCalcSView::OnDeltaposSpin30(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	OnSpinChange(IDC_EDIT31, pNMUpDown->iDelta);
	*pResult = 0;
}


void CMedCalcSView::OnDeltaposSpin31(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	OnSpinChange(IDC_EDIT32, pNMUpDown->iDelta);
	*pResult = 0;
}


void CMedCalcSView::OnDeltaposSpin17(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	OnSpinChange(IDC_EDIT18, pNMUpDown->iDelta);
	*pResult = 0;
}


void CMedCalcSView::OnDeltaposSpin18(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	OnSpinChange(IDC_EDIT19, pNMUpDown->iDelta);
	*pResult = 0;
}


void CMedCalcSView::OnDeltaposSpin19(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	OnSpinChange(IDC_EDIT20, pNMUpDown->iDelta);
	*pResult = 0;
}


void CMedCalcSView::OnDeltaposSpin20(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	OnSpinChange(IDC_EDIT21, pNMUpDown->iDelta);
	*pResult = 0;
}


void CMedCalcSView::OnDeltaposSpin21(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	OnSpinChange(IDC_EDIT22, pNMUpDown->iDelta);
	*pResult = 0;
}


void CMedCalcSView::OnDeltaposSpin22(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	OnSpinChange(IDC_EDIT23, pNMUpDown->iDelta);
	*pResult = 0;
}


void CMedCalcSView::OnDeltaposSpin23(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	OnSpinChange(IDC_EDIT24, pNMUpDown->iDelta);
	*pResult = 0;
}


void CMedCalcSView::OnDeltaposSpin24(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	OnSpinChange(IDC_EDIT25, pNMUpDown->iDelta);
	*pResult = 0;
}


void CMedCalcSView::OnDeltaposSpin25(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	OnSpinChange(IDC_EDIT26, pNMUpDown->iDelta);
	*pResult = 0;
}


void CMedCalcSView::OnDeltaposSpin26(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	OnSpinChange(IDC_EDIT27, pNMUpDown->iDelta);
	*pResult = 0;
}


void CMedCalcSView::OnDeltaposSpin27(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	OnSpinChange(IDC_EDIT28, pNMUpDown->iDelta);
	*pResult = 0;
}


void CMedCalcSView::OnDeltaposSpin28(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	OnSpinChange(IDC_EDIT29, pNMUpDown->iDelta);
	*pResult = 0;
}


CString CMedCalcSView::GetCtrlText(int nID)
{
	CString str;
	GetDlgItemText(nID, str);
	return str;
}


void CMedCalcSView::OnFileSave()
{
	LPCTSTR lpszFilter = _T("TXT Files(*.txt)|*.txt|任何文件|*.*|");
	CString  filename;
	CFileDialog dlg(FALSE, lpszFilter, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, lpszFilter, NULL);
	dlg.DoModal();
	filename = dlg.GetFileName();

	if (filename.GetLength() <= 0)
	{
		//AfxMessageBox(_T("未保存"));
		return;
	}

	// save
	CString strFullName = dlg.GetFolderPath();
	strFullName += _T("\\");
	strFullName += filename;

	CStdioFile fReport;
	fReport.Open(strFullName, CFile::modeReadWrite | CFile::modeCreate | CFile::typeText);
	setlocale(LC_CTYPE, "chs");
	CString strTmp;

	strTmp = _T("入科时间 ");
	strTmp += GetCtrlText(IDC_DATETIMEPICKER1);
	strTmp += _T(" 至 ");
	strTmp += GetCtrlText(IDC_DATETIMEPICKER2);
	strTmp += _T("\t共 ");
	strTmp += GetCtrlText(IDC_EDIT_TotalHours);
	strTmp += _T("小时 ");
	strTmp += GetCtrlText(IDC_EDIT_TotalDays);
	strTmp += _T("日");
	fReport.WriteString(strTmp + _T("\r\n"));

	strTmp = _T("重症 ");
	strTmp += GetCtrlText(IDC_EDIT_ICU);
	strTmp += _T("\t擦浴 ");
	strTmp += GetCtrlText(IDC_EDIT_SpongeBath);
	strTmp += _T("\t口会护 ");
	strTmp += GetCtrlText(IDC_EDIT_Mouth);
	strTmp += _T("\t气垫床 ");
	strTmp += GetCtrlText(IDC_EDIT_AirBed);
	fReport.WriteString(strTmp + _T("\r\n"));

	strTmp = _T("心电图 ");
	strTmp += GetCtrlText(IDC_EDIT_ECG);
	strTmp += _T("\t心电监测 ");
	strTmp += GetCtrlText(IDC_EDIT_ECGM);
	strTmp += _T("\t血糖 ");
	strTmp += GetCtrlText(IDC_EDIT_Glycemic);
	fReport.WriteString(strTmp + _T("\r\n"));
	fReport.WriteString(_T("\r\n"));

	strTmp = _T("呼吸机时间 ");
	strTmp += GetCtrlText(IDC_DTP_VENT_FROM);
	strTmp += _T(" 至 ");
	strTmp += GetCtrlText(IDC_DTP_VENT_TO);
	strTmp += _T("\t共 ");
	strTmp += GetCtrlText(IDC_EDIT_TotalVent);
	strTmp += _T("小时 ");
	fReport.WriteString(strTmp + _T("\r\n"));

	strTmp = _T("正常加压吸氧 ");
	strTmp += GetCtrlText(IDC_EDIT_OxyNormal);
	strTmp += _T("\t雾化吸入 ");
	strTmp += GetCtrlText(IDC_EDIT_Mist);
	fReport.WriteString(strTmp + _T("\r\n"));
	fReport.WriteString(_T("\r\n"));

	strTmp = _T("动脉监测时间 ");
	strTmp += GetCtrlText(IDC_DTP_ARTERY_FROM);
	strTmp += _T(" 至 ");
	strTmp += GetCtrlText(IDC_DTP_ARTERY_TO);
	strTmp += _T("\t共 ");
	strTmp += GetCtrlText(IDC_EDIT_TotalArtery);
	strTmp += _T("小时 ");
	fReport.WriteString(strTmp + _T("\r\n"));

	strTmp = _T("静脉监测时间 ");
	strTmp += GetCtrlText(IDC_DTP_VEIN_FROM);
	strTmp += _T(" 至 ");
	strTmp += GetCtrlText(IDC_DTP_VEIN_TO);
	strTmp += _T("\t共 ");
	strTmp += GetCtrlText(IDC_EDIT_TotalVein);
	strTmp += _T("小时 ");
	fReport.WriteString(strTmp + _T("\r\n"));
	fReport.WriteString(_T("\r\n"));

	strTmp = _T("胃肠减压时间 ");
	strTmp += GetCtrlText(IDC_DTP_GIDEC_FROM);
	strTmp += _T(" 至 ");
	strTmp += GetCtrlText(IDC_DTP_GIDEC_TO);
	strTmp += _T("\t共 ");
	strTmp += GetCtrlText(IDC_EDIT_TotalGIDEC);
	strTmp += _T("小时 ");
	strTmp += GetCtrlText(IDC_EDIT_TotalGIDECDay);
	strTmp += _T("日");
	fReport.WriteString(strTmp + _T("\r\n"));

	strTmp = _T("鼻饲注食 ");
	strTmp += GetCtrlText(IDC_EDIT_NoseInject);
	strTmp += _T("\t鼻饲泵 ");
	strTmp += GetCtrlText(IDC_EDIT_NosePump);
	fReport.WriteString(strTmp + _T("\r\n"));
	fReport.WriteString(_T("\r\n"));

	strTmp = _T("血滤 ");
	strTmp += GetCtrlText(IDC_DTP_CVVT_FROM);
	strTmp += _T(" 至 ");
	strTmp += GetCtrlText(IDC_DTP_CVVT_TO);
	strTmp += _T("\t共 ");
	strTmp += GetCtrlText(IDC_EDIT_TotalCVVT);
	strTmp += _T("小时 ");
	fReport.WriteString(strTmp + _T("\r\n"));
	fReport.WriteString(_T("\r\n"));

	strTmp = _T("小换药 ");
	strTmp += GetCtrlText(IDC_EDIT2);
	strTmp += _T("\t中换药 ");
	strTmp += GetCtrlText(IDC_EDIT3);
	strTmp += _T("\t大换药 ");
	strTmp += GetCtrlText(IDC_EDIT4);
	strTmp += _T("\tPC ");
	strTmp += GetCtrlText(IDC_EDIT5);
	fReport.WriteString(strTmp + _T("\r\n"));

	strTmp = _T("静脉采血 ");
	strTmp += GetCtrlText(IDC_EDIT6);
	strTmp += _T("\t动脉采血 ");
	strTmp += GetCtrlText(IDC_EDIT7);
	strTmp += _T("\t套管针 ");
	strTmp += GetCtrlText(IDC_EDIT8);
	strTmp += _T("\t输血 ");
	strTmp += GetCtrlText(IDC_EDIT9);
	fReport.WriteString(strTmp + _T("\r\n"));

	strTmp = _T("留置尿管 ");
	strTmp += GetCtrlText(IDC_EDIT10);
	strTmp += _T("\t留置胃管 ");
	strTmp += GetCtrlText(IDC_EDIT11);
	strTmp += _T("\t灌流 ");
	strTmp += GetCtrlText(IDC_EDIT12);
	strTmp += _T("\t气管插管 ");
	strTmp += GetCtrlText(IDC_EDIT13);
	fReport.WriteString(strTmp + _T("\r\n"));

	strTmp = _T("CVC穿刺 ");
	strTmp += GetCtrlText(IDC_EDIT14);
	strTmp += _T("\t胸穿 ");
	strTmp += GetCtrlText(IDC_EDIT15);
	strTmp += _T("\t腰穿 ");
	strTmp += GetCtrlText(IDC_EDIT16);
	strTmp += _T("\t临终护理 ");
	strTmp += GetCtrlText(IDC_EDIT17);
	fReport.WriteString(strTmp + _T("\r\n"));

	strTmp = _T("CR ");
	strTmp += GetCtrlText(IDC_EDIT30);
	strTmp += _T("\tCT ");
	strTmp += GetCtrlText(IDC_EDIT31);
	strTmp += _T("\t会诊 ");
	strTmp += GetCtrlText(IDC_EDIT32);
	fReport.WriteString(strTmp + _T("\r\n"));
	fReport.WriteString(_T("\r\n"));

	strTmp = _T("鼻饲管 ");
	strTmp += GetCtrlText(IDC_EDIT18);
	strTmp += _T("\tT管 ");
	strTmp += GetCtrlText(IDC_EDIT19);
	strTmp += _T("\t导尿包 ");
	strTmp += GetCtrlText(IDC_EDIT20);
	strTmp += _T("\t精密尿袋 ");
	strTmp += GetCtrlText(IDC_EDIT21);
	fReport.WriteString(strTmp + _T("\r\n"));

	strTmp = _T("胃管 ");
	strTmp += GetCtrlText(IDC_EDIT22);
	strTmp += _T(" \t负压盒 ");
	strTmp += GetCtrlText(IDC_EDIT23);
	strTmp += _T("\t舒氧宝 ");
	strTmp += GetCtrlText(IDC_EDIT24);
	strTmp += _T("\t血滤 ");
	strTmp += GetCtrlText(IDC_EDIT25);
	fReport.WriteString(strTmp + _T("\r\n"));

	strTmp = _T("灌流配套 ");
	strTmp += GetCtrlText(IDC_EDIT26);
	strTmp += _T("\t呼吸机管路 ");
	strTmp += GetCtrlText(IDC_EDIT27);
	strTmp += _T("\t面罩 ");
	strTmp += GetCtrlText(IDC_EDIT28);
	strTmp += _T("\t氧气面罩 ");
	strTmp += GetCtrlText(IDC_EDIT29);
	fReport.WriteString(strTmp + _T("\r\n"));


	fReport.Flush();
	fReport.Close();

	AfxMessageBox(_T("数据保存成功！"));
}
