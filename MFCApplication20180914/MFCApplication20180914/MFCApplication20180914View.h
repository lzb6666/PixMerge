
// MFCApplication20180914View.h: CMFCApplication20180914View 类的接口
//

#pragma once


class CMFCApplication20180914View : public CScrollView
{
protected: // 仅从序列化创建
	CMFCApplication20180914View() noexcept;
	DECLARE_DYNCREATE(CMFCApplication20180914View)

// 特性
public:
	CMFCApplication20180914Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // 构造后第一次调用
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CMFCApplication20180914View();
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
	virtual void OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/);
};

#ifndef _DEBUG  // MFCApplication20180914View.cpp 中的调试版本
inline CMFCApplication20180914Doc* CMFCApplication20180914View::GetDocument() const
   { return reinterpret_cast<CMFCApplication20180914Doc*>(m_pDocument); }
#endif

