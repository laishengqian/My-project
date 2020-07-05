
// DB0505View.h : CDB0505View 类的接口
//

#pragma once

class CDB0505Set;

class CDB0505View : public CRecordView
{
protected: // 仅从序列化创建
	CDB0505View();
	DECLARE_DYNCREATE(CDB0505View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_DB0505_FORM };
#endif
	CDB0505Set* m_pSet;

// 特性
public:
	CDB0505Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CDB0505View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	long ID;
	CString number;
	CString name;
	CString sex;
	CString age;
protected:
	CString phone;
public:
	CString photo;
	afx_msg void OnBnClickedButton1();
};

#ifndef _DEBUG  // DB0505View.cpp 中的调试版本
inline CDB0505Doc* CDB0505View::GetDocument() const
   { return reinterpret_cast<CDB0505Doc*>(m_pDocument); }
#endif

