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
        cout<<"So luong hang hoa: "<<this->n<<endl;
        node<goods> *tmp = this->Head;
        int k=0;
        while(tmp!=NULL){
            cout<<"Vat tu thu "<<++k<<":\n";
            cout<<tmp->data;
            tmp = tmp->next;
        }
    }
}

int goodsList::numOfSup() const{
    return this->n;
}

bool goodsList::reduce(const node<goods> &S){
    node<goods> *tmp = this->Head;
    while(tmp!=NULL && tmp->data.code!=S.data.code){
        tmp = tmp->next;
    }
    if(tmp->data.quantity<S.data.quantity){
        cout<<"Khong the xuat hang hoa (so luong can xuat lon hon so luong hang hoa trong kho)!\n";
        cout<<"Note: ma hang hoa: "<<tmp->data.code<<", so luong trong kho: "<<tmp->data.dt<<endl;
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

goodsList &goodsList::operator =(goodsList gL){
    this->n = gL.n;
    swap(this->Head, gL.Head);
    return *this;
}

istream &operator >>(istream &in, goodsList &gL){
    string str;
    while(getline(in, str)){
        goods S(str);
        gL.insertTail(S);
    }
	return in;
}

ostream &operator <<(ostream &out, const goodsList &gL){
    node<goods> *tmp = gL.Head;
    while(tmp!=NULL){
        out<<tmp->data.code<<',';
        out<<tmp->data.name<<',';
        out<<tmp->data.type<<',';
        out<<tmp->data.unit<<',';
        out<<tmp->data.dt.dtAsString()<<',';
        out<<tmp->data.producer<<',';
        out<<tmp->data.quantity<<',';
        out<<tmp->data.unit_price<<',';
        out<<tmp->data.total<<',';
        out<<endl;
        tmp = tmp->next;
    }
    return out;
}