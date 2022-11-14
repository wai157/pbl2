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
    billList tmpBL(*this);
    tmpBL.Sort(1,3);
    node<bill> *tmp = tmpBL.Head;
    while(tmp!=NULL){
        if(tmp->data.ngayNhapXuat>=start && tmp->data.ngayNhapXuat<=end){
            cout<<"Ngay "<<tmp->data.ngayNhapXuat<<":\n";
            cout<<"| STT |"<<" Ma hang hoa |"<<"       Ten hang hoa       |"<<" Don vi tinh |"<<" So luong |"<<"    Don gia    |"<<"   Thanh tien   |"<<endl;
            node<goods> *tmpSL = tmp->data.gL.Head;
            int stt=0;
            while(tmpSL!=NULL){
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
        tmp = tmp->next;
    }
}
istream &operator >>(std::istream &in, billList &bL){
    string str1;
    while(getline(in, str1)){
        bill b(str1);
        int k = str1.find_last_of(',', str1.length()-2)+1;
        k = stoi(str1.substr(k, str1.length()-k));
        for(int i=0;i<k;i++){
            string str2;
            getline(in, str2);
            goods S(str2);
            b.gL.insertTail(S);
        }
        bL.insertTail(b);
    }
    return in;
}
ostream &operator <<(std::ostream &out, const billList &bL){
    node<bill> *tmp = bL.Head;
    while(tmp!=NULL){
        out<<tmp->data.fileName<<',';
        out<<tmp->data.ngayTao<<',';
        out<<tmp->data.total<<',';
        out<<tmp->data.gL.numOfSup()<<','<<endl;
        out<<tmp->data.gL;
        tmp = tmp->next;
    }
    return out;
}