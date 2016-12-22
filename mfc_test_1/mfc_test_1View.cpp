
// mfc_test_1View.cpp : implementation of the Cmfc_test_1View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "mfc_test_1.h"
#endif

#include "mfc_test_1Doc.h"
#include "mfc_test_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cmfc_test_1View

IMPLEMENT_DYNCREATE(Cmfc_test_1View, CView)

BEGIN_MESSAGE_MAP(Cmfc_test_1View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &Cmfc_test_1View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// Cmfc_test_1View construction/destruction

Cmfc_test_1View::Cmfc_test_1View()
{
	// TODO: add construction code here

}

Cmfc_test_1View::~Cmfc_test_1View()
{
}

BOOL Cmfc_test_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Cmfc_test_1View drawing

void Cmfc_test_1View::OnDraw(CDC* /*pDC*/)
{
	Cmfc_test_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// Cmfc_test_1View printing


void Cmfc_test_1View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL Cmfc_test_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void Cmfc_test_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void Cmfc_test_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void Cmfc_test_1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Cmfc_test_1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Cmfc_test_1View diagnostics

#ifdef _DEBUG
void Cmfc_test_1View::AssertValid() const
{
	CView::AssertValid();
}

void Cmfc_test_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cmfc_test_1Doc* Cmfc_test_1View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cmfc_test_1Doc)));
	return (Cmfc_test_1Doc*)m_pDocument;
}
#endif //_DEBUG


// Cmfc_test_1View message handlers
