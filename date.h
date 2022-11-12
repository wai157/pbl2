#include <bits/stdc++.h>

#ifndef date_h
#define date_h

class date{
	private:
		int year, month, day;
	public:
		date(int yyyy=2000, int mm=01, int dd=01);
		date(const std::string &dt);
		date(const date &dt);
		bool isLeap();
		bool isValid();
		std::string dtAsString() const;
		date &operator =(const date &dt);
		bool operator <(const date &dt) const;
		bool operator <=(const date &dt) const;
		bool operator >(const date &dt) const;
		bool operator >=(const date &dt) const;
		bool operator ==(const date &dt) const;
		date &operator ++();
		friend std::istream &inpDT(std::istream &in, date &dt);
		friend std::ostream &outDT(std::ostream &out, const date &dt);
		friend std::istream &operator >>(std::istream &in, date &dt);
		friend std::ostream &operator <<(std::ostream &out, const date &dt);
};

#endif
