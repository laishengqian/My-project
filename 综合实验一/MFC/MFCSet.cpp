
// MFCSet.cpp : CMFCSet 类的实现
//

#include "stdafx.h"
#include "MFC.h"
#include "MFCSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCSet 实现

// 代码生成在 2020年5月24日 星期日, 23:45

IMPLEMENT_DYNAMIC(CMFCSet, CRecordset)

CMFCSet::CMFCSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_1 = L"";
	m_nFields = 2;
	m_nDefaultType = snapshot;
}
//#error 安全问题: 连接字符串可能包含密码。
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
CString CMFCSet::GetDefaultConnect()
{
	return _T("DSN=\x6570\x636e\x6e90_\x7efc\x5408\x5b9e\x9a8c\x4e00;DBQ=C:\\Users\\Administrator\\Documents\\Office\x6570\x636e\x5e93\\Test1Data.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;PWD=991015;UID=admin;");
}

CString CMFCSet::GetDefaultSQL()
{
	return _T("[表1]");
}

void CMFCSet::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[字段1]"), m_1);

}
/////////////////////////////////////////////////////////////////////////////
// CMFCSet 诊断

#ifdef _DEBUG
void CMFCSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CMFCSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

