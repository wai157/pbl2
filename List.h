#include <bits/stdc++.h>
#include "node.cpp"

#ifndef linkedlist_h
#define linkedlist_h

template<typename T>
class List{
    protected:
        int n;
        node<T> *Head;
    public:
        List();
        virtual ~List();
        bool isEmpty() const;
        int numOfNode() const;
        virtual void show() const = 0;
        void insertHead(const T &data);
        void insertAfter(node<T> *prevNode,const T &data);
        void insertTail(const T &data);
        void del(node<T> *delNode);
        void Sort(const int &order=1, const int &att=1);
        template<typename U>
        friend int partition(node<U> *first, node<U> *last, bool compFunc(const U&, const U&, const int&), int t);
        template<typename U>
        friend void qSort(node<U> *first, node<U> *last, bool compFunc(const U&, const U&, const int&), int t);
};

#endif