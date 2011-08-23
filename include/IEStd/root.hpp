/********************************************************
*														*
*	File: root.h										*
*	Autor: Keinier Caboverde R.							*
*														*
********************************************************/

#ifndef __ROOT_H__
#define __ROOT_H__

#include "../utility.h"
#include "../IEAlloc/allocator.hpp"
namespace IEStd
{

/*
*	class: node
*	autor: Keinier Caboverde R. <Keinier@gmail.com>
*/

	template<class T>
	class node
	{
	public:
		// Construct of node
		node(T data){mData =  data;mBack = mNext = NULL;}
		// Get data of node
		inline T getData(VOID)const{return (mData);}
		// Get pointer to next node
		inline node<T>* getNext(VOID)const{ return (mNext);}
		// Get pointer to back node
		inline node<T>* getBack(VOID)const{ return (mBack);}
		// Set pointer to next node
		inline VOID setNext(node<T>* link){ mNext=link;} 
		// Set pointer ti back node
		inline VOID setBack(node<T>* link){ mBack = link;}

		void* operator new (size_t size)
		{
			return allocateAligned(size,4);
		}
		void operator delete(void* p)
		{
			freeAligned(p);
		}
		virtual ~node(){}

	protected:

		node<T>* mBack; // link to last node
		node<T>* mNext; // link to next node
		
		// Data inside of node
		T mData;
	};



/*
*	class: root
*	autor: Keinier Caboverde R. <Keinier@gmail.com>
*/
	template<class T>
	class root
	{
	public:
		root(){mPivote=NULL;mSize=NULL;}
		virtual ~root(){}
		U32 Size(VOID)const{ return mSize; }
		BOOL empty(VOID)const{ return (mSize==NULL);}
		node<T>* getPivote(VOID)const
		{
			return mPivote;
		}
		PVOID getPPivote(VOID)const { return &mPivote;}
		
		
	protected:
		
		U32 mSize;
		node<T>* mPivote;

	};

	/*
*	class: iterator
*	autor: Keinier Caboverde R. <Keinier@gmail.com>
*/
	

	template<class T>
		class iterator
		{
		public:
			iterator(root<T>* _cont)
			{
				cont=_cont;
				if(!_cont->empty()){
				ptr=cont->getPivote();
				}else{
					ptr=NULL;
				}
				
			}

			virtual ~iterator(){}

			BOOL isBegin()const
			{
				
					ptr=cont->getPivote();
				
				return (ptr->getBack() == NULL);

			}
			BOOL isEnd()const
			{
				
					ptr=cont->getPivote();
				
				return (ptr->getNext() == NULL);
			}

			node<T>* next(VOID)
			{
			
					ptr=cont->getPivote();
				
				ptr=ptr->getNext();
				return (ptr);
			}
			node<T>* back(VOID)
			{
		
					ptr=cont->getPivote();
			
				ptr =  ptr->getBack();
				return (ptr);
			}
			T item(VOID)
			{
				
					ptr=cont->getPivote();
			
				return (ptr->getData());
			}

			T operator[](U32 i)
			{
				
					ptr=cont->getPivote();
			
				node<T>* tmp=ptr;
				U32 ite = 0;
				if(cont->Size()>=i){
				for(ite=0;ite<i;ite++)
				{
					tmp=tmp->getNext();
				}
				}else{
					return NULL;
				}
				return tmp->getData();
				
			}
		
		protected:
			node<T>* ptr;
			root<T>* cont;
		
		};

};

#endif // __ROOT_H__