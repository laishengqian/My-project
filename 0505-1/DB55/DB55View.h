
// DB55View.h : CDB55View 类的接口
//

#pragma once

class CDB55Set;

class CDB55View : public CRecordView
{
protected: // 仅从序列化创建
	CDB55View();
	DECLARE_DYNCREATE(CDB55View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_DB55_FORM };
#endif
	CDB55Set* m_pSet;

// 特性
public:
	CDB55Doc* GetDocument() const;

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
	virtual ~CDB55View();
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

#ifndef _DEBUG  // DB55View.cpp 中的调试版本
inline CDB55Doc* CDB55View::GetDocument() const
   { return reinterpret_cast<CDB55Doc*>(m_pDocument); }
#endif

