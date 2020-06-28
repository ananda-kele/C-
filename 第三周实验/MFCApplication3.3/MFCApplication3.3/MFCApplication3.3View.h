
// MFCApplication3.3View.h : CMFCApplication33View 类的接口
//

#pragma once


class CMFCApplication33View : public CView
{
protected: // 仅从序列化创建
	CMFCApplication33View();
	DECLARE_DYNCREATE(CMFCApplication33View)

// 特性
public:
	CMFCApplication33Doc* GetDocument() const;

// 操作
public:
//	CArray<CRect,CRect&> ca;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CMFCApplication33View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFCApplication3.3View.cpp 中的调试版本
inline CMFCApplication33Doc* CMFCApplication33View::GetDocument() const
   { return reinterpret_cast<CMFCApplication33Doc*>(m_pDocument); }
#endif

