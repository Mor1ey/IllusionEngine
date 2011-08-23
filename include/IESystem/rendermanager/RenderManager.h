#ifndef __IERENDERMANAGER_H__
#define __IERENDERMANAGER_H__
#include <utility.h>
#include <IEAtom.h>

#include <IESystem\manager.h>

#include <IESystem\dll\IEDinamicLib.h> // only win32

namespace IESystem
{
	
	class RenderManager:public Manager
	{
	public:
		// ctor
		RenderManager();
		//dstor
		~RenderManager();

	virtual VOID startUp(); 
	virtual VOID shutDown();

	protected:
	};


	class IERender
	{
	public:
		// ctor
		IERender(){}
		//dtor
		virtual ~IERender(){}

		// operations
		//START UP
		virtual U8 startUP() = 0;

		//SHUTDOWN
		virtual VOID shutDOWN() = 0;

		//draw
		virtual VOID drawIt() = 0;



	};


	// for windows
	class IERenderWin32:public IERender
	{
		// ctor
		IERenderWin32(){}
		//dtor
		virtual ~IERenderWin32(){}

		// operations
		//START UP
		virtual U8 startUP();

		//SHUTDOWN
		virtual VOID shutDOWN();

		//draw
		virtual VOID drawIt();
	};

	
	// for linux
	class IERenderLnx32:public IERender
	{
		// ctor
		IERenderLnx32(){}
		//dtor
		virtual ~IERenderLnx32(){}

		// operations
		//START UP
		virtual U8 startUP();

		//SHUTDOWN
		virtual VOID shutDOWN();

		//draw
		virtual VOID drawIt();
	};


}; // namespace IESystem

#endif