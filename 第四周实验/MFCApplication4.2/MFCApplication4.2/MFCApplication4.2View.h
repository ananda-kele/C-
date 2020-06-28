
// MFCApplication4.2View.h : CMFCApplication42View 类的接口
//

#pragma once


class CMFCApplication42View : public CView
{
protected: // 仅从序列化创建
	CMFCApplication42View();
	DECLARE_DYNCREATE(CMFCApplication42View)

// 特性
public:
	CMFCApplication42Doc* GetDocument() const;

// 操作
public:

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
	virtual ~CMFCApplication42View();
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
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFCApplication4.2View.cpp 中的调试版本
inline CMFCApplication42Doc* CMFCApplication42View::GetDocument() const
   { return reinterpret_cast<CMFCApplication42Doc*>(m_pDocument); }
#endif

