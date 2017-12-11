#ifndef ListNumber_H
#define ListNumber_H

#include "ElemNumber.h"
#include <cstddef>

template <class T>
class ListNumber
{
private:
    ElemNumber<T> *root;
    ElemNumber<T> *cur;
    int kol;
public:
    ListNumber() { root = NULL; cur = NULL; kol = 0; }
    ListNumber(const ListNumber<T>&);
    ~ListNumber();
    bool isEmpty() { return (kol) ? (false) : (true); }
    void push_back(T val);
    int Size() const {return kol;}
    ListNumber<T>& operator= (const ListNumber<T>&);

    class iterator
    {
    private:
        ElemNumber<T> *p;
        friend class ListNumber;
        void setIterator(ElemNumber<T> *pointer) { p = pointer; }
        void DeleteIterator() {delete p;}
    public:        
        iterator() { p = NULL; }        
        T operator*() { return p->val; }
        bool operator==(iterator r) { return (p == r.p) ? (true) : (false); }
        bool operator!=(iterator r) { return (p != r.p) ? (true) : (false); }
        bool IsDone() {return (!p) ? true : false;}

        iterator &operator++();
        iterator operator++(int unusable);
        iterator& operator +(int);
    };
    iterator begin() const;
    iterator end() const;
    iterator Erase(iterator&);
    void Clean();
};

template <class T>
ListNumber<T>::ListNumber(const ListNumber<T>& obj)
{
    if (!obj.root)
    {
        root = cur = NULL;
        kol = 0;
    }
    else
    {
       ListNumber<T>::iterator it = obj.begin();
       for(; !it.IsDone(); ++it)
           push_back(*it);
    }
}

template <class T>
ListNumber<T>& ListNumber<T>::operator=(const ListNumber& obj)
{
    if (&obj == this)
        return *this;
    if (root)
        Clean();
    if (!obj.root)
        return *this;
    ListNumber<T>::iterator it = obj.begin();
    for(; !it.IsDone(); ++it)
        push_back(*it);
    return *this;
}


template <class T>
ListNumber<T>::~ListNumber()
{
    if (root)
        Clean();
}

template <class T>
void ListNumber<T>::push_back(T val)
{
    if(isEmpty())
    {
        root = new ElemNumber<T>;
        root->val = val;
        cur = root;
    }
    else
    {
        cur->next = new ElemNumber<T>;
        cur = cur->next;
        cur->val = val;
    }
    kol++;
}

template <class T>
typename ListNumber<T>::iterator ListNumber<T>::begin() const
{
    iterator it;

    it.setIterator(root);
    return it;
}

template <class T>
typename ListNumber<T>::iterator ListNumber<T>::end() const
{
    iterator it;

    it.setIterator(NULL);
    return it;
}

template <class T>
typename ListNumber<T>::iterator &ListNumber<T>::iterator::operator++()
{
    if (p->next)
        p = p->next;
    else
        p = NULL;
   return *this;

}

template <class T>
typename ListNumber<T>::iterator ListNumber<T>::iterator::operator++(int unusable)
{
    iterator it = *this;
    if (p->next)
        p = p->next;
    return it;
}

template <class T>
typename ListNumber<T>::iterator& ListNumber<T>::iterator::operator +(int value)
{
    for (int i = 0; i < value; i++)
        if (p->next)
            p = p->next;
    return *this;
}

template <class T>
typename ListNumber<T>::iterator ListNumber<T>::Erase(ListNumber<T>::iterator& it)
{
    ElemNumber<T>* cur = root;
    ElemNumber<T>* prev = NULL;

    for (; cur; cur = cur->next)
    {
        if (it.p == cur)
        {
            if (prev)
                prev->next = cur->next;
            else
            {
                it.p = it.p->next;
                root = cur->next;
            }
            kol -= 1;
            delete cur;
            return it;
        }
        prev = cur;
    }
    return it;
}

template <class T>
void ListNumber<T>::Clean()
{
    if (root)
    {
        for (ListNumber<T>::iterator it = begin(); !it.IsDone(); Erase(it))
            ;
        root = cur = NULL;
    }
}


#endif // LIST_H
