
// MFCView.cpp : CMFCView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC.h"
#endif

#include "MFCSet.h"
#include "MFCDoc.h"
#include "MFCView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCView

IMPLEMENT_DYNCREATE(CMFCView, CRecordView)

BEGIN_MESSAGE_MAP(CMFCView, CRecordView)
	ON_COMMAND(ID_RECORD_FIRST, &CMFCView::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CMFCView::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CMFCView::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CMFCView::OnRecordLast)
END_MESSAGE_MAP()

// CMFCView 构造/析构

CMFCView::CMFCView()
	: CRecordView(IDD_MFC_FORM)
	, pname(_T(""))
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码
	path = _T("D:\\新建文件夹 44\\");
}

CMFCView::~CMFCView()
{
}

void CMFCView::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_1);
}

BOOL CMFCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CMFCView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFCSet;
	CRecordView::OnInitialUpdate();

}


// CMFCView 诊断

#ifdef _DEBUG
void CMFCView::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFCView::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFCDoc* CMFCView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCDoc)));
	return (CMFCDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCView 数据库支持
CRecordset* CMFCView::OnGetRecordset()
{
	return m_pSet;
}



// CMFCView 消息处理程序


void CMFCView::OnRecordFirst()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveFirst();
	UpdateData(false);
	CString filename,s;
	GetDlgItemText(IDC_EDIT1, s);
	filename = path + s;
	draw(filename);
}


void CMFCView::OnRecordPrev()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
	CString filename, s;
	GetDlgItemText(IDC_EDIT1, s);
	filename = path + s;
	draw(filename);
}


void CMFCView::OnRecordNext()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveNext();
	if (m_pSet->IsEOF())
		m_pSet->MoveLast();
	UpdateData(false);
	CString filename, s;
	GetDlgItemText(IDC_EDIT1, s);
	filename = path + s;
	draw(filename);
}


void CMFCView::OnRecordLast()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveLast();
	UpdateData(false);
	CString filename, s;
	GetDlgItemText(IDC_EDIT1, s);
	filename = path + s;
	draw(filename);
}

void CMFCView::draw(CString file) {
	CRect rect;
	CImage img;
	img.Load(file);
	GetClientRect(&rect);
	int sx, sy, h, w;
	CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();
	GetDlgItem(IDC_STATIC)->GetClientRect(&rect);
	float rect_radio = 1.0 * rect.Width() / rect.Height();
	float image_radio = 1.0 * img.GetWidth() / img.GetHeight();
	if (rect_radio > image_radio)
	{
		h = rect.Height();
		w = image_radio * h;
		sx = (rect.Width() - w) / 2;
		sy = 0;
	}
	else {
		w = rect.Width();
		h = w / image_radio;
		sx = 0;
		sy = (rect.Height() - h) / 2;
	}
	pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);
}