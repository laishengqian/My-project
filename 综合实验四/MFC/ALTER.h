#pragma once


// ALTER 对话框

class ALTER : public CDialogEx
{
	DECLARE_DYNAMIC(ALTER)

public:
	ALTER(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ALTER();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	long id;
	long num;
	CString name;
	long age;
	CString sex;
	CString pos;
};
