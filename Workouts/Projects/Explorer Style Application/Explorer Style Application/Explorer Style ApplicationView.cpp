
// Explorer Style ApplicationView.cpp : implementation of the CExplorerStyleApplicationView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Explorer Style Application.h"
#endif

#include "Explorer Style ApplicationDoc.h"
#include "Explorer Style ApplicationView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExplorerStyleApplicationView

IMPLEMENT_DYNCREATE(CExplorerStyleApplicationView, CView)

BEGIN_MESSAGE_MAP(CExplorerStyleApplicationView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CExplorerStyleApplicationView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CExplorerStyleApplicationView construction/destruction

CExplorerStyleApplicationView::CExplorerStyleApplicationView()
{
	// TODO: add construction code here

}

CExplorerStyleApplicationView::~CExplorerStyleApplicationView()
{
}

BOOL CExplorerStyleApplicationView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CExplorerStyleApplicationView drawing

void CExplorerStyleApplicationView::OnDraw(CDC* /*pDC*/)
{
	CExplorerStyleApplicationDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CExplorerStyleApplicationView printing


void CExplorerStyleApplicationView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CExplorerStyleApplicationView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CExplorerStyleApplicationView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CExplorerStyleApplicationView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CExplorerStyleApplicationView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CExplorerStyleApplicationView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CExplorerStyleApplicationView diagnostics

#ifdef _DEBUG
void CExplorerStyleApplicationView::AssertValid() const
{
	CView::AssertValid();
}

void CExplorerStyleApplicationView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExplorerStyleApplicationDoc* CExplorerStyleApplicationView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExplorerStyleApplicationDoc)));
	return (CExplorerStyleApplicationDoc*)m_pDocument;
}
#endif //_DEBUG


// CExplorerStyleApplicationView message handlers
