
// MFCApplication3.3View.cpp : CMFCApplication33View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication3.3.h"
#endif

#include "MFCApplication3.3Doc.h"
#include "MFCApplication3.3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication33View

IMPLEMENT_DYNCREATE(CMFCApplication33View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication33View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCApplication33View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCApplication33View 构造/析构

CMFCApplication33View::CMFCApplication33View()
{
	// TODO: 在此处添加构造代码
	
}

CMFCApplication33View::~CMFCApplication33View()
{
}

BOOL CMFCApplication33View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication33View 绘制

void CMFCApplication33View::OnDraw(CDC* pDC)
{
	CMFCApplication33Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	for (int i = 0; i < pDoc->ca.GetSize(); i++)
		pDC->Rectangle(pDoc->ca.GetAt(i));
}


// CMFCApplication33View 打印


void CMFCApplication33View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCApplication33View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCApplication33View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCApplication33View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CMFCApplication33View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCApplication33View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCApplication33View 诊断

#ifdef _DEBUG
void CMFCApplication33View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication33View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication33Doc* CMFCApplication33View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication33Doc)));
	return (CMFCApplication33Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication33View 消息处理程序


void CMFCApplication33View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int r = rand() % 50 + 5;
	CRect cr(point.x - r, point.y - r, point.x + r, point.y + r);
	CMFCApplication33Doc* pDoc = GetDocument();
	pDoc->ca.Add(cr);
	this->Invalidate();
	CView::OnLButtonDown(nFlags, point);
}
