// -*- C++ -*-
/* 
 * File:   List.hpp
 * Author: keinier
 *
 * Created on 24 de julio de 2011, 19:31
 * Description:
 *
 * Lista enlazada simple de tipo generico
 */

#ifndef LIST_HPP
#define	LIST_HPP

#include "DataType.hpp"

#ifndef NULL
#define NULL 0
#endif
/*
 * Clase: Nodo <Generico>
 * Autor: Keinier Caboverde <keinier@gmail.com>
 */

template <class T> class Node
{
public:
    // Constructor de la clase
    Node(T t)
    {
        data = t;
        link = NULL;
    }

    Node(T p,Node<T>* n)
    {
        data = p;
        link = n;
    }

    T dataNode()const
    {
        return data;
    }

    Node<T>* linkNode() const
    {
        return link;
    }

    void SetLink(Node<T>* next)
    {
        link = next;
    }
protected:
    T data;
    Node<T>* link;
};



/*
 * Nombre de la Clase: List
 * Autor: Keinier Caboverde R <Keinier@gmail.com>
 */

template <class T> class List
{
public:

    // Constructor por defecto
    List()
    {
        frist= NULL;
    }

    // Metodo para insertar un dato en la lista
   
    VOID insertBegin(T data)
    {
        Node<T> *_new;
        _new =  new Node<T>(data);
        _new->SetLink(frist);
        frist= _new;
    }

    VOID push(T data)
    {
        
        
    }

    VOID insert(Node<T>* ptrlast,T data)
    {
        Node<T>* _new;
        _new = new Node<T>(data);
        _new->SetLink(ptrlast->linkNode());
        ptrlast->SetLink(_new);
    }

    Node<T>* Find(T data)
    {
        Node<T>* index;
        for(index=frist;index!=NULL;index=index->linkNode())
            return index;
    }

    Node<T>* operator[](U32 i)
    {
        Node<T>* index;
        int j;
        if(0>=i)
            index=frist;

        for(j=1;(j<i) && (index != NULL); j++)
            index=index->linkNode();

        return index;
    }

    VOID deleteItem(T data)
    {
        Node<T> *actual,*back;
        BOOL shared;

        actual=frist;
        back=NULL;
        shared =  false;

        while((actual != NULL) && !shared)
        {
            shared= (actual->dataNode() == data);

            if(!shared)
            {
                back=actual;
                actual=actual->linkNode();
            }
        }

        if(actual != NULL)
        {
            if(actual == frist)
            {
                frist=actual->linkNode();
            }else{
                back->SetLink(actual->linkNode());
            }
            delete actual;
        }

    }

    Node<T> * end(void) const
    {
        Node<T> *p = frist;
        if(p == NULL) throw "Error,this list is empty";
        while(p->linkNode() != NULL) p = p->linkNode();

        return p;
    }


protected:
    Node<T>* frist;
    Node<T>* last;
};
#endif	/* LIST_HPP */

