
// MFCApplication4.4View.cpp : CMFCApplication44View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCApplication44View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMFCApplication44View ����/����

CMFCApplication44View::CMFCApplication44View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFCApplication44View::~CMFCApplication44View()
{
}

BOOL CMFCApplication44View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCApplication44View ����

void CMFCApplication44View::OnDraw(CDC* /*pDC*/)
{
	CMFCApplication44Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFCApplication44View ��ӡ


void CMFCApplication44View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCApplication44View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFCApplication44View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFCApplication44View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
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


// CMFCApplication44View ���

#ifdef _DEBUG
void CMFCApplication44View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication44View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication44Doc* CMFCApplication44View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication44Doc)));
	return (CMFCApplication44Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication44View ��Ϣ�������


void CMFCApplication44View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	SetCapture();
	CView::OnLButtonDown(nFlags, point);
}


void CMFCApplication44View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	char str[50];
	CClientDC dc(this);
	dc.TextOut(20, 20, "WM_MOUSEMOVE");
	wsprintf(str, "X:%d  Y:%d", point.x, point.y)
		dc.TextOut(200, 20, str);
	CView::OnMouseMove(nFlags, point);
}


void CMFCApplication44View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	ReleaseCapture();
	CView::OnLButtonUp(nFlags, point);
}
