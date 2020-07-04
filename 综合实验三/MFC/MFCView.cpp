
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
#include "ADD.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCView

IMPLEMENT_DYNCREATE(CMFCView, CRecordView)

BEGIN_MESSAGE_MAP(CMFCView, CRecordView)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCView::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCView::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCView::OnBnClickedButton3)
END_MESSAGE_MAP()

// CMFCView 构造/析构

CMFCView::CMFCView()
	: CRecordView(IDD_MFC_FORM)
	, id(0)
	, name(_T(""))
	, number(_T(""))
	, c(_T(""))
	, sex(_T(""))
	, birth(_T(""))
	, pnumber(_T(""))
	, address(_T(""))
	, ppos(_T(""))
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码

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
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_ID);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->column1);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->column2);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->column3);
	DDX_Text(pDX, IDC_EDIT5, m_pSet->column4);
	DDX_Text(pDX, IDC_EDIT6, m_pSet->column5);
	DDX_Text(pDX, IDC_EDIT7, m_pSet->column6);
	DDX_Text(pDX, IDC_EDIT8, m_pSet->column7);
	DDX_Text(pDX, IDC_EDIT9, m_pSet->column8);
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


void CMFCView::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	m_pSet->Delete();
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
}


void CMFCView::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	ADD adlg;
	if (adlg.DoModal() == IDOK) {
		m_pSet->AddNew();
		m_pSet->m_ID = adlg.id;
		m_pSet->column1 = adlg.name;
		m_pSet->column2 = adlg.number;
		m_pSet->column3 = adlg.c;
		m_pSet->column4 = adlg.sex;
		m_pSet->column5 = adlg.birth;
		m_pSet->column6 = adlg.pnumber;
		m_pSet->column7 = adlg.address;
		m_pSet->column8 = adlg.ppos;
		m_pSet->Update();
		UpdateData(false);

	}
}


void CMFCView::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	ADD adlg;
	if (adlg.DoModal() == IDOK) {
		m_pSet->Edit();
		if(adlg.id!=0)
			m_pSet->m_ID = adlg.id;
		if(adlg.name!= _T(""))
			m_pSet->column1 = adlg.name;
		if (adlg.number != _T(""))
			m_pSet->column2 = adlg.number;
		if (adlg.c != _T(""))
			m_pSet->column3 = adlg.c;
		if (adlg.sex != _T(""))
			m_pSet->column4 = adlg.sex;
		if (adlg.birth != _T(""))
			m_pSet->column5 = adlg.birth;
		if (adlg.pnumber != _T(""))
			m_pSet->column6 = adlg.pnumber;
		if (adlg.address != _T(""))
			m_pSet->column7 = adlg.address;
		if (adlg.ppos != _T(""))
			m_pSet->column8 = adlg.ppos;
		m_pSet->Update();
		UpdateData(false);
	}
}
