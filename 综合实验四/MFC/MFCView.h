
// MFCView.h : CMFCView 类的接口
//

#pragma once

class CMFCSet;

class CMFCView : public CRecordView
{
protected: // 仅从序列化创建
	CMFCView();
	DECLARE_DYNCREATE(CMFCView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFC_FORM };
#endif
	CMFCSet* m_pSet;

// 特性
public:
	CMFCDoc* GetDocument() const;

// 操作
public:
	void draw(CString file,int idc);
// 重写
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CMFCView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	long id;
	long num;
	CString name;
	long age;
	CString sex;
	CString pos;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnPaint();
	afx_msg void On32771();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnSort();
	afx_msg void OnAlter();
	afx_msg void On32775();
	afx_msg void On32774();
	afx_msg void OnRecord();
};

#ifndef _DEBUG  // MFCView.cpp 中的调试版本
inline CMFCDoc* CMFCView::GetDocument() const
   { return reinterpret_cast<CMFCDoc*>(m_pDocument); }
#endif

