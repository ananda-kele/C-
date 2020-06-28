
// MFCApplication4.2View.cpp : CMFCApplication42View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCApplication42View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMFCApplication42View ����/����

CMFCApplication42View::CMFCApplication42View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFCApplication42View::~CMFCApplication42View()
{
}

BOOL CMFCApplication42View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCApplication42View ����

void CMFCApplication42View::OnDraw(CDC* pDC)
{
	CMFCApplication42Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CPoint point(30, 30);
	pDC->MoveTo(point);
	pDC->LineTo(pDoc->m_Point);
}


// CMFCApplication42View ��ӡ


void CMFCApplication42View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCApplication42View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFCApplication42View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFCApplication42View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
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


// CMFCApplication42View ���

#ifdef _DEBUG
void CMFCApplication42View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication42View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication42Doc* CMFCApplication42View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication42Doc)));
	return (CMFCApplication42Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication42View ��Ϣ�������


void CMFCApplication42View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFCApplication42Doc* pDoc = GetDocument();
	pDoc->m_Point = point;
	InvalidateRect(NULL, FALSE);
	CView::OnMouseMove(nFlags, point);
}
