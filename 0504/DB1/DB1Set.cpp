
// DB1Set.cpp : CDB1Set ���ʵ��
//

#include "stdafx.h"
#include "DB1.h"
#include "DB1Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDB1Set ʵ��

// ���������� 2020��6��29��, 20:16

IMPLEMENT_DYNAMIC(CDB1Set, CRecordset)

CDB1Set::CDB1Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_1 = L"";
	m_2 = L"";
	m_3 = L"";
	m_4 = L"";
	m_nFields = 5;
	m_nDefaultType = snapshot;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CDB1Set::GetDefaultConnect()
{
	return _T("DSN=\x6570\x636e\x6e90-\x5b66\x751f\x4fe1\x606f;DBQ=C:\\Users\\\x6bdb\x5148\x751f\\Documents\\Database2.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CDB1Set::GetDefaultSQL()
{
	return _T("[ѧ����Ϣ��]");
}

void CDB1Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[�ֶ�1]"), m_1);
	RFX_Text(pFX, _T("[�ֶ�2]"), m_2);
	RFX_Text(pFX, _T("[�ֶ�3]"), m_3);
	RFX_Text(pFX, _T("[�ֶ�4]"), m_4);

}
/////////////////////////////////////////////////////////////////////////////
// CDB1Set ���

#ifdef _DEBUG
void CDB1Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CDB1Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

