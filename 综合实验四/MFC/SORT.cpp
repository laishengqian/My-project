// SORT.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC.h"
#include "SORT.h"
#include "afxdialogex.h"


// SORT 对话框

IMPLEMENT_DYNAMIC(SORT, CDialogEx)

SORT::SORT(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG3, pParent)
	, comd(_T(""))
{

}

SORT::~SORT()
{
}

void SORT::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, comd);
}


BEGIN_MESSAGE_MAP(SORT, CDialogEx)
END_MESSAGE_MAP()


// SORT 消息处理程序
