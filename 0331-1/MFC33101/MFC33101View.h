
// MFC33101View.h : CMFC33101View ��Ľӿ�
//

#pragma once


class CMFC33101View : public CView
{
protected: // �������л�����
	CMFC33101View();
	DECLARE_DYNCREATE(CMFC33101View)

// ����
public:
	CMFC33101Doc* GetDocument() const;

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
	virtual ~CMFC33101View();
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

#ifndef _DEBUG  // MFC33101View.cpp �еĵ��԰汾
inline CMFC33101Doc* CMFC33101View::GetDocument() const
   { return reinterpret_cast<CMFC33101Doc*>(m_pDocument); }
#endif

