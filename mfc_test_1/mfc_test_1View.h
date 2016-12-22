
// mfc_test_1View.h : interface of the Cmfc_test_1View class
//

#pragma once


class Cmfc_test_1View : public CView
{
protected: // create from serialization only
	Cmfc_test_1View();
	DECLARE_DYNCREATE(Cmfc_test_1View)

// Attributes
public:
	Cmfc_test_1Doc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~Cmfc_test_1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in mfc_test_1View.cpp
inline Cmfc_test_1Doc* Cmfc_test_1View::GetDocument() const
   { return reinterpret_cast<Cmfc_test_1Doc*>(m_pDocument); }
#endif

