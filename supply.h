#include <bits/stdc++.h>
#include "datetime.cpp"

#ifndef supply_h
#define supply_h
class Supply{
	private:
		string code;
		string name;
		string type;
		string unit;
		Date_Time DateTime;
		string producer;
		int quantity;
		int unit_price;
		int total;
	public:
		Supply *prev;
		Supply *next;
		Supply(string c="NULL", string n="NULL", string t="NULL", string u="NULL", int YYYY=2000, int MM=1, int DD=1, int H=0, int M=0, string p="NULL", int q=0, int u_p=0);
		Supply operator +(int q);
		Supply operator -(int q);
		Supply &operator =(const Supply &S);
		bool operator ==(Supply S);
		bool operator !=(Supply S);
		bool isValid();
		friend std::istream &operator >>(std::istream &in, Supply &S);
		friend std::ifstream& dbInput(std::ifstream &fin, Supply &S);
		friend std::ostream &operator <<(std::ostream &out, const Supply &S);
		friend void dbOutput(std::ofstream &fout, const Supply &S);
		friend void codeSearch(Supply* &head, string code);
};

#endif
