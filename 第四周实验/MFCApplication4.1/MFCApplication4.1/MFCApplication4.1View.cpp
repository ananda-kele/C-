
// MFCApplication4.1View.cpp : CMFCApplication41View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication4.1.h"
#endif

#include "MFCApplication4.1Doc.h"
#include "MFCApplication4.1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication41View

IMPLEMENT_DYNCREATE(CMFCApplication41View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication41View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCApplication41View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCApplication41View 构造/析构

CMFCApplication41View::CMFCApplication41View()
{
	// TODO: 在此处添加构造代码

}

CMFCApplication41View::~CMFCApplication41View()
{
}

BOOL CMFCApplication41View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication41View 绘制

void CMFCApplication41View::OnDraw(CDC* pDC)
{
	CMFCApplication41Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
//	if (!pDoc)
	//	return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->Rectangle(pDoc->m_tagRec);
}


// CMFCApplication41View 打印


void CMFCApplication41View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCApplication41View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCApplication41View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCApplication41View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CMFCApplication41View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCApplication41View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCApplication41View 诊断

#ifdef _DEBUG
void CMFCApplication41View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication41View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication41Doc* CMFCApplication41View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication41Doc)));
	return (CMFCApplication41Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication41View 消息处理程序


void CMFCApplication41View::OnLButtonDown(UINT nFlags, CPoint point)
{
	CMFCApplication41Doc* pDoc = GetDocument();
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (nFlags&MK_SHIFT)
	{
		pDoc->m_tagRec.left = 30;
		pDoc->m_tagRec.top = 30;
		pDoc->m_tagRec.right = 350;
		pDoc->m_tagRec.bottom = 300;
	}
	else
	{
		pDoc->m_tagRec.left = point.x;
		pDoc->m_tagRec.top = point.y;
		pDoc->m_tagRec.right = point.x + 320;
		pDoc->m_tagRec.bottom = point.y + 270;
	}
	InvalidateRect(NULL, TRUE);
	CView::OnLButtonDown(nFlags, point);
}
