#include <bits/stdc++.h>
#include <ctime>
#include "bill.h"
using namespace std;

date curDate(){
    time_t rawtime;
    struct tm *timeinfo;
    char buffer[80];
    time (&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer,sizeof(buffer),"%Y%m%d",timeinfo);
    string str(buffer);
    date curDate(str);
    return curDate;
}

bill::bill(bool nhapXuat, std::string code, int yyyy, int mm, int dd):ngayTao(), ngayNhapXuat(yyyy,mm,dd), gL(){
    this->nhapXuat = nhapXuat;
    this->code = code;
    this->fileName = "";
    this->total = 0;
}

bill::bill(const bill &b):gL(b.gL){
    this->nhapXuat = b.nhapXuat;
    this->code = b.code;
    this->nguoiTao = b.nguoiTao;
    this->ngayTao = b.ngayTao;
    this->ngayNhapXuat = b.ngayNhapXuat;
    this->fileName = b.fileName;
    this->total = b.total;
}

bill::bill(const string &str){
    int ps[5]={0};
    int pe[5]={0};
    int i=0;
    int k=0;
    while(i<4){
        ps[i]=k;
        k = str.find(',', k);
        pe[i]=k;
        k++;
        i++;
    }
    this->fileName = str.substr(ps[0],pe[0]-ps[0]);
    this->nguoiTao = str.substr(ps[1],pe[1]-ps[1]);
    this->ngayTao = str.substr(ps[2],pe[2]-ps[2]);
    this->total = stoi(str.substr(ps[3],pe[3]-ps[3]));
    this->ngayNhapXuat = this->fileName.substr(0,8);
    this->nhapXuat = stoi(this->fileName.substr(9,1));
    this->code = this->fileName.substr(11,this->fileName.length()-11-4);
}

bill::~bill(){
    while(this->gL.Head!=NULL) this->gL.del(this->gL.Head);
}

date bill::ngayNhapXuat_() const{
    return this->ngayNhapXuat;
}

void bill::add(const goods &S){
    node<goods> *tmp = this->gL.Head;
    while(tmp!=NULL){
        if(tmp->data.code==S.code) throw("\nHang hoa nhap vao khong hop le (hang hoa da duoc nhap trong phieu)!\n");
        tmp = tmp->next;
    }
    this->gL.insertTail(S);
}


void bill::print(){
    ofstream billout;
    billout.open(this->fileName);
    billout<<"\t\t\tPHIEU "<<((this->nhapXuat)?"NHAP ":"XUAT ")<<"KHO"<<endl;
    billout<<"\t\t\tNgay "<<((this->nhapXuat)?"nhap":"xuat")<<": "<<this->ngayNhapXuat<<endl;
    billout<<"Nguoi tao: "<<this->nguoiTao<<endl;
    ngayTao = curDate();
    billout<< "Ngay tao: " << this->ngayTao<<endl;
    billout<<setfill('_')<<setw(141)<<"_"<<endl;
    billout<<setfill(' ')<<"| STT |"<<" Ma hang hoa |"<<"      Ten hang hoa      |"<<" Loai hang hoa |"<<"    Nha san xuat    |"<<" Don vi tinh |"<<" So luong |"<<"    Don gia    |"<<"   Thanh tien   |"<<endl;
    int stt=0;
    node<goods> *tmp = this->gL.Head;
    while(tmp!=NULL){
        this->total += tmp->data.total;
        billout<<"|"<<setw(4)<<right<<++stt<<" | ";
        billout<<setw(12)<<left<<tmp->data.code<<"| ";
        billout<<setw(23)<<left<<tmp->data.name<<"| ";
        billout<<setw(14)<<left<<tmp->data.type<<"| ";
        billout<<setw(19)<<left<<tmp->data.producer<<"| ";
        billout<<setw(12)<<left<<tmp->data.unit<<"|";
        billout<<setw(9)<<right<<tmp->data.quantity<<" |";
        billout<<setw(14)<<right<<tmp->data.unit_price<<" |";
        billout<<setw(15)<<right<<tmp->data.total<<" |"<<endl;
        tmp=tmp->next;
    }
    billout<<setfill('_')<<setw(141)<<"_"<<endl;
    billout<<setfill(' ')<<"|"<<setw(63)<<"Cong"<<setw(60)<<"|"<<setw(15)<<right<<this->total<<" |"<<endl;
    billout<<setfill('_')<<setw(141)<<"_"<<endl;
    billout<<setfill(' ');
    billout.close();
}

bill &bill::operator =(bill b){
    this->nhapXuat = b.nhapXuat;
    this->code = b.code;
    this->nguoiTao = b.nguoiTao;
    this->ngayTao = b.ngayTao;
    this->ngayNhapXuat = b.ngayNhapXuat;
    this->fileName = b.fileName;
    this->gL = b.gL;
    this->total = b.total;
    return *this;
}

ostream &operator <<(ostream &out, const bill &b){
    out<<setw(9)<<left<<b.code<<"| ";
    out<<setw(26)<<left<<b.nguoiTao<<"| ";
    out<<b.ngayTao<<" |     ";
    out<<b.ngayNhapXuat<<" |";
    out<<setw(12)<<right<<b.gL.numOfNode()<<" |";
    out<<setw(14)<<right<<b.total<<" |";

    return out;
}

//cua goodsList;
void goodsList::addBill(const bill &b){
    node<goods> *tmp = b.gL.Head;
    while(tmp!=NULL){
        this->insertTail(tmp->data);
        tmp = tmp->next;
    }
}
void goodsList::subBill(const bill &b){
    node<goods> *tmp = b.gL.Head;
    while(tmp!=NULL){
        this->reduce(tmp->data);
        tmp = tmp->next;
    }
}

bool ascend(const bill &a, const bill &b, const int &k){
    switch(k){
        case 2:
            return a.nguoiTao<b.nguoiTao;
        case 3:
            return a.ngayTao<b.ngayTao;
        case 4:
            return a.ngayNhapXuat<b.ngayNhapXuat;
        case 5:
            return a.gL.numOfNode()<b.gL.numOfNode();
        case 6:
            return a.total<b.total;
        default:
            return a.code<b.code;
    }
}
bool descend(const bill &a, const bill &b, const int &k){
    switch(k){
        case 2:
            return a.nguoiTao>b.nguoiTao;
        case 3:
            return a.ngayTao>b.ngayTao;
        case 4:
            return a.ngayNhapXuat>b.ngayNhapXuat;
        case 5:
            return a.gL.numOfNode()>b.gL.numOfNode();
        case 6:
            return a.total>b.total;
        default:
            return a.code>b.code;
    }
}