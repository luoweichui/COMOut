#include <iostream>
#include <Windows.h>
#include "AutoRegistry.h"
#include "IComInterface.h"
#include "ComFactory.h"

void ComRegistrybyParam(char* cmdLine)
{
	char szTokens[] = "-/";
	HRESULT retVal = 0;
	char *next_token = NULL;
	char* szToken = strtok_s(cmdLine, szTokens, &next_token);
	while (szToken != NULL)
	{
		if (_stricmp(szToken, "RegServer") == 0)
		{
			char szModule[1024] = "E:\\code\\COMOut\\Debug\\COMOut.exe";
			retVal = RegisterServer(CLSID_COMTest,
				szModule,
				"CLSID_COMTest.Object",
				"CLSID_COMTest Component",
				NULL);
			printf("RegisterServer ret=%d", retVal);
		}
		else if (_stricmp(szToken, "UnregServer") == 0)
		{
			retVal = UnregisterServer(CLSID_COMTest,
				"CLSID_COMTest.Object", NULL);
			printf("UnregServer ret=%d", retVal);
		}
		else if (_stricmp(szToken, "Embedding") == 0)
		{
			printf("Embedding");
		}
		szToken = strtok_s(NULL, szTokens, &next_token);
	}
}

int main(int argc, char *argv[])
{
	if (argc >= 2)
	{
		ComRegistrybyParam(argv[1]);
	}
	CoInitializeEx(NULL, COINIT_MULTITHREADED);
	CCOMFactory::RegisterFactory();
	while (true)
	{
		Sleep(500);
	}
	CCOMFactory::UnregisterFactory();
	CoUninitialize();
	return 0;
}