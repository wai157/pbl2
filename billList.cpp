#include <bits/stdc++.h>
#include "billList.h"
using namespace std;

billList::billList(){
    this->n = 0;
    this->Head = NULL;
}

billList::billList(const billList &bL){
    this->n = 0;
    this->Head = NULL;
    node<bill> *tmp = bL.Head;
    while(tmp!=NULL){
        this->insertTail(tmp->data);
        tmp = tmp->next;
    }
}

billList::~billList(){
    while(this->Head!=NULL){
        while(this->Head->data.gL.Head!=NULL) this->Head->data.gL.del(this->Head->data.gL.Head);
        this->del(this->Head);
    }
}

void billList::show() const{
    node<bill> *tmp = this->Head;
    while(tmp!=NULL){
        cout<<tmp->data.code<<endl;
        node<goods> *gLtmp = tmp->data.gL.Head;
        while(gLtmp!=NULL){
            cout<<setw(10)<<left<<gLtmp->data.code<<"| ";
            cout<<setw(23)<<left<<gLtmp->data.name<<"| ";
            cout<<setw(25)<<left<<gLtmp->data.producer<<"| ";
            cout<<setw(12)<<left<<gLtmp->data.unit<<"|";
            cout<<setw(9)<<right<<gLtmp->data.quantity<<" |";
            cout<<setw(14)<<right<<gLtmp->data.unit_price<<" |";
            cout<<setw(15)<<right<<gLtmp->data.total<<" |"<<endl;
            gLtmp=gLtmp->next;
        }
        tmp = tmp->next;
    }
}

void billList::history(const date &start, const date &end) const{
    node<bill> *tmpBL = this->Head;
    while(tmpBL!=NULL){
        if(tmpBL->data.ngayNhapXuat>=start && tmpBL->data.ngayNhapXuat<=end){
            cout<<"Ngay "<<tmpBL->data.ngayNhapXuat<<":\n";
            node<goods> *tmpSL = tmpBL->data.gL.Head;
            int stt=0;
            while(tmpSL!=NULL){
                cout<<"| STT |"<<" Ma vat tu |"<<"       Ten vat tu       |"<<" Don vi tinh |"<<" So luong |"<<"    Don gia    |"<<"   Thanh tien   |"<<endl;
                cout<<"|"<<setw(4)<<right<<++stt<<" | ";
                cout<<setw(10)<<left<<tmpSL->data.code<<"| ";
                cout<<setw(23)<<left<<tmpSL->data.name<<"| ";
                cout<<setw(12)<<left<<tmpSL->data.unit<<"|";
                cout<<setw(9)<<right<<tmpSL->data.quantity<<" |";
                cout<<setw(14)<<right<<tmpSL->data.unit_price<<" |";
                cout<<setw(15)<<right<<tmpSL->data.total<<" |"<<endl;
                tmpSL=tmpSL->next;
            }
        }
    }
}