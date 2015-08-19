
// MedCalcMDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MedCalcM.h"
#include "MedCalcMDlg.h"
#include "afxdialogex.h"
#include <locale> 

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
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


// CMedCalcMDlg 对话框



CMedCalcMDlg::CMedCalcMDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MEDCALCM_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMedCalcMDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
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

BEGIN_MESSAGE_MAP(CMedCalcMDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DATETIMEPICKER1, &CMedCalcMDlg::OnDtnDatetimechangeDatetimepicker1)
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DATETIMEPICKER2, &CMedCalcMDlg::OnDtnDatetimechangeDatetimepicker2)
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DTP_VENT_FROM, &CMedCalcMDlg::OnDtnDatetimechangeDtpVentFrom)
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DTP_VENT_TO, &CMedCalcMDlg::OnDtnDatetimechangeDtpVentTo)
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DTP_ARTERY_FROM, &CMedCalcMDlg::OnDtnDatetimechangeDtpArteryFrom)
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DTP_ARTERY_TO, &CMedCalcMDlg::OnDtnDatetimechangeDtpArteryTo)
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DTP_VEIN_FROM, &CMedCalcMDlg::OnDtnDatetimechangeDtpVeinFrom)
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DTP_VEIN_TO, &CMedCalcMDlg::OnDtnDatetimechangeDtpVeinTo)
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DTP_GIDEC_FROM, &CMedCalcMDlg::OnDtnDatetimechangeDtpGidecFrom)
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DTP_GIDEC_TO, &CMedCalcMDlg::OnDtnDatetimechangeDtpGidecTo)
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DTP_CVVT_FROM, &CMedCalcMDlg::OnDtnDatetimechangeDtpCvvtFrom)
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DTP_CVVT_TO, &CMedCalcMDlg::OnDtnDatetimechangeDtpCvvtTo)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN1, &CMedCalcMDlg::OnDeltaposSpin1)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN2, &CMedCalcMDlg::OnDeltaposSpin2)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN3, &CMedCalcMDlg::OnDeltaposSpin3)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN4, &CMedCalcMDlg::OnDeltaposSpin4)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN5, &CMedCalcMDlg::OnDeltaposSpin5)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN6, &CMedCalcMDlg::OnDeltaposSpin6)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN7, &CMedCalcMDlg::OnDeltaposSpin7)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN8, &CMedCalcMDlg::OnDeltaposSpin8)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN9, &CMedCalcMDlg::OnDeltaposSpin9)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN10, &CMedCalcMDlg::OnDeltaposSpin10)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN11, &CMedCalcMDlg::OnDeltaposSpin11)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN12, &CMedCalcMDlg::OnDeltaposSpin12)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN13, &CMedCalcMDlg::OnDeltaposSpin13)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN14, &CMedCalcMDlg::OnDeltaposSpin14)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN15, &CMedCalcMDlg::OnDeltaposSpin15)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN16, &CMedCalcMDlg::OnDeltaposSpin16)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN29, &CMedCalcMDlg::OnDeltaposSpin29)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN30, &CMedCalcMDlg::OnDeltaposSpin30)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN31, &CMedCalcMDlg::OnDeltaposSpin31)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN17, &CMedCalcMDlg::OnDeltaposSpin17)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN18, &CMedCalcMDlg::OnDeltaposSpin18)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN19, &CMedCalcMDlg::OnDeltaposSpin19)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN20, &CMedCalcMDlg::OnDeltaposSpin20)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN21, &CMedCalcMDlg::OnDeltaposSpin21)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN22, &CMedCalcMDlg::OnDeltaposSpin22)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN23, &CMedCalcMDlg::OnDeltaposSpin23)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN24, &CMedCalcMDlg::OnDeltaposSpin24)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN25, &CMedCalcMDlg::OnDeltaposSpin25)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN26, &CMedCalcMDlg::OnDeltaposSpin26)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN27, &CMedCalcMDlg::OnDeltaposSpin27)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN28, &CMedCalcMDlg::OnDeltaposSpin28)
	ON_BN_CLICKED(IDC_BN_SAVE, &CMedCalcMDlg::OnBnClickedBnSave)
END_MESSAGE_MAP()


// CMedCalcMDlg 消息处理程序

BOOL CMedCalcMDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
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

	m_dTotalRoomHours = 0.0;

	//SetDlgItemText(IDC_EDIT2, _T("0"));
	//SetDlgItemText(IDC_EDIT3, _T("0"));
	//SetDlgItemText(IDC_EDIT4, _T("0"));
	//SetDlgItemText(IDC_EDIT5, _T("0"));
	//SetDlgItemText(IDC_EDIT6, _T("0"));
	//SetDlgItemText(IDC_EDIT7, _T("0"));
	//SetDlgItemText(IDC_EDIT8, _T("0"));
	//SetDlgItemText(IDC_EDIT9, _T("0"));
	//SetDlgItemText(IDC_EDIT10, _T("0"));
	//SetDlgItemText(IDC_EDIT11, _T("0"));
	//SetDlgItemText(IDC_EDIT12, _T("0"));
	//SetDlgItemText(IDC_EDIT13, _T("0"));
	//SetDlgItemText(IDC_EDIT14, _T("0"));
	//SetDlgItemText(IDC_EDIT15, _T("0"));
	//SetDlgItemText(IDC_EDIT16, _T("0"));
	//SetDlgItemText(IDC_EDIT17, _T("0"));
	//SetDlgItemText(IDC_EDIT18, _T("0"));
	//SetDlgItemText(IDC_EDIT19, _T("0"));
	//SetDlgItemText(IDC_EDIT20, _T("0"));
	//SetDlgItemText(IDC_EDIT21, _T("0"));
	//SetDlgItemText(IDC_EDIT22, _T("0"));
	//SetDlgItemText(IDC_EDIT23, _T("0"));
	//SetDlgItemText(IDC_EDIT24, _T("0"));
	//SetDlgItemText(IDC_EDIT25, _T("0"));
	//SetDlgItemText(IDC_EDIT26, _T("0"));
	//SetDlgItemText(IDC_EDIT27, _T("0"));
	//SetDlgItemText(IDC_EDIT28, _T("0"));
	//SetDlgItemText(IDC_EDIT29, _T("0"));
	//SetDlgItemText(IDC_EDIT30, _T("0"));
	//SetDlgItemText(IDC_EDIT31, _T("0"));
	//SetDlgItemText(IDC_EDIT32, _T("0"));

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMedCalcMDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMedCalcMDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMedCalcMDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMedCalcMDlg::OnDtnDatetimechangeDatetimepicker1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	CalcTime();
	*pResult = 0;
}


void CMedCalcMDlg::OnDtnDatetimechangeDatetimepicker2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	CalcTime();
	*pResult = 0;
}


int CMedCalcMDlg::CalcTime()
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
		SetDlgItemText(IDC_TXT_NOTE, _T(""));
	}

	return 0;
}


int CMedCalcMDlg::CleanAll()
{
	CString strNull = _T("");
	SetDlgItemText(IDC_EDIT_TotalHours, strNull);
	SetDlgItemText(IDC_EDIT_TotalDays, strNull);



	return 0;
}


int CMedCalcMDlg::CalcTotal(CTimeSpan &timeSpan)
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


void CMedCalcMDlg::OnDtnDatetimechangeDtpVentFrom(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	CalcVent();
	*pResult = 0;
}


void CMedCalcMDlg::OnDtnDatetimechangeDtpVentTo(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	CalcVent();
	*pResult = 0;
}


void CMedCalcMDlg::CalcVent()
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


void CMedCalcMDlg::OnDtnDatetimechangeDtpArteryFrom(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	CalcArtery();
	*pResult = 0;
}


void CMedCalcMDlg::OnDtnDatetimechangeDtpArteryTo(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	CalcArtery();
	*pResult = 0;
}


void CMedCalcMDlg::OnDtnDatetimechangeDtpVeinFrom(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	CalcVein();
	*pResult = 0;
}


void CMedCalcMDlg::OnDtnDatetimechangeDtpVeinTo(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	CalcVein();
	*pResult = 0;
}


void CMedCalcMDlg::OnDtnDatetimechangeDtpGidecFrom(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	CalcGIDEC();
	*pResult = 0;
}


void CMedCalcMDlg::OnDtnDatetimechangeDtpGidecTo(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	CalcGIDEC();
	*pResult = 0;
}


void CMedCalcMDlg::OnDtnDatetimechangeDtpCvvtFrom(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	CalcCVVT();
	*pResult = 0;
}


void CMedCalcMDlg::OnDtnDatetimechangeDtpCvvtTo(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	CalcCVVT();
	*pResult = 0;
}


void CMedCalcMDlg::CalcVein()
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


void CMedCalcMDlg::CalcArtery()
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


void CMedCalcMDlg::CalcGIDEC()
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


void CMedCalcMDlg::CalcCVVT()
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


void CMedCalcMDlg::OnDeltaposSpin1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码

	OnSpinChange(IDC_EDIT2, pNMUpDown->iDelta);

	*pResult = 0;
}


void CMedCalcMDlg::OnSpinChange(int nID, int nDelta)
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


void CMedCalcMDlg::OnDeltaposSpin2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	OnSpinChange(IDC_EDIT3, pNMUpDown->iDelta);

	*pResult = 0;
}


void CMedCalcMDlg::OnDeltaposSpin3(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	OnSpinChange(IDC_EDIT4, pNMUpDown->iDelta);

	*pResult = 0;
}


void CMedCalcMDlg::OnDeltaposSpin4(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	OnSpinChange(IDC_EDIT5, pNMUpDown->iDelta);

	*pResult = 0;
}


void CMedCalcMDlg::OnDeltaposSpin5(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	OnSpinChange(IDC_EDIT6, pNMUpDown->iDelta);

	*pResult = 0;
}


void CMedCalcMDlg::OnDeltaposSpin6(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	OnSpinChange(IDC_EDIT7, pNMUpDown->iDelta);

	*pResult = 0;
}


void CMedCalcMDlg::OnDeltaposSpin7(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	OnSpinChange(IDC_EDIT8, pNMUpDown->iDelta);

	*pResult = 0;
}


void CMedCalcMDlg::OnDeltaposSpin8(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	OnSpinChange(IDC_EDIT9, pNMUpDown->iDelta);

	*pResult = 0;
}


void CMedCalcMDlg::OnDeltaposSpin9(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	OnSpinChange(IDC_EDIT10, pNMUpDown->iDelta);

	*pResult = 0;
}


void CMedCalcMDlg::OnDeltaposSpin10(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	OnSpinChange(IDC_EDIT11, pNMUpDown->iDelta);

	*pResult = 0;
}


void CMedCalcMDlg::OnDeltaposSpin11(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	OnSpinChange(IDC_EDIT12, pNMUpDown->iDelta);

	*pResult = 0;
}


void CMedCalcMDlg::OnDeltaposSpin12(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	OnSpinChange(IDC_EDIT13, pNMUpDown->iDelta);

	*pResult = 0;
}


void CMedCalcMDlg::OnDeltaposSpin13(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	OnSpinChange(IDC_EDIT14, pNMUpDown->iDelta);

	*pResult = 0;
}


void CMedCalcMDlg::OnDeltaposSpin14(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	OnSpinChange(IDC_EDIT15, pNMUpDown->iDelta);

	*pResult = 0;
}


void CMedCalcMDlg::OnDeltaposSpin15(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	OnSpinChange(IDC_EDIT16, pNMUpDown->iDelta);

	*pResult = 0;
}


void CMedCalcMDlg::OnDeltaposSpin16(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	OnSpinChange(IDC_EDIT17, pNMUpDown->iDelta);

	*pResult = 0;
}


void CMedCalcMDlg::OnDeltaposSpin29(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	OnSpinChange(IDC_EDIT30, pNMUpDown->iDelta);

	*pResult = 0;
}


void CMedCalcMDlg::OnDeltaposSpin30(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	OnSpinChange(IDC_EDIT31, pNMUpDown->iDelta);

	*pResult = 0;
}


void CMedCalcMDlg::OnDeltaposSpin31(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	OnSpinChange(IDC_EDIT32, pNMUpDown->iDelta);

	*pResult = 0;
}


void CMedCalcMDlg::OnDeltaposSpin17(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	OnSpinChange(IDC_EDIT18, pNMUpDown->iDelta);

	*pResult = 0;
}


void CMedCalcMDlg::OnDeltaposSpin18(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	OnSpinChange(IDC_EDIT19, pNMUpDown->iDelta);

	*pResult = 0;
}


void CMedCalcMDlg::OnDeltaposSpin19(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	OnSpinChange(IDC_EDIT20, pNMUpDown->iDelta);

	*pResult = 0;
}


void CMedCalcMDlg::OnDeltaposSpin20(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	OnSpinChange(IDC_EDIT21, pNMUpDown->iDelta);

	*pResult = 0;
}


void CMedCalcMDlg::OnDeltaposSpin21(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	OnSpinChange(IDC_EDIT22, pNMUpDown->iDelta);

	*pResult = 0;
}


void CMedCalcMDlg::OnDeltaposSpin22(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	OnSpinChange(IDC_EDIT23, pNMUpDown->iDelta);

	*pResult = 0;
}


void CMedCalcMDlg::OnDeltaposSpin23(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	OnSpinChange(IDC_EDIT24, pNMUpDown->iDelta);

	*pResult = 0;
}


void CMedCalcMDlg::OnDeltaposSpin24(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	OnSpinChange(IDC_EDIT25, pNMUpDown->iDelta);

	*pResult = 0;
}


void CMedCalcMDlg::OnDeltaposSpin25(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	OnSpinChange(IDC_EDIT26, pNMUpDown->iDelta);

	*pResult = 0;
}


void CMedCalcMDlg::OnDeltaposSpin26(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	OnSpinChange(IDC_EDIT27, pNMUpDown->iDelta);

	*pResult = 0;
}


void CMedCalcMDlg::OnDeltaposSpin27(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	OnSpinChange(IDC_EDIT28, pNMUpDown->iDelta);

	*pResult = 0;
}


void CMedCalcMDlg::OnDeltaposSpin28(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	OnSpinChange(IDC_EDIT29, pNMUpDown->iDelta);

	*pResult = 0;
}


CString CMedCalcMDlg::GetCtrlText(int nID)
{
	CString str;
	GetDlgItemText(nID, str);
	return str;
}


void CMedCalcMDlg::OnBnClickedBnSave()
{
	LPCTSTR lpszFilter = _T("TXT Files(*.txt)|*.txt|任何文件|*.*|");
	CFileDialog dlg(FALSE, lpszFilter, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, lpszFilter, NULL);
	
	if (dlg.DoModal() != IDOK)
	{
		return;
	}

	// save
	CString strFullName = dlg.GetPathName();

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
