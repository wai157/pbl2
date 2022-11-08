#include <bits/stdc++.h>
#include "supply.cpp"

#ifndef supList_h
#define supList_h

class supList{
    protected:
        int n;
        Supply *Head;
    public:
        supList();
        supList(supList &sL);
        virtual ~supList();
        void show();
        int numOfSup();
        void insertHead(Supply data);
        void insertAfter(Supply *prevSup, Supply data);
        void insertTail(Supply data);
        void del(Supply *delSup);
        Supply &operator [](int k);
        Supply &operator [](int k) const;
        int Search(const Supply &S) const;
        friend int partition(Supply *sL, int l, int h, bool compFunc(Supply, Supply, int), int t);
        friend void qSort(Supply *sL, int l, int h, bool compFunc(Supply, Supply, int), int t);
        void Sort(int order, int t);
        friend std::istream &operator >>(std::istream &in, supList &L);
        friend std::ostream &operator <<(std::ostream &out, const supList &L);
};

#endif