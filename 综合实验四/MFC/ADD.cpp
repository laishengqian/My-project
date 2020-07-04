// ADD.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC.h"
#include "ADD.h"
#include "afxdialogex.h"


// ADD 对话框

IMPLEMENT_DYNAMIC(ADD, CDialogEx)

ADD::ADD(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG5, pParent)
	, id(0)
	, num(0)
	, name(_T(""))
	, age(0)
	, sex(_T(""))
	, pos(_T(""))
{

}

ADD::~ADD()
{
}

void ADD::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, id);
	DDX_Text(pDX, IDC_EDIT2, num);
	DDX_Text(pDX, IDC_EDIT3, name);
	DDX_Text(pDX, IDC_EDIT4, age);
	DDX_Text(pDX, IDC_EDIT5, sex);
	DDX_Text(pDX, IDC_EDIT6, pos);
}


BEGIN_MESSAGE_MAP(ADD, CDialogEx)
END_MESSAGE_MAP()


// ADD 消息处理程序
