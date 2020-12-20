#include <comutil.h>
#include <stdio.h>
#include <OAIdl.h>
#include "..\COMOut\IComInterface.h"
#include "Sink.h"
int main()
{
	IUnknown *pUnknown = NULL;
	IComInterface *pIComInterface = NULL;
	HRESULT hResult;
	if (CoInitialize(NULL) != S_OK)
	{
		printf("Initialize COM library failed!\n");
		Sleep(3000);
		CoUninitialize();
		return -1;
	}

	hResult = CoCreateInstance(CLSID_COMTest, NULL,
		CLSCTX_LOCAL_SERVER, IID_IUnknown, (void **)&pUnknown);
	if (FAILED(hResult))
	{
		printf("Create object failed!\n");
		Sleep(3000);
		CoUninitialize();
		return -2;
	}

	hResult = pUnknown->QueryInterface(IID_IComInterface, (void **)&pIComInterface);
	if (FAILED(hResult))
	{
		pUnknown->Release();
		printf("QueryInterface IID_IComInterface failed hResult=%d erro=%d!\n", hResult, GetLastError());
		Sleep(3000);
		CoUninitialize();
		return -3;
	}

	CSink *m_pSinkCallBack = new CSink();
	m_pSinkCallBack->AddRef();
	long backID;
	pIComInterface->SetCallBack(m_pSinkCallBack, &backID);
	while (true)
	{
		pIComInterface->Test();
		Sleep(1000);
	}

	pIComInterface->Release();
	CoUninitialize();
	return 0;
}