#include <bits/stdc++.h>
#include <sstream>
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

void goodsList::show() const{
    if(this->Head==NULL) throw("\nKho trong\n");
    else{
        cout<<"So luong mat hang: "<<this->numOfNode()<<endl;
        cout<<"| STT |"<<" Ma hang hoa |"<<"      Ten hang hoa      |"<<" Loai hang hoa |"<<"    Nha san xuat    |"<<" Ngay nhap hang |"<<" Don vi tinh |"<<" So luong |"<<"    Don gia    |"<<"   Thanh tien   |"<<endl;
        int stt=0;
        node<goods> *tmp = this->Head;
        while(tmp!=NULL){
        cout<<"|"<<setw(4)<<right<<++stt<<" | ";
        cout<<tmp->data<<endl;
        tmp=tmp->next;
    }
    }
}

void goodsList::print() const{
    ofstream khoHang;
    khoHang.open("kho_hang.txt", ofstream::out);
    khoHang<<setw(83)<<"KHO HANG"<<endl;
    khoHang<<"So luong mat hang: "<<this->numOfNode()<<endl;
    khoHang<<setfill('_')<<setw(158)<<"_"<<setfill(' ')<<endl;
    khoHang<<"| STT |"<<" Ma hang hoa |"<<"      Ten hang hoa      |"<<" Loai hang hoa |"<<"    Nha san xuat    |"<<" Ngay nhap hang |"<<" Don vi tinh |"<<" So luong |"<<"    Don gia    |"<<"   Thanh tien   |"<<endl;
    int stt=0;
    node<goods> *tmp = this->Head;
    while(tmp!=NULL){
        khoHang<<"|"<<setw(4)<<right<<++stt<<" | ";
        khoHang<<tmp->data<<endl;
        tmp=tmp->next;
    }
    khoHang<<setfill('_')<<setw(158)<<"_"<<endl;
}

void goodsList::nhap(goods &S){
    cin>>S;
    if(!S.isValid()) throw("\nHang hoa nhap vao khong hop le (so luong hoac don gia be hon hoac bang 0)!\n");
    node<goods> *tmp = this->Head;
    while(tmp!=NULL){
        if(tmp->data.code==S.code) throw("\nHang hoa nhap vao khong hop le (ma hang hoa trung voi hang hoa co san trong kho)!\n");
        tmp = tmp->next;
    }
}
void goodsList::xuat(goods &S){
    cout<<"\tNhap ma hang hoa: "; getline(cin, S.code); 
    node<goods> *tmp = this->Head;
    while(tmp!=NULL && tmp->data.code!=S.code){
        tmp = tmp->next;
    }
    if(tmp==NULL) throw("\nKhong the xuat hang hoa (khong tim thay hang hoa tuong ung trong kho)!\n");
    else{
        S = tmp->data;
        cout<<"\tTen hang hoa: "<<S.name<<endl;
        cout<<"\tLoai hang hoa: "<<S.type<<endl;
        cout<<"\tNha san xuat: "<<S.producer<<endl;
        cout<<"\tDon vi tinh: "<<S.unit<<endl;
        cout<<"\tNgay nhap hang: "<<S.dt<<endl;
        cout<<"\tSo luong: "<<S.quantity<<endl;
        cout<<"\tDon gia: "<<S.unit_price<<endl;
        cout<<"\tNhap so luong can xuat: "; cin>>S.quantity; cin.ignore();
        cout<<"\tNhap don gia can xuat: "; cin>>S.unit_price; cin.ignore();
        S.total = S.quantity*S.unit_price;
    }
    if(!S.isValid()) throw("\nHang hoa nhap vao khong hop le (so luong hoac don gia can xuat be hon hoac bang 0)!\n");
}

void goodsList::reduce(const goods &S){
    node<goods> *tmp = this->Head;
    while(tmp!=NULL && tmp->data.code!=S.code){
        tmp = tmp->next;
    }
    if(tmp->data.quantity<S.quantity){
        throw("\nKhong the xuat hang hoa (so luong can xuat lon hon so luong hang hoa trong kho)!\n");
    }
    tmp->data = tmp->data - S.quantity;
    if(tmp->data.quantity==0) del(tmp);
}

void goodsList::Search(const int &att) const{
    node<goods> *tmp = this->Head;
    string str;
    //default: tim theo code
    if(att!=2){
        cout<<"\nNhap ma hang hoa can tim: ";
        getline(cin, str);
        while(tmp!=NULL && tmp->data.code!=str) tmp = tmp->next;
        cout<<"\nTim thay "<<((tmp!=NULL)?"1 ":"0 ")<<"mat hang!\n"<<endl;
        cout<<"| STT |"<<" Ma hang hoa |"<<"      Ten hang hoa      |"<<" Loai hang hoa |"<<"    Nha san xuat    |"<<" Ngay nhap hang |"<<" Don vi tinh |"<<" So luong |"<<"    Don gia    |"<<"   Thanh tien   |"<<endl;
        if(tmp!=NULL) cout<<"|   1 | "<<tmp->data;
        cout<<endl;
        return;
    }
    //tim theo filter
    bool arr[10]={0};
    cout<<"\nChon cac filter ma ban muon\n";
    cout<<"(1: ten hang hoa, 2: loai hang hoa, 3: nha san xuat,\n";
    cout<<"4: ngay nhap hang, 5: so luong, 6: don gia): "; getline(cin, str);
    stringstream ss(str);
    int a;
    while(ss>>a){
        if(a<1 || a>6) throw(1);
        arr[a]=true;
    }
    string name, type, producer;
    date start, end;
    int qtyl, qtyh, pricel, priceh;
    if(arr[1]==true){
        cout<<"\nNhap ten hang hoa can tim: ";
        getline(cin, name);
    }
    if(arr[2]==true){
        cout<<"\nNhap loai hang hoa can tim: ";
        getline(cin, type);
    }
    if(arr[3]==true){
        cout<<"\nNhap nha san xuat can tim: ";
        getline(cin, producer);
    }
    if(arr[4]==true){
        cout<<"\nNhap ngay bat dau:\n"; cin>>start;
        cin.ignore();
        if(!start.isValid()) throw(2);
        cout<<"Nhap ngay ket thuc:\n"; cin>>end;
        cin.ignore();
        if(!end.isValid()) throw(2);
        if(start>end) throw(3);
    }
    if(arr[5]==true){
        cout<<"\nNhap so luong min: "; cin>>qtyl; cin.ignore();
        if(qtyl<=0) throw(4);
        cout<<"Nhap so luong max: "; cin>>qtyh; cin.ignore();
        if(qtyh<=0) throw(4);
        if(qtyl>qtyh) throw(5);
    }
    if(arr[6]==true){
        cout<<"\nNhap don gia min: "; cin>>pricel; cin.ignore();
        if(pricel<=0) throw(6);
        cout<<"Nhap don gia max: "; cin>>priceh; cin.ignore();
        if(priceh<=0) throw(6);
        if(pricel>priceh) throw(7);
    }
    goodsList res;
    while(tmp!=NULL){
        if(((arr[1]==true)?tmp->data.name==name:1) &&
           ((arr[2]==true)?tmp->data.type==type:1) &&
           ((arr[3]==true)?tmp->data.producer==producer:1) &&
           ((arr[4]==true)?(tmp->data.dt>=start && tmp->data.dt<=end):1) &&
           ((arr[5]==true)?(tmp->data.quantity>=qtyl && tmp->data.quantity<=qtyh):1) &&
           ((arr[6]==true)?(tmp->data.unit_price>=pricel && tmp->data.unit_price<=priceh):1)){
            res.insertTail(tmp->data);
        }
        tmp = tmp->next;
    }
    cout<<"\nTim thay "<<res.numOfNode()<<" mat hang!\n"<<endl;
    cout<<"| STT |"<<" Ma hang hoa |"<<"      Ten hang hoa      |"<<" Loai hang hoa |"<<"    Nha san xuat    |"<<" Ngay nhap hang |"<<" Don vi tinh |"<<" So luong |"<<"    Don gia    |"<<"   Thanh tien   |"<<endl;
    int stt=0;
    node<goods> *finalRes = res.Head;
    while(finalRes!=NULL){
        cout<<"|"<<setw(4)<<right<<++stt<<" | ";
        cout<<finalRes->data<<endl;
        finalRes = finalRes->next;
    }
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