#include <bits/stdc++.h>
#include "List.h"
using namespace std;

template<typename T>
List<T>::List(){
    this->n=0;
    this->Head=NULL;
}

template<typename T>
List<T>::~List(){
    while(this->Head!=NULL) this->del(this->Head);
}

template<typename T>
bool List<T>::isEmpty() const{
    return (this->Head==NULL);
}

template<typename T>
int List<T>::numOfNode() const{
    return this->n;
}

template<typename T>
void List<T>::insertHead(const T &data){
    this->n++;
    node<T> *newNode = new node<T>(data);
    newNode->next = this->Head;
    if (this->Head != NULL) {
        this->Head->prev = newNode;
    }
    this->Head = newNode;
}

template<typename T>
void List<T>::insertAfter(node<T> *prevNode,const T &data){
    if(prevNode == NULL){
        cout<<"Error code 1: can't insert after null";
        return;
    }
    this->n++;
    node<T> *newNode = new node<T>(data);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
    newNode->prev = prevNode;
    if(newNode->next!=NULL)
        newNode->next->prev = newNode;
}

template<typename T>
void List<T>::insertTail(const T &data){
    this->n++;
    node<T> *newNode = new node<T>(data);
    node<T> *tail = this->Head;
    if(tail==NULL){
        newNode->prev=NULL;
        this->Head=newNode;
        return;
    }
    while(tail->next!=NULL) tail = tail->next;
    tail->next = newNode;
    newNode->prev = tail;
}

template<typename T>
void List<T>::del(node<T> *delNode){
    if(delNode==NULL || this->Head==NULL){
        cout<<"Error code 2: can't delete null";
        return;
    }
    if(this->Head==delNode) this->Head = delNode->next;
    if(delNode->next!=NULL) delNode->next->prev = delNode->prev;
    if(delNode->prev!=NULL) delNode->prev->next = delNode->next;
    delete delNode;
    this->n--;
}

template<typename T>
void List<T>::Sort(const int &order, const int &att){
    node<T> *last = this->Head;
    while(last!=NULL && last->next!=NULL){
        last = last->next;
    }
    if(order%2==1) qSort(this->Head, last, ascend, att);
    else qSort(this->Head, last, descend, att);
}

template<typename T>
node<T>* partition(node<T> *first, node<T> *last, bool compFunc(const T&,const T&, const int&), int k){
    node<T> *pivot = first;
    node<T> *front = first;
    while(front!=NULL && front!=last){
        if(compFunc(front->data,last->data,k)){
            pivot = first;
            swap(first->data, front->data);
            first = first->next;
        }
        front = front->next;
    }
    swap(first->data, last->data);
    return pivot;
}

template<typename T>
void qSort(node<T> *first, node<T> *last, bool compFunc(const T&, const T&, const int&), int k){
    if(first==last){
        return;
    }
    node<T> *pivot = partition(first, last, compFunc, k);
    if(pivot!=NULL && pivot->next!=NULL){
		qSort(pivot->next,last,compFunc,k);
	}
    if(pivot!=NULL && first!=NULL){
        qSort(first,pivot,compFunc,k);
    }
}