#ifndef __QUEUE_H__
#define __QUEUE_H__

#ifndef NULL
#define NULL 0
#endif

namespace IEStd
{

	template<class T>
	class queue
	{
	public:
		queue()
		{
			_begin=end=NULL;
		}

		void push(T item)
		{
			Node* _new = new Node(item);

			if(empty())
			{
				_begin=_new;
			}else{
				end->_next= _new;
			}
			end=_new;
		}

		T pop()
		{
			if(empty()) throw "this queue is empty";

			T aux =  _begin->_item;
			Node*a=_begin;
			_begin=_begin->_next;
			delete a;
			return aux;
		}

		void erase()
		{
			for(;_begin != NULL;)
			{
				Node*a;
				a=_begin;
				_begin =  _begin->_next;
				delete a;
			}
			end= NULL;
		}

		T begin() const
		{
			if(empty()) throw "this queue us empty";
			 return _begin->_item;
		}

		bool empty() const
		{
			return _begin == NULL;
		}

		~queue()
		{
			erase();
		}
	protected:
		class Node
		{
		public:
			Node* _next;
			T _item;
			Node(T x)
			{
				_item=x;
				_next=NULL;
			}
		};

		Node* _begin,*end;
	};

};
#endif /* __QUEUE_H__ */