#include <bits/stdc++.h>
#include "linkedList.cpp"
#include "goods.cpp"
int main();
class bill;
class billList;

#ifndef goodsList_h
#define goodsList_h

class goodsList: public linkedList<goods>{
    private:
        friend class bill;
        friend class billList;
    public:
        goodsList();
        goodsList(const goodsList &gL);
        virtual ~goodsList();
        void show() const; //in ra man hinh
        void print() const; //in file hh
        void nhap(goods &S); //nhap hh vao kho
        void xuat(goods &S); //xuat hh tu kho
        void reduce(const goods &S); //giam hh trong kho
        void Search(const int &att) const; //tim kiem
        goodsList &operator =(goodsList gL);
        friend std::istream &operator >>(std::istream &in, goodsList &gL); //nhap tu db
        friend std::ostream &operator <<(std::ostream &out, const goodsList &gL); //in ra db
        friend int main();
};

#endif