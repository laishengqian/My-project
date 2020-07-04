
// MFC33101View.cpp : CMFC33101View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC33101.h"
#endif

#include "MFC33101Doc.h"
#include "MFC33101View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC33101View

IMPLEMENT_DYNCREATE(CMFC33101View, CView)

BEGIN_MESSAGE_MAP(CMFC33101View, CView)
	ON_WM_CHAR()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC33101View ����/����

CMFC33101View::CMFC33101View()
{
	// TODO: �ڴ˴���ӹ������


	
	

}

CMFC33101View::~CMFC33101View()
{
}

BOOL CMFC33101View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC33101View ����

void CMFC33101View::OnDraw(CDC* pDC)
{
	CMFC33101Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���

	
	CRect cd(200,200,500,400);
	pDC->Rectangle(cd);

	x = cd.left;
	y = cd.bottom;
}


// CMFC33101View ���

#ifdef _DEBUG
void CMFC33101View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC33101View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC33101Doc* CMFC33101View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC33101Doc)));
	return (CMFC33101Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC33101View ��Ϣ�������


void CMFC33101View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
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



void CMFC33101View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	x = point.x;
	y = point.y;


	CView::OnLButtonDown(nFlags, point);
}
