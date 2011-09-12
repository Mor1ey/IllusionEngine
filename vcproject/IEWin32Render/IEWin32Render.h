// El siguiente bloque ifdef muestra la forma est�ndar de crear macros que facilitan 
// la exportaci�n de archivos DLL. Todos los archivos de este archivo DLL se compilan con el s�mbolo IEWIN32RENDER_EXPORTS
// definido en la l�nea de comandos. Este s�mbolo no debe definirse en ning�n proyecto
// que use este archivo DLL. De este modo, otros proyectos cuyos archivos de c�digo fuente incluyan el archivo 
// interpretan que las funciones IEWIN32RENDER_API se importan de un archivo DLL, mientras que este archivo DLL interpreta los s�mbolos
// definidos en esta macro como si fueran exportados.
#ifdef IEWIN32RENDER_EXPORTS
#define IEWIN32RENDER_API __declspec(dllexport)
#else
#define IEWIN32RENDER_API __declspec(dllimport)
#endif

// Clase exportada de IEWin32Render.dll
class IEWIN32RENDER_API CIEWin32Render {
public:
	CIEWin32Render(void);
	// TODO: agregar m�todos aqu�.
};

extern IEWIN32RENDER_API int nIEWin32Render;

IEWIN32RENDER_API int fnIEWin32Render(void);
