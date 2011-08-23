#ifndef __DEQUE_H__
#define __DEQUE_H__

#include "queue.h"

#ifndef NULL
#define NULL 0
#endif

namespace IEStd
{

	template<class T>
	class deque:public queue<T>
	{
	public:
		void push_end(T item)
		{
			pop(item);
		}
		void push_begin(T item)
		{
			Node* _new;

			_new =  new Node(item);
			if(empty())
			{
				end=_new;
			}

			_new->_next =  _begin;
			_begin=_new;
		}

		T pop_begin()
		{
			return pop();
		}
		T pop_end()
		{
			T aux;
			if(!empty())
			{
				if(_begin == end)
				{
					aux= pop();
				}else{

					Node* a= _begin;
					while(a->_next != end)
						a=a->_next;
					aux=end->_item;
					end=a;
					delete (a->_next);
				}
				}else
			{
				throw "i do'nt delete of empty queue";

			}
				return aux;
		}
	
	
		unsigned int size()const
		{
			unsigned int n=0;
			Node*a = _begin;

			if(!empty())
			{
				n=1;
				while(a!=end)
				{
					n++;
					a=a->_next;
				}
			}
			return n;
		}
	};
};
#endif