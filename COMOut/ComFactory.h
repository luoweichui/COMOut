#ifndef __COMFACTORY__
#define __COMFACTORY__
#include <Unknwn.h>

class CCOMFactory : public IClassFactory
{
public:
	CCOMFactory();
	~CCOMFactory();

	//IUnknown members
	HRESULT __stdcall QueryInterface(const IID& iid, void **ppv);
	ULONG __stdcall AddRef();
	ULONG __stdcall Release();

	//IClassFactory members
	HRESULT __stdcall CreateInstance(IUnknown *, const IID& iid, void **ppv);
	HRESULT __stdcall LockServer(BOOL);
public:
	static BOOL RegisterFactory();
	static void UnregisterFactory();
	static BOOL CanUnloadNow();

public:
	static CCOMFactory *theFactory;
	static DWORD dwRegister;

protected:
	LONG  m_Ref;
};

#endif // __COMFACTORY__