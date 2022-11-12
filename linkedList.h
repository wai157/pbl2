#include <bits/stdc++.h>
#include "node.cpp"

#ifndef linkedlist_h
#define linkedlist_h

template<typename T>
class linkedList{
    protected:
        int n;
        node<T> *Head;
    public:
        linkedList();
        virtual ~linkedList();
        void insertHead(const T &data);
        void insertAfter(node<T> *prevNode,const T &data);
        void insertTail(const T &data);
        void del(node<T> *delNode);
        template<typename U>
        friend int partition(node<U> *L, int l, int h, bool compFunc(U, U, int), int t);
        template<typename U>
        friend void qSort(node<U> *L, int l, int h, bool compFunc(U, U, int), int t);
};

#endif