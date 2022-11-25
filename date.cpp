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

date::date(const std::string &dt){
	this->year = stoi(dt.substr(0,4));
	this->month = stoi(dt.substr(4,2));
	this->day = stoi(dt.substr(6,2));
}

date::date(const date &dt){
	this->day = dt.day;
	this->month = dt.month;
	this->year = dt.year;
}

bool date::isLeap(){
	return (this->year%400==0 || (this->year%100!=0 && this->year%4==0));
}

bool date::isValid(){
	return(this->year>999 && this->month>0 && this->day>0 &&
		   this->month<13 && this->day<=dayOfYears[this->isLeap()][this->month-1]);
}

string date::dtAsString() const{
	string tmp="";
	tmp += to_string(this->year);
	if(this->month<10) tmp += "0";
	tmp += to_string(this->month);
	if(this->day<10) tmp +="0";
	tmp += to_string(this->day);
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

bool date::operator <=(const date &dt) const{
	return !(*this>dt);
}

bool date::operator >(const date &dt) const{
	if(this->year!=dt.year) return this->year>dt.year;
	if(this->month!=dt.month) return this->month>dt.month;
	return this->day>dt.day;
}

bool date::operator >=(const date &dt) const{
	return !(*this<dt);
}

bool date::operator ==(const date &dt) const{
	if(this->day==dt.day && this->month==dt.month && this->year==dt.year)
		return 1;
	return 0;
} 

date &date::operator ++(){
	if(this->day < dayOfYears[this->isLeap()][this->month-1]) this->day++;
    else{ 
		this->day = 1;
        if(this->month<12) this->month++;
        else{
			this->month = 1; 
			this->year++;
		}
    }
    return *this;
}

istream &operator >>(istream &in, date &dt){
	cout<<"\tNgay: "; in>>dt.day;
	cout<<"\tThang: "; in>>dt.month;
	cout<<"\tNam: "; in>>dt.year;
	return in;
}

ostream &operator <<(ostream &out, const date &dt){
	out<<setfill('0')<<setw(2)<<right<<dt.day<<"/"<<setw(2)<<right<<dt.month<<"/"<<setw(4)<<right<<dt.year<<setfill(' ');
	return out;
}
