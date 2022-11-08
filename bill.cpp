#include <bits/stdc++.h>
#include <chrono>
#include <ctime>
#include "bill.h"
using namespace std;

bill::bill(bool nhapXuat, std::string code, int yyyy, int mm, int dd):dt(yyyy,mm,dd){
    this->nhapXuat = nhapXuat;
    this->code = code;
    this->fileName = "";
}
bill::~bill(){
    while(this->Head!=NULL) this->del(this->Head);
}
void bill::create(){
    cout<<"Nhap ngay "<<((this->nhapXuat)?"nhap ":"xuat ")<<":\n"; cin>>this->dt; cin.ignore();
    cout<<"Nhap ma phieu: "; getline(cin, this->code);
    this->fileName = this->fileName + this->dt.dtAsString() + "_";
    this->fileName = this->fileName + to_string(this->nhapXuat) + "_";
    this->fileName = this->fileName + this->code;
    
}
void bill::print() const{
    ofstream billout;
    billout.open(this->fileName);
    billout<<"\t\t\tPHIEU    "<<((this->nhapXuat)?"NHAP ":"XUAT ")<<"KHO"<<endl;
    billout<<"\t\t\tNgay "<<((this->nhapXuat)?"nhap":"xuat")<<": "<<this->dt;
    billout<<"Nguoi tao: unknown user"<<endl;
    time_t end_time = chrono::system_clock::to_time_t(chrono::system_clock::now());
    billout<< "Ngay tao: " << ctime(&end_time);
    billout<<setfill('_')<<setw(98)<<"_"<<endl;
    billout<<setfill(' ')<<"| STT |"<<" Ma vat tu |"<<"       Ten vat tu       |"<<" Don vi tinh |"<<" So luong |"<<"   Don gia   |"<<"  Thanh tien  |"<<endl;
}