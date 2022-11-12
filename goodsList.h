#include <bits/stdc++.h>
#include "linkedList.cpp"
#include "goods.cpp"

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
        void show();
        int numOfSup();
        bool reduce(const node<goods> &S);
        int Search(const node<goods> &S) const;
        void Sort(int order, int t);
        friend std::istream &operator >>(std::istream &in, goodsList &L);
        friend std::ostream &operator <<(std::ostream &out, const goodsList &L);
		friend bool ascend(const goods a, const goods b, const int k);
		friend bool descend(const goods a, const goods b, const int k);
};

#endif