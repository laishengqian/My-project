
// MFC33103View.cpp : CMFC33103View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC33103.h"
#endif

#include "MFC33103Doc.h"
#include "MFC33103View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC33103View

IMPLEMENT_DYNCREATE(CMFC33103View, CView)

BEGIN_MESSAGE_MAP(CMFC33103View, CView)
	ON_WM_CHAR()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC33103View ����/����

CMFC33103View::CMFC33103View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC33103View::~CMFC33103View()
{
}

BOOL CMFC33103View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC33103View ����

void CMFC33103View::OnDraw(CDC* pDC)
{
	CMFC33103Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CRect cd(200, 200, 500, 400);
	pDC->Rectangle(cd);

	x = cd.left;
	y = cd.bottom;


	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC33103View ���

#ifdef _DEBUG
void CMFC33103View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC33103View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC33103Doc* CMFC33103View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC33103Doc)));
	return (CMFC33103Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC33103View ��Ϣ�������


void CMFC33103View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CClientDC dc(this);
	CString A;


	int position;
	int flag;
	CRect Rect(200, 200, 500, 500);


	A.Format(_T("%c"), nChar);

	if (x >= 200 && y >= 200)
	{
		position = (x - 200) / 10 + (y - 200) / 20 * 30;

		c.Insert(position, nChar);

	}

	else
	{
		c.Append(A);
	}

	dc.DrawText(c, Rect, DT_LEFT | DT_WORDBREAK | DT_EDITCONTROL);


	CView::OnChar(nChar, nRepCnt, nFlags);
}


void CMFC33103View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	x = point.x;
	y = point.y;


	CView::OnLButtonDown(nFlags, point);
}
