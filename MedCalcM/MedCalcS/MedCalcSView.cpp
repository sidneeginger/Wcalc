
// MedCalcSView.cpp : CMedCalcSView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MedCalcS.h"
#endif

#include "MedCalcSDoc.h"
#include "MedCalcSView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMedCalcSView

IMPLEMENT_DYNCREATE(CMedCalcSView, CFormView)

BEGIN_MESSAGE_MAP(CMedCalcSView, CFormView)
END_MESSAGE_MAP()

// CMedCalcSView ����/����

CMedCalcSView::CMedCalcSView()
	: CFormView(IDD_MEDCALCS_FORM)
{
	// TODO: �ڴ˴���ӹ������

}

CMedCalcSView::~CMedCalcSView()
{
}

void CMedCalcSView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL CMedCalcSView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CFormView::PreCreateWindow(cs);
}

void CMedCalcSView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CMedCalcSView ���

#ifdef _DEBUG
void CMedCalcSView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMedCalcSView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMedCalcSDoc* CMedCalcSView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMedCalcSDoc)));
	return (CMedCalcSDoc*)m_pDocument;
}
#endif //_DEBUG


// CMedCalcSView ��Ϣ�������
