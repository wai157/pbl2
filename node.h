#include <bits/stdc++.h>

#ifndef node_h
#define node_h

template<typename T> 
class node{
    public:
        T data;
        node<T> *prev;
        node<T> *next;
        node();
        node(const node<T> &n);
        node(const T &data);
        ~node();
};

#endif