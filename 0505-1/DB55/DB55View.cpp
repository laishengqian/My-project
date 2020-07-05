
// DB55View.cpp : CDB55View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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

// CDB55View ����/����

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
	// TODO: �ڴ˴���ӹ������

}

CDB55View::~CDB55View()
{
}

void CDB55View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
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
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

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


// CDB55View ���

#ifdef _DEBUG
void CDB55View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CDB55View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CDB55Doc* CDB55View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDB55Doc)));
	return (CDB55Doc*)m_pDocument;
}
#endif //_DEBUG


// CDB55View ���ݿ�֧��
CRecordset* CDB55View::OnGetRecordset()
{
	return m_pSet;
}



// CDB55View ��Ϣ�������
