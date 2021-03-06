
// MFCApplication20180914View.cpp: CMFCApplication20180914View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication20180914.h"
#endif

#include "MFCApplication20180914Doc.h"
#include "MFCApplication20180914View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication20180914View

IMPLEMENT_DYNCREATE(CMFCApplication20180914View, CScrollView)

BEGIN_MESSAGE_MAP(CMFCApplication20180914View, CScrollView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCApplication20180914View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMFCApplication20180914View 构造/析构

CMFCApplication20180914View::CMFCApplication20180914View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFCApplication20180914View::~CMFCApplication20180914View()
{
}

BOOL CMFCApplication20180914View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CScrollView::PreCreateWindow(cs);
}

// CMFCApplication20180914View 绘图

void CMFCApplication20180914View::OnDraw(CDC* pDC)
{
	CMFCApplication20180914Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	if (pDoc->m_pImage)
	{
		pDoc->m_pImage->BitBlt(pDC->GetSafeHdc(), 10, 20, SRCCOPY);
	}
	
}

void CMFCApplication20180914View::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	CMFCApplication20180914Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: 计算此视图的合计大小
	if (pDoc->m_pImage) {
		sizeTotal.cx = pDoc->m_pImage->GetWidth() + 15;
		sizeTotal.cy = pDoc->m_pImage->GetHeight() + 27;
	}
	else
	{
		sizeTotal.cx = sizeTotal.cy = 100;
	}
	SetScrollSizes(MM_TEXT, sizeTotal);
	
}


// CMFCApplication20180914View 打印


void CMFCApplication20180914View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCApplication20180914View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCApplication20180914View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCApplication20180914View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CMFCApplication20180914View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCApplication20180914View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCApplication20180914View 诊断

#ifdef _DEBUG
void CMFCApplication20180914View::AssertValid() const
{
	CScrollView::AssertValid();
}

void CMFCApplication20180914View::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CMFCApplication20180914Doc* CMFCApplication20180914View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication20180914Doc)));
	return (CMFCApplication20180914Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication20180914View 消息处理程序


void CMFCApplication20180914View::OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/)
{
	// TODO: 在此添加专用代码和/或调用基类
	//添加初始化代码
	CSize sizeTotal;
	CMFCApplication20180914Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: 计算此视图的合计大小
	if (pDoc->m_pImage) {
		sizeTotal.cx = pDoc->m_pImage->GetWidth() + 15;
		sizeTotal.cy = pDoc->m_pImage->GetHeight() + 27;
	}
	else
	{
		sizeTotal.cx = sizeTotal.cy = 100;
	}
	SetScrollSizes(MM_TEXT, sizeTotal);
}
