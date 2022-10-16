#include <bits/stdc++.h>
#include "datetime.h"
using namespace std;

int dayOfYears[2][12]={{31,28,31,30,31,30,31,31,30,31,30,31},
					   {31,29,31,30,31,30,31,31,30,31,30,31}};

Date_Time::Date_Time(int YYYY, int MM, int DD, int H, int M){
	this->Year = YYYY;
	this->Month = MM;
	this->Day = DD;
	this->Hour = H;
	this->Minute = M;
}

bool Date_Time::isLeap(){
	return (this->Year%400==0 || (this->Year%100!=0 && this->Year%4==0));
}

bool Date_Time::isValid(){
	return(this->Year>0 && this->Month>0 && this->Day>0 && this->Hour>=0 && this->Minute>=0 &&
		   this->Month<13 && this->Day<dayOfYears[this->isLeap()][this->Month-1] && 
		   this->Hour<24 && this->Minute<60);
}
Date_Time &Date_Time::operator =(const Date_Time &DT){
	this->Day = DT.Day;
	this->Month = DT.Month;
	this->Year = DT.Year;
	this->Hour = DT.Hour;
	this->Minute = DT.Minute;
	return (*this);
} 

bool Date_Time::operator <(const Date_Time &DT) const{
	if(this->Year!=DT.Year) return this->Year<DT.Year;
	if(this->Month!=DT.Month) return this->Month<DT.Month;
	if(this->Day!=DT.Day) return this->Day<DT.Day;
	if(this->Hour!=DT.Hour) return this->Hour<DT.Hour;
	return this->Minute<DT.Minute;
}

bool Date_Time::operator ==(Date_Time &DT){
	if(this->Hour==DT.Hour && this->Minute==DT.Minute && this->Day==DT.Day && this->Month==DT.Month && this->Year==DT.Year)
		return 1;
	return 0;
} 

istream &operator >>(istream &in, Date_Time &DT){
	cout<<"\tNhap ngay thang nam:\n";
	cout<<"\t\tNgay: "; in>>DT.Day;
	cout<<"\t\tThang: "; in>>DT.Month;
	cout<<"\t\tNam: "; in>>DT.Year;
	cout<<"\tNhap gio phut giay:\n";
	cout<<"\t\tGio: "; in>>DT.Hour;
	cout<<"\t\tPhut: "; in>>DT.Minute;
	return in;
}

ifstream& dbInput(ifstream &fin, Date_Time &DT){
	fin>>DT.Day;
	fin>>DT.Month;
	fin>>DT.Year;
	fin>>DT.Hour;
	fin>>DT.Minute;
	return fin;
}

ostream &operator <<(ostream &out, const Date_Time &DT){
	out<<setfill('0')<<setw(2)<<DT.Day<<"/"<<setw(2)<<DT.Month<<"/"<<setw(4)<<DT.Year<<"---"
	<<setw(2)<<DT.Hour<<":"<<setw(2)<<DT.Minute<<endl;
	return out;
}
void dbOutput(ofstream &fout, const Date_Time &DT){
	fout<<DT.Day<<endl<<DT.Month<<endl<<DT.Year<<endl
	<<DT.Hour<<endl<<DT.Minute<<endl;
}
