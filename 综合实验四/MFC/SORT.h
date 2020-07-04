#pragma once


// SORT 对话框

class SORT : public CDialogEx
{
	DECLARE_DYNAMIC(SORT)

public:
	SORT(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~SORT();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString comd;
};
