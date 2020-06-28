
// MFCApplication2.1View.cpp : CMFCApplication21View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication2.1.h"
#endif

#include "MFCApplication2.1Doc.h"
#include "MFCApplication2.1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication21View

IMPLEMENT_DYNCREATE(CMFCApplication21View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication21View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCApplication21View 构造/析构

CMFCApplication21View::CMFCApplication21View()
{
	// TODO: 在此处添加构造代码

}

CMFCApplication21View::~CMFCApplication21View()
{
}

BOOL CMFCApplication21View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication21View 绘制

void CMFCApplication21View::OnDraw(CDC* /*pDC*/)
{
	CMFCApplication21Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}

void CMFCApplication21View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCApplication21View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCApplication21View 诊断

#ifdef _DEBUG
void CMFCApplication21View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication21View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication21Doc* CMFCApplication21View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication21Doc)));
	return (CMFCApplication21Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication21View 消息处理程序


void CMFCApplication21View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	CRect rc;
	GetClientRect(&rc);

	CView::OnLButtonDown(nFlags, point);
}
