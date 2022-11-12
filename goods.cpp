#include <bits/stdc++.h>
#include "goods.h"
using namespace std;

goods::goods(string c, string n, string t, string u, int yyyy, int mm, int dd, string p, int q, int u_p):dt(yyyy,mm,dd){
	this->code = c;
	this->name = n;
	this->type = t;
	this->unit = u;
	this->producer = p;
	this->quantity = q;
	this->unit_price = u_p;
}

goods::goods(const goods &S){
	this->code = S.code;
	this->name = S.name;
	this->type = S.type;
	this->unit = S.unit;
	this->dt = S.dt;
	this->producer = S.producer;
	this->quantity = S.quantity;
	this->unit_price = S.unit_price;
	this->total = S.total;
}

goods::~goods(){
	
}

goods goods::operator +(int q){
	goods res = *this;
	res.quantity += q;
	res.total = res.quantity * res.unit_price;
	return res;
}

goods goods::operator -(int q){
	goods res = *this;
	res.quantity -= q;
	res.total = res.quantity * res.unit_price;
	return res;
}

goods &goods::operator =(const goods &S){
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

bool goods::operator ==(goods S) const{
	if(this->code==S.code && this->name==S.name && this->type==S.type && this->unit==S.unit && this->dt==S.dt && this->producer==S.producer && this->quantity==S.quantity && this->unit_price==S.unit_price)
		return 1;
	return 0;
}
bool goods::operator !=(goods S) const{
	if(this->code==S.code && this->name==S.name && this->type==S.type && this->unit==S.unit && this->dt==S.dt && this->producer==S.producer && this->quantity==S.quantity && this->unit_price==S.unit_price)
		return 0;
	return 1;
}

bool goods::isValid() const{
	return (this->quantity>0 && this->unit_price>0);
}

void goods::setDT(date dt){
	this->dt = dt;
}

istream &operator >>(istream &in, goods &S){
	cout<<"\tNhap ma vat tu: "; getline(in, S.code); 
	cout<<"\tNhap ten vat tu: "; getline(in, S.name);
	cout<<"\tNhap loai vat tu: "; getline(in, S.type);
	cout<<"\tNhap don vi tinh: "; getline(in, S.unit);
	cout<<"\tNhap nha san xuat: "; getline(in, S.producer);
	cout<<"\tNhap so luong: "; in>>S.quantity; in.ignore();
	cout<<"\tNhap don gia: "; in>>S.unit_price; in.ignore();
	S.total = S.quantity * S.unit_price;
	return in;
}

ostream &operator <<(ostream &out, const goods &S){
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

bool ascend(const goods a, const goods b, const int k=1){
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

bool descend(const goods a, const goods b, const int k=1){
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