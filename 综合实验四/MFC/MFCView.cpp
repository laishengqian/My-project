
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
#include "PHOTO.h"
#include "SEARCH.h"
#include "SORT.h"
#include "ALTER.h"
#include "ADD.h"
#include "RECORDSET.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCView

IMPLEMENT_DYNCREATE(CMFCView, CRecordView)

BEGIN_MESSAGE_MAP(CMFCView, CRecordView)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCView::OnBnClickedButton2)
	ON_WM_PAINT()
	ON_COMMAND(ID_32771, &CMFCView::On32771)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCView::OnBnClickedButton3)
	ON_COMMAND(ID_SORT, &CMFCView::OnSort)
	ON_COMMAND(ID_ALTER, &CMFCView::OnAlter)
	ON_COMMAND(ID_32775, &CMFCView::On32775)
	ON_COMMAND(ID_32774, &CMFCView::On32774)
	ON_COMMAND(ID_RECORD, &CMFCView::OnRecord)
END_MESSAGE_MAP()

// CMFCView 构造/析构

CMFCView::CMFCView()
	: CRecordView(IDD_MFC_FORM)
	, id(0)
	, num(0)
	, name(_T(""))
	, age(0)
	, sex(_T(""))
	, pos(_T(""))
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
	Invalidate();
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
	PHOTO dlg;
	CString file;
	GetDlgItemText(IDC_EDIT6, file);
	dlg.pname = file;
	if (dlg.DoModal() == IDOK) {

	}
}

void CMFCView::draw(CString file,int idc) {
	CRect rect;
	CImage img;
	img.Load(file);
	GetClientRect(&rect);
	int sx, sy, h, w;
	CDC *pDC = GetDlgItem(idc)->GetDC();
	GetDlgItem(idc)->GetClientRect(&rect);
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

BOOL IsFileExist(const CString& csFile)
{
	DWORD dwAttrib = GetFileAttributes(csFile);
	return INVALID_FILE_ATTRIBUTES != dwAttrib && 0 == (dwAttrib & FILE_ATTRIBUTE_DIRECTORY);
}

void CMFCView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CRecordView::OnPaint()
	CString file;
	GetDlgItemText(IDC_EDIT6, file);
	if (IsFileExist(file)) {
		draw(file, IDC_STATIC9);
	}
}


void CMFCView::On32771()
{
	// TODO: 在此添加命令处理程序代码
	SEARCH dlg;
	if (dlg.DoModal() == IDOK) {
		//UpdateData(true);
		m_pSet->m_strFilter.Format(_T("%s"),dlg.comd);
		m_pSet->Requery();
		UpdateData(false);
	}
}


void CMFCView::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	m_pSet->m_strFilter = _T("");
	m_pSet->m_strSort = _T("");
	m_pSet->Requery();
	UpdateData(false);
}


void CMFCView::OnSort()
{
	// TODO: 在此添加命令处理程序代码
	SORT dlg;
	if (dlg.DoModal() == IDOK) {
		m_pSet->m_strSort.Format(_T("%s"), dlg.comd);
		m_pSet->Requery();
		UpdateData(false);
	}
}


void CMFCView::OnAlter()
{
	// TODO: 在此添加命令处理程序代码
	ALTER dlg;
	dlg.id = m_pSet->m_ID;
	dlg.num = m_pSet->column1;
	dlg.name = m_pSet->column2;
	dlg.age = m_pSet->column3;
	dlg.sex = m_pSet->column4;
	dlg.pos = m_pSet->column5;
	UpdateData(false);
	if (dlg.DoModal() == IDOK) {
		m_pSet->Edit();
		m_pSet->m_ID = dlg.id;
		m_pSet->column1 = dlg.num;
		m_pSet->column2 = dlg.name;
		m_pSet->column3 = dlg.age;
		m_pSet->column4 = dlg.sex;
		m_pSet->column5 = dlg.pos;
		m_pSet->Update();
		UpdateData(false);
	}
}


void CMFCView::On32775()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->Delete();
	m_pSet->MovePrev();
	if (m_pSet->IsBOF()) {
		m_pSet->MoveFirst();
	}
	UpdateData(false);
}


void CMFCView::On32774()
{
	// TODO: 在此添加命令处理程序代码
	ADD dlg;
	if (dlg.DoModal() == IDOK) {
		m_pSet->AddNew();
		m_pSet->m_ID = dlg.id;
		m_pSet->column1 = dlg.num;
		m_pSet->column2 = dlg.name;
		m_pSet->column3 = dlg.age;
		m_pSet->column4 = dlg.sex;
		m_pSet->column5 = dlg.pos;
		m_pSet->Update();
		UpdateData(false);
	}
}


void CMFCView::OnRecord()
{
	// TODO: 在此添加命令处理程序代码
	RECORDSET dlg;
	int n = m_pSet->GetODBCFieldCount();
	int k=0;
	while (!m_pSet->IsEOF()) {
		CString s[6];
		for (int i = 0; i < n; i++) {
			m_pSet->GetFieldValue((short)i, s[i]);
			dlg.ss[k] += _T("   ");
			dlg.ss[k] += s[i];
		}
		k++;
		m_pSet->MoveNext();
	}
	dlg.k = k;
	if (dlg.DoModal() == IDOK) {

	}
}
