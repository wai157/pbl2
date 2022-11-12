#include <bits/stdc++.h>
#include "goodsList.h"
using namespace std;

goodsList::goodsList(){
    this->n = 0;
    this->Head = NULL;
}

goodsList::goodsList(const goodsList &gL){
    this->n = 0;
    this->Head = NULL;
    node<goods> *tmp = gL.Head;
    while(tmp!=NULL){
        this->insertTail(tmp->data);
        tmp = tmp->next;
    }
}

goodsList::~goodsList(){
    while(this->Head!=NULL) this->del(this->Head);
}

void goodsList::show(){
    if(this->Head==NULL) cout<<"Kho trong\n";
    else {
        cout<<"So luong vat tu: "<<this->n<<endl;
        node<goods> *tmp = this->Head;
        int k=0;
        while(tmp!=NULL){
            cout<<"Vat tu thu "<<++k<<":\n";
            cout<<tmp->data;
            tmp = tmp->next;
        }
    }
}

int goodsList::numOfSup(){
    return this->n;
}

bool goodsList::reduce(const node<goods> &S){
    node<goods> *tmp = this->Head;
    while(tmp!=NULL && tmp->data.code!=S.data.code){
        tmp = tmp->next;
    }
    if(tmp->data.quantity<S.data.quantity){
        cout<<"Khong the xuat vat tu (so luong can xuat lon hon so luong vat tu trong kho)!\n";
        cout<<"Note: ma vat tu: "<<tmp->data.code<<", so luong trong kho: "<<tmp->data.dt<<endl;
        return false;
    }
    tmp->data = tmp->data - S.data.quantity;
    if(tmp->data.quantity==0) del(tmp);
    return true;
}

int goodsList::Search(const node<goods> &S) const{
    node<goods> *tmp = this->Head;
    int k=0;
    while(tmp!=NULL){
        if(tmp->data.code==S.data.code) return k;
        k++;
        tmp = tmp->next;
    }
    return -1;
}

void goodsList::Sort(int order, int t){
    node<goods> *tmpArr = new node<goods>[this->n];
    int k=0;
    node<goods> *tmp = this->Head;
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

istream &operator >>(istream &in, goodsList &gL){
    int tmpCnt;
    in>>tmpCnt;
    for(int i=0;i<tmpCnt;i++){
        node<goods> S;
        in.ignore();
        getline(in, S.data.code); 
        getline(in, S.data.name);
        getline(in, S.data.type);
        getline(in, S.data.unit);
        inpDT(in, S.data.dt);
        in.ignore();
        getline(in, S.data.producer);
        in>>S.data.quantity;
        in>>S.data.unit_price;
        in>>S.data.total;
        gL.insertTail(S.data);
    }
    
	return in;
}

ostream &operator <<(ostream &out, const goodsList &gL){
    node<goods> *tmp = gL.Head;
    out<<gL.n<<endl;
    while(tmp!=NULL){
        out<<tmp->data.code<<endl;
        out<<tmp->data.name<<endl;
        out<<tmp->data.type<<endl;
        out<<tmp->data.unit<<endl;
        outDT(out, tmp->data.dt);
        out<<tmp->data.producer<<endl;
        out<<tmp->data.quantity<<endl;
        out<<tmp->data.unit_price<<endl;
        out<<tmp->data.total<<endl;
        tmp = tmp->next;
    }
    return out;
}