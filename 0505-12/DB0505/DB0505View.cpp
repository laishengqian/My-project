
// DB0505View.cpp : CDB0505View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "DB0505.h"
#endif

#include "DB0505Set.h"
#include "DB0505Doc.h"
#include "DB0505View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDB0505View

IMPLEMENT_DYNCREATE(CDB0505View, CRecordView)

BEGIN_MESSAGE_MAP(CDB0505View, CRecordView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_BN_CLICKED(IDC_BUTTON1, &CDB0505View::OnBnClickedButton1)


	ON_EN_CHANGE(IDC_EDIT3, &CDB0505View::OnEnChangeEdit3)
END_MESSAGE_MAP()

// CDB0505View ����/����

CDB0505View::CDB0505View()
	: CRecordView(IDD_DB0505_FORM)
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

CDB0505View::~CDB0505View()
{
}

void CDB0505View::DoDataExchange(CDataExchange* pDX)
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
	DDX_Text(pDX, IDC_EDIT6, m_pSet->m_5);
	DDX_Text(pDX, IDC_EDIT7, m_pSet->m_6);
}

BOOL CDB0505View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CDB0505View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_DB0505Set;
	CRecordView::OnInitialUpdate();

}

void CDB0505View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CDB0505View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CDB0505View ���

#ifdef _DEBUG
void CDB0505View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CDB0505View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CDB0505Doc* CDB0505View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDB0505Doc)));
	return (CDB0505Doc*)m_pDocument;
}
#endif //_DEBUG


// CDB0505View ���ݿ�֧��
CRecordset* CDB0505View::OnGetRecordset()
{
	return m_pSet;
}



// CDB0505View ��Ϣ�������


void CDB0505View::OnEnChangeEdit3()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CRecordView::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CDB0505View::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	CImage img;
	CString filename;
	CString str1;
	GetDlgItemText(IDC_EDIT7, str1);
	filename = str1;

	img.Load(filename);
	int sx, sy, w, h;
	CDC *pDC = GetDlgItem(IDC_STATIC1)->GetDC();

	CRect rect;
	GetDlgItem(IDC_STATIC1)->GetClientRect(&rect);
	float rect_ratio = 1.0*rect.Width() / rect.Height();
	float img_ratio = 1.0*img.GetWidth() / img.GetHeight();
	if (rect_ratio > img_ratio)
	{
		h = rect.Height();
		w = img_ratio*h;
		sx = (rect.Width() - w) / 2;
		sy = 0;

	}
	else
	{
		w = rect.Width();
		h = w / img_ratio;
		sx = 0;
		sy = (rect.Height() - h) / 2;
	}


	pDC->SetStretchBltMode(HALFTONE);//�ļ���ʧ��
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);

}
