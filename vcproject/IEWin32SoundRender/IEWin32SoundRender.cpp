// IEWin32SoundRender.cpp: define las funciones exportadas de la aplicación DLL.
//

#include "stdafx.h"
#include "IEWin32SoundRender.h"


// Ejemplo de variable exportada
IEWIN32SOUNDRENDER_API int nIEWin32SoundRender=0;

// Ejemplo de función exportada.
IEWIN32SOUNDRENDER_API int fnIEWin32SoundRender(void)
{
	return 42;
}

// Constructor de clase exportada.
// Consultar IEWin32SoundRender.h para definir la clase
CIEWin32SoundRender::CIEWin32SoundRender()
{
	return;
}
