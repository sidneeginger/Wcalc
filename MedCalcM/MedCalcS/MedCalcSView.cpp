
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

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMedCalcSView

IMPLEMENT_DYNCREATE(CMedCalcSView, CFormView)

BEGIN_MESSAGE_MAP(CMedCalcSView, CFormView)
END_MESSAGE_MAP()

// CMedCalcSView 构造/析构

CMedCalcSView::CMedCalcSView()
	: CFormView(IDD_MEDCALCS_FORM)
{
	// TODO: 在此处添加构造代码

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
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CFormView::PreCreateWindow(cs);
}

void CMedCalcSView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

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
