
// MFC33102View.h : CMFC33102View ��Ľӿ�
//

#pragma once


class CMFC33102View : public CView
{
protected: // �������л�����
	CMFC33102View();
	DECLARE_DYNCREATE(CMFC33102View)

// ����
public:
	CMFC33102Doc* GetDocument() const;

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
	virtual ~CMFC33102View();
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

#ifndef _DEBUG  // MFC33102View.cpp �еĵ��԰汾
inline CMFC33102Doc* CMFC33102View::GetDocument() const
   { return reinterpret_cast<CMFC33102Doc*>(m_pDocument); }
#endif

