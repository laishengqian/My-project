
// MFC33103View.h : CMFC33103View ��Ľӿ�
//

#pragma once


class CMFC33103View : public CView
{
protected: // �������л�����
	CMFC33103View();
	DECLARE_DYNCREATE(CMFC33103View)

// ����
public:
	CMFC33103Doc* GetDocument() const;

// ����
public:

	int x, y;
	CPoint m_ptOrigin;
	CString c;


// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC33103View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC33103View.cpp �еĵ��԰汾
inline CMFC33103Doc* CMFC33103View::GetDocument() const
   { return reinterpret_cast<CMFC33103Doc*>(m_pDocument); }
#endif

