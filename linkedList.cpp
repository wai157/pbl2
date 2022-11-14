#include <bits/stdc++.h>
#include "linkedList.h"
using namespace std;

template<typename T>
linkedList<T>::linkedList(){
    this->n=0;
    this->Head=NULL;
}

template<typename T>
linkedList<T>::~linkedList(){
    while(this->Head!=NULL) this->del(this->Head);
}

template<typename T>
void linkedList<T>::insertHead(const T &data){
    this->n++;
    node<T> *newNode = new node<T>(data);
    newNode->next = this->Head;
    if (this->Head != NULL) {
        this->Head->prev = newNode;
    }
    this->Head = newNode;
}

template<typename T>
void linkedList<T>::insertAfter(node<T> *prevNode,const T &data){
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
void linkedList<T>::insertTail(const T &data){
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
void linkedList<T>::del(node<T> *delNode){
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
void linkedList<T>::Sort(int order, int att){
    node<T> *tmpArr = new node<T>[this->n];
    int k=0;
    node<T> *tmp = this->Head;
    while(tmp!=NULL){
        tmpArr[k++] = *tmp;
        tmp = tmp->next;
    }
    if(order%2==1) qSort(tmpArr, 0, this->n-1, ascend, att);
    else qSort(tmpArr, 0, this->n-1, descend, att);
    tmp = this->Head;
    k=0;
    while(tmp!=NULL){
        *tmp = tmpArr[k++];
        tmp = tmp->next;
    }
}

template<typename T>
int partition(node<T> *L, int l, int h, bool compFunc(const T&,const T&, const int&), int k){
    node<T> pivot = L[h];
	int i=l-1;
	for(int j=l;j<h;j++){
		if(compFunc(L[j].data,pivot.data,k)){
			i++;
			swap(L[i].data,L[j].data);
		}
	}
	swap(L[i+1].data,L[h].data);
	return (i+1);
}

template<typename T>
void qSort(node<T> *L, int l, int h, bool compFunc(const T&, const T&, const int&), int k){
    if(l<h){
		int pi=partition(L,l,h,compFunc,k);
		qSort(L,l,pi-1,compFunc,k);
		qSort(L,pi+1,h,compFunc,k);
	}
}