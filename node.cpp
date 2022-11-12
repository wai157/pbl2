#include <bits/stdc++.h>
#include "node.h"
using namespace std;

template<typename T>
node<T>::node(){
    this->prev = NULL;
    this->next = NULL;
}

template<typename T>
node<T>::node(const node<T> &n){
    this->data = n.data;
    this->prev = NULL;
    this->next = NULL;
}

template<typename T>
node<T>::node(const T &data){
    this->data = data;
    this->prev = NULL;
    this->next = NULL;
}

template<typename T>
node<T>::~node(){

}