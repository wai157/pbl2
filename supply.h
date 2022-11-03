#include <bits/stdc++.h>
#include "datetime.cpp"

class supList;
#ifndef supply_h
#define supply_h
class Supply{
	private:
		std::string code;
		std::string name;
		std::string type;
		std::string unit;
		Date_Time DateTime;
		std::string producer;
		int quantity;
		int unit_price;
		int total;
		friend class supList;
	public:
		Supply *prev, *next;
		Supply(std::string c="NULL", std::string n="NULL", std::string t="NULL", std::string u="NULL", int YYYY=2000, int MM=1, int DD=1, int H=0, int M=0, std::string p="NULL", int q=0, int u_p=0);
		Supply(const Supply &S);
		Supply operator +(int q);
		Supply operator -(int q);
		Supply &operator =(const Supply &S);
		bool operator ==(Supply S);
		bool operator !=(Supply S);
		bool isValid();
		friend std::istream &operator >>(std::istream &in, Supply &S);
		friend std::ostream &operator <<(std::ostream &out, const Supply &S);
		friend std::istream &operator >>(std::istream &in, supList &sL);
		friend void codeSearch(Supply* &head, string code);
		friend std::ostream &operator <<(std::ostream &out, const supList &L);
		friend bool ascend(const Supply a, const Supply b, int k);
		friend bool descend(const Supply a, const Supply b, int k);
};

#endif
