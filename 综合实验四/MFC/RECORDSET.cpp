// RECORDSET.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC.h"
#include "RECORDSET.h"
#include "afxdialogex.h"


// RECORDSET 对话框

IMPLEMENT_DYNAMIC(RECORDSET, CDialogEx)

RECORDSET::RECORDSET(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG6, pParent)
{

}

RECORDSET::~RECORDSET()
{
}

void RECORDSET::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, lbox);
}


BEGIN_MESSAGE_MAP(RECORDSET, CDialogEx)
END_MESSAGE_MAP()


// RECORDSET 消息处理程序


BOOL RECORDSET::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	for (int i = 0; i < k; i++) {
		lbox.InsertString(-1, ss[i]);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
