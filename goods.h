#include <bits/stdc++.h>
#include "date.cpp"

class goodsList;
class bill;
class billList;

#ifndef goods_h
#define goods_h

class goods{
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
		friend class goodsList;
		friend class bill;
		friend class billList;
	public:
		goods(int yyyy=2000, int mm=1, int dd=1, std::string c="NULL", std::string n="NULL", std::string t="NULL", std::string u="NULL", std::string p="NULL", int q=0, int u_p=0);
		goods(const goods &S);
		goods(const string &str);
		~goods();
		bool isValid() const;
		date DT() const;
		void setDT(const date &dt);
		goods operator +(int q);
		goods operator -(int q);
		goods &operator =(const goods &S);
		bool operator ==(goods S) const;
		bool operator !=(goods S) const;
		friend std::istream &operator >>(std::istream &in, goods &S); //nhap tu ban phim
		friend std::ostream &operator <<(std::ostream &out, const goods &S); //in ra file, man hinh
		friend bool ascend(const goods &a, const goods &b, const int &k);
		friend bool descend(const goods &a, const goods &b, const int &k);

		//cua goodList
		friend std::istream &operator >>(std::istream &in, goodsList &gL);
		friend std::ostream &operator <<(std::ostream &out, const goodsList &L);
};

#endif
