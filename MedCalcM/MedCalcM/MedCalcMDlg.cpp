
// MedCalcMDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MedCalcM.h"
#include "MedCalcMDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CMedCalcMDlg �Ի���



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


// CMedCalcMDlg ��Ϣ�������

BOOL CMedCalcMDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	m_dtStart.SetFormat(_T("yyyy-MM-dd hh:mm:ss"));
	m_dtEnd.SetFormat(_T("yyyy-MM-dd hh:mm:ss"));

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMedCalcMDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMedCalcMDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMedCalcMDlg::OnDtnDatetimechangeDatetimepicker1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CalcTime();
	*pResult = 0;
}


void CMedCalcMDlg::OnDtnDatetimechangeDatetimepicker2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
		SetDlgItemText(IDC_TXT_NOTE, _T("ע�⣺����ʱ��Ҫ���ڿ�ʼʱ�䣡"));
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
