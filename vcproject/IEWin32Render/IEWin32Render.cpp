// IEWin32Render.cpp: define las funciones exportadas de la aplicación DLL.
//

#include "stdafx.h"
#include "IEWin32Render.h"


// Ejemplo de variable exportada
IEWIN32RENDER_API int nIEWin32Render=0;

// Ejemplo de función exportada.
IEWIN32RENDER_API int fnIEWin32Render(void)
{
	return 42;
}

// Constructor de clase exportada.
// Consultar IEWin32Render.h para definir la clase
CIEWin32Render::CIEWin32Render()
{
	return;
}
