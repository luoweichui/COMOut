
#include "ComFactory.h"
#include "CComInterface.h"

extern LONG    g_lockNumber;
extern LONG    g_comTestNumber;
extern DWORD   g_dwMainThreadID;
extern "C" const GUID CLSID_COMTest;

CCOMFactory::CCOMFactory() : m_Ref(0)
{

}

CCOMFactory::~CCOMFactory()
{

}

HRESULT CCOMFactory::QueryInterface(const IID& iid, void **ppv)
{
	if (iid == IID_IUnknown)
	{
		*ppv = (IUnknown *) this;
		((IUnknown *)(*ppv))->AddRef();
	}
	else if (iid == IID_IClassFactory)
	{
		*ppv = (IClassFactory *) this;
		((IClassFactory *)(*ppv))->AddRef();
	}
	else
	{
		*ppv = NULL;
		return E_NOINTERFACE;
	}
	return S_OK;
}

ULONG CCOMFactory::AddRef()
{
	return  InterlockedIncrement(&m_Ref);
}

ULONG CCOMFactory::Release()
{
	if (InterlockedDecrement(&m_Ref) == 0)
	{
		delete this;
		return 0;
	}
	return  (ULONG)m_Ref;
}

HRESULT CCOMFactory::CreateInstance(IUnknown *pUnknownOuter, const IID& iid, void **ppv)
{
	CComInterface * pObj;
	HRESULT hr;

	*ppv = NULL;
	hr = E_OUTOFMEMORY;
	if (NULL != pUnknownOuter)
	{
		return CLASS_E_NOAGGREGATION;
	}

	pObj = CComInterface::GetVirtualObject();
	if (NULL == pObj)
	{
		return hr;
	}

	hr = pObj->QueryInterface(iid, ppv);

	if (hr != S_OK)
	{
		InterlockedDecrement(&g_comTestNumber);
		delete pObj;
	}
	return hr;
}

HRESULT CCOMFactory::LockServer(BOOL bLock)
{
	if (bLock)
	{
		InterlockedIncrement(&g_lockNumber);
	}
	else
	{
		InterlockedDecrement(&g_lockNumber);
		if (CanUnloadNow())
		{
		}
	}

	return NOERROR;
}

CCOMFactory *CCOMFactory::theFactory = NULL;
DWORD CCOMFactory::dwRegister = 0;

BOOL CCOMFactory::RegisterFactory()
{
	theFactory = new CCOMFactory();
	theFactory->AddRef();
	IUnknown *pUnkForFactory = (IUnknown  *)theFactory;

	HRESULT hr = ::CoRegisterClassObject(
		CLSID_COMTest,
		pUnkForFactory,
		CLSCTX_LOCAL_SERVER,
		REGCLS_MULTIPLEUSE,
		&dwRegister);
	if (FAILED(hr))
	{
		theFactory->Release();
		return FALSE;
	}
	return TRUE;
}

void CCOMFactory::UnregisterFactory()
{
	if (dwRegister != 0)
	{
		::CoRevokeClassObject(dwRegister);
	}

	if (theFactory != NULL)
	{
		theFactory->Release();
	}
}

BOOL CCOMFactory::CanUnloadNow()
{
	if (g_lockNumber > 0 || g_comTestNumber > 0)
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}