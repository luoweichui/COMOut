

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


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


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_ICallBack,0x8A26B267,0x20B6,0x48BE,0xA6,0xA1,0x7E,0x36,0xB2,0x07,0x4D,0xD3);


MIDL_DEFINE_GUID(IID, IID_IComInterface,0x7799FC42,0x7048,0x4FDD,0x80,0x35,0xDC,0x18,0x72,0xA9,0xF9,0x5E);


MIDL_DEFINE_GUID(IID, LIBID_IComInterfaceLib,0x9BBD854F,0x970A,0x4ABD,0x91,0x7E,0xFF,0x73,0x6C,0x8C,0x86,0xCB);


MIDL_DEFINE_GUID(CLSID, CLSID_CComInterface,0x6779B5C9,0x3F74,0x47CA,0x88,0x00,0x5D,0xC8,0xA7,0xF9,0xFD,0x55);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



