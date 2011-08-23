#ifndef __IEMATH_BASE_HPP__
#define __IEMATH_BASE_HPP__

#include <IEMath\core\iemath_core.hpp>


template<class TReal,U8 Rows,U8 Cols>class Base
{
public:
	enum {NumRows = Rows,NumCols = Cols};

	Base(){
		SetNull();
	}
	VOID SetNull(VOID)
	{
		for(U8 i=0;i<Rows;i++)
		{
			for(U8 j=0;j<Cols;j++)
			{
				m_data[i][j] = 0;
			}
		}
	}
	Base(TReal values[Rows][Cols])
{
		for(U8 i=0;i<Rows;i++)
		{
			for(U8 j=0;j<Cols;j++)
			{
				m_data[i][j] =values[i][j];
			}
		}
}
	VOID SetData(TReal dat,U8 i,U8 j){m_data[i][j]=dat;}
	TReal GetData(U8 i,U8 j){ return m_data[i][j]; }
	TReal* Data(){ return &m_data[0][0];};
	
	// operadores unarios
	Base operator-(VOID)
	{
		Base tmp;
		for(U8 i=0;i<Rows;i++)
		{
			for(U8 j=0;j<Colss;j++)
			{
				tmp.SetData(-(m_data[i][j]),i,j);
			}
		}
		return tmp;
	}

	BOOL IsNull(VOID)
	{
		
		for(U8 i=0;i<Rows;i++)
		{
			for(U8 j=0;j<Cols;j++)
			{
				if(m_data[i][j] == 0){
					return true;
				}				
					
			}
		}
		return false;

	}
	TReal m_data[Rows][Cols];
};


#endif // __IEMATH_BASE_HPP__