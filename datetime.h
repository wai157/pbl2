#include <bits/stdc++.h>

#ifndef datetime_h
#define datetime_h

class Date_Time{
	private:
		int Year, Month, Day, Hour, Minute;
	public:
		Date_Time(int YYYY=2000, int MM=01, int DD=01, int H=0, int M=0);
		bool isLeap();
		bool isValid();
		Date_Time &operator =(const Date_Time &DT);
		bool operator <(const Date_Time &DT) const;
		bool operator ==(Date_Time &DT);
		friend std::istream &operator >>(std::istream &in, Date_Time &DT);
		friend std::ifstream& dbInput(std::ifstream &fin, Date_Time &DT);
		friend std::ostream &operator <<(std::ostream &out, const Date_Time &DT);
		friend void dbOutput(std::ofstream &fout, const Date_Time &DT);
};

#endif
