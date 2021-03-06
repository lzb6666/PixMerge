
// MFCApplication20180914Doc.h: CMFCApplication20180914Doc 类的接口
//


#pragma once


class CMFCApplication20180914Doc : public CDocument
{
protected: // 仅从序列化创建
	CMFCApplication20180914Doc() noexcept;
	DECLARE_DYNCREATE(CMFCApplication20180914Doc)

// 特性
public:
	CImage * m_pImage;
// 操作
public:
	void mergePix(CImage * pImage_1, CImage * pImage_2);
// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~CMFCApplication20180914Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
};
