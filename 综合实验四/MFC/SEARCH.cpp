// SEARCH.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC.h"
#include "SEARCH.h"
#include "afxdialogex.h"


// SEARCH 对话框

IMPLEMENT_DYNAMIC(SEARCH, CDialogEx)

SEARCH::SEARCH(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, comd(_T(""))
{

}

SEARCH::~SEARCH()
{
}

void SEARCH::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, comd);
}


BEGIN_MESSAGE_MAP(SEARCH, CDialogEx)
END_MESSAGE_MAP()


// SEARCH 消息处理程序
