// ALTER.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC.h"
#include "ALTER.h"
#include "afxdialogex.h"


// ALTER 对话框

IMPLEMENT_DYNAMIC(ALTER, CDialogEx)

ALTER::ALTER(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG4, pParent)
	, id(0)
	, num(0)
	, name(_T(""))
	, age(0)
	, sex(_T(""))
	, pos(_T(""))
{

}

ALTER::~ALTER()
{
}

void ALTER::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, id);
	DDX_Text(pDX, IDC_EDIT2, num);
	DDX_Text(pDX, IDC_EDIT3, name);
	DDX_Text(pDX, IDC_EDIT4, age);
	DDX_Text(pDX, IDC_EDIT5, sex);
	DDX_Text(pDX, IDC_EDIT6, pos);
}


BEGIN_MESSAGE_MAP(ALTER, CDialogEx)
END_MESSAGE_MAP()


// ALTER 消息处理程序
