#include <bits/stdc++.h>
#include "bill.cpp"

#ifndef billlist_h
#define billlist_h

class billList: public linkedList<bill>{
    public:
        billList();
        billList(const billList &bL);
        virtual ~billList();
        void show() const;
        void history(const date &start, const date &end) const;
        friend std::istream &operator >>(std::istream &in, billList &bL);
        friend std::ostream &operator <<(std::ostream &out, const billList &bL);
};

#endif