#include <bits/stdc++.h>
#include "billList.cpp"
using namespace std;

#ifndef pbl2_h
#define pbl2_h

class pbl2{
    private:
        goodsList khoNhap;
        billList phieuNhap;
        billList phieuXuat;
    public:
        pbl2();
        ~pbl2();
        void welcome();
        void menu();
        bool option1();
        bool option2();
        bool option3();
        bool option4();
        bool option5();
        bool option6();
        bool option7();
        bool option8();
        bool option9();
        bool option10();
        bool option11();
        bool option12();
};

#endif