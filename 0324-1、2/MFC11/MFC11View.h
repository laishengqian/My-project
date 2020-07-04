
// MFC11View.h : CMFC11View ��Ľӿ�
//

#pragma once


class CMFC11View : public CView
{
protected: // �������л�����
	CMFC11View();
	DECLARE_DYNCREATE(CMFC11View)

// ����
public:
	CMFC11Doc* GetDocument() const;

// ����
public:
	CBitmap m_Bitmap;
	int m_nWidth;
	int m_nHeight;

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC11View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnName();
};

#ifndef _DEBUG  // MFC11View.cpp �еĵ��԰汾
inline CMFC11Doc* CMFC11View::GetDocument() const
   { return reinterpret_cast<CMFC11Doc*>(m_pDocument); }
#endif

