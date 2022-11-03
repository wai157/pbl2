#include <bits/stdc++.h>
#include "supList.h"
using namespace std;

supList::supList(int n){
    this->n = n;
    this->Head = NULL;
}

supList::~supList(){
    while(this->Head!=NULL) this->del(this->Head);
}

void supList::show(){
    cout<<"So luong vat tu: "<<this->n<<endl;
    Supply *tmp = this->Head;
    int k=0;
    while(tmp!=NULL){
        cout<<"Vat tu thu "<<++k<<":\n";
        cout<<*tmp;
        tmp = tmp->next;
    }
}

int supList::numOfSup(){
    return this->n;
}

void supList::insertHead(Supply data){
    this->n++;
    Supply *newNode = new Supply(data);
    newNode->next = this->Head;
    if (this->Head != NULL) {
        this->Head->prev = newNode;
    }
    this->Head = newNode;
}

void supList::insertAfter(Supply *prevNode, Supply data){
    if(prevNode == NULL){
        cout<<"Error code 1";
        return;
    }
    this->n++;
    Supply *newNode = new Supply(data);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
    newNode->prev = prevNode;
    if(newNode->next!=NULL)
        newNode->next->prev = newNode;
}

void supList::insertTail(Supply data){
    this->n++;
    Supply *newNode = new Supply(data);
    Supply *tail = this->Head;
    if(tail==NULL){
        newNode->prev=NULL;
        this->Head=newNode;
        return;
    }
    while(tail->next!=NULL) tail = tail->next;
    tail->next = newNode;
    newNode->prev = tail;
}


void supList::del(Supply *delNode){
    if(delNode==NULL || this->Head==NULL){
        cout<<"Error code 2";
        return;
    }
    if(this->Head==delNode) this->Head = delNode->next;
    if(delNode->next!=NULL) delNode->next->prev = delNode->prev;
    if(delNode->prev!=NULL) delNode->prev->next = delNode->next;
    delete delNode;
}

int supList::Search(const Supply &S) const{
    Supply *tmp = this->Head;
    int k=0;
    while(tmp!=NULL){
        if(tmp->code==S.code) return k;
        k++;
        tmp = tmp->next;
    }
    return -1;
}

int partition(Supply *sL, int l, int h, bool compFunc(Supply, Supply, int), int k){
    Supply pivot = sL[h];
	int i=l-1;
	for(int j=l;j<h;j++){
		if(compFunc(sL[j],pivot,k)){
			i++;
			swap(sL[i],sL[j]);
		}
	}
	swap(sL[i+1],sL[h]);
	return (i+1);
}

void qSort(Supply *sL, int l, int h, bool compFunc(Supply, Supply, int), int k){
    if(l<h){
		int pi=partition(sL,l,h,compFunc,k);
		qSort(sL,l,pi-1,compFunc,k);
		qSort(sL,pi+1,h,compFunc,k);
	}
}

void supList::Sort(int order, int t){
    Supply *tmpArr = new Supply[this->n];
    int k=0;
    Supply *tmp = this->Head;
    while(tmp!=NULL){
        tmpArr[k++] = *tmp;
        tmp = tmp->next;
    }
    if(order%2==1) qSort(tmpArr, 0, this->n-1, ascend, t);
    else qSort(tmpArr, 0, this->n-1, descend, t);
    tmp = this->Head;
    k=0;
    while(tmp!=NULL){
        *tmp = tmpArr[k++];
        tmp = tmp->next;
    }
}

istream &operator >>(istream &in, supList &sL){
    int tmpCnt;
    in>>tmpCnt;
    for(int i=0;i<tmpCnt;i++){
        Supply S;
        in.ignore();
        getline(in, S.code); 
        getline(in, S.name);
        getline(in, S.type);
        getline(in, S.unit);
        inpDT(in, S.DateTime);
        in.ignore();
        getline(in, S.producer);
        in>>S.quantity;
        in>>S.unit_price;
        in>>S.total;
        sL.insertTail(S);
    }
    
	return in;
}

ostream &operator <<(ostream &out, const supList &sL){
    Supply *tmp = sL.Head;
    out<<sL.n<<endl;
    while(tmp!=NULL){
        out<<tmp->code<<endl;
        out<<tmp->name<<endl;
        out<<tmp->type<<endl;
        out<<tmp->unit<<endl;
        outDT(out, tmp->DateTime);
        out<<tmp->producer<<endl;
        out<<tmp->quantity<<endl;
        out<<tmp->unit_price<<endl;
        out<<tmp->total<<endl;
        tmp = tmp->next;
    }
    return out;
}
