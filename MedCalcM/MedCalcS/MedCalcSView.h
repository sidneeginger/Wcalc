
// MedCalcSView.h : CMedCalcSView ��Ľӿ�
//

#pragma once


class CMedCalcSView : public CFormView
{
protected: // �������л�����
	CMedCalcSView();
	DECLARE_DYNCREATE(CMedCalcSView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MEDCALCS_FORM };
#endif

// ����
public:
	CMedCalcSDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CMedCalcSView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MedCalcSView.cpp �еĵ��԰汾
inline CMedCalcSDoc* CMedCalcSView::GetDocument() const
   { return reinterpret_cast<CMedCalcSDoc*>(m_pDocument); }
#endif

