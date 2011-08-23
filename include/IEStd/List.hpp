/*
// @File: List.hpp
// @Autor: Keinier Caboverde Ramirez <Keinier@gmail.com>
// @Date: 26th july of 2011
//
// @Description: This file have a several functions for managament of data at disposed in list
//
*/

#ifndef __LIST_H__
#define __LIST_H__


#include "root.hpp"


namespace IEStd
{

template<class T>
class list:public root<T>
{
public:
	list():root(){ }
	virtual ~list(){erase();}

	

	// inserts in the list //

	VOID push_front(T data)
	{
		node<T> *_tmp = new  node<T>(data);
		_tmp->setBack(NULL);
		_tmp->setNext(this->mPivote);
		if(mPivote!=NULL){
		this->mPivote->setBack(_tmp);
		}
		this->mPivote=_tmp;
		mSize++;
	}

	VOID push_end(T data)
	{
		node<T>* it = this->end();
		if(it == NULL)
		{
			mPivote = new node<T>(data);
			mPivote->setBack(NULL);
			mPivote->setNext(NULL);
		}else{
			it->setNext(new node<T>(data));
			it->getNext()->setBack(it);
		}
		mSize++;
	}

	VOID insert(node<T>* prev,T data)
	{
		node<T> *it =  new node<T>(data);
		it->setNext(prev->getNext());
		it->setBack(prev);
		prev->setNext(it);
		mSize++;
	}

	// location
	node<T>* end(VOID) const
	{
		node<T>* it = this->mPivote;
		if(it == NULL) return(it);
		while(it->getNext()!=NULL) it = it->getNext();
		return (it);
	}

	// share
	node<T>* find(T data)const
	{
		node<T>* it;
		
		for(it=mPivote;it!=NULL;it->getNext())
			if(data == it->getData())
				return it;
		return NULL;
	}
	node<T>* findPos(U32 position)
	{
		node<T>* index;
		U32 i;
		if (0>= position) return NULL;
		index = mPivote;
		for(i=1;(i<position) && (index != NULL);i++)
			index = index->getNext();
		return index;
	}
	// delete
	VOID erase(T data)
	{
		node<T>* dat;
		dat = this->find(data);
		if(dat!=NULL){
		
			if((dat == mPivote))
			{
				mPivote->setBack(NULL);
				mPivote=mPivote->getNext();
				
			}else{
				dat->getBack()->setNext(dat->getNext());
				dat->getNext()->setBack(dat->getBack());
			}
			delete dat;
			mSize--;
		}
	}
	VOID erase(VOID)
	{
		while(this->Size())
		{
			erase(mPivote->getData());
		}
	}
};

};

#endif /* __LIST_H__ */