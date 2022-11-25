#include <bits/stdc++.h>
#include "bill.cpp"

#ifndef billlist_h
#define billlist_h

class billList: public linkedList<bill>{
    public:
        billList();
        billList(const billList &bL);
        virtual ~billList();
        void create(bill &b) const; //tao phieu
        void show() const; //in ra mh
        void print(const int &nx) const; //in file ds phieu
        void history(const date &start, const date &end) const; //lich su nhap xuat
        void Search(const int &nx, const int &att) const; //tim kiem
        friend std::istream &operator >>(std::istream &in, billList &bL); //nhap tu db
        friend std::ostream &operator <<(std::ostream &out, const billList &bL); //in ra db
};

#endif