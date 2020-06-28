
// MFCApplication3.2View.cpp : CMFCApplication32View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication3.2.h"
#endif

#include "MFCApplication3.2Doc.h"
#include "MFCApplication3.2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication32View

IMPLEMENT_DYNCREATE(CMFCApplication32View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication32View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCApplication32View 构造/析构

CMFCApplication32View::CMFCApplication32View()
{
	// TODO: 在此处添加构造代码
}

CMFCApplication32View::~CMFCApplication32View()
{
}

BOOL CMFCApplication32View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication32View 绘制

void CMFCApplication32View::OnDraw(CDC* /*pDC*/)
{
	CMFCApplication32Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}

void CMFCApplication32View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCApplication32View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCApplication32View 诊断

#ifdef _DEBUG
void CMFCApplication32View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication32View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication32Doc* CMFCApplication32View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication32Doc)));
	return (CMFCApplication32Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication32View 消息处理程序


void CMFCApplication32View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int r = rand() % 50 + 5;
	CClientDC dc(this);
	CRect cr(point.x - r, point.y - r, point.x + r, point.y + r);
	dc.Rectangle(cr);
	CView::OnLButtonDown(nFlags, point);
}
