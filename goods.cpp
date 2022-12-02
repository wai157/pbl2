#include <bits/stdc++.h>
#include "goods.h"
using namespace std;

goods::goods(int yyyy, int mm, int dd, string c, string n, string t, string u, string p, int q, int u_p):dt(yyyy,mm,dd){
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

goods::goods(const string &str){
	int k=0;
	int ps[10]={0};
	int pe[10]={0};
	int i=1;
	while(i<=9){
		ps[i]=k;
		k = str.find(',', k);
		pe[i]=k;
		k++;
		i++;
	}
	this->code = str.substr(ps[1],pe[1]-ps[1]);
	this->name = str.substr(ps[2],pe[2]-ps[2]);
	this->type = str.substr(ps[3],pe[3]-ps[3]);
	this->unit = str.substr(ps[4],pe[4]-ps[4]);
	this->dt = str.substr(ps[5],pe[5]-ps[5]);
	this->producer = str.substr(ps[6],pe[6]-ps[6]);
	this->quantity = stoi(str.substr(ps[7],pe[7]-ps[7]));
	this->unit_price = stoi(str.substr(ps[8],pe[8]-ps[8]));
	this->total = stoi(str.substr(ps[9],pe[9]-ps[9]));
}

goods::~goods(){
	
}

bool goods::isValid() const{
	return (this->code!="" && this->name!="" && 
			this->type!="" && this->unit!="" && this->producer!="" &&
			this->quantity>0 && this->unit_price>0);
}

date goods::DT() const{
	return this->dt;
}

void goods::setDT(const date &dt){
	this->dt = dt;
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

istream &operator >>(istream &in, goods &S){
	cout<<"\tNhap ma hang hoa: "; getline(in, S.code); 
	cout<<"\tNhap ten hang hoa: "; getline(in, S.name);
	cout<<"\tNhap loai hang hoa: "; getline(in, S.type);
	cout<<"\tNhap don vi tinh: "; getline(in, S.unit);
	cout<<"\tNhap nha san xuat: "; getline(in, S.producer);
	cout<<"\tNhap so luong: "; in>>S.quantity; in.ignore();
	cout<<"\tNhap don gia: "; in>>S.unit_price; in.ignore();
	S.total = S.quantity * S.unit_price;
	
	return in;
}

ostream &operator <<(ostream &out, const goods &S){
	out<<setw(12)<<left<<S.code<<"| ";
	out<<setw(23)<<left<<S.name<<"| ";
	out<<setw(14)<<left<<S.type<<"| ";
	out<<setw(19)<<left<<S.producer<<"| ";
	out<<"    "<<S.dt<<" | ";
	out<<setw(12)<<left<<S.unit<<"|";
	out<<setw(9)<<right<<S.quantity<<" |";
	out<<setw(14)<<right<<S.unit_price<<" |";
	out<<setw(15)<<right<<S.total<<" |";

	return out;
}

bool ascend(const goods &a, const goods &b, const int &k){
	switch(k){
		case 2:
			// if(a.name==b.name) return a.dt<b.dt;
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

bool descend(const goods &a, const goods &b, const int &k){
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