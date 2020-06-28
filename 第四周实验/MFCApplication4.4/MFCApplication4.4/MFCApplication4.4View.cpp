
// MFCApplication4.4View.cpp : CMFCApplication44View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication4.4.h"
#endif

#include "MFCApplication4.4Doc.h"
#include "MFCApplication4.4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication44View

IMPLEMENT_DYNCREATE(CMFCApplication44View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication44View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCApplication44View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMFCApplication44View 构造/析构

CMFCApplication44View::CMFCApplication44View()
{
	// TODO: 在此处添加构造代码

}

CMFCApplication44View::~CMFCApplication44View()
{
}

BOOL CMFCApplication44View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication44View 绘制

void CMFCApplication44View::OnDraw(CDC* /*pDC*/)
{
	CMFCApplication44Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCApplication44View 打印


void CMFCApplication44View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCApplication44View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCApplication44View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCApplication44View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CMFCApplication44View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCApplication44View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCApplication44View 诊断

#ifdef _DEBUG
void CMFCApplication44View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication44View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication44Doc* CMFCApplication44View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication44Doc)));
	return (CMFCApplication44Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication44View 消息处理程序


void CMFCApplication44View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	SetCapture();
	CView::OnLButtonDown(nFlags, point);
}


void CMFCApplication44View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	char str[50];
	CClientDC dc(this);
	dc.TextOut(20, 20, "WM_MOUSEMOVE");
	wsprintf(str, "X:%d  Y:%d", point.x, point.y)
		dc.TextOut(200, 20, str);
	CView::OnMouseMove(nFlags, point);
}


void CMFCApplication44View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	ReleaseCapture();
	CView::OnLButtonUp(nFlags, point);
}
