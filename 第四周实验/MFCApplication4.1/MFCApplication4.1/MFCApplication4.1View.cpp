
// MFCApplication4.1View.cpp : CMFCApplication41View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCApplication41View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCApplication41View ����/����

CMFCApplication41View::CMFCApplication41View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFCApplication41View::~CMFCApplication41View()
{
}

BOOL CMFCApplication41View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCApplication41View ����

void CMFCApplication41View::OnDraw(CDC* pDC)
{
	CMFCApplication41Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
//	if (!pDoc)
	//	return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	pDC->Rectangle(pDoc->m_tagRec);
}


// CMFCApplication41View ��ӡ


void CMFCApplication41View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCApplication41View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFCApplication41View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFCApplication41View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
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


// CMFCApplication41View ���

#ifdef _DEBUG
void CMFCApplication41View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication41View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication41Doc* CMFCApplication41View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication41Doc)));
	return (CMFCApplication41Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication41View ��Ϣ�������


void CMFCApplication41View::OnLButtonDown(UINT nFlags, CPoint point)
{
	CMFCApplication41Doc* pDoc = GetDocument();
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
