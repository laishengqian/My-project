
// MFC11View.cpp : CMFC11View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC11.h"
#endif

#include "MFC11Doc.h"
#include "MFC11View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC11View

IMPLEMENT_DYNCREATE(CMFC11View, CView)

BEGIN_MESSAGE_MAP(CMFC11View, CView)
	ON_COMMAND(ID_NAME, &CMFC11View::OnName)
END_MESSAGE_MAP()

// CMFC11View ����/����

CMFC11View::CMFC11View()
{
	// TODO: �ڴ˴���ӹ������
	BITMAP BM;
	m_Bitmap.LoadBitmap(IDB_BITMAP1);
	m_Bitmap.GetBitmap(&BM);
	m_nWidth = BM.bmWidth;
	m_nHeight = BM.bmHeight;

}

CMFC11View::~CMFC11View()
{
}

BOOL CMFC11View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC11View ����

void CMFC11View::OnDraw(CDC* pDC)
{
	CMFC11Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CDC MemDC;
	MemDC.CreateCompatibleDC(NULL);
	MemDC.SelectObject(m_Bitmap);
	pDC->BitBlt(0, 0, m_nWidth, m_nHeight, &MemDC, 0, 0, SRCCOPY);
}


// CMFC11View ���

#ifdef _DEBUG
void CMFC11View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC11View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC11Doc* CMFC11View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC11Doc)));
	return (CMFC11Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC11View ��Ϣ�������


void CMFC11View::OnName()
{
	// TODO: �ڴ���������������
	CString s = _T("��ʢǮ");
	CClientDC dc(this);
	dc.TextOutW(500, 300, s);
}
