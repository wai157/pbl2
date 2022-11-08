#include <bits/stdc++.h>
#include "date.cpp"

class supList;
#ifndef supply_h
#define supply_h
class Supply{
	private:
		std::string code;
		std::string name;
		std::string type;
		std::string unit;
		date dt;
		std::string producer;
		int quantity;
		int unit_price;
		int total;
	public:
		Supply *prev, *next;
		Supply(std::string c="NULL", std::string n="NULL", std::string t="NULL", std::string u="NULL", int yyyy=2000, int mm=1, int dd=1, std::string p="NULL", int q=0, int u_p=0);
		Supply(const Supply &S);
		std::string Code() const;
		Supply operator +(int q);
		Supply operator -(int q);
		Supply &operator =(const Supply &S);
		bool operator ==(Supply S);
		bool operator !=(Supply S);
		bool isValid();
		friend std::istream &operator >>(std::istream &in, Supply &S);
		friend std::ostream &operator <<(std::ostream &out, const Supply &S);
		friend std::istream &operator >>(std::istream &in, supList &sL);
		// friend int supList::Search(const Supply &S) const;
		friend std::ostream &operator <<(std::ostream &out, const supList &L);
		friend bool ascend(const Supply a, const Supply b, int k);
		friend bool descend(const Supply a, const Supply b, int k);
};

#endif
