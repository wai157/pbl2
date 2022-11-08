#include <bits/stdc++.h>
#include "date.h"
using namespace std;

int dayOfYears[2][12]={{31,28,31,30,31,30,31,31,30,31,30,31},
					   {31,29,31,30,31,30,31,31,30,31,30,31}};

date::date(int yyyy, int mm, int dd){
	this->year = yyyy;
	this->month = mm;
	this->day = dd;
}

bool date::isLeap(){
	return (this->year%400==0 || (this->year%100!=0 && this->year%4==0));
}

bool date::isValid(){
	return(this->year>0 && this->month>0 && this->day>0 &&
		   this->month<13 && this->day<=dayOfYears[this->isLeap()][this->month-1]);
}

string date::dtAsString() const{
	string tmp="";
	tmp = tmp + to_string(this->year) + to_string(this->month) + to_string(this->day);
	return tmp;
}

date &date::operator =(const date &dt){
	this->day = dt.day;
	this->month = dt.month;
	this->year = dt.year;
	return (*this);
} 

bool date::operator <(const date &dt) const{
	if(this->year!=dt.year) return this->year<dt.year;
	if(this->month!=dt.month) return this->month<dt.month;
	return this->day<dt.day;
}

bool date::operator >(const date &dt) const{
	if(this->year!=dt.year) return this->year>dt.year;
	if(this->month!=dt.month) return this->month>dt.month;
	return this->day>dt.day;
}

bool date::operator ==(date &dt){
	if(this->day==dt.day && this->month==dt.month && this->year==dt.year)
		return 1;
	return 0;
} 

istream &inpDT(istream &in, date &dt){
	in>>dt.day;
	in>>dt.month;
	in>>dt.year;
	return in;
}

ostream &outDT(ostream &out, const date &dt){
	out<<dt.day<<endl<<dt.month<<endl<<dt.year<<endl;
	return out;
}

istream &operator >>(istream &in, date &dt){
	cout<<"\t\tNgay: "; in>>dt.day;
	cout<<"\t\tThang: "; in>>dt.month;
	cout<<"\t\tNam: "; in>>dt.year;
	return in;
}

ostream &operator <<(ostream &out, const date &dt){
	out<<setfill('0')<<setw(2)<<dt.day<<"/"<<setw(2)<<dt.month<<"/"<<setw(4)<<dt.year<<endl;
	return out;
}
