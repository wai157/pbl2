#include <bits/stdc++.h>
#include "goodsList.cpp"

class billList;

#ifndef bill_h
#define bill_h

class bill{
    private:
        bool nhapXuat;
        std::string code;
        std::string nguoiTao;
        date ngayTao;
        date ngayNhapXuat;
        std::string fileName;
        goodsList gL;
        int total;
        friend class billList;
    public:
        bill(bool nhapXuat=0, std::string code="", int yyyy=2000, int mm=1, int dd=1);
        bill(const bill &b);
        bill(const std::string &str);
        virtual ~bill();
        date ngayNhapXuat_() const;
        void add(const goods &S);
        void print(); //in file phieu
        bill &operator =(bill b);
        friend std::ostream &operator <<(std::ostream &out, const bill &b);
        friend bool ascend(const bill &a, const bill &b, const int &k);
		friend bool descend(const bill &a, const bill &b, const int &k);
        //cua goodsList
        friend void goodsList::addBill(const bill &b);
        friend void goodsList::subBill(const bill &b);
        //cua billList
        friend std::istream &operator >>(std::istream &in, billList &bL); 
        friend std::ostream &operator <<(std::ostream &out, const billList &bL);
};

#endif