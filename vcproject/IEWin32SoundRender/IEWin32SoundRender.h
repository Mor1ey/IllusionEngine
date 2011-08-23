// El siguiente bloque ifdef muestra la forma estándar de crear macros que facilitan 
// la exportación de archivos DLL. Todos los archivos de este archivo DLL se compilan con el símbolo IEWIN32SOUNDRENDER_EXPORTS
// definido en la línea de comandos. Este símbolo no debe definirse en ningún proyecto
// que use este archivo DLL. De este modo, otros proyectos cuyos archivos de código fuente incluyan el archivo 
// interpretan que las funciones IEWIN32SOUNDRENDER_API se importan de un archivo DLL, mientras que este archivo DLL interpreta los símbolos
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
	// TODO: agregar métodos aquí.
};

extern IEWIN32SOUNDRENDER_API int nIEWin32SoundRender;

IEWIN32SOUNDRENDER_API int fnIEWin32SoundRender(void);
