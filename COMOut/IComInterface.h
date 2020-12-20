#ifndef __IComInterface_h__
#define __IComInterface_h__
#include <Unknwn.h>
#include <OAIdl.h>

#include "rpc.h"
#include "rpcndr.h"

#define COM_DLL_EXPORTS
#ifdef COM_DLL_EXPORTS
#   define COM_DLL_API __declspec(dllexport)
#else
#   define COM_DLL_API __declspec(dllimport)
#endif


#pragma warning( disable: 4049 )

#ifndef __ICallBack_FWD_DEFINED__
#define __ICallBack_FWD_DEFINED__
typedef interface ICallBack ICallBack;
#endif

#ifndef __IComInterface_FWD_DEFINED__
#define __IComInterface_FWD_DEFINED__
typedef interface IComInterface IComInterface;
#endif

#ifdef __cplusplus
typedef class CComInterface CComInterface;
#else
typedef struct CComInterface CComInterface;
#endif

#ifdef __cplusplus
extern "C"{
#endif 
	// {A83B5F67-1530-4A1B-AB2F-89B99E653335}
	const GUID CLSID_COMTest = { 0xa83b5f67, 0x1530, 0x4a1b,
	{ 0xab, 0x2f, 0x89, 0xb9, 0x9e, 0x65, 0x33, 0x35 } };

	// {7799FC42-7048-4FDD-8035-DC1872A9F95E}
	const GUID IID_IComInterface = { 0x7799fc42, 0x7048, 0x4fdd,
	{ 0x80, 0x35, 0xdc, 0x18, 0x72, 0xa9, 0xf9, 0x5e } };

	// {8A26B267-20B6-48BE-A6A1-7E36B2074DD3}
	const GUID IID_CallBack = { 0x8a26b267, 0x20b6, 0x48be,
	{ 0xa6, 0xa1, 0x7e, 0x36, 0xb2, 0x7, 0x4d, 0xd3 } };

	/// {9BBD854F-970A-4ABD-917E-FF736C8C86CB}
	const GUID IID_IComInterfaceLib = { 0x9bbd854f, 0x970a, 0x4abd,
	{ 0x91, 0x7e, 0xff, 0x73, 0x6c, 0x8c, 0x86, 0xcb } };

	// {6779B5C9-3F74-47CA-8800-5DC8A7F9FD55}
	const GUID IID_IComInterfaceObject = { 0x6779b5c9, 0x3f74, 0x47ca,
	{ 0x88, 0x0, 0x5d, 0xc8, 0xa7, 0xf9, 0xfd, 0x55 } };

	MIDL_INTERFACE("8A26B267-20B6-48BE-A6A1-7E36B2074DD3")
	ICallBack : public IUnknown
	{
	public:
		virtual HRESULT __stdcall SendMsgToClinet(long port) = 0;
	};

	MIDL_INTERFACE("7799FC42-7048-4FDD-8035-DC1872A9F95E")
	IComInterface : public IUnknown
	{
	public:
		virtual HRESULT  __stdcall Write(long size) = 0;
		virtual HRESULT  __stdcall Read(long* port) = 0;
		virtual HRESULT  __stdcall SetCallBack(ICallBack* pCallBack, long* callBackID) = 0;
		virtual HRESULT  __stdcall ReleaseCallBack(long callBackID) = 0;
		virtual HRESULT  __stdcall Test(void) = 0;
	};

	class DECLSPEC_UUID("6779B5C9-3F74-47CA-8800-5DC8A7F9FD55") CComInterface;

#ifdef __cplusplus
}
#endif

#endif