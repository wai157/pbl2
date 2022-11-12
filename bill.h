#include <bits/stdc++.h>
#include "goodsList.cpp"

class billList;

#ifndef bill_h
#define bill_h

class bill{
    private:
        bool nhapXuat;
        std::string code;
        std::string fileName;
        date ngayTao;
        date ngayNhapXuat;
        int total;
        goodsList gL;
        friend class billList;
    public:
        bill(bool nhapXuat=0, std::string code="", int yyyy=2000, int mm=1, int dd=1);
        bill(const bill &b);
        virtual ~bill();
        date ngayNhapXuat_() const;
        void add(const goods &S);
        bool create();
        void print();
};

#endif