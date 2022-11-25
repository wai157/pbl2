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
        bool isEmpty() const;
        int numOfNode() const;
        void insertHead(const T &data);
        void insertAfter(node<T> *prevNode,const T &data);
        void insertTail(const T &data);
        void del(node<T> *delNode);
        void Sort(int order=1, int att=1);
        template<typename U>
        friend int partition(node<U> *L, int l, int h, bool compFunc(const U&, const U&, const int&), int t);
        template<typename U>
        friend void qSort(node<U> *L, int l, int h, bool compFunc(const U&, const U&, const int&), int t);
};

#endif