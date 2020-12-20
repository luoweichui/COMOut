#include "sink.h"
#include <stdio.h>
#include <stdint.h>

CSink::CSink(void) :m_cRef(0)
{
}

CSink::~CSink(void)
{
}

STDMETHODIMP CSink::QueryInterface(const struct _GUID &iid, void ** ppv)
{
	*ppv = NULL;

	if (IID_IUnknown == iid || IID_CallBack == iid)
	{
		*ppv = this;
	}
	if (NULL != *ppv)
	{
		((LPUNKNOWN)*ppv)->AddRef();
		return  S_OK;
	}

	return ResultFromScode(E_NOINTERFACE);
}

ULONG __stdcall CSink::AddRef()
{
	return InterlockedIncrement(&m_cRef);;
}

ULONG __stdcall CSink::Release()
{
	if (InterlockedDecrement(&m_cRef) == 0)
	{
		delete this;
		return 0;
	}

	return  (ULONG)m_cRef;
}


HRESULT __stdcall CSink::SendMsgToClinet(long port)
{
	printf("wwwww port=%d\n", port);
	return S_OK;
}


