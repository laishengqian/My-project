
// MFC0302-1View.cpp : CMFC03021View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC0302-1.h"
#endif

#include "MFC0302-1Doc.h"
#include "MFC0302-1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC03021View

IMPLEMENT_DYNCREATE(CMFC03021View, CView)

BEGIN_MESSAGE_MAP(CMFC03021View, CView)
END_MESSAGE_MAP()

// CMFC03021View ����/����

CMFC03021View::CMFC03021View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC03021View::~CMFC03021View()
{
}

BOOL CMFC03021View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC03021View ����

void CMFC03021View::OnDraw(CDC* pDC)
{
	CMFC03021Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CString s = _T("������ʢǮ");
	pDC->TextOutW(300, 250, s);
	int a = 115;
	CString t;
	t.Format(_T("%d"), a);
	pDC->TextOutW(300, 300, t);
}


// CMFC03021View ���

#ifdef _DEBUG
void CMFC03021View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC03021View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC03021Doc* CMFC03021View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC03021Doc)));
	return (CMFC03021Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC03021View ��Ϣ�������
