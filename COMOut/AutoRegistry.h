#ifndef __Registry_H__
#define __Registry_H__

HRESULT RegisterServer(const CLSID& clsid,
	const char *szFileName,
	const char* szProgID,
	const char* szDescription,
	const char* szVerIndProgID);


HRESULT UnregisterServer(const CLSID& clsid,
	const char* szProgID,
	const char* szVerIndProgID);

#endif