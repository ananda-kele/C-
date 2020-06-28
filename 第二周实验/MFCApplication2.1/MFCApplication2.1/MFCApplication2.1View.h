
// MFCApplication2.1View.h : CMFCApplication21View 类的接口
//

#pragma once


class CMFCApplication21View : public CView
{
protected: // 仅从序列化创建
	CMFCApplication21View();
	DECLARE_DYNCREATE(CMFCApplication21View)

// 特性
public:
	CMFCApplication21Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCApplication21View();
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

#ifndef _DEBUG  // MFCApplication2.1View.cpp 中的调试版本
inline CMFCApplication21Doc* CMFCApplication21View::GetDocument() const
   { return reinterpret_cast<CMFCApplication21Doc*>(m_pDocument); }
#endif

