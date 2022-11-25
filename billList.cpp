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

void billList::create(bill &b) const{
    cout<<"Nhap ten nguoi tao: "; getline(cin, b.nguoiTao);
    cout<<"Nhap ngay "<<((b.nhapXuat)?"nhap ":"xuat ")<<":\n"; cin>>b.ngayNhapXuat; cin.ignore();
    if(!b.ngayNhapXuat.isValid()){
        throw(1);
    }
    cout<<"Nhap ma phieu: "; getline(cin, b.code);
    node<bill> *tmp = this->Head;
    while(tmp!=NULL){
        if(tmp->data.code==b.code) throw(2);
        tmp = tmp->next;
    }
    b.fileName = b.fileName + b.ngayNhapXuat.dtAsString() + "_";
    b.fileName = b.fileName + to_string(b.nhapXuat) + "_";
    b.fileName = b.fileName + b.code + ".txt";
}

void billList::show() const{
    if(this->Head==NULL) throw("Chua co phieu duoc tao!\n");
    node<bill> *tmp = this->Head;
    int stt=0;
    cout<<"| STT |"<<" Ma phieu |"<<"         Nguoi Tao         |"<<"  Ngay tao  |"<<" Ngay "<<((tmp->data.nhapXuat)?"nhap ":"xuat ")<<"hang |"<<" So mat hang |"<<" Tong gia tien |"<<endl;
    while(tmp!=NULL){
        cout<<"|"<<setw(4)<<right<<++stt<<" | ";
        cout<<tmp->data<<endl;
        tmp = tmp->next;
    }
}

void billList::print(const int &nx) const{
    node<bill> *tmp = this->Head;
    int stt=0;
    ofstream dsphieu;
    string str = "danh_sach_phieu_";
    str += ((nx)?"nhap":"xuat");
    str += ".txt";
    dsphieu.open(str, ofstream::out);
    dsphieu<<setw(50)<<"DANH SACH PHIEU "<<((nx)?"NHAP ":"XUAT ")<<endl;
    dsphieu<<setfill('_')<<setw(106)<<'_'<<setfill(' ')<<endl;
    dsphieu<<"| STT |"<<" Ma phieu |"<<"         Nguoi Tao         |"<<"  Ngay tao  |"<<" Ngay "<<((nx)?"nhap ":"xuat ")<<"hang |"<<" So mat hang |"<<" Tong gia tien |"<<endl;
    while(tmp!=NULL){
        dsphieu<<"|"<<setw(4)<<right<<++stt<<" | ";
        dsphieu<<tmp->data<<endl;
        tmp = tmp->next;
    }
    dsphieu<<setfill('_')<<setw(106)<<'_'<<setfill(' ')<<endl;
}

void billList::history(const date &start, const date &end) const{
    billList tmpBL(*this);
    tmpBL.Sort(1,3);
    node<bill> *tmp = tmpBL.Head;
    while(tmp!=NULL){
        if(tmp->data.ngayNhapXuat>=start && tmp->data.ngayNhapXuat<=end){
            cout<<"Ngay "<<tmp->data.ngayNhapXuat<<":\n";
            cout<<"| STT |"<<" Ma hang hoa |"<<"      Ten hang hoa      |"<<" Loai hang hoa |"<<"    Nha san xuat    |"<<" Don vi tinh |"<<" So luong |"<<"    Don gia    |"<<"   Thanh tien   |"<<endl;
            node<goods> *tmpSL = tmp->data.gL.Head;
            int stt=0;
            while(tmpSL!=NULL){
                cout<<"|"<<setw(4)<<right<<++stt<<" | ";
                cout<<setw(12)<<left<<tmpSL->data.code<<"| ";
                cout<<setw(23)<<left<<tmpSL->data.name<<"| ";
                cout<<setw(14)<<left<<tmpSL->data.type<<"| ";
                cout<<setw(19)<<left<<tmpSL->data.producer<<"| ";
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

void billList::Search(const int &nx, const int &att) const{
    node<bill> *tmp = this->Head;
    string str;
    //default: tim theo code
    if(att!=2){
        cout<<"Nhap ma phieu can tim: ";
        getline(cin, str);
        while(tmp!=NULL && tmp->data.code!=str) tmp = tmp->next;
        cout<<"\nTim thay "<<((tmp!=NULL)?"1 ":"0 ")<<"phieu!\n"<<endl;
        cout<<"| STT |"<<" Ma phieu |"<<"         Nguoi Tao         |"<<"  Ngay tao  |"<<" Ngay "<<((nx)?"nhap ":"xuat ")<<"hang |"<<" So mat hang |"<<" Tong gia tien |"<<endl;
        if(tmp!=NULL) cout<<"|   1 | "<<tmp->data;
        cout<<endl;
        return;
    }
    //tim theo filter
    bool arr[10]={0};
    cout<<"\nChon cac filter ma ban muon\n";
    cout<<"(1: nguoi tao, 2: ngay tao, 3: ngay "<<((nx)?"nhap":"xuat")<<" hang,\n";
    cout<<"4: so mat hang, 5: tong gia tien): "; getline(cin, str);
    stringstream ss(str);
    int a;
    while(ss>>a){
        if(a<1 || a>5) throw(1);
        arr[a]=true;
    }
    string creator;
    date createl, createh, nxl, nxh;
    int qtyl, qtyh, pricel, priceh;
    if(arr[1]==true){
        cout<<"\nNhap nguoi tao can tim: ";
        getline(cin, creator);
    }
    if(arr[2]==true){
        cout<<"\nNhap ngay tao bat dau:\n"; cin>>createl;
        cin.ignore();
        if(!createl.isValid()) throw(2);
        cout<<"Nhap ngay tao ket thuc:\n"; cin>>createh;
        cin.ignore();
        if(!createh.isValid()) throw(2);
        if(createl>createh) throw(3);
    }
    if(arr[3]==true){
        cout<<"\nNhap ngay "<<((nx)?"nhap":"xuat")<<" bat dau:\n"; cin>>nxl;
        cin.ignore();
        if(!nxl.isValid()) throw(2);
        cout<<"Nhap ngay "<<((nx)?"nhap":"xuat")<<" ket thuc:\n"; cin>>nxh;
        cin.ignore();
        if(!nxh.isValid()) throw(2);
        if(nxl>nxh) throw(3);
    }
    if(arr[4]==true){
        cout<<"\nNhap so mat hang min: "; cin>>qtyl; cin.ignore();
        if(qtyl<=0) throw(4);
        cout<<"Nhap so mat hang max: "; cin>>qtyh; cin.ignore();
        if(qtyh<=0) throw(4);
        if(qtyl>qtyh) throw(5);
    }
    if(arr[5]==true){
        cout<<"\nNhap tong gia tien min: "; cin>>pricel; cin.ignore();
        if(pricel<=0) throw(6);
        cout<<"Nhap tong gia tien max: "; cin>>priceh; cin.ignore();
        if(priceh<=0) throw(6);
        if(pricel>priceh) throw(7);
    }
    billList res;
    while(tmp!=NULL){
        if(((arr[1]==true)?tmp->data.nguoiTao==creator:1) &&
           ((arr[2]==true)?(tmp->data.ngayTao>=createl && tmp->data.ngayTao<=createh):1) &&
           ((arr[3]==true)?(tmp->data.ngayNhapXuat>=nxl && tmp->data.ngayNhapXuat<=nxh):1) &&
           ((arr[4]==true)?(tmp->data.gL.n>=qtyl && tmp->data.gL.n<=qtyh):1) &&
           ((arr[5]==true)?(tmp->data.total>=pricel && tmp->data.total<=priceh):1)){
            res.insertTail(tmp->data);
        }
        tmp = tmp->next;
    }
    cout<<"\nTim thay "<<res.numOfNode()<<" phieu!\n"<<endl;
    cout<<"| STT |"<<" Ma phieu |"<<"         Nguoi Tao         |"<<"  Ngay tao  |"<<" Ngay "<<((nx)?"nhap ":"xuat ")<<"hang |"<<" So mat hang |"<<" Tong gia tien |"<<endl;
    int stt=0;
    node<bill> *finalRes = res.Head;
    while(finalRes!=NULL){
        cout<<"|"<<setw(4)<<right<<++stt<<" | ";
        cout<<finalRes->data<<endl;
        finalRes = finalRes->next;
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
        out<<tmp->data.nguoiTao<<',';
        out<<tmp->data.ngayTao.dtAsString()<<',';
        out<<tmp->data.total<<',';
        out<<tmp->data.gL.numOfNode()<<','<<endl;
        out<<tmp->data.gL;
        tmp = tmp->next;
    }
    return out;
}