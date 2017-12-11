#ifndef LISTPOINTER_H
#define LISTPOINTER_H

#include "ElemPointer.h"
#include <cstddef>

template <class T>
class ListPointer
{
private:
    ElemPointer<T> *root;
    ElemPointer<T> *cur;
    int kol;

public:
    ListPointer() { root = NULL; cur = NULL; kol = 0; }
    ListPointer(const ListPointer<T>&);
    ~ListPointer();
    bool isEmpty() { return (kol) ? (false) : (true); }
    void push_back(T val);
    int Size() {return kol;}
    ListPointer<T>& operator= (const ListPointer<T>&);

    class iterator
    {
    private:
        friend class ListPointer;

        void setIterator(ElemPointer<T> *pointer) { p = pointer; }
        void deleteIterator() {delete p;}
    public:
        ElemPointer<T> *p;
        iterator() { p = NULL; }
        T operator*() { return p->val; }
        bool operator==(iterator r) { return (p == r.p) ? (true) : (false); }
        bool operator!=(iterator r) { return (p != r.p) ? (true) : (false); }
        bool IsDone() {return (!p) ? true : false;}

        iterator &operator++();
        iterator operator++(int unusable);
        iterator& operator +=(int);
    };
    iterator begin() const;
    iterator end() const;
    iterator erase(iterator&);
    void clean();
};

template <class T>
ListPointer<T>::ListPointer(const ListPointer<T>& obj)
{
    if (!obj.root)
    {
        root = cur = NULL;
        kol = 0;
    }
    else
    {
       ListPointer<T>::iterator it = obj.begin();
       for(; !it.IsDone(); ++it)
           push_back(*it);
    }
}

template <class T>
ListPointer<T>& ListPointer<T>::operator=(const ListPointer& obj)
{
    if (&obj == this)
        return *this;
    if (root)
        clean();
    if (!obj.root)
        return *this;
    ListPointer<T>::iterator it = obj.begin();
    for(; !it.IsDone(); ++it)
        push_back(*it);
    return *this;
}

template <class T>
ListPointer<T>::~ListPointer()
{
    if (root)           
        clean();
}

template <class T>
void ListPointer<T>::push_back(T val)
{
    if(isEmpty())
    {
        root = new ElemPointer<T>;
        root->val = val;
        cur = root;
    }
    else
    {
        cur->next = new ElemPointer<T>;
        cur = cur->next;
        cur->val = val;
    }
    kol++;
}

template <class T>
typename ListPointer<T>::iterator ListPointer<T>::begin() const
{
    iterator it;
    it.setIterator(root);
    return it;
}

template <class T>
typename ListPointer<T>::iterator ListPointer<T>::end() const
{
    iterator it;

    it.setIterator(NULL);
    return it;
}

template <class T>
typename ListPointer<T>::iterator &ListPointer<T>::iterator::operator++()
{
    if (p->next)
        p = p->next;
    else
        p = NULL;
   return *this;

}

template <class T>
typename ListPointer<T>::iterator ListPointer<T>::iterator::operator++(int unusable)
{
    (void)(unusable);
    iterator it = *this;
    if (p->next)
        p = p->next;
    return it;
}

template <class T>
typename ListPointer<T>::iterator& ListPointer<T>::iterator::operator +=(int value)
{
    for (int i = 0; i < value; i++)
        if (p->next)
            p = p->next;
    return *this;
}

template <class T>
typename ListPointer<T>::iterator ListPointer<T>::erase(ListPointer<T>::iterator& it)
{
    ElemPointer<T>* cur = root;
    ElemPointer<T>* prev = NULL;

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
void ListPointer<T>::clean()
{
    if (root)
    {
        for (ListPointer<T>::iterator it = begin(); !it.IsDone(); erase(it));
        root = cur = NULL;
    }
}

#endif // LISTPOINTER_H
