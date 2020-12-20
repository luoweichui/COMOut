#include "CComInterface.h"
#include "ComFactory.h"
#include <stdio.h>

LONG    g_lockNumber = 0;
LONG    g_comTestNumber = 0;
DWORD	g_dwMainThreadID = 0;
LONG    g_ser = 0;

CComInterface* CComInterface::m_obj = NULL;
CComInterface* CComInterface::GetVirtualObject()
{
	if (m_obj == NULL)
	{
		m_obj = new CComInterface();
	}
	return m_obj;
}

CComInterface::~CComInterface()
{
	if (CCOMFactory::CanUnloadNow())
	{
		// TODO: ½áÊøCOM
	}
}


CComInterface::CComInterface()
{
	InterlockedIncrement(&g_comTestNumber);
}


HRESULT CComInterface::QueryInterface(const IID& iid, void **ppv)
{
	if (iid == IID_IUnknown)
	{
		*ppv = (IComInterface *) this;
		((IComInterface *)(*ppv))->AddRef();
	}
	else if (iid == IID_IComInterface)
	{
		*ppv = (IComInterface *) this;
		((IComInterface *)(*ppv))->AddRef();
	}
	else
	{
		*ppv = NULL;
		return E_NOINTERFACE;
	}

	return S_OK;
}

ULONG CComInterface::AddRef()
{
	return  InterlockedIncrement(&m_ref);
}

ULONG CComInterface::Release()
{
	if (InterlockedDecrement(&m_ref) == 0) {
		InterlockedDecrement(&g_comTestNumber);
		delete this;
		return 0;
	}
	return  (ULONG)m_ref;
}

HRESULT CComInterface::Write(long size)
{
	printf("Write %d", size);
	return S_OK;
}

HRESULT CComInterface::Read(long* port)
{
	*port = 10;
	printf("Read %d", *port);
	return S_OK;
}

HRESULT CComInterface::SetCallBack(ICallBack* pCallBack, long* callBackID)
{
	printf("pCallBack\n");
	if (pCallBack == NULL)
	{
		return S_FALSE;
	}

	*callBackID = g_ser;
	m_pCalls[g_ser] = pCallBack;
	g_ser++;
	ULONG ref = pCallBack->AddRef();
	return S_OK;
}

HRESULT CComInterface::ReleaseCallBack(long callBackID)
{
	printf("ReleaseCallBack\n");
	auto& it = m_pCalls.find(callBackID);
	if (it != m_pCalls.end())
	{
		ICallBack* back = it->second;
		back->Release();
		back = NULL;
		m_pCalls.erase(it);
		return S_OK;
	}
	return S_FALSE;
}

HRESULT CComInterface::Test(void)
{
	printf("Test\n");
	for (auto&it : m_pCalls)
	{
		it.second->SendMsgToClinet(3);
	}
	return S_OK;
}