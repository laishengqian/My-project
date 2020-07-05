
// DB55View.cpp : CDB55View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "DB55.h"
#endif

#include "DB55Set.h"
#include "DB55Doc.h"
#include "DB55View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDB55View

IMPLEMENT_DYNCREATE(CDB55View, CRecordView)

BEGIN_MESSAGE_MAP(CDB55View, CRecordView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CDB55View 构造/析构

CDB55View::CDB55View()
	: CRecordView(IDD_DB55_FORM)
	, ID(0)
	, number(_T(""))
	, name(_T(""))
	, sex(_T(""))
	, age(_T(""))
	, phone(_T(""))
	, photo(_T(""))
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码

}

CDB55View::~CDB55View()
{
}

void CDB55View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_ID);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->m_1);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->m_2);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->m_3);
	DDX_Text(pDX, IDC_EDIT5, m_pSet->m_4);
	//DDX_Text(pDX, IDC_EDIT6, m_pSet->m_5);
	//DDX_Text(pDX, IDC_EDIT7, m_pSet->m_6);
}

BOOL CDB55View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CDB55View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_DB55Set;
	CRecordView::OnInitialUpdate();

}

void CDB55View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CDB55View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CDB55View 诊断

#ifdef _DEBUG
void CDB55View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CDB55View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CDB55Doc* CDB55View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDB55Doc)));
	return (CDB55Doc*)m_pDocument;
}
#endif //_DEBUG


// CDB55View 数据库支持
CRecordset* CDB55View::OnGetRecordset()
{
	return m_pSet;
}



// CDB55View 消息处理程序
