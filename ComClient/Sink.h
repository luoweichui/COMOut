

#pragma once
#include "..\COMOut\IComInterface.h"

//�ص�ʵ����
class CSink :public ICallBack
{
protected:
	ULONG m_cRef;
public:
	CSink(void);
	~CSink(void);
	STDMETHOD(QueryInterface)(const struct _GUID &iid,void ** ppv);
	ULONG __stdcall AddRef(void);
	ULONG __stdcall Release(void);
	
	HRESULT __stdcall SendMsgToClinet(long port);
};
