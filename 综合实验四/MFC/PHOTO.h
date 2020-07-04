#pragma once


// PHOTO 对话框

class PHOTO : public CDialogEx
{
	DECLARE_DYNAMIC(PHOTO)

public:
	PHOTO(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~PHOTO();
	CString pname;
	void draw(CString file);

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};


