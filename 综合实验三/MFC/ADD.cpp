// ADD.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC.h"
#include "ADD.h"
#include "afxdialogex.h"


// ADD 对话框

IMPLEMENT_DYNAMIC(ADD, CDialogEx)

ADD::ADD(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, id(0)
	, name(_T(""))
	, number(_T(""))
	, c(_T(""))
	, sex(_T(""))
	, birth(_T(""))
	, pnumber(_T(""))
	, address(_T(""))
	, ppos(_T(""))
{

}

ADD::~ADD()
{
}

void ADD::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, id);
	DDX_Text(pDX, IDC_EDIT2, name);
	DDX_Text(pDX, IDC_EDIT3, number);
	DDX_Text(pDX, IDC_EDIT4, c);
	DDX_Text(pDX, IDC_EDIT5, sex);
	DDX_Text(pDX, IDC_EDIT6, birth);
	DDX_Text(pDX, IDC_EDIT7, pnumber);
	DDX_Text(pDX, IDC_EDIT8, address);
	DDX_Text(pDX, IDC_EDIT9, ppos);
}


BEGIN_MESSAGE_MAP(ADD, CDialogEx)
END_MESSAGE_MAP()


// ADD 消息处理程序
