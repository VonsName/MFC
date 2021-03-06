
// MFCApp1View.cpp: CMFCApp1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApp1.h"
#endif

#include "MFCApp1Doc.h"
#include "MFCApp1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApp1View

IMPLEMENT_DYNCREATE(CMFCApp1View, CView)

BEGIN_MESSAGE_MAP(CMFCApp1View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCApp1View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMFCApp1View 构造/析构

CMFCApp1View::CMFCApp1View()
{
	// TODO: 在此处添加构造代码

}

CMFCApp1View::~CMFCApp1View()
{
}

BOOL CMFCApp1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApp1View 绘图

void CMFCApp1View::OnDraw(CDC* /*pDC*/)
{
	CMFCApp1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCApp1View 打印


void CMFCApp1View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCApp1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCApp1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCApp1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CMFCApp1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCApp1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCApp1View 诊断

#ifdef _DEBUG
void CMFCApp1View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApp1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApp1Doc* CMFCApp1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApp1Doc)));
	return (CMFCApp1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApp1View 消息处理程序
