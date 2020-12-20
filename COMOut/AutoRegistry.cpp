#include <objbase.h>
#include <assert.h>

#include "AutoRegistry.h"

BOOL SetKeyAndValue(const char* pszPath,
	const char* szSubkey,
	const char* szValue);


void CLSIDtoString(const CLSID& clsid,
	char* szCLSID,
	int length);


LONG DeleteKey(HKEY hKeyParent, const char* szKeyString);


const int CLSID_STRING_SIZE = 39;


HRESULT RegisterServer(const CLSID& clsid,
	const char *szFileName,
	const char* szProgID,
	const char* szDescription,
	const char* szVerIndProgID)

{
	char szCLSID[CLSID_STRING_SIZE];
	CLSIDtoString(clsid, szCLSID, sizeof(szCLSID));

	char szKey[64];
	strcpy_s(szKey, _countof("CLSID\\"), "CLSID\\");
	strcat_s(szKey, _countof(szKey), szCLSID);

	SetKeyAndValue(szKey, NULL, szDescription);


	SetKeyAndValue(szKey, "LocalServer32", szFileName);


	if (szProgID != NULL) {
		SetKeyAndValue(szKey, "ProgID", szProgID);
		SetKeyAndValue(szProgID, "CLSID", szCLSID);
	}

	if (szVerIndProgID) {
		SetKeyAndValue(szKey, "VersionIndependentProgID",
			szVerIndProgID);

		SetKeyAndValue(szVerIndProgID, NULL, szDescription);
		SetKeyAndValue(szVerIndProgID, "CLSID", szCLSID);
		SetKeyAndValue(szVerIndProgID, "CurVer", szProgID);

		SetKeyAndValue(szProgID, NULL, szDescription);
		SetKeyAndValue(szProgID, "CLSID", szCLSID);
	}

	return S_OK;
}


HRESULT UnregisterServer(const CLSID& clsid,
	const char* szProgID,
	const char* szVerIndProgID)
{

	char szCLSID[CLSID_STRING_SIZE];
	CLSIDtoString(clsid, szCLSID, sizeof(szCLSID));

	char szKey[64];
	strcpy_s(szKey, _countof("CLSID\\"), "CLSID\\");
	strcat_s(szKey, _countof(szCLSID), szCLSID);

	LONG lResult = DeleteKey(HKEY_CLASSES_ROOT, szKey);

	if (szVerIndProgID != NULL)
		lResult = DeleteKey(HKEY_CLASSES_ROOT, szVerIndProgID);

	if (szProgID != NULL)
		lResult = DeleteKey(HKEY_CLASSES_ROOT, szProgID);

	return S_OK;
}

void CLSIDtoString(const CLSID& clsid,
	char* szCLSID,
	int length)
{
	assert(length >= CLSID_STRING_SIZE);
	LPOLESTR wszCLSID = NULL;
	HRESULT hr = StringFromCLSID(clsid, &wszCLSID);
	assert(SUCCEEDED(hr));

	size_t ret;
	wcstombs_s(&ret, szCLSID, length, wszCLSID, length);

	CoTaskMemFree(wszCLSID);
}


LONG DeleteKey(HKEY hKeyParent,           // Parent of key to delete
	const char* lpszKeyChild)  // Key to delete
{
	// Open the child.
	HKEY hKeyChild;
	size_t dsize = strlen(lpszKeyChild) + 1;
	wchar_t* dest = new wchar_t[dsize];
	size_t i;
	mbstowcs_s(&i, dest, dsize, lpszKeyChild, strlen(lpszKeyChild));
	LONG lRes = RegOpenKeyEx(hKeyParent, dest, 0,
		KEY_ALL_ACCESS, &hKeyChild);
	delete[] dest;
	if (lRes != ERROR_SUCCESS)
	{
		return lRes;
	}

	FILETIME time;
	char szBuffer[256];
	DWORD dwSize = 256;
	while (RegEnumKeyExA(hKeyChild, 0, szBuffer, &dwSize, NULL,
		NULL, NULL, &time) == S_OK)
	{
		lRes = DeleteKey(hKeyChild, szBuffer);
		if (lRes != ERROR_SUCCESS)
		{
			RegCloseKey(hKeyChild);
			return lRes;
		}
		dwSize = 256;
	}

	RegCloseKey(hKeyChild);

	return RegDeleteKeyA(hKeyParent, lpszKeyChild);
}


BOOL SetKeyAndValue(const char* szKey,
	const char* szSubkey,
	const char* szValue)
{
	HKEY hKey;
	char szKeyBuf[1024];

	strcpy_s(szKeyBuf, strlen(szKey) + 1, szKey);

	if (szSubkey != NULL)
	{
		strcat_s(szKeyBuf, _countof(szKeyBuf), "\\");
		strcat_s(szKeyBuf, _countof(szKeyBuf), szSubkey);
	}

	size_t dsize = strlen(szKeyBuf) + 1;
	wchar_t* dest = new wchar_t[dsize];
	size_t i;
	mbstowcs_s(&i, dest, dsize, szKeyBuf, strlen(szKeyBuf));
	long lResult = RegCreateKeyEx(HKEY_CLASSES_ROOT,
		dest,
		0, NULL, REG_OPTION_NON_VOLATILE,
		KEY_ALL_ACCESS, NULL,
		&hKey, NULL);
	delete[] dest;
	if (lResult != ERROR_SUCCESS)
	{
		return FALSE;
	}

	// Set the Value.
	if (szValue != NULL)
	{
		RegSetValueExA(hKey, NULL, 0, REG_SZ,
			(BYTE *)szValue,
			strlen(szValue) + 1);
	}

	RegCloseKey(hKey);
	return TRUE;
}
