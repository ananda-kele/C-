
// MFCApplication4.2View.cpp : CMFCApplication42View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication4.2.h"
#endif

#include "MFCApplication4.2Doc.h"
#include "MFCApplication4.2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication42View

IMPLEMENT_DYNCREATE(CMFCApplication42View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication42View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCApplication42View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMFCApplication42View 构造/析构

CMFCApplication42View::CMFCApplication42View()
{
	// TODO: 在此处添加构造代码

}

CMFCApplication42View::~CMFCApplication42View()
{
}

BOOL CMFCApplication42View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication42View 绘制

void CMFCApplication42View::OnDraw(CDC* pDC)
{
	CMFCApplication42Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CPoint point(30, 30);
	pDC->MoveTo(point);
	pDC->LineTo(pDoc->m_Point);
}


// CMFCApplication42View 打印


void CMFCApplication42View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCApplication42View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCApplication42View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCApplication42View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CMFCApplication42View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCApplication42View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCApplication42View 诊断

#ifdef _DEBUG
void CMFCApplication42View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication42View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication42Doc* CMFCApplication42View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication42Doc)));
	return (CMFCApplication42Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication42View 消息处理程序


void CMFCApplication42View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCApplication42Doc* pDoc = GetDocument();
	pDoc->m_Point = point;
	InvalidateRect(NULL, FALSE);
	CView::OnMouseMove(nFlags, point);
}
