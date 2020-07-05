
// DB55View.h : CDB55View ��Ľӿ�
//

#pragma once

class CDB55Set;

class CDB55View : public CRecordView
{
protected: // �������л�����
	CDB55View();
	DECLARE_DYNCREATE(CDB55View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_DB55_FORM };
#endif
	CDB55Set* m_pSet;

// ����
public:
	CDB55Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CDB55View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	long ID;
	CString number;
	CString name;
	CString sex;
	CString age;
	CString phone;
	CString photo;
};

#ifndef _DEBUG  // DB55View.cpp �еĵ��԰汾
inline CDB55Doc* CDB55View::GetDocument() const
   { return reinterpret_cast<CDB55Doc*>(m_pDocument); }
#endif

