
// DB0505Set.cpp : CDB0505Set ���ʵ��
//

#include "stdafx.h"
#include "DB0505.h"
#include "DB0505Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDB0505Set ʵ��

// ���������� 2020��7��5��, 20:48

IMPLEMENT_DYNAMIC(CDB0505Set, CRecordset)

CDB0505Set::CDB0505Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_1 = L"";
	m_2 = L"";
	m_3 = L"";
	m_4 = L"";
	m_5 = L"";
	m_6 = L"";
	m_nFields = 7;
	m_nDefaultType = snapshot;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CDB0505Set::GetDefaultConnect()
{
	return _T("DSN=\x5b66\x751f\x57fa\x672c\x4fe1\x606f\x8868;DBQ=C:\\Users\\\x6bdb\x5148\x751f\\Documents\\Database55.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CDB0505Set::GetDefaultSQL()
{
	return _T("[55ѧ��������Ϣ��]");
}

void CDB0505Set::DoFieldExchange(CFieldExchange* pFX)
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
	RFX_Text(pFX, _T("[�ֶ�5]"), m_5);
	RFX_Text(pFX, _T("[�ֶ�6]"), m_6);

}
/////////////////////////////////////////////////////////////////////////////
// CDB0505Set ���

#ifdef _DEBUG
void CDB0505Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CDB0505Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

