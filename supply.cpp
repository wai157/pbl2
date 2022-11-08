#include <bits/stdc++.h>
#include "supply.h"
using namespace std;

Supply::Supply(string c, string n, string t, string u, int yyyy, int mm, int dd, string p, int q, int u_p):dt(yyyy,mm,dd){
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

Supply::Supply(const Supply &S){
	*this = S;
	this->prev = NULL;
	this->next = NULL;
}

string Supply::Code() const{
	return this->code;
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
	this->dt = S.dt;
	this->producer = S.producer;
	this->quantity = S.quantity;
	this->unit_price = S.unit_price;
	this->total = S.total;
	return (*this);
}

bool Supply::operator ==(Supply S){
	if(this->code==S.code && this->name==S.name && this->type==S.type && this->unit==S.unit && this->dt==S.dt && this->producer==S.producer && this->quantity==S.quantity && this->unit_price==S.unit_price)
		return 1;
	return 0;
}
bool Supply::operator !=(Supply S){
	if(this->code==S.code && this->name==S.name && this->type==S.type && this->unit==S.unit && this->dt==S.dt && this->producer==S.producer && this->quantity==S.quantity && this->unit_price==S.unit_price)
		return 0;
	return 1;
}

bool Supply::isValid(){
	
	return (this->dt.isValid() && this->quantity>0 && this->unit_price>0);
}

istream &operator >>(istream &in, Supply &S){
	int c;
	cout<<"\tNhap ma vat tu: "; getline(in, S.code); 
	cout<<"\tNhap ten vat tu: "; getline(in, S.name);
	cout<<"\tNhap loai vat tu: "; getline(in, S.type);
	cout<<"\tNhap don vi tinh: "; getline(in, S.unit);
	cout<<"\tNhap nha san xuat: "; getline(in, S.producer);
	cout<<"\tNhap so luong: "; in>>S.quantity; in.ignore();
	// while((c=getchar())!='\n' && c!=EOF);
	cout<<"\tNhap don gia: "; in>>S.unit_price; in.ignore();
	// while((c=getchar())!='\n' && c!=EOF);
	S.total = S.quantity * S.unit_price;
	return in;
}

ostream &operator <<(ostream &out, const Supply &S){
	out<<"\tMa vat tu: "<<S.code<<endl;
	out<<"\tTen vat tu: "<<S.name<<endl;
	out<<"\tLoai vat tu: "<<S.type<<endl;
	out<<"\tDon vi tinh: "<<S.unit<<endl;
	out<<"\tNgay nhap hang: "<<S.dt;
	out<<"\tNha san xuat: "<<S.producer<<endl;
	out<<"\tSo luong: "<<S.quantity<<endl;
	out<<"\tDon gia: "<<S.unit_price<<endl;
	out<<"\tThanh tien: "<<S.total<<endl;
	return out;
}

bool ascend(const Supply a, const Supply b, int k=1){
	switch(k){
		case 2:
			return a.name<b.name;
		case 3:
			return a.type<b.type;
		case 4:
			return a.unit<b.unit;
		case 5:
			return a.dt<b.dt;
		case 6:
			return a.producer<b.producer;
		case 7:
			return a.quantity<b.quantity;
		case 8:
			return a.unit_price<b.unit_price;
		case 9:
			return a.total<b.total;
		default:
			return a.code<b.code;
	}
}

bool descend(const Supply a, const Supply b, int k=1){
	switch(k){
		case 2:
			return a.name>b.name;
		case 3:
			return a.type>b.type;
		case 4:
			return a.unit>b.unit;
		case 5:
			return a.dt>b.dt;
		case 6:
			return a.producer>b.producer;
		case 7:
			return a.quantity>b.quantity;
		case 8:
			return a.unit_price>b.unit_price;
		case 9:
			return a.total>b.total;
		default:
			return a.code>b.code;
	}
}