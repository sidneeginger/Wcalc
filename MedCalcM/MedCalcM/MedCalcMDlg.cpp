
// MedCalcMDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MedCalcM.h"
#include "MedCalcMDlg.h"
#include "afxdialogex.h"

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
}

BEGIN_MESSAGE_MAP(CMedCalcMDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DATETIMEPICKER1, &CMedCalcMDlg::OnDtnDatetimechangeDatetimepicker1)
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DATETIMEPICKER2, &CMedCalcMDlg::OnDtnDatetimechangeDatetimepicker2)
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
	m_dtStart.SetFormat(_T("yyyy-MM-dd hh:mm:ss"));
	m_dtEnd.SetFormat(_T("yyyy-MM-dd hh:mm:ss"));

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
		SetDlgItemText(IDC_TXT_NOTE, _T("注意：结束时间要大于开始时间！"));
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
	CString strTemp;
	strTemp.Format(_T("%.2f"), dTotalHours);
	SetDlgItemText(IDC_EDIT_TotalHours, strTemp);
	strTemp.Format(_T("%.2f"), dTotalHours / 24.0);
	SetDlgItemText(IDC_EDIT_TotalDays, strTemp);
	return 0;
}
