// El siguiente bloque ifdef muestra la forma est�ndar de crear macros que facilitan 
// la exportaci�n de archivos DLL. Todos los archivos de este archivo DLL se compilan con el s�mbolo IEWIN32SOUNDRENDER_EXPORTS
// definido en la l�nea de comandos. Este s�mbolo no debe definirse en ning�n proyecto
// que use este archivo DLL. De este modo, otros proyectos cuyos archivos de c�digo fuente incluyan el archivo 
// interpretan que las funciones IEWIN32SOUNDRENDER_API se importan de un archivo DLL, mientras que este archivo DLL interpreta los s�mbolos
// definidos en esta macro como si fueran exportados.
#ifdef IEWIN32SOUNDRENDER_EXPORTS
#define IEWIN32SOUNDRENDER_API __declspec(dllexport)
#else
#define IEWIN32SOUNDRENDER_API __declspec(dllimport)
#endif
// Clase exportada de IEWin32SoundRender.dll
class IEWIN32SOUNDRENDER_API CIEWin32SoundRender {
public:
	CIEWin32SoundRender(void);
	// TODO: agregar m�todos aqu�.
};

extern IEWIN32SOUNDRENDER_API int nIEWin32SoundRender;

IEWIN32SOUNDRENDER_API int fnIEWin32SoundRender(void);
