
// MFC33102View.cpp : CMFC33102View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC33102.h"
#endif

#include "MFC33102Doc.h"
#include "MFC33102View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC33102View

IMPLEMENT_DYNCREATE(CMFC33102View, CView)

BEGIN_MESSAGE_MAP(CMFC33102View, CView)
	ON_WM_CHAR()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC33102View ����/����

CMFC33102View::CMFC33102View()
{
	// TODO: �ڴ˴���ӹ������


}

CMFC33102View::~CMFC33102View()
{
}

BOOL CMFC33102View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC33102View ����

void CMFC33102View::OnDraw(CDC* pDC)
{
	CMFC33102Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CRect cd(200, 200, 500, 400);
	pDC->Rectangle(cd);

	x = cd.left;
	y = cd.bottom;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC33102View ���

#ifdef _DEBUG
void CMFC33102View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC33102View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC33102Doc* CMFC33102View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC33102Doc)));
	return (CMFC33102Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC33102View ��Ϣ�������


void CMFC33102View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
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


void CMFC33102View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	x = point.x;
	y = point.y;

	CView::OnLButtonDown(nFlags, point);
}
