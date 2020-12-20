

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Sun Dec 20 19:52:22 2020
 */
/* Compiler settings for COMProxy.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __COMProxy_h_h__
#define __COMProxy_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ICallBack_FWD_DEFINED__
#define __ICallBack_FWD_DEFINED__
typedef interface ICallBack ICallBack;
#endif 	/* __ICallBack_FWD_DEFINED__ */


#ifndef __IComInterface_FWD_DEFINED__
#define __IComInterface_FWD_DEFINED__
typedef interface IComInterface IComInterface;
#endif 	/* __IComInterface_FWD_DEFINED__ */


#ifndef __CComInterface_FWD_DEFINED__
#define __CComInterface_FWD_DEFINED__

#ifdef __cplusplus
typedef class CComInterface CComInterface;
#else
typedef struct CComInterface CComInterface;
#endif /* __cplusplus */

#endif 	/* __CComInterface_FWD_DEFINED__ */


/* header files for imported files */
#include "unknwn.h"
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __ICallBack_INTERFACE_DEFINED__
#define __ICallBack_INTERFACE_DEFINED__

/* interface ICallBack */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ICallBack;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8A26B267-20B6-48BE-A6A1-7E36B2074DD3")
    ICallBack : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SendMsgToClinet( 
            /* [in] */ long port) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICallBackVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICallBack * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICallBack * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICallBack * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SendMsgToClinet )( 
            ICallBack * This,
            /* [in] */ long port);
        
        END_INTERFACE
    } ICallBackVtbl;

    interface ICallBack
    {
        CONST_VTBL struct ICallBackVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICallBack_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICallBack_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICallBack_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICallBack_SendMsgToClinet(This,port)	\
    ( (This)->lpVtbl -> SendMsgToClinet(This,port) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICallBack_INTERFACE_DEFINED__ */


#ifndef __IComInterface_INTERFACE_DEFINED__
#define __IComInterface_INTERFACE_DEFINED__

/* interface IComInterface */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IComInterface;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7799FC42-7048-4FDD-8035-DC1872A9F95E")
    IComInterface : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Write( 
            /* [in] */ long size) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Read( 
            /* [out] */ long *port) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetCallBack( 
            /* [in] */ ICallBack *pCallBack,
            /* [out] */ long *callBackID) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ReleaseCallBack( 
            /* [in] */ long callBackID) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Test( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IComInterfaceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IComInterface * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IComInterface * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IComInterface * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Write )( 
            IComInterface * This,
            /* [in] */ long size);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Read )( 
            IComInterface * This,
            /* [out] */ long *port);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetCallBack )( 
            IComInterface * This,
            /* [in] */ ICallBack *pCallBack,
            /* [out] */ long *callBackID);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ReleaseCallBack )( 
            IComInterface * This,
            /* [in] */ long callBackID);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Test )( 
            IComInterface * This);
        
        END_INTERFACE
    } IComInterfaceVtbl;

    interface IComInterface
    {
        CONST_VTBL struct IComInterfaceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IComInterface_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IComInterface_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IComInterface_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IComInterface_Write(This,size)	\
    ( (This)->lpVtbl -> Write(This,size) ) 

#define IComInterface_Read(This,port)	\
    ( (This)->lpVtbl -> Read(This,port) ) 

#define IComInterface_SetCallBack(This,pCallBack,callBackID)	\
    ( (This)->lpVtbl -> SetCallBack(This,pCallBack,callBackID) ) 

#define IComInterface_ReleaseCallBack(This,callBackID)	\
    ( (This)->lpVtbl -> ReleaseCallBack(This,callBackID) ) 

#define IComInterface_Test(This)	\
    ( (This)->lpVtbl -> Test(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IComInterface_INTERFACE_DEFINED__ */



#ifndef __IComInterfaceLib_LIBRARY_DEFINED__
#define __IComInterfaceLib_LIBRARY_DEFINED__

/* library IComInterfaceLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_IComInterfaceLib;

EXTERN_C const CLSID CLSID_CComInterface;

#ifdef __cplusplus

class DECLSPEC_UUID("6779B5C9-3F74-47CA-8800-5DC8A7F9FD55")
CComInterface;
#endif
#endif /* __IComInterfaceLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


