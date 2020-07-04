#pragma once


// ADD 对话框

class ADD : public CDialogEx
{
	DECLARE_DYNAMIC(ADD)

public:
	ADD(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ADD();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	long id;
	CString name;
	CString number;
	CString c;
	CString sex;
	CString birth;
	CString pnumber;
	CString address;
	CString ppos;
};
