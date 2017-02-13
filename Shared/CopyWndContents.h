// ContentMgr.h: interface for the CContentMgr class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_COPYWNDCONTENTS_H__C258D849_69ED_46A7_A2F0_351C5C9FB3B3__INCLUDED_)
#define AFX_COPYWNDCONTENTS_H__C258D849_69ED_46A7_A2F0_351C5C9FB3B3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//////////////////////////////////////////////////////////////////////

class CCopyWndContents
{
public:
	virtual ~CCopyWndContents();

	BOOL DoCopy(CBitmap& bmp);

protected:
	CCopyWndContents(CWnd& wnd);

protected:
	CWnd& m_wnd;

protected:
	virtual int PageDown(int nCurVertPos);
	virtual int PageRight(int nCurHorzPos);
	
	virtual void DoPrint(CDC& dc, int nHPos, int nVPos);
	virtual void DoPageDown();
	virtual void DoPageRight();

	virtual int GetContentVScrollPos() const;
	virtual int GetContentHScrollPos() const;

	virtual CSize CalcContentsSize() const;
	virtual CSize CalcPageSize() const;
	virtual int CalcHeaderHeight() const { return 0; }

	CSize GetContentsSize() const { return m_sizeContent; }
	CSize GetPageSize() const { return m_sizePage; }

	static void DoPrint(HWND hwnd, HDC hdc, DWORD dwFlags = PRF_CLIENT);

private:
	CSize m_sizeContent, m_sizePage;

private:
};

//////////////////////////////////////////////////////////////////////

class CCopyTreeCtrlContents : public CCopyWndContents
{
public:
	CCopyTreeCtrlContents(CTreeCtrl& tree);
	virtual ~CCopyTreeCtrlContents();

protected:
	int m_nItemHeight;
	CTreeCtrl& m_tree;

protected:
	virtual void DoPageDown();
	virtual CSize CalcContentsSize() const;
	virtual CSize CalcPageSize() const;
	virtual int GetContentVScrollPos() const;
};

//////////////////////////////////////////////////////////////////////

class CCopyListCtrlContents : public CCopyWndContents
{
public:
	CCopyListCtrlContents(CListCtrl& list);
	virtual ~CCopyListCtrlContents();

protected:
	int m_nItemHeight;
	CListCtrl& m_list;

protected:
	virtual int PageDown(int nCurVertPos);
	virtual void DoPageDown();
	virtual void DoPrint(CDC& dc, int nHPos, int nVPos);
	virtual CSize CalcContentsSize() const;
	virtual CSize CalcPageSize() const;
	virtual int GetContentVScrollPos() const;
	virtual int CalcHeaderHeight() const;
};

//////////////////////////////////////////////////////////////////////

class CCopyHeaderCtrlContents : public CCopyWndContents
{
public:
	CCopyHeaderCtrlContents(CHeaderCtrl& hdr);
	virtual ~CCopyHeaderCtrlContents();
};

//////////////////////////////////////////////////////////////////////

class CCopyEditContents : public CCopyWndContents
{
public:
	CCopyEditContents(CEdit& edit);
	virtual ~CCopyEditContents();

protected:
	int m_nLineHeight, m_nLineCount;

protected:
	virtual void DoPageDown();
	virtual CSize CalcContentsSize() const;
	virtual CSize CalcPageSize() const;
};

//////////////////////////////////////////////////////////////////////

#endif // AFX_COPYWNDCONTENTS_H__C258D849_69ED_46A7_A2F0_351C5C9FB3B3__INCLUDED_