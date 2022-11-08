#include <bits/stdc++.h>
#include "supList.cpp"

#ifndef bill_h
#define bill_h

class bill: public supList{
    private:
        bool nhapXuat;
        std::string code;
        std::string fileName;
        date dt;
        int total;
    public:
        bill(bool nhapXuat=0, std::string code="", int yyyy=2000, int mm=1, int dd=1);
        virtual ~bill();
        void create();
        void print() const;
};

#endif