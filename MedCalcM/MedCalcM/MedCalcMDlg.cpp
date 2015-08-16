
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
		//SetDlgItemText(IDC_TXT_NOTE, _T("ע�⣺����ʱ��Ҫ���ڿ�ʼʱ�䣡"));
		AfxMessageBox(_T("����ʱ��Ҫ���ڿ�ʼʱ�䣡"));
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CalcVent();
	*pResult = 0;
}


void CMedCalcMDlg::OnDtnDatetimechangeDtpVentTo(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
		//SetDlgItemText(IDC_TXT_NOTE, _T("ע�⣺����ʱ��Ҫ���ڿ�ʼʱ�䣡"));
		AfxMessageBox(_T("����ʱ��Ҫ���ڿ�ʼʱ�䣡"));
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CalcArtery();
	*pResult = 0;
}


void CMedCalcMDlg::OnDtnDatetimechangeDtpArteryTo(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CalcArtery();
	*pResult = 0;
}


void CMedCalcMDlg::OnDtnDatetimechangeDtpVeinFrom(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CalcVein();
	*pResult = 0;
}


void CMedCalcMDlg::OnDtnDatetimechangeDtpVeinTo(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CalcVein();
	*pResult = 0;
}


void CMedCalcMDlg::OnDtnDatetimechangeDtpGidecFrom(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CalcGIDEC();
	*pResult = 0;
}


void CMedCalcMDlg::OnDtnDatetimechangeDtpGidecTo(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CalcGIDEC();
	*pResult = 0;
}


void CMedCalcMDlg::OnDtnDatetimechangeDtpCvvtFrom(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CalcCVVT();
	*pResult = 0;
}


void CMedCalcMDlg::OnDtnDatetimechangeDtpCvvtTo(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
		//SetDlgItemText(IDC_TXT_NOTE, _T("ע�⣺����ʱ��Ҫ���ڿ�ʼʱ�䣡"));
		AfxMessageBox(_T("����ʱ��Ҫ���ڿ�ʼʱ�䣡"));
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
		//SetDlgItemText(IDC_TXT_NOTE, _T("ע�⣺����ʱ��Ҫ���ڿ�ʼʱ�䣡"));
		AfxMessageBox(_T("����ʱ��Ҫ���ڿ�ʼʱ�䣡"));
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
		//SetDlgItemText(IDC_TXT_NOTE, _T("ע�⣺����ʱ��Ҫ���ڿ�ʼʱ�䣡"));
		AfxMessageBox(_T("����ʱ��Ҫ���ڿ�ʼʱ�䣡"));
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
		//SetDlgItemText(IDC_TXT_NOTE, _T("ע�⣺����ʱ��Ҫ���ڿ�ʼʱ�䣡"));
		AfxMessageBox(_T("����ʱ��Ҫ���ڿ�ʼʱ�䣡"));
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
