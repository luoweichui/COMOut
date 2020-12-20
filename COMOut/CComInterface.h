#pragma once
#include "IComInterface.h"
#include <map>

class CComInterface : public IComInterface
{
public:
	static CComInterface* GetVirtualObject();
	~CComInterface();

private:
	CComInterface();

public:
	// IUnknown member function
	virtual HRESULT __stdcall QueryInterface(const IID& iid, void **ppv);
	virtual ULONG	__stdcall AddRef();
	virtual ULONG	__stdcall Release();

	// IVirtualChannel member function
	virtual HRESULT  __stdcall Write(long size);
	virtual HRESULT  __stdcall Read(long* port);
	virtual HRESULT  __stdcall SetCallBack(ICallBack* pCallBack, long* callBackID);
	virtual HRESULT  __stdcall ReleaseCallBack(long callBackID);
	virtual HRESULT  __stdcall Test(void);

private:
	static CComInterface* m_obj;
	LONG m_ref{ 0 }; // 组件引用计数
	std::map<int, ICallBack *> m_pCalls;
};
