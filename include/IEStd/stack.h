/********************************************************
*														*
*	File: stack.h										*
*	Autor: Keinier Caboverde R.							*
*														*
********************************************************/

#ifndef __STACK_H__
#define __STACK_H__

#include "List.hpp"



namespace IEStd
{

	/*
	*	class: stack
	*	autor: Keinier Caboverde R. <Keinier@gmail.com>
	*/
	template <class T>
	class stack:public list<T>
	{	
	public:

		stack():list<T>()
		{
		}

		void push(T _item)
		{
			this->push_end(_item);
		}

		T pop()
		{
			
			
			if(empty()) throw "stack is empty";

			node<T>* tmp=end();
			T dat; 

			
		
			if((tmp == mPivote))
			{
				dat = tmp->getData();
				mPivote=NULL;
				
				
			}else{
				dat = tmp->getData();

				tmp->getBack()->setNext(NULL);
	
			}
			delete tmp;
			mSize--;
			

			/*tmp->getBack()->setNext(NULL);
			delete tmp;
			mSize--;*/
			return (dat);
			
		}

		node<T>* Top() const
		{
			if(empty()) throw "stack is empty";

			return (this->end()->getData());
		}


		

		virtual ~stack()
		{
			erase();
		}

	};
};

#endif /* __STACK_H__ */