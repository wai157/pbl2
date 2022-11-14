#include <bits/stdc++.h>
#include <ctime>
#include <sys/stat.h>
#include "bill.h"
using namespace std;

inline bool exists_test(const std::string& name){
    struct stat buffer;   
    return (stat (name.c_str(), &buffer) == 0); 
}

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
    this->fileName = b.fileName;
    this->ngayTao = b.ngayTao;
    this->ngayNhapXuat = b.ngayNhapXuat;
    this->total = b.total;
}

bill::bill(const string &str){
    int ps[5]={0};
    int pe[5]={0};
    int i=0;
    int k=0;
    while(i<3){
        ps[i]=k;
        k = str.find(',', k);
        pe[i]=k;
        k++;
        i++;
    }
    this->fileName = str.substr(ps[0],pe[0]-ps[0]);
    this->ngayTao = str.substr(ps[1],pe[1]-ps[1]);
    this->total = stoi(str.substr(ps[2],pe[2]-ps[2]));
    this->ngayNhapXuat = this->fileName.substr(0,8);
    this->nhapXuat = stoi(this->fileName.substr(9,1));
    this->code = this->fileName.substr(11);
}

bill::~bill(){
    while(this->gL.Head!=NULL) this->gL.del(this->gL.Head);
}

date bill::ngayNhapXuat_() const{
    return this->ngayNhapXuat;
}

void bill::add(const goods &S){
    this->gL.insertTail(S);
}

bool bill::create(){
    cout<<"Nhap ngay "<<((this->nhapXuat)?"nhap ":"xuat ")<<":\n"; cin>>this->ngayNhapXuat; cin.ignore();
    if(!this->ngayNhapXuat.isValid()){
        cout<<"Khong the tao phieu (ngay thang nam khong hop le)!\n";
        return false;
    }
    cout<<"Nhap ma phieu: "; getline(cin, this->code);
    this->fileName = this->fileName + this->ngayNhapXuat.dtAsString() + "_";
    this->fileName = this->fileName + to_string(this->nhapXuat) + "_";
    this->fileName = this->fileName + this->code + ".txt";
    if(exists_test(this->fileName)){
        cout<<"Khong the tao phieu (phieu da duoc tao)!\n";
        return false;
    }
    return true;
}
void bill::print(){
    ofstream billout;
    billout.open(this->fileName);
    billout<<"\t\t\tPHIEU "<<((this->nhapXuat)?"NHAP ":"XUAT ")<<"KHO"<<endl;
    billout<<"\t\t\tNgay "<<((this->nhapXuat)?"nhap":"xuat")<<": "<<this->ngayNhapXuat;
    billout<<"Nguoi tao: user A"<<endl;
    ngayTao = curDate();
    billout<< "Ngay tao: " << this->ngayTao;
    billout<<setfill('_')<<setw(129)<<"_"<<endl;
    billout<<setfill(' ')<<"| STT |"<<" Ma vat tu |"<<"       Ten vat tu       |"<<"       Nha san xuat       |"<<" Don vi tinh |"<<" So luong |"<<"    Don gia    |"<<"   Thanh tien   |"<<endl;
    int stt=0;
    node<goods> *tmp = this->gL.Head;
    while(tmp!=NULL){
        this->total += tmp->data.total;
        billout<<"|"<<setw(4)<<right<<++stt<<" | ";
        billout<<setw(10)<<left<<tmp->data.code<<"| ";
        billout<<setw(23)<<left<<tmp->data.name<<"| ";
        billout<<setw(25)<<left<<tmp->data.producer<<"| ";
        billout<<setw(12)<<left<<tmp->data.unit<<"|";
        billout<<setw(9)<<right<<tmp->data.quantity<<" |";
        billout<<setw(14)<<right<<tmp->data.unit_price<<" |";
        billout<<setw(15)<<right<<tmp->data.total<<" |"<<endl;
        tmp=tmp->next;
    }
    billout<<setfill('_')<<setw(129)<<"_"<<endl;
    billout<<setfill(' ')<<"|"<<setw(57)<<"Cong"<<setw(54)<<"|"<<setw(15)<<right<<this->total<<" |"<<endl;
    billout<<setfill('_')<<setw(129)<<"_"<<endl;
    billout<<setfill(' ');
    billout.close();
}

bill &bill::operator =(bill b){
    this->nhapXuat = b.nhapXuat;
    this->code = b.code;
    this->fileName = b.fileName;
    this->ngayTao = b.ngayTao;
    this->ngayNhapXuat = b.ngayNhapXuat;
    this->gL = b.gL;
    this->total = b.total;
    return *this;
}

bool ascend(const bill &a, const bill &b, const int &k){
    switch(k){
        case 2:
            return a.ngayTao<b.ngayTao;
        case 3:
            return a.ngayNhapXuat<b.ngayNhapXuat;
        case 4:
            return a.total<b.total;
        default:
            return a.code<b.code;
    }
}
bool descend(const bill &a, const bill &b, const int &k){
    switch(k){
        case 2:
            return a.ngayTao>b.ngayTao;
        case 3:
            return a.ngayNhapXuat>b.ngayNhapXuat;
        case 4:
            return a.total>b.total;
        default:
            return a.code>b.code;
    }
}