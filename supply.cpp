#include <bits/stdc++.h>
#include "supply.h"
using namespace std;

Supply::Supply(string c, string n, string t, string u, int YYYY, int MM, int DD, int H, int M, string p, int q, int u_p):DateTime(YYYY,MM,DD,H,M){
	this->code = c;
	this->name = n;
	this->type = t;
	this->unit = u;
	this->producer = p;
	this->quantity = q;
	this->unit_price = u_p;
	this->prev = NULL;
	this->next = NULL;
}

Supply Supply::operator +(int q){
	Supply res = *this;
	res.quantity += q;
	res.total = res.quantity * res.unit_price;
	return res;
}

Supply Supply::operator -(int q){
	Supply res = *this;
	res.quantity -= q;
	res.total = res.quantity * res.unit_price;
	return res;
}

Supply &Supply::operator =(const Supply &S){
	this->code = S.code;
	this->name = S.name;
	this->type = S.type;
	this->unit = S.unit;
	this->DateTime = S.DateTime;
	this->producer = S.producer;
	this->quantity = S.quantity;
	this->unit_price = S.unit_price;
	this->total = S.total;
	return (*this);
}

bool Supply::operator ==(Supply S){
	if(this->code==S.code && this->name==S.name && this->type==S.type && this->unit==S.unit && this->DateTime==S.DateTime && this->producer==S.producer && this->quantity==S.quantity && this->unit_price==S.unit_price)
		return 1;
	return 0;
}
bool Supply::operator !=(Supply S){
	if(this->code==S.code && this->name==S.name && this->type==S.type && this->unit==S.unit && this->DateTime==S.DateTime && this->producer==S.producer && this->quantity==S.quantity && this->unit_price==S.unit_price)
		return 0;
	return 1;
}

bool Supply::isValid(){
	return (this->DateTime.isValid() && this->quantity>0 && this->unit_price>0);
}

istream &operator >>(istream &in, Supply &S){
	int c;
	cout<<"\tNhap ma vat tu: "; getline(in, S.code); 
	cout<<"\tNhap ten vat tu: "; getline(in, S.name);
	cout<<"\tNhap loai vat tu: "; getline(in, S.type);
	cout<<"\tNhap don vi tinh: "; getline(in, S.unit);
	cout<<"\tNhap thoi gian nhap hang: "<<endl; in>>S.DateTime;
	while((c=getchar())!='\n' && c!=EOF);;
	cout<<"\tNhap nha san xuat: "; getline(in, S.producer);
	cout<<"\tNhap so luong: "; in>>S.quantity;
	while((c=getchar())!='\n' && c!=EOF);;
	cout<<"\tNhap don gia: "; in>>S.unit_price;
	while((c=getchar())!='\n' && c!=EOF);;
	S.total = S.quantity * S.unit_price;
	return in;
}

void dbInput(ifstream &fin, Supply &S){
	int c;
	getline(fin, S.code); cout<<S.code<<endl	;
	getline(fin, S.name); cout<<2;
	getline(fin, S.type); cout<<3;
	getline(fin, S.unit); cout<<4;
	dbInput(fin, S.DateTime); cout<<9;
	getline(fin, S.producer); cout<<10;
	fin>>S.quantity; cout<<11;
	fin>>S.unit_price; cout<<12;
	S.total = S.quantity * S.unit_price;
}

ostream &operator <<(ostream &out, const Supply &S){
	out<<"\tMa vat tu: "<<S.code<<endl;
	out<<"\tTen vat tu: "<<S.name<<endl;
	out<<"\tLoai vat tu: "<<S.type<<endl;
	out<<"\tDon vi tinh: "<<S.unit<<endl;
	out<<"\tNgay nhap hang: "<<S.DateTime;
	out<<"\tNha san xuat: "<<S.producer<<endl;
	out<<"\tSo luong: "<<S.quantity<<endl;
	out<<"\tDon gia: "<<S.unit_price<<endl;
	out<<"\tThanh tien: "<<S.total<<endl;
	return out;
}

void dbOutput(ofstream &fout, const Supply &S){
	fout<<S.code<<endl;
	fout<<S.name<<endl;
	fout<<S.type<<endl;
	fout<<S.unit<<endl;
	dbOutput(fout, S.DateTime);
	fout<<S.producer<< endl;
	fout<<S.quantity<< endl;
	fout<<S.unit_price<<endl;
}

void insert(Supply* &head, Supply S){
	Supply* newSupply = new Supply(S);
	newSupply->next = head;
	if(head!=NULL){
		head->prev = newSupply;
	}
	head = newSupply;
}

void codeSearch(Supply* &head, string code){
	while(head!=NULL && head->code!=code){
		head = head->next;
	}
}