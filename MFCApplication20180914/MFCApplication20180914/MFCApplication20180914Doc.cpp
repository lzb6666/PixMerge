
// MFCApplication20180914Doc.cpp: CMFCApplication20180914Doc 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication20180914.h"
#endif

#include "MFCApplication20180914Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMFCApplication20180914Doc

IMPLEMENT_DYNCREATE(CMFCApplication20180914Doc, CDocument)

BEGIN_MESSAGE_MAP(CMFCApplication20180914Doc, CDocument)
END_MESSAGE_MAP()


// CMFCApplication20180914Doc 构造/析构

CMFCApplication20180914Doc::CMFCApplication20180914Doc() noexcept
{
	// TODO: 在此添加一次性构造代码
	m_pImage = NULL;
}

CMFCApplication20180914Doc::~CMFCApplication20180914Doc()
{
	if (m_pImage)
	{
		delete m_pImage;
	}
}

void CMFCApplication20180914Doc::mergePix(CImage * pImage_1, CImage * pImage_2)
{
	int nWidth, nHeight, nBPP;
	HDC hDC;

	nBPP = pImage_1->GetBPP();
	nWidth = pImage_1->GetWidth()+pImage_2->GetWidth();
	nHeight = pImage_1->GetHeight();

	if (nHeight<pImage_2->GetHeight())
	{
		nHeight = pImage_2->GetHeight();
	}

	m_pImage = new CImage;
	m_pImage->Create(nWidth, nHeight, nBPP);

	hDC = m_pImage->GetDC();
	pImage_1->BitBlt(hDC, 0, 0, SRCCOPY);
	pImage_2->BitBlt(hDC, pImage_1->GetWidth(), 0, SRCCOPY);

	m_pImage->ReleaseDC();

	UpdateAllViews(NULL);
}

BOOL CMFCApplication20180914Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CMFCApplication20180914Doc 序列化

void CMFCApplication20180914Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CMFCApplication20180914Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 搜索处理程序的支持
void CMFCApplication20180914Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:     strSearchContent = _T("point;rectangle;circle;ole object;")；
	SetSearchContent(strSearchContent);
}

void CMFCApplication20180914Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMFCApplication20180914Doc 诊断

#ifdef _DEBUG
void CMFCApplication20180914Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFCApplication20180914Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMFCApplication20180914Doc 命令


BOOL CMFCApplication20180914Doc::OnOpenDocument(LPCTSTR lpszPathName)
{
	//if (!CDocument::OnOpenDocument(lpszPathName))
	//	return FALSE;

	// TODO:  在此添加您专用的创建代码
	HRESULT hr;
	m_pImage = new CImage();
	hr= m_pImage->Load(lpszPathName);
	if (S_OK!=hr)
	{
		return FALSE;
	}
	theApp.m_iCntpix++;
	return TRUE;
}


BOOL CMFCApplication20180914Doc::OnSaveDocument(LPCTSTR lpszPathName)
{
	// TODO: 在此添加专用代码和/或调用基类
	m_pImage->Save(lpszPathName, Gdiplus::ImageFormatJPEG);
	return CDocument::OnSaveDocument(lpszPathName);
}
