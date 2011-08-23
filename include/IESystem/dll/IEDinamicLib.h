#ifndef __DINAMICLIB_H__
#define __DINAMICLIB_H__

#include<Windows.h>

namespace IESystem
{
	
class IEDinamicLib
{
	typedef HMODULE IEMODULE;
public:
	IEDinamicLib(char* library)
	{
		rute = library;
	}
	void startUP()
	{
		pLibrary = LoadLibrary((LPCTSTR)rute);
		if(!pLibrary)
			MessageBoxA(0,"Error: dll not found!","Error of DLL",MB_ICONERROR);
	}

	void* GetProc(char* procname)
	{
		return (void*)GetProcAddress(pLibrary,(LPCSTR) procname);
	}
	void shutDown()
	{
		FreeLibrary(pLibrary);
	}
	~IEDinamicLib(){}

protected:
	IEMODULE pLibrary;
	char* rute;
};
}; // namespace IESystem
#endif